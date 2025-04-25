cfg = configuration_data()

subdir('default')

if get_option('FORCE_HIGHBITDEPTH_DECODING') and not get_option('CONFIG_AV1_HIGHBITDEPTH')
    warning('Enabled CONFIG_AV1_HIGHBITDEPTH required for FORCE_HIGHBITDEPTH_DECODING')
    cfg.set10('CONFIG_AV1_HIGHBITDEPTH', true)
endif

if get_option('CONFIG_THREE_PASS') and not get_option('CONFIG_AV1_DECODER')
    warning('Disabled CONFIG_THREE_PASS incompatible with CONFIG_AV1_DECODER')
    cfg.set10('CONFIG_AV1_DECODER', false)
endif

# Detect target CPU.
target_cpu = get_option('AOM_TARGET_CPU')
if target_cpu == ''
    cpu_family = host_machine.cpu_family()
    if (cpu_family.startswith('arm') or
        cpu_family.startswith('x86') or
        cpu_family.startswith('ppc') or
        cpu_family.startswith('riscv'))
        target_cpu = cpu_family
    elif cpu_family == 'aarch64'
        target_cpu = 'arm64'
    else
        warning('The architecture @0@ is not supported, falling back to the generic target'.format(cpu_family))
        target_cpu = 'generic'
    endif
endif
message('Detected cpu: @0@'.format(target_cpu))
target_system = host_machine.system()

subdir('toolchain')

if get_option('buildtype') == 'debug'
    cfg.set10('CONFIG_DEBUG', true)
endif

if get_option('default_library') == 'shared'
    cfg.set10('CONFIG_PIC', true)
    cfg.set10('CONFIG_SHARED', true)
elif not get_option('CONFIG_PIC')
    if get_option('b_staticpic')
        cfg.set10('CONFIG_PIC', true)
    elif cc.compiles('''
                #if !(__pie__ || __PIE__)
                #error Neither __pie__ or __PIE__ are set
                #endif
                extern void unused(void);
                void unused(void) {}
            ''',
            name: 'HAVE_PIE',
        )
        cfg.set10('CONFIG_PIC', true)
        message('CONFIG_PIC enabled for position independent executable (PIE) build')
    endif
endif

if cc.get_argument_syntax() != 'msvc'
    if cfg.get('CONFIG_PIC') == 1
        if target_system == 'linux' and target_cpu != 'arm64' and target_cpu.startswith('arm')
            asm_args += '--defsym PIC=1'
        else
            asm_args += '-DPIC'
        endif
    endif
endif

if target_cpu in ['x86', 'x86_64']
    asm_compiler = find_program('yasm', required: false)
    if not asm_compiler.found() or get_option('ENABLE_NASM')
        nasm = find_program('nasm', required: false, version: '>= 2.14')
        asm_compiler = nasm
    else
        nasm = disabler()
    endif

    if asm_compiler.found()
        if target_system == 'darwin'
            asm_format = 'macho'
        elif target_system in ['cygwin', 'windows']
            asm_format = 'win'
        else
            asm_format = 'elf'
        endif
        if target_cpu == 'x86_64'
            asm_format += '64'
        elif target_cpu == 'x86'
            asm_format += '32'
        else
            error('Unknown asm format: @0@-@1@'.format(target_cpu, system))
        endif

        if nasm.found()
            output = run_command(nasm, '-hf', check: true).stdout()
            if not output.contains('-Ox')
                error('Unsupported nasm: multipass optimization not supported.')
            endif
            if not output.contains(asm_format)
                error('Unsupported nasm: @0@ asm format not supported.'.format(asm_format))
            endif
        endif

        asm_args += [
            '-f', asm_format,
            '-I', '@0@/'.format(lib_src_dir),
            '-I', '@0@/'.format(lib_dst_dir),
            '@INPUT@', '-o', '@OUTPUT@'
        ]

        asm_gen = generator(asm_compiler,
               output: '@BASENAME@.obj',
              depfile: '@BASENAME@.obj.ndep',
            arguments: asm_args)

        # Xcode requires building the objects manually, so pass the object format flag.
        if get_option('backend') == 'xcode'
            asm_args += '-f @0@'.format(asm_format)
        endif
    else
        error('Unable to find assembler. Install \'yasm\' or \'nasm.\' ' +
              'To build without optimizations, add -DAOM_TARGET_CPU=generic to ' +
              'your meson command line.')
    endif
