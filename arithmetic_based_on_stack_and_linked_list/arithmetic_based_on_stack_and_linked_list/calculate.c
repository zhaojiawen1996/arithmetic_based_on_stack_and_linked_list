/*
********************************************************
* 文件名：calculate.c
* 作  者：wenzi
* 日  期：2019/11/19
* 版  本：V1.0
********************************************************
*/

#include "config.h"

/*
*******************************************************
* 函数名：Prio_Judg
* 功  能：判断op1和op2优先级的大小
* 形  参：op1 > op2时，输出1
          op1 < op2时，输出0
* 返回值：1 or 0
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
			/*虽然括号的优先级是最大的，但是这里设置为最低是为了避免当操作符入栈时*/
			/*括号处于栈顶，从而导致元素全部出栈*/
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
* 函数名：Cen_Trans_Back
* 功  能：将中缀表达式转换为后缀表达式
* 形  参：char *str：              要转换的中缀表达式
          Op_Stack_Link *Op_Stack: 存储运算符的链栈
		  Linked_List *List：      存储后缀表达式的链表
* 备  注：中缀表达式转换为后缀表达式：
         （1）遇到数字时，插入链表
		 （2）遇到括号时，压入堆栈
		 （3）当当前堆栈为空时，遇到符号，压入堆栈
		 （4）当当前堆栈不为空，且遇到由括号，全部出栈且插入链表
		  (5) 当当前堆栈不为空，且遇到符号，符号优先级大于等于栈顶符号时，压栈
		 （6）当当前堆栈不为空，且遇到符号，符号优先级小于栈顶符号，全部栈插入链表，并将当前符号压栈
		 （7）当当前字符串遍历结束，将堆栈中的符号全部弹出，并依次插入链表
* 返回值：OK or ERROR
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
		        num = num * 10 + (*P - '0')*1;/*将字符串转换成十进制数*/
			    P ++;			    
			}
			Linked_List_Incert(List,num,OPNONE,DATA);
			num = 0;/*压栈一次后必须归零*/
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
* 函数名：Tw_Calculate
* 功  能：计算两数之和
* 形  参：int F_Value：第一次出栈的数
          int B_Value：第二次出栈的数
		  char op：    操作符
* 返回值：计算的结果
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
* 函数名：Ex_Calculate
* 功  能：表达式计算求值，遍历链表，运用后缀表达式求值
* 形  参：Linked_List *List：         已有的链表
          Data_Stack_Link *Data_Stack：用于临时存放数据的数据栈
* 返回值：最终计算的值
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