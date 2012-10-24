#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> 
#include <signal.h>
#include <semaphore.h>
#include <assert.h>
#include <math.h>

typedef struct Node
{
	int el;
	struct Node * Next;
} Sps;

void pull(int val)
{
	Sps *p; //Текущий элемент
	p = malloc(sizeof(Sps));
	p->el = val;
	p->Next = NULL;
	return p;

}
void main()
{
	int i;
	int d[5];
	for (i = 0; i<5; i++)
	{
		scanf("%d", &d[i]);
	}
	
	for (i = 0; i<5; i++)
	{
		printf("%d ", d[i]);
	}
	return 0;
}


