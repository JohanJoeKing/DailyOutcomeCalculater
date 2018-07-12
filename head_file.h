/********************************************************
* - Project name : MyOperateSystem
* - Filename : head_file.h
* - Author : ����
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : �ļ�����ͷ�ļ�
* - Others : ʯ��ׯ������ѧ��Ϣ��ѧ�뼼��ѧԺ
			 �������ѧ�뼼��ϵ
			 �༶ - ��1501-1
			 ѧ�� - 20153178
* - Function list : FILE_PRINT_DEFAULT_PANEL
					GENERATE_DISKS
					SET_CURRENT_DISK
					FILE_FCFS
					FILE_SSTF
					FILE_SCAN
					FILE_C_SCAN
					SEARCH_SUMMARY
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
#include <cstdlib>
#include <ctime>
#include <cmath>




/****************************
		 ȫ�ֱ���
****************************/
int FILE_ALGORITHM;    // �����㷨
const int FCFS = 1;    // �����ȷ����㷨
const int SSTF = 2;    // ���Ѱ��ʱ�������㷨
const int SCAN = 3;    // ɨ���㷨
const int C_SCAN = 4;  // ѭ��ɨ���㷨
const int MAX_DISK = 200;   // ���ŵ�
const int VISITS = 10;      // ���ʴŵ�����
int curDisk = 0;            // ��ǰ���ڴŵ�
int *disk;                  // �ŵ�����˳��
int direction;              // ��ǰ�����ƶ�����
int search_times = 0;       // ��Ѱ������
double average_times = 0;   // ƽ��Ѱ������




/****************************
		 ��������
****************************/
void FILE_PRINT_DEFAULT_PANEL();
void GENERATE_DISKS();
void SET_CURRENT_DISK();
void FILE_FCFS();
void FILE_SSTF();
void FILE_SCAN();
void FILE_C_SCAN();
void SEARCH_SUMMARY();