elif target_cpu.startswith('arm')
    if target_system == 'darwin'
        if not asm_compiler.found()
            asm_compiler = cc
        endif
        asm_args += [
            '-arch', target_cpu,
            # '-isysroot', osx_sysroot,
        ]
    elif target_system == 'windows'
        if not asm_compiler.found()
            asm_compiler = cc
        endif
        asm_args += ['-c', 'mimplicit-it=always']
    else
        if not asm_compiler.found()
            # asm_compiler = as
        endif
    endif
    if not asm_compiler.found()
        error('Unable to find assembler and optimizations are enabled. ' +
              'Searched for assembler compiler. Install it, add it to your path, ' +
              'or set the assembler directly by adding ' +
              '-DASM_COMPILER=<assembler path> to your meson command line. ' +
              'To build without optimizations, add -DAOM_TARGET_CPU=generic to your ' +
              'meson command line.')
    endif
endif

if get_option('CONFIG_ANALYZER')
    wx_widgets = [
        dependency('adv'),
        dependency('base'),
        dependency('core'),
    ]
endif

if cc.get_argument_syntax() == 'gcc'
    cfg.set10('CONFIG_GCC', true)
endif

if get_option('CONFIG_GCOV') or get_option('b_coverage')
    if not get_option('CONFIG_GCOV')
        cfg.set10('CONFIG_GCOV', true)
    endif
    message('Testing for CONFIG_GCOV support.')
    exec_args += cc.get_supported_arguments(['-fprofile-arcs', '-ftest-coverage'])
    c_args += cc.get_supported_arguments(['-fprofile-arcs', '-ftest-coverage'])
endif

if get_option('CONFIG_GPROF')
    message('Testing for CONFIG_GPROF support.')
    c_args += cc.get_supported_arguments('-pg')
endif

if target_system in ['darwin', 'linux', 'windows', 'android']
    cfg.set10('CONFIG_OS_SUPPORT', true)
endif

if target_system == 'windows'
    # The default _WIN32_WINNT value in MinGW is 0x0502 (Windows XP with SP2). Set
    # it to 0x0601 (Windows 7).
    c_args += cc.get_supported_arguments('-D_WIN32_WINNT=0x0601')
    # Quiet warnings related to fopen, printf, etc.
    c_args += cc.get_supported_arguments('-D_CRT_SECURE_NO_WARNINGS')
endif

#
# Fix CONFIG_* dependencies. This must be done before including cpu.cmake to
# ensure RTCD_CONFIG_* are properly set.
if get_option('CONFIG_ANALYZER') and not get_option('CONFIG_INSPECTION')
    warning('Enabled CONFIG_INSPECTION required for CONFIG_ANALYZER')
    cfg.set10('CONFIG_INSPECTION', true)
endif

if cc.has_header('pthread.h')
    cfg.set10('HAVE_PTHREAD_H', true)
endif

if cc.has_header('unistd.h')
    cfg.set10('HAVE_UNISTD_H', true)
endif

if target_system != 'windows' and cc.compiles('''
    #include <fenv.h>
    void unused(void) {
        (void)unused;
        (void)feenableexcept(FE_DIVBYZERO | FE_INVALID);
    }''',
    name: 'HAVE_FEXCEPT')
    link_args += cc.get_supported_arguments('-lm')
    cfg.set10('HAVE_FEXCEPT', true)
endif

subdir('cpu')

if get_option('ENABLE_CCACHE')
    #set_compiler_launcher(ENABLE_CCACHE ccache)
endif

if get_option('ENABLE_DISTCC')
    #set_compiler_launcher(ENABLE_DISTCC distcc)
endif

if get_option('ENABLE_GOMA')
    #set_compiler_launcher(ENABLE_GOMA gomacc)
endif

if not get_option('CONFIG_AV1_DECODER') and not  get_option('CONFIG_AV1_ENCODER')
    error('Decoder and encoder disabled, nothing to build.')
endif

if get_option('DECODE_HEIGHT_LIMIT') or get_option('DECODE_WIDTH_LIMIT')
    if not get_option('CONFIG_SIZE_LIMIT')
        warning('Enabled CONFIG_SIZE_LIMIT required for DECODE_HEIGHT_LIMIT and DECODE_WIDTH_LIMIT')
        cfg.set10('CONFIG_SIZE_LIMIT', true)
    endif
endif

