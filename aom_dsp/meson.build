common_c_args  = []
common_objects = []
common_sources = files(
    'aom_dsp_rtcd.c',
    'aom_convolve.c',
    'aom_dsp_common.h',
    'aom_filter.h',
    'aom_simd.h',
    'aom_simd_inline.h',
    'bitreader_buffer.c',
    'bitreader_buffer.h',
    'bitwriter_buffer.c',
    'bitwriter_buffer.h',
    'blend.h',
    'blend_a64_hmask.c',
    'blend_a64_mask.c',
    'blend_a64_vmask.c',
    'entcode.c',
    'entcode.h',
    'grain_params.h',
    'intrapred.c',
    'intrapred_common.h',
    'loopfilter.c',
    'odintrin.c',
    'odintrin.h',
    'prob.h',
    'recenter.h',
    'simd/v128_intrinsics.h',
    'simd/v128_intrinsics_c.h',
    'simd/v256_intrinsics.h',
    'simd/v256_intrinsics_c.h',
    'simd/v64_intrinsics.h',
    'simd/v64_intrinsics_c.h',
    'txfm_common.h',
    'x86/convolve_common_intrin.h',
)

common_asm_sse2 = files(
    'x86/intrapred_asm_sse2.asm'
)
if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
    common_asm_sse2 += files(
        'x86/aom_high_subpixel_8t_sse2.asm',
        'x86/aom_high_subpixel_bilinear_sse2.asm',
        'x86/highbd_intrapred_asm_sse2.asm',
    )
endif

common_sources_sse2 = files(
    'x86/aom_convolve_copy_sse2.c',
    'x86/convolve.h',
    'x86/convolve_sse2.h',
    'x86/intrapred_sse2.c',
    'x86/intrapred_x86.h',
    'x86/loopfilter_sse2.c',
    'x86/lpf_common_sse2.h',
    'x86/mem_sse2.h',
    'x86/transpose_sse2.h',
    'x86/txfm_common_sse2.h',
    'x86/sum_squares_sse2.h',
    'x86/bitdepth_conversion_sse2.h',
)
if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
    common_sources_sse2 += files(
        'x86/highbd_convolve_sse2.c',
        'x86/highbd_intrapred_sse2.c',
        'x86/highbd_loopfilter_sse2.c',
    )
endif

common_asm_ssse3 = files(
    'x86/aom_subpixel_8t_ssse3.asm',
    'x86/aom_subpixel_bilinear_ssse3.asm',
)

common_sources_ssse3 = files(
    'x86/aom_subpixel_8t_intrin_ssse3.c',
    'x86/convolve_ssse3.h',
    'x86/intrapred_ssse3.c',
)
if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
    common_sources_ssse3 += files(
        'x86/highbd_convolve_ssse3.c',
    )
endif

common_sources_sse4_1 = files(
    'x86/blend_mask_sse4.h',
    'x86/blend_a64_hmask_sse4.c',
    'x86/blend_a64_mask_sse4.c',
    'x86/blend_a64_vmask_sse4.c',
    'x86/intrapred_sse4.c',
    'x86/intrapred_utils.h',
)

common_sources_avx2 = files(
    'x86/aom_convolve_copy_avx2.c',
    'x86/aom_subpixel_8t_intrin_avx2.c',
    'x86/common_avx2.h',
    'x86/txfm_common_avx2.h',
    'x86/convolve_avx2.h',
    'x86/intrapred_avx2.c',
    'x86/loopfilter_avx2.c',
    'x86/blend_a64_mask_avx2.c',
    'x86/bitdepth_conversion_avx2.h',
)
if cfg.get('CONFIG_SVT_AV1') == 1
    common_sources_avx2 += files(
        '../third_party/SVT-AV1/convolve_2d_avx2.h',
        '../third_party/SVT-AV1/convolve_avx2.h',
        '../third_party/SVT-AV1/EbMemory_AVX2.h',
        '../third_party/SVT-AV1/EbMemory_SSE4_1.h',
        '../third_party/SVT-AV1/synonyms.h',
    )
endif
if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
    common_sources_avx2 += files(
        'x86/highbd_convolve_avx2.c',
        'x86/highbd_loopfilter_avx2.c',
    )
endif

common_sources_neon = files(
    'arm/aom_convolve_copy_neon.c',
    'arm/aom_convolve8_neon.c',
    'arm/aom_scaled_convolve8_neon.c',
    'arm/loopfilter_neon.c',
    'arm/intrapred_neon.c',
    'arm/blend_a64_mask_neon.c'
)
if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
    common_sources_neon += files(
        'arm/highbd_blend_a64_hmask_neon.c',
        'arm/highbd_blend_a64_mask_neon.c',
        'arm/highbd_blend_a64_vmask_neon.c',
        'arm/highbd_convolve8_neon.c',
        'arm/highbd_intrapred_neon.c',
        'arm/highbd_loopfilter_neon.c',
    )
