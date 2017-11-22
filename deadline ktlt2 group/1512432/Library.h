#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
using namespace std;

#define MAX 20

/*tạo kiểu dữ liệu PhanSo có 2 thành phần là tử và mẫu*/
typedef struct {
	long Tu; // tử số
	long Mau; // mẫu số
}SPhanSo;
/* khai báo kiểu dữ liệu đơn thức*/
typedef struct {
	int n; // mũ của x
	float HeSo; // giá trị hệ số của đơn thức
}SDonThuc;
/*khai báo kiểu dữ liệu đa thức*/
typedef struct {
	int n; // bậc của đa thức
	float *HeSo; // mảng hệ số của đơn thức
}SDaThuc;
/*tạo kiểu dữ liệu điểm 2D */
typedef struct
{
	int x, y;
}SDiem2D;
/*khai báo kiểu dữ liệu ngày tháng năm*/
typedef struct
{
	int ngay, thang, nam;
}SNgay;



/*chương trình vs phân số*/
void TaoDayPhanSo(SPhanSo *&p, int &np);
void XuatDayPhanSo(SPhanSo *p, int np);
int TimUCLN(int x, int y);
void RutGonPhanSo(SPhanSo &x);
SPhanSo TongHaiPhanSo(SPhanSo x, SPhanSo y);
SPhanSo QuyDong(SPhanSo p1, SPhanSo p2);
void tich(SPhanSo p1, SPhanSo p2, SPhanSo &p3);
void hoanvi(int &x, int &y);
void thuong(SPhanSo p1, SPhanSo p2, SPhanSo &p3);
bool ktPSamduong(SPhanSo p);
void sosanh(SPhanSo p1, SPhanSo p2);
bool ktpsToiGian(SPhanSo p);

/*chương trình với đơn thức*/
void NhapDonThuc(SDonThuc &p);
void XuatDonThuc(SDonThuc p);
SDonThuc TichHaiDonThuc(SDonThuc x, SDonThuc y);
SDonThuc ChiaHaiDonThuc(SDonThuc x, SDonThuc y);
SDonThuc DaoHamCapk(SDonThuc p, int k);
float TinhGiaTriDonThuc(SDonThuc p, float x);

/*chương trình với đa thức*/
void XuatDaThuc(SDaThuc *p);
void NhapDaThuc(SDaThuc *&p);
SDaThuc *TongHaiDaThuc(SDaThuc *x, SDaThuc *y);
SDaThuc *HieuHaiDaThuc(SDaThuc *x, SDaThuc *y);
SDaThuc *TichHaiDaThuc(SDaThuc *x, SDaThuc *y);
SDaThuc *DaoHamBacMotDaThuc(SDaThuc *y);
SDaThuc *DaoHamCapKDaThuc(SDaThuc *p, int Cap);

/*chương trình với điểm trong mặt phẳng tọa độ*/
void nhap(SDiem2D &a);
void xuat(SDiem2D a);
float tinhkhoangcach(SDiem2D a1, SDiem2D a2);
void DiemDoiXung(SDiem2D a1, SDiem2D &a2);
void kiemtra(SDiem2D a);
void NhapToaDoDinh(SDiem2D a[3]);

/*chương trình làm việc với ngày tháng năm*/
void NhapNgay(SNgay &a);
void xuat(SNgay a);
bool KiemTraNamNhuan(SNgay a);
int tinhSoNgayTrongThang(SNgay a);
int tinhSTTNgayTrongNam(SNgay a);
int tinhSTTNgay(SNgay a);
void timNgayHomTruoc(SNgay &a, int k);
void timNgayHomSau(SNgay &a, int k);
int TinhKC2Ngay(SNgay a, SNgay b);
void sosanh(SNgay a, SNgay b);