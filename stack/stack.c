/*
* @Author: shilun
* @Date:   2017-09-11 20:38:28
* @Last Modified by:   shilun
* @Last Modified time: 2017-09-11 20:39:48
*/
#include <stdlib.h>

#include "list.h"
#include "stack.h"

int stack_push(Stack *stack ,const void *data){
	return  list_ins_next(stack, NULL, data);
}
int stack_pop(Stack *stack, void **data){
	return list_rem_next(stack, NULL, data);
}
