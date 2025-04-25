common_c_args  = []
common_sources = files(
    'common/av1_rtcd.c',
    '../common/args_helper.h',
    '../common/args_helper.c',
    'arg_defs.h',
    'arg_defs.c',
    'av1_iface_common.h',
    'common/alloccommon.c',
    'common/alloccommon.h',
    'common/av1_common_int.h',
    'common/av1_inv_txfm1d.c',
    'common/av1_inv_txfm1d.h',
    'common/av1_inv_txfm1d_cfg.h',
    'common/av1_inv_txfm2d.c',
    'common/av1_loopfilter.c',
    'common/av1_loopfilter.h',
    'common/av1_txfm.c',
    'common/av1_txfm.h',
    'common/blockd.c',
    'common/blockd.h',
    'common/cdef.c',
    'common/cdef.h',
    'common/cdef_block.c',
    'common/cdef_block.h',
    'common/cfl.c',
    'common/cfl.h',
    'common/common.h',
    'common/common_data.c',
    'common/common_data.h',
    'common/convolve.c',
    'common/convolve.h',
    'common/debugmodes.c',
    'common/entropy.c',
    'common/entropy.h',
    'common/entropymode.c',
    'common/entropymode.h',
    'common/entropymv.c',
    'common/entropymv.h',
    'common/enums.h',
    'common/filter.h',
    'common/frame_buffers.c',
    'common/frame_buffers.h',
    'common/idct.c',
    'common/idct.h',
    'common/mv.h',
    'common/mvref_common.c',
    'common/mvref_common.h',
    'common/obu_util.c',
    'common/obu_util.h',
    'common/pred_common.c',
    'common/pred_common.h',
    'common/quant_common.c',
    'common/quant_common.h',
    'common/reconinter.c',
    'common/reconinter.h',
#   'common/reconinter_template.inc',
    'common/reconintra.c',
    'common/reconintra.h',
    'common/resize.c',
    'common/resize.h',
    'common/restoration.c',
    'common/restoration.h',
    'common/scale.c',
    'common/scale.h',
    'common/scan.c',
    'common/scan.h',
    'common/seg_common.c',
    'common/seg_common.h',
    'common/thread_common.c',
    'common/thread_common.h',
    'common/tile_common.c',
    'common/tile_common.h',
    'common/timing.c',
    'common/timing.h',
    'common/token_cdfs.h',
    'common/txb_common.c',
    'common/txb_common.h',
    'common/warped_motion.c',
    'common/warped_motion.h',
)

common_sources_sse2 = files(
    'common/x86/av1_txfm_sse2.h',
    'common/x86/cfl_sse2.c',
    'common/x86/convolve_2d_sse2.c',
    'common/x86/convolve_sse2.c',
    'common/x86/jnt_convolve_sse2.c',
    'common/x86/resize_sse2.c',
    'common/x86/wiener_convolve_sse2.c',
)

common_sources_ssse3 = files(
    'common/x86/av1_inv_txfm_ssse3.c',
    'common/x86/av1_inv_txfm_ssse3.h',
    'common/x86/cfl_ssse3.c',
    'common/x86/jnt_convolve_ssse3.c',
    'common/x86/resize_ssse3.c',
)
if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
    common_sources_ssse3 += files(
        'common/x86/highbd_convolve_2d_ssse3.c',
        'common/x86/highbd_wiener_convolve_ssse3.c',
        'common/x86/reconinter_ssse3.c',
    )
endif

# Fallbacks to support Valgrind on 32-bit x86
common_sources_ssse3_x86 = files(
    'common/x86/cdef_block_ssse3.c',
)

common_sources_sse4_1 = files(
    'common/x86/av1_convolve_horiz_rs_sse4.c',
    'common/x86/av1_convolve_scale_sse4.c',
    'common/x86/av1_txfm_sse4.c',
    'common/x86/av1_txfm_sse4.h',
    'common/x86/cdef_block_sse4.c',
    'common/x86/filterintra_sse4.c',
    'common/x86/highbd_inv_txfm_sse4.c',
    'common/x86/intra_edge_sse4.c',
    'common/x86/reconinter_sse4.c',
    'common/x86/selfguided_sse4.c',
    'common/x86/warp_plane_sse4.c',
)
if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
    common_sources_sse4_1 += files(
        'common/x86/highbd_convolve_2d_sse4.c',
        'common/x86/highbd_jnt_convolve_sse4.c',
        'common/x86/highbd_warp_plane_sse4.c',
    )
