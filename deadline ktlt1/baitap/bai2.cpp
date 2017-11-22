#include <stdio.h>
#include <stdlib.h>
// chương trình tìm vị trí sống sót cuối cùng của trò chơi hải tặc tự sát
int HaiTac(int &Nguoi, int &SoDan) 
{
	int vitri; // Vị trí súng đi tới
	int vitricuoicung; // Vị trí cuối cùng trong vòng ( == sô người tham gia)
	int SoDanConLai; // Số đạn còn sau mỗi lần tự sát

	printf("\nNhap so hai tac tham gia tro choi: ");
	scanf("%d", &Nguoi);
	if (Nguoi <= 1)
		return -1; // nếu số người nhỏ hơn 1 thì trò chơi vô nghĩa

	/* tạo mảng lưu giá trị sống chết của người chơi
	còn sống thì giá trị bằng "0", nếu đã chết sẽ gán giá trị bằng "1" ..*/
	int *a = (int*)calloc(Nguoi, sizeof(int));// calloc sẽ tạo mảng cho các giá trị bằng 0

	printf("\nNhap so dan nap vao: ");
	scanf("%d", &SoDan);
	vitri = 0, SoDanConLai = 0, vitricuoicung = Nguoi - 1;

	while (Nguoi > 1)
	{
		if (SoDanConLai == 0)
		{
			// nếu số đạn còn lại đã hết thì người này sẽ nạp đạn và chuyền cho người kế tiếp
			SoDanConLai = SoDan;
			vitri++;
		}
		if (a[vitri] == 0)
		{
			//nếu người này còn sống sẽ tự sát và người kế bên sẽ lấy súng
			a[vitri] = 1;
			vitri++;
			if (vitri > vitricuoicung) //nếu vị trí lớn hơn số người thì vị trí sẽ bằng bắt đầu
				vitri = 0;
			SoDanConLai--; // số đạn giảm đi 1
			Nguoi--; // số người chơi giảm đi 1
			if (Nguoi == 1){
				// Nếu só người chơi còn lại duy nhất thì trả về vị trí an toàn
				for (int i = 0; i <= vitricuoicung; i++)
				if (a[i] == 0)
					return i + 1; // vì ban đầu i = 0 nên trả về cộng thêm 1
			}
			//Nếu người tiếp theo đã chết thì người kế nữa sẽ lấy súng
			while (a[vitri] == 1) {
				vitri++;
				if (vitri > vitricuoicung) //nếu vị trí lớn hơn số người thì vị trí sẽ bằng bắt đầu
					vitri = 0;
			}
		}
		vitri++;//nguoi ke cam sung tu nguoi da chet chuyen tiep
		if (vitri > vitricuoicung) //nếu vị trí lớn hơn số người thì vị trí sẽ bằng bắt đầu
			vitri = 0;
		while (a[vitri] == 1) {
			vitri++;
			if (vitri > vitricuoicung) //nếu vị trí lớn hơn số người thì vị trí sẽ bằng bắt đầu
				vitri = 0;
		}
	}
}
void main()
{
	int b, c;
	int x = HaiTac(b, c);
	printf("\n vi tri song sot cuoi cung la: %d\n", x);


}
