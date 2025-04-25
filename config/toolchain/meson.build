if target_cpu == 'arm64'
    if target_system == 'darwin'
        arg = '-arch arm64'
        if cc.get_supported_arguments(arg)
            c_args += arg
            cpp_args += arg
            exec_args += arg
        endif
    elif target_system == 'linux'
    elif target_system == 'cygwin'
    endif
elif target_cpu.startswith('arm')
    if target_system == 'darwin'
        osx_sysroot = 'iphoneos'
    elif target_system == 'linux'
        asm_compiler = find_program('arm-linux-gnueabihf-as', required: false)
        asm_args += [
            '--defsym ARCHITECTURE=7',
            '-march=armv7-a',
            '-mfpu=neon',
            '-mfloat-abi=softfp',
        ]
        args = [
            '-march=armv7-a',
            '-mfpu=vfpv3',
            '-mfloat-abi=softfp',
        ]
        if cc.get_supported_arguments(args)
            c_args += args
            cpp_args += args
        endif
    elif system == 'cygwin'
    endif
elif target_cpu.startswith('ppc')
    if target_system == 'linux'
        asm_compiler = find_program('powerpc64le-linux-gnu-as', required: false)
    endif
elif target_cpu.startswith('riscv')
    if target_system == 'linux'
        asm_compiler = find_program('riscv64-linux-gnu-as', required: false)
    endif
elif target_cpu == 'x86'
    if target_system == 'darwin'
        arg = '-arch i386'
        if cc.get_supported_arguments(arg)
            c_args += arg
            cpp_args += arg
            exec_args += arg
        endif
    elif system in ['linux', 'cygwin']
        arg = '-m32'
        if cc.get_supported_arguments(arg)
            c_args += arg
            cpp_args += arg
            exec_args += arg
        endif
    endif
elif target_cpu == 'x86_64'
    if target_system == 'darwin'
        arg = '-arch x86_64'
        if cc.get_supported_arguments(arg)
            c_args += arg
            cpp_args += arg
            exec_args += arg
        endif
    elif target_system == 'cygwin'
    endif
 endif
