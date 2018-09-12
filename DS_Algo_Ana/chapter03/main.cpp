#include "infrastructure.h"

/*ʱ�临�Ӷȣ�O(L + P)
�㷨˼�룺����һ����������  counter��Ȼ��� q �е�Ԫ�رȽϣ����������ʱ����ӡ����ʱ
q -> data ��ֵ��
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

//ʹ��β�巨����������
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

//��ͷָ�룬�ǵ��� p  = p -> next; ������ӡ��ͷָ�롣
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
����Ҫ�ҵ��������ǰԪ�أ�Ȼ����������
���� p �� p -> next ��λ��
*/
void SwapLinkList(LNode *p, LNode *L) {
    LNode *q;
    LNode *beforeP, *afterP;
    q = L -> next;
    afterP = p -> next;

    cout << "\n" << p -> data << endl; //For Test!

	//�ҵ�  p ��ǰһ�����
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

	//��������һ��, ��ͼ�����.

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
