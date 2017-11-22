#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

// 01. Hàm so sánh 2 biến kiểu cấu trúc cho trước
// Đầu vào: biến cấu trúc (info1) và biến cấu trúc (info2)
// Đầu ra:	0 (bằng nhau), -1 (info1 nhỏ hơn info2), 1 (info1 lớn hơn info2)
int CompareData(Data info1, Data info2)
{
	if (info1.x < info2.x)
		return -1;
	else // >=
	{
		if (info1.x > info2.x)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

// 02. Hàm khởi tạo DSLK (rỗng)
// Đầu vào:	tham chiếu đến DSLK cần khởi tạo (l)
// Đầu ra:	Không có
void InitList(List& l)
{
	l.pHead = l.pTail = NULL;
}

// 03. Hàm kiểm tra DSLK cho trước có phải là DSLK rỗng hay không?
// Đầu vào:	DSLK cần kiểm tra (l)
// Đầu ra:	DSLK rỗng hay không (true/false)
bool IsEmptyList(List l)
{
	return (l.pHead == NULL);
}

// 04. Hàm in DSLK cho trước
// Đầu vào: DSLK cần in (l) kèm theo chuỗi thông báo (str)
// Đầu ra:	Không có
void PrintList(List l, char* str)
{
	printf("%s", str);
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		printf("%4d", p->info.x);
	}
}

// 05. Hàm tạo một nút mới với dữ liệu cho trước
// Đầu vào:	Dữ liệu của nút (info)
// Đầu ra:	Con trỏ đến nút đó (trả về NULL nếu không tạo được)
Node* CreateNode(Data info)
{
	Node* p = new  Node;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		p->info = info;
		p->pNext = NULL;
	}
	return p;
}

// 06. Hàm tìm nút đầu tiên trong DSLK cho trước có dữ liệu cho trước
// Đầu vào:	DSLK (l), dữ liệu của nút cần tìm (info)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, Data info)
{
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (CompareData(p->info, info) == 0)
		{
			return p;
		}
	}
	return NULL;
}

// 07. Hàm tìm nút có chỉ số (bắt đầu từ 0) cho trước
// Đầu vào:	DSLK (l), chỉ số của nút cần lấy (index)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, int index)
{
	int chiso = 0;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (chiso == index)
		{
			return p;
		}
		chiso++;
	}
	return NULL;
}

// 08. Hàm xác định vị trí của một nút cho trước trong DSLK cho trước
// Đầu vào:	DSLK (l), con trỏ đến nút cần xác định vị trí (pNode)
// Đầu ra:	Thứ tự của nút cho trước (trả về -1 nếu nút này không có trong DSLK)
int GetNodeIndex(List l, Node* pNode)
{
	int vthientai = 0;
	if(IsEmptyList(l))
	{
		return -1;
	}
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->info.x == pNode->info.x )////// p == pNode
		{
			return vthientai;
		}
		vthientai++;
	}
	return -1;
}

// 09. Hàm xác định con trỏ đến nút đứng trước của một nút cho trước trong DSLK
// Đầu vào:	DSLK (l), con trỏ đến nút cho trước (pNode)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetPreviousNodePointer(List l, Node* pNode)
{
	for (Node* ptruoc = l.pHead; ptruoc != NULL; ptruoc = ptruoc->pNext)
	{
		if (ptruoc->pNext == pNode)
			return ptruoc;
	}
	return NULL;
}

// 10. Hàm chèn một nút cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddHead(List& l, Node* pNewNode)
{
	if (l.pHead == NULL) // Tức là danh sách bị rỗng
	{
		l.pHead = l.pTail = pNewNode;
	}
	else
	{
		pNewNode->pNext = l.pHead; // p quăng dây để tham gia vào danh sách
		l.pHead = pNewNode; // p chính thức đã đứng dầu danh sách
	}
}

// 11. Hàm chèn một nút có dữ liệu cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddHead(List& l, Data info)
{
	Node* p = CreateNode(info);
	if (p == NULL)
		return NULL;
	
	else
	{
		AddHead(l, p);
		return p;
	}
	return NULL;
}

// 12. Hàm chèn một nút cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddTail(List& l, Node* pNewNode)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = pNewNode;
	}
	else
	{
		l.pTail->pNext = pNewNode;
		l.pTail = pNewNode;
	}
}

