#define maxSize 100
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

void PrintLots(LNode *p, LNode *q);

void CreateList(LNode *&p, int a[], int n);

void PrintList(LNode *p, int n);

void SwapLinkList(LNode *p, LNode *L);