endif

common_sources_avx2 = files(
    'common/x86/av1_inv_txfm_avx2.c',
    'common/x86/av1_inv_txfm_avx2.h',
    'common/x86/cdef_block_avx2.c',
    'common/x86/cfl_avx2.c',
    'common/x86/convolve_2d_avx2.c',
    'common/x86/convolve_avx2.c',
    'common/x86/highbd_inv_txfm_avx2.c',
    'common/x86/jnt_convolve_avx2.c',
    'common/x86/reconinter_avx2.c',
    'common/x86/resize_avx2.c',
    'common/x86/selfguided_avx2.c',
    'common/x86/warp_plane_avx2.c',
    'common/x86/wiener_convolve_avx2.c',
)
if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
    common_sources_avx2 += files(
        'common/x86/highbd_convolve_2d_avx2.c',
        'common/x86/highbd_jnt_convolve_avx2.c',
        'common/x86/highbd_wiener_convolve_avx2.c',
        'common/x86/highbd_warp_affine_avx2.c',
    )
endif

common_sources_neon = files(
    'common/arm/av1_convolve_horiz_rs_neon.c',
    'common/arm/av1_convolve_scale_neon.c',
    'common/arm/av1_inv_txfm_neon.c',
    'common/arm/av1_inv_txfm_neon.h',
    'common/arm/av1_txfm_neon.c',
    'common/arm/blend_a64_hmask_neon.c',
    'common/arm/blend_a64_vmask_neon.c',
    'common/arm/cdef_block_neon.c',
    'common/arm/cfl_neon.c',
    'common/arm/compound_convolve_neon.c',
    'common/arm/convolve_neon.c',
    'common/arm/convolve_neon.h',
    'common/arm/highbd_inv_txfm_neon.c',
    'common/arm/reconinter_neon.c',
    'common/arm/reconintra_neon.c',
    'common/arm/resize_neon.c',
    'common/arm/selfguided_neon.c',
    'common/arm/warp_plane_neon.c',
    'common/arm/wiener_convolve_neon.c',
)
if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
    common_sources_neon += files(
        'common/arm/highbd_compound_convolve_neon.c',
        'common/arm/highbd_convolve_horiz_rs_neon.c',
        'common/arm/highbd_convolve_neon.c',
        'common/arm/highbd_convolve_scale_neon.c',
        'common/arm/highbd_reconinter_neon.c',
        'common/arm/highbd_reconintra_neon.c',
        'common/arm/highbd_warp_plane_neon.c',
        'common/arm/highbd_wiener_convolve_neon.c',
    )
endif

common_sources_neon_dotprod = files(
    'common/arm/av1_convolve_scale_neon_dotprod.c',
    'common/arm/compound_convolve_neon_dotprod.c',
    'common/arm/convolve_neon_dotprod.c',
    'common/arm/resize_neon_dotprod.c',
)

common_sources_neon_i8mm = files(
    'common/arm/av1_convolve_scale_neon_i8mm.c',
    'common/arm/compound_convolve_neon_i8mm.c',
    'common/arm/convolve_neon_i8mm.c',
    'common/arm/resize_neon_i8mm.c',
    'common/arm/warp_plane_neon_i8mm.c',
)

common_sources_sve = files(
    'common/arm/highbd_warp_plane_sve.c',
    'common/arm/warp_plane_sve.c',
)

common_sources_sve2 = files(
    'common/arm/convolve_sve2.c',
)
if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
    common_sources_sve2 += files(
        'common/arm/highbd_compound_convolve_sve2.c',
        'common/arm/highbd_convolve_sve2.c',
    )
endif

common_sources_vsx = files(
    'common/ppc/cfl_ppc.c',
)

common_sources_rvv = files(
    'common/riscv/cdef_block_rvv.c',
)

