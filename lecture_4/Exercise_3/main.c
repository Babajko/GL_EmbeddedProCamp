#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	int size;
	int writePoint;
	int readPoint;
	void* storage;
} Queue_t;

enum errorCode
{
	none,
	mismatchMemory
};

errorCode writeQ(Queue_t * q, int writeData)
{
	int * arr;
	arr = (int*)q->storage;
	if (q->writePoint >= q->size)
	{
		return mismatchMemory;
	}

	arr[q->writePoint] = writeData;
	q->writePoint++;

	return none;
}

errorCode readQ(Queue_t * q, int * rValue)
{
	int * arr;
	arr = (int*)q->storage;

	if (q->readPoint == q->writePoint)
	{
		return mismatchMemory;
	}

	*rValue = arr[q->readPoint];
	q->readPoint++;
	return none;
}

errorCode createQ(Queue_t * q, int size)
{
	q->size = size;
	q->writePoint = 0;
	q->readPoint = 0;
	q->storage = malloc(sizeof(int) * size);
	return NULL != q->storage ? none : mismatchMemory;
}

errorCode deleteQ(Queue_t * q)
{
	free(q->storage);
	return none;
}

int main()
{
	Queue_t  queue;
	int rV{0};

	createQ(&queue, 5);

	printf("is write 10 : %s\n", writeQ(&queue, 10) ? "folse" : "true");
	printf("is write 20 : %s\n", writeQ(&queue, 20) ? "folse" : "true");
	printf("is write 30 : %s\n", writeQ(&queue, 30) ? "folse" : "true");
	//printf("is write 40 : %s\n", writeQ(&queue, 40) ? "folse" : "true");
	//printf("is write 50 : %s\n", writeQ(&queue, 50) ? "folse" : "true");
	//printf("is write 60 : %s\n", writeQ(&queue, 60) ? "folse" : "true");

	printf("is read : %s   ", readQ(&queue, &rV) ? "folse" : "true");
	printf("read = %d\n", rV);
	printf("is read : %s   ", readQ(&queue, &rV) ? "folse" : "true");
	printf("read = %d\n", rV);
	printf("is read : %s   ", readQ(&queue, &rV) ? "folse" : "true");
	printf("read = %d\n", rV);
	printf("is read : %s   ", readQ(&queue, &rV) ? "folse" : "true");
	printf("read = %d\n", rV);

	deleteQ(&queue);

	return 0;
}
