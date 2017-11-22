#include <stdio.h>
#include <stdlib.h>

void main()
{
	float* a ;
	int n;
	printf("nhap n: ");
	scanf("%d", &n);
	a = (float*)malloc(n*sizeof(float));
	for (int i = 0; i < n; i++)
	{
		printf("nhap pt thu %d: ", i);
		scanf("%f", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%f\t", a[i]);
		
	}
	printf("\n%f", *(a + 3));
	float* a1 = &a[1];
	float* a2 = &a[2];

	printf("\nso byte cach nhau: %d\n", sizeof(a1-a2));

	free(a);
}