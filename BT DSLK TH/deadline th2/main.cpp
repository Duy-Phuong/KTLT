#include <stdio.h>
#include <stdlib.h>

void main()
{
	//bai 8
	int **p;
	int m, n;
	scanf("%d", &m);
	scanf("%d", &n);
	p = new int*[m];
	for (int i = 0; i < m; i++)
		p[i] = new int[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			p[i][j] = i*n + j;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			//xuống dòng 50 lần
		printf("\n");
	}
	//giả sử nhập m = 5, n = 10
	printf("%d\n", **p);// **p là giá trị của phần tử đầu của mảng = 0
	printf("%d\n", **(p + 2));//**(p + 2) la gia tri cua phần tử thứ 2 **p = 20
	printf("%d\n", *(*(p + 2)+1));// **(p + 10) la gia tri cua phần tử thứ 10 nên *(p + 10) sẽ xuất ra địa chỉ rác
	printf("%d\n", *(p + 3));//**(p + 3) la gia tri cua phần tử thứ 3 nên *(p + 3) sẽ xuất ra địa chỉ rác

}