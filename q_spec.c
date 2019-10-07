#include "q.h"
#include<assert.h>
#include<stdio.h>
/*void print(queue *q)// this only works for normal queue not for circular
{
	int i;
	for(i=q->tail;i<q->size;i++)
	{
		printf("%d\t",q->data[i]);
	}
	printf("\n");
}*/
void test_empty_queue()
{
	Queue queue = queue_new(5);
	Queue *q = &queue;
	assert(queue_full(q)==0);
	assert(queue_empty(q)==1);
}
void test_queue()
{
	Queue queue = queue_new(6);
	Queue *q = &queue;
	queue_result res;

	q=queue_add(q, 10, &res);
	//print(q);
	assert(res.status==Queue_OK && q->count==1);
	q=queue_add(q, 20, &res);
	q=queue_add(q, 30, &res);
	//print(q);
	q=queue_delete(q,&res);
	//print(q);
	assert(res.status==Queue_OK && res.data==10);
	q=queue_delete(q,&res);
	q=queue_delete(q,&res);
	assert(queue_empty(q)==1);

}
int main()
{
	test_empty_queue();
	test_queue();
	return 0;
}
