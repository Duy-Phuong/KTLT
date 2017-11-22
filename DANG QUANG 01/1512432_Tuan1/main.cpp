/*Sinh viên: Nguyễn Đăng Quang
MSSV: 1512432
Lớp 15CTT2.2*/


#include "Library.h"

int main(){
	//khai báo ma trận
	int a[MAX][MAX];
	int d, c;
	BuildMatrix(a, d, c);
	OutputMatrix(a, d, c);
	/* Bài tập phần tìm các phần tử cực đại của ma trận */
	int *b;
	int k = DemPhanTuCucDaiTrongMang(b, a, d, c);
	printf("So phan tu cuc dai trong mang la: %d\n\n", k);
	printf("la cac phan tu: \n\n");
	for (int i = 0; i < k; i++){
		printf("%d\t", b[i]);
	}
	free(b);
	/* Bài tập phần xét các phần tử có phải là phần từ hoàng hậu hay không*/
	int *aHH = NULL;
	int HH = DuyetPTHoangHauMatrix(aHH, a, d, c);
	printf("\n\n- So phan tu hoang hau trong mang la: %d\n\n", HH);
	printf("La cac phan tu: \n");
	for (int i = 0; i < HH; i++){
		printf("%d\t", aHH[i]);
	}
	printf("\n");
	free(aHH);
	_getch();
	/*Bài tập sắp xếp các dòng của ma trận theo thứ tự tăng dần của PT lớn nhất trên dòng*/
	printf("Ma tran sau khi xap xep lai dong theo thu tu tang ");
	printf("dan cua phan tu lon nhat tren dong la : \n");
	SapXepLaiDong(a, d, c);
	OutputMatrix(a, d, c);
	/*Phần bài tập tính tổng của dãy các phân số */
	PhanSo *p;
	int np;
	TaoDayPhanSo(p, np);
	XuatDayPhanSo(p, np);
	PhanSo kp = TinhTongDayPhanSo(p, np);
	printf("\n\nTong day phan so sau khi duoc cong la: %d/%d\n", kp.Tu, kp.Mau);
	int UCLN = TimUCLN(kp.Tu, kp.Mau);
	printf("Tong sau khi toi gian la: %d/%d\n", kp.Tu / UCLN, kp.Mau / UCLN);
	free(p);
	/*chương trình tìm sinh viên có điểm TB cao nhất mà điểm toán k dưới 5*/
	SinhVien *SV;
	int nSV;
	NhapThongTinhSinhVien(SV, nSV);
	float *DTB = (float*)calloc(nSV,sizeof(float));
	TinhDiemTrungBinh(SV, nSV, DTB);
	int SVGioiNhat = TimSVCoDiemCaoNhat(SV, nSV, DTB);
	if (SVGioiNhat == -1){
		printf("khong co sinh vien nao co diem toan khong duoi 5");
	}
	else{
		printf("Sinh vien co diem trung binh lon nhat va diem toan khong duoi 5 la: \n");
		puts(SV[SVGioiNhat].HoTen);
		printf("MSSV: ");
		puts(SV[SVGioiNhat].MSSV);
	}
	free(SV);
	free(DTB);
	return 0;
}