endif

common_sources_neon_dotprod = files(
    'arm/aom_convolve8_neon_dotprod.c',
    'arm/aom_scaled_convolve8_neon_dotprod.c',
)

common_sources_neon_i8mm = files(
    'arm/aom_convolve8_neon_i8mm.c',
    'arm/aom_scaled_convolve8_neon_i8mm.c',
)

common_sources_sve = []
if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
    common_sources_sve += files(
        'arm/highbd_convolve8_sve.c',
    )
endif

if cfg.get('CONFIG_AV1_DECODER') == 1
    decoder_c_args  = []
    decoder_sources = files(
        'binary_codes_reader.c',
        'binary_codes_reader.h',
        'bitreader.c',
        'bitreader.h',
        'entdec.c',
        'entdec.h',
    )
endif

if cfg.get('CONFIG_AV1_ENCODER') == 1
    encoder_c_args  = []
    encoder_objects = []
    encoder_sources = files(
        'avg.c',
        'bitwriter.c',
        'bitwriter.h',
        'blk_sse_sum.c',
        'entenc.c',
        'entenc.h',
        'fft.c',
        'fft_common.h',
        'fwd_txfm.c',
        'psnr.c',
        'psnr.h',
        'quantize.c',
        'quantize.h',
        'sad.c',
        'sad_av1.c',
        'subtract.c',
        'sse.c',
        'ssim.c',
        'ssim.h',
        'sum_squares.c',
        'variance.c',
        'variance.h',
    )
    # Flow estimation library and grain/noise table/model.
    if cfg.get('CONFIG_REALTIME_ONLY') == 0
        encoder_sources += files(
            'pyramid.c',
            'binary_codes_writer.c',
            'binary_codes_writer.h',
            'flow_estimation/corner_detect.c',
            'flow_estimation/corner_match.c',
            'flow_estimation/disflow.c',
            'flow_estimation/flow_estimation.c',
            'grain_table.c',
            'grain_table.h',
            'noise_model.c',
            'noise_model.h',
            'noise_util.c',
            'noise_util.h',
            'flow_estimation/ransac.c',
        )
    endif

    if cfg.get('CONFIG_INTERNAL_STATS') == 1
        encoder_sources += files(
            'fastssim.c',
            'psnrhvs.c',
        )
    endif

    if cfg.get('CONFIG_TUNE_VMAF') == 1
        encoder_sources += files(
            'vmaf.c',
        )
    endif

    if cfg.get('CONFIG_TUNE_BUTTERAUGLI') == 1
        encoder_sources += files(
            'butteraugli.c',
        )
    endif

    encoder_asm_sse2 = files(
        'x86/sad4d_sse2.asm',
        'x86/sad_sse2.asm',
        'x86/subtract_sse2.asm',
    )
    if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
        encoder_asm_sse2 += files(
            'x86/highbd_sad4d_sse2.asm',
            'x86/highbd_sad_sse2.asm',
            'x86/highbd_subpel_variance_impl_sse2.asm',
            'x86/highbd_variance_impl_sse2.asm',
        )
    endif

    encoder_asm_sse2_x86_64 = files(
        'x86/ssim_sse2_x86_64.asm',
    )

    encoder_sources_sse2 = files(
        'x86/avg_intrin_sse2.c',
        'x86/fft_sse2.c',
        'x86/fwd_txfm_impl_sse2.h',
        'x86/fwd_txfm_sse2.c',
        'x86/fwd_txfm_sse2.h',
        'x86/quantize_sse2.c',
        'x86/adaptive_quantize_sse2.c',
        'x86/quantize_x86.h',
        'x86/blk_sse_sum_sse2.c',
        'x86/sum_squares_sse2.c',
        'x86/variance_sse2.c',
    )
    if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
        encoder_sources_sse2 += files(
            'x86/highbd_adaptive_quantize_sse2.c',
            'x86/highbd_quantize_intrin_sse2.c',
            'x86/highbd_subtract_sse2.c',
            'x86/highbd_variance_sse2.c',
        )
    endif
    if cfg.get('CONFIG_REALTIME_ONLY') == 1
        encoder_sources_sse2.remove(files(
            'x86/adaptive_quantize_sse2.c',
            'x86/highbd_adaptive_quantize_sse2.c',
        ))
    endif

    encoder_asm_ssse3 = files(
        'x86/subpel_variance_ssse3.asm',
    )

    encoder_asm_ssse3_x86_64 = files(
        'x86/fwd_txfm_ssse3_x86_64.asm',
        'x86/quantize_ssse3_x86_64.asm',
    )

    encoder_sources_ssse3 = files(
        'x86/masked_sad_intrin_ssse3.h',
        'x86/masked_sad_intrin_ssse3.c',
        'x86/masked_variance_intrin_ssse3.h',
        'x86/masked_variance_intrin_ssse3.c',
        'x86/quantize_ssse3.c',
        'x86/variance_impl_ssse3.c',
        'x86/variance_ssse3.c',
    )

    encoder_sources_sse4_1 = files(
        'x86/avg_intrin_sse4.c',
        'x86/sse_sse4.c',
        'x86/obmc_sad_sse4.c',
        'x86/obmc_variance_sse4.c',
    )
    if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
        encoder_sources_sse4_1 += files(
            'x86/highbd_variance_sse4.c',
        )
    endif
    if cfg.get('CONFIG_REALTIME_ONLY') == 0
        encoder_sources_sse4_1 += files(
            'flow_estimation/x86/corner_match_sse4.c',
            'flow_estimation/x86/disflow_sse4.c',
        )
    else
        encoder_sources_sse4_1.remove(files(
            'x86/obmc_sad_sse4.c',
            'x86/obmc_variance_sse4.c',
        ))
    endif

    encoder_sources_avx = files(
        'x86/aom_quantize_avx.c',
    )

    encoder_sources_avx2 = files(
        'x86/avg_intrin_avx2.c',
        'x86/fft_avx2.c',
        'x86/masked_sad_intrin_avx2.c',
        'x86/subtract_avx2.c',
        'x86/adaptive_quantize_avx2.c',
        'x86/quantize_avx2.c',
        'x86/sad4d_avx2.c',
        'x86/sad_avx2.c',
        'x86/sad_impl_avx2.c',
        'x86/variance_avx2.c',
        'x86/sse_avx2.c',
        'x86/variance_impl_avx2.c',
        'x86/obmc_sad_avx2.c',
        'x86/obmc_variance_avx2.c',
        'x86/blk_sse_sum_avx2.c',
        'x86/sum_squares_avx2.c',
    )
    if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
        encoder_sources_avx2 += files(
            'x86/highbd_adaptive_quantize_avx2.c',
            'x86/highbd_quantize_intrin_avx2.c',
            'x86/highbd_sad_avx2.c',
            'x86/highbd_variance_avx2.c',
        )
    endif
    if cfg.get('CONFIG_REALTIME_ONLY') == 0
        encoder_sources_avx2 += files(
            'flow_estimation/x86/corner_match_avx2.c',
            'flow_estimation/x86/disflow_avx2.c',
        )
    else
        encoder_sources_avx2.remove(files(
            'x86/adaptive_quantize_avx2.c',
            'x86/highbd_adaptive_quantize_avx2.c',
            'x86/obmc_sad_avx2.c',
            'x86/obmc_variance_avx2.c',
        ))
    endif

    encoder_sources_neon = files(
        'arm/avg_pred_neon.c',
        'arm/fwd_txfm_neon.c',
        'arm/sadxd_neon.c',
        'arm/sad_neon.c',
        'arm/masked_sad_neon.c',
        'arm/subpel_variance_neon.c',
        'arm/variance_neon.c',
        'arm/hadamard_neon.c',
        'arm/avg_neon.c',
        'arm/obmc_variance_neon.c',
        'arm/obmc_sad_neon.c',
        'arm/sse_neon.c',
        'arm/subtract_neon.c',
        'arm/sum_squares_neon.c',
        'arm/blk_sse_sum_neon.c',
    )
    if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
        encoder_sources_neon += files(
            'arm/highbd_avg_neon.c',
            'arm/highbd_avg_pred_neon.c',
            'arm/highbd_hadamard_neon.c',
            'arm/highbd_masked_sad_neon.c',
            'arm/highbd_obmc_sad_neon.c',
            'arm/highbd_obmc_variance_neon.c',
            'arm/highbd_quantize_neon.c',
            'arm/highbd_sad_neon.c',
            'arm/highbd_sadxd_neon.c',
            'arm/highbd_sse_neon.c',
            'arm/highbd_subpel_variance_neon.c',
            'arm/highbd_variance_neon.c',
        )
    endif
    if cfg.get('CONFIG_REALTIME_ONLY') == 0
        encoder_sources_neon += files(
            'flow_estimation/arm/disflow_neon.c',
        )
    else
        encoder_sources_neon.remove(files(
            'arm/highbd_obmc_sad_neon.c',
            'arm/highbd_obmc_variance_neon.c',
            'arm/obmc_sad_neon.c',
            'arm/obmc_variance_neon.c',
        ))
    endif

    encoder_sources_neon_dotprod = files(
        'arm/sad_neon_dotprod.c',
        'arm/sadxd_neon_dotprod.c',
        'arm/sse_neon_dotprod.c',
        'arm/sum_squares_neon_dotprod.c',
        'arm/variance_neon_dotprod.c',
    )
    if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
        encoder_sources_neon_dotprod += files(
            'arm/highbd_variance_neon_dotprod.c',
        )
    endif

    encoder_sources_sve = files(
        'arm/avg_sve.c',
        'arm/blk_sse_sum_sve.c',
        'arm/sum_squares_sve.c',
    )
    if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
        encoder_sources_sve += files(
            'arm/highbd_sse_sve.c',
            'arm/highbd_variance_sve.c',
        )
    endif
    if cfg.get('CONFIG_REALTIME_ONLY') == 0
        encoder_sources_sve += files(
            'flow_estimation/arm/disflow_sve.c',
        )
    endif
