#include <iostream>
#include <string>
using namespace std;
void main()
{
	int n = 5;
	string s;
	char t;
	//gets(s);
	//puts(s);
	fflush(stdin);
	getline(std :: cin,s);
	cout << s << "\n";
	for (int i = 0; i < n-1; i++)
	{
		for (int j = n - 1; j>i; j--)
		{
			//printf("i = %d\t j = %d\n", i, j);
			cout << i << "  " << j << "\n";
			if (s[j-1]> s[j])
			{
				t = s[j];
				s[j] = s[j - 1];
				s[j - 1] = t;
			}
		}
	}
	cout << s << "\n";

}