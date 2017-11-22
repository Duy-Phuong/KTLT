#include "Library.h"

// hàm tìm phần tử max dòng của dòng đưa vào
int LaPTMaxDong(int a[][MAX], int d, int c, int x){
	int Max = a[x][0];
	for (int i = 1; i < c; i++){
		if (a[x][i]>Max)
			Max = a[x][i];
	}
	return Max;
}
// hàm hoán vị 2 phần tử
void HoanVi(int &x, int &y){
	int t = x; x = y; y = t;
}
//hàm hoán vị 2 dòng
void HoanViDong(int a[][MAX], int d, int c, int dx, int dy){
	for (int i = 0; i < c; i++){
		HoanVi(a[dx][i], a[dy][i]);
	}
}
// hàm sắp xếp lại dòng theo thứ tự tăng dần của PT lớn nhất trên dòng
void SapXepLaiDong(int a[][MAX], int d, int c){
	for (int i = 0; i < d; i++){
		for (int j = i + 1; j < d; j++){
			if (LaPTMaxDong(a, d, c, j) < LaPTMaxDong(a, d, c, i)){
				HoanViDong(a, d, c, i, j);
			}
		}
	}
}

