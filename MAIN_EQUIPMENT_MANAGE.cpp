/********************************************************
* - Project name : MyOperateSystem
* - Filename : MAIN_EQUIPMENT_MANAGE.cpp
* - Author : ����
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : �豸����
* - Others : ʯ��ׯ������ѧ��Ϣ��ѧ�뼼��ѧԺ
			 �������ѧ�뼼��ϵ
			 �༶ - ��1501-1
			 ѧ�� - 20153178
* - Function list :
* - History : [����]2018/6/29��һ���޸ģ�����ʵ���˰�ȫ���㷨
********************************************************/



/****************************
		 �ļ�����
****************************/
#include "head_equipment.h"




/****************************
		 ��������
****************************/




/************************************
* Function name : MAIN_EQUIPMENT_MANAGE
* Description : �豸����������
* Variables : void
************************************/
void MAIN_EQUIPMENT_MANAGE(){

	// ϵͳ������ʼ��
	EQUIPMENT_INIT();

	// ָ����Դ���������������
	EQUIPMENT_USER_SET();

	// ��ӡ������
	EQUIPMENT_PRINT_DEFAULT_PANEL();

	// ��ʾ����ʼ
	EQUIPMENT_START();

}




/************************************
* Function name : EQUIPMENT_PRINT_DEFAULT_PANEL
* Description : ��ʾ������
* Variables : void
************************************/
void EQUIPMENT_PRINT_DEFAULT_PANEL(){

	// ����
	system("cls");

	// ��ӡ����
	// ��ӡ����
	printf("****************************************\n\n");
	printf("             �豸������          \n\n");
	printf("****************************************\n\n");
}





/************************************
* Function name : EQUIPMENT_INIT
* Description : ��ʼ��
* Variables : void
************************************/
void EQUIPMENT_INIT(){

	// ��ʼ��MAX
	MAX = new int*[PROCESS];
	for (int i = 0; i < PROCESS; i++){
		MAX[i] = new int[RESOURCES];
	}

	// ��ʼ��AVAILABLE
	AVAILABLE = new int[RESOURCES];

	// ��ʼ��ALLOCATION
	ALLOCATION = new int*[PROCESS];
	for (int i = 0; i < PROCESS; i++){
		ALLOCATION[i] = new int[RESOURCES];
	}

	// ��ʼ��NEED
	NEED = new int*[PROCESS];
	for (int i = 0; i < PROCESS; i++){
		NEED[i] = new int[RESOURCES];
	}

	// ��ʼ����������
	REQUEST = new int[RESOURCES];

	// ��ʼ����ֵ
	for (int i = 0; i < PROCESS; i++){
		for (int j = 0; j < RESOURCES; j++){
			MAX[i][j] = 0;
			ALLOCATION[i][j] = 0;
			NEED[i][j] = 0;
		}
	}
	for (int i = 0; i < RESOURCES; i++){
		AVAILABLE[i] = 0;
		REQUEST[i] = 0;
	}

}





/************************************
* Function name : EQUIPMENT_USER_SET
* Description : �û�ָ����ֵ
* Variables : void
************************************/
void EQUIPMENT_USER_SET(){

	// �趨��Դ�����ֱ�Ϊ9,8,7
	AVAILABLE[0] = 3;
	AVAILABLE[1] = 3;
	AVAILABLE[2] = 2;

	// �趨�������������
	MAX[0][0] = 7;
	MAX[0][1] = 5;
	MAX[0][2] = 3;

	MAX[1][0] = 3;
	MAX[1][1] = 2;
	MAX[1][2] = 2;

	MAX[2][0] = 9;
	MAX[2][1] = 0;
	MAX[2][2] = 2;

	MAX[3][0] = 2;
	MAX[3][1] = 2;
	MAX[3][2] = 2;

	MAX[4][0] = 4;
	MAX[4][1] = 3;
	MAX[4][2] = 3;

	// ���õ�ǰALLOCATION
	ALLOCATION[0][0] = 0;
	ALLOCATION[0][1] = 1;
	ALLOCATION[0][2] = 0;

	ALLOCATION[1][0] = 2;
	ALLOCATION[1][1] = 0;
	ALLOCATION[1][2] = 0;

	ALLOCATION[2][0] = 3;
	ALLOCATION[2][1] = 0;
	ALLOCATION[2][2] = 2;

	ALLOCATION[3][0] = 2;
	ALLOCATION[3][1] = 1;
	ALLOCATION[3][2] = 1;

	ALLOCATION[4][0] = 0;
	ALLOCATION[4][1] = 0;
	ALLOCATION[4][2] = 2;

}





