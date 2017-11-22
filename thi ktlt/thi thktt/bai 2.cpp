#include <stdio.h>




void main()
{
	int nam;
	int soCT;
	LIST l;
	Init(l);
	//Mã cầu thủ, họ tên, năm sinh, chỉ số, câu lạc bộ, trạng thái
	CT p[100];
	FILE* f = fopen("DanhSachCT.txt", "rt");
	if (f == NULL)
	{
		printf("00\n");
		//break;
	}
	fscanf(f, "%d\n", &nam);
	printf("nam: %d\n", nam);
	fscanf(f, "%d\n", &soCT);
	printf("so cau thu: %d\n", soCT);
	for (int i = 0; i < soCT; i++)
	{
		fflush(stdin);
		fscanf(f, "%s\n%[^\n]\n%d\n%d\n%[^\n]\n", &p[i].maCT, &p[i].hoten, &p[i].namsinh, &p[i].chiso, &p[i].caulacbo);
		p[i].tuoi = (2015 - p[i].namsinh);
		if (p[i].tuoi <= 18)
		{
			strcpy(p[i].trangthai, "tre");
		}
		else
		{
			if (p[i].tuoi <= 21 && p[i].chiso >= 70)
			{
				strcpy(p[i].trangthai, "tre tiem nang");
			}
			else
			{
				strcpy(p[i].trangthai, "chuyen nghiep");
			}
		}
		//xuatCT(p[i]);
		addlast(l, p[i]);
	}
	printf("sau khi dua vao dslk\n");
	//print(l);
	fclose(f);
	//bai 2
	FILE* f1;
	for (int i = 0; i < soCT; i++)
	{
		if (p[i].tuoi > 33 && p[i].chiso <= 60)
		{
			NODE* p1 = creatnode(p[i]);
			getnodebefore(l, p1);
			remove(l, p1);
			xuatCTrataptin(f1, p[i]);
		}
	}
	//bai 3
	FILE* f2;
	for (int i = 0; i < soCT; i++)
	{
		if (p[i].tuoi > 33 && p[i].chiso <= 60)
		{
			xuatCTrataptin2(f2, p[i]);//vi khi doc o bai 1 em da cap nhat trang thai cho no roi nen bay gio chi xuat lai
		}
	}
	//bai 4
	FILE* f3;
	int max = timchisomax(soCT, p);
	for (int i = 0; i < soCT; i++)
	{
		if (stricmp(p[i].trangthai, "tretiemnang") == 0 && p[i].chiso == max)
		{
			xuatCTrataptin2(f3, p[i]);
		}
	}
}