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
****************************************************
* ��������Linked_List_Init
* ��  �ܣ���ʼ������
* ��  �Σ�Linked_List *List
* ����ֵ��OK or ERROR
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
* ��������Linked_List_Incert
* ��  �ܣ����á�β�巨���������в���Ԫ��
* ��  �Σ�Linked_List *List���������
          DElemType value  ��Ҫ�������ֵ
		  OpElemType op    ��Ҫ����������
		  Type             :Ϊ1ʱ����ʾҪ���������ֵ
		                    Ϊ0ʱ����ʾҪ������������
* ����ֵ��OK or ERROR
*************************************************************
*/
Status Linked_List_Incert(Linked_List *List,DElemType value,OpElemType op,Incert_Type Type)
{
    LinkedNode P;
    static LinkedNode Q;
	static unsigned char count = 0;

	if(!count)
	{
		/*Ϊͷ�������ڴ棬ͷָ��ָ��ĵ�һ����㲻�������*/
		/*ͷ���Ĵ�����Ϊ��ʹ��һ�����Ĳ���������λ�õĽ����뷽��һ��*/
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
	List->count ++;/*ÿ����һ��Ԫ�أ�count++�����ڼ�¼����ĳ���*/
	return OK;
}



/*
***********************************************************
* ��������Linked_List_Show
* ��  �ܣ��������е����Լ���������
* ��  �Σ�Linked_List List�����е�����
* ����ֵ��OK or ERROR
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
* ��������Length_Linked_List
* ��  �ܣ���������ĳ���
* ��  �Σ�Linked_List List�����е�����
* ����ֵ������ĳ���
***********************************************************
*/
int Length_Linked_List(Linked_List List)
{
	return List.count;
}


/*
************************************************************
* ��������GetElem_Linked_List
* ��  �ܣ��������ָ��λ�û�ȡһ��Ԫ��
* ��  �Σ�Linked_List List�����е�����
          int position��    ���ҵ�λ��
		  DElemType *value���洢�ҵ���ֵ
		  OpElemType *op��  �洢�ҵ��Ĳ�����
* ����ֵ��������״̬
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