#include <mmintrin.h>
#include <xmmintrin.h>
#include <emmintrin.h>

int param;
int main (int argc, char ** argv)
{
    __m128i a = _mm_set1_epi32 (param), b = _mm_set1_epi32 (param + 1), c;
    c = _mm_xor_si128 (a, b);
    return _mm_cvtsi128_si32(c);
}
