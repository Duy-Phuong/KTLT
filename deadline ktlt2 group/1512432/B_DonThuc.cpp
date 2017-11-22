#include "Library.h"
/*vì đề bài không nói gì thêm nên
em xin được tính toán trên đơn thức một biến, nghĩa là
chỉ có một biến x.*/

/*nhập hệ số và số bậc cho đơn thức*/
void NhapDonThuc(SDonThuc &p){
	cout << "Nhap so bac don thuc: ";
	cin >> p.n;
	cout << "Nhap he so cua don thuc: ";
	cin >> p.HeSo;

}
/*xuất đơn thức ra màn hình*/
void XuatDonThuc(SDonThuc p){
	if (p.n < 0){
		p.n = -p.n;
		cout << p.HeSo << "/x^" << p.n << endl;
	}
	else{ // >= 0
		if (p.n == 1){
			cout << p.HeSo << "*x" << endl;
		}
		else if (p.n == 0)
			cout << p.HeSo << endl;
		else
			cout << p.HeSo << "*x^" << p.n << endl;
	}

}
/*Tính tích 2 đơn thức*/
SDonThuc TichHaiDonThuc(SDonThuc x, SDonThuc y){
	SDonThuc k;
	k.HeSo = x.HeSo*y.HeSo;
	k.n = x.n + y.n;
	return k;
}
/*tính thương của 2  đơn thức*/
SDonThuc ChiaHaiDonThuc(SDonThuc x, SDonThuc y){
	SDonThuc k;
	k.HeSo = x.HeSo / y.HeSo;
	k.n = x.n - y.n;
	return k;
}
/*đạo hàm cấp 1 của đơn thức*/
SDonThuc DaoHamCapMot(SDonThuc p){
	SDonThuc k;
	k.HeSo = p.HeSo*p.n;
	k.n = p.n - 1;
	return k;
}
/*đạo hàm cấp k của đơn thức*/
SDonThuc DaoHamCapk(SDonThuc p, int k){

	if (k > p.n)
		return{ 0, 0 };
	else{ //k <= p.n
		while (k != 0){
			p = DaoHamCapMot(p);
			k--;
		}
		return p;
	}

}
/*tính giá trị của đơn thức tại x = x0*/
float TinhGiaTriDonThuc(SDonThuc p, float x){
	return p.HeSo*pow(x, p.n);
}