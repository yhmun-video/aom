# CPUs.
cfg.set10('AOM_ARCH_AARCH64'                    , false)    # Enables AArch64 architecture.
cfg.set10('AOM_ARCH_ARM'                        , false)    # Enables ARM architecture.
cfg.set10('AOM_ARCH_PPC'                        , false)    # Enables PPC architecture.
cfg.set10('AOM_ARCH_X86'                        , false)    # Enables X86 architecture.
cfg.set10('AOM_ARCH_X86_64'                     , false)    # Enables X86_64 architecture.
cfg.set10('AOM_ARCH_RISCV'                      , false)    # Enables RISC-V architecture.

# Arm/AArch64 feature flags.
cfg.set10('HAVE_NEON'                           , false)    # Enables Neon intrinsics optimizations.
cfg.set10('HAVE_ARM_CRC32'                      , false)    # Enables Arm CRC32 optimizations.
cfg.set10('HAVE_NEON_DOTPROD'                   , false)    # Enables Armv8.2-A Neon dotprod intrinsics optimizations.
cfg.set10('HAVE_NEON_I8MM'                      , false)    # Enables Armv8.2-A Neon i8mm intrinsics optimizations.
cfg.set10('HAVE_SVE'                            , false)    # Enables Armv8.2-A SVE intrinsics optimizations.
cfg.set10('HAVE_SVE2'                           , false)    # Enables Armv9-A SVE2 intrinsics optimizations.

# PPC feature flags.
cfg.set10('HAVE_VSX'                            , false)    # Enables VSX optimizations.

# x86/x86_64 feature flags.
cfg.set10('HAVE_MMX'                            , false)    # Enables MMX optimizations.
cfg.set10('HAVE_SSE'                            , false)    # Enables SSE optimizations.
cfg.set10('HAVE_SSE2'                           , false)    # Enables SSE2 optimizations.
cfg.set10('HAVE_SSE3'                           , false)    # Enables SSE3 optimizations.
cfg.set10('HAVE_SSSE3'                          , false)    # Enables SSSE3 optimizations.
cfg.set10('HAVE_SSE4_1'                         , false)    # Enables SSE 4.1 optimizations.
cfg.set10('HAVE_SSE4_2'                         , false)    # Enables SSE 4.2 optimizations.
cfg.set10('HAVE_AVX'                            , false)    # Enables AVX optimizations.
cfg.set10('HAVE_AVX2'                           , false)    # Enables AVX2 optimizations.

# RISC-V64 feature flags.
cfg.set10('HAVE_RVV'                            , false)    # Enables RVV optimizations.

# Flags describing the build environment.
cfg.set10('HAVE_FEXCEPT'                        , false)    # Internal flag, GNU fenv.h present for target.
cfg.set10('HAVE_PTHREAD_H'                      , false)    # Internal flag, target pthread support.
cfg.set10('HAVE_UNISTD_H'                       , false)    # Internal flag, unistd.h present for target.
cfg.set10('HAVE_WXWIDGETS'                      , false)    # WxWidgets present.

# Build configuration flags.
cfg.set_quoted('AOM_RTCD_FLAGS'                 , get_option('AOM_RTCD_FLAGS'))
cfg.set10('CONFIG_AV1_DECODER'                  , get_option('CONFIG_AV1_DECODER'))
cfg.set10('CONFIG_AV1_ENCODER'                  , get_option('CONFIG_AV1_ENCODER'))
cfg.set10('CONFIG_BIG_ENDIAN'                   , get_option('CONFIG_BIG_ENDIAN'))
cfg.set10('CONFIG_FPMT_TEST'                    , get_option('CONFIG_FPMT_TEST'))
cfg.set10('CONFIG_GCC'                          , get_option('CONFIG_GCC'))
cfg.set10('CONFIG_GCOV'                         , get_option('CONFIG_GCOV'))
cfg.set10('CONFIG_GPROF'                        , get_option('CONFIG_GPROF'))
cfg.set10('CONFIG_LIBYUV'                       , get_option('CONFIG_LIBYUV'))
cfg.set10('CONFIG_SVT_AV1'                      , get_option('CONFIG_SVT_AV1'))
cfg.set10('CONFIG_AV1_HIGHBITDEPTH'             , get_option('CONFIG_AV1_HIGHBITDEPTH'))
cfg.set10('CONFIG_AV1_TEMPORAL_DENOISING'       , get_option('CONFIG_AV1_TEMPORAL_DENOISING'))
cfg.set10('CONFIG_MULTITHREAD'                  , get_option('CONFIG_MULTITHREAD'))
cfg.set10('CONFIG_OS_SUPPORT'                   , get_option('CONFIG_RUNTIME_CPU_DETECT'))
cfg.set10('CONFIG_PIC'                          , get_option('CONFIG_PIC'))
cfg.set10('CONFIG_QUANT_MATRIX'                 , get_option('CONFIG_QUANT_MATRIX'))
cfg.set10('CONFIG_REALTIME_ONLY'                , get_option('CONFIG_REALTIME_ONLY'))
cfg.set10('CONFIG_RUNTIME_CPU_DETECT'           , get_option('CONFIG_RUNTIME_CPU_DETECT'))
cfg.set10('CONFIG_SHARED'                       , get_option('CONFIG_SHARED'))
cfg.set10('CONFIG_WEBM_IO'                      , get_option('CONFIG_WEBM_IO'))

