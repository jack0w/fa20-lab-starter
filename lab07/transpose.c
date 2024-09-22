#include "transpose.h"

/* The naive transpose function as a reference. */
void transpose_naive(int n, int blocksize, int *dst, int *src) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            dst[y + x * n] = src[x + y * n];
        }
    }
}

/* Implement cache blocking below. You should NOT assume that n is a
 * multiple of the block size. */
void transpose_blocking(int n, int blocksize, int *dst, int *src) {
    int xRange;
    int yRange;
    for (int i = 0; i < n; i += blocksize) {
        for (int j = 0; j < n; j += blocksize) {
        	xRange = (n - i < blocksize) ? n - i : blocksize;
        	yRange = (n - j < blocksize) ? n - j : blocksize;
		for (int x = 0; x < xRange; x++) {
			for (int y = 0; y < yRange; y++) {
				dst[y + j + (x + i) * n] = src[x + i + (y + j) * n];
			}
		}
        }
    }  
}
