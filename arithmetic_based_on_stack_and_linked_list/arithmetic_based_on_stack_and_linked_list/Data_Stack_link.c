/*
******************************************************
* �ļ�����config.h
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/19
* ��  ����v1.0
*****************************************************
*/

#include "config.h"

/*
**************************************************************
* ��������Data_Stack_Link_Init
* ��  �ܣ���ʼ����ջ
* ��  �Σ�Data_Stack_Link *DS
* ����ֵ������״̬
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
* ��������Data_Stack_link_Push
* ��  �ܣ�����ջ��ѹ������
* ��  �Σ�Data_Stack_Link *Data_Stack�����е���ջ
          DSElemtype value��           Ҫѹ���ֵ
* ����ֵ��OK or ERROR
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
* ��������Data_Stack_link_Print
* ��  �ܣ�����ջ��������е�����
* ��  �Σ�Data_Stack_Link Data_Stack��Ҫ���ʵ���ջ
* ����ֵ��OK or ERROR
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
* ��������Data_Stack_link_Pop
* ��  �ܣ���������ջ�е���һ��ֵ
* ��  �Σ�Data_Stack_Link *Data_Stack�����е���ջ
          DSElemtype *value�����ڴ洢��ջ�е�����Ԫ��
* ����ֵ��OK or ERROR
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
* ��������Clear_Data_Stack_Link
* ��  �ܣ��ͷŵ�������ջ
* ��  �Σ�Data_Stack_Link *Data_Stack:Ҫ�ͷŵ���ջ
* ����ֵ��OK or ERROR
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