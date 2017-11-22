#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void nhap(int a[][15], int m, FILE* f);
void xuat(int a[][15], int m, FILE* f);

typedef struct
{
	char Ma[10];
	char HoTen[40];
} SinhVien;

void WriteFile(char *FileName);
void ReadFile(char *FileName);
void Search(char *FileName);
void mahoa(char* s, int k);
void giaima(char* s, int k);
void Xoa(char* a, int vt);
void hoanvi(int &x, int &y);