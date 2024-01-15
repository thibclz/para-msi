#include <omp.h>
#include <string.h>

// void copy (int w, int h, unsigned char *src, unsigned char *dest)
// {
// 	memcpy(dest, src, w * h);
// }

// void light(int w, int h, unsigned char *img, unsigned char val)
// {
// 	int i;
// 	int size = w * h;

// 	#pragma omp parallel for
// 	for (i = 0; i < size; i++) {
// 		int value = img[i] + val;
// 		img[i] = (value > 255) ? 255 : value;
// 	}
	
// }

// void curve(int w, int h, unsigned char *img, unsigned char *lut)
// {
// 	int i;
// 	int size = w * h;

// 	#pragma omp parallel for
// 	for (i = 0; i < size; i++) {
// 		unsigned char current = img[i];
// 		img[i] = lut[current];
// 	}
// }

void transfo(int w, int h, unsigned char *src, unsigned char *dest, unsigned char *lut, unsigned char val)
{
	int i;
	int size = w * h;
	memcpy(dest, src, size);
	#pragma omp parallel for
	for (i = 0; i < size; i++) {
		unsigned int current = lut[dest[i]] + val;
		dest[i] = (current > 255) ? 255 : current;
	}
}
