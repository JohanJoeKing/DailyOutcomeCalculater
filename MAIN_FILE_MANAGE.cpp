/********************************************************
* - Project name : MyOperateSystem
* - Filename : MAIN_FILE_MANAGE.cpp
* - Author : ����
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : �ļ�����
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
* - History : [����]2018/6/28��һ���޸ģ�����˻�������ʵ��
********************************************************/



/****************************
		 �ļ�����
****************************/
#include "head_file.h"




/****************************
		 ��������
****************************/




/************************************
* Function name : MAIN_FILE_MANAGE
* Description : �ļ�����������
* Variables : void
************************************/
void MAIN_FILE_MANAGE(){

	// ��ӡ����
	FILE_PRINT_DEFAULT_PANEL();

	// ѡ������㷨
	int choice;
	cin >> choice;
	int inputN = 0;   // ͳ�ƴ�������ָ��Ĵ���
	while (inputN <= 5 && choice < 1 && choice > 4){
		inputN++;
		cin >> choice;
	}
	if (inputN > 5 && choice < 1 && choice > 4){
		// ��ָ������������ޣ��˳�
		return;
	}

	// �����㷨ȷ��
	FILE_ALGORITHM = choice * 10 / 10;

	// �������ʴŵ�������˳��
	GENERATE_DISKS();

	// ȷ����ǰ�ŵ�λ��
	SET_CURRENT_DISK();

	// ѡ������㷨����ʼ
	if (FILE_ALGORITHM == FCFS){
		// �����ȷ����㷨
		FILE_FCFS();
	}
	else if (FILE_ALGORITHM == SSTF){
		// ���Ѱ��ʱ�������㷨
		FILE_SSTF();
	}
	else if (FILE_ALGORITHM == SCAN){
		// ɨ���㷨
		FILE_SCAN();
	}
	else if (FILE_ALGORITHM == C_SCAN){
		// ѭ��ɨ���㷨
		FILE_C_SCAN();
	}

	// ��ʾͳ��Ѱ������
	SEARCH_SUMMARY();

	// ��ʾ����
	string aaa;
	printf("������Լ���...\n");
	cin >> aaa;

}




/************************************
* Function name : FILE_PRINT_DEFAULT_PANEL
* Description : ��ʾ������
* Variables : void
************************************/
void FILE_PRINT_DEFAULT_PANEL(){

	// ����
	system("cls");

	// ��ӡ����
	printf("****************************************\n\n");
	printf("             �ļ�������          \n\n");
	printf("****************************************\n\n");

	// ��ӡѡ��
	printf("ѡ����̵����㷨\n[1]�����ȷ����㷨\n[2]���Ѱ��ʱ�������㷨\n[3]ɨ���㷨\n[4]ѭ��ɨ���㷨\n> ");

}





/************************************
* Function name : GENERATE_DISKS
* Description : ���ɷ��ʴŵ�λ��
* Variables : void
************************************/
void GENERATE_DISKS(){

	// ��ʼ���ŵ�����˳���б�
	disk = new int[VISITS];

	// ������ɷ��ʴŵ�
	for (int i = 0; i < VISITS; i++){
		disk[i] = rand() % 200 + 1;
		while (disk[i] <= 0 || disk[i] >= MAX_DISK){
			disk[i] = rand() % 200 + 1;
		}
	}

	// ��ʾ����˳��
	system("cls");
	printf("���ʴŵ���˳��\n");
	for (int i = 0; i < VISITS; i++){
		printf("%d\t", disk[i]);
	}
	printf("\n\n");

}





/************************************
* Function name : SET_CURRENT_DISK
* Description : ȷ����ǰ�ŵ�λ��
* Variables : void
************************************/
void SET_CURRENT_DISK(){

	// ��ʾ����
	printf("�����뵱ǰ�ŵ�λ�ã�");
	cin >> curDisk;
	while (curDisk < 0 || curDisk > MAX_DISK){
		cin >> curDisk;
	}

}