// 13. Hàm chèn một nút có dữ liệu cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddTail(List& l, Data info)
{
	Node* p = CreateNode(info);
	if (p == NULL)
		return NULL;

	else
	{
		AddTail(l, p);
		return p;
	}
	return NULL;
}

// 14. Hàm chèn một nút cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAfter(List& l, Node* q, Node* pNewNode)
{
	if (q != NULL)
	{
		// thì nút mới trỏ đến nút q đang trỏ
		// sau đó q trỏ đến nút mới
		pNewNode->pNext = q->pNext;
		q->pNext = pNewNode;

		// Lưu ý, sau khi thực hiện xong, nếu nút mới là nút cuối DSLK (nút kế tiếp là NULL)
		if (pNewNode->pNext == NULL)
		{
			// thì cập nhật lại pTail
			l.pTail = pNewNode;
		}
	}
}

// 15. Hàm chèn một nút có dữ liệu cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddAfter(List& l, Node* q, Data info)
{
	Node* p = CreateNode(info);
	if (p != NULL)
	{
		AddAfter(l, q, p);
	
	}
	return p;
}

// 16. Hàm chèn một nút cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddBefore(List& l, Node* q, Node* pNewNode)
{
	if (q != NULL)
	{
		// Nếu q cho trước là nút đầu tiên
		if (l.pHead == q)
		{
			// thì gọi hàm thêm vào đầu DSLK
			AddHead(l, pNewNode);
		}
		// Ngược lại (q cho trước không phải là nút đầu tiên)
		else
		{
			// thì tìm nút p đứng trước nút q
			Node* p = GetPreviousNodePointer(l, q);
			// và gọi hàm thêm vào sau nút p cho trước
			AddAfter(l, p, pNewNode);
		}
	}
}

// 17. Hàm chèn một nút có dữ liệu cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddBefore(List& l, Node* q, Data info)
{
	Node* pNewNode = CreateNode(info);
	if (pNewNode != NULL)
	{
		AddBefore(l, q, pNewNode);
		
	}
	return pNewNode;
}

// 18. Hàm chèn một nút cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAscendingList(List& l, Node* pNewNode)
{
	// Xuất phát từ nút đầu tiên (gọi là p)
	// sử dụng thêm nút q (ban đầu bằng NULL) để lưu trữ nút trước đó
	// do cần phải có nút trước đó để có thể chèn vào sau
	Node* p = l.pHead, *q = NULL;

	// Trong khi chưa kết thúc DSLK (nút đang xét khác NULL)
	// và dữ liệu của nút p hiện tại vẫn nhỏ hơn nút cần chèn
	while (p != NULL && CompareData(p->info, pNewNode->info) < 0)
	{
		// thì dùng nút q để lưu lại nút p hiện tại
		q = p;
		// và cho p đi tới nút tiếp theo
		p = p->pNext;
	}

	// Nếu q khác NULL nghĩa là tìm được vị trí trong DSLK để chèn
	if (q != NULL)
	{
		// thì gọi hàm chèn nút mới vào sau nút q
		AddAfter(l, q, pNewNode);
	}
	// Ngược lại (vẫn là NULL như ban đầu)
	else
	{
		// thì gọi hàm chèn nút mới vào đầu DSLK
		AddHead(l, pNewNode);
	}
}

// 19. Hàm chèn một nút có dữ liệu cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddAscendingList(List& l, Data info)
{
	// Tạo nút mới với dữ liệu cho trước
	Node* pNewNode = CreateNode(info);

	// Nếu tạo được
	if (pNewNode != NULL)
	{
		// thì gọi hàm đã viết đến để thêm nút đó vào DSLK sao cho DSLK vẫn tăng dần
		AddAscendingList(l, pNewNode);
	}

	// Trả về nút mới tạo được
	// Nếu không thêm được thì do không tạo được nút mới
	// thì trả về NULL (đúng yêu cầu đề bài)
	return pNewNode;
}

