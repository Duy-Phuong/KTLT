#include <stdio.h>

void CutFile(char* filename)
{
	int n;
	printf("nhap so file ban can chia: ");
	scanf("%d", &n);
	FILE* f = fopen(filename, "rb");
	char s;
	char* c = "a";
	int kichthuoc = (int)ftell(f) / n + 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < kichthuoc; j++)
		{
			fread(&s, 1, 1, f);
			printf("%s", s);
			FILE* f1 = fopen(c, "ab");
			fwrite(&s, 1, 1, f1);
			fclose(f1);
		}
		//c++;
	}
	fclose(f);
}
void main()
{
	CutFile("INPUT.txt");

}