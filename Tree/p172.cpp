int n = 0;
void count(BTNode *p){
	if(p!=NULL){
		++n;
		count(p -> lchild);
		count(p -> rchlid);
	}
}

int count(BTNode *p){
	int n1, n2;
	if(p == NULL)
		return 0;
	else if(p -> lchild == NULL && p -> rchild == NULL){
		return 1£» 
	else{
		n1 = count(p -> lchild);
		n2 = count(p -> rchild);
		return 1 + n1 + n2;
	}
}

void link(BTNode *p, BTNode *&head, BTNode *&tail){
	if(p != NULL){
		if(p -> lchild = NULL && p -> rchild == NULL){
			if(head == NULL){
				head = p;
				tail = p;
			}
			else{
				tail -> rchild = p;
				tail = p;
			}
		}
		link(p -> lchild, head, tail);
		link(p -> rchild, head, tail);
	}
} 

typedef struct BTNode{
	char data;
	struct BTNode *parent;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

void triBtree(BTNode *p, BTNode *q){
	if(p != NULL){
		p -> parent =q;
		q = p;
		
		triBtree(p -> lchild, q);
		triBtree(p -> rchild, q);
	}
}

void printPath(BTNode *p){
	while(p!=NULL){
		cout << p -> data << " " endl;
		p = p -> parent;
	}
}

void allPath(BTNode *p){
	if(p != NULL){
		printPath(p);
		
		allPath(p -> lchild);
		allPath(p -> rchild);
	}
} 

void changeOrder(char pre[], int L1, int R1, char post[], int L2, int R2){
	if(L1 < = R1){
		post[R2] = pre[L1];
		changeOrder(pre, L1+1,(L1+1+R1)/2,post,L2,(L2+R2-1)/2);
		changeOrder(pre,(L1+1+R1)/2+1,R1,post,(L2+R2-1)/2+1,R2-1); 
	}
}

int L = 1;
void leno(BTNode *p, char x){
	if(p!= NULL){
		if(p -> data == x){
			cout << L << endl;
		}
		++L;
		
		leno(p -> lchild, x);
		leno(p -> rchild, x);
		--L;
	}
}


void DoubleOrder(BTNode *p){
	if(t != NULL){
		Visit(t);
		DoubleOrder(t -> lchild);
		Visit(t);
		DoubleOrder(t -> rchild);
	}
}












