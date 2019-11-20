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
****************************************************
* 函数名：Linked_List_Init
* 功  能：初始化链表
* 形  参：Linked_List *List
* 返回值：OK or ERROR
****************************************************
*/
Status Linked_List_Init(Linked_List *List)
{
	List->head = (LinkedNode)malloc(sizeof(Node));
	List->head = NULL;
	List->count = 0;
	return OK;
}

/*
************************************************************
* 函数名：Linked_List_Incert
* 功  能：利用“尾插法”往链表中插入元素
* 形  参：Linked_List *List：链表对象
          DElemType value  ：要插入的数值
		  OpElemType op    ：要插入的运算符
		  Type             :为1时，表示要插入的是数值
		                    为0时，表示要插入的是运算符
* 返回值：OK or ERROR
*************************************************************
*/
Status Linked_List_Incert(Linked_List *List,DElemType value,OpElemType op,Incert_Type Type)
{
    LinkedNode P;
    static LinkedNode Q;
	static unsigned char count = 0;

	if(!count)
	{
		/*为头结点分配内存，头指针指向的第一个结点不存放数据*/
		/*头结点的存在是为了使第一个结点的插入与其他位置的结点插入方法一致*/
		List->head = (LinkedNode)malloc(sizeof(Node));
		List->count = 0;
		Q = (LinkedNode)malloc(sizeof(Node));
		Q = List->head;
		count ++;
	} 
	P = (LinkedNode)malloc(sizeof(Node)); 
	if(Type)
	{
		P->data = value;
		P->valid = 1; 
	}
	else
	{
		P->op = op;
		P->valid = 0;
	}
	Q->next = P;
	P->next = NULL;
	Q = P;
	List->count ++;/*每插入一个元素，count++，用于记录链表的长度*/
	return OK;
}



/*
***********************************************************
* 函数名：Linked_List_Show
* 功  能：将链表中的数以及运算符输出
* 形  参：Linked_List List：已有的链表
* 返回值：OK or ERROR
***********************************************************
*/
Status Linked_List_Show(Linked_List List)
{
    LinkedNode P;
    P = (LinkedNode)malloc(sizeof(Node));
	P = List.head->next;
	printf("The Linked List Element is:\n");
	while(NULL != P)
	{
		if(P->valid)
		{
			printf("%d ",P->data);
		}
		else 
		{
			printf("%c ",P->op);
		}
		P = P->next;
	}
	return OK;
}

/*
***********************************************************
* 函数名：Length_Linked_List
* 功  能：返回链表的长度
* 形  参：Linked_List List：已有的链表
* 返回值：链表的长度
***********************************************************
*/
int Length_Linked_List(Linked_List List)
{
	return List.count;
}


/*
************************************************************
* 函数名：GetElem_Linked_List
* 功  能：从链表的指定位置获取一个元素
* 形  参：Linked_List List：已有的链表
          int position：    查找的位置
		  DElemType *value：存储找到的值
		  OpElemType *op：  存储找到的操作符
* 返回值：操作的状态
************************************************************
*/
Status GetElem_Linked_List(Linked_List List,int position,DElemType *value,OpElemType *op)
{
    LinkedNode P;
	int i;
	P = (LinkedNode)malloc(sizeof(Node));
	P = List.head;
	for(i = 0;i < position;i++)
	{
		P = P->next;
	}
	if(P->valid)
	{
		*value = P->data;
	}
	else
	{
		*op = P->op;
	}
	return OK;
}