/*
******************************************************
* 文件名：config.h
* 作  者：wenzi
* 日  期：2019/11/19
* 版  本：v1.0
*****************************************************
*/

#ifndef __OPER_STACK_LINK_H__
#define __OPER_STACK_LINK_H__

typedef char OpSElemtype;


/*定义了一个存放运算符的链栈的结点*/
typedef struct OpSnode
{
    OpSElemtype op;
	struct OpSnode *next;
}OpSnode;

typedef struct OpSnode *OpLinkedNode;

typedef struct 
{
    OpLinkedNode top;/*定义了这个运算符链栈的栈顶指针*/
	int count;    /*该栈中数据的个数*/
}Op_Stack_Link;

Status Op_Stack_Link_Init(Op_Stack_Link *Op_Stack);
Status Op_Stack_link_Push(Op_Stack_Link *Op_Stack,OpSElemtype op);
Status Op_Stack_link_Print(Op_Stack_Link Op_Stack);
OpSElemtype Op_Stack_link_Pop(Op_Stack_Link *Op_Stack);
Status Clear_Op_Stack_Link(Op_Stack_Link *Op_Stack);
Empty IS_Stack_Empty(Op_Stack_Link Op_Stack);

#endif