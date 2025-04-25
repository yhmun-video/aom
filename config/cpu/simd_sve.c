#ifndef __ARM_NEON_SVE_BRIDGE
#error 1
#endif

#include <arm_sve.h>
#include <arm_neon_sve_bridge.h>

void other(void);
svfloat32_t func(svfloat32_t a)
{
    other();
    return a;
}
