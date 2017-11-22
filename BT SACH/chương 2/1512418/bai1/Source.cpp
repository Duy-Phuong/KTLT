#include <stdio.h>

typedef union
{
	float value;
	struct
	{
		unsigned long mantissa: 23;
		unsigned int expo: 8;
		unsigned int sign : 1;
	};
}floatstruct;


void floatDump(floatstruct* fstr)
{
	int i;
	if (fstr == NULL)
	{
		return;
	}
	printf("------------------\n");
	printf("+value: %f\n", fstr->value);
	printf("\n");
	printf("+IEEE stored part:\n");
	printf("sign: %d\n", fstr->sign);
	printf("expo: 0x%X\n", fstr->expo);
	printf("mantissa: 0x%lX\n", fstr->mantissa);
}
void main()
{
	floatstruct* pFloat;
	float x = 1 / (float)3;
	pFloat = (floatstruct*)(&x);
	floatDump(pFloat);
	
}




