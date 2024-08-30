#include<iostream>
#include<time.h>
using namespace std;

template <typename T>
struct DNode
{
	T data;
	DNode<T>* next;
	DNode<T>* prev;
};
//DNode->T*;
//typedef DNode<int T>* PDNode;
template <typename T>
struct Linkedlist
{
	DNode<T>* head;
	DNode<T>* tail;
};
template <typename T>
void Initation(Linkedlist<T>& H)
{
	H.head = H.tail = NULL;
}
template <typename T>
bool IsEmpty(Linkedlist<T> H)
{
	return (H.head == NULL);
}
template <typename T>
DNode<T>* creatNode(T k)
{
	DNode<T>* Q = new DNode<T>;
	if (Q == NULL) return NULL;
	Q->data = k;
	Q->next = NULL;
	Q->prev = NULL;
	return Q;
}
template <typename T>
void InsertBegin(Linkedlist<T>& H, T k)
{
	DNode<T>* Q = creatNode(k);
	if (IsEmpty(H)) {
		H.head = H.tail = Q;
	}
	else {
		Q->next = H.head;
		H.head->prev = Q;
		H.head = Q;
	}
}
template <typename T>
void InsertTail(Linkedlist<T>& H, T k)
{
	DNode<T>* Q = creatNode(k);
	if (IsEmpty(H))
	{
		H.head = H.tail = Q;
	}
	else
	{
		H.tail->next = Q;
		Q->prev = H.tail;
		H.tail = Q;
	}
}
template <typename T>
void InsertBefore(Linkedlist<T>& H, DNode<T>* P, int k)
{
	DNode<T>* Q = creatNode(k);
	if (IsEmpty(H))
	{
		H.head = H.tail = Q;
	}
	else
	{
		Q->next = P;
		Q->prev = P->prev;
		P->prev->next = Q;
		P->prev = Q;
	}
}
template <typename T>
void InsertAfter(Linkedlist<T>& H, DNode<T>* P, int k)
{
	DNode<T>* Q = creatNode(k);
	if (IsEmpty(H)) {
		H.head = H.tail = Q;
	}
	else {
		if (P == NULL) return;
		Q->next = P->next;
		Q->prev = P;
		P->next->prev = Q;
		P->next = Q;
	}
}
template <typename T>
void delHead(Linkedlist<T>& H) {
	if (!IsEmpty(H)) {
		DNode<T>* P = H.head;
		H.head = H.head->next;
		H.head->prev = NULL;
		delete P;
	}
}
template <typename T>
void delTail(Linkedlist<T>& H) {
	if (!IsEmpty(H)) {
		DNode<T>* P = H.tail;
		H.tail = H.tail->prev;
		H.tail->next = NULL;
		P->prev = NULL;
		delete P;
	}
}
template <typename T>
int demsoPT(Linkedlist<T> H) {
	int dem = 0;
	DNode<T>* P = H.head;
	while (P != NULL) {
		dem++;
		P = P->next;
	}
	return dem;
}
template <typename T>
void delAtK(Linkedlist<T>& H, T k) // xoa o vi tri K
{
	if (k <= 1) delHead(H);
	else if (k >= demsoPT(H)) delTail(H);
	else
	{
		int dem = 0;
		if(!IsEmpty(H))
		{
			DNode<T>* P = H.head;
			DNode<T>* Q = new DNode<T>;
			while (P != NULL)
			{
				dem++;
				Q = P;
				if (dem == k) break;
				else P = P->next;
			}
			DNode<T>* R = H.head;
			while (R->next != Q) R = R->next;
			R->next = Q->next;
			(Q->next)->prev = R;
			delete Q;
		}
	}
}
template <typename T>
DNode<T>* SearchNode(Linkedlist<T> H, T K) {
	DNode<T>* P = H.head;
	while (P != 0) {
		if (P->data == K)
			return P;
		else P = P->next;
	}
	return NULL;
}
template <typename T>
void show1(Linkedlist<T> H)
{
	if (H.head == NULL) cout << "danh sach rong";
	else
	{
		DNode<T>* A = new DNode<T>;
		A = H.head;
		cout << "danh sach lien ket: ";
		while (A != NULL)
		{
			cout << A->data << " ";
			A = A->next;
		}
		cout << endl;
	}
}
template <typename T>
void show(Linkedlist<T> H)
{
	if (H.head == NULL) cout << "danh sach rong";
	else
	{
		DNode<T>* A = new DNode<T>;
		A = H.head;
		cout << "danh sach lien ket: ";
		while (A != NULL)
		{
			if (A->prev != NULL) cout << A->prev->data << " ";
			cout << A->data << " ";
			if (A->next != NULL) cout << A->next->data << " ";
			A = A->next;
			cout << endl;
		}
		cout << endl;
	}
}
template <typename T>
void swap(Linkedlist<T> H, DNode<T>* a, DNode<T>* b)
{
	T t = a->data;
	a->data = b->data;
	b->data = t;
}
template <typename T>
void sortInsertion(Linkedlist<T>& H)
{
	DNode<T>* Q = new DNode<T>;
	DNode<T>* P = new DNode<T>;
	int t;
	Q = H.head;
	for (Q = Q->next; Q != NULL; Q = Q->next)
	{
		t = Q->data;
		for (P = Q; P != H.head && P->prev->data > t; P = P->prev)
			P->data = P->prev->data;
		P->data = t;
	}
}
template <typename T>
void sortSelection(Linkedlist<T>& H)
{
	DNode<T>* Q = new DNode<T>;
	DNode<T>* P = new DNode<T>;
	DNode<T>* mi = new DNode<T>;
	Q = H.head;
	for (Q; Q != H.tail->prev; Q = Q->next)
	{
		mi = Q;
		P = Q->next;
		for (P; P != NULL; P = P->next)
		{
			if (P->data < mi->data) mi = P;
		}
		if (mi != Q)
			swap(H, Q, mi);
	}
}
template <typename T>
void bubbleSort(Linkedlist<T>& H)
{
	DNode<T>* Q = new DNode<T>;
	DNode<T>* P = new DNode<T>;
	bool sorted = false;
	Q = H.head;
	while (!sorted && Q != H.tail)
	{
		sorted = true;
		for (P = H.tail->prev; P != Q->prev; P = P->prev)
			if (P->data > P->next->data)
			{
				swap(H, P, P->next);
				sorted = false;
			}
		Q = Q->next;
	}
}
//void heapSort

