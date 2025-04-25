includes = files(
    'aom_once.h',
    'aom_timer.h',
    'bitops.h',
    'emmintrin_compat.h',
    'mem.h',
    'mem_ops.h',
    'mem_ops_aligned.h',
    'sanitizer.h',
)

sources_x86 = files(
    'float.asm',
#   'x86_abi_support.asm',
)

sources_aarch32 = files(
    'aarch32_cpudetect.c',
)

sources_aarch64 = files(
    'aarch64_cpudetect.c',
)

sources_ppc = files(
    'ppc.h',
    'ppc_cpudetect.c',
)

sources_riscv = files(
    'riscv.h',
    'riscv_cpudetect.c',
)

# For arm and x86 targets:
#
# * Creates the aom_ports build target, adds the includes in aom_ports to the
#   target, and makes libaom depend on it.
#
# Otherwise:
#
# * Adds the includes in aom_ports to the libaom target.
#
# For all target platforms:
#
# * The libaom target must exist before this function is called.
objects = []
sources = []

if target_cpu == 'x86_64'
    if get_option('backend') == 'xcode'
    endif
    objects += asm_gen.process(sources_x86)
elif target_cpu == 'arm64'
    sources = sources_aarch64
elif target_cpu.startswith('arm')
    sources = sources_aarch32
elif target_cpu.startswith('ppc')
    sources = sources_ppc
elif target_cpu.startswith('riscv')
    sources = sources_riscv
endif

if objects.length() > 0 or sources.length() > 0
    lib_targets += static_library('aom_ports',
        objects: objects,
        sources: sources,
        include_directories: lib_incs)
endif
