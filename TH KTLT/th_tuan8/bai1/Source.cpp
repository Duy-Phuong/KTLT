﻿#include <stdio.h>

//bai 1
struct node
{
	int data;
	struct node* pnext;
};

typedef struct node NODE;


struct list
{
	NODE* phead;
	NODE* ptail;
};

typedef struct list LIST;


NODE* Getnode(int x)
{
	NODE* p = new NODE;
	p->data = x;
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

NODE* AddHead(LIST& l, int x)
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

NODE* AddTail(LIST& l, int x)
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
		printf("%d\t", p->data);
	}
}

int removeHead(LIST &l)
{
	NODE* p;
	int x;
	if (l.phead != NULL)
	{
		p = l.phead;
		x = p->data;
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

int RemoveAfter(LIST& l, NODE* q)
{
	// Chuẩn bị sẵn con trỏ đến nút sẽ được xóa
	int x;
	NODE* r = NULL;

	// Nếu nút đã cho khác NULL
	if (q != NULL)
	{
		// và Nếu nút này không phải nút cuối cùng
		if (q != l.ptail)
		{
			// thì ghi nhận lại địa chỉ nút sau nút đã cho (sẽ bị xóa)
			r = q->pnext;
			x = r->data;
			// và nhập nhật lại liên kết
			q->pnext = r->pnext;

			// Nếu pHead bằng NULL nghĩa là DSLK rỗng thì cập nhật lại pTail
			if (l.phead == NULL)
			{
				l.ptail = NULL;
			}
		}
	}

	// Trả về địa chỉ c ủa nút bị xóa nếu có (nếu không có trả về NULL)
	return x;
}

// 21. Hàm xóa một nút cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị xóa (nếu có)
int RemoveTail(LIST& l)
{
	// Chuẩn bị sẵn con trỏ đến nút sẽ được xóa
	int x;
	NODE* p = NULL;
	// Nếu DSLK không rỗng nghĩa là có nút cuối để xóa
	if (l.phead != NULL)
	{
		// Nếu chỉ có một nút
		if (l.phead == l.ptail)
		{
			// thì gọi hàm xóa nút đầu DSLK
			x = removeHead(l);//l.phead = l.ptail = NULL
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
NODE* Getnodepointer(LIST l, int x)
{
	for (NODE* p = l.phead; p != NULL; p = p->pnext)
	{
		if (p->data == x)
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
NODE* AddAfter(LIST& l, NODE* q, int x)
{
	NODE* p = Getnode(x);
	if (p != NULL)
	{
		AddAfter(l, q, p);
		
	}
	return p;
}

NODE* ThemSau(LIST& l, int x, int y)// x la gia tri can nam trong mang y la gt them
{
	NODE* p = Getnodepointer(l, x);
	NODE* q = AddAfter(l, p, y);
	return q;
}

//xoa 1 pt sau pt co gia tri x
int Xoasau(LIST& l, int x)
{
	int y;
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
void main()
{
	LIST l;

	// Khởi tạo dslk
	InitList(l);

	int n;
	printf("nhap n(n=10): ");// n = 10
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		AddTail(l, i);
		
	}
	print(l);

	printf("\nxoa nut dau:\n");

	int x2 = removeHead(l);
	printf("gia tri nut sau khi xoa la: %d\n", x2);
	print(l);

	printf("\nxoa nut cuoi:\n");

	int x3 = RemoveTail(l);
	printf("gia tri nut sau khi xoa la: %d\n", x3);
	print(l);

	printf("\ntim phan co gia tri x\n");
	int x;
	printf("nhap x nam trong mang: ");
	scanf("%d", &x);

	NODE* p = Getnodepointer(l, x);
	printf("\nphan tu duoc tim thay trong mang la: %d\n", p->data);

	printf("\nthem phan tu 0 sau phan tu co gia tri x = 5\n");
	ThemSau(l, 5, 0);

	print(l);

	printf("\nxoa phan tu 0 sau phan tu co gia tri x = 5\n");
	Xoasau(l, 5);

	print(l);
	
	DeleteAll(l);
	//print(l);
}