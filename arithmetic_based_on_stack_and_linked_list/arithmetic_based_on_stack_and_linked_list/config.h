/*
******************************************************
* �ļ�����config.h
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/19
* ��  ����v1.0
*****************************************************
*/

#ifndef __CONFIG_H__
#define __CONFIG_H__


#define  OK          1
#define  ERROR       0

#define  DATA        1/*��ʾ����*/
#define  OP          0/*��ʾ�����*/

#define  OPNONE      0/*��ʾ�����������*/
#define  DATANONE    0/*��ʾ����������*/

#define  Debug       1
#define  UnDebug     0

typedef unsigned char Status;
typedef unsigned char Incert_Type;
typedef unsigned char Empty;
typedef unsigned char Result;

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Data_Stack_link.h"
#include "Oper_Stack_link.h"
#include "Linked_List.h"
#include "calculate.h"


#endif