endif

if cfg.get('HAVE_SSE2') == 1
    common_objects += asm_gen.process(common_asm_sse2)
    common_sources += common_sources_sse2
    common_c_args += sse2_args
    if cfg.get('CONFIG_AV1_ENCODER') == 1
        if target_cpu == 'x86_64'
            encoder_objects += asm_gen.process(encoder_asm_sse2_x86_64)
        endif
        encoder_objects += asm_gen.process(encoder_asm_sse2)
        encoder_sources += encoder_sources_sse2
        encoder_c_args += sse2_args
    endif
endif

if cfg.get('HAVE_SSSE3') == 1
    common_objects += asm_gen.process(common_asm_ssse3)
    common_sources += common_sources_ssse3
    common_c_args += ssse3_args
    if cfg.get('CONFIG_AV1_ENCODER') == 1
        if target_cpu == 'x86_64'
            encoder_objects += asm_gen.process(encoder_asm_ssse3_x86_64)
        endif
        encoder_objects += asm_gen.process(encoder_asm_ssse3)
        encoder_sources += encoder_sources_ssse3
        encoder_c_args += ssse3_args
    endif
endif

if cfg.get('HAVE_SSE4_1') == 1
    common_sources += common_sources_sse4_1
    common_c_args += sse4_1_args
    if cfg.get('CONFIG_AV1_ENCODER') == 1
        encoder_sources += encoder_sources_sse4_1
        encoder_c_args += sse4_1_args
    endif