if cfg.get('CONFIG_AV1_DECODER') == 1
    decoder_c_args  = []
    decoder_objects = []
    decoder_sources = files(
        'av1_dx_iface.c',
        'decoder/decodeframe.c',
        'decoder/decodeframe.h',
        'decoder/decodemv.c',
        'decoder/decodemv.h',
        'decoder/decoder.c',
        'decoder/decoder.h',
        'decoder/decodetxb.c',
        'decoder/decodetxb.h',
        'decoder/detokenize.c',
        'decoder/detokenize.h',
        'decoder/dthread.h',
        'decoder/grain_synthesis.c',
        'decoder/grain_synthesis.h',
        'decoder/obu.h',
        'decoder/obu.c',
    )

    if cfg.get('CONFIG_ACCOUNTING') == 1
        decoder_sources += files(
            'decoder/accounting.c',
            'decoder/accounting.h',
        )
    endif

    if cfg.get('CONFIG_INSPECTION') == 1
        decoder_sources += files(
            'decoder/inspection.c',
            'decoder/inspection.h',
        )
    endif
endif

if cfg.get('CONFIG_AV1_ENCODER') == 1
    encoder_c_args  = []
    encoder_objects = []
    encoder_sources = files(
        'av1_cx_iface.c',
        'av1_cx_iface.h',
        'encoder/aq_complexity.c',
        'encoder/aq_complexity.h',
        'encoder/aq_cyclicrefresh.c',
        'encoder/aq_cyclicrefresh.h',
        'encoder/aq_variance.c',
        'encoder/aq_variance.h',
        'encoder/allintra_vis.c',
        'encoder/allintra_vis.h',
        'encoder/enc_enums.h',
        'encoder/av1_fwd_txfm1d.c',
        'encoder/av1_fwd_txfm1d.h',
        'encoder/av1_fwd_txfm1d_cfg.h',
        'encoder/av1_fwd_txfm2d.c',
        'encoder/av1_quantize.c',
        'encoder/av1_quantize.h',
        'encoder/bitstream.c',
        'encoder/bitstream.h',
        'encoder/block.h',
        'encoder/cnn.c',
        'encoder/cnn.h',
        'encoder/compound_type.c',
        'encoder/compound_type.h',
        'encoder/context_tree.c',
        'encoder/context_tree.h',
        'encoder/cost.c',
        'encoder/cost.h',
        'encoder/encodeframe.c',
        'encoder/encodeframe.h',
        'encoder/encodeframe_utils.c',
        'encoder/encodeframe_utils.h',
        'encoder/encodemb.c',
        'encoder/encodemb.h',
        'encoder/encodemv.c',
        'encoder/encodemv.h',
        'encoder/encode_strategy.c',
        'encoder/encode_strategy.h',
        'encoder/encoder.c',
        'encoder/encoder.h',
        'encoder/encoder_alloc.h',
        'encoder/encoder_utils.c',
        'encoder/encoder_utils.h',
        'encoder/encodetxb.c',
        'encoder/encodetxb.h',
        'encoder/ethread.c',
        'encoder/ethread.h',
        'encoder/extend.c',
        'encoder/extend.h',
        'encoder/external_partition.c',
        'encoder/external_partition.h',
        'encoder/firstpass.c',
        'encoder/firstpass.h',
        'encoder/global_motion.c',
        'encoder/global_motion.h',
        'encoder/global_motion_facade.c',
        'encoder/global_motion_facade.h',
        'encoder/gop_structure.c',
        'encoder/gop_structure.h',
        'encoder/grain_test_vectors.h',
        'encoder/hash.c',
        'encoder/hash.h',
        'encoder/hash_motion.c',
        'encoder/hash_motion.h',
        'encoder/hybrid_fwd_txfm.c',
        'encoder/hybrid_fwd_txfm.h',
        'encoder/interp_search.c',
        'encoder/interp_search.h',
        'encoder/level.c',
        'encoder/level.h',
        'encoder/lookahead.c',
        'encoder/lookahead.h',
        'encoder/mcomp.c',
        'encoder/mcomp.h',
        'encoder/mcomp_structs.h',
        'encoder/ml.c',
        'encoder/ml.h',
        'encoder/model_rd.h',
        'encoder/motion_search_facade.c',
        'encoder/motion_search_facade.h',
        'encoder/mv_prec.c',
        'encoder/mv_prec.h',
        'encoder/palette.c',
        'encoder/palette.h',
        'encoder/partition_search.h',
        'encoder/partition_search.c',
        'encoder/partition_strategy.h',
        'encoder/partition_strategy.c',
        'encoder/pass2_strategy.h',
        'encoder/pass2_strategy.c',
        'encoder/pickcdef.c',
        'encoder/pickcdef.h',
        'encoder/picklpf.c',
        'encoder/picklpf.h',
        'encoder/pickrst.c',
        'encoder/pickrst.h',
        'encoder/ratectrl.c',
        'encoder/ratectrl.h',
        'encoder/rc_utils.h',
        'encoder/rd.c',
        'encoder/rd.h',
        'encoder/rdopt.c',
        'encoder/nonrd_pickmode.c',
        'encoder/nonrd_opt.c',
        'encoder/nonrd_opt.h',
        'encoder/rdopt.h',
        'encoder/rdopt_data_defs.h',
        'encoder/rdopt_utils.h',
        'encoder/reconinter_enc.c',
        'encoder/reconinter_enc.h',
        'encoder/segmentation.c',
        'encoder/segmentation.h',
        'encoder/sorting_network.h',
        'encoder/speed_features.c',
        'encoder/speed_features.h',
        'encoder/superres_scale.c',
        'encoder/superres_scale.h',
        'encoder/svc_layercontext.c',
        'encoder/svc_layercontext.h',
        'encoder/temporal_filter.c',
        'encoder/temporal_filter.h',
        'encoder/tokenize.c',
        'encoder/tokenize.h',
        'encoder/tpl_model.c',
        'encoder/tpl_model.h',
        'encoder/tx_search.c',
        'encoder/tx_search.h',
        'encoder/txb_rdopt.c',
        'encoder/txb_rdopt.h',
        'encoder/txb_rdopt_utils.h',
        'encoder/intra_mode_search.c',
        'encoder/intra_mode_search.h',
        'encoder/intra_mode_search_utils.h',
        'encoder/wedge_utils.c',
        'encoder/var_based_part.c',
        'encoder/var_based_part.h',
        'encoder/av1_noise_estimate.c',
        'encoder/av1_noise_estimate.h',
        '../third_party/fastfeat/fast.c',
        '../third_party/fastfeat/fast.h',
        '../third_party/fastfeat/fast_9.c',
        '../third_party/fastfeat/nonmax.c',
        '../third_party/vector/vector.c',
        '../third_party/vector/vector.h',
        'encoder/dwt.c',
        'encoder/dwt.h',
    )
    if cfg.get('CONFIG_REALTIME_ONLY') == 1
