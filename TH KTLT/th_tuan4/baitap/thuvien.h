#include <stdio.h>
#include <string.h>
#include <stdlib.h>//iota, atoi trong nay
void DemKiTu(char* s);
int DemTu(char* s);
void cut(char* s);
void TimTuMaxMin(char* s);
int DemSoTu(char* a, int b);
void VietHoaKiTuDau(char* a);
void ChenKiTu(char* s, int vt, char c);
void ChuyenSoSangChuoi();
void Xoa(char* a, int vt);
void XoaKhoangTrangThua(char* a);
void XoaKhoangCachTruocDau(char* a);
void ChenKhoangCachSauDau(char* a);
void VietHoaKiTuDauSauDauCau(char* a);

void ChuanHoaDoanVan(char* s);
void DemTuTrongDoan(char* s);
void DaoChuoi(char* s);

typedef struct
{
	char a[100];
}mang;

void DaoTu(char* s, mang* d, int &nd);
void XuatTuNguocLai(mang* d, int nd);

void Tong(char* a, char* b);
void TimKiem(char* a, char* b);

bool KiemTraHopLe(char* s);

//bai 7
typedef struct
{
	int sotu;
	int vitri;
}MANG;
void Timchuoicon(char* s1, char* s2, MANG b[100], int &nb);
int Timmax(MANG b[100], int nb);
void Xuat(char* s1, MANG b[100], int nb);










