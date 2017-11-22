#include "Library.h"

int main(){
	/*yêu cầu người dùng nhập vào tên file chưa danh sách sinh viên chứa thông tin*/
	char *name_DSSV = new char[50];
	cout << "Nhap ten file chua danh sach sinh vien: ";
	gets(name_DSSV);
	int n = strlen(name_DSSV);
	char *name = new char[n + 1];
	/*đưa về chuỗi mới ngắn hơn để giải phóng bộ nhớ thừa*/
	strcpy(name, name_DSSV);
	/*xóa vùng nhớ cũ đã tạo*/
	delete[]name_DSSV;
	/*gọi hàm tạo bảng điểm tổng kết*/
	BangDiemTongKethtml(name, "DSSVTam.html");

	return 0;
}