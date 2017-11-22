#include "thuvien.h"



//bai 1
//-------1--------

void DemKiTu(char* s)
{
	int dem = 0;
	int so = 0;
	int kitukhac = 0;
	int khoangcach = 0;
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 'A' && s[i] < 'Z' || s[i] >= 'a' && s[i] < 'z')
		{
			dem++;
		}
		if (s[i] >= '0' && s[i] < '9')
		{
			so++;
		}
		if (s[i] >= '!' && s[i] < '/' || s[i] >= ':' && s[i] < '@' || s[i] >= '{' && s[i] < '~')
		{
			kitukhac++;
		}
		if (s[i] == ' ')
		{
			khoangcach++;
		}
	}
	printf("so luong ki tu so la: %d\n", so);
	printf("so luong ki tu chu cai latin la: %d\n", dem);
	printf("so luong khoang cach la: %d\n", khoangcach);
	printf("so luong ki tu khac la: %d\n", kitukhac);
}

//------2-------

int DemTu(char* s)
{
	int dem = 0;
	int n = strlen(s);
	if (s[0] != 0)
	{
		dem = 1;
	}
	for (int i = 0; i < n - 2; i++)//tru truong hop dau cách va '\0'
	{
		if (s[i] == ' ' && s[i + 1] != ' ')
		{
			dem++;
		}
	}
	return dem;
}


//cat cac tu trong chuoi tren tung hang
void cut(char* s)
{
	int dem = 0;
	char* b = strdup(s);
	b = strtok(b, " .,-!?:;");
	while (b != NULL)
	{
		dem++;
		puts(b);
		b = strtok(NULL, " .,-!?:;");
	}
	printf("so tu trong chuoi la: %d\n", dem);
}

//tim tu co do dai max va min
void TimTuMaxMin(char* s)
{
	char* b = strdup(s);
	char* max = (char*)malloc(100 * sizeof(char));
	char* min = (char*)malloc(100 * sizeof(char));
	b = strtok(b, " ");
	strcpy(max, b);
	strcpy(min, b);
	int max1;
	int min1;
	max1 = min1 = strlen(b);
	while (b != NULL)
	{
		if (strlen(b) > max1)
		{
			max1 = strlen(b);
			//strcpy(max, b);
		}
		if (strlen(b) < min1)
		{
			min1 = strlen(b);
			//strcpy(min, b);
		}
		b = strtok(NULL, " ");
	}
	//xuat cac tu co chieu dai max va min
	char* c = strdup(s);
	b = strtok(c, " ");
	while (c != NULL)
	{
		if (strlen(c) == max1)
		{
			printf("\ntu dai nhat trong chuoi la:\n");
			puts(c);
		}
		if (strlen(c) == min1)
		{
			printf("\ntu ngan nhat trong chuoi la:\n");
			puts(c);
		}
		c = strtok(NULL, " ");
	}


	/*printf("\ntu dai nhat trong chuoi la:\n");
	puts(max);
	printf("\ntu ngan nhat trong chuoi la:\n");
	puts(min);*/
	free(max);
	free(min);
}

//----------3--------
//bai 3:dem bao nhieu tu dai hon 1 so nguyen n trong chuoi cho truoc
int DemSoTu(char* a, int b)
{
	int dem = 0;
	int n = strlen(a);
	int k = 1;
	for (int i = 0; i < n; i++)
	{

		if (a[i] != ' ' && a[i + 1] != ' ')
		{
			k++;
			if (a[i + 1] == '\0')
			{
				k--;
			}
		}
		if (a[i] != ' ' && a[i + 1] == ' ' || a[i] != ' ' && a[i + 1] == '\0')
		{
			if (k > b)
			{
				dem++;
			}
			k = 1;
		}
	}
	return dem;
}

//-------4--------
//bai4 viet hoa ki tu dau
void VietHoaKiTuDau(char* s)
{
	char* a = strdup(s);
	int n = strlen(a);
	if (a[0] != ' ')
	{
		if (a[0] >= 'a' && a[0] <= 'z')
		{
			a[0] -= 32;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == ' ' && a[i + 1] != ' ')
		{
			if (a[i + 1] >= 'a' && a[i + 1] <= 'z')
			{
				a[i + 1] -= 32;
			}
		}
		if (a[i] != ' ' && (a[i + 1] >= 'A' && a[i + 1] <= 'Z'))
		{
			a[i + 1] += 32;
		}
	}
	printf("chuoi sau khi viet hoa cac ki tu dau la:\n");
	puts(a);
}

//bai 2: viet chuong trinh nhap vao so nguyen va xuat so do ra o dang chuoi, nhung co dau phay ngan o hang ngan, hang tram, hang trieufor
void ChenKiTu(char* s, int vt, char c)
{
	int n = strlen(s);
	for (int i = n - 1; i >= vt; i--)
	{
		s[i + 1] = s[i];
	}
	s[vt] = c;
	s[n + 1] = '\0';
}

