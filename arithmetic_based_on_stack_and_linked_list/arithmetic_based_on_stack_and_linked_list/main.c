/*
******************************************************
* 文件名：config.h
* 作  者：wenzi
* 日  期：2019/11/19
* 版  本：v1.0
*****************************************************
*/

#include "config.h"

Data_Stack_Link Data_Stack;
Op_Stack_Link Op_Stack;
Linked_List List;

int main(void)
{
#if 1
	char ch1,ch2;
	char str[20];
	int result;

	ch1 = '*';
	ch2 = '-';
#if UnDebug
	DSElemtype value;
	char c,b;
	c = getchar();
#endif
    Data_Stack_Link_Init(&Data_Stack);
#if UnDebug
	Data_Stack_link_Push(&Data_Stack,5);
	Data_Stack_link_Push(&Data_Stack,6);
	Data_Stack_link_Print(Data_Stack);
	Clear_Data_Stack_Link(&Data_Stack);
	Data_Stack_link_Print(Data_Stack);
	Data_Stack_link_Pop(&Data_Stack,&value);
	Data_Stack_link_Print(Data_Stack);
#endif
	gets(str);
	////puts(str);
	//Op_Stack_Link_Init(&Op_Stack);
	//Op_Stack_link_Push(&Op_Stack,c);
	//Op_Stack_link_Print(Op_Stack);	
    
	//Linked_List_Init(&List);
	//Linked_List_Incert(&List,5,0,1);
	//Linked_List_Incert(&List,6,0,1);  
	//Linked_List_Incert(&List,0,'(',0);
	Cen_Trans_Back(str,&Op_Stack,&List);
#if UnDebug
	Linked_List_Show(List);
#endif
	result = Ex_Calculate(&List,&Data_Stack);
	printf("The Final Result is:%d",result);
#endif

	//result = Prio_Judg(ch1,ch2);
	//printf("%d\n",result);
}  