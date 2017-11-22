#include <stdio.h>

//bai 1: BAI TAP MANG 2 CHIEU
//bai 1:

#include <stdlib.h>
void NhapMaTran(float** &a, int &m, int &n)
{
	printf("nhap m dong: ");
	scanf_s("%d", &m);
	printf("nhap n cot: ");
	scanf_s("%d", &n);
	a = (float**)calloc(m, sizeof(float*));
	for (int i = 0; i < m; i++)
	{
		a[i] = (float*)calloc(n, sizeof(float));
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("nhap phan tu thu a[%d][%d]: ", i, j);
			scanf_s("%f", &a[i][j]);
		}
	}
}
void XuatMaTran(float** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%f\t", a[i][j]);
		}
		printf("\n");
	}
}
void TimPhanTuMinMax(float** a, int m, int n)
{
	float min, max;
	min = a[0][0];
	max = a[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
			}
			if (a[i][j] < min)
			{
				min = a[i][j];
			}
		}
	}
	printf("phan tu lon nhat la: %f\n", max);
	printf("phan tu nho nhat la: %f\n", min);
}

//bai 2
void hoanvi(float &x, float &y)
{
	float t = x;
	x = y;
	y = t;
}
void SapXep_c1(float** a, int m, int n)
{
	int z = m*n;
	for (int i = 0; i < z - 1; i++)
	{
		for (int j = i + 1; j < z; j++)
		{
			if (a[i / n][i % n] > a[j / n][j % n])
				hoanvi(a[i / n][i % n], a[j / n][j % n]);
		}
	}
}

//cach 2
void DoMang2ChieuSangMang1Chieu(float** a, int m, int n, float* b, int &nb)
{
	nb = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[nb++] = a[i][j];
		}
	}
}
void DoMang1ChieuSangMang2Chieu(float** a, int m, int n, float* b, int nb)
{
	nb = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = b[nb++];
		}
	}
}

void SapXepMang1Chieu(float* b, int nb)
{
	for (int i = 0; i < nb-1; i++)
	{
		for (int j = i + 1; j < nb; j++)
		{
			if (b[i] > b[j])
			{
				hoanvi(b[i], b[j]);
			}
		}
	}
}

void SapXep_c2(float** a, int m, int n)
{
	int z = m*n;
	float* b = (float*)calloc(z, sizeof(float));
	int nb;
	DoMang2ChieuSangMang1Chieu(a, m, n, b, nb);
	SapXepMang1Chieu(b, nb);
	DoMang1ChieuSangMang2Chieu(a, m, n, b, nb);
	free(b);
}

//bai 3

void LaPTYenNgua(float** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		float min_dong = a[i][0];
		int imin = 0;
		int jmin = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < min_dong)
			{
				min_dong = a[i][j];
				imin = i;
				jmin = j;
			}
		}
		int kiemtra = 1;
		for (int i = 0; i < m; i++)
		{
			if (a[i][jmin] > min_dong)
			{
				kiemtra = 0;
			}
		}
		
		if (kiemtra == 1)
		{
			printf("%f\t", min_dong);
		}

	}
}
//bai 4
int LaPhanNguyenDuong(float** a, int m, int n, int x, int y)
{
	int dem = 0;
	for (int i = -1; i < 2; i++)
	{
		if (x + i >= 0 && x + i < m)
		{
			for (int j = -1; j < 2; j++)
			{
				if (y + j >= 0 && y + j < n)
				{
					if (a[x + i][y + j] > 0)
					{
						dem++;
					}
					
				}
			}
		}
	}
	return dem;
}

void DemPhanTuNguyenDuongTrongMang(int** &b, float** a, int m, int n)
{
	b = (int**)calloc(m, sizeof(int*));
	for (int i = 0; i < m; i++)
		*(b + i) = (int *)calloc(n, sizeof(int));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > 0)
			{
				b[i][j] = LaPhanNguyenDuong(a, m, n, i, j) - 1;//loai truong hop a[i][j] ra vi khi chay no tinh ca a[i][j]
			}
			else //<= 0
			{
				b[i][j] = LaPhanNguyenDuong(a, m, n, i, j);
			}
				
		}
	}
}

void XuatMaTranNguyen(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

//bai 5
typedef struct
{
	float heso;
	int dong;
}MANG;
void hoanvidong(float** a, int m, int n, int k, int h)
{
	float t;
	for (int i = 0; i < n; i++)
	{
		t = a[k][i];
		a[k][i] = a[h][i];
		a[h][i] = t;

	}
}

void TongDong(float** a, int m, int n, MANG b[], int &k)
{
	//b = (MANG*)calloc(m, sizeof(MANG));
	float s = 0;
	k = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			s += a[i][j];
		}
		b[k].heso = s;
		b[k].dong = i;
		k++;
		s = 0;
	}
}

void sapxep(float** a, int m, int n, MANG b[], int k)
{
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (b[i].heso > b[j].heso)
			{
				hoanvidong(a, m, n, b[i].dong, b[j].dong);
			}
		}
	}
}


