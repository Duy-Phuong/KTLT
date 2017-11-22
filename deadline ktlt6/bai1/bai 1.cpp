#include <stdio.h>
#include <string.h>

typedef struct
{
	char MSSV[100];
	char ten[100];
	char ngaysinh[100];
	char gioitinh[100];
	float toan;
	float li;
	float hoa;
	float DTB;
	char name[100];
	char hodem[100];

}SV;
//tach ten ra
int TimViTriTen(char* s)
{
	int n = strlen(s);
	for (int i = n-1; i >= 0; i--)
	{
		if (s[i] != ' ' && s[i-1] == ' ')
		{
			return i;
		}
	}
}

void timten(char* ten, char* hovaten, char* hodem)
{
	int vtten = TimViTriTen(hovaten);
	strncpy(ten, hovaten + vtten, strlen(hovaten) - vtten);
	ten[strlen(hovaten) - vtten] = '\0';
	strncpy(hodem, hovaten + 0, vtten - 1);
	hodem[vtten - 1] = '\0';
}

//ham tao bag diem tong ket
void TaoBangDiemTongKet(FILE* f1, SV s[], int n)
{
	char z = '"';
	
	fprintf(f1, "<html>\n");
	fprintf(f1, "<title>Bang diem tong ket</title>\n");
	fprintf(f1, "<body>\n");
	fprintf(f1, "<p style='text-align:center'>\n");
	fprintf(f1, "<b>\n");
	fprintf(f1, "<span style='font-size:20.0pt;font-family:%cTahoma%c'>\n", z, z);
	fprintf(f1, "BANG DIEM TONG KET");
	fprintf(f1, "</span>\n");
	fprintf(f1, "</b>\n");
	fprintf(f1, "</p>\n");
	fprintf(f1, "<table align=center border=1 cellspacing=0 cellpadding=5>\n");
	fprintf(f1, "<tr>\n");
	fprintf(f1, "<td align=center><b>MSSV</b></td>\n");
	fprintf(f1, "<td align=center><b>Ho va ten lot</b></td>\n");
	fprintf(f1, "<td align=center><b>Ten</b></td>\n");//

	fprintf(f1, "<td align=center><b>Ngay sinh</b></td>\n");
	fprintf(f1, "<td align=center><b>Gioi tinh</b></td>\n");
	fprintf(f1, "<td align=center><b>Diem trung binh</b></td>\n");
	fprintf(f1, "<td align=center><b>Chi tiet</b></td>\n");

	fprintf(f1, "</tr>\n");
	fprintf(f1, "<tr>\n");

	for (int i = 0; i < n; i++)
	{

		fprintf(f1, "<td>%s</td>\n", s[i].MSSV);
		fprintf(f1, "<td>%s</td>\n", s[i].hodem);
		fprintf(f1, "<td>%s</td>\n", s[i].name);
		fprintf(f1, "<td align=center>%s</td>\n", s[i].ngaysinh);
		fprintf(f1, "<td align=center>%s</td>\n", s[i].gioitinh);
		fprintf(f1, "<td align=center>%.2f</td>\n", s[i].DTB);
		fprintf(f1, "<td align=center><a href=%c1412888.html%c>Xem diem</a></td>\n", z, z);

		if (i + 1 < n)
		{
			fprintf(f1, "</tr>\n");
			fprintf(f1, "<tr>\n");
		}
	}



	fprintf(f1, "</tr>\n");
	fprintf(f1, "</table>\n");
	fprintf(f1, "</body>\n");
	fprintf(f1, "</html>\n");
}
//ham tao bang diem chi tiet
void TaoFielhtmlChiTiet(SV s)
{
	char* MSSVhtml =new char[100];
	MSSVhtml = strdup(s.MSSV);
	strcat(MSSVhtml, ".html");
	char z = '"';
	FILE* f2 = fopen(MSSVhtml, "wt");
	fprintf(f2, "<html>\n");
	fprintf(f2, "<title>Bang diem chi tiet</title>\n");
	fprintf(f2, "<body>\n");
	fprintf(f2, "<p style='text-align:center'>\n");
	fprintf(f2, "<b>\n");
	fprintf(f2, "<span style='font-size:20.0pt;font-family:%cTahoma%c'>\n", z, z);
	fprintf(f2, "BANG DIEM CHI TIET\n");
	fprintf(f2, "<br>\n");
	fprintf(f2, "Sinh viên: %s (%s)\n", s.ten, s.MSSV);
	fprintf(f2, "</span>\n");
	fprintf(f2, "</b>\n");
	fprintf(f2, "</p>\n");
	fprintf(f2, "<table align=center border=1 cellspacing=0 cellpadding=5>\n");
	fprintf(f2, "<tr>\n");
	fprintf(f2, "<td align=center><b>Toan</b></td>\n");
	fprintf(f2, "<td align=center><b>Ly</b></td>\n");
	fprintf(f2, "<td align=center><b>Hoa</b></td>\n");
	fprintf(f2, "<td align=center><b>Diem trung binh</b></td>\n");

	fprintf(f2, "</tr>\n");
	fprintf(f2, "<tr>\n");


	fprintf(f2, "<td align=center>%f</td>\n", s.toan);
	fprintf(f2, "<td align=center>%f</td>\n", s.li);
	fprintf(f2, "<td align=center>%f</td>\n", s.hoa);
	fprintf(f2, "<td align=center>%f</td>\n", s.DTB);

	fprintf(f2, "</tr>\n");
	fprintf(f2, "</table>\n");
	fprintf(f2, "</body>\n");
	fprintf(f2, "</html>\n");


	fclose(f2);
	//delete[] MSSVhtml; khong co ms chay dk
}

void main()
{
	SV s[100];
	int i = 0;
	int n = 0;
	FILE* f = fopen("DSSV.txt", "rt");
	while (!feof(f))
	{
		fscanf(f, "%[^-]-%[^(](%[^,],%[^)])%f\t%f\t%f\n", &s[i].MSSV, &s[i].ten, &s[i].ngaysinh, &s[i].gioitinh, &s[i].toan, &s[i].li, &s[i].hoa);
		printf("%s-%s-%s-%s-%.1f-%.1f-%.1f", s[i].MSSV, s[i].ten, s[i].ngaysinh, s[i].gioitinh, s[i].toan, s[i].li, s[i].hoa);
		i++;
		n++;
	}
	for (int i = 0; i < n; i++)
	{
		s[i].DTB = (s[i].toan + s[i].li + s[i].hoa) / 3;
		printf("\n%.1f", s[i].DTB);
		timten(s[i].name, s[i].ten, s[i].hodem);
	}

	fclose(f);

	//tao bang diem tong ket
	FILE* f1 = fopen("BANGDIEM.html", "wt");
	TaoBangDiemTongKet(f1, s, n);
	fclose(f1);

	//tao bang diem chi tiet
	for (i = 0; i < n; i++)
	{
		TaoFielhtmlChiTiet(s[i]);
	}
}