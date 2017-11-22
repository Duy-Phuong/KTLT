#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//bai1: chuan hoa chuoi
int STRLEN(char* a)
{
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return i;
}

void Xoa(char* a, int vt)
{
	int n = STRLEN(a);
	for (int i = vt; i < n-1; i++)
	{
		a[i] = a[i + 1];
	}
	a[n - 1] = '\0';
}

void XoaKhoangTrangThua(char* a)
{
	int n = STRLEN(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == ' '  && a[i + 1] == ' ')
		{
			Xoa(a, i);
			i--;
			n--;
		}

	}
	if (a[0] == ' ')
	{
		Xoa(a, 0);
		n--;
	}
	if (a[n-1] == ' ')
	{
		Xoa(a, n-1);
		n--;
	}
}

void VietHoaKiTuDau(char* a)
{
	int n = STRLEN(a);
	if (a[0] != ' ')
	{
		if (a[0] >= 'a' && a[0] <= 'z')
		{
			a[0] -= 32;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == ' ' && a[i + 1] != ' ')
		{
			if (a[i+1] >= 'a' && a[i+1] <= 'z')
			{
				a[i+1] -= 32;
			}
		}
		if (a[i] != ' ' && (a[i + 1] >= 'A' && a[i + 1] <= 'Z'))
		{
			a[i + 1] += 32;
		}
	}
}

char* STRDUP(char *s)
{
	int n = STRLEN(s);

	char *p = (char *)malloc((n + 1) * sizeof(char));// them ki tu '\0'

	for (int i = 0; i < n; i++)
	{
		p[i] = s[i];
	}
	p[n] = '\0';
	return p;
}


void ChuanHoaChuoi(char* a)
{
	char* p = STRDUP(a);
	XoaKhoangTrangThua(p);
	VietHoaKiTuDau(p);
	puts(p);
}

//bai 2: xoa ki tu theo yeu cau
void XoaKiTu(char* a, char c)
{
	int n = STRLEN(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == c)
		{
			Xoa(a, i);
			i--;
		}
		if (c >= 'A' && c <= 'Z')
		{
			if (a[i] == c + 32)
			{
				Xoa(a, i);
				i--;//sau khi xoa cap nhat lai vi tri
			}
		}
		if (c >= 'a' && c <= 'z')
		{
			if (a[i] == c - 32)
			{
				Xoa(a, i);
				i--;
			}
		}
	}
}

void XoaKiTuTheoYeuCau(char* a, char c)
{
	char* p = STRDUP(a);
	XoaKiTu(p, c);
	puts(p);
}

//bai 3:dem bao nhieu tu dai hon 1 so nguyen n trong chuoi cho truoc
int DemSoTu(char* a, int b)
{
	int dem = 0;
	int n = STRLEN(a);
	int k = 1;// th k co dau ' ' o dau
	for (int i = 0; i < n; i++)
	{
	
		if (a[i] != ' ' && a[i + 1] != ' ')
		{
			k++;
			if (a[i + 1] == '\0')
			{
				k--;
			}
		}
		if (a[i] != ' ' && a[i + 1] == ' ' || a[i] != ' ' && a[i + 1] == '\0')
		{
			if (k > b)
			{
				dem++;
			}
			k = 1;
		}
	}
	return dem;
}
// bai 4: xuat ra ki tu dai nhat cach nhau bang dau tab
void DemKiTu(char* a, int b[100], int &nb)
{
	nb = 0;
	int dem = 0;
	int n = STRLEN(a);
	int k = 1;
	for (int i = 0; i < n; i++)
	{

		if (a[i] != ' ' && a[i + 1] != ' ')
		{
			k++;
			if (a[i + 1] == '\0')
			{
				k--;
			}
		}
		if (a[i] != ' ' && a[i + 1] == ' ' || a[i] != ' ' && a[i + 1] == '\0')
		{
			b[nb++] = k;
			k = 1;
		}
	}
}

int MAX(int b[100], int nb)
{
	int max = b[0];
	for (int i = 1; i < nb; i++)
	{
		if (b[i] > max)
			max = b[i];
	}
	return max;
}

void XuatKiTuDaiNhat(char* a, int c, int b[100], int &nb)//mang b chua vt cuoi cua nhung tu co do dai max
{
	nb = 0;
	int dem = 0;
	int n = STRLEN(a);
	int k = 1;
	for (int i = 0; i < n; i++)
	{

		if (a[i] != ' ' && a[i + 1] != ' ')
		{
			k++;
			if (a[i + 1] == '\0')
			{
				k--;
			}
		}
		if (a[i] != ' ' && a[i + 1] == ' ' || a[i] != ' ' && a[i + 1] == '\0')
		{
			if (k == c)
			{
				//printf("%s\t", )
				b[nb++] = i;
			}
			k = 1;
		}
	}
}

void Bai4(char* a, int c, int b[100], int nb)
{
	int n = STRLEN(a);
	for (int i = 0; i < nb; i++)
	{
		for (int j = b[i] - c; j <= b[i]; j++)
		{
			printf("%c", a[j]);
		}
		printf("\t");
	}
}
//bai 5: xuat ra tu vi tri pos n ki tu theo yeu cau

char* XuatKiTuTheoYeuCau(char* a, int pos, int b)
{
	char* d = (char*)malloc(100 * sizeof(char));
	int n = STRLEN(a);
	for (int i = 0; i < n; i++)
	{
		if (i == pos)
		{
			for (int j = 0; j < b; j++)
			{
				d[j] = a[i];
				i++;
			}
			d[b] = '\0';
			return d;
		}
	}
	return d;
}
void main()
{
	char* a = (char*)malloc(100*sizeof(char));
	
	char* d = (char*)malloc(100 * sizeof(char));
	char c;
	int b, e, pos;
	printf("nhap 1 chuoi: ");
	gets(a);
	printf("chuoi sau khi duoc chuan hoa la: ");
	ChuanHoaChuoi(a);
	printf("chuoi truoc khi duoc chuan hoa la: ");
	puts(a);

	printf("\nbai 2: Xoa ki tu theo yeu cau:\n");
	printf("nhap vao ki tu: ");
	scanf("%c", &c);
	printf("chuoi sau khi xoa la: ");
	XoaKiTuTheoYeuCau(a, c);

	printf("\nbai 3: dem so tu nhieu hon 1 so co truoc:\n");
	printf("nhap n: ");
	scanf("%d", &b);
	int z = DemSoTu(a, b);
	printf("so tu dai hon %d ki tu la: %d\n", b, z);


	//bai 4
	int f[100];
	int nf;
	int h[100];
	int nh;
	DemKiTu(a, f, nf);
	for (int i = 0; i < nf; i++)
	{
		printf("%d\t", f[i]);
	}
	int k = MAX(f, nf);
	printf("\n%d\n", k);
	XuatKiTuDaiNhat(a, k, h, nh);
	for (int i = 0; i < nh; i++)
	{
		printf("%d\t", h[i]);
	}
	printf("\ncac ki tu co do dai max la: \n");
	Bai4(a, k, h, nh);


	printf("\nbai 5: cat n ki tu tu vi tri pos cho truoc\n");

	printf("nhap so ki tu e:\n");
	scanf("%d", &e);
	printf("nhap vi tri cat pos:\n");
	scanf("%d", &pos);
	printf("chuoi sau khi tach ra %d ki tu tu vi tri %d cho truoc la: ", e, pos);
	d = XuatKiTuTheoYeuCau(a, pos, e);
	puts(d);

	free(d);


}