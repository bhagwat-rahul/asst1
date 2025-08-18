#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>
#include <vector>
#include <string.h>
#include <immintrin.h> // Only want to use avx2 not umbrella immintrin
using namespace std;

void mysqrt(int N, float initialGuess, float values[], float* output);

#endif
