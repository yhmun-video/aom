lib_headers = files(
    'aom.h',
    'aom_codec.h',
    'aom_decoder.h',
    'aom_encoder.h',
    'aom_external_partition.h',
    'aom_frame_buffer.h',
    'aom_image.h',
    'aom_integer.h',
    'aomcx.h',
    'aomdx.h',
)

sources = files(
#   'config/aom_config.c',
#   'config/aom_config.h',
    'internal/aom_codec_internal.h',
    'internal/aom_image_internal.h',
    'src/aom_codec.c',
    'src/aom_decoder.c',
    'src/aom_encoder.c',
    'src/aom_image.c',
    'src/aom_integer.c',
)

aom_lib = library(lib_name,
                sources: sources,
    include_directories: lib_incs,
              link_with: lib_targets,
                version: lib_version,
              soversion: lib_version.split('.')[0],
            install_dir: install_lib_dir,
                install: true,
)