#       encoder_sources.remove(files(
#           'encoder/grain_test_vectors.h',
#       ))
    endif

    if cfg.get('CONFIG_THREE_PASS') == 1
        encoder_sources += files(
            'encoder/thirdpass.c',
            'encoder/thirdpass.h',
        )
    endif

    if cfg.get('CONFIG_TUNE_VMAF') == 1
        encoder_sources += files(
            'encoder/tune_vmaf.c',
            'encoder/tune_vmaf.h',
        )
    endif

    if cfg.get('CONFIG_TUNE_BUTTERAUGLI') == 1
        encoder_sources += files(
            'encoder/tune_butteraugli.c',
            'encoder/tune_butteraugli.h',
        )
    endif

    if cfg.get('CONFIG_SALIENCY_MAP') == 1
        encoder_sources += files(
            'encoder/saliency_map.c',
            'encoder/saliency_map.h',
        )
    endif

    if cfg.get('CONFIG_OPTICAL_FLOW_API') == 1
        encoder_sources += files(
            'encoder/sparse_linear_solver.c',
            'encoder/sparse_linear_solver.h',
            'encoder/optical_flow.c',
            'encoder/optical_flow.h',
        )
    endif

    if cfg.get('CONFIG_AV1_TEMPORAL_DENOISING') == 1
        encoder_sources += files(
            'encoder/av1_temporal_denoiser.c',
            'encoder/av1_temporal_denoiser.h',
        )
    endif

    if cfg.get('CONFIG_INTERNAL_STATS') == 1
        encoder_sources += files(
            'encoder/blockiness.c',
            'encoder/blockiness.h',
        )
    endif

    encoder_asm_sse2 = files(
        'encoder/x86/dct_sse2.asm',
        'encoder/x86/error_sse2.asm',
    )

    encoder_sources_sse2 = files(
        'encoder/x86/av1_fwd_txfm_sse2.c',
        'encoder/x86/av1_fwd_txfm_sse2.h',
        'encoder/x86/av1_k_means_sse2.c',
        'encoder/x86/av1_quantize_sse2.c',
        'encoder/x86/encodetxb_sse2.c',
        'encoder/x86/error_intrin_sse2.c',
        'encoder/x86/reconinter_enc_sse2.c',
        'encoder/x86/temporal_filter_sse2.c',
        'encoder/x86/wedge_utils_sse2.c',
    )
    if cfg.get('CONFIG_AV1_TEMPORAL_DENOISING') == 1
        encoder_sources_sse2 += files(
            'encoder/x86/av1_temporal_denoiser_sse2.c',
        )
    endif

    if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
        encoder_sources_sse2 += files(
            'encoder/x86/highbd_block_error_intrin_sse2.c',
            'encoder/x86/highbd_temporal_filter_sse2.c',
        )
    endif

    encoder_sources_sse3 = []
    # The functions defined in these files are removed from rtcd when CONFIG_EXCLUDE_SIMD_MISMATCH=1.
    if cfg.get('CONFIG_EXCLUDE_SIMD_MISMATCH') == 0
        encoder_sources_sse3 += files(
            'encoder/x86/ml_sse3.c',
            'encoder/x86/ml_sse3.h',
        )
    endif

    encoder_asm_ssse3_x86_64 = files(
        'encoder/x86/av1_quantize_ssse3_x86_64.asm'
    )

    encoder_sources_sse4_1 = files(
        'encoder/x86/av1_fwd_txfm1d_sse4.c',
        'encoder/x86/av1_fwd_txfm2d_sse4.c',
        'encoder/x86/encodetxb_sse4.c',
        'encoder/x86/highbd_fwd_txfm_sse4.c',
        'encoder/x86/rdopt_sse4.c',
        'encoder/x86/pickrst_sse4.c',
    )
    if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
        encoder_sources_sse4_1 += files(
            'encoder/x86/av1_highbd_quantize_sse4.c',
        )
    endif

    encoder_sources_sse4_2 = files(
        'encoder/x86/hash_sse42.c',
    )

    encoder_sources_avx2 = files(
        'encoder/x86/av1_quantize_avx2.c',
        'encoder/x86/error_intrin_avx2.c',
        'encoder/x86/av1_fwd_txfm_avx2.h',
        'encoder/x86/av1_fwd_txfm2d_avx2.c',
        'encoder/x86/highbd_fwd_txfm_avx2.c',
        'encoder/x86/wedge_utils_avx2.c',
        'encoder/x86/encodetxb_avx2.c',
        'encoder/x86/rdopt_avx2.c',
        'encoder/x86/av1_k_means_avx2.c',
        'encoder/x86/temporal_filter_avx2.c',
        'encoder/x86/pickrst_avx2.c',
    )
    if cfg.get('CONFIG_EXCLUDE_SIMD_MISMATCH') == 0
        encoder_sources_avx2 += files(
            'encoder/x86/cnn_avx2.c',
            'encoder/x86/ml_avx2.c',
        )
    endif

    if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
         encoder_sources_avx2 += files(
            'encoder/x86/av1_highbd_quantize_avx2.c',
            'encoder/x86/highbd_block_error_intrin_avx2.c',
            'encoder/x86/highbd_temporal_filter_avx2.c',
        )
    endif

    encoder_sources_neon = files(
        'encoder/arm/av1_error_neon.c',
        'encoder/arm/av1_fwd_txfm2d_neon.c',
        'encoder/arm/av1_k_means_neon.c',
        'encoder/arm/cnn_neon.c',
        'encoder/arm/encodetxb_neon.c',
        'encoder/arm/highbd_fwd_txfm_neon.c',
        'encoder/arm/hybrid_fwd_txfm_neon.c',
        'encoder/arm/pickrst_neon.c',
        'encoder/arm/pickrst_neon.h',
        'encoder/arm/quantize_neon.c',
        'encoder/arm/rdopt_neon.c',
        'encoder/arm/reconinter_enc_neon.c',
        'encoder/arm/temporal_filter_neon.c',
        'encoder/arm/wedge_utils_neon.c',
    )
    if cfg.get('CONFIG_EXCLUDE_SIMD_MISMATCH') == 0
        encoder_sources_neon += files(
            'encoder/arm/ml_neon.c',
        )
    endif

    if cfg.get('CONFIG_AV1_TEMPORAL_DENOISING') == 1
        encoder_sources_neon += files(
            'encoder/arm/av1_temporal_denoiser_neon.c',
        )
    endif

    if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
        encoder_sources_neon += files(
            'encoder/arm/av1_highbd_quantize_neon.c',
            'encoder/arm/highbd_pickrst_neon.c',
            'encoder/arm/highbd_rdopt_neon.c',
            'encoder/arm/highbd_temporal_filter_neon.c',
        )
    endif

    encoder_sources_neon_dotprod = files(
        'encoder/arm/temporal_filter_neon_dotprod.c',
    )

    encoder_sources_sve = files(
        'encoder/arm/av1_error_sve.c',
        'encoder/arm/pickrst_sve.c',
        'encoder/arm/wedge_utils_sve.c',
    )
    if cfg.get('CONFIG_AV1_HIGHBITDEPTH') == 1
        encoder_sources_sve += files(
            'encoder/arm/highbd_pickrst_sve.c',
        )
    endif

    encoder_sources_arm_crc32 = files(
        'encoder/arm/hash_arm_crc32.c',
    )