class myString
{
	int length;
	char* data;
public:
	myString(int _length = 5, char _data = '\0');
	~myString();
	myString(const myString& a);
	myString& operator =(const myString& c);
	friend istream& operator >>(istream& is, myString& A);
	friend ostream& operator <<(ostream& os, const myString& A);
	int operator!=(const myString& A);
	int operator==(const myString& A);
	int operator>(const myString& A);
	int operator>=(const myString& A);
	int operator<(const myString& A);
	int operator<=(const myString& A);
	char operator[](int index);
	void set_data_i(int i, char c);
	myString operator +(myString& s)
	{
		myString x;
		x.length = length + s.length;
		delete[] x.data;
		x.data = new char[x.length];
		for (int i = 0; i < length; i++)
		{
			x.data[i] = data[i];
		}
		for (int i = length; i < x.length; i++)
		{
			x.data[i] = s.data[i - length];
		}
		return x;
	}
};
myString::myString(int _length, char _data)
{
	length = _length;
	data = new char[length];
	for (int i = 0; i < length; i++)
	{
		data[i] = _data;
	}
	data[length - 1] = NULL;
}
myString::myString(const myString& A)
{
	length = A.length;
	data = new char[length];
	for (int i = 0; i < length; ++i)
		data[i] = A.data[i];
}
myString& myString::operator=(const myString& A)
{
	if (length != A.length) {
		delete[] data;
		length = A.length;
		data = new char[length];
	}
	for (int i = 0; i < length; ++i)
		data[i] = A.data[i];
	return *this;
}
istream& operator>>(istream& is, myString& A)
{
	delete[] A.data;
	cout << "\nnhap so phan tu cho xau ki tu: ";
	is >> A.length;
	A.data = new char[A.length];
	cout << "nhap cac phan tu cho xau: ";
	for (int i = 0; i < A.length; i++)
	{
		is >> A.data[i];
	}
	return is;
}
ostream& operator<<(ostream& os, const myString& A)
{
	os << endl;
	for (int i = 0; i < A.length; i++)
	{
		os << A.data[i];
	}
	return os;
}
int myString::operator !=(const myString& a)
{
	int dem = 0;
	if (a.length != length) return 1;
	else
	{
		for (int i = 0; i < length - 1; i++)
		{
			if (a.data[i] != data[i])
			{
				dem++;
			}
		}
		if (dem == 0) return 0;
		else return 1;
	}
}
int myString::operator ==(const myString& a)
{
	if (*this != a) return 0;
	else return 1;
}
int myString::operator >(const myString& a)
{
	if (length > a.length) return 1;
	else return 0;
}
int myString::operator >=(const myString& a)
{
	if (length > a.length || *this == a) return 1;
	else return 0;
}
int myString::operator <(const myString& a)
{
	if (length < a.length) return 1;
	else return 0;
}
int myString::operator <=(const myString& a)
{
	if (length < a.length || *this == a) return 1;
	else return 0;
}
char myString::operator[](int index)
{
	return data[index];
}
void myString::set_data_i(int i, char b)
{
	data[i] = b;
}
myString::~myString()
{
	delete[] data;
}

int main()
{
	clock_t start, end;
	double time_use;
	start = clock();
	Linkedlist<int> H;
	Initation(H);
	InsertBegin(H, 1);
	InsertBegin(H, 2);
	InsertBegin(H, 3);
	InsertBegin(H, 4);
	show(H);
	DNode<int>* A;
	A = SearchNode(H, 3);
	InsertAfter<int>(H, A, 8);
	show(H);
	InsertBefore(H, A, 5);
	show(H);
	InsertTail(H, 30);
	show(H);
	/*sortInsertion(H);*/
	sortSelection(H);
	/*InsertBegin(H, 10);*/
	/*bubbleSort(H);*/
	delHead(H);
	delTail(H);
	delAtK(H, 8);
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian chay: " << time_use << "\n";
	show(H);
	show1(H);
	/*myString a[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "hay nhap xau thu " << i;
		cin >> a[i];
	}*/
	myString a, b, c, d;
	cout << "hay nhap xau thu nhat";
	cin >> a;
	cout << "hay nhap xau thu hai";
	cin >> b;
	cout << "hay nhap xau thu ba";
	cin >> c;
	cout << "hay nhap xau thu tu";
	cin >> d;
	Linkedlist<myString> D;
	Initation(D);
	InsertBegin(D, a);
	InsertBegin(D, b);
	InsertBegin(D, c);
	InsertBegin(D, d);
	bubbleSort(D);
	show1(D);
	return 0;
}
