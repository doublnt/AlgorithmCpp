#include "infrastructure.h"

/*时间复杂度：O(L + P)
算法思想：设置一个自增变量  counter，然后和 q 中的元素比较，当遇到相等时，打印出这时
q -> data 的值。
*/
void PrintLots(LNode *p, LNode *q)
{
    int counter = 1;

    p = p -> next;
    q = q -> next;

    while(p != NULL && q != NULL)
    {
        if(q -> data == counter++)
        {
            cout << p -> data << " ";
            q = q -> next;
        }

        p = p -> next;
    }
}

//使用尾插法来建立链表
void CreateList(LNode *&C, int a[], int n)
{
    LNode *s, *r;
    int i;
    C = (LNode *)malloc(sizeof(LNode));
    C -> next = NULL;
    r = C;

    for(i = 0; i < n ; ++i)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s -> data = a[i];
        r -> next = s;
        r = r -> next;
    }

    r -> next = NULL;
}

//带头指针，记得先 p  = p -> next; 否则会打印出头指针。
void PrintList(LNode *p, int n)
{
    LNode *q;
    q = p -> next;

    while(q != NULL)
    {
        cout << q -> data << " ";
        q = q -> next;
    }

    cout << "\n" << endl;
}

int main()
{
    int a[] = {1, 3, 4, 5};
    int b[] = {2, 3};
    LNode *p1, *p2;
    CreateList(p1, a, 4);
    CreateList(p2, b, 2);

    PrintList(p1, 4);
    PrintList(p2, 2);

    PrintLots(p1, p2);
}

/*Output:
1 3 4 5

2 3

3 4
*/