if get_option('CONFIG_SIZE_LIMIT')
    if not get_option('DECODE_HEIGHT_LIMIT') or not get_option('DECODE_WIDTH_LIMIT')
        error('When setting CONFIG_SIZE_LIMIT, DECODE_HEIGHT_LIMIT and DECODE_WIDTH_LIMIT must be set.')
    endif
endif

# Test compiler flags.
if cc.get_argument_syntax() == 'msvc'
    # It isn't possible to specify C99 conformance for MSVC. MSVC doesn't support
    # C++ standards modes earlier than C++14.
    cpp_args += cc.get_supported_arguments('/std:c++14')
    # c_args += cc.get_supported_arguments('/W3')

    # Disable MSVC warnings that suggest making code non-portable.
    c_args += cc.get_supported_arguments('/wd4996')
    if get_option('ENABLE_WERROR')
        c_args += cc.get_supported_arguments('/WX')
    endif

    # Compile source files in parallel
    # c_args += cc.get_supported_arguments('/MP')
else
    # c_args += cc.get_supported_arguments('-std=c99')
    if cc.get_id() == 'clang'
            # AND CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "GNU"
            # AND CMAKE_CXX_SIMULATE_ID STREQUAL "MSVC"
        # Microsoft's C++ Standard Library requires C++14 as it's MSVC's default and
        # minimum supported C++ version. If Clang is using this Standard Library
        # implementation, it cannot target C++11.
        cpp_args += cc.get_supported_arguments('-std=c++14')
    elif target_system == 'cygwin' and host_machine.kernel() == 'gnu'
        # The GNU C++ compiler in Cygwin needs the -std=gnu++11 flag to make the
        # POSIX function declarations visible in the Standard C Library headers.
        cpp_args += cc.get_supported_arguments('-std=gnu++11')
    else
        cpp_args += cc.get_supported_arguments('-std=c++11')
    endif
    c_args += cc.get_supported_arguments([
        # '-Wall',
        '-Wdisabled-optimization',
        # '-Wextra',
    ])
    # Prior to version 3.19.0 cmake would fail to parse the warning emitted by gcc
    # with this flag. Note the order of this check and -Wextra-semi-stmt is
    # important due to is_flag_present() matching substrings with string(FIND ...).
    if false # CMAKE_VERSION VERSION_LESS "3.19"
             # AND CMAKE_C_COMPILER_ID STREQUAL "GNU"
             # AND CMAKE_C_COMPILER_VERSION VERSION_GREATER_EQUAL 10
        cpp_args += cc.get_supported_arguments('-Wextra-semi')
    else
        c_args += cc.get_supported_arguments('-Wextra-semi')
    endif
    c_args += cc.get_supported_arguments([
        '-Wextra-semi-stmt',
        '-Wfloat-conversion',
        '-Wformat=2',
        '-Wimplicit-function-declaration',
        '-Wlogical-op',
        '-Wmissing-declarations',
        '-Wmissing-prototypes',
        '-Wpointer-arith',
        '-Wshadow',
        '-Wshorten-64-to-32',
        '-Wsign-compare',
        '-Wstring-conversion',
        '-Wtype-limits',
        '-Wundef',
        '-Wuninitialized',
        '-Wunreachable-code-aggressive',
        '-Wunused',
        '-Wvla',
    ])
    cpp_args += cc.get_supported_arguments([
        '-Wc++14-extensions',
        '-Wc++17-extensions',
        '-Wc++20-extensions',
    ])
    if get_option('b_sanitize') in ['address', 'undefined']
        # This combination has more stack overhead, so we account for it by
        # providing higher stack limit than usual.
        c_args += cc.get_supported_arguments('-Wstack-usage=285000')
        cpp_args += cc.get_supported_arguments('-Wstack-usage=270000')
    elif get_option('CONFIG_RD_DEBUG')
        # Another case where higher stack usage is expected.
        c_args += cc.get_supported_arguments('-Wstack-usage=135000')
        cpp_args += cc.get_supported_arguments('-Wstack-usage=240000')
    else
        c_args += cc.get_supported_arguments('-Wstack-usage=120000')
        cpp_args += cc.get_supported_arguments('-Wstack-usage=240000')
    endif

    if get_option('b_sanitize') == 'address'
        # Disable no optimization warning when compiling with sanitizers
        c_args += cc.get_supported_arguments('-Wno-disabled-optimization')
    endif

    # Quiet gcc 6 vs 7 abi warnings:
    # https://gcc.gnu.org/bugzilla/show_bug.cgi?id=77728
    if target_cpu.startswith('arm')
        cpp_args += cc.get_supported_arguments('-Wno-psabi')
    endif

    if get_option('ENABLE_WERROR')
        c_args += cc.get_supported_arguments('-Werror')
    endif

    if get_option('buildtype') == 'release'
        c_args += cc.get_supported_arguments([
            '-U_FORTIFY_SOURCE',
            '-D_FORTIFY_SOURCE=0',
        ])
    endif
    c_args += cc.get_supported_arguments([
        '-D_LARGEFILE_SOURCE',
        '-D_FILE_OFFSET_BITS=64',
    ])

    # Do not allow implicit vector type conversions on Clang builds (this is
    # already the default on GCC builds).
    if cc.get_id() == 'clang'
        # Clang 8.0.1 (in Cygwin) doesn't support -flax-vector-conversions=none.
        c_args += cc.get_supported_arguments('-flax-vector-conversions=none')
    endif
