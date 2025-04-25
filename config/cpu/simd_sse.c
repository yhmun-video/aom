#include <xmmintrin.h>

int main (int argc, char ** argv)
{
    static __m128 mtest;
    mtest = _mm_setzero_ps();
    return *((unsigned char *) &mtest) != 0;
}
