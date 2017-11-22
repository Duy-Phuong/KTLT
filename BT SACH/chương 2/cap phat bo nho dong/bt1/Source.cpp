#include <iostream>
#include <vector>
using namespace std;

// mang 2 chieu theo kieu vector
typedef struct vector <int> arr;// phai dinh nghia trong mang 2 chieu

void nhap(vector <arr> &a, int m, int n)// phai co dau & de thay doi gia tri
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
}

void Xuat(vector <arr> a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}
}
void main()
{
	int m, n;
	vector <arr> a;
	cout << "nhap vao dong va cot\n";
	cin >> m;
	cin >> n;

	// mang 2 chieu theo kieu vector
	a.resize(m);
	for (int i = 0; i < m; i++)
	{
		a[i].resize(n);
	}
	nhap(a, m, n);
	Xuat(a, m, n);

	//mang dong 1 chieu khi xac dinh so phan tu ban dau
	/*vector <int> a;
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]" << "  ";
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
		
	}*/

	//mang 1 chieu kih thuoc tu dieu chinh

}