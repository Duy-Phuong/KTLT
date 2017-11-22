#include <stdio.h>

#define KICHTHUOC 8
#define SODUONGCHEO (2*KICHTHUOC-1)

#define TRUE 1
#define FALSE 0

int cottrong[KICHTHUOC];			// Cac cot con trong (TRUE <=> trong)
int cheoxuoitrong[SODUONGCHEO];		// Cac duong cheo xuoi con trong
int cheonguoctrong[SODUONGCHEO];	// Cac duong cheo nguoc con trong	

int loigiai[KICHTHUOC];				// Con hau i dat o toa do (i, loigiai[i])
int soloigiai = 0;

void khoitao();						// Khoi tao tat ca cot va duong cheo deu trong
void hoanghau(int j);				// Ham dat hoang hau j len hang j
void inloigiai(int loigiai[]);		// Ham in tat ca vi tri cac hoang hau tren ban co khi thanh cong

void main()
{
	khoitao();		// Khoi tao
	hoanghau(0);	// Dat hoang hau dau tien
}

// Khoi tao tat ca cot va duong cheo deu trong (TRUE)
void khoitao()
{
	for (int i = 0; i<KICHTHUOC; i++)
		cottrong[i] = TRUE;

	for (int i = 0; i<SODUONGCHEO; i++)
	{
		cheoxuoitrong[i] = TRUE;
		cheonguoctrong[i] = TRUE;
	}
}

// Ham dat hoang hau j len hang j
void hoanghau(int j)
{
	for (int i = 0; i<KICHTHUOC; i++)	// Cac cot co the dat hoang hau
		// Neu tai vi tri do cot, duong cheo xuoi va nguoc deu trong
	if (cottrong[i] && cheoxuoitrong[j - i + KICHTHUOC - 1] && cheonguoctrong[j + i])
	{
		// => ghi nhan vi tri (dat quan hau j tai cot i)
		loigiai[j] = i;

		// Danh dau cot, duong cheo xuoi & nguoc di qua no khong con trong nua
		cottrong[i] = FALSE;
		cheoxuoitrong[j - i + KICHTHUOC - 1] = FALSE;
		cheonguoctrong[j + i] = FALSE;

		if (j == KICHTHUOC - 1)				// Neu da dat quan hau cuoi cung
			inloigiai(loigiai);				// => In loi giai
		else
			hoanghau(j + 1);					// Nguoc lai dat quan hau tiep theo

		// Du thanh cong hay that bai deu quay lai de tim loi giai moi
		// <=> phuc hoi trang thai truoc khi dat hoang hau j
		cottrong[i] = TRUE;
		cheoxuoitrong[j - i + KICHTHUOC - 1] = TRUE;
		cheonguoctrong[j + i] = TRUE;
	}
}

// Ham in tat ca vi tri cac hoang hau tren ban co khi thanh cong
void inloigiai(int loigiai[])
{
	int i, j;
	printf("Loi giai thu %d:\n", ++soloigiai);

	printf(" ");
	for (i = 0; i<KICHTHUOC; i++)
		printf("%3d", i);
	printf("\n");

	for (j = 0; j<KICHTHUOC; j++)
	{
		printf("%d  ", j);
		for (i = 0; i<loigiai[j]; i++)
			printf("_  ");

		printf("x  ");

		for (i = loigiai[j] + 1; i<KICHTHUOC; i++)
			printf("_  ");

		printf("\n");
	}

	printf("\n\n");
}