// 20. Hàm xóa một nút đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị xóa (nếu có)
Node* RemoveHead(List& l)
{
	// Chuẩn bị sẵn con trỏ đến nút sẽ được xóa
	Node* r = NULL;

	// Nếu DSLK không rỗng nghĩa là có nút đầu để xóa
	if (!IsEmptyList(l))
	{
		// thì ghi nhận lại địa chỉ nút đầu
		r = l.pHead;

		// và cập nhật lại pHead
		l.pHead = r->pNext;

		// Nếu pHead bằng NULL nghĩa là DSLK rỗng thì cập nhật lại pTail
		if (l.pHead == NULL)
		{
			l.pTail = NULL;
		}
	}

	// Trả về địa chỉ của nút bị xóa nếu có (nếu không có trả về NULL)
	return r;
}

// 21. Hàm xóa một nút cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị xóa (nếu có)
Node* RemoveTail(List& l)
{
	// Chuẩn bị sẵn con trỏ đến nút sẽ được xóa
	Node* r = NULL;

	// Nếu DSLK không rỗng nghĩa là có nút cuối để xóa
	if (!IsEmptyList(l))
	{
		// Nếu chỉ có một nút
		if (l.pHead == l.pTail)
		{
			// thì gọi hàm xóa nút đầu DSLK
			r = RemoveHead(l);
		}
		else // Ngược lại (có nhiều hơn 1 nút)
		{
			// thì tìm nút trước nút cuối
			Node* q = GetPreviousNodePointer(l, l.pTail);
			// sau đó gọi hàm xóa nút sau nút tìm được ở trên
			r = RemoveAfter(l, q);
		}
	}

	// Trả về địa chỉ của nút bị xóa nếu có (nếu không có trả về NULL)
	return r;
}

// 22. Hàm xóa một nút đứng sau một nút cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q)
// Đầu ra:	Con trỏ đến nút bị xóa (nếu có)
Node* RemoveAfter(List& l, Node* q)
{
	// Chuẩn bị sẵn con trỏ đến nút sẽ được xóa
	Node* r = NULL;

	// Nếu nút đã cho khác NULL
	if (q != NULL)
	{
		// và Nếu nút này không phải nút cuối cùng
		if (q != l.pTail)
		{
			// thì ghi nhận lại địa chỉ nút sau nút đã cho (sẽ bị xóa)
			r = q->pNext;

			// và nhập nhật lại liên kết
			q->pNext = r->pNext;

			// Nếu pHead bằng NULL nghĩa là DSLK rỗng thì cập nhật lại pTail
			if (l.pHead == NULL)
			{
				l.pTail = NULL;
			}
		}
	}

	// Trả về địa chỉ của nút bị xóa nếu có (nếu không có trả về NULL)
	return r;
}

// 23. Hàm xóa một nút có dữ liệu cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần xóa (info)
// Đầu ra:	Con trỏ đến nút bị xóa (nếu có)
Node* RemoveNode(List& l, Data info)
{
	// Chuẩn bị sẵn con trỏ đến nút sẽ được xóa
	Node* r = NULL;

	// Gọi hàm tìm nút có thông tin info cho trước
	Node* p = GetNodePointer(l, info);

	// Nếu tìm được (nghĩa là khác NULL)
	if (p != NULL)
	{
		// Nếu đây là nút đầu DSLK
		if (p == l.pHead)
		{
			// thì gọi hàm xóa nút đầu này
			r = RemoveHead(l);
		}
		// Ngược lại (không phải nút đầu DSLK)
		else
		{
			// thì gọi hàm tìm nút trước nút này
			Node* q = GetPreviousNodePointer(l, p);

			// và Nếu tìm được (nghĩa là khác NULL)
			if (q != NULL)
			{
				// thì gọi hàm xóa nút sau nút này
				r = RemoveAfter(l, q);
			}
		}
	}

	// Trả về địa chỉ của nút bị xóa nếu có (nếu không có trả về NULL)
	return r;
}

// 24. Hàm hủy toàn bộ DSLK cho trước
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Không có
void DeleteAll(List& l)
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
	Node* p;

	// Trong khi DSLK chưa rỗng
	while (!IsEmptyList(l))
	{
		// Giữ địa chỉ nút đầu
		p = l.pHead;

		// Cập nhật lại pHead
		l.pHead = p->pNext;

		// Hủy nút đã giữ
		delete p;
	}

	// Cập nhật lại pTail bằng NULL khi DSLK rỗng
	l.pTail = NULL;
}