void enQueue(LNode *&rear, int x ){
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s -> data = x;
	s -> next = rear -> next;
	rear -> next s;
	rear = s;
} 

int deQueue(LNode *&rear, int &x){
	LNode *s;
	if(rear -> next == rear)
	    return 0;
	else{
		s = rear -> next -> next;
		rear -> next -> next = s -> next;
		x = s -> data;
		if(s == rear){
			rear = rear -> next;
		} 
		free(s);
		return 1;
	}
}
