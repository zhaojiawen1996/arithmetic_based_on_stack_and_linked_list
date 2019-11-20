/*
********************************************************
* �ļ�����calculate.c
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/19
* ��  ����V1.0
********************************************************
*/

#include "config.h"

/*
*******************************************************
* ��������Prio_Judg
* ��  �ܣ��ж�op1��op2���ȼ��Ĵ�С
* ��  �Σ�op1 > op2ʱ�����1
          op1 < op2ʱ�����0
* ����ֵ��1 or 0
*******************************************************
*/
Result Prio_Judg(OpSElemtype op1,OpSElemtype op2)
{
	OpSElemtype Temp;
	int count = 0;
	Temp = op1;
	while(count < 2)
	{
	    switch(Temp)
		{
			/*��Ȼ���ŵ����ȼ������ģ�������������Ϊ�����Ϊ�˱��⵱��������ջʱ*/
			/*���Ŵ���ջ�����Ӷ�����Ԫ��ȫ����ջ*/
			case '(':Temp = 0;break;
		    case '+':
			case '-':Temp = 1;break;
			case '*':
			case '/':Temp = 2;break;
		}
		if(!count)
		{
		    op1 = Temp;
		}
		else
		{
			op2 = Temp;
		}
		Temp = op2;
		count ++;
	}
	return (op1 >= op2);
}



/*
******************************************************************************************************
* ��������Cen_Trans_Back
* ��  �ܣ�����׺���ʽת��Ϊ��׺���ʽ
* ��  �Σ�char *str��              Ҫת������׺���ʽ
          Op_Stack_Link *Op_Stack: �洢���������ջ
		  Linked_List *List��      �洢��׺���ʽ������
* ��  ע����׺���ʽת��Ϊ��׺���ʽ��
         ��1����������ʱ����������
		 ��2����������ʱ��ѹ���ջ
		 ��3������ǰ��ջΪ��ʱ���������ţ�ѹ���ջ
		 ��4������ǰ��ջ��Ϊ�գ������������ţ�ȫ����ջ�Ҳ�������
		  (5) ����ǰ��ջ��Ϊ�գ����������ţ��������ȼ����ڵ���ջ������ʱ��ѹջ
		 ��6������ǰ��ջ��Ϊ�գ����������ţ��������ȼ�С��ջ�����ţ�ȫ��ջ��������������ǰ����ѹջ
		 ��7������ǰ�ַ�����������������ջ�еķ���ȫ�������������β�������
* ����ֵ��OK or ERROR
******************************************************************************************************
*/
Status Cen_Trans_Back(char *str,Op_Stack_Link *Op_Stack,Linked_List *List)
{
    char *P;
	OpSElemtype ch = 0;
	int num = 0;
	P = str;

	while(*P)
	{
	    if(*P >= '0' && *P <= '9')
		{
			while(*P >= '0' && *P <= '9')
			{
		        num = num * 10 + (*P - '0')*1;/*���ַ���ת����ʮ������*/
			    P ++;			    
			}
			Linked_List_Incert(List,num,OPNONE,DATA);
			num = 0;/*ѹջһ�κ�������*/
#if UnDebug
			Linked_List_Show(*List);
#endif
		}
		else
		{
			if(IS_Stack_Empty(*Op_Stack) || *P == '(')
			{
			    Op_Stack_link_Push(Op_Stack,*P);
				P ++;
			}
			else if(!IS_Stack_Empty(*Op_Stack) && *P == ')')
			{
				while(1)
				{   
					ch = Op_Stack_link_Pop(Op_Stack);
					if(IS_Stack_Empty(*Op_Stack) ||'(' == ch)/*IS_Stack_Empty(*Op_Stack) ||*/
					{
					    break;
					}
					Linked_List_Incert(List,DATANONE,ch,OP);
				}
				P ++;
			}
			else
			{
                 if(Prio_Judg(*P,Op_Stack->top->op))
				 {
				      Op_Stack_link_Push(Op_Stack,*P);
					  P ++;
				 }
				 else
				 {
					while(!IS_Stack_Empty(*Op_Stack))
					{
				        ch = Op_Stack_link_Pop(Op_Stack);
					    Linked_List_Incert(List,DATANONE,ch,OP);					
					}
					Op_Stack_link_Push(Op_Stack,*P);
					P ++;
				 }
			}
		}
	}
	while(!IS_Stack_Empty(*Op_Stack))
	{
	    ch = Op_Stack_link_Pop(Op_Stack);
	    Linked_List_Incert(List,DATANONE,ch,OP); 
	}
	return OK;
}

/*
***************************************************************
* ��������Tw_Calculate
* ��  �ܣ���������֮��
* ��  �Σ�int F_Value����һ�γ�ջ����
          int B_Value���ڶ��γ�ջ����
		  char op��    ������
* ����ֵ������Ľ��
**************************************************************
*/
static int Tw_Calculate(int F_Value,int B_Value,char op)
{
	int Temp;
	switch (op)
	{
	     case '+':Temp = B_Value + F_Value;break;
		 case '-':Temp = B_Value - F_Value;break;
		 case '*':Temp = B_Value * F_Value;break;
		 case '/':Temp = B_Value / F_Value;break;
	}
	return Temp;
}


/*
********************************************************************
* ��������Ex_Calculate
* ��  �ܣ����ʽ������ֵ�������������ú�׺���ʽ��ֵ
* ��  �Σ�Linked_List *List��         ���е�����
          Data_Stack_Link *Data_Stack��������ʱ������ݵ�����ջ
* ����ֵ�����ռ����ֵ
********************************************************************
*/
int Ex_Calculate(Linked_List *List,Data_Stack_Link *Data_Stack)
{
	unsigned char i;
	LinkedNode P;
	int F_Value,B_Value;
	int Temp,Result;

	P = (LinkedNode)malloc(sizeof(Node));
	P = List->head;
	for(i = 0;i < List->count;i++)
	{
		P = P->next;
		if(P->valid)
		{
			Data_Stack_link_Push(Data_Stack,P->data);
		}
		else
		{
		    F_Value = Data_Stack_link_Pop(Data_Stack);    
			B_Value = Data_Stack_link_Pop(Data_Stack);
			Temp = Tw_Calculate(F_Value,B_Value,P->op);
			Data_Stack_link_Push(Data_Stack,Temp);
		}
	}

	Result = Data_Stack_link_Pop(Data_Stack);
	return Result; 
}