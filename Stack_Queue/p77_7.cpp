typedef struct{
	int data[maxSize];
	int front, rear;
}cycqueue;

int deQueue(cycqueue &Q, int &x){
	if(Q.front == Q.rear)
	    return 0;
    else
    {
    	x = Q.data[Q.rear];
    	Q.rear = (Q.rear - 1 + maxSize)%maxSize;
    	return 1;
    }
}

int enQueue(cycqueue &Q, int x){
	if(Q.rear == (Q.front -1 + maxSize)%maxSize)
	    return 0;
    else{
    	Q.data[Q.front] = x;
    	Q.front = (Q.front - 1 +maxSize)&maxSize;
    	return 1;
    }
}
