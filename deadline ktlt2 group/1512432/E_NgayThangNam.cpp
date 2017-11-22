#include "Library.h"

void NhapNgay(SNgay &a)
{
	printf("\nnhap ngay: ");
	scanf("%d", &a.ngay);
	printf("\nnhap thang: ");
	scanf("%d", &a.thang);
	printf("\nnhap nam: ");
	scanf("%d", &a.nam);
}
void xuat(SNgay a)
{
	printf("\nngay trong nam do la: ngay %d thang %d nam %d", a.ngay, a.thang, a.nam);
}
bool KiemTraNamNhuan(SNgay a)
{
	return (a.nam % 400 == 0 || a.nam % 4 == 0 && a.nam % 100 != 0);
}
// Hàm trả về số ngày trong tháng th thuộc năm nm cho trước
int tinhSoNgayTrongThang(SNgay a)
{
	int songay;

	switch (a.ngay)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: songay = 31; break;
	case 4:
	case 6:
	case 9:
	case 11: songay = 30; break;
	case 2:
		if (KiemTraNamNhuan(a))
		{
			songay = 29;
		}
		else
		{
			songay = 28;
		}
		break;
	}

	return songay;
}
// Bài 10
// Hàm tính và trả về số thứ tự ngày trong năm từ ngày ng/th/nm cho trước (đã hợp lệ)
int tinhSTTNgayTrongNam(SNgay a)
{
	int stt = a.ngay;

	for (int thang = 1; thang <= a.thang - 1; thang++)
	{
		stt = stt + tinhSoNgayTrongThang(a);
	}

	return stt;
}

// Bài 11
// Hàm tính và trả về số thứ tự ngày so với ngày 1/1/1 từ ngày ng/th/nm cho trước (đã hợp lệ)
int tinhSTTNgay(SNgay a)
{
	int stt = tinhSTTNgayTrongNam(a);

	stt = stt + 365 * (a.nam - 1);
	for (int nam = 1; nam <= a.nam - 1; nam++)
	{
		if (KiemTraNamNhuan(a))
		{
			stt++;
		}
	}

	return stt;
}

// Hàm tìm ngày hôm trước của một ngày ng/th/nm cho trước (đã hợp lệ)
void timNgayHomTruoc(SNgay &a, int k)
{
	a.ngay -= k;
	if (a.ngay == 0)
	{
		a.thang--;
		if (a.thang == 0)
		{
			a.thang = 12;
			a.nam--;
		}

		a.ngay = tinhSoNgayTrongThang(a);
	}
}

// Bài 11
// Hàm tìm ngày hôm sau của một ngày ng/th/nm cho trước (đã hợp lệ)
void timNgayHomSau(SNgay &a, int k)
{
	a.ngay += k;
	if (a.ngay > tinhSoNgayTrongThang(a))
	{
		a.ngay = 1;
		a.thang++;
		if (a.thang > 12)
		{
			a.thang = 1;
			a.nam++;
		}
	}
}
int TinhKC2Ngay(SNgay a, SNgay b)
{
	int z;
	int x = tinhSTTNgayTrongNam(a);
	int y = tinhSTTNgayTrongNam(b);
	if (x > y)
	{
		z = x - y;
	}
	else
	{
		z = y - x;
	}
	return z;
}
void sosanh(SNgay a, SNgay b)
{
	int x = tinhSTTNgayTrongNam(a);
	int y = tinhSTTNgayTrongNam(b);
	if (x > y)
	{
		printf("\nngay %d thang %d nam % d lon hon ngay %d thang %d nam % d ", a.ngay, a.thang, a.nam, b.ngay, b.thang, b.nam);
	}
	else if (x < y)
	{
		printf("\nngay %d thang %d nam % d nho hon ngay %d thang %d nam % d ", a.ngay, a.thang, a.nam, b.ngay, b.thang, b.nam);
	}
	else if (x = y)
	{
		printf("\nhai ngay trung nhau\n");
	}
}