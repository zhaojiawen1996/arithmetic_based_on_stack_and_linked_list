/*
******************************************************
* �ļ�����config.h
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/19
* ��  ����v1.0
*****************************************************
*/

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__


typedef int              DElemType;
typedef char             OpElemType;



/*����һ�����ܹ��洢�������ܴ洢�����������*/
typedef struct Node
{
    DElemType     data;
	OpElemType    op;
	unsigned char valid;/*��Чλ����validλ1ʱ��dataΪ��Ч���ݣ���validλΪ0ʱ��opΪ��Чλ*/       
	struct Node *next;
}Node;

typedef struct Node *LinkedNode;

typedef struct 
{
	LinkedNode head;/*�����ͷָ��*/
	int count;       /*�����е�Ԫ�ظ���*/
}Linked_List;

Status Linked_List_Incert(Linked_List *List,DElemType value,OpElemType op,Incert_Type Type);
Status Linked_List_Init(Linked_List *List);
Status Linked_List_Show(Linked_List List);

#endif