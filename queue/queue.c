/*
* @Author: shilun
* @Date:   2017-09-11 20:43:52
* @Last Modified by:   shilun
* @Last Modified time: 2017-09-11 20:45:03
*/
#include <stdlib.h>
#include "list.h"
#include "queue.h"

int queue_enqueue(Queue *queue, const void *data){
	return list_ins_next(queue,list_tail(queue),data);
}

int queue_dequeue(Queue *queue, void **data){
	return list_rem_next(queue,NULL,data);
}