#include "infrastructure.h"

/*时间复杂度：O(L + P)
算法思想：设置一个自增变量  counter，然后和 q 中的元素比较，当遇到相等时，打印出这时
q -> data 的值。
*/
void PrintLots(LNode *p, LNode *q) {
    int counter = 1;

    p = p -> next;
    q = q -> next;

    while(p != NULL && q != NULL) {
        if(q -> data == counter++) {
            cout << p -> data << " ";
            q = q -> next;
        }

        p = p -> next;
    }

    cout << "\n" << endl;
}

//使用尾插法来建立链表
void CreateList(LNode *&C, int a[], int n) {
    LNode *s, *r;
    int i;
    C = (LNode *)malloc(sizeof(LNode));
    C -> next = NULL;
    r = C;

    for(i = 0; i < n ; ++i) {
        s = (LNode *)malloc(sizeof(LNode));
        s -> data = a[i];
        r -> next = s;
        r = r -> next;
    }

    r -> next = NULL;
}

//带头指针，记得先 p  = p -> next; 否则会打印出头指针。
void PrintList(LNode *p, int n) {
    LNode *q;
    q = p -> next;

    while(q != NULL) {
        cout << q -> data << " ";
        q = q -> next;
    }

    cout << "\n" << endl;
}

/*
首先要找到单链表的前元素，然后再作交换
交换 p 和 p -> next 的位置
*/
void SwapLinkList(LNode *p, LNode *L) {
    LNode *q;
    LNode *beforeP, *afterP;
    q = L -> next;
    afterP = p -> next;

    cout << "\n" << p -> data << endl; //For Test!

	//找到  p 的前一个结点
    while(q != NULL) {
        if(q -> next == p)
            beforeP = q;

        q = q -> next;
    }

    cout << "\n" << beforeP -> data << endl; //For Test!

	//Swap two element
   // p -> next = afterP -> next;
//    beforeP -> next = afterP ;
//    afterP -> next = p;

	//上下两者一样, 画图来理解.

	beforeP -> next = p -> next;
	p -> next = afterP -> next;
	afterP -> next = p;
}

int main() {
    int a[] = {1, 3, 4, 5};
    int b[] = {2, 3};
    int c[] = {2, 3, 4, 5, 6, 7};

    LNode *p1, *p2, *p3;
    CreateList(p1, a, 4);
    CreateList(p2, b, 2);
    CreateList(p3, c, 6);

    PrintList(p1, 4);
    PrintList(p2, 2);

    PrintLots(p1, p2);

    LNode *current = p3 -> next->next;

    PrintList(p3, 6);
    SwapLinkList(current, p3);
    PrintList(p3, 6);
}

/*Output:
1 3 4 5

2 3

3 4
*/