endif

if cfg.get('CONFIG_REALTIME_ONLY') == 1
    if cfg.get('CONFIG_AV1_DECODER') == 0
        common_sources.remove(files(
            'common/cfl.c',
            'common/cfl.h',
            'common/restoration.c',
            'common/restoration.h',
            'common/warped_motion.c',
            'common/warped_motion.h',
        ))

        common_sources_sse2.remove(files(
            'common/x86/cfl_sse2.c',
            'common/x86/warp_plane_sse2.c',
            'common/x86/wiener_convolve_sse2.c',
        ))

        common_sources_sse4_1.remove(files(
            'common/x86/highbd_warp_plane_sse4.c',
            'common/x86/selfguided_sse4.c',
            'common/x86/warp_plane_sse4.c',
        ))

        common_sources_ssse3.remove(files(
            'common/x86/cfl_ssse3.c',
            'common/x86/highbd_wiener_convolve_ssse3.c',
        ))

        common_sources_avx2.remove(files(
            'common/x86/cfl_avx2.c',
            'common/x86/highbd_warp_affine_avx2.c',
            'common/x86/highbd_wiener_convolve_avx2.c',
            'common/x86/selfguided_avx2.c',
            'common/x86/warp_plane_avx2.c',
            'common/x86/wiener_convolve_avx2.c',
        ))

        common_sources_neon.remove(files(
            'common/arm/cfl_neon.c',
            'common/arm/highbd_warp_plane_neon.c',
            'common/arm/highbd_wiener_convolve_neon.c',
            'common/arm/selfguided_neon.c',
            'common/arm/warp_plane_neon.c',
            'common/arm/warp_plane_neon.h',
            'common/arm/wiener_convolve_neon.c',
        ))

        common_sources_neon_i8mm.remove(files(
            'common/arm/warp_plane_neon_i8mm.c',
        ))

        common_sources_sve.remove(files(
            'common/arm/highbd_warp_plane_sve.c',
            'common/arm/warp_plane_sve.c',
        ))
    endif

    encoder_sources_sse2.remove(files(
        'encoder/x86/highbd_temporal_filter_sse2.c',
        'encoder/x86/temporal_filter_sse2.c',
    ))

    encoder_sources_sse4_1.remove(files(
        'encoder/x86/pickrst_sse4.c',
    ))

    encoder_sources_avx2.remove(files(
        'encoder/x86/highbd_temporal_filter_avx2.c',
        'encoder/x86/pickrst_avx2.c',
        'encoder/x86/temporal_filter_avx2.c',
        'encoder/x86/cnn_avx2.c',
    ))

    encoder_sources_neon.remove(files(
        'encoder/arm/cnn_neon.c',
        'encoder/arm/highbd_pickrst_neon.c',
        'encoder/arm/highbd_temporal_filter_neon.c',
        'encoder/arm/pickrst_neon.c',
       'encoder/arm/pickrst_neon.h',
        'encoder/arm/temporal_filter_neon.c',
    ))

    encoder_sources_neon_dotprod.remove(files(
        'encoder/arm/temporal_filter_neon_dotprod.c',
    ))

    encoder_sources_sve.remove(files(
        'encoder/arm/pickrst_sve.c',
    ))

    encoder_sources.remove(files(
        'encoder/cnn.c',
        'encoder/cnn.h',
        'encoder/firstpass.c',
        'encoder/firstpass.h',
        'encoder/global_motion.c',
        'encoder/global_motion.h',
        'encoder/global_motion_facade.c',
        'encoder/global_motion_facade.h',
        'encoder/gop_structure.c',
        'encoder/gop_structure.h',
        'encoder/misc_model_weights.h',
        'encoder/partition_cnn_weights.h',
        'encoder/partition_model_weights.h',
        'encoder/pass2_strategy.c',
        'encoder/picklpf.h',
        'encoder/pickrst.c',
        'encoder/temporal_filter.c',
        'encoder/temporal_filter.h',
        'encoder/tpl_model.c',
        'encoder/tpl_model.h',
    ))
