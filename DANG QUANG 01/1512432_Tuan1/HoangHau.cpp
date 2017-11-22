#include "Library.h"

/*hàm xét pt có phải là PT hoàng hậu không*/
int LaPTHoangHau(int a[][MAX], int d, int c, int x, int y){
	// xét phần từ có max dòng không
	for (int i = 0; i < c; i++){
		if (a[x][y] < a[x][i])
			return 0;
	}
	// xét phần tử có phải là max cột không
	for (int i = 0; i < d; i++){
		if (a[x][y] < a[i][y])
			return 0;
	}
	// là phần tử lớn nhất trên đường chéo chính của nó
	for (int i = -x; i < d; i++){
		if ((x + i >= 0) && (x + i < d) && (y + i >= 0) && (y + i < c)) {
			if ((a[x + i][y + i] > a[x][y]))
				return 0;
		}
	}
	// là phần tử lớn nhất trên đường chéo phụ của nó
	for (int i = -x; i < d; i++){
		if ((x + i >= 0) && (x + i < d) && (y + i >= 0) && (y + i < c)) {
			if ((a[x + i][y - i] > a[x][y]))
				return 0;
		}
	}
	return 1;
}

/*hàm đếm số pt hoàng hậu trong ma trận */
int DuyetPTHoangHauMatrix(int *&aHH,int a[][MAX], int d, int c){
	int dem = 0;
	aHH = (int*)calloc(c, sizeof(int));
	for (int i = 0; i < d; i++){
		for (int j = 0; j < c; j++){
			if (LaPTHoangHau(a, d, c, i, j) == 1){
				aHH[dem] = a[i][j];
				dem++;
			}
		}
	}
	return dem;
}