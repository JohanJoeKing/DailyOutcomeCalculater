/********************************************************
* - Project name : MyOperateSystem
* - Filename : MAIN_PROCESS_MANAGE.cpp
* - Author : ����
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : ���̹���
* - Others : ʯ��ׯ������ѧ��Ϣ��ѧ�뼼��ѧԺ
			 �������ѧ�뼼��ϵ
			 �༶ - ��1501-1
			 ѧ�� - 20153178
* - Function list :
* - History : 
********************************************************/



/****************************
		 �ļ�����
****************************/
#include "head_process.h"




/****************************
		 ��������
****************************/




/************************************
* Function name : MAIN_PROCESS_MANAGE
* Description : ���̹���������
* Variables : void
************************************/
void MAIN_PROCESS_MANAGE(){

	// ��ӡ����
	PROCESS_PRINT_DEFAULT_PANEL();
	TIME = 0;

	// ѡ����ʾ
	string choice = "";
	cin >> choice;
	int inputN = 0;   // ͳ�ƴ�������ָ��Ĵ���
	while (inputN <= 5 && choice != "1" && choice != "2"){
		inputN++;
		cin >> choice;
	}
	if (inputN > 5 && choice != "1" && choice != "2"){
		// ��ָ������������ޣ��˳�
		return;
	}

	// ������ʾ
	if (choice == "1"){
		// ������-�����߳�����ʾ
		PRODUCER_CONSUMER_DEMO();
	}
	else if (choice == "2"){
		// ��̬���ȼ�������ʾ
		string c2;
		printf("\n[1]����Ӧ���㷨\n[2]����ҵ����\n[3]�����ȼ������㷨\n> ");
		cin >> c2;
		int k = 0;
		while (k <= 5 && c2 != "1" && c2 != "2" && c2 != "3"){
			k++;
			cin >> c2;
		}
		if (k > 5 && c2 != "1" && c2 != "2" && c2 != "3"){
			// ��ָ������������ޣ��˳�
			return;
		}
		PROCESS_ALGORITHM = c2;

		// ��ʼ��ʾ
		PROCESS_DEMO();
	}

}





/************************************
* Function name : producer
* Description : ������
* Variables : void
************************************/
void producer(){

	while (PRODUCE_TIMES > 0){

		// ���������������ȴ�Ƭ��������
		if (products >= BUF_MAX)
		{
			printf("[��ʾ]\t������������Ⱥ�Ƭ��\n");
			Sleep(3000);
		}

		// �������δ������������
		else
		{
			products++;
			printf("[����]\t��Ʒ������%d\n", products);
			Sleep(1300);
		}

		// ������ʾʱ��
		PRODUCE_TIMES--;
	}

}





/************************************
* Function name : consumer
* Description : ������
* Variables : void
************************************/
void consumer(){

	while (PRODUCE_TIMES > 0)
	{

		// ��������ѿգ��ȴ�����
		if (products == 0)
		{
			printf("[��ʾ]\t������ѿգ��ȴ�Ƭ��\n");
			Sleep(2000);
		}

		// �����������Դ����������
		else
		{
			products--;
			printf("[����]\t��Ʒ������%d\n", products);
			Sleep(2000);
		}
	}

}





/************************************
* Function name : PROCESS_PRINT_DEFAULT_PANEL
* Description : ��ʾ����
* Variables : void
************************************/
void PROCESS_PRINT_DEFAULT_PANEL(){

	// ����
	system("cls");

	// ��ӡ����
	// ��ӡ����
	printf("****************************************\n\n");
	printf("             ���̹�����          \n\n");
	printf("****************************************\n\n");

	// ��ӡѡ��
	printf("ѡ����ʾ\n[1]������-�����߳���\t[2]��̬���ȼ�������ʾ\n> ");

}





/************************************
* Function name : PRODUCER_CONSUMER_DEMO
* Description : ������-�����߳�����ʾ
* Variables : void
************************************/
void PRODUCER_CONSUMER_DEMO(){

	// ��ӡ����
	system("cls");
	printf("> ��ʾ��������-�����߳���\n\n");

	// �򿪶��߳�
	thread t1(producer);
	thread t2(consumer);
	t1.join();
	t2.join();

}





/************************************
* Function name : PROCESS_DEMO
* Description : ��̬���ȼ�������ʾ
* Variables : void
************************************/
void PROCESS_DEMO(){

	// ��ʼ��֧����
	PROCESS_DEMO_INIT();

	// ��ӡ����
	system("cls");
	printf("> ��ʾ����̬���ȼ�����\n\n");

	// ��ʾ���ھ��������еĽ���
	printf("���ھ��������еĽ����У�");
	showQueue(ready->next);
	printf("\n\n");

	// ��ʾ���н������
	PROCESS_DEMO_PRINT();

	// ȷ�Ͽ�ʼ
	printf("������Կ�ʼ...\n");
	string aaa;
	cin >> aaa;

	// ��ʼ����
	PROCESS_DEMO_LOOP();

}