endif

if cfg.get('HAVE_SSE2') == 1
    common_sources += common_sources_sse2
    common_c_args += sse2_args
    if cfg.get('CONFIG_AV1_DECODER') == 1
        #if is_variable('AOM_AV1_DECODER_ASM_SSE2')
        #    decoder_objects += asm_gen.process(AOM_AV1_DECODER_ASM_SSE2)
        #endif
        #if is_variable('decoder_sources_SSE2')
        #    decoder_sources += decoder_sources_SSE2
        #endif
    endif
    if cfg.get('CONFIG_AV1_ENCODER') == 1
        encoder_objects += asm_gen.process(encoder_asm_sse2)
        encoder_sources += encoder_sources_sse2
        encoder_c_args += sse2_args
    endif
endif

if cfg.get('HAVE_SSE3') == 1
    if cfg.get('CONFIG_AV1_ENCODER') == 1
        encoder_sources += encoder_sources_sse3
        encoder_c_args += sse3_args
    endif
endif

if cfg.get('HAVE_SSSE3') == 1
    common_sources += common_sources_ssse3
    common_c_args += ssse3_args
    if target_cpu == 'x86'
        common_sources += common_sources_ssse3_x86
    endif
    if cfg.get('CONFIG_AV1_DECODER') == 1
        #if is_variable('decoder_sources_ssse3')
        #    decoder_sources += decoder_sources_ssse3
        #endif
    endif
