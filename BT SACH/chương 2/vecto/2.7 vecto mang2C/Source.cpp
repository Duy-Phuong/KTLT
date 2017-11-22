#include <iostream>
#include <vector>
using namespace std;

//ap dung vector de tao mang vuong 2 chieu
typedef vector <float> floats;
typedef vector <floats> Float2D;

void capphat(Float2D &a, int n)
{
	a.resize(n);
	for (int i = 0; i < a.size(); i++)
	{
		a[i].resize(n);
	}
}

void nhap(Float2D &a, int n)
{
	capphat(a, n);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			cin >> a[i][j];
		}
	}
}

void xuat(Float2D &a, int n)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}
}
void main()
{
	int n;
	Float2D a;
	cout << "nhap so phan tu n: ";
	cin >> n;
	nhap(a, n);
	xuat(a, n);

}