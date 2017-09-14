#ifndef SET_H
#define SET_H
#include <stdlib.h>
#include "list.h"

typedef List Set;

/**
 * set实际上是一个链表，所以这里直接调用list_init来初始化set.
 */
void set_init(Set *set, int (*match)(const void *key1, const void *key2),void (*destroy)(void *data));

#define set_destroy list_destroy
int set_insert(Set *set, const void *data);
int set_remove(Set *set, void **data);
int set_union(Set *setu, const Set *set1, const Set *set2);
int set_intersection(Set *seti,const *set1, const Set *set2);
int set_difference(Set *setd, const Set *set1, const Set *set2);
int set_is_memeber(const Set *set, const void *data);
int set_is_subset(const Set *set1, const Set *set2);
int set_equal(const Set *set1, cosnt Set *set2);
#define set_size(set) ((set)->size)
#endif


