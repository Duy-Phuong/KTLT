#include "Library.h"

/*Khởi tạo Thông tin sinh viên*/
void NhapThongTinhSinhVien(SinhVien *&SV, int &nSV){
	printf("Nhap so sinh vien");
	scanf_s("%d", &nSV);
	if (nSV < 1){
		printf("So sinh vien khong hop le!!");
		return;
	}
	SV = (SinhVien*)calloc(nSV, sizeof(SinhVien));
	for (int i = 0; i < nSV; i++){
		printf("Ho Ten SV: ");
		fflush(stdin);
		gets_s(SV[i].HoTen);
		printf("MSSV: ");
		gets_s(SV[i].MSSV);
		printf("Diem Toan: ");
		scanf_s("%f", &SV[i].DiemToan);
		printf("Diem NMLT: ");
		scanf_s("%f", &SV[i].DiemNMLT);
		printf("Diem KTLT: ");
		scanf_s("%f", &SV[i].DiemKTLT);
	}
}
/*Tính điểm Tb của sinh viên*/
void TinhDiemTrungBinh(SinhVien *SV, int nSV, float *&DTB){
	for (int i = 0; i < nSV; i++) {
		DTB[i] = (SV[i].DiemNMLT + SV[i].DiemKTLT + SV[i].DiemToan) / 3;
	}
}
/* hàm tìm sinh viên có điểm TB cao nhất mà điểm toán không dưới 5*/
int TimSVCoDiemCaoNhat(SinhVien *SV, int nSV, float *DTB){

	int iMax = -1;  // cờ hiệu
	for (int i = 0; i < nSV; i++){
		if (SV[i].DiemToan >= 5){
			iMax = i; // nếu có SV có điểm toán trên hoặc bằng 5 thì lưu địa chỉ lại
			break; // thoát
		}
	}
	int x = iMax;
	if (iMax != -1){ // Nếu có SV có điểm toán trên hoặc bằng 5 thì tiếp tục tìm ĐTB lớn nhất
		for (int i = x; i < nSV; i++){
			if (DTB[i]>DTB[iMax] && SV[i].DiemToan >= 5) {
				iMax = i;//lưu lại địa chỉ SV giỏi nhất
			}
		}
	}
	return iMax;
}