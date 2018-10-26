/***
问题描述：一组生产者进程和消费者进程共享一个初始为空、大小为 n 的缓冲区，只有缓冲区没满时，
生产者才能把消息放入到缓冲区，否则必须等待；只有缓冲区不空时，消费者才能从中取出信息，否则必须等待。
由于缓冲区是临界资源，它只允许一个生产者放入消息，或者一个消费者从中取出消息。
***/
semaphore mutex = 1;
semaphore empty = n;
semaphore full = 0;

producer
{
	while(1)
	{
	    producer an item in nextp;
		P(mutex		P(empty);
); //临界资源加锁
		add nextp to buffer;
		V(mutex);
		V(full);
	}
}

consumer()
{
	while(1)
	{
		P(full);
		P(mutex);//临界资源加锁
		remove an item from buffer;
		V(mutex);
		V(empty);
		consume the item;
	}
}