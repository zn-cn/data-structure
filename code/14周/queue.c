#include<stdio.h>

int queue[10];
int head = 0;
static int tail = 0;

void enqueue(int i);
void dequeue();
int ifFull();
int ifEmpty();
void printQueue();

int main()
{
	enqueue(1);
	printQueue();
	dequeue();
	printQueue();

	return 0;
}

void enqueue(int i)
{
	if (!ifFull())
	{
		queue[tail] = i;
		tail++;

	}
}

void dequeue()
{
	if (!ifEmpty())
	{

		queue[tail - 1] = 0;
		tail--;
	}
}


int ifFull()
{
	if (tail == 10)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int ifEmpty()
{
	if (tail == 0)
	{
		return 1;
	}
	else
	{

		return 0;
	}
}

void printQueue()
{
	printf("[ ");
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", queue[i]);
	}
	printf("]\n");
}
