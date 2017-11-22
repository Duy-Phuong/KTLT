#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void main()
{
	//bai 3
	char s[100];
	FILE* f = fopen("MSSV.txt", "wt");
	while (1)
	{
		gets(s);
		if (stricmp(s, "end") == 0)
		{
			break;
		}
		fprintf(f, "%s\n", s);
		
	}
	fclose(f);
	//bai 4
	printf("\n----noi dung cua tap tin-----\n");
	FILE* fp = fopen("MSSV.txt", "rt");
	while (fgets(s, 100, f) != NULL)
	{
		printf("%s", s);
	}
	fclose(fp);

	FILE* fd = fopen("MSSV.txt", "rt");
	int* b = (int*)calloc(26, sizeof(int));
	char ch;
	int z;
	while (1)
	{
		ch = fgetc(fd);
		if (!feof(fd))
		{
			if (ch >= 'a' && ch <= 'z')
			{
				z = ch - 97;
				b[z]++;
			}

			if (ch >= 'A' && ch <= 'Z')
			{
				z = ch - 65;
				b[z]++;
			}
		}
		else
			break;
	}
	char j = 'a';
	char k = 'A';
	for (int i = 0; i < 26; i++)
	{
		printf("so lan xuat hien cua ki tu %c hay %c la: %d\n", j, k, b[i]);
		j++;
		k++;
	}
	free(b);
	fclose(fd);

}
