#include "Library.h"

// hàm tìm ước số chung lớn nhất để tối giản phân số
int TimUCLN(int x, int y){
	if (x%y == 0)
		return y;
	else
		TimUCLN(y, x%y);
}
// Tạo dãy các phân số
void TaoDayPhanSo(PhanSo *&p, int &np){
	srand(time(NULL));
	printf("Nhap so luong phan so trong day: ");
	scanf_s("%d", &np);
	long x;
	int i = 0;
	p = (PhanSo*)calloc(np, sizeof(PhanSo));
	while (i < np){
		x = rand() % 10;
		if (x != 0){
			p[i].Tu = x;
			x = rand() % 10;
			if (x != 0){
				p[i].Mau = x;
				i++;
			}
		}
	}
}
// function cộng hai phân số
PhanSo CongHaiPhanSo(PhanSo x, PhanSo y){
	PhanSo k;
	k.Tu = (x.Tu*y.Mau) + (y.Tu*x.Mau);
	k.Mau = x.Mau*y.Mau;
	return k;
}
void XuatDayPhanSo(PhanSo *p, int np){
	for (int i = 0; i < np; i++){
		printf("%d/%d\t", p[i].Tu, p[i].Mau);
	}
}
//function cộng các phân số trong dãy lại với nhau
PhanSo TinhTongDayPhanSo(PhanSo *p, int np){

	PhanSo S = p[0];
	for (int i = 1; i < np; i++){
		S = CongHaiPhanSo(S, p[i]);
	}
	return S;
}