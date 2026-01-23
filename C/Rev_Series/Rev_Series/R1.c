#include<stdio.h>

int main() {
	float pie = 3.14;
	float r, vol;
	scanf("%f", &r);
	vol = (4.0 / 3) * pie * r * r * r;

	printf("Volume of sphere is: %.2f\n", vol);
	return 0;
}