//只给一个数组和一个变量i，找出这个数组中的最小值 
#include<iostream>
#include<stdlib.h>
#define N 9
using namespace std; 
void findMin(int A[], int &i){
	i=A[0];
	while(i/10 <=N-1){
		if(i%10>A[i/10]){
			i = i - i%10;
			i = i + A[i/10];
		}
		i=i+10;
	}
	i=i%10;
}

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode;

void createLNode(LNode *&A, int a[], int n){
	LNode *s, *r;
	int i;
	A = (LNode*)malloc(sizeof(LNode));
	A ->next = NULL;
	r = A;
	for(i =0; i<n; ++i){
	    s =(LNode *)malloc(sizeof(LNode));
		s -> data = a[i];
		r -> next = s;
		r = r -> next; 
	}
	r -> next = NULL; 
}

void reprint(LNode *L){
	if( L != NULL){
		reprint(L -> next);
		cout<<L -> data<< " ";
	}
}

int main(){
	int A[N]={1,3,5,4,9,7,45,63,79};
	int i;
	
	LNode *L;
	createLNode(L,A,N);
	reprint(L);	
	
	findMin(A,i);
	cout<<i<<endl;
	int j;
	for(j = 0; j < N ; j++){
		cout<<A[j]<<" ";
	}
}
