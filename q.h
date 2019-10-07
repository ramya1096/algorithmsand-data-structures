#ifndef _INCLUDED_QUEUE
#define _INCLUDED_QUEUE
#include<stdint.h>
#define MAX_DEPTH 32

typedef struct _queue_ Queue;
typedef struct _queue_result_ QueueResult;

struct _queue_{
     uint32_t size;
     uint32_t count;
     uint32_t head;
     uint32_t tail;
     int32_t data[MAX_DEPTH];
     };



struct _queue_result_{
     int32_t data;
     int32_t status;
     };

#define Queue_OK 1
#define Queue_FULL 2
#define Queue_EMPTY 3

Queue queue_new(uint32_t size);
uint32_t queue_full(Queue *q);
uint32_t queue_empty(Queue *q);
Queue* queue_add(Queue *q,int32_t element,QueueResult *res);
Queue* queue_delete(Queue *q,QueueResult *res);

#endif // _INCLUDED_