//BAI TAP AP DUNG VE CON TRO
//bai 1

void NhapMang1Chieu(int* &a, int &n)
{
	printf("\nnhap n:");
	scanf("%d", &n);
	a = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		printf("nhap phan tu thu %d: ", i);
		scanf("%d", &a[i]);
	}
}

void XuatMang1Chieu(int* a, int n)
{
	printf("\nmang sau khi nhap la:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}

int DemNguyenDuong(int* a, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			dem++;
		}
	}
	return dem;
}

void Xoa(int* a, int &n, int vt)
{
	for (int i = vt; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

void XoaNPhanTu(int* a, int &n, int vt, int x)
{
	for (int i = 0; i < x; i++)
	{
		Xoa(a, n, vt);//xoa xong cap nhat lai vi tri
	}
}

//bai 2


//thuc hien tren 2 mang tuong tu giu nguyen 2 mang nay
void XoaPTTrungNhau(int* c, int &nc, int* d, int &nd)
{
	int z[100];
	int nz = 0;
	for (int i = 0; i < nc; i++)
	{
		for (int j = 0; j < nd; j++)
		{
			if (c[i] == d[j])
			{
				z[nz++] = d[j];
				Xoa(d, nd, j);
				j--;//lui lai vi khi xoa se bo qua vi tri i
				
			}
		}
		
	}
	//sau khi xoa xong mang d ta xoa mang c
	for (int i = 0; i < nz; i++)
	{
		for (int j = 0; j < nc; j++)
		{
			if (z[i] == c[j])
			{
				Xoa(c, nc, j);
				j--;//lui lai vi khi xoa se bo qua vi tri i

			}
		}
	}

}
void NoiMang(int* c, int nc, int* d, int nd, int* &e, int &ne)
{
	int z = nc + nd;
	e = (int*)calloc(z, sizeof(int));
	ne = 0;
	for (int i = 0; i < nc; i++)
	{
		e[ne++] = c[i];
	}
	for (int i = 0; i < nd; i++)
	{
		e[ne++] = d[i];
	}
}


void main()
{


		//float** a;
		//int m, n;
		//
		////bai1
		//printf("bai 1:\n");
		//NhapMaTran(a, m, n);
		//XuatMaTran(a, m, n);
		//TimPhanTuMinMax(a, m, n);
		//free(a);
		//
		////bai2
		//printf("bai 2 cach 1:\n");
		//NhapMaTran(a, m, n);
		//SapXep_c1(a, m, n);
		//XuatMaTran(a, m, n);
		//free(a);

		//printf("\nbai 2 cach 2:\n");
		//NhapMaTran(a, m, n);
		//SapXep_c2(a, m, n);
		//XuatMaTran(a, m, n);
		//free(a);

		////bai 3
		//printf("\nbai 3:\n");
		//NhapMaTran(a, m, n);
		//XuatMaTran(a, m, n);
		//
		//printf("\ncac phan tu yen ngua la:\n");
		//LaPTYenNgua(a, m, n);
		//free(a);
		//
	 //   //bai 4:
		//printf("\nbai 4:\n");
		//int** g;
		//NhapMaTran(a, m, n);
		//XuatMaTran(a, m, n);
		//DemPhanTuNguyenDuongTrongMang(g, a, m, n);
		//XuatMaTranNguyen(g, m, n);
		//free(a);
		//free(g);


		////bai 5:
		//MANG b[100];
		//int j;
		//printf("\nbai 5:\n");
		//NhapMaTran(a, m, n);
		//XuatMaTran(a, m, n);
		//TongDong(a, m, n, b, j);
		//sapxep(a, m, n, b, j);
		//printf("\nmang sau khi sap xep:\n");
		//XuatMaTran(a, m, n);
		//free(a);
		//free(b);

		//BAI TAP AP DUNG VE CON TRO

		//printf("\n---------BAI TAP AP DUNG VE CON TRO----------\n");
		int* c;
		int nc;
		//int i, k;
		//printf("\nbai1:\n");
		//NhapMang1Chieu(c, nc);
		//XuatMang1Chieu(c, nc);
		//printf("\nnhap vi tri can xoa: ");
		//scanf("%d", &i);
		//printf("nhap so lan xoa: ");
		//scanf("%d", &k);
		//
		//XoaNPhanTu(c, nc, i, k);
		//XuatMang1Chieu(c, nc);
		//free(c);

		int* d;
		int nd;
		int* e;
		int ne;
		printf("\nbai2:\n");
		NhapMang1Chieu(c, nc);
		XuatMang1Chieu(c, nc);
		
		NhapMang1Chieu(d, nd);
		XuatMang1Chieu(d, nd);

		XoaPTTrungNhau(c, nc, d, nd);
		XuatMang1Chieu(c, nc);
		XuatMang1Chieu(d, nd);
		NoiMang(c, nc, d, nd, e, ne);
		XuatMang1Chieu(e, ne);

		free(c);
		free(d);
		free(e);
}