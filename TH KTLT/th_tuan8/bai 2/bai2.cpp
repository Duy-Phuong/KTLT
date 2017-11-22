#include <stdio.h>

struct Diem
{
	int x, y;
};


struct node
{
	Diem d;
	struct node* pnext;
};
typedef struct node NODE;

struct list
{
	NODE* phead;
	NODE* ptail;
};

typedef struct list LIST;

NODE* Getnode(Diem x)
{
	NODE* p = new NODE;
	p->d.x = x.x;
	p->d.y = x.y;
	p->pnext = NULL;
	return p;
}
//bai 2
void addFirst(LIST &l, NODE* p)
{
	if (l.phead == NULL)
	{
		l.phead = l.ptail = p;
	}
	else
	{
		p->pnext = l.phead;
		l.phead = p;
	}
}

NODE* AddHead(LIST& l, Diem x)
{
	NODE* p = Getnode(x);
	if (p == NULL)
		return NULL;

	else
	{
		addFirst(l, p);
		return p;
	}
	return NULL;
}

void addLast(LIST &l, NODE* p)
{
	if (l.phead == NULL)
	{
		l.phead = l.ptail = p;
	}
	else
	{
		l.ptail->pnext = p;
		l.ptail = p;
	}
}

NODE* AddTail(LIST& l, Diem x)
{
	NODE* p = Getnode(x);
	if (p == NULL)
		return NULL;

	else
	{
		addLast(l, p);
		return p;
	}
	return NULL;
}

void print(LIST l)
{
	for (NODE* p = l.phead; p != NULL; p = p->pnext)
	{
		printf("(%d, %d)\t", p->d.x, p->d.y);
	}
}

Diem removeHead(LIST &l)
{
	NODE* p;
	Diem x;
	if (l.phead != NULL)
	{
		p = l.phead;
		x = p->d;
		l.phead = l.phead->pnext;
		delete p;
		if (l.phead == NULL)
		{
			l.ptail = NULL;
		}
	}
	return x;
}

//bai 3

NODE* GetPreviousNodePointer(LIST l, NODE* pNode)
{
	for (NODE* ptruoc = l.phead; ptruoc != NULL; ptruoc = ptruoc->pnext)
	{
		if (ptruoc->pnext == pNode)
			return ptruoc;
	}
	return NULL;
}

Diem RemoveAfter(LIST& l, NODE* q)
{
	// Chuẩn bị sẵn con trỏ đến nút sẽ được xóa
	Diem x;
	NODE* r = NULL;

	// Nếu nút đã cho khác NULL
	if (q != NULL)
	{
		// và Nếu nút này không phải nút cuối cùng
		if (q != l.ptail)
		{
			// thì ghi nhận lại địa chỉ nút sau nút đã cho (sẽ bị xóa)
			r = q->pnext;
			x = r->d;
			// và nhập nhật lại liên kết
			q->pnext = r->pnext;

			// Nếu pHead bằng NULL nghĩa là DSLK rỗng thì cập nhật lại pTail
			if (l.phead == NULL)
			{
				l.ptail = NULL;
			}
		}
	}

	// Trả về địa chỉ của nút bị xóa nếu có (nếu không có trả về NULL)
	return x;
}

// 21. Hàm xóa một nút cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị xóa (nếu có)
Diem RemoveTail(LIST& l)
{
	// Chuẩn bị sẵn con trỏ đến nút sẽ được xóa
	Diem x;
	NODE* p = NULL;
	// Nếu DSLK không rỗng nghĩa là có nút cuối để xóa
	if (l.phead != NULL)
	{
		// Nếu chỉ có một nút
		if (l.phead == l.ptail)
		{
			// thì gọi hàm xóa nút đầu DSLK
			x = removeHead(l);
		}
		else // Ngược lại (có nhiều hơn 1 nút)
		{
			// thì tìm nút trước nút cuối
			NODE* q = GetPreviousNodePointer(l, l.ptail);
			// sau đó gọi hàm xóa nút sau nút tìm được ở trên
			x = RemoveAfter(l, q);
		}
	}

	// Trả về địa chỉ của nút bị xóa nếu có (nếu không có trả về NULL)
	return x;
}

