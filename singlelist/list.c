/*
* @Author: shilun
* @Date:   2017-09-11 09:27:44
* @Last Modified by:   shilun
* @Last Modified time: 2017-09-11 17:52:27
*/
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * list init function, 这里把size初始化为0，head,tail为空。
 * 释放函数为destroy，这样再进行使用的时候就不用再初始化释放函数了。
 * 初始化函数不申请存储空间，不分配存储空间，很类似于linux的写时复制政策。
 */
void list_init(List *list, void(*destroy)(void *data)){
	/*initialize the list*/
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
	return;
}
/**
 * [list_destroy description]
 * 这个destroy是怎么个destroy?在我的印象里，可能应该是把size赋值为0，然后？获得一个节点free一个节点？？
 * 还是直接把头指针赋空？我倾向于第一种，free每一个节点。但是具体怎么做看下面的书上的代码。
 * @param list [description]
 */
void list_destroy(List *list){
	void *data;

	//注意，是一个一个干掉，free掉，不是直接干掉。
	while(list_size(list) > 0){
		if(list_rem_next(list,NULL,(void **)&data) == 0 && list->destroy != NULL){
			list->destroy(data):
		}
		memset(list,0,sizeof(List));
		return;
	}
}

int list_rem_next(List *list,ListElmt *element, void **data){
	ListElmt *old_element;
	//Do not allow removal from an empty list
	if(list_size(list) == 0)
		return -1;
	if(element == NULL){
		*data = list->head->data;
		old_element = list->head;
		list->head = list->head->next;

		if(list_size(list) == 1)
			list->tail = NULL;
	}else{
		if(element->next == NULL)
			return -1;
		*data = element->next->data;
		old_element = element->next;
		element->next = element->next->next;
		if(element->next == NULL)
			list->tail = element;
	}
	free(old_element);
	list->size--;
	return 0;
}

int list_ins_next(List *list,ListElmt *element,const void *data){
	listElmt  *new_element;
	if((new_element = (ListElmt*)malloc(sizeof(listElmt))) == NULL)
		return -1;
	new_element->data = (void*)data;
	if(element == NULL){
		if(list_size(list) == 0)
			list->tail = new_element;
	}else{
		if(element->next == NULL)
			list->tail = new_element;
		new_element->next = element->next;
		element->next = new_element;
	}
	list->size++;
	return 0;
}