/************************************
* Function name : FILE_FCFS
* Description : �����ȷ����㷨
* Variables : void
************************************/
void FILE_FCFS(){

	// �㷨��ʾ
	printf("\n�������ȷ����㷨��\n\n");

	// �б����
	printf("��ǰ�ŵ�\t�����ʴŵ�\tѰ������\n");
	printf("---------------------------------------------\n");

	// ���η���
	for (int i = 0; i < VISITS; i++){

		// �ŵ���Ϣ��ʾ
		printf("%5d%20d%15d\n"
			, curDisk
			, disk[i]
			, abs(curDisk - disk[i]));

		// Ѱ������ͳ��
		search_times += abs(curDisk - disk[i]);

		// �޸ĵ�ǰ�ŵ�
		curDisk = disk[i];

	} // for

}




/************************************
* Function name : FILE_SSTF
* Description : ���Ѱ��ʱ�������㷨
* Variables : void
************************************/
void FILE_SSTF(){

	// �Է��ʴŵ�������������
	int i, j, temp;
	for (i = 0; i < VISITS; i++){
		for (j = i + 1; j < VISITS; j++){
			if (disk[i] > disk[j]){
				temp = disk[i];
				disk[i] = disk[j];
				disk[j] = temp;
			}
		}
	}

	// ���������Ѱ��
	if (curDisk <= disk[0]){

		// ����ǰ�ŵ�����С�ķ��ʴŵ�ǰ���������
		for (int k = 0; k < VISITS; k++){

			// �ŵ���Ϣ��ʾ
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// Ѱ������ͳ��
			search_times += abs(curDisk - disk[k]);

			// �޸ĵ�ǰ�ŵ�
			curDisk = disk[k];
		}


	} // if

	else if (curDisk >= disk[VISITS - 1]){

		// ����ǰ�ŵ������ķ��ʴŵ��󣬽������
		for (int k = VISITS - 1; k >= 0; k--){

			// �ŵ���Ϣ��ʾ
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// Ѱ������ͳ��
			search_times += abs(curDisk - disk[k]);

			// �޸ĵ�ǰ�ŵ�
			curDisk = disk[k];
		}


	} // else if

	else{

		// ����ǰ�ŵ��ڴŵ�˳��֮�䣬Ѱ��ǰ�����ڵķ��ʴŵ�
		int behind, front;
		for (int k = 0; k < VISITS; k++){
			if (disk[k] <= curDisk && disk[k + 1] > curDisk){
				front = k;       // ��ǰ�ŵ�ǰ
				behind = k + 1;  // ��ǰ�ŵ���
			}
		}

		// �ж����ĸ�����
		if (abs(curDisk - disk[front]) < abs(curDisk - disk[behind])){

			// ����ǰһ���ڽӷ��ʴŵ��������Ƚ���������������
			for (int k = front; k >= 0; k--){
				// �ŵ���Ϣ��ʾ
				printf("%5d%20d%15d\n"
					, curDisk
					, disk[k]
					, abs(curDisk - disk[k]));

				// Ѱ������ͳ��
				search_times += abs(curDisk - disk[k]);

				// �޸ĵ�ǰ�ŵ�
				curDisk = disk[k];
			}
			for (int k = behind; k < VISITS; k++){
				// �ŵ���Ϣ��ʾ
				printf("%5d%20d%15d\n"
					, curDisk
					, disk[k]
					, abs(curDisk - disk[k]));

				// Ѱ������ͳ��
				search_times += abs(curDisk - disk[k]);

				// �޸ĵ�ǰ�ŵ�
				curDisk = disk[k];
			}

		}

		else{

			// �����һ���ڽӷ��ʴŵ�����������������ٽ������
			for (int k = behind; k < VISITS; k++){
				// �ŵ���Ϣ��ʾ
				printf("%5d%20d%15d\n"
					, curDisk
					, disk[k]
					, abs(curDisk - disk[k]));

				// Ѱ������ͳ��
				search_times += abs(curDisk - disk[k]);

				// �޸ĵ�ǰ�ŵ�
				curDisk = disk[k];
			}
			for (int k = front; k >= 0; k--){
				// �ŵ���Ϣ��ʾ
				printf("%5d%20d%15d\n"
					, curDisk
					, disk[k]
					, abs(curDisk - disk[k]));

				// Ѱ������ͳ��
				search_times += abs(curDisk - disk[k]);

				// �޸ĵ�ǰ�ŵ�
				curDisk = disk[k];
			}

		}

	} // else
}





