#ifndef __LIST_TEST_H__
#define __LIST_TEST_H__

typedef struct __listNode{
	// int size;//我自己定义了这个
	void *data;//教程上定义了这个
	/*两者可能用途不一样吧*/

	struct __listNode *next;
}listNode, *plistNode;

typedef struct __list{
	int size;//这个代表了单链表的大小

	plistNode *head;//表头
	plistNode *tail; //表尾
	//上面这些就是我能想到的了。
	//注意哈,这里这个数据结构并不是listNode，它本身的作用也就是存个大小啊，头尾神码的，
	//不会建一个节点就new一个新值，这个相当于一个哨兵，就是只是指向而已。
	
	//下面这个是书上给的。添加了我的一些注释。
	void (*destroy)(struct __list *list);//这里我觉得应该这样定义，因为目的就是为了销毁链表嘛！你给个指向链表头节点的指针就行了，but,书上的定义如下：
	//void (*destroy)(void *data);//不知道这里的 void *data是个神码意思。
	//
	int (*match)(const void *key1, const void *key2);//这个不知道干嘛的
}

#endif