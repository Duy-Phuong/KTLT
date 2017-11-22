#include <iostream>
#include <vector>
using namespace std;
// KIEU VECTOR


void Nhap(vector <int> &a)
{
	int n;
	cin >> n;
	while (n < 1)
	{
		return;
	}
	a.resize(n);
	for (int i = 0; i < a.size(); i++)
	{
		cout << "nhap phan tu thu " << i << "  ";
		cin >> a[i];
	}

}

void xuat(vector <int> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << "  ";
	}
}

//nhap mang dong cac phan tu khong can so luong cho truoc

//void xuatmang(const vector <float> &a)
//{
//	for (int i = 0; i < a.size(); i++)
//	{
//		cout << a[i] << "  ";
//	}
//}
//
//void nhapmang(vector <float> &a)
//{
//	float x;
//	while (cin >> x)
//	{
//		a.push_back(x);//tham x vao cuoi mang mang tu  gian ra 1 pt
//	}
//
//}

void cat(vector <int> &a, vector <int> &b)
{
	int k = a.size();
	int newsize = a.size() + b.size();
	a.resize(newsize);
	
	for (int i = 0; i < b.size(); i++)
	{
		//a.push_back(b[i]); khi them kieu nay thi mang se thanh 12 000 345 do them tiep vao cuoi mang a
		a[k++] = b[i];
	}
}
	
void cut(vector <int> &a, vector <int> &b, int vt)
{
	b.resize(0);
	for (int i = vt; i < a.size(); i++)
	{
		b.push_back(a[i]);
	}
	a.resize(vt);//cap nhat lai so luong phan tu cua a
}

void main()
{
	vector <int> a;
	cout << "\nnhap so phan tu mang a" << endl;
	Nhap(a);
	
	//a.resize(3, 1);//nhu calloc cac phan tu ban dau deu bang 0 neu them gia tri o sau thi mac dinh la gia tri cua toan bo mang, khi co ham nhap o truoc thi nhung gia tri k co moi dk gan = 1
	xuat(a);
	cout << "\nnhap so phan tu mang b" << endl;
	vector <int> b;
	Nhap(b);
	xuat(b);
	cout << "\n ket qua la: \n";

	//kiem tra push vs pop_back
	/*b.push_back(0);
	b.pop_back();
	cout << "so luong phan tu cua mang la: " << b.size() << "\n";
	xuat(b);*/

	//ham noi chuoi
	//cat(a, b);
	//xuat(a);

	//b.clear();//xoa mang b
	//cut(a, b, 2);//mang a: 12345 => 12
	//xuat(b);
	//cout << "\n";
	//xuat(a);

	/*cout << "nhap vao 1 mang , an Ctrl X then enter de dung" << endl;
	nhapmang(a);
	cout << "so phan tu cua mang la: " << endl;
	xuatmang(a);
	cout << endl;*/

	//vector<int> myvector;
	//int sum = 0;
	//myvector.push_back(100);
	//myvector.push_back(200);
	//myvector.push_back(300);

	//while (!myvector.empty())
	//{
	//	sum += myvector.back();
	//	myvector.pop_back();
	//}

	///*for (int i = 0; i < myvector.size(); i++)
	//{
	//	sum += myvector[i];
	//}*/
	//cout << "The elements of myvector add up to " << sum << '\n';


	




}