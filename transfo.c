#include <omp.h>

void copy (int w, int h, unsigned char *src, unsigned char *dest)
{
	int i,j;
  	for (j = 0; j < h; j++) {
		for (i = 0; i < w; i++) {
			dest[j * w + i] = src[j * w + i];
		}
	}
}

void light(int w, int h, unsigned char *img, unsigned char val)
{
	int i,j;
	unsigned char current;

	for (j = 0; j < h; j++) {
		#pragma omp parallel for private(current)
		for (i = 0; i < w; i++) {
			current = img[j * w + i];
			img[j * w + i] = (((int) current + val) > 255) ? 255 : current + val;
		}
	}
}

void curve(int w, int h, unsigned char *img, unsigned char *lut)
{
	int i,j;
  	unsigned char current;
  	for (j = 0; j < h; j++) {
  		for (i = 0; i < w; i++) {
  			current = img[j * w + i];
			img[j * w + i] = lut[current];
  		}
  	}
}

void transfo(int w, int h, unsigned char *src, unsigned char *dest, unsigned char *lut, unsigned char val)
{
  	copy(w, h, src, dest);
  	curve(w, h, dest, lut);
  	light(w, h, dest, val);
}
