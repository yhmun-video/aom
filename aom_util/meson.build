sources = files(
    'aom_pthread.h',
    'aom_thread.c',
    'aom_thread.h',
    'endian_inl.h',
)

if cfg.get('CONFIG_BITSTREAM_DEBUG') == 1
    sources += files(
        'debug_util.c',
        'debug_util.h',
    )
endif

lib_targets += static_library('aom_util',
    sources: sources,
    include_directories: lib_incs)
