/*
******************************************************
* 文件名：config.h
* 作  者：wenzi
* 日  期：2019/11/19
* 版  本：v1.0
*****************************************************
*/

#include "config.h"

/*
**************************************************************
* 函数名：Op_Stack_Link_Init
* 功  能：初始化链栈
* 形  参：Op_Stack_Link *Op_Stack
* 返回值：操作状态
**************************************************************
*/
Status Op_Stack_Link_Init(Op_Stack_Link *Op_Stack)
{
	Op_Stack->top = (OpLinkedNode)malloc(sizeof(OpSnode));
	Op_Stack->top = NULL;
	Op_Stack->count = 0;
	return OK;
}


/*
**************************************************************
* 函数名：Op_Stack_link_Push
* 功  能: 压入一个元素到链栈
* 形  参：Op_Stack_Link *Op_Stack
* 返回值：操作状态
**************************************************************
*/
Status Op_Stack_link_Push(Op_Stack_Link *Op_Stack,OpSElemtype op)
{
    OpLinkedNode P;
	P = (OpLinkedNode)malloc(sizeof(OpSnode));
	P->op = op;
	P->next = Op_Stack->top;
	Op_Stack->top = P;
	Op_Stack->count ++;
	return OK;
}



/*
***************************************************************
* 函数名：Op_Stack_link_Print
* 功  能：从链栈中输出所有的元素
* 形  参：Op_Stack_Link Op_Stack：操作的对象
* 返回值：OK or ERROR
***************************************************************
*/
Status Op_Stack_link_Print(Op_Stack_Link Op_Stack)
{
    OpLinkedNode P;
	P = (OpLinkedNode)malloc(sizeof(OpSnode));    
	P = Op_Stack.top;
	printf("The Op Stack List Element is :\n");
	while(NULL != P)
	{
		printf("%c\n",P->op);
		P = P->next;
	}
	return OK;
}


/*
*******************************************************************
* 函数名：Op_Stack_link_Pop
* 功  能：从链栈中弹出一个元素
* 形  参：Op_Stack_Link *Op_Stack：要操作的链栈
          OpSElemtype *op:         用于存储运算符的变量
* 返回值：OpSElemtype:pop出的元素
*******************************************************************
*/
OpSElemtype Op_Stack_link_Pop(Op_Stack_Link *Op_Stack)
{
	OpLinkedNode P;
	OpSElemtype op;
	P = (OpLinkedNode)malloc(sizeof(OpSnode));    
	P = Op_Stack->top;
	op = P->op;
	Op_Stack->top = P->next;
	free(P);
	//printf("The Pop value is :%c\n",op);
	return op;
}

/*
********************************************************
* 函数名：Clear_Op_Stack_Link
* 功  能：释放链栈中的元素
* 形  参：Op_Stack_Link *Op_Stack：要释放的链栈
* 返回值：OK or ERROR
*******************************************************
*/
Status Clear_Op_Stack_Link(Op_Stack_Link *Op_Stack)
{
    OpLinkedNode P,Q;
	P = (OpLinkedNode)malloc(sizeof(OpSnode));
    Q = (OpLinkedNode)malloc(sizeof(OpSnode));
	P = Op_Stack->top;
	while(NULL != P)
	{
		Q = P->next;
		free(P);
		P = Q;
	}
	Op_Stack->top = NULL;
	return OK;
}


/*
*********************************************************
* 函数名：IS_Stack_Empty
* 功  能：判断当前的链栈是否是空栈
          空栈：   返回1
		  非空栈 ：返回0
* 形  参：Op_Stack_Link Op_Stack：当前的链栈
* 返回值：0 or 1
*********************************************************
*/
Empty IS_Stack_Empty(Op_Stack_Link Op_Stack)
{
	return (NULL == Op_Stack.top);
}