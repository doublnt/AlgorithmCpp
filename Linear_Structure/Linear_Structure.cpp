#include<iostream>
#include "stdlib.h"
#define maxSize 100
#define NotFound -1

using namespace std;

typedef struct SqList {
    int data[maxSize];
    int length;
} SqList;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

typedef struct DLNode {
    int data;
    struct DLNode *prior;
    struct DLNode *next;
} DLNode;

/*
返回第一个比 x 大的元素，若没有找到则返回末尾的元素位置
*/
int findElem(SqList L, int x) {
    int i;

    for(i = 0; i < L.length; ++i) {
        if(x < L.data[i])
            return i;
    }

    return i;
}

/*
FindELem in SqList
*/
int FindElemSqList(SqList L, int element) {
    int i = 0;

    for(i; i < L.length; ++i) {
        if(L.data[i] == element)
            return i;
    }

    return NotFound;
}

void insertElem(SqList &L, int x) {
    int i = 0;
    int insertPosition;
    insertPosition = findElem(L, x);

    for(i  = L.length ; i > insertPosition; --i) {
        L.data[i] = L.data[i - 1];
    }

    L.data[insertPosition] = x;
    ++(L.length);
}

/*
在SqList L 的 p 位置上 插入 元素 e，插入成功返回 1 ，否则返回 -1
*/
int InsertElem(SqList &L, int e, int p) {
    if(p > L.length - 1 || p < 0)
        return -1;

    int i;

    for(i = L.length; i > p; --i) {
        L.data[i] = L.data[i - 1];
    }

    L.data[p] = e;
    ++(L.length);//别忘记插入元素后，表长要加1
    return 1;
}

/*
删除下标 为 p 的元素
*/
int DeleteElem(SqList &L, int p, int &e){
	int i;
	if(p > L.length - 1 || p < 0){
		return -1;
	}
	e = L.data[p];
	for(int i = p; i < L.length ; ++i)
	{
		L.data[i] = L.data[i+1];
	}
	--(L.length);
	return 1;
}

void mergeSqList(LNode *A, LNode *B, LNode*&C) {
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *r;
    C = A;
    C->next = NULL;
//	free(B);
    r = C;

    while(p != NULL && q != NULL) {
        if(p->data <= q->data) {
            r->next = p;
            p = p->next;
            r = r->next;
        } else {
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }

    r->next = NULL;

    if(p != NULL) {
        r->next = p;
    }

    if(q != NULL) {
        r->next = q;
    }
}
/*
将L中所有小于表头元素的整数放在前半部分，其他放在后半部分
*/
void exchangeElem(SqList &L) {
    int temp, i = 0, j = L.length - 1;
    temp = L.data[i];

    while(i < j) {
        //region	Vital Procedure
        while(i < j && L.data[j] > temp) //Question: is i<j redundant？ 在循环里面当i++和 --j可能出现超越的情况
            --j;

        if(i < j) {
            L.data[i] = L.data[j];
            ++i;
        }

        while(i < j && L.data[i] < temp)
            ++i;

        if(i < j) {
            L.data[j] = L.data[i];
            --j;
        }

        //endregion
    }

    L.data[i] = temp;
}

//当需要改变变量时，记得用 &
void CreateSqList(SqList &s, int a[], int length) {
    s.length = length;

    for(int i = 0; i < length; ++i) {
        s.data[i] = a[i];
    }

}

void PrintSqList(SqList s) {
    for(int i = 0; i < s.length; ++i) {
        cout << s.data[i] << " ";
    }
}

// 尾插法建立单链表
void CreateListR(LNode *&C, int a[], int n)
{
	LNode *s, *r;
	int i;
	C = (LNode *)malloc(sizeof(LNode));
	C -> next = NULL;
	
	r = C;
	
	for(i = 0; i < n; ++i)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s -> data = a[i];
		
		r -> next = s;
		r = r -> next;
	}
	r -> next = NULL;
}

// 头插法建立单链表
void CreateListF(LNode *&C, int a[], int n)
{
	LNode *s;
	int i;
	C = (LNode *)malloc(sizeof(LNode));
	C -> next = NULL;
	
	for(i = 0; i < n; ++i)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s -> data = a[i];
		
		s -> next = C -> next;
		C -> next = s;
	}
}

void PrintLNodeList(LNode *C)
{
	C = C -> next;
	while(C != NULL)
	{
		cout << C ->data << "\t";
		C = C -> next;
	}
	cout << endl;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	#pragma region SqList
	/*
    SqList sq1;

    CreateSqList(sq1, a, 9);
    PrintSqList(sq1);

    cout << "\nThe Result value is:" << FindElemSqList(sq1, 10) << endl;

    insertElem(sq1, 1);
    PrintSqList(sq1);

    cout << "\nInsert the Element 100 in position 1" << endl;

    cout << "\nThe result is:" << InsertElem(sq1, 100, 1) << endl;
    PrintSqList(sq1);
	
	cout <<"\nHello, This is from Command Line" << endl;
	
	int deleteEle;
	DeleteElem(sq1,2,deleteEle);
	
	cout<< deleteEle << endl;
	PrintSqList(sq1);
	*/
	#pragma endregion
	
	cout << "Create LNode..." <<endl;
	
	LNode *AF,*AR;
	
	CreateListF(AF, a, 9); //头插法
	CreateListR(AR, a, 9); //尾插法
	
	PrintLNodeList(AF);
	PrintLNodeList(AR);
}
