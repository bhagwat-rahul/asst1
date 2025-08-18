#include "sqrt.h"

// TODO: currently is a scam copy past impl of sqrt ispc, need to make this w avx2 intrinsics to see what ispc gives us over reg avx
static const float kThreshold = 0.00001f;

void mysqrt(int N, float initialGuess, float values[], float* output)
{
  for (int i = 0; i < N; i++) {
      printf("in the loop\n");
      float x = values[i];
      float guess = initialGuess;

      float pred = (guess * guess * x - 1.f);

      while (pred > kThreshold) {
          guess = (3.f * guess - x * guess * guess * guess) * 0.5f;
          pred = (guess * guess * x - 1.f);
      }

      output[i] = x * guess;

  }
}

int main()
{
    float input[1] = {4.0f};
    float out[1] = {0.0f};
    puts("self test");
    mysqrt(1, 2.0f, input, out);
    printf("output %f\n", out[0]);
}
