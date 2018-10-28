#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int size;
	int writePoint;
	int readPoint;
	void* storage;
} Queue;

typedef enum 
{
	NONE,
	MISMATCH_MEMORY
} errorCode;

errorCode writeQ(Queue * q, int writeData)
{
	int * arr;
	arr = (int*)q->storage;
	if (q->writePoint >= q->size)
	{
		return MISMATCH_MEMORY;
	}

	arr[q->writePoint] = writeData;
	q->writePoint++;

	return NONE;
}

errorCode readQ(Queue * q, int * rValue)
{
	int * arr;
	arr = (int*)q->storage;

	if (q->readPoint == q->writePoint)
	{
		return MISMATCH_MEMORY;
	}

	*rValue = arr[q->readPoint];
	q->readPoint++;
	return NONE;
}

errorCode createQ(Queue * q, int size)
{
	q->size = size;
	q->writePoint = 0;
	q->readPoint = 0;
	q->storage = malloc(sizeof(int) * size);
	return NULL != q->storage ? NONE : MISMATCH_MEMORY;
}

errorCode deleteQ(Queue * q)
{
	free(q->storage);
	return NONE;
}

int main()
{
	Queue  queue;
	int rV = 0;

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
