/*
******************************************************
* �ļ�����config.h
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/19
* ��  ����v1.0
*****************************************************
*/

#ifndef __CALCULATE_H__
#define __CALCULATE_H__

Result Prio_Judg(OpSElemtype op1,OpSElemtype op2);

Status Cen_Trans_Back(char *str,Op_Stack_Link *Op_Stack,Linked_List *List);
int Ex_Calculate(Linked_List *List,Data_Stack_Link *Data_Stack);


#endif