# Debugging flags.
cfg.set10('CONFIG_DEBUG'                        , get_option('CONFIG_DEBUG'))
cfg.set10('CONFIG_EXCLUDE_SIMD_MISMATCH'        , get_option('CONFIG_EXCLUDE_SIMD_MISMATCH'))
cfg.set10('CONFIG_MISMATCH_DEBUG'               , get_option('CONFIG_MISMATCH_DEBUG'))

# AV1 feature flags.
cfg.set10('CONFIG_ACCOUNTING'                   , get_option('CONFIG_ACCOUNTING'))
cfg.set10('CONFIG_ANALYZER'                     , get_option('CONFIG_ANALYZER'))
cfg.set10('CONFIG_COEFFICIENT_RANGE_CHECKING'   , get_option('CONFIG_COEFFICIENT_RANGE_CHECKING'))
cfg.set10('CONFIG_DENOISE'                      , get_option('CONFIG_DENOISE'))
cfg.set10('CONFIG_INSPECTION'                   , get_option('CONFIG_INSPECTION'))
cfg.set10('CONFIG_INTERNAL_STATS'               , get_option('CONFIG_INTERNAL_STATS'))
cfg.set10('FORCE_HIGHBITDEPTH_DECODING'         , get_option('FORCE_HIGHBITDEPTH_DECODING'))
cfg.set  ('CONFIG_MAX_DECODE_PROFILE'           , get_option('CONFIG_MAX_DECODE_PROFILE'))
cfg.set10('CONFIG_NORMAL_TILE_MODE'             , get_option('CONFIG_NORMAL_TILE_MODE'))
cfg.set10('CONFIG_SIZE_LIMIT'                   , get_option('CONFIG_SIZE_LIMIT'))
cfg.set10('CONFIG_TUNE_BUTTERAUGLI'             , get_option('CONFIG_TUNE_BUTTERAUGLI'))
cfg.set10('CONFIG_TUNE_VMAF'                    , get_option('CONFIG_TUNE_VMAF'))
cfg.set10('DECODE_HEIGHT_LIMIT'                 , get_option('DECODE_HEIGHT_LIMIT'))
cfg.set10('DECODE_WIDTH_LIMIT'                  , get_option('DECODE_WIDTH_LIMIT'))
cfg.set10('STATIC_LINK_JXL'                     , get_option('STATIC_LINK_JXL'))

# AV1 experiment flags.
cfg.set10('CONFIG_BITRATE_ACCURACY'             , get_option('CONFIG_BITRATE_ACCURACY'))
cfg.set10('CONFIG_BITRATE_ACCURACY_BL'          , get_option('CONFIG_BITRATE_ACCURACY_BL'))
cfg.set10('CONFIG_BITSTREAM_DEBUG'              , get_option('CONFIG_BITSTREAM_DEBUG'))
cfg.set10('CONFIG_COLLECT_COMPONENT_TIMING'     , get_option('CONFIG_COLLECT_COMPONENT_TIMING'))
cfg.set10('CONFIG_COLLECT_PARTITION_STATS'      , get_option('CONFIG_COLLECT_PARTITION_STATS'))
cfg.set10('CONFIG_COLLECT_RD_STATS'             , get_option('CONFIG_COLLECT_RD_STATS'))
cfg.set10('CONFIG_DISABLE_FULL_PIXEL_SPLIT_8X8' , get_option('CONFIG_DISABLE_FULL_PIXEL_SPLIT_8X8'))
cfg.set10('CONFIG_ENTROPY_STATS'                , get_option('CONFIG_ENTROPY_STATS'))
cfg.set10('CONFIG_INTER_STATS_ONLY'             , get_option('CONFIG_INTER_STATS_ONLY'))
cfg.set10('CONFIG_NN_V2'                        , get_option('CONFIG_NN_V2'))
cfg.set10('CONFIG_OPTICAL_FLOW_API'             , get_option('CONFIG_OPTICAL_FLOW_API'))
cfg.set10('CONFIG_PARTITION_SEARCH_ORDER'       , get_option('CONFIG_PARTITION_SEARCH_ORDER'))
cfg.set10('CONFIG_RATECTRL_LOG'                 , get_option('CONFIG_RATECTRL_LOG'))
cfg.set10('CONFIG_RD_COMMAND'                   , get_option('CONFIG_RD_COMMAND'))
cfg.set10('CONFIG_RD_DEBUG'                     , get_option('CONFIG_RD_DEBUG'))
cfg.set10('CONFIG_RT_ML_PARTITIONING'           , get_option('CONFIG_RT_ML_PARTITIONING'))
cfg.set10('CONFIG_SPEED_STATS'                  , get_option('CONFIG_SPEED_STATS'))
cfg.set10('CONFIG_TFLITE'                       , get_option('CONFIG_TFLITE'))
cfg.set10('CONFIG_THREE_PASS'                   , get_option('CONFIG_THREE_PASS'))
cfg.set10('CONFIG_OUTPUT_FRAME_SIZE'            , get_option('CONFIG_OUTPUT_FRAME_SIZE'))
cfg.set10('CONFIG_SALIENCY_MAP'                 , get_option('CONFIG_SALIENCY_MAP'))
cfg.set10('CONFIG_CWG_C013'                     , get_option('CONFIG_CWG_C013'))
cfg.set10('CONFIG_CWG_E050'                     , get_option('CONFIG_CWG_E050'))
cfg.set10('CONFIG_LIBVMAF_PSNR_PEAK'            , get_option('CONFIG_LIBVMAF_PSNR_PEAK'))