endif

if cfg.get('HAVE_AVX') == 1
    if cfg.get('CONFIG_AV1_ENCODER') == 1
        encoder_sources += encoder_sources_avx
        encoder_c_args += avx_args
    endif
endif

if cfg.get('HAVE_AVX2') == 1
    common_sources += common_sources_avx2
    common_c_args += avx2_args
    if cfg.get('CONFIG_AV1_ENCODER') == 1
        encoder_sources += encoder_sources_avx2
        encoder_c_args += avx2_args
    endif
endif

if cfg.get('HAVE_NEON') == 1
    common_sources += common_sources_neon
    if cfg.get('CONFIG_AV1_ENCODER') == 1
    #    encoder_sources += encoder_sources_NEON
    endif
endif

if cfg.get('HAVE_NEON_DOTPROD') == 1
    common_sources += common_sources_neon_dotprod
    common_c_args += neon_dotprod_args
    if cfg.get('CONFIG_AV1_ENCODER') == 1
    #    encoder_sources += encoder_sources_NEON_DOTPROD
    endif
endif

if cfg.get('HAVE_NEON_I8MM') == 1
    common_sources += common_sources_neon_i8mm
    common_c_args += neon_i8mm_args
endif

if cfg.get('HAVE_SVE') == 1
    common_sources += common_sources_sve
    common_c_args += sve_args
    if cfg.get('CONFIG_AV1_ENCODER') == 1
    #    encoder_sources += encoder_sources_SVE
    endif
endif

lib_targets += static_library('aom_dsp_common',
                objects: common_objects,
                sources: common_sources,
                 c_args: common_c_args,
    include_directories: lib_incs)

if cfg.get('CONFIG_AV1_DECODER') == 1
    lib_targets += static_library('aom_dsp_decoder',
                    sources: decoder_sources,
                     c_args: decoder_c_args,
        include_directories: lib_incs)
endif

if cfg.get('CONFIG_AV1_ENCODER') == 1
    lib_targets += static_library('aom_dsp_encoder',
                    objects: encoder_objects,
                    sources: encoder_sources,
                     c_args: encoder_c_args,
        include_directories: lib_incs)
endif
