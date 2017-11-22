#include "Library.h"

/*hàm làm tròn điểm trung bình theo phần thập phân >< 0.5*/
void LamTronDTB(float &DTB){
	/*nếu DTB có phần thập phân lớn hơn 0.5 thì làm tròn lên*/
	if (DTB - floor(DTB) > 0.5)
		DTB = ceil(DTB);
	/*nếu DTB có phần thập phân nhỏ hơn 0.5 thì làm tròn lên*/
	else if (DTB - floor(DTB) < 0.5)
		DTB = floor(DTB);
	else
		return;
}
/*hàm xuất thông tin của từng sinh viên đọc được trong file ra màn hình*/
void ShowStu(SinhVien sv){
	cout << sv.MSSV << "-" << sv.HoTen << "(" << sv.NTNS << ","
		<< sv.GioiTinh << ")\t" << sv.Toan << "\t" << sv.Ly << "\t" << sv.Hoa << endl;
}
/*hàm đưa họ tên thành 2 thành phần họ và tên lót và tên*/
void AddHoTenToHo_Ten(SinhVien &sv){
	int n = strlen(sv.HoTen); //lấy độ dài phần họ tên của sinh viên
	for (int i = n - 1; i >= 0; i--){ //xóa khoảng trắng cuối dòng
		if (isalpha(sv.HoTen[i]) != 0){
			sv.HoTen[i + 1] = '\0';
			break;
		}
	}
	n = strlen(sv.HoTen); // lấy lại độ dài
	int dem = 0;
	for (int i = n - 1; i >= 0; i--){
		if (isspace(sv.HoTen[i])){
			strncpy(sv.Ho, sv.HoTen, i); // copy phần họ và tên lót vào phần riêng
			sv.Ho[i] = '\0';
			strncpy(sv.Ten, sv.HoTen + i, n - i); //copy phần tên ra riêng
			sv.Ten[n - i] = '\0';
			return;
		}
	}
}
/*hàm tính điểm trung bình của một sinh viên*/
void DTB(SinhVien &sv){
	sv.DTB = (sv.Toan + sv.Ly + sv.Hoa) / 3; //DTB bằng tổng toán lý hóa chia 3
	LamTronDTB(sv.DTB); // làm tròn số
}
/*hàm hoán vị thứ tự 2 sinh viên*/
void HoanViSinhVien(SinhVien &sv1, SinhVien &sv2){
	SinhVien tam = sv1;
	sv1 = sv2;
	sv2 = tam;
}
/*hàm sắp xếp danh sacshc sinh viên theo thứ tự alphabe*/
void SapXepDSSV(SinhVien *sv, int SoSV){
	for (int i = 0; i < SoSV; i++){
		for (int j = i + 1; j < SoSV; j++){
			if (strcmp(sv[i].Ten, sv[j].Ten) > 0)
				HoanViSinhVien(sv[i], sv[j]);
		}
	}
}
/*hàm tạo bảng điểm chi tiết cho từng sinh viên, hàm truyền vào MSSV.html và form chung
bảng điểm từng sinh viên và thông tin sinh viên*/
void TaoFielhtmlChiTiet(char *name_MSSV_html, char *name_form, SinhVien sv){
	FILE *fform = fopen(name_form, "r"); // mở hàm form chung để đọc thông tin vào MSSV.html
	FILE *fMSSV = fopen(name_MSSV_html, "w"); //mở file MSSV.html để ghi thông tin đọc được ở form chung

	if (fform != NULL){
		rewind(fform);
		char ch;
		while (!feof(fform)) {
			ch = fgetc(fform);
			if (ch == EOF)
				break;
			fputc(ch, fMSSV);
		}
	}
	fcloseall();

	FILE *fp3 = fopen(name_MSSV_html, "a");
	fprintf(fp3, "%s (%s)</h2></font>\n\t</p>\n", sv.HoTen, sv.MSSV);
	fprintf(fp3, "\t<table align = center border = 3 bordercolor = blue");
	fprintf(fp3, "cellpadding = 1 cellspacing = 3 width = 80%%>\n\t\t<tr>\n");
	fprintf(fp3, "\t\t\t<th align = center> <b> Toan </b> </th>\n");
	fprintf(fp3, "\t\t\t<th align = center> <b> Ly </b> </th>\n");
	fprintf(fp3, "\t\t\t<th align = center> <b> Hoa </b> </th>\n");
	fprintf(fp3, "\t\t\t<th align = center> <b> Diem Trung Binh </b> </th>\n\t\t</tr>\n");
	fprintf(fp3, "\t\t<tr>\n\t\t\t<td align = center> %f </td>", sv.Toan);
	fprintf(fp3, "\n\t\t\t<td align = center> %f </td>", sv.Ly);
	fprintf(fp3, "\n\t\t\t<td align = center> %f </td>", sv.Hoa);
	fprintf(fp3, "\n\t\t\t<td align = center> %f </td>\n", sv.DTB);
	fprintf(fp3, "\t\t</tr>\n\t</table>\n</body>\n</html>\n");
	fcloseall();
}
/*hàm lấy MSSV từng người để tạo thành bảng điểm chi tiết kiểu MSSV.html*/
void TaoFileChiTiet(SinhVien sv){
	int n = strlen(sv.MSSV);
	char *name_table = new char[n + 7];
	/*xóa khoảng trắng hoặc kí tự lạ trước MSSV*/
	if (sv.MSSV[0] == '\n') {
		strcpy(name_table, sv.MSSV + 1);
		n--;
	}
	else
		strcpy(name_table, sv.MSSV);
	/*tạo file dạng MSSV.html*/
	strcpy(name_table + n, ".html");
	name_table[n + 6] = '\0';
	/*gọi hàm tạo bảng điểm chi tiết theo tên trên*/
	TaoFielhtmlChiTiet(name_table, "formbangdiemchitiet.html", sv);
	delete[]name_table;
}
/*hàm thêm điểm và thông tin từng người vào file BangDiem.html
truyền vào là tên file chứa thông tin DSSV và tên file html, ( vd:BangDiem.html) */
void BangDiemTongKethtml(char *name_txt, char *name_html){

	FILE *ftxt = fopen(name_txt, "rt");
	/*nhập số học sinh muốn thêm vào bảng từ file DSSV.xt*/
	int n;
	cout << "nhap so hoc sinh trong danh sach: ";
	cin >> n;
	/*tạo mảng kiểu struct SinhVien để lưu thông tin từng sinh viên*/
	SinhVien *sv = new SinhVien[n];
	/*mở file DSSV để đọc dữ liệu vào mảng struct SinhVien vừa tạo*/
	if (ftxt != NULL){
		rewind(ftxt);
		int i = 0;
		while (!feof(ftxt)){
			fscanf(ftxt, "%[^-]-%[^(](%[^,],%[^)])\t%f%f%f%", &sv[i].MSSV, &sv[i].HoTen, &sv[i].NTNS, &sv[i].GioiTinh,
				&sv[i].Toan, &sv[i].Ly, &sv[i].Hoa);
			i++;
		}
		n = i; //thay đổi n bằng với số lượng sinh viên khi đọc đến hết file  DSSV
	}
	fclose(ftxt);
	/*hàm tính điểm trung bình cho từng sv*/
	for (int j = 0; j < n; j++)
		DTB(sv[j]);
	/*hàm tách riêng họ, tên*/
	for (int j = 0; j < n; j++){
		AddHoTenToHo_Ten(sv[j]);
	}
	/*sắp xếp theo thứ tự tăng dần alphabe*/
	SapXepDSSV(sv, n);
	/*tạo bảng điểm chi tiết cho từng sinh viên*/
	for (int j = 0; j < n; j++)
		TaoFileChiTiet(sv[j]);
	/*mở file BangDiem.html để ghi thông tin*/
	FILE *fhtml = fopen(name_html, "w");
	int k = 0;
	while (k < n){
		fprintf(fhtml, "<tr>\n");
		fprintf(fhtml, "\t<td align = center> %s </td>\n", sv[k].MSSV);
		fprintf(fhtml, "\t<td align = center>%s </td>\n", sv[k].Ho);
		fprintf(fhtml, "\t<td align = center>%s </td>\n", sv[k].Ten);
		fprintf(fhtml, "\t<td align = center>%s </td>\n", sv[k].NTNS);
		fprintf(fhtml, "\t<td align = center>%s </td>\n", sv[k].GioiTinh);
		fprintf(fhtml, "\t<td align = center>%lf </td>\n", sv[k].DTB);
		fprintf(fhtml, "\t<td align = center><a href = \"%s.html\"> xem diem</a> </td>\n", sv[k].MSSV);
		fprintf(fhtml, "</tr>\n");
		k++;
	}
	fprintf(fhtml, "\t</table>\n</body>\n</html>");
	fcloseall();
	/*giải phóng vùng nhớ đã tạo mảng SinhVien*/
	delete[]sv;
}