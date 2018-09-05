#define MaxSize 50
#include<iostream> 
#include<stdlib.h> 
using namespace std;


typedef struct{
	int data[MaxSize];
	int top;
}SqStack;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode;

typedef struct{
	int data[MaxSize];
	int front;
	int rear;
}SqQueue;

typedef struct QNode{
	int data;
	struct QNode *next;
}QNode;

typedef struct{
	QNode *front;
	QNode *rear;
}LiQueue;

int match(char exp[], int n){
	char stack[MaxSize];
	int top = -1;
	int i;
	for(i = 0; i < n; ++i){
		if(exp[i] == '(')
			stack[++top]='(';
		if(exp[i] == ')')
		{
			if(top == -1)
			    return 0;
			else
			    --top;
		}
	}
	if(top == -1)
	    return 1;
    else
        return 0;
}

int op(int a, char Op, int b){
	if(Op == '+') return a + b;
	if(Op == '-') return a - b;
	if(Op == '*') return a * b;
	if(Op == '/'){
		if(b == 0){
			cout<<"ERROR"<<endl;
			return 0;
		}else{
			return a / b;	
		}
	}
}

int com(char exp[]){
	int i,a,b,c;
	int stack[MaxSize];
	int top = -1;
	
	char Op;
	
	for(i = 0 ; exp[i]!='\0';++i){
		if(exp[i] >= '0' && exp[i] <='9')
		    stack[++top] = exp[i] - '0';
		else
		{
			Op = exp[i];
			b = stack[top--];
			a = stack[top--];
			c = op(a, Op,b);
			stack[++top] = c;
		}
	}
	return stack[top];
}

void enQueue(LiQueue *lqu, int x){
	QNode *p;
	p = (QNode*)malloc(sizeof(QNode));
	p -> data = x;
	p -> next = NULL;
	if(lqu ->rear == NULL)
	    lqu -> front = lqu -> rear = p;
	else{
		lqu -> rear -> next = p;
		lqu -> rear = p;
	}
}

int deQueue(LiQueue *lqu, int &x){
	QNode *p;
	if(lqu -> rear ==NULL){
		return 0;
	}
	else{
		p = lqu -> front;
	}
	if(lqu -> front == lqu -> rear){
		lqu -> front = lqu -> rear = NULL;
	}
	else{
		lqu -> front = lqu -> front -> next; 
	}
	x = p -> data;
	free(p);
	return 1; 
}




