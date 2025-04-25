project('aom', 'c',
    version: '3.12.1',
    license: [
        'BSD-2-clause',
        'PATENTS',
    ],
    license_files: [
        'LICENSE',
        'PATENTS',
    ],
    meson_version: '>= 1.1.0',
)

lib_name        = meson.project_name()
lib_version     = meson.project_version()
lib_src_dir     = meson.current_source_dir()
lib_dst_dir     = meson.current_build_dir()
lib_incs        = include_directories('.')
lib_targets     = []
lib_headers     = []

install_prefix  = get_option('prefix')
install_inc_dir = join_paths(install_prefix, get_option('includedir'), lib_name)
install_lib_dir = join_paths(install_prefix, get_option('libdir'))
install_bin_dir = join_paths(install_prefix, get_option('bindir'))
install_dat_dir = join_paths(install_prefix, get_option('datadir'), lib_name)

cc              = meson.get_compiler('c')
asm_compiler    = disabler()
c_args          = []
cpp_args        = []
asm_args        = []
link_args       = []
exec_args       = []
rtcd_args       = []

subdir('config')

add_global_arguments(c_args, language: 'c')
add_global_link_arguments(link_args, language: 'c')

if cfg.get('CONFIG_THREE_PASS') == 1
    subdir('common')
endif

subdir('aom_dsp')
subdir('aom_mem')
subdir('aom_ports')
subdir('aom_scale')
subdir('aom_util')
subdir('av1')
subdir('aom')

#include("${AOM_ROOT}/build/cmake/aom_install.cmake")
#include("${AOM_ROOT}/build/cmake/sanitizers.cmake")
#include("${AOM_ROOT}/build/cmake/util.cmake")
#include("${AOM_ROOT}/test/test.cmake")

if get_option('ENABLE_EXAMPLES')
    #add_library(aom_encoder_stats OBJECT ${AOM_ENCODER_STATS_SOURCES})
    #set(AOM_LIB_TARGETS ${AOM_LIB_TARGETS} aom_encoder_stats)
endif

aom_dep = declare_dependency(link_with: aom_lib, include_directories: include_directories('aom'))

# Generate aom.pc and setup install rule.
pkg = import('pkgconfig')
pkg.generate(name: lib_name,
         filebase: lib_name,
          version: lib_version,
          subdirs: lib_name,
        libraries: aom_lib,
      description: 'Description: Alliance for Open Media AV1 codec library v@0@.'.format(lib_version))

install_headers(lib_headers, install_dir: install_inc_dir)

install_data(meson.project_license_files(),
    install_dir: join_paths(install_prefix, get_option('datadir'), 'licenses', lib_name))
