#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	/*char str[] = "- This, a sample string.";
	char * pch;
	printf("Splitting string \"%s\" into tokens:\n", str);
	pch = strtok(str, ", -.");
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, ", -.");
	}
	return 0;*/
		int i;
		char buffer[256];
		printf("nhap 1 so: ");
		fgets(buffer, 256, stdin);
		i = atoi(buffer);
		printf("gia tri cua so do la %d. gap doi la %d.\n", i, i * 2);
		//int i;
		//char buffer[33];
		printf("nhap 1 so: ");
		scanf("%d", &i);
		itoa(i, buffer, 10);
		printf("chuoi nhan duoc la: %s\n", buffer);
		/*toa(i, buffer, 16);
		printf("he co so 16: %s\n", buffer);
		itoa(i, buffer, 2);
		printf("he nhi phan: %s\n", buffer);*/
		return 0;
}
