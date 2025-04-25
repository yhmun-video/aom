#include <immintrin.h>

int main (int argc, char ** argv)
{
    static __m256i mtest;
    mtest = _mm256_set_m128i(_mm_setzero_si128(),_mm_setzero_si128());
    return *((unsigned char *) &mtest) != 0;
}
