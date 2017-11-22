#include "thuvien5.h"

//bai 2
void nhap(int a[][15], int m, FILE* f)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			fscanf(f, "%d", &a[i][j]);
		}
	}
}
void xuat(int a[][15], int m, FILE* f)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

//bai 5


void WriteFile(char *FileName)
{
	FILE *f;
	int n, i;
	SinhVien sv;
	f = fopen(FileName, "ab");
	printf("Nhap so sinh vien: ");
	scanf("%d", &n);
	fflush(stdin);
	for (i = 1; i <= n; i++)
	{
		printf("Sinh vien thu %i\n", i);
		printf(" - MSSV: ");
		gets(sv.Ma);
		printf(" - Ho ten: ");
		gets(sv.HoTen);
		fwrite(&sv, sizeof(sv), 1, f);
		fflush(stdin);
	}
	fclose(f);
}

void ReadFile(char *FileName)
{
	FILE *f;
	SinhVien sv;
	f = fopen(FileName, "rb");
	printf(" MSSV | Ho va ten\n");
	fread(&sv, sizeof(sv), 1, f);
	while (!feof(f))
	{
		printf(" %s | %s\n", sv.Ma, sv.HoTen);
		fread(&sv, sizeof(sv), 1, f);
	}
	fclose(f);
	printf("Bam phim bat ky de tiep tuc!!!");
	getch();
}

void Search(char *FileName)
{
	char MSSV[10];
	FILE *f;
	int Found = 0;
	SinhVien sv;
	fflush(stdin);
	printf("Ma so sinh vien can tim: ");
	gets(MSSV);
	f = fopen(FileName, "rb");
	while (!feof(f) && Found == 0)
	{
		fread(&sv, sizeof(sv), 1, f);
		if (strcmp(sv.Ma, MSSV) == 0) Found = 1;
	}
	fclose(f);
	if (Found == 1)
		printf("Tim thay SV co ma %s. Ho ten la: %s", sv.Ma, sv.HoTen);
	else
		printf("Tim khong thay sinh vien co ma %s", MSSV);

	printf("\nBam phim bat ky de tiep tuc!!!");
	getch();

}
//bai 7
void hoanvi(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}

//bai 8
void mahoa(char* s, int k)
{
	int i, n = strlen(s);
	for (i = 0; i < n; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = 'A' + ((s[i] - 'A' + k) % 26);
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = 'a' + ((s[i] - 'a' + k) % 26);
	}
}


void giaima(char* s, int k)
{
	int i, n = strlen(s);
	for (i = 0; i < n; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = 'A' + ((s[i] - 'A' + 26 - k) % 26);
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = 'a' + ((s[i] - 'a' + 26 - k) % 26);
		if (s[i] == '(' && s[i + 1] == 'S' && s[i + 2] == 'O' && s[i + 3] == 'H' && s[i + 4] == ')' && s[i + 5] == '1')
		{
			Xoa(s, i + 5);
			Xoa(s, i + 4);
			Xoa(s, i + 3);
			Xoa(s, i + 2);
			Xoa(s, i + 1);
			Xoa(s, i);
			strcat(s, "~.");
			break;
		}
		
	}
}

void Xoa(char* a, int vt)
{
	int n = strlen(a);
	for (int i = vt; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	a[n - 1] = '\0';
}