/********************************************************
 * - Project name : MyOperateSystem
 * - Filename : main.cpp
 * - Author : ����
 * - Version : 1.0
 * - Start date : 2018/6/26
 * - Description : 2018�ļ�ѧ�ڲ���ϵͳʵѵ-������ʵ�����
 * - Others : ʯ��ׯ������ѧ��Ϣ��ѧ�뼼��ѧԺ
			  �������ѧ�뼼��ϵ
			  �༶ - ��1501-1
			  ѧ�� - 20153178
 * - Function list : main
				     PRINT_DEFAULT_PANEL
 * - History : [����]2018/6/26��һ���޸ģ�������Ŀ
			   [����]2018/6/28�ڶ����޸ģ���Ӵ洢����ģ��
 ********************************************************/




/****************************
		  �ļ�����
****************************/
#include "head.h"




/****************************
		  ��������
****************************/
void PRINT_DEFAULT_PANEL();




/************************************
* Function name : main
* Description : ������
* Variables : void
************************************/
void main(){

	// ѭ������
	while (1){

		// ��ʾ������
		PRINT_DEFAULT_PANEL();

		// ����ѡ��
		string choise = "";   // ָ��
		cin >> choise;

		// ����ָ���ת
		if (choise == "1"){
			// ���̹���
			MAIN_PROCESS_MANAGE();
		}
		else if (choise == "2"){
			// �豸����
			MAIN_EQUIPMENT_MANAGE();
		}
		else if (choise == "3"){
			// �ļ�����
			MAIN_FILE_MANAGE();
		}
		else if (choise == "4"){
			// �洢����
			MAIN_MEMORY_MANAGE();
		}

	} // while

}





/************************************
* Function name : PRINT_DEFAULT_PANEL
* Description : ��ʾ������
* Variables : void
************************************/
void PRINT_DEFAULT_PANEL(){

	// ����
	system("cls");

	// ��ӡ����
	printf("****************************************\n\n");
	printf("             ģ�����ϵͳ          \n\n");
	printf("****************************************\n\n");

	// ��ӡѡ��
	printf("[1]���̹���\t[2]�豸����\n[3]�ļ�����\t[4]�洢����\n> ");

}