endif

# Prior to r23, or with ANDROID_USE_LEGACY_TOOLCHAIN_FILE set,
# android.toolchain.cmake would set normal (non-cache) versions of variables
# like CMAKE_C_FLAGS_RELEASE which would mask the ones added to the cache
# variable in add_compiler_flag_if_supported(), etc. As a workaround we add
# everything accumulated in AOM_C/CXX_FLAGS to the normal versions. This could
# also be addressed by reworking the flag tests and adding the results directly
# to target_compile_options() as in e.g., libgav1, but that's a larger task.
# https://github.com/android/ndk/wiki/Changelog-r23#changes
if target_system == 'android'
    # AND ("${ANDROID_NDK_MAJOR}" LESS 23 OR ANDROID_USE_LEGACY_TOOLCHAIN_FILE))
    # foreach(lang C;CXX)
    #    string(STRIP "${AOM_${lang}_FLAGS}" AOM_${lang}_FLAGS)
    #    if(AOM_${lang}_FLAGS)
    #        foreach(config ${AOM_${lang}_CONFIGS})
    #            set(${config} "${${config}} ${AOM_${lang}_FLAGS}")
    #        endforeach
    #    endif
    #endforeach
endif

c_args += cc.get_supported_arguments([
    '-Wno-implicit-function-declaration',
    '-Wno-unused-variable',
    '-Wno-unused-function',
])

# Generate aom_config.{asm,h}.
configure_file(
            input: 'aom_config.asm.in',
           output: 'aom_config.asm',
    configuration: cfg,
          install: false,
)
configure_file(
            input: 'aom_config.h.in',
           output: 'aom_config.h',
    configuration: cfg,
          install: false,
)

# Read the current git hash.
git = find_program('git', required: false)
if not git.found()
    message('Git missing, version will be read from CHANGELOG.')
endif

cur_dir = meson.current_build_dir()

# Find Perl and generate the RTCD sources.
perl = find_program('perl', required: false)
if not perl.found()
    error('Perl is required to build libaom.')
endif

run_command(perl,
    files('../build/cmake/rtcd.pl'),
    '--arch=@0@'.format(target_cpu),
    '--sym=aom_dsp_rtcd', rtcd_args,
    '--config=@0@/aom_config.h'.format(cur_dir),
    '--output=@0@/aom_dsp_rtcd.h'.format(cur_dir),
    files('../aom_dsp/aom_dsp_rtcd_defs.pl'),
    check: false,
)
run_command(perl,
    files('../build/cmake/rtcd.pl'),
    '--arch=@0@'.format(target_cpu),
    '--sym=aom_scale_rtcd', rtcd_args,
    '--config=@0@/aom_config.h'.format(cur_dir),
    '--output=@0@/aom_scale_rtcd.h'.format(cur_dir),
    files('../aom_scale/aom_scale_rtcd.pl'),
    check: false,
)
run_command(perl,
    files('../build/cmake/rtcd.pl'),
    '--arch=@0@'.format(target_cpu),
    '--sym=av1_rtcd', rtcd_args,
    '--config=@0@/aom_config.h'.format(cur_dir),
    '--output=@0@/av1_rtcd.h'.format(cur_dir),
    files('../av1/common/av1_rtcd_defs.pl'),
    check: false,
)

# Generate aom_version.h.
run_command(perl,
    files('../build/cmake/version.pl'),
    '--version_data=@0@'.format('../CHANGELOG'),
    '--version_filename=@0@/aom_version.h'.format(cur_dir),
    check: false,
)