void ChuyenSoSangChuoi()
{
	int n;
	printf("nhap so n: ");
	scanf("%d", &n);
	char* a = (char*)malloc(256*sizeof(char));
	a = itoa(n, a, 10);
	int x = strlen(a);
	int dem = 0;
	for (int i = x - 1; i > 0; i--)//lon hon 0 vi k co dau phay o dau
	{
		dem++;
		if ( dem % 3 == 0 )//bo dem khac 0 vi dem ++ roi
		{
			ChenKiTu(a, i, ',');// chen o vi tri i-1 vi khi chen vao vi tri i nó chen o sau i
		}
	}
	puts(a);
	free(a);
}
 
//bai 3: 
void Xoa(char* a, int vt)
{
	int n = strlen(a);
	for (int i = vt; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	a[n - 1] = '\0';
}


void XoaKhoangTrangThua(char* a)
{
	int n = strlen(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == ' '  && a[i + 1] == ' ')
		{
			Xoa(a, i);
			i--;
			n--;
		}
	}
	if (a[0] == ' ')
	{
		Xoa(a, 0);
		n--;
	}
	if (a[n - 1] == ' ')
	{
		Xoa(a, n - 1);
		n--;
	}
}


void XoaKhoangCachTruocDau(char* a)
{
	int n = strlen(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == ' '  && a[i + 1] == '.' || a[i] == ' '  && a[i + 1] == ',' || a[i] == ' '  && a[i + 1] == ':' || a[i] == ' '  && a[i + 1] == ';' || a[i] == ' '  && a[i + 1] == '!' || a[i] == ' '  && a[i + 1] == '?' )
		{
			Xoa(a, i);
			i--;//cap nhat lai vi tri khi xoa xuoi
			n--;
		}
	}
}


void ChenKhoangCachSauDau(char* a)
{
	//chay nguoc
	int n = strlen(a);
	for (int i = n-1; i >= 0; i--)
	{
		if (a[i] == '.' || a[i] == ',' || a[i] == ':' || a[i] == ';' || a[i]  == '!' || a[i] == '?')
		{
			ChenKiTu(a, i, ' ');
		}
	}
}


void VietHoaKiTuDauSauDauCau(char* a)
{
	int n = strlen(a);
	if (a[0] != ' ')
	{
		if (a[0] >= 'a' && a[0] <= 'z')
		{
			a[0] -= 32;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '.' && a[i + 2] != ' ' || a[i] == '!' && a[i + 2] != ' ' || a[i] == '?' && a[i + 2] != ' ')
		{
			if (a[i + 2] >= 'a' && a[i + 2] <= 'z')
			{
				a[i + 2] -= 32;
			}
		}
		if (a[i] != ' ' && (a[i + 1] >= 'A' && a[i + 1] <= 'Z'))
		{
			a[i + 1] += 32;
		}
	}
}


void ChuanHoaDoanVan(char* s)
{
	printf("\nchuoi sau khi chuan hoa la:\n");
	char* a = strdup(s);
	XoaKhoangTrangThua(a);
	XoaKhoangCachTruocDau(a);
	ChenKhoangCachSauDau(a);
	XoaKhoangTrangThua(a);//sau khi chen no co the du ra tai vi chen sau dau neu co dau cach no cx k biet
	VietHoaKiTuDauSauDauCau(a);
	puts(a);
}


//cau c:
void DemTuTrongDoan(char* s)
{
	int dem = 0;
	char* b = strdup(s);
	printf("\ncac tu trong doan van la:\n");
	b = strtok(b, " .,-!?:;");
	while (b != NULL)
	{
		dem++;
		puts(b);
		b = strtok(NULL, " .,-!?:;");
	}
	printf("\nso tu trong chuoi la: %d\n", dem);
}

//cau d:
void DaoChuoi(char* s)
{
	char* b = strdup(s);
	printf("\ncac tu sau khi dao trong doan van la:\n");
	b = strtok(b, " .,-!?:;");
	while (b != NULL)
	{
		strrev(b);
		printf("%s\t", b);
		b = strtok(NULL, " .,-!?:;");
	}
}

void DaoTu(char* s, mang* d, int &nd)
{
	char* b = strdup(s);
	printf("\ncac tu sau khi dao trong doan van la:\n");
	b = strtok(b, " .,-!?:;");
	nd = 0;
	while (b != NULL)
	{
		strcpy(d[nd].a, b);
		puts(b);
		b = strtok(NULL, " .,-!?:;");
		nd++;
	}
}

void XuatTuNguocLai(mang* d, int nd)
{
	for (int i = nd-1; i >= 0; i--)
	{
		printf("%s\t", d[i].a);
	}
}


