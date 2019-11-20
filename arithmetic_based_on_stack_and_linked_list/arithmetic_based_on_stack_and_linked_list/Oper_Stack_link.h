/*
******************************************************
* �ļ�����config.h
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/19
* ��  ����v1.0
*****************************************************
*/

#ifndef __OPER_STACK_LINK_H__
#define __OPER_STACK_LINK_H__

typedef char OpSElemtype;


/*������һ��������������ջ�Ľ��*/
typedef struct OpSnode
{
    OpSElemtype op;
	struct OpSnode *next;
}OpSnode;

typedef struct OpSnode *OpLinkedNode;

typedef struct 
{
    OpLinkedNode top;/*����������������ջ��ջ��ָ��*/
	int count;    /*��ջ�����ݵĸ���*/
}Op_Stack_Link;

Status Op_Stack_Link_Init(Op_Stack_Link *Op_Stack);
Status Op_Stack_link_Push(Op_Stack_Link *Op_Stack,OpSElemtype op);
Status Op_Stack_link_Print(Op_Stack_Link Op_Stack);
OpSElemtype Op_Stack_link_Pop(Op_Stack_Link *Op_Stack);
Status Clear_Op_Stack_Link(Op_Stack_Link *Op_Stack);
Empty IS_Stack_Empty(Op_Stack_Link Op_Stack);

#endif