/************************************
* Function name : EQUIPMENT_START
* Description : ��ʾ����ʼ
* Variables : void
************************************/
void EQUIPMENT_START(){

	// ��ӡ��Դ����
	printf("������Դ������\n");
	for (int i = 0; i < RESOURCES; i++){
		printf("%3d", AVAILABLE[i]);
	}
	printf("\n\n");

	// ��ӡ���������������
	printf("�����������Դ��������\n");
	for (int i = 0; i < PROCESS; i++){
		for (int j = 0; j < RESOURCES; j++){
			printf("%3d", MAX[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	// ��ʾ��ʼ
	printf("������Կ�ʼ...\n");
	string aaa;
	cin >> aaa;

	// ��ʼ������Դ
	system("cls");
	EQUIPMENT_LOOP();

}





/************************************
* Function name : EQUIPMENT_LOOP
* Description : ��ʾ����ʼ
* Variables : void
************************************/
void EQUIPMENT_LOOP(){

	//while (1){

		// ǰ��ָ���
		printf("###############################################\n");

		// ����Need����
		int i, j;
		for (i = 0; i < PROCESS; i++){
			for (j = 0; j < RESOURCES; j++){
				NEED[i][j] = MAX[i][j] - ALLOCATION[i][j];
			}
		}

		// ��ʾMAX����
		printf("Max\n");
		for (i = 0; i < PROCESS; i++){
			for (j = 0; j < RESOURCES; j++){
				printf("%3d", MAX[i][j]);
			}
			printf("\n");
		}

		// ��ʾALLOCATION����
		printf("Allocation\n");
		for (i = 0; i < PROCESS; i++){
			for (j = 0; j < RESOURCES; j++){
				printf("%3d", ALLOCATION[i][j]);
			}
			printf("\n");
		}

		// ��ʾNEED����
		printf("Need\n");
		for (i = 0; i < PROCESS; i++){
			for (j = 0; j < RESOURCES; j++){
				printf("%3d", NEED[i][j]);
			}
			printf("\n");
		}

		// ��ʾAVAILABLE����
		printf("Available\n");
		for (i = 0; i < RESOURCES; i++){
			printf("%3d", AVAILABLE[i]);
		}
		printf("\n\n");

		// ������������
		printf("����������̣�");
		cin >> process;
		printf("��������������");
		for (i = 0; i < RESOURCES; i++){
			cin >> REQUEST[i];
		}
		printf("\n");

		// ���м��㷨
		EQUIPMENT_ALGORITHM();

		// ���ָ���
		//printf("###############################################\n");
		printf("������Լ���...\n");
		string aaa;
		cin >> aaa;

	//} // while

}




/************************************
* Function name : EQUIPMENT_ALGORITHM
* Description : ���м��㷨
* Variables : void
************************************/
void EQUIPMENT_ALGORITHM(){

	// request�Ƿ�С��need
	bool flag = true;
	int i, j;
	for (i = 0; i < RESOURCES; i++){
		if (REQUEST[i] > NEED[process][i]){
			flag = false;
			break;
		}
	}
	if (flag){

		// request������need���Ƚ�available
		bool flag2 = true;
		for (i = 0; i < RESOURCES; i++){
			if (REQUEST[i] > AVAILABLE[i]){
				flag2 = false;
				break;
			}
		}
		if (flag2){

			// request������available�����Է���
			changeData();

			// ��ȫ�Լ��
			if (!checkSecurity()){
				// �����䲻��ȫ
				returnBackData();       // �ع�����
				printf("���䲻��ȫ\n"); // ��ʾ
			}
			else{
				// �����䰲ȫ����ȫ�������ڱ������֮ǰ��ʾ
				printf("�ʷ��䰲ȫ\n");
			}

		}

		else{

			// request����available�����ܷ���
			printf("Request����Available�����ܷ���\n");
			return;

		}


	} // if

	else{

		// request����need���쳣�˳�
		printf("Request����Need���������\n");
		return;

	} // else

}





/************************************
* Function name : changeData
* Description : ���Է���
* Variables : int process
************************************/
void changeData(){

	// ������Դ
	for (int i = 0; i < RESOURCES; i++){
		AVAILABLE[i] -= REQUEST[i];
		ALLOCATION[process][i] += REQUEST[i];
		NEED[process][i] -= REQUEST[i];
	}

}





/************************************
* Function name : returnBackData
* Description : �ع�����
* Variables : int process
************************************/
void returnBackData(){

	// �ع�����
	for (int i = 0; i < RESOURCES; i++){
		AVAILABLE[i] += REQUEST[i];
		ALLOCATION[process][i] -= REQUEST[i];
		NEED[process][i] += REQUEST[i];
	}

}






/************************************
* Function name : checkSecurity
* Description : ��ȫ�Լ���
* Variables : void
************************************/
bool checkSecurity(){

	int WORK;              // WORK��ĳ����Դ��������
	bool FINISH[PROCESS];  // FINISH��ĳ�����Ƿ���ɵı��
	int temp[PROCESS];     // temp�ǻ��氲ȫ����
	int i, j, k = 0;       // k����ָʾ��ȫ���������λ��

	// ��ʼ�����н��̶�δ���
	for (i = 0; i < PROCESS; i++)
		FINISH[i] = false;

	//�ð�ȫ�Լ���㷨�ж�ϵͳ�Ƿ�ȫ�����Ƿ�Ϊ true��
	// ����Դ���ѭ��
	for (j = 0; j < RESOURCES; j++)
	{
		// ��ȡ��ǰĳ��Դ����������WORK
		WORK = AVAILABLE[j];

		// ��i���ڽ��̺�
		i = process;

		// �������̺�
		while (i < PROCESS)
		{
			if (FINISH[i] == false && NEED[i][j] <= WORK)
			{
				// ������iδ����Ҹý�����Ҫ����Դ���������ڸ��������Դ
				// ȫ��������ý��̺��ͷ�����ռ����Դ
				WORK = WORK + ALLOCATION[i][j];

				// ��Ǹý��������
				FINISH[i] = true;

				// ��¼����ȫ����
				temp[k] = i;
				k++;

				// ��ͷ��������������
				i = 0;
			}
			else
			{
				// ���������Ľ�������ɻ�����������Ҫ����Դ
				// ��ת����һ������
				i++;
			}
		} // while


		// �������������������������
		// ��˵���ҵ���һ����ȫ����
		// ����û��
		for (i = 0; i < PROCESS; i++)
		if (FINISH[i] == false)
		{
			printf("��⵽����%dδ���\n", i);
			return false;
		}
	} // for


	// ͨ������İ�ȫ�Լ�����̺�
	// �����λ��ʱ����֤������һ����ȫ����
	// ��ʾ���ð�ȫ����
	printf("�ɵõ��İ�ȫ���У�");
	for (i = 0; i < PROCESS; i++){
		printf("%3d", temp[i]);
	}
	printf("\n");
	return true;

}