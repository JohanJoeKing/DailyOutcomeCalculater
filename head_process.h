/********************************************************
* - Project name : MyOperateSystem
* - Filename : head_process.h
* - Author : ����
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : ���̹���ͷ�ļ�
* - Others : ʯ��ׯ������ѧ��Ϣ��ѧ�뼼��ѧԺ
			 �������ѧ�뼼��ϵ
			 �༶ - ��1501-1
			 ѧ�� - 20153178
* - Function list : producer
					consumer
					PROCESS_PRINT_DEFAULT_PANEL
					PRODUCER_CONSUMER_DEMO
					PROCESS_DEMO
					PROCESS_DEMO_LOOP
					PROCESS_DEMO_INIT
					PROCESS_DEMO_PRINT
					insertIntoReady
					insertIntoFinish
					showQueue
					rebuildQueue
					getInCPU
					CPU_OPERATE
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
#include <thread>
#include <windows.h>



/****************************
		  �ṹ��
****************************/
typedef struct pcb{
	int name;      // ������
	int prio;      // ������
	int arrive;    // ����ʱ��
	int needtime;  // ��Ҫ����ʱ��
	int cputime;   // ����CPUʱ��
	int finishtime;// ����ʱ��
	int state;     // ����״̬
	pcb *next;     // nextָ��
}PCB;



/****************************
		 ȫ�ֱ���
****************************/
const int BUF_MAX = 8;     // ������������Ϊ8
int products = 5;          // ���Բ�Ʒ����Ϊ5
int PRODUCE_TIMES = 20;    // ������ʾʱ��
const int PRO_READY = 0;   // ����̬
const int PRO_RUN = 1;     // ����̬
const int PRO_FINISH = 2;  // ���̬
PCB *ready;   // ��������
PCB *run;     // ִ��ָ��
PCB *finish;  // ��ɶ���
const int DEMO_PROCESS = 5;  // ��ʾ��������
const int PRIO_WEIGHT = 50;  // ���ȼ�ȷ�����
const int NEEDTIME_INTERVAL = 2;   // Ĭ������ʱ����
int TIME = 0;    // ʱ��Ƭ

string PROCESS_ALGORITHM;  // �����㷨
const string HRRN = "1";   // �����Ӧ���㷨
const string SSTF = "2";   // ����ҵ�����㷨
const string HPFS = "3";   // �����ȼ������㷨





/****************************
		 ��������
****************************/
void producer();
void consumer();
void PROCESS_PRINT_DEFAULT_PANEL();
void PRODUCER_CONSUMER_DEMO();
void PROCESS_DEMO();
void PROCESS_DEMO_LOOP();
void PROCESS_DEMO_INIT();
void PROCESS_DEMO_PRINT();
void insertIntoReady(PCB *p);
void insertIntoFinish(PCB *p);
void showQueue(PCB *p);
void rebuildQueue();
void rebuildQueueByTime();
void rebuildQueueHRRN();
void getInCPU();
void CPU_OPERATE();