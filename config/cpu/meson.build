if target_cpu == 'arm64'
    cfg.set10('AOM_ARCH_ARM', true)
    cfg.set10('AOM_ARCH_AARCH64', true)

    if get_option('ENABLE_NEON')
        cfg.set10('HAVE_NEON', true)
    endif
    if cfg.get('HAVE_NEON') == 0
        rtcd_args += '--disable-neon'
    endif

    if get_option('ENABLE_ARM_CRC32')
        arm_crc32_args = ['-march=armv8-a+crc']
        cfg.set10('HAVE_ARM_CRC32', cc.get_supported_arguments(arm_crc32_args))
    endif
    if cfg.get('HAVE_ARM_CRC32') == 0
        rtcd_args += '--disable-arm_crc32'
    endif

    if get_option('ENABLE_NEON_DOTPROD')
        neon_dotprod_args = ['-march=armv8.2-a+dotprod']
        cfg.set10('HAVE_NEON_DOTPROD', cc.get_supported_arguments(neon_dotprod_args))
    endif
    if cfg.get('HAVE_NEON_DOTPROD') == 0
        rtcd_args += '--disable-neon_dotprod'
    endif

    if get_option('ENABLE_NEON_I8MM')
        neon_i8mm_args = ['-march=armv8.2-a+dotprod+i8mm']
        cfg.set10('HAVE_NEON_I8MM', cc.get_supported_arguments(neon_i8mm_args))
    endif
    if cfg.get('HAVE_NEON_I8MM') == 0
        rtcd_args += '--disable-neon_i8mm'
    endif

    if get_option('ENABLE_SVE')
        sve_args = '-march=armv8.2-a+dotprod+i8mm+sve'
        # SVE and SVE2 require that the Neon-SVE bridge header is also available.
        # Check whether the compiler can compile SVE functions that require
        # backup/restore of SVE registers according to AAPCS. Clang for Windows used
        # to fail this, see https://github.com/llvm/llvm-project/issues/80009.
        cfg.set10('HAVE_SVE', cc.compiles(
            files('simd_sve.c'),
            args: sve_args,
            name: 'SVE Intrinsic Support',
        ))
    endif
    if cfg.get('HAVE_SVE') == 0
        rtcd_args += '--disable-sve'
    endif

    if get_option('ENABLE_SVE2')
        # SVE2 is a v9-only feature
        sve2_args = '-march=armv9-a+i8mm+sve2'
        cfg.set10('HAVE_SVE2', cc.compiles(
            files('simd_sve.c'),
            args: sve2_args,
            name: 'SVE2 Intrinsic Support',
        ))
    endif
    if cfg.get('HAVE_SVE2') == 0
        rtcd_args += '--disable-sve2'
    endif
elif target_cpu.startswith('arm')
    cfg.set10('AOM_ARCH_ARM', true)

    if get_option('ENABLE_NEON')
        cfg.set10('HAVE_NEON', true)
    endif
    if cfg.get('HAVE_NEON') == 0
        rtcd_args += '--disable-neon'
    endif
elif target_cpu.startswith('ppc')
    cfg.set10('AOM_ARCH_PPC', true)

    if get_option('ENABLE_VSX')
        cfg.set10('HAVE_VSX', true)
    endif
    if cfg.get('HAVE_VSX') == 0
        rtcd_args += '--disable-neon'
    endif
