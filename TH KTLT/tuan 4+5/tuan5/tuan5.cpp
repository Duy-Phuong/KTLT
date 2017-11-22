#include "thuvien5.h"

void main()
{
	////bai 1
	//int a[10000];
	//FILE* f = fopen("input.txt", "wt");
	//FILE* f1 = fopen("input1.txt", "wb");
	//for (int i = 0; i < 10000; i++)
	//{
	//	a[i] = rand();
	//	fprintf(f, "%d ", a[i]);
	//	printf("%d ", a[i]);
	//}

	//fwrite(a, sizeof(int), 10000, f1);
	//int z2 = ftell(f);
	//int z1 = ftell(f1);
	//printf("\nkich thuoc tap tin o dang van ban la:  %d, kich thuoc tap tin theo kieu nhi phan la: %d\n", z2, z1);
	//if (z2 > z1)
	//{
	//	printf("\nkich thuoc tap tin o dang van ban la:  %d lon hon kich thuoc tap tin theo kieu nhi phan la: %d\n", z2, z1);
	//}
	//else
	//{
	//	printf("\nkich thuoc tap tin o dang van ban la:  %d nho hon kich thuoc tap tin theo kieu nhi phan la: %d\n", z2, z1);
	//}
	//fcloseall();

	////bai 2
	//int c[100][15];
	//int m;
	//FILE* f2 = fopen("bai2.txt", "rt");
	//printf("nhap so luong dong m(tuy thuoc vao so luong so nguyen trong tap tin):\n");
	//scanf("%d", &m);
	//nhap(c, m, f2);
	//xuat(c, m, f2);
	//fclose(f2);

	////bai 3
	//printf("\nnhap van ban vao tap tin, muon ket thuc nhap end !\n");
	//char s[100];
	//FILE* f3 = fopen("MSSV.txt", "wt");
	//while (1)
	//{
	//	gets(s);
	//	if (stricmp(s, "end") == 0)
	//	{
	//		break;
	//	}
	//	fprintf(f3, "%s\n", s);

	//}
	//fclose(f3);
	////bai 4
	//printf("\n----noi dung cua tap tin-----\n");
	//FILE* fp = fopen("MSSV.txt", "rt");
	//while (fgets(s, 100, fp) != NULL)
	//{
	//	printf("%s", s);
	//}
	//fclose(fp);

	//printf("-----so luong ki tu xuat hien trong tap tin-----\n");
	//FILE* fd = fopen("MSSV.txt", "rt");
	//int* b = (int*)calloc(26, sizeof(int));
	//char ch;
	//int z;
	//while (1)
	//{
	//	ch = fgetc(fp);
	//	if (!feof(fd))
	//	{
	//		if (ch >= 'a' && ch <= 'z')
	//		{
	//			z = ch - 97;
	//			b[z]++;
	//		}

	//		if (ch >= 'A' && ch <= 'Z')
	//		{
	//			z = ch - 65;
	//			b[z]++;
	//		}
	//	}
	//	else
	//		break;
	//}
	//char j = 'a';
	//char k = 'A';
	//for (int i = 0; i < 26; i++)
	//{
	//	printf("so lan xuat hien cua ki tu %c hay %c la: %d\n", j, k, b[i]);
	//	j++;
	//	k++;
	//}
	//free(b);
	//fclose(fd);
	//
	////bai 5
	//int e;
	//while (1)
	//{
	//	printf("\n---MENU----\n");
	//	printf("\n1. Nhap DSSV\n");
	//	printf("2. Tim kiem\n");
	//	printf("0. Thoat\n");
	//	printf("Ban chon 1, 2, 0: ");
	//	fflush(stdin);
	//	scanf("%d", &e);
	//	if (e == 1)
	//	{
	//		WriteFile("SinhVien.txt");
	//		ReadFile("SinhVien.txt");
	//	}
	//	else if (e == 2)
	//		Search("SinhVien.txt");
	//	else break;
	//} 

	//bai 7
	int r[100];
	int s2[100] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
	FILE* f11 = fopen("bai7.txt", "wb");
	for (int i = 0; i < 18; i++)
	{
		if (i % 2 == 0)
			hoanvi(s2[i], s2[i + 1]);
	}
	for (int i = 0; i < 18; i++)
	{
		fwrite(&s2[i], sizeof(int), 1, f11);
	}
	fclose(f11);

	FILE* f22 = fopen("bai7.txt", "rb");
	int o;
	
	int q=0;
	while (1)
	{
		fread(&o, sizeof(int), 1, f22);
		
		if (!feof(f22))
		{
			r[q++] = o;
			printf("%d\t", o);
		}
		else
			break;
	}
	for (int i = 0; i < q; i++)
	{
		if (i % 2 == 0)
			hoanvi(r[i], r[i + 1]);
	}
	printf("\nsau khi giai ma:\n");
	for (int i = 0; i < q; i++)
	{
		printf("%d\t", r[i]);
	}
	fclose(f22);

	//bai 8
	/*char g[100];
	char g1[100];
	int l;
	printf("nhap 1 so lam key(k > 0 va k < 64):\n");
	scanf("%d", &l);
	printf("nhap chuoi:\n");
	fflush(stdin);
	gets(g);
	FILE* f8 = fopen("bai8.txt", "wt");
	mahoa(g, l);
	for (int i = 0; i < strlen(g); i++)
	{
		if (g[i] == '~' && g[i + 1] == '.')
		{
			Xoa(g, i + 1);
			Xoa(g, i);
			strcat(g, "(SOH)1");
		}
	}
	fputs(g, f8);
	fclose(f8);
	FILE* f9 = fopen("bai8.txt", "rt");
	fgets(g1, 100, f9);
	printf("chuoi sau khi duoc giai ma la:\n");
	giaima(g1, l);
	puts(g1);
	fclose(f9);
*/


}