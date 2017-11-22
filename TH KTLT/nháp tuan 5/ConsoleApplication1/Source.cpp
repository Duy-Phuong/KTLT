#include<stdio.h>
#include<conio.h>
#include<string.h>

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
void main()
{
	char s[100];
	char s1[100];
	int k;
	printf("nhap 1 so lam key(k > 0 va k < 64):\n");
	scanf("%d", &k);
	printf("nhap chuoi:\n");
	fflush(stdin);
	gets(s);
	FILE* f = fopen("input.txt", "wt");
	mahoa(s, k);
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == '~' && s[i + 1] == '.')
		{
			Xoa(s, i + 1);
			Xoa(s, i);
			strcat(s, "(SOH)1");
		}
	}
	fputs(s, f);
	fclose(f);
	FILE* f3 = fopen("input.txt", "rt");
	fgets(s1, 100, f3);
	//mahoa(s1, 3);
	giaima(s1, k);
	puts(s1);
	fclose(f3);

	//FILE* f1 = fopen("input1.txt", "wb");
	//int n = strlen(s);
	//for (int i = 0; i < n; i++)
	//{
	//	fwrite(&s[i], sizeof(char), 1, f1);
	//}
	//fclose(f1);
	





}