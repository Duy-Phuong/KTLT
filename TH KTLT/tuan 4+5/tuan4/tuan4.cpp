#include "thuvien4.h"


void main()
{
	char s[100];
	printf("nhap 1 chuoi: ");
	gets(s);
	printf("-----1------\n");
	DemKiTu(s);
	int dem = DemTu(s);
	printf("so tu trong chuoi la: %d\n", dem);
	printf("-----2------\n");
	cut(s);
	printf("-----3------\n");
	printf("so tu lon hon so cho truoc la:\n");
	int b;
	printf("nhap so n:\n");
	scanf("%d", &b);
	int x = DemSoTu(s, b);
	printf("so tu lon hon so %d la: %d\n", b, x);
	printf("-----4------\n");
	TimTuMaxMin(s);
	printf("-----5------\n");
	VietHoaKiTuDau(s);

	printf("\nbai 2: xuat so nguyen ra o dang chuoi\n");
	ChuyenSoSangChuoi();

	printf("\nbai 3:\n");
	fflush(stdin);
	char a[1000000];
	//cau a
	printf("nhap doan van:\n");
	gets(a);
	ChuanHoaDoanVan(a);
	//cau b
	demsocau(a);
	//cau c
	DemTuTrongDoan(a);
	//cau d
	DaoChuoi(a);
	//cau e
	mang d[100];
	int nd;
	printf("\nxuat cac tu nguoc lai:\n");
	DaoTu(a, d, nd);
	printf("%d\n", nd);		//kiem tra nd va mang
	puts(d[2].a);
	XuatTuNguocLai(d, nd);

	//bai4
	fflush(stdin);
	char* s1 = (char*)malloc(100 * sizeof(char));
	char* s2 = (char*)malloc(100 * sizeof(char));
	printf("\nbai 4:\n");
	Tong(s1, s2);
	free(s1);
	free(s2);

	//bai5
	fflush(stdin);
	char* s3 = (char*)malloc(100 * sizeof(char));
	char* s4 = (char*)malloc(100 * sizeof(char));
	printf("\nbai 5:\n");
	printf("nhap chuoi s1: ");
	gets(s3);
	printf("nhap chuoi s2: ");
	gets(s4);
	TimKiem(s3, s4);
	free(s3);
	free(s4);

	//bai6: 
	fflush(stdin);
	char* s5 = (char*)malloc(100 * sizeof(char));
	printf("\nbai 6:\n");
	printf("nhap chuoi s1: ");
	gets(s5);
	if (KiemTraHopLe(s1))
	{
		printf("bieu thuc hop le\n");
	}
	else
	{
		printf("bieu thuc khong hop le\n");
	}
	free(s5);

	//bai 7:
	fflush(stdin);
	char* s7 = (char*)malloc(100 * sizeof(char));
	char* s8 = (char*)malloc(100 * sizeof(char));
	printf("\nbai 7:\n");
	printf("nhap chuoi s1: ");
	gets(s7);
	printf("nhap chuoi s2: ");
	gets(s8);
	MANG h[100];
	int nh;
	Timchuoicon(s7, s8, h, nh);
	printf("chuoi con chung lon nhat la:\n");
	Xuat(s7, h, nh);
	printf("\n");
	free(s7);
	free(s8);

}