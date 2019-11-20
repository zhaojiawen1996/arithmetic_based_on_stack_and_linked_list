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
* 函数名：Data_Stack_Link_Init
* 功  能：初始化链栈
* 形  参：Data_Stack_Link *DS
* 返回值：操作状态
**************************************************************
*/
Status Data_Stack_Link_Init(Data_Stack_Link *Data_Stack)
{
	Data_Stack->top = (SLinkedNode)malloc(sizeof(Snode));
	Data_Stack->top = NULL;
	Data_Stack->count = 0;
	return OK;
}


/*
**************************************************************************
* 函数名：Data_Stack_link_Push
* 功  能：往链栈中压入数据
* 形  参：Data_Stack_Link *Data_Stack：现有的链栈
          DSElemtype value：           要压入的值
* 返回值：OK or ERROR
**************************************************************************
*/
Status Data_Stack_link_Push(Data_Stack_Link *Data_Stack,DSElemtype value)
{
    SLinkedNode P;
	P = (SLinkedNode)malloc(sizeof(Snode));
	P->data = value;
	P->next = Data_Stack->top;
	Data_Stack->top = P;
	Data_Stack->count ++;
	return OK;
}


/*
****************************************************************
* 函数名：Data_Stack_link_Print
* 功  能：从链栈中输出所有的数据
* 形  参：Data_Stack_Link Data_Stack：要访问的链栈
* 返回值：OK or ERROR
****************************************************************
*/
Status Data_Stack_link_Print(Data_Stack_Link Data_Stack)
{
    SLinkedNode P;
	P = (SLinkedNode)malloc(sizeof(Snode));    
	P = Data_Stack.top;
	printf("The Data Stack List Element is :\n");
	while(NULL != P)
	{
		printf("%d\n",P->data);
		P = P->next;
	}
	return OK;
}


/*
*************************************************************************
* 函数名：Data_Stack_link_Pop
* 功  能：从已有链栈中弹出一个值
* 形  参：Data_Stack_Link *Data_Stack：已有的链栈
          DSElemtype *value：用于存储从栈中弹出的元素
* 返回值：OK or ERROR
*************************************************************************
*/
int Data_Stack_link_Pop(Data_Stack_Link *Data_Stack)
{
	DSElemtype value;
	SLinkedNode P;
	P = (SLinkedNode)malloc(sizeof(Snode));    
	P = Data_Stack->top;
	value = P->data;
	Data_Stack->top = P->next;
	free(P);
#if UnDebug
	printf("The Pop value is :%d\n",value);
#endif
	return value;
}


/*
***************************************************************
* 函数名：Clear_Data_Stack_Link
* 功  能：释放掉数据链栈
* 形  参：Data_Stack_Link *Data_Stack:要释放的链栈
* 返回值：OK or ERROR
***************************************************************
*/
Status Clear_Data_Stack_Link(Data_Stack_Link *Data_Stack)
{
    SLinkedNode P,Q;
	P = (SLinkedNode)malloc(sizeof(Snode));
    Q = (SLinkedNode)malloc(sizeof(Snode));
	P = Data_Stack->top;
	while(NULL != P)
	{
		Q = P->next;
		free(P);
		P = Q;
	}
	Data_Stack->top = NULL;
	return OK;
}