//bai4: nhap 2 chuoi so tinh tong va in ra
void Tong(char* a, char* b)
{
	printf("nhap chuoi so thu nhat: ");
	gets(a);
	printf("nhap chuoi so thu hai: ");
	gets(b);

	int i = atoi(a);
	int j = atoi(b);
	int s = i + j;
	printf("tong cua 2 so la: %d\n", s);
}

//bai 5:tim chuoi s2 trong s1
void TimKiem(char* a, char* b)
{
	int n = strlen(a);
	int m = strlen(b);
	int j = 0;
	int kt = 0;
	int vt = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[j])
		{
			while (j < m)
			{
				if (a[i] == b[j])
				{
					kt = 1;
				}
				else
				{
					kt = 0;
				}
				i++;
				j++;
			}

			if (kt == 1)
			{
				vt = i;
				break;
			}
		}
			
	}
	if (kt == 1)
	{
		printf("chuoi s2 nam trong chuoi s1!\n");
		printf("vi tri cua chuoi s2 trong s1 la: %d\n", vt-m);
	}
	if (kt == 0)
	{
		printf("chuoi s2 khong nam trong chuoi s1!\n");
	}
}

//bai 6: kiem tra bieu thuc gom dau "(" ")" co la bieu thuc hop le khong
bool KiemTraHopLe(char* s)
{
	int n = strlen(s);
	int dem = 0;
	int i = 0;
	int j;
	if (s[0] == ')')//neu dong ngoac o dau la sai
		return false;
	while (i < n)
	{
		if (s[i] == '(')
		{
			dem++;
		}
		if (s[i] == ')')
		{
			j = i;
			while (j < n)
			{
				if (s[j] == '(')//gap mo ngoac la dung
				{
					break;
				}
				if (s[j] == ')')
				{
					dem--;
				}
				j++;
			}
			if (dem != 0)
			{
				return false;
			}
			dem = 0;
			i = j;
			i--;//vi sau khi cho i=j i++ lan nua se sai do j++ roi nen giam lai
		}
		
		i++;
	}
	return true;
}

//bai 7: tim chuoi com max trong s1 s2 

/*char* chuoiChungMax(char *a, char *b, int &n, int &m);
char* chuoiChungMax(char *a, char *b, int &n, int &m)
{
	int vtc, vtd;
	if (n <= m)
	{
		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (ktStInSt(b, j + 1, a, i + 1, vtc, vtd))
				{
					for (int z = n - 1; z >= j + 1; z--)
					{
						xoaKiTu(a, n, z);
					}
					return a;
				}
			}
		}
	}
	else
	{
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				if (ktStInSt(a, i + 1, b, j + 1, vtc, vtd))
				{
					for (int z = m - 1; z >= j + 1; z--)
					{
						xoaKiTu(b, m, z);
					}
					return b;
				}
			}
		}
	}
}
void bai07();
void bai07()
{
	char *a, *b;
	int n, m;
	nhapChuoi(a, n);
	nhapChuoi(b, m);
	printf("Chuoi chung dai nhat cua 2 chuoi tren: %s\n", chuoiChungMax(a, b, n, m));
}

bool ktStInSt(char *a, int n, char *b, int m, int &vtc, int &vtd);
bool ktStInSt(char *a, int n, char *b, int m, int &vtc, int &vtd)
{
	int j = 0;
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[0])
		{
			vtd = i;
			break;
		}
	}
	for (int i = vtd; i < n; i++)
	{
		if (a[i] == b[j])
		{
			dem++;
			j++;
		}
	}
	vtc = vtd + j;
	if (dem == m)
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/



int Timmax(MANG b[100], int nb)
{
	int max = b[0].sotu;
	int vt = 0;
	for (int i = 1; i < nb; i++)
	{
		if (b[i].sotu > max)
		{
			max = b[i].sotu;
			vt = i;
		}
	}
	return vt;
}
void Timchuoicon(char* s1, char* s2, MANG b[100], int &nb)
{
	int n = strlen(s1);
	int m = strlen(s2);
	nb = 0;
	int dem = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			while (s1[i] == s2[j] && i < n && j < m)
			{
				dem++;
				i++;
				j++;
			}
			if (dem >= 2)
			{
				i = i - dem;
				b[nb].sotu = dem;
				b[nb].vitri = i;//vi tri trong s1
				nb++;
				dem = 0;
				j = j - dem;
			}
			if (dem == 1)
			{
				dem--;
				i--;
				j--;
			}
		}
	}
}

void Xuat(char* s1, MANG b[100], int nb)
{
	int n = strlen(s1);
	int z = Timmax(b, nb);
	for (int i = b[z].vitri; i < b[z].vitri + b[z].sotu; i++)
	{
		printf("%c", s1[i]);
	}

}