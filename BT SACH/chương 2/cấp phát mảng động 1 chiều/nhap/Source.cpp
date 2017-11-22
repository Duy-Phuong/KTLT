#include <stdio.h>
#include <stdlib.h>// de co the th dong lenh xoa man hinh va dung man hinh
int TinhGiaiThua(int _iGiaiThua)
{
	int c = 1;
	for(int i = 2; i <= _iGiaiThua; i++)
	{
		c = c * i;
	}
	return c;
}


void main()
{

	int _iGiaiThua, n;
	printf("nhap vao so n:");
	scanf("%d", &n);
	int x = TinhGiaiThua(n);
	printf("giai thua cua %d la: %d\n", n, x);
}
