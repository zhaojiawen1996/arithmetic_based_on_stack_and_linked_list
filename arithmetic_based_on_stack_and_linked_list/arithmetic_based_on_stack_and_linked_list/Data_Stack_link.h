/*
******************************************************
* �ļ�����config.h
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/19
* ��  ����v1.0
*****************************************************
*/

#ifndef __DATA_STACK_LINK_H__
#define __DATA_STACK_LINK_H__

typedef int DSElemtype;


/*������һ��������ݵ���ջ�Ľ��*/
typedef struct Snode
{
    DSElemtype data;
	struct Snode *next;
}Snode;

typedef struct Snode *SLinkedNode;

typedef struct 
{
    SLinkedNode top;/*���������������ջ��ջ��ָ��*/
	int count;    /*��ջ�����ݵĸ���*/
}Data_Stack_Link;

Status Data_Stack_Link_Init(Data_Stack_Link *Data_Stack);
Status Data_Stack_link_Push(Data_Stack_Link *Data_Stack,DSElemtype value);
Status Data_Stack_link_Print(Data_Stack_Link Data_Stack);
int Data_Stack_link_Pop(Data_Stack_Link *Data_Stack);
Status Clear_Data_Stack_Link(Data_Stack_Link *Data_Stack);


#endif