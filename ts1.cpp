/*
* @Author: shilun
* @Date:   2017-09-08 08:37:53
* @Last Modified by:   shilun
* @Last Modified time: 2017-09-08 09:10:41
*/
//no useful
void swap1(int x, int y){
	int tmp;
	tmp = x; x=y; y=tmp;
	return;
}

//useful
void swap2(int *x, int *y){
	int tmp;
	tmp=*x; *x=*y; *y=tmp;
	return;
}

/**
 * [list_rem_next description]
 * @param  list    [description]
 * @param  element [description]
 * @param  data    [description]指向指针的指针
 * @return         [description]
 */
int list_rem_next(List *list,ListElmt *element, void **data);


#include <stdlib.h>
$include <string.h>

int swap2(void *x,void *y, int size){
	void *tmp;

	if((tmp=malloc(size)) == NULL)
		return -1;

	memcpy(tmp,x,size);
	memcpy(x,y,size);
	memcpy(y,tmp,size);
	free(tmp);

	return 0;
}