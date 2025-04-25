sources = files(
    'aom_scale_rtcd.c',
    'generic/yv12config.c',
    'generic/yv12extend.c',
    'yv12config.h',
)

lib_targets += static_library('aom_scale',
    sources: sources,
    include_directories: lib_incs)