/************************************
* Function name : FILE_SCAN
* Description : ɨ���㷨
* Variables : void
************************************/
void FILE_SCAN(){

	// �Է��ʴŵ�������������
	int i, j, temp;
	for (i = 0; i < VISITS; i++){
		for (j = i + 1; j < VISITS; j++){
			if (disk[i] > disk[j]){
				temp = disk[i];
				disk[i] = disk[j];
				disk[j] = temp;
			}
		}
	}

	// �жϴ���λ��
	if (curDisk < disk[0]){
		// ��ǰ����λ������С�Ĵŵ�֮ǰ���������
		for (int k = 0; k < VISITS; k++){

			// �ŵ���Ϣ��ʾ
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// Ѱ������ͳ��
			search_times += abs(curDisk - disk[k]);

			// �޸ĵ�ǰ�ŵ�
			curDisk = disk[k];
		}
	} // if

	else{
		// �������ڷ��ʴŵ��м�,Ѱ�Ҵ���ǰ����ʴŵ�
		int behind = 0, front = 0;
		for (int k = 0; k < VISITS; k++){
			if (disk[k] <= curDisk && disk[k + 1] > curDisk){
				front = k;       // ��ǰ�ŵ�ǰ
				behind = k + 1;  // ��ǰ�ŵ���
			}
		}

		// �������ٽ���
		for (int k = behind; k < VISITS; k++){
			// �ŵ���Ϣ��ʾ
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// Ѱ������ͳ��
			search_times += abs(curDisk - disk[k]);

			// �޸ĵ�ǰ�ŵ�
			curDisk = disk[k];
		}
		for (int k = front; k >= 0; k--){
			// �ŵ���Ϣ��ʾ
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// Ѱ������ͳ��
			search_times += abs(curDisk - disk[k]);

			// �޸ĵ�ǰ�ŵ�
			curDisk = disk[k];
		}
	}

}





/************************************
* Function name : FILE_C_SCAN
* Description : ѭ��ɨ���㷨
* Variables : void
************************************/
void FILE_C_SCAN(){

	// �Է��ʴŵ�������������
	int i, j, temp;
	for (i = 0; i < VISITS; i++){
		for (j = i + 1; j < VISITS; j++){
			if (disk[i] > disk[j]){
				temp = disk[i];
				disk[i] = disk[j];
				disk[j] = temp;
			}
		}
	}

	// �жϴ���λ��
	if (curDisk <= disk[0] || curDisk > disk[VISITS - 1]){

		// ����������С�ŵ�֮ǰ�����ŵ�֮�󣬶��������
		for (int k = 0; k < VISITS; k++){

			// �ŵ���Ϣ��ʾ
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// Ѱ������ͳ��
			search_times += abs(curDisk - disk[k]);

			// �޸ĵ�ǰ�ŵ�
			curDisk = disk[k];
		}

	} // if

	else{

		// �������ڷ��ʴŵ�֮�䣬�����ڷ��ʴŵ�
		int behind, front;
		for (int k = 0; k < VISITS; k++){
			if (disk[k] <= curDisk && disk[k + 1] > curDisk){
				front = k;       // ��ǰ�ŵ�ǰ
				behind = k + 1;  // ��ǰ�ŵ���
			}
		}

		// ��������ʵ����ŵ����ڴ���С�ŵ���ʼ����
		for (int k = behind; k < VISITS; k++){
			// �ŵ���Ϣ��ʾ
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// Ѱ������ͳ��
			search_times += abs(curDisk - disk[k]);

			// �޸ĵ�ǰ�ŵ�
			curDisk = disk[k];
		}
		for (int k = 0; k <= front; k++){
			// �ŵ���Ϣ��ʾ
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// Ѱ������ͳ��
			search_times += abs(curDisk - disk[k]);

			// �޸ĵ�ǰ�ŵ�
			curDisk = disk[k];
		}

	} // else
}





/************************************
* Function name : SEARCH_SUMMARY
* Description : ͳ��Ѱ������
* Variables : void
************************************/
void SEARCH_SUMMARY(){

	// ����
	average_times = (double)search_times / (double)VISITS;

	// ��ʾ
	printf("\n��Ѱ�����ȣ�%d\nƽ��Ѱ�����ȣ�%lf\n\n"
		, search_times
		, average_times);

}