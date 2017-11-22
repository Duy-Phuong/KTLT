// Danh sách liên kết (DSLK) đơn
//SinglyLinkedList.h

/*
typedef struct
{
	int x;
} Data;

typedef struct tagNode
{
	Data info;
	struct tagNode* pNext;
} Node;

typedef struct tagList
{
	Node* pHead;
	Node* pTail;
} List;

// 01. Hàm so sánh 2 biến kiểu cấu trúc cho trước
// Đầu vào: biến cấu trúc (info1) và biến cấu trúc (info2)
// Đầu ra:	0 (bằng nhau), -1 (info1 nhỏ hơn info2), 1 (info1 lớn hơn info2)
int CompareData(Data info1, Data info2);

// 02. Hàm khởi tạo DSLK (rỗng)
// Đầu vào:	tham chiếu đến DSLK cần khởi tạo (l)
// Đầu ra:	Không có
void InitList(List& l);

// 03. Hàm kiểm tra DSLK cho trước có phải là DSLK rỗng hay không?
// Đầu vào:	DSLK cần kiểm tra (l)
// Đầu ra:	DSLK rỗng hay không (true/false)
bool IsEmptyList(List l);

// 04. Hàm in DSLK cho trước
// Đầu vào: DSLK cần in (l) kèm theo chuỗi thông báo (str)
// Đầu ra:	Không có
void PrintList(List l, char* str);

// 05. Hàm tạo một nút mới với dữ liệu cho trước
// Đầu vào:	Dữ liệu của nút (info)
// Đầu ra:	Con trỏ đến nút đó (trả về NULL nếu không tạo được)
Node* CreateNode(Data info);

// 06. Hàm tìm nút đầu tiên trong DSLK cho trước có dữ liệu cho trước
// Đầu vào:	DSLK (l), dữ liệu của nút cần tìm (info)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, Data info);

// 07. Hàm tìm nút có chỉ số (bắt đầu từ 0) cho trước
// Đầu vào:	DSLK (l), chỉ số của nút cần lấy (index)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, int index);

// 08. Hàm xác định vị trí của một nút cho trước trong DSLK cho trước
// Đầu vào:	DSLK (l), con trỏ đến nút cần xác định vị trí (pNode)
// Đầu ra:	Thứ tự của nút cho trước (trả về -1 nếu nút này không có trong DSLK)
int GetNodeIndex(List l, Node* pNode);

// 09. Hàm xác định con trỏ đến nút đứng trước của một nút cho trước trong DSLK
// Đầu vào:	DSLK (l), con trỏ đến nút cho trước (pNode)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetPreviousNodePointer(List l, Node* pNode);

// 10. Hàm chèn một nút cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddHead(List& l, Node* pNewNode);

// 11. Hàm chèn một nút có dữ liệu cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddHead(List& l, Data info);

// 12. Hàm chèn một nút cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddTail(List& l, Node* pNewNode);

// 13. Hàm chèn một nút có dữ liệu cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddTail(List& l, Data info);

// 14. Hàm chèn một nút cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAfter(List& l, Node* q, Node* pNewNode);

// 15. Hàm chèn một nút có dữ liệu cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddAfter(List& l, Node* q, Data info);

// 16. Hàm chèn một nút cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddBefore(List& l, Node* q, Node* pNewNode);

// 17. Hàm chèn một nút có dữ liệu cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddBefore(List& l, Node* q, Data info);

// 18. Hàm chèn một nút cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAscendingList(List& l, Node* pNewNode);

// 19. Hàm chèn một nút có dữ liệu cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddAscendingList(List& l, Data info);

// 20. Hàm xóa một nút đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị xóa (nếu có)
Node* RemoveHead(List& l);

// 21. Hàm xóa một nút cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị xóa (nếu có)
Node* RemoveTail(List& l);

// 22. Hàm xóa một nút đứng sau một nút cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q)
// Đầu ra:	Con trỏ đến nút bị xóa (nếu có)
Node* RemoveAfter(List& l, Node* q);

// 23. Hàm xóa một nút có dữ liệu cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần xóa (info)
// Đầu ra:	Con trỏ đến nút bị xóa (nếu có)
Node* RemoveNode(List& l, Data info);

// 24. Hàm hủy toàn bộ DSLK cho trước
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Không có
void DeleteAll(List& l);

//SinglyLinked.cpp

// Lưu ý:
// 1. Để SV dễ theo dõi nên các hàm được viết chi tiết
// và không sử dụng mẹo lập trình (cách viết ngắn)
// 2. Có nhiều cách để viết các hàm này,
// mã nguồn dưới đây là một trong số đó
// và chỉ mang tính chất tham khảo
// 3. Đối với các hàm xóa cần lưu ý xóa là gỡ bỏ nút khỏi DSLK
// người gọi hàm sẽ nhận được địa chỉ nút bị gỡ bỏ này
// và có thể tùy ý quyết định hủy (delete) nó hay không
#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

// 01. Hàm so sánh 2 biến kiểu cấu trúc cho trước
// Đầu vào: biến cấu trúc (info1) và biến cấu trúc (info2)
// Đầu ra:	0 (bằng nhau), -1 (info1 nhỏ hơn info2), 1 (info1 lớn hơn info2)
int CompareData(Data info1, Data info2)
{
	// Không thể so sánh trực tiếp các cấu trúc
	// mà phải so sánh thành phần dữ liệu của các cấu trúc đó
	if (info1.x < info2.x)
	{
		return -1;	// info1 nhỏ hơn info2
	}
	else
	{
		if (info1.x > info2.x)
		{
			return 1;	// info1 lớn hơn info2
		}
		else
		{
			return 0;	// info1 bằng info2
		}
	}
}

// 02. Hàm khởi tạo DSLK (rỗng)
// Đầu vào:	tham chiếu đến DSLK cần khởi tạo (l)
// Đầu ra:	Không có
void InitList(List& l)
{
	// Khởi tạo cho DSLK rỗng nghĩa là pHead và pTail đều bằng NULL
	l.pHead = NULL;
	l.pTail = NULL;
}

// 03. Hàm kiểm tra DSLK cho trước có phải là DSLK rỗng hay không?
// Đầu vào:	DSLK cần kiểm tra (l)
// Đầu ra:	DSLK rỗng hay không (true/false)
bool IsEmptyList(List l)
{
	// Nếu pHead bằng NULL thì DSLK rỗng
	if (l.pHead == NULL)
	{
		return true;
	}
	else // Ngược lại DSLK không rỗng
	{
		return false;
	}
}

// 04. Hàm in DSLK cho trước
// Đầu vào: DSLK cần in (l) kèm theo chuỗi thông báo (str)
// Đầu ra:	Không có
void PrintList(List l, char* str)
{
	// Xuất phát từ đầu DSLK
	Node *p = l.pHead;
	cout << str;

	// Trong khi chưa kết thúc DSLK (nút đang xét khác NULL)
	while (p != NULL)
	{
		// thì xuất thông tin nút đó ra
		cout << p->info.x << " ";
		// và đi tới nút kế tiếp
		p = p->pNext;
	}

	cout << endl;
}

// 05. Hàm tạo một nút mới với dữ liệu cho trước
// Đầu vào:	Dữ liệu của nút (info)
// Đầu ra:	Con trỏ đến nút đó (trả về NULL nếu không tạo được)
Node* CreateNode(Data info)
{
	// Tạo một nút mới
	Node* pNewNode = new Node;

	// Nếu tạo được nút mới (khác NULL)
	if (pNewNode != NULL)
	{
		// thì gán thông tin cho nút đó
		// và không cho nút đó trỏ đến đâu cả (nút kế bằng NULL)
		pNewNode->info = info;
		pNewNode->pNext = NULL;
	}

	// Trả về con trỏ đến nút tạo được
	// Nếu không tạo được thì con trỏ bằng NULL (đúng yêu cầu đề bài)
	return pNewNode;
}

// 06. Hàm tìm nút đầu tiên trong DSLK cho trước có dữ liệu cho trước
// Đầu vào:	DSLK (l), dữ liệu của nút cần tìm (info)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, Data info)
{
	// Xuất phát từ đầu DSLK
	Node* p = l.pHead;

	// Trong khi chưa kết thúc DSLK (nút đang xét khác NULL)
	// và dữ liệu của nút đang xét khác dữ liệu cho trước
	while (p != NULL && CompareData(p->info, info) != 0)
	{
		// thì đi tới nút kế tiếp
		p = p->pNext;
	}

	// Trả về con trỏ đến nút tìm được
	// Nếu không tìm được thì nút đó sẽ là NULL do kết thúc DSLK
	return p;
}

// 07. Hàm tìm nút có chỉ số (bắt đầu từ 0) cho trước
// Đầu vào:	DSLK (l), chỉ số của nút cần lấy (index)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, int index)
{
	// Chỉ số đầu tiên bằng 0 (đầu DSLK)
	int curIndex = 0;

	// Xuất phát từ đầu DSLK
	Node *p = l.pHead;

	// Trong khi chưa kết thúc DSLK (nút hiện tại khác NULL)
	// và chỉ số hiện tại vẫn chưa bằng chỉ số cần
	while (p != NULL && curIndex < index)
	{
		// thì đi tới nút kế tiếp
		// và tăng chỉ số hiện tại lên 1 đơn vị
		p = p->pNext;
		curIndex++;
	}

	// Trả về con trỏ đến nút tìm được
	// Nếu không tìm được thì nút đó sẽ là NULL do kết thúc DSLK
	return p;
}

// 08. Hàm xác định vị trí của một nút cho trước trong DSLK cho trước
// Đầu vào:	DSLK (l), con trỏ đến nút cần xác định vị trí (pNode)
// Đầu ra:	Thứ tự của nút cho trước (trả về -1 nếu nút này không có trong DSLK)
int GetNodeIndex(List l, Node* pNode)
{
	// Xuất phát từ đầu DSLK
	Node* p = l.pHead;

	// Vị trí hiện tại bằng 0
	int pos = 0;

	// Nếu DSLK rỗng thì dừng lại và trả về -1
	// do không thấy nút này trong DSLK
	if (IsEmptyList(l))
	{
		return -1;
	}

	// Trong khi chưa kết thúc DSLK (nút đang xét khác NULL)
	// và nút đang xét vẫn khác nút cho trước
	while (p != NULL && p != pNode)
	{
		// thì tăng vị trí hiện tại lên
		// và đi tới nút kế tiếp
		pos++;
		p = p->pNext;
	}

	// Khi kết thúc, nếu con trỏ đến nút hiện tại bằng con trỏ đến nút cho trước
	// thì trả về vị trí hiện tại đó
	// ngược lại trả về -1 (không tìm thấy)
	if (p == pNode)
	{
		return pos;
	}
	else
	{
		return -1;
	}
}

// 09. Hàm xác định con trỏ đến nút đứng trước của một nút cho trước trong DSLK
// Đầu vào:	DSLK (l), con trỏ đến nút cho trước (pNode)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetPreviousNodePointer(List l, Node* pNode)
{
	// Nút trước đó đầu tiên là nút đầu DSLK
	Node* pPreviousNode = l.pHead;

	// Trong khi chưa kết thúc DSLK (nút đang xét khác NULL)
	// và nút sau nút đó không phải nút cho trước
	while (pPreviousNode != NULL && pPreviousNode->pNext != pNode)
	{
		// thì đi đến nút kế tiếp
		pPreviousNode = pPreviousNode->pNext;
	}

	// Trả về con trỏ đến nút trước nút cho trước nếu tìm được
	// Nếu không tìm được thì nút đó vẫn là NULL (đúng yêu cầu đề bài)
	return pPreviousNode;
}

// 10. Hàm chèn một nút cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddHead(List& l, Node* pNewNode)
{
	// Nếu DSLK rỗng
	if (IsEmptyList(l))
	{
		// thì đây là nút đầu tiên của DSLK
		// nghĩa là pHead và pTail đề trỏ đến nút đầu tiên này
		l.pHead = pNewNode;
		l.pTail = l.pHead;
	}
	else // Ngược lại (DSLK không rỗng)
	{
		// thì nút mới trỏ tới nút đầu DSLK
		// rồi pHead trỏ tới nút mới
		pNewNode->pNext = l.pHead;
		l.pHead = pNewNode;
	}
}

// 11. Hàm chèn một nút có dữ liệu cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddHead(List& l, Data info)
{
	// Tạo nút mới với dữ liệu cho trước
	Node* pNewNode = CreateNode(info);

	// Nếu tạo được
	if (pNewNode != NULL)
	{
		// thì gọi hàm đã viết để thêm nút đó vào đầu DSLK
		AddHead(l, pNewNode);
	}

	// Trả về nút mới tạo được
	// Nếu không thêm được thì do không tạo được nút mới
	// thì trả về NULL (đúng yêu cầu đề bài)
	return pNewNode;
}

// 12. Hàm chèn một nút cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddTail(List& l, Node* pNewNode)
{
	// Nếu DSLK rỗng
	if (IsEmptyList(l))
	{
		// thì đây là nút đầu tiên của DSLK
		// nghĩa là pHead và pTail đề trỏ đến nút đầu tiên này
		l.pHead = pNewNode;
		l.pTail = l.pHead;
	}
	// Ngược lại (DSLK không rỗng)
	else
	{
		// thì nút cuối DSLK trỏ đến nút mới
		// rồi pTail trỏ tới nút mới
		l.pTail->pNext = pNewNode;
		l.pTail = pNewNode;
	}
}

// 13. Hàm chèn một nút có dữ liệu cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddTail(List& l, Data info)
{
	// Tạo nút mới với dữ liệu cho trước
	Node* pNewNode = CreateNode(info);

	// Nếu tạo được
	if (pNewNode != NULL)
	{
		// thì gọi hàm đã viết để thêm nút đó vào cuối DSLK
		AddTail(l, pNewNode);
	}

	// Trả về nút mới tạo được
	// Nếu không thêm được thì do không tạo được nút mới
	// thì trả về NULL (đúng yêu cầu đề bài)
	return pNewNode;
}

// 14. Hàm chèn một nút cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAfter(List& l, Node* q, Node* pNewNode)
{
	// Nếu nút cho trước q khác NULL
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
	// Tạo nút mới với dữ liệu cho trước
	Node* pNewNode = CreateNode(info);

	// Nếu tạo được
	if (pNewNode != NULL)
	{
		// thì gọi hàm đã viết đến để thêm nút đó vào sau nút q cho trước
		AddAfter(l, q, pNewNode);
	}

	// Trả về nút mới tạo được
	// Nếu không thêm được thì do không tạo được nút mới
	// thì trả về NULL (đúng yêu cầu đề bài)
	return pNewNode;
}

// 16. Hàm chèn một nút cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddBefore(List& l, Node* q, Node* pNewNode)
{
	// Nếu nút q cho trước khác NULL thì mới làm
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
	// Tạo nút mới với dữ liệu cho trước 
	Node* pNewNode = CreateNode(info);

	// Nếu tạo được
	if (pNewNode != NULL)
	{
		// thì gọi hàm đã viết đến để thêm nút đó vào trước nút q cho trước
		AddBefore(l, q, pNewNode);
	}

	// Trả về nút mới tạo được
	// Nếu không thêm được thì do không tạo được nút mới
	// thì trả về NULL (đúng yêu cầu đề bài)
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

//Hàm main

#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

void main()
{
	List l;

	// Khởi tạo dslk
	InitList(l);

	// Chèn nút có giá trị 8 vào đầu dslk
	Data info;
	info.x = 8;
	AddHead(l, info);
	PrintList(l, "Chen nut 8 vao dau:\t\t");

	// Chèn nút có giá trị 9 vào đầu dslk
	info.x = 9;
	Node *q = AddHead(l, info);
	PrintList(l, "Chen nut 9 vao dau:\t\t");

	// Chèn nút có giá trị 10 vào đầu dslk
	info.x = 10;
	AddHead(l, info);
	PrintList(l, "Chen nut 10 vao dau:\t\t");

	// Chèn nút có giá trị 999 vào cuối dslk
	info.x = 999;
	AddTail(l, info);
	PrintList(l, "Chen nut 999 vao cuoi:\t\t");

	// Chèn nút có giá trị 789 vào cuối dslk
	info.x = 789;
	AddTail(l, info);
	PrintList(l, "Chen nut 789 vao cuoi:\t\t");

	// Chèn nút có giá trị 111 vào sau nút q (nút có giá trị 9 ở trên)
	info.x = 111;
	AddAfter(l, q, info);
	PrintList(l, "Chen nut 111 vao sau nut 9:\t");

	// Chèn nút có giá trị 123 vào trước nút q (nút có giá trị 9 ở trên)
	info.x = 123;
	AddBefore(l, q, info);
	PrintList(l, "Chen nut 123 vao truoc nut 9:\t");

	// Xóa nút đầu tiên
	Node* p;
	p = RemoveHead(l);
	PrintList(l, "Xoa nut dau tien:\t\t");
	if (p != NULL)
	{
		cout << "=> Gia tri cua nut bi xoa:\t" << p->info.x << endl;
		delete p;
	}
	else
	{
		cout << "=> Xoa khong thanh cong!" << endl;
	}

	// Xóa nút cuối cùng
	p = RemoveTail(l);
	PrintList(l, "Xoa nut cuoi cung:\t\t");
	if (p != NULL)
	{
		cout << "=> Gia tri cua nut bi xoa:\t" << p->info.x << endl;
		delete p;
	}
	else
	{
		cout << "=> Xoa khong thanh cong!" << endl;
	}

	// Xóa nút sau nút q (nút có giá trị 9 ở trên)
	p = RemoveAfter(l, q);
	PrintList(l, "Xoa nut sau nut 9:\t\t");
	if (p != NULL)
	{
		cout << "=> Gia tri cua nut bi xoa:\t" << p->info.x << endl;
		delete p;
	}
	else
	{
		cout << "=> Xoa khong thanh cong!" << endl;
	}

	// Xóa nút có giá trị cho trước
	cout << "Nhap gia tri nut can xoa: ";
	cin >> info.x;
	p = RemoveNode(l, info);
	if (p != NULL)
	{
		PrintList(l, "=> Xoa thanh cong:\t\t");
		delete p;
	}
	else
		PrintList(l, "=> Xoa khong thanh cong:\t");

	// Hủy tất cả
	DeleteAll(l);
	PrintList(l, "Xoa toan bo danh sach lien ket!\t\t");

	// Chèn nút 6 vào mảng tăng dần
	info.x = 6;
	AddAscendingList(l, info);
	PrintList(l, "Chen nut 6 (sao cho tang dan):\t");

	// Chèn nút 8 vào mảng tăng dần
	info.x = 8;
	AddAscendingList(l, info);
	PrintList(l, "Chen nut 8 (sao cho tang dan):\t");

	// Chèn nút 7 vào mảng tăng dần
	info.x = 7;
	AddAscendingList(l, info);
	PrintList(l, "Chen nut 7 (sao cho tang dan):\t");

	// Chèn nút 5 vào mảng tăng dần
	info.x = 5;
	AddAscendingList(l, info);
	PrintList(l, "Chen nut 5 (sao cho tang dan):\t");

	// Chèn nút 9 vào mảng tăng dần
	info.x = 9;
	AddAscendingList(l, info);
	PrintList(l, "Chen nut 9 (sao cho tang dan):\t");
}
*/