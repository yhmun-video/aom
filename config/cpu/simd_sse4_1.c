#include <smmintrin.h>

int main (int argc, char ** argv)
{
    static __m128i mtest;
    mtest = _mm_setzero_si128();
    mtest = _mm_cmpeq_epi64(mtest, mtest);
    return *((unsigned char *) &mtest) != 0;
}
