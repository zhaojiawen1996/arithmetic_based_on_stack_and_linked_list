/*
******************************************************
* 文件名：config.h
* 作  者：wenzi
* 日  期：2019/11/19
* 版  本：v1.0
*****************************************************
*/

#ifndef __CONFIG_H__
#define __CONFIG_H__


#define  OK          1
#define  ERROR       0

#define  DATA        1/*表示数据*/
#define  OP          0/*表示运算符*/

#define  OPNONE      0/*表示不插入操作符*/
#define  DATANONE    0/*表示不插入数据*/

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