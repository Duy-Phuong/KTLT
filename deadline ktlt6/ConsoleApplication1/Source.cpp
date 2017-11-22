#include <stdio.h>
#include <string.h>


int TimViTriTen(char* s)
{
	int n = strlen(s);
	for (int i = n-1; i >= 0; i--)
	{
		if (s[i] != ' ' && s[i - 1] == ' ')
		{
			return i;
		}
	}
}

void timten(char* ten, char* hovaten, char* hodem)
{
	int vtten = TimViTriTen(hovaten);
	strncpy(ten, hovaten + vtten, strlen(hovaten) - vtten);//sau khi copy phai co dau "\0"
	ten[strlen(hovaten) - vtten] = '\0';
	strncpy(hodem, hovaten + 0, vtten - 1);
	hodem[vtten - 1] = '\0';
}

void main()
{
	char s[100];
	char a[100];
	char b[100];
	gets(s);
	timten(a, s, b);
	puts(a);
	puts(b);


}