elif target_cpu.startswith('x86')
    if target_cpu == 'x86'
        cfg.set10('AOM_ARCH_X86', true)
    elif target_cpu == 'x86_64'
        cfg.set10('AOM_ARCH_X86_64', true)
    endif

    if get_option('ENABLE_MMX')
        if cc.get_id() == 'msvc'
            mmx_args = ['/w14710', '/w14714', '/wd4244', '/wd4799']
        elif cc.get_id() == 'sun'
            mmx_args = ['-xarch=sse']
        else
            mmx_args = ['-mmmx']
        endif
        cfg.set10('HAVE_MMX', cc.get_id() == 'msvc' or cc.compiles(
            files('simd_mmx.c'),
            args: mmx_args,
            name: 'MMX Intrinsic Support',
        ))
    endif
    if cfg.get('HAVE_MMX') == 0
        rtcd_args += '--disable-mmx'
    endif

    if get_option('ENABLE_SSE')
        if cc.get_id() == 'msvc'
            sse_args = []
        elif cc.get_id() == 'sun'
            sse_args = ['-xarch=sse']
        else
            sse_args = ['-msse']
        endif
        cfg.set10('HAVE_SSE', cc.compiles(
            files('simd_sse.c'),
            args: sse_args,
            name: 'SSE Intrinsic Support',
        ))
    endif
    if cfg.get('HAVE_SSE') == 0
        rtcd_args += '--disable-sse'
    endif

    if get_option('ENABLE_SSE2')
        if cc.get_id() == 'msvc'
            sse2_args = []
        elif cc.get_id() == 'sun'
            sse2_args = ['-xarch=sse2']
        else
            sse2_args = ['-msse2']
        endif
        cfg.set10('HAVE_SSE2', cc.compiles(
            files('simd_sse2.c'),
            args: sse2_args,
            name: 'SSE2 Intrinsic Support',
        ))
    endif
    if cfg.get('HAVE_SSE2') == 0
        rtcd_args += '--disable-sse2'
    endif

    if get_option('ENABLE_SSE3')
        if cc.get_id() == 'msvc'
            sse3_args = []
        elif cc.get_id() == 'sun'
            sse3_args = ['-xarch=sse3']
        else
            sse3_args = ['-msse3']
        endif
        cfg.set10('HAVE_SSE3', cc.compiles(
            files('simd_sse2.c'),
            args: sse3_args,
            name: 'SSE3 Intrinsic Support',
        ))
    endif
    if cfg.get('HAVE_SSE3') == 0
        rtcd_args += '--disable-sse3'
    endif

    if get_option('ENABLE_SSSE3')
        if cc.get_id() == 'msvc'
            ssse3_args = []
        else
            ssse3_args = ['-mssse3']
        endif
        cfg.set10('HAVE_SSSE3', cc.compiles(
            files('simd_ssse3.c'),
            args: ssse3_args,
            name: 'SSSE3 Intrinsic Support',
        ))
    endif
    if cfg.get('HAVE_SSSE3') == 0
        rtcd_args += '--disable-ssse3'
    endif

    if get_option('ENABLE_SSE4_1')
        if cc.get_id() == 'msvc'
            sse4_1_args = []
        else
            sse4_1_args = ['-msse4.1']
        endif
        cfg.set10('HAVE_SSE4_1', cc.compiles(
            files('simd_sse4_1.c'),
            args: sse4_1_args,
            name: 'SSE4.1 Intrinsic Support',
        ))
    endif
    if cfg.get('HAVE_SSE4_1') == 0
        rtcd_args += '--disable-sse4_1'
    endif

    if get_option('ENABLE_SSE4_2')
        if cc.get_id() == 'msvc'
            sse4_2_args = []
        else
            sse4_2_args = ['-msse4.2']
        endif
        cfg.set10('HAVE_SSE4_2', cc.compiles(
            files('simd_sse4_1.c'),
            args: sse4_2_args,
            name: 'SSE4.2 Intrinsic Support',
        ))
    endif
    if cfg.get('HAVE_SSE4_2') == 0
        rtcd_args += '--disable-sse4_2'
    endif

    if get_option('ENABLE_AVX')
        if cc.get_id() == 'msvc'
            avx_args = ['/arch:AVX']
        else
            avx_args = ['-mavx']
        endif
        cfg.set10('HAVE_AVX', cc.compiles(
            files('simd_avx.c'),
            args: avx_args,
            name: 'AVX Intrinsic Support',
        ))
    endif
    if cfg.get('HAVE_AVX') == 0
        rtcd_args += '--disable-avx'
    endif

    if get_option('ENABLE_AVX2')
        if cc.get_id() == 'msvc'
            avx2_args = ['/arch:AVX2']
        else
            avx2_args = ['-mavx2']
        endif
        cfg.set10('HAVE_AVX2', cc.compiles(
            files('simd_avx2.c'),
            args: avx2_args,
            name: 'AVX2 Intrinsic Support',
        ))
    endif
    if cfg.get('HAVE_AVX2') == 0
        rtcd_args += '--disable-avx2'
    endif

elif target_cpu.startswith('riscv')
    cfg.set10('AOM_ARCH_RISCV', true)

    if get_option('ENABLE_RVV')
        rvv_args = ['-march=rv64gcv1p0']
        cfg.set10('HAVE_RVV', cc.compiles(
            files('simd_rvv.c'),
            args: rvv_args,
            name: 'RISC-V Vector Intrinsic Support',
        ))
    endif
    if cfg.get('HAVE_RVV') == 0
        rtcd_args += '--disable-rvv'
    endif
endif
