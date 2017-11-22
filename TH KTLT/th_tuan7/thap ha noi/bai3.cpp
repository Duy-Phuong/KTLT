#include <stdio.h>

// Ham chuyen n dia cotA -> cotC (trung gian cotB)
void hanoi(int n, char cotA, char cotB, char cotC);

int buoc = 0;

void main()
{
	int n;
	printf("Nhap so luong dia: ");
	scanf("%d", &n);

	// Chuyen n dia A -> C (trung gian B)
	hanoi(n, 'A', 'B', 'C');
}

// Ham chuyen n dia cotA -> cotC (trung gian cotB)
void hanoi(int n, char cotA, char cotB, char cotC)
{
	if (n == 1)	// Chuyen 1 dia cotA -> cotC
		printf("Buoc %d. Chuyen 1 dia tu cot %c sang cot %c\n", ++buoc, cotA, cotC);
	else
	{
		// Chuyen n-1 dia cotA -> cotB (trung gian C)
		hanoi(n - 1, cotA, cotC, cotB);

		// Chuyen 1 dia cotA -> cotC
		printf("Buoc %d. Chuyen 1 dia tu cot %c sang cot %c\n", ++buoc, cotA, cotC);

		// Chuyen n-1 dia cotB -> cotC (trung gian A)
		hanoi(n - 1, cotB, cotA, cotC);
	}
}