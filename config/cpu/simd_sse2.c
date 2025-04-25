#include <emmintrin.h>

int main (int argc, char ** argv)
{
    static __m128i mtest;
    mtest = _mm_setzero_si128();
    return *((unsigned char *) &mtest) != 0;
}