//tim phan tu có gia tri x trong dslk tra ve node
NODE* Getnodepointer(LIST l, Diem x)
{
	for (NODE* p = l.phead; p != NULL; p = p->pnext)
	{
		if (p->d.x == x.x && p->d.y == x.y)
		{
			return p;
		}
	}
	return NULL;
}

//them phan tu ra sau phan tu có gia tri x
// 14. Hàm chèn một nút cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAfter(LIST& l, NODE* q, NODE* pNewNode)
{
	if (q != NULL)
	{
		// thì nút mới trỏ đến nút q đang trỏ
		// sau đó q trỏ đến nút mới
		pNewNode->pnext = q->pnext;
		q->pnext = pNewNode;

		// Lưu ý, sau khi thực hiện xong, nếu nút mới là nút cuối DSLK (nút kế tiếp là NULL)
		if (pNewNode->pnext == NULL)
		{
			// thì cập nhật lại pTail
			l.ptail = pNewNode;
		}
	}
}

// 15. Hàm chèn một nút có dữ liệu cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
NODE* AddAfter(LIST& l, NODE* q, Diem x)
{
	NODE* p = Getnode(x);
	if (p != NULL)
	{
		AddAfter(l, q, p);
		return p;
	}
	return NULL;
}

NODE* ThemSau(LIST& l, Diem x, Diem y)// x la gia tri can nam trong mang y la gt them
{
	NODE* p = Getnodepointer(l, x);
	NODE* q = AddAfter(l, p, y);
	return q;
}

//xoa 1 pt sau pt co gia tri x
Diem Xoasau(LIST& l, Diem x)
{
	Diem y;
	NODE* p = Getnodepointer(l, x);
	y = RemoveAfter(l, p);
	return y;
}

void InitList(list& l)
{
	// Khởi tạo cho DSLK rỗng nghĩa là pHead và pTail đều bằng NULL
	l.phead = NULL;
	l.ptail = NULL;
}

void DeleteAll(LIST& l)
{
	// Cách 1: Gọi hàm xóa nút đầu tiên nhiều lần đến khi DSLK rỗng
	//Node* p;
	//while (!IsEmptyList(l))
	//{
	//	p = RemoveHead(l);
	//	delete p;
	//}

	// Cách 2: Chủ động duyệt và hủy từng nút...
	// Sử dụng 1 con trỏ giữ địa chỉ nút sẽ xóa
	NODE* p;

	// Trong khi DSLK chưa rỗng
	while (l.phead != NULL)
	{
		// Giữ địa chỉ nút đầu
		p = l.phead;

		// Cập nhật lại pHead
		l.phead = p->pnext;

		// Hủy nút đã giữ
		delete p;
	}

	// Cập nhật lại pTail bằng NULL khi DSLK rỗng
	l.ptail = NULL;
}

void nhapdiem(Diem& x)
{
	printf("nhap x: ");
	scanf("%d", &x.x);
	printf("nhap y: ");
	scanf("%d", &x.y);
}
void main()
{
	LIST l;

	// Khởi tạo dslk
	InitList(l);
	Diem a[100];
	int n;
	printf("nhap n(n=10): ");// n = 10
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("nhap diem thu %d\n", i);
		nhapdiem(a[i]);
		AddTail(l, a[i]);

	}
	print(l);

	printf("\nxoa nut dau:\n");
	
	Diem x2 = removeHead(l);
	printf("gia tri nut sau khi xoa la: %d\n", x2);
	print(l);

	printf("\nxoa nut cuoi:\n");

	Diem x3 = RemoveTail(l);
	printf("gia tri nut sau khi xoa la: %d\n", x3);
	print(l);
	
	printf("\ntim phan co gia tri x\n");
	Diem x;
	printf("nhap toa do diem x nam trong mang: ");
	nhapdiem(x);

	NODE* p = Getnodepointer(l, x);
	printf("\nphan tu duoc tim thay trong mang co toa do la: (%d, %d)\n", p->d.x, p->d.y);
	
	printf("\nthem diem sau diem cho truoc\n");
	Diem x5, x6;
	printf("nhap toa do diem x nam trong mang: \n");
	nhapdiem(x5);
	printf("nhap toa do diem them sau diem x trong mang:\n");
	nhapdiem(x6);
	ThemSau(l, x5, x6);

	print(l);

	printf("\nxoa diem moi them sau phan tu co gia tri cho truoc\n");
	Xoasau(l, x5);

	print(l);

	DeleteAll(l);
	
}

