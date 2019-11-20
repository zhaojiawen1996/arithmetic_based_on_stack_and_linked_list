/*
******************************************************
* 文件名：config.h
* 作  者：wenzi
* 日  期：2019/11/19
* 版  本：v1.0
*****************************************************
*/

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__


typedef int              DElemType;
typedef char             OpElemType;



/*创建一个既能够存储数据又能存储运算符的链表*/
typedef struct Node
{
    DElemType     data;
	OpElemType    op;
	unsigned char valid;/*有效位，当valid位1时，data为有效数据，当valid位为0时，op为有效位*/       
	struct Node *next;
}Node;

typedef struct Node *LinkedNode;

typedef struct 
{
	LinkedNode head;/*链表的头指针*/
	int count;       /*链表中的元素个数*/
}Linked_List;

Status Linked_List_Incert(Linked_List *List,DElemType value,OpElemType op,Incert_Type Type);
Status Linked_List_Init(Linked_List *List);
Status Linked_List_Show(Linked_List List);

#endif