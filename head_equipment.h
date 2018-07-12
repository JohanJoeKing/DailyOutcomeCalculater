/********************************************************
* - Project name : MyOperateSystem
* - Filename : head_equipment.h
* - Author : ����
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : �豸����ͷ�ļ�
* - Others : ʯ��ׯ������ѧ��Ϣ��ѧ�뼼��ѧԺ
			 �������ѧ�뼼��ϵ
			 �༶ - ��1501-1
			 ѧ�� - 20153178
* - Function list : EQUIPMENT_PRINT_DEFAULT_PANEL
					EQUIPMENT_INIT
					EQUIPMENT_USER_SET
					EQUIPMENT_START
					EQUIPMENT_LOOP
					EQUIPMENT_ALGORITHM
					changeData
					returnBackData
					checkSecurity
********************************************************/



/************************************
* Function name :
* Description :
* Variables :
************************************/



/****************************
		 Ԥ����ָ��
****************************/

#pragma once

#include "head.h"




/****************************
		 ȫ�ֱ���
****************************/
const int PROCESS = 5;    // ��������
const int RESOURCES = 3;  // ��Դ����
int **MAX;       // ���̶���Դ�����������
int *AVAILABLE;  // ϵͳ������Դ����
int **ALLOCATION;// �����ѵõ�����Դ����
int **NEED;      // ���̻���Ҫ����Դ����
int process;     // ��������Ľ���
int *REQUEST;    // ��������



/****************************
		 ��������
****************************/
void EQUIPMENT_PRINT_DEFAULT_PANEL();
void EQUIPMENT_INIT();
void EQUIPMENT_USER_SET();
void EQUIPMENT_START();
void EQUIPMENT_LOOP();
void EQUIPMENT_ALGORITHM();
void changeData();
void returnBackData();
bool checkSecurity();