#include "Library.h"

int *CapPhat(int n){
	int *p = (int*)calloc(n, sizeof(int));
	return p;
}
//khởi tạo Matrix
void BuildMatrix(int a[][MAX], int &d, int &c){
	//Nhập số dòng cho ma trận
	do{
		printf("So dong: ");
		scanf_s("%d", &d);
	} while (d < 1);
	//Nhập số cột cho ma trận

	do{
		printf("So cot: ");
		scanf_s("%d", &c);
	} while (d < 1);

	srand(time(NULL));
	for (int i = 0; i < d; i++){
		for (int j = 0; j < c; j++){
			a[i][j] = rand() % 100;
		}
	}
}
// Xuat matrix
void OutputMatrix(int a[][MAX], int d, int c){
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++){
			printf("%d \t", a[i][j]);
		}
		printf("\n\n");
	}
}
// kiểm tra phần tử truyền vào co phải phần tử cực đại hay không
int IsLargestElement(int a[][MAX], int d, int c, int x, int y) {
	for (int i = -1; i < 2; i++){
		if (x + i >= 0 && x + i < d){
			for (int j = -1; j < 2; j++){
				if (y + j >= 0 && y + j < c){
					if (a[x][y] < a[x + i][y + j])
						return 0;
				}
			}
		}
	}
	return 1;
}
// đếm số phần từ cực đại trong mảng
int DemPhanTuCucDaiTrongMang(int *&b, int a[][MAX], int d, int c){
	int nLargest = 0;
	if (d >= c)
		b = (int*)calloc(d, (sizeof(int)));
	else
		b = (int*)calloc(c, (sizeof(int)));

	for (int i = 0; i < d; i++){
		for (int j = 0; j < c; j++){
			if (IsLargestElement(a, d, c, i, j) == 1){
				b[nLargest] = a[i][j];
				nLargest++;
			}
		}
	}
	return nLargest;
}
