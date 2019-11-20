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
* ��������Op_Stack_Link_Init
* ��  �ܣ���ʼ����ջ
* ��  �Σ�Op_Stack_Link *Op_Stack
* ����ֵ������״̬
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
* ��������Op_Stack_link_Push
* ��  ��: ѹ��һ��Ԫ�ص���ջ
* ��  �Σ�Op_Stack_Link *Op_Stack
* ����ֵ������״̬
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
* ��������Op_Stack_link_Print
* ��  �ܣ�����ջ��������е�Ԫ��
* ��  �Σ�Op_Stack_Link Op_Stack�������Ķ���
* ����ֵ��OK or ERROR
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
* ��������Op_Stack_link_Pop
* ��  �ܣ�����ջ�е���һ��Ԫ��
* ��  �Σ�Op_Stack_Link *Op_Stack��Ҫ��������ջ
          OpSElemtype *op:         ���ڴ洢������ı���
* ����ֵ��OpSElemtype:pop����Ԫ��
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
* ��������Clear_Op_Stack_Link
* ��  �ܣ��ͷ���ջ�е�Ԫ��
* ��  �Σ�Op_Stack_Link *Op_Stack��Ҫ�ͷŵ���ջ
* ����ֵ��OK or ERROR
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
* ��������IS_Stack_Empty
* ��  �ܣ��жϵ�ǰ����ջ�Ƿ��ǿ�ջ
          ��ջ��   ����1
		  �ǿ�ջ ������0
* ��  �Σ�Op_Stack_Link Op_Stack����ǰ����ջ
* ����ֵ��0 or 1
*********************************************************
*/
Empty IS_Stack_Empty(Op_Stack_Link Op_Stack)
{
	return (NULL == Op_Stack.top);
}