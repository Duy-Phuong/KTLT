#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <conio.h>

using namespace std;

#pragma pack(push, 1)
typedef struct {
	char HoTen[50];
	char Ho[20];
	char Ten[10];
	char MSSV[10];
	char NTNS[12];
	char GioiTinh[5];
	float Toan;
	float Ly;
	float Hoa;
	float DTB;
}SinhVien;
#pragma pack(pop)

void LamTronDTB(float &DTB);
void BangDiemTongKethtml(char *name_txt, char *name_html);
void ShowStu(SinhVien sv);
void AddHoTenToHo_Ten(SinhVien &sv);
void DTB(SinhVien &sv);
void TaoFielhtmlChiTiet(char *name_MSSV, char *name_form, SinhVien sv);
void TaoFileChiTiet(SinhVien sv);
void HoanViSinhVien(SinhVien &sv1, SinhVien &sv2);
void SapXepDSSV(SinhVien *sv, int SoSV);