/************************************
* Function name : PROCESS_DEMO_LOOP
* Description : ��̬���ȼ����ȹ���
* Variables : void
************************************/
void PROCESS_DEMO_LOOP(){

	// ����
	system("cls");

	// ѭ������
	// ���������к�CPUΪ��ʱ�˳�
	while (run->next != NULL || ready->next != NULL){

		// Ϊ������������
		if (PROCESS_ALGORITHM == HRRN){
			// �����Ӧ���㷨
			rebuildQueueHRRN();
		}
		else if (PROCESS_ALGORITHM == SSTF){
			// ����ҵ����
			rebuildQueueByTime();
		}
		else if (PROCESS_ALGORITHM == HPFS){
			// �����ȼ������㷨
			rebuildQueue();
		}


		// ��ͷ�����Ž��̣�����CPUִ��
		getInCPU();


		// ��ӡ���н�����Ϣ
		system("cls");
		PROCESS_DEMO_PRINT();

		// CPUִ�иý���
		CPU_OPERATE();

		// ʱ��Ƭ����
		printf("��ǰʱ�䣺%d\n", TIME);
		TIME++;

		// ������Լ���
		printf("������Լ���...\n");
		string aaa;
		cin >> aaa;

	} // while

	// ͳ��ƽ����תʱ���ƽ����Ȩ��תʱ��
	double avgTime, avgWeightTime;
	double sumTime = 0, sumWeightTime = 0;
	PCB *c = NULL;
	c = finish->next;
	while (c){
		sumTime += ((double)c->finishtime - (double)c->arrive);
		sumWeightTime += ((double)c->needtime / ((double)c->finishtime - (double)c->arrive));
		c = c->next;
	}
	avgTime = sumTime / (double)DEMO_PROCESS;
	avgWeightTime = sumWeightTime / (double)DEMO_PROCESS;

	// ������ʾ
	system("cls");
	PROCESS_DEMO_PRINT();
	printf("\n\n���н��������\n");
	printf("ƽ����תʱ�䣺%lf\nƽ����Ȩ��תʱ�䣺%lf\n\n",
		avgTime, avgWeightTime);

	// ������Լ���
	printf("������Լ���...\n");
	string aaa;
	cin >> aaa;

}




/************************************
* Function name : PROCESS_DEMO_INIT
* Description : ��̬���ȼ�������ʾ��ʼ��
* Variables : void
************************************/
void PROCESS_DEMO_INIT(){

	// ��ʼ������ָ��
	ready = NULL;
	run = NULL;
	finish = NULL;
	ready = new PCB;
	run = new PCB;
	finish = new PCB;
	ready->next = NULL;
	run->next = NULL;
	finish->next = NULL;

	// ����������в������ɽ���
	int nameBuf = 0;      // ��������
	int needTimeBuf = 2;  // ������Ҫ��ʱ����
	for (int i = 0; i < DEMO_PROCESS; i++){

		// �����µ�PCB
		PCB *n = NULL;
		n = new PCB;

		// ��ֵ
		n->name = nameBuf++;                  // ��������
		n->needtime = needTimeBuf;            // ������Ҫʱ��
		n->prio = PRIO_WEIGHT - needTimeBuf;  // �������ȼ�
		needTimeBuf += NEEDTIME_INTERVAL;
		n->arrive = 0;          // ���̵���ʱ��
		n->cputime = 0;         // ������ʹ��CPUʱ��
		n->finishtime = -1;     // �������ʱ��
		n->state = PRO_READY;   // ����״̬
		n->next = NULL;         // nextָ��Ϊ��

		// ���뵽��������
		insertIntoReady(n);

	} // for

}