endif

if cfg.get('HAVE_SSE4_1') == 1
    common_sources += common_sources_sse4_1
    common_c_args += sse4_1_args
    if cfg.get('CONFIG_AV1_ENCODER') == 1
        if target_cpu == 'x86_64'
            encoder_objects += asm_gen.process(encoder_asm_ssse3_x86_64)
        endif
        encoder_sources += encoder_sources_sse4_1
        encoder_c_args += sse4_1_args
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
        encoder_sources += encoder_sources_neon
    endif
endif

if cfg.get('HAVE_ARM_CRC32') == 1
    if cfg.get('CONFIG_AV1_ENCODER') == 1
        encoder_sources += encoder_sources_arm_crc32
        encoder_c_args += arm_crc32_args
    endif
endif

if cfg.get('HAVE_NEON_DOTPROD') == 1
    common_sources += common_sources_neon_dotprod
    if cfg.get('CONFIG_AV1_ENCODER') == 1
        encoder_sources += encoder_sources_neon_dotprod
        encoder_c_args += neon_dotprod_args
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
        encoder_sources += encoder_sources_sve
        encoder_c_args += sve_args
    endif
endif

if cfg.get('HAVE_SVE2') == 1
    common_sources += common_sources_sve2
    common_c_args += sve2_args
endif

if cfg.get('HAVE_VSX') == 1
    common_sources += common_sources_vsx
    common_c_args += vsx_args
endif

if cfg.get('HAVE_RVV') == 1
    common_sources += common_sources_rvv
    common_c_args += rvv_args
endif

lib_targets += static_library('aom_av1_common',
                sources: common_sources,
                 c_args: common_c_args,
    include_directories: lib_incs,
)

if cfg.get('CONFIG_AV1_DECODER') == 1
    lib_targets += static_library('aom_av1_decoder',
                             decoder_objects,
                    sources: decoder_sources,
                     c_args: decoder_c_args,
        include_directories: lib_incs,
    )
endif

if cfg.get('CONFIG_AV1_ENCODER') == 1
    lib_targets += static_library('aom_av1_encoder',
                             encoder_objects,
                    sources: encoder_sources,
                     c_args: encoder_c_args,
        include_directories: lib_incs,
    )
endif
