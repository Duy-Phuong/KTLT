#include <stdio.h>
#include <stdlib.h> // rand()

void main()
{
	int a[10000];
	FILE* f = fopen("input.txt", "wt");
	FILE* f1 = fopen("input1.txt", "wb");
	for (int i = 0; i < 10000; i++)
	{
		a[i] = rand();
		fprintf(f, "%d ", a[i]);
		printf("%d ", a[i]);
	}

	fwrite(a, sizeof(int), 10000, f1);
	int z = ftell(f);
	int z1 = ftell(f1);
	printf("\nkich thuoc tap tin o dang van ban la:  %d, kich thuoc tap tin theo kieu nhi phan la: %d\n", z, z1);
	if (z > z1)
	{
		printf("\nkich thuoc tap tin o dang van ban la:  %d lon hon kich thuoc tap tin theo kieu nhi phan la: %d\n", z, z1);
	}
	else
	{
		printf("\nkich thuoc tap tin o dang van ban la:  %d nho hon kich thuoc tap tin theo kieu nhi phan la: %d\n", z, z1);
	}
	fcloseall();
	

}