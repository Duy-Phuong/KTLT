#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20
// tạo kiểu dữ liệu PhanSo có 2 thành phần là tử và mẫu
typedef struct {
	long Tu; // tử số
	long Mau; // mẫu số
}PhanSo;
/*Tạo kiểu dữ liệu để lưu thông tin của một sinh viên*/
typedef struct {
	char HoTen[30];
	char MSSV[10];
	float DiemToan;
	float DiemNMLT;
	float DiemKTLT;
}SinhVien;
/*khởi tạo ma trận*/
int *CapPhat(int n);
void BuildMatrix(int a[][MAX], int &d, int &c);
void OutputMatrix(int a[][MAX], int d, int c);
/*Đếm số PT cực đại*/
int IsLargestElement(int a[][MAX], int d, int c, int x, int y);
int DemPhanTuCucDaiTrongMang(int *&b,int a[][MAX], int d, int c);
/*đếm số PT hoàng hậu*/
int LaPTHoangHau(int a[][MAX], int d, int c, int x, int y);
int DuyetPTHoangHauMatrix(int *&aHH, int a[][MAX], int d, int c);
/*Sắp xếp dòng tăng dần theo PT lớn nhất trên dòng*/
int LaPTMaxDong(int a[][MAX], int d, int c, int x);
void HoanVi(int &x, int &y);
void HoanViDong(int a[][MAX], int d, int c, int dx, int dy);
void SapXepLaiDong(int a[][MAX], int d, int c);
/* phần tính tồng phân số*/
int TimUCLN(int x, int y);
void TaoDayPhanSo(PhanSo *&p, int &np);
void XuatDayPhanSo(PhanSo *p, int np);
PhanSo TinhTongDayPhanSo(PhanSo *p, int np);

void NhapThongTinhSinhVien(SinhVien *&SV, int &nSV);
void TinhDiemTrungBinh(SinhVien *SV, int nSV, float *&DTB);
int TimSVCoDiemCaoNhat(SinhVien *SV, int nSV, float *DTB);