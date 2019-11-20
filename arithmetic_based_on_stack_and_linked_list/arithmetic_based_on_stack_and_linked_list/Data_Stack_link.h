/*
******************************************************
* 文件名：config.h
* 作  者：wenzi
* 日  期：2019/11/19
* 版  本：v1.0
*****************************************************
*/

#ifndef __DATA_STACK_LINK_H__
#define __DATA_STACK_LINK_H__

typedef int DSElemtype;


/*定义了一个存放数据的链栈的结点*/
typedef struct Snode
{
    DSElemtype data;
	struct Snode *next;
}Snode;

typedef struct Snode *SLinkedNode;

typedef struct 
{
    SLinkedNode top;/*定义了这个数据链栈的栈顶指针*/
	int count;    /*该栈中数据的个数*/
}Data_Stack_Link;

Status Data_Stack_Link_Init(Data_Stack_Link *Data_Stack);
Status Data_Stack_link_Push(Data_Stack_Link *Data_Stack,DSElemtype value);
Status Data_Stack_link_Print(Data_Stack_Link Data_Stack);
int Data_Stack_link_Pop(Data_Stack_Link *Data_Stack);
Status Clear_Data_Stack_Link(Data_Stack_Link *Data_Stack);


#endif