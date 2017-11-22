#include "Library.h"

/*hàm nhập bậc và mảng hệ số cho đa thức*/
void NhapDaThuc(SDaThuc *&p){
	p = new SDaThuc; //cấp phát cho biến kiểu đa thức
	int i;
Nhap:
	cout << "nhap so bac cua da thuc: ";
	cin >> p->n;
	if (p->n < 1){
		cout << "so bac phai lon hon 0! Xin nhap lai!!";
		goto Nhap;
	}
	// cấp phát cho mảng hệ số bộ nhớ bằng số bậc đa thức
	p->HeSo = new float[p->n + 1]; 
	for (int i = 0; i <= p->n; i++){
		cout << "He so thu " << i << " la: ";
		cin >> p->HeSo[i];
	}
}
/*Xuất đa thức*/
void XuatDaThuc(SDaThuc *p){
	for (int i = 0; i < p->n; i++){
		if (p->HeSo[i] == 0)
			continue;
		if (i == 0)
			cout << p->HeSo[i] << " + ";
		else if (i == 1)
			cout << p->HeSo[i] << "*x + ";
		else if (i>1)
			cout << p->HeSo[i] << "*x^" << i << " + ";
	}
	cout << p->HeSo[p->n] << "*x^" << p->n << "." << endl << endl;


}
/*Hàm tính tổng 2 đa thức*/
SDaThuc *TongHaiDaThuc(SDaThuc *x, SDaThuc *y){
	//tạo một con trỏ kiểu đa thức để lưu biến mới
	SDaThuc *k = new SDaThuc; // cấp phát
	/*bậc của k bằng bậc của đa thức có số bậc lớn hơn*/
	if (x->n >= y->n)
		k->n = x->n;
	else //x->n < y->n
		k->n = y->n;
	k->HeSo = new float[k->n + 1]; // cấp phát cho mảng hệ số 
	for (int i = 0; i <= k->n; i++){
		if (i > x->n){ // khi i lớn hơn bậc của đa thức x
			for (int j = i; j <= k->n; j++)
				// gán hệ số của k từ i trở đi = hệ số đa thức y 
				k->HeSo[j] = y->HeSo[j];  
			break;
		}
		if (i > y->n){ // tương tự khi i lớn hơn bậc của đa thức y
			for (int j = i; j <= k->n; j++)
				k->HeSo[j] = x->HeSo[j];
			break;
		}
		k->HeSo[i] = x->HeSo[i] + y->HeSo[i];
	}
	return k; //trả về con trỏ tới biến k
}
SDaThuc *HieuHaiDaThuc(SDaThuc *x, SDaThuc *y){
	/*Làm tương tự như phép cộng hai đa thức nhưng thay dấu + bằng dấu -*/
	SDaThuc *k = new SDaThuc;

	if (x->n >= y->n)
		k->n = x->n;
	else //x->n < y->n
		k->n = y->n;
	k->HeSo = new float[k->n + 1];
	for (int i = 0; i <= k->n; i++){
		if (i > x->n){
			for (int j = i; j <= k->n; j++)
				k->HeSo[j] = -y->HeSo[j];
			break;
		}
		if (i > y->n){
			for (int j = i; j <= k->n; j++)
				k->HeSo[j] = x->HeSo[j];
			break;
		}
		k->HeSo[i] = x->HeSo[i] - y->HeSo[i];
	}
	return k;
}
SDaThuc *TichHaiDaThuc(SDaThuc *x, SDaThuc *y){
	SDaThuc *k = new SDaThuc; //khai báo và cấp phát con trỏ chứa đa thức mới 
	k->n = x->n + y->n; // bậc k bẳng tổng bậc của 2 đa thức đưa vào
	k->HeSo = new float[k->n + 1]; // cấp phát mảng các hệ số 

	for (int i = 0; i <= k->n; i++)
		k->HeSo[i] = 0; // gán các hệ số của mảng k bằng 0
	for (int n = 0; n <= k->n; n++){
		for (int i = 0; i <= x->n; i++){
			if (i > n)
				break;
			for (int j = 0; j <= y->n; j++){
				if (j > n || i + j > n)
					break;
				if (i + j == n) // theo quy tắc nhân đa thức bình thường
					k->HeSo[n] += x->HeSo[i] * y->HeSo[j];
			}
		}
	}
	return k;
}
SDaThuc *DaoHamBacMotDaThuc(SDaThuc *p){
	SDaThuc *k = new SDaThuc;
	k->n = p->n - 1;
	k->HeSo = new float[k->n + 1];

	for (int i = 0; i <= k->n; i++){
		k->HeSo[i] = p->HeSo[i + 1] * (i + 1);
	}
	return k;
}
SDaThuc *DaoHamCapKDaThuc(SDaThuc *p,int Cap){
	if (Cap > p->n)
		return NULL;
	SDaThuc *k = new SDaThuc;
	k->n = p->n - Cap;
	k = DaoHamBacMotDaThuc(p);
	Cap--;
	while (Cap>0) {
		k = DaoHamBacMotDaThuc(k);
		Cap--;
	}
	
	return k;
}
double TinhGiaTriDaThuc(SDaThuc *p, float x){
	double giatri = 0;
	for (int i = 0; i <= p->n; i++){
		giatri += p->HeSo[i]*pow(giatri,i);
	}
	return giatri;
}