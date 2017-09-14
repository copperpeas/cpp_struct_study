/*
* @Author: shilun
* @Date:   2017-09-11 21:49:21
* @Last Modified by:   shilun
* @Last Modified time: 2017-09-11 21:50:36
*/
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "set.h"

/*set_init*/

void set_init(Set *set, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data)){
	
}