/************************************
* Function name : PROCESS_DEMO_PRINT
* Description : ��ʾ���н������
* Variables : void
************************************/
void PROCESS_DEMO_PRINT(){

	// ��ӡ����
	printf("---------------------------------------------------\n");
	printf("����  ���ȼ�  ��Ҫʱ��  ����ʱ��  ����ʱ��  ����ʱ��\n");
	printf("---------------------------------------------------\n");

	// ��ӡ����̬����
	printf("����̬��\n");
	if (run->next != NULL){
		// ����̬�н���
		printf("%3d%9d%9d%9d%9d%9d\n"
			, run->next->name
			, run->next->prio
			, run->next->needtime
			, run->next->cputime
			, run->next->arrive
			, run->next->finishtime);
	}
	else{
		// ���������еĽ���
		printf("%3c%9c%9c%9c%9c%9c\n"
			, '-', '-', '-', '-', '-', '-');
	}
	printf("---------------------------------------------------\n");

	// ��ӡ����̬����
	printf("����̬��\n");
	if (ready->next != NULL){
		// �о���̬����
		PCB *cur = NULL;
		cur = ready->next;

		// ����
		while (cur){
			printf("%3d%9d%9d%9d%9d%9d\n"
				, cur->name
				, cur->prio
				, cur->needtime
				, cur->cputime
				, cur->arrive
				, cur->finishtime);
			cur = cur->next;
		}

		// ����ָ��
		delete cur;
	}
	else{
		// �޾���̬����
		printf("%3c%9c%9c%9c%9c%9c\n"
			, '-', '-', '-', '-', '-', '-');
	}
	printf("---------------------------------------------------\n");

	// ��ӡ���̬����
	printf("���̬��\n");
	if (finish->next != NULL){
		// �о���̬����
		PCB *cur = NULL;
		cur = finish->next;

		// ����
		while (cur){
			printf("%3d%9d%9d%9d%9d%9d\n"
				, cur->name
				, cur->prio
				, cur->needtime
				, cur->cputime
				, cur->arrive
				, cur->finishtime);
			cur = cur->next;
		}

		// ����ָ��
		delete cur;
	}
	else{
		// �޾���̬����
		printf("%3c%9c%9c%9c%9c%9c\n"
			, '-', '-', '-', '-', '-', '-');
	}
	printf("---------------------------------------------------\n");

}




/************************************
* Function name : insertIntoReady
* Description : ������̿��ƿ鵽��������
* Variables : PCB *p
************************************/
void insertIntoReady(PCB *p){

	// �½��ƶ�ָ��
	PCB *cur = NULL;

	// ָ���������ͷ
	cur = ready;

	// Ѱ�Ҿ�������β
	while (cur->next){
		cur = cur->next;
	}

	// ����
	cur->next = p;

	// �޸�״̬
	p->state = PRO_READY;
	p->next = NULL;

}





/************************************
* Function name : insertIntoFinish
* Description : ������̿��ƿ鵽��ɶ���
* Variables : PCB *p
************************************/
void insertIntoFinish(PCB *p){

	// �½��ƶ�ָ��
	PCB *cur = NULL;

	// ָ���������ͷ
	cur = finish;

	// Ѱ�Ҿ�������β
	while (cur->next){
		cur = cur->next;
	}

	// ����
	cur->next = p;

	// �޸�״̬
	p->state = PRO_FINISH;
	p->next = NULL;

}




/************************************
* Function name : showQueue
* Description : ��������
* Variables : PCB *p
************************************/
void showQueue(PCB *p){

	// �½��ƶ�ָ��
	PCB *cur = NULL;

	// ָ�����ͷ
	cur = p;

	// �������
	while (cur){
		printf("%5d", cur->name);
		cur = cur->next;
	}

}




/************************************
* Function name : rebuildQueue
* Description : �����ȼ��Զ�������
* Variables : void
************************************/
void rebuildQueue(){

	// �½�α����ͷ
	PCB *head = NULL;
	head = new PCB;

	// �滻ready
	head->next = ready->next;

	// ready�ÿ�
	ready->next = NULL;

	// ���²��뵽ready
	// ��headû�к��ʱ�˳�
	while (head->next){

		int index;    // ������ȼ����̵�����
		int max = 0;  // ���ȼ����ֵ

		// �½��ƶ�ָ��
		PCB *cur = NULL;
		cur = head->next;

		// Ѱ��������ȼ�����
		while (cur){
			if (cur->prio > max){
				// �ҵ������ֵ��Ľ��̣���¼
				max = cur->prio;
				index = cur->name;
			}
			cur = cur->next;
		}

		// ���ݶ�λ����������ȼ����̣�����ready
		PCB *cur2 = NULL;
		cur2 = head;
		while (cur2){
			if (cur2->next->name == index){
				// �ҵ�������ȼ�����
				PCB *b = NULL;
				b = cur2->next;       // b����������������̵�PCB
				cur2->next = b->next; // �޸�����
				insertIntoReady(b);   // ���뵽ready����
				b->next = NULL;       // �ÿ�β�����ָ��
				break;
			}
			else{
				cur2 = cur2->next;
			}
		}

	} // while

}





/************************************
* Function name : rebuildQueueByTime
* Description : ��CPUʱ��Զ�������
* Variables : void
************************************/
void rebuildQueueByTime(){

	// �½�α����ͷ
	PCB *head = NULL;
	head = new PCB;

	// �滻ready
	head->next = ready->next;

	// ready�ÿ�
	ready->next = NULL;

	// ���²��뵽ready
	// ��headû�к��ʱ�˳�
	while (head->next){

		int index;        // �����ҵʱ����̵�����
		int min = 99999;  // ��ҵʱ�����ֵ

		// �½��ƶ�ָ��
		PCB *cur = NULL;
		cur = head->next;

		// Ѱ��������ȼ�����
		while (cur){
			if (cur->cputime < min){
				// �ҵ�����СֵС�Ľ��̣���¼
				min = cur->cputime;
				index = cur->name;
			}
			cur = cur->next;
		}

		// ���ݶ�λ���������Ҳʱ����̣�����ready
		PCB *cur2 = NULL;
		cur2 = head;
		while (cur2){
			if (cur2->next->name == index){
				// �ҵ�������ȼ�����
				PCB *b = NULL;
				b = cur2->next;       // b����������������̵�PCB
				cur2->next = b->next; // �޸�����
				insertIntoReady(b);   // ���뵽ready����
				b->next = NULL;       // �ÿ�β�����ָ��
				break;
			}
			else{
				cur2 = cur2->next;
			}
		}

	} // while

}




/************************************
* Function name : rebuildQueueHRRN
* Description : �����Ӧ���㷨
* Variables : void
************************************/
void rebuildQueueHRRN(){

	// �½�α����ͷ
	PCB *head = NULL;
	head = new PCB;

	// �滻ready
	head->next = ready->next;

	// ready�ÿ�
	ready->next = NULL;

	// ���²��뵽ready
	// ��headû�к��ʱ�˳�
	while (head->next){

		int index;       // �������Ľ��̵�����
		int max = 0;     // �����Ӧ��

		// �½��ƶ�ָ��
		PCB *cur = NULL;
		cur = head->next;

		// Ѱ��������ȼ�����
		while (cur){
			float wait = (float)TIME - (float)cur->arrive;
			float k = ((float)cur->needtime + wait) / wait;
			if (k > max){
				// �ҵ�������ʱ����Ľ��̣���¼
				max = k;
				index = cur->name;
			}
			cur = cur->next;
		}

		// ���ݶ�λ����������̣�����ready
		PCB *cur2 = NULL;
		cur2 = head;
		while (cur2){
			if (cur2->next->name == index){
				// �ҵ��������
				PCB *b = NULL;
				b = cur2->next;       // b����������������̵�PCB
				cur2->next = b->next; // �޸�����
				insertIntoReady(b);   // ���뵽ready����
				b->next = NULL;       // �ÿ�β�����ָ��
				break;
			}
			else{
				cur2 = cur2->next;
			}
		}

	} // while
}




/************************************
* Function name : getInCPU
* Description : ��ͷ����CPU
* Variables : void
************************************/
void getInCPU(){

	// ��readyΪ�գ��˳�
	if (ready->next == NULL){
		return;
	}

	// ��runΪ��
	if (run->next == NULL){
		// runָ��ָ���ͷ���
		run->next = ready->next;

		// readyͷָ�����
		ready->next = run->next->next;

		// �޸�״̬
		run->next->state = PRO_RUN;
	}

	// ��run��Ϊ�գ��Ƚ������Ľ��̲���������У��ٽ���CPU
	else{
		// ����Ӧ���㷨
		if (PROCESS_ALGORITHM == HRRN){
			float w1 = (float)TIME - (float)run->next->arrive;
			float w2 = (float)TIME - (float)ready->next->arrive;
			float k1 = (w1 + (float)run->next->needtime) / w1;
			float k2 = (w2 + (float)ready->next->needtime) / w2;
			if (k1 < k2){
				// ����������ҵ��Ӧ�ȸ��ߣ��滻
				insertIntoReady(run->next);
				run->next = NULL;
				getInCPU();
			}
			else{
				// ���н��̸��ߣ��˳�
				return;
			}
		}

		// ����ҵ�����㷨
		else if (PROCESS_ALGORITHM == SSTF){
			if (run->next->needtime > ready->next->needtime){
				// ����������ҵ���̣��滻
				insertIntoReady(run->next);
				run->next = NULL;
				getInCPU();
			}
			else{
				// ���н��̸��̣��˳�
				return;
			}
		}

		// �����ȼ������㷨
		else if (PROCESS_ALGORITHM == HPFS){
			if (run->next->prio < ready->next->prio){
				// ���ȼ��������еĽ��̴��滻
				insertIntoReady(run->next);
				run->next = NULL;
				getInCPU();
			}
			else{
				// ���ȼ�û�������еĽ��̴��˳�
				return;
			}
		}

	}

}





/************************************
* Function name : CPU_OPERATE
* Description : CPUִ�н���
* Variables : void
************************************/
void CPU_OPERATE(){

	// ִ��һ��ʱ��Ƭ�����ȼ���1
	run->next->prio--;

	// �޸�ִ��ʱ��
	run->next->cputime++;

	// ���������
	if (run->next->cputime == run->next->needtime){
		// ��¼����ʱ��
		run->next->finishtime = TIME + 1;

		// ������ɶ���
		insertIntoFinish(run->next);

		// �ÿ�run
		run->next = NULL;
	}

}