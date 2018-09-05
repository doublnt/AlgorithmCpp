#include<iostream>
#define maxSize 100

using namespace std;

typedef struct SqList{
	int data[maxSize];
	int length;
}SqList;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode;

typedef struct DNode{
	int data;
	struct DNode *prior;
	struct DNode *next;
}DNode;

int findElem(SqList L, int x){
	int i;
	for(i =0;i<L.length;++i){
		if(x < L.data[i])
			return i;
	}
	return i;
}

void insertElem(SqList &L, int x){
	int p,i;
	p = findElem(L,x);
	for(i = L.length -1;i>=p;--i){
		L.data[i+1] = L.data[i];
	}
	L.data[p]=x;
	++(L.length); 
}

void mergeSqList(LNode *A, LNode *B, LNode*&C){
    LNode *p = A->next;
    LNode *q = B->next;
	LNode *r;
	C = A;
	C->next=NULL;
//	free(B);
	r=C; 
	while(p!=NULL&& q!=NULL){
		if(p->data<=q->data){
			r->next=p;
			p=p->next;
			r=r->next;
		}else{
			r->next =q;
			q=q->next;
			r=r->next;
		}
	}
	r->next=NULL;
	if(p!=NULL){
		r->next =p;
	}
	if(q!=NULL){
		r->next=q;
	}
} 
/*
将L中所有小于表头元素的整数放在前半部分，其他放在后半部分 
*/
void exchangeElem(SqList &L){
	int temp,i=0,j=L.length-1;
	temp=L.data[i];
	
	while(i<j){
		//region	Vital Procedure 
		while(i<j&&L.data[j]>temp)//Question: is i<j redundant？ 在循环里面当i++和 --j可能出现超越的情况 
			--j;
		
		if(i<j){
			L.data[i]=L.data[j];
			++i;
		}
		
		while(i<j&&L.data[i]<temp)
			++i;
		if(i<j){
			L.data[j]=L.data[i];
			--j;
		}
		//endregion
	}
	L.data[i]=temp;
}

int main(){
	struct SqList{
		int data[maxSize]={0};
		int length = maxSize;
	}; 
	SqList sq1;
	cout << sq1.length<< endl;
}
