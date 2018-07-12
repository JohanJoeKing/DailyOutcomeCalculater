/********************************************************
* - Project name : MyOperateSystem
* - Filename : MAIN_MEMORY_MANAGE.cpp
* - Author : ����
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : �洢����
* - Others : ʯ��ׯ������ѧ��Ϣ��ѧ�뼼��ѧԺ
			 �������ѧ�뼼��ϵ
			 �༶ - ��1501-1
			 ѧ�� - 20153178
* - Function list : MAIN_MEMORY_MANAGE
					MEMORY_PRINT_DEFAULT_PANEL
					GENERATE_ADDRESS
					VISIT_LOOP
					RAND_ADDRESS
					ifPageInMemory
					ifExistNullBlock
					fifo_findFirstIn
					lru_findLeastUseBlock
					PRINT_BLOCKS
* - History : [����]2018/6/28��һ���޸ģ���ɻ�������
********************************************************/



/****************************
		 �ļ�����
****************************/
#include "head_memory.h"




/************************************
* Function name : MAIN_MEMORY_MANAGE
* Description : �ڴ����������
* Variables : void
************************************/
void MAIN_MEMORY_MANAGE(){

	// ��ӡ����
	MEMORY_PRINT_DEFAULT_PANEL();

	// ѡ����̭�㷨
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

	// ��̭�㷨ȷ��
	if (choice == "1"){
		ALGORITHM = 1;
	}
	else if (choice == "2"){
		ALGORITHM = 2;
	}

	// ����ָ���ַ
	GENERATE_ADDRESS();

	// ��ʼѭ��
	VISIT_LOOP();

	// ��ӡ�û�ͼ
	PRINT_BLOCKS();

}




/************************************
* Function name : PRINT_DEFAULT_PANEL
* Description : ��ʾ������
* Variables : void
************************************/
void MEMORY_PRINT_DEFAULT_PANEL(){

	// ����
	system("cls");

	// ��ӡ����
	printf("****************************************\n\n");
	printf("             �洢������          \n\n");
	printf("****************************************\n\n");

	// ��ӡѡ��
	printf("ѡ����̭�㷨[1]FIFO\t[2]LRU\n> ");

}






/************************************
* Function name : GENERATE_ADDRESS
* Description : ����ָ���ַ
* Variables : void
************************************/
void GENERATE_ADDRESS(){

	// ����
	system("cls");

	// ��ʼ��ָ���ַ����
	addr = new int[ADDRESS];
	page = new int[ADDRESS];

	// ����������ɸ�0-10240֮��ĵ�ַ��
	RAND_ADDRESS();

	// ��ʾ��̭�㷨
	if (ALGORITHM == FIFO){
		printf("���Ƚ��ȳ��㷨��\n\n");
	}
	else if (ALGORITHM == LRU){
		printf("��������δʹ���㷨��\n\n");
	}

	// ��ʾָ���ַ����
	int i;
	printf("ָ���ַ����\n");
	for (i = 0; i < ADDRESS; i++){
		printf("%d\t", addr[i]);
		if ((i + 1) % 10 == 0){
			printf("\n");
		}
	}

	// �ָ���
	printf("-----------------------------------------------------------\n");

}





/************************************
* Function name : VISIT_LOOP
* Description : ��ʼѭ��
* Variables : void
************************************/
void VISIT_LOOP(){

	// ��ʼ��������¼����
	Block = new block;          // ͷ���
	Current = new block;
	Current = Block;      // �ҵ���ǰ���
	int addr_buf;   // ָ���ַ����
	int page_buf;   // ҳ�Ż���

	// ѭ��
	for (int i = 0; i < ADDRESS; i++){

		// ����һ��ָ���ַ
		addr_buf = addr[i];

		// ����õ�ַ���ڵ�ҳ��
		page_buf = addr_buf / PAGE_SIZE;
		page[i] = page_buf;

		// �鿴��ҳ�Ƿ�������
		if (ifPageInMemory(page_buf)){

			// ����ҳ�Ѵ��������棬�����¹���
			block *b = NULL;
			b = new block;

			// ���ӹ��̲�����
			Current->next = b;
			*b = *Current;
			b->next = NULL;

			// �޸ı仯��������ʹ��ʱ��
			for (int k = 0; k < PAGE_TABLE_LENGTH; k++){
				if (b->pages[k] == page_buf){
					b->changed[k] = i;
				}
			}

			Current = Current->next;

		} // if

		else{

			// ����ҳ��������
			if (ifExistNullBlock()){

				// ��ҳ����ڿ�������
				block *b = NULL;
				b = new block;

				// ���ӹ��̲�����
				Current->next = b;
				*b = *Current;
				b->next = NULL;

				// �޸�ҳ��
				for (int k = 0; k < PAGE_TABLE_LENGTH; k++){
					if (b->pages[k] == -1){
						b->pages[k] = page_buf;  // ����ҳ��
						b->changed[k] = i;   // ��¼�޸�ʱ��
						b->in[k] = i;   // ��¼����ʱ��
						break;
					}
				}

				Current = Current->next;

			}

			else{

				// ��ҳ�����ڿ������ʹ����̭�㷨
				if (ALGORITHM == FIFO){
					// �Ƚ��ȳ��㷨
					block *b = NULL;
					b = new block;

					// ���ӹ��̲�����
					Current->next = b;
					*b = *Current;
					b->next = NULL;

					// �ҵ�����λ��
					int index = fifo_findFirstIn();

					// ����ҳ��
					b->pages[index] = page_buf;  // ����ҳ��
					b->changed[index] = i;   // ��¼�޸�ʱ��
					b->in[index] = i;   // ��¼����ʱ��
					b->lack = true;     // ȷ��ȱҳ

					Current = Current->next;
				}
				else if (ALGORITHM == LRU){
					// ������δʹ���㷨
					block *b = NULL;
					b = new block;

					// ���ӹ��̲�����
					Current->next = b;
					*b = *Current;
					b->next = NULL;

					// �ҵ�����λ��
					int index = lru_findLeastUseBlock();

					// ����ҳ��
					b->pages[index] = page_buf;  // ����ҳ��
					b->changed[index] = i;   // ��¼�޸�ʱ��
					b->in[index] = i;   // ��¼����ʱ��
					b->lack = true;     // ȷ��ȱҳ

					Current = Current->next;
				}

				// ȱҳ��1
				LACKS++;
			}

		} // else

	} // for

}




/************************************
* Function name : RAND_ADDRESS
* Description : �������ָ���ַ����
* Variables : void
************************************/
void RAND_ADDRESS(){

	// �Զ��������ָ���ַģʽ
	if (AUTO_RANDOM_ADDRESS){

		int n;
		for (int i = 0; i < 20; i++){
			n = rand();
			while (n <= 0 || n >= 10240){
				n = rand() % 10240 + 1;
			}
			addr[i] = n;
		}

	}

	// ָ��ָ���ַģʽ
	else{

		addr[0] = 312;
		addr[1] = 1025;
		addr[2] = 3346;
		addr[3] = 234;
		addr[4] = 7142;
		addr[5] = 6685;
		addr[6] = 3442;
		addr[7] = 5665;
		addr[8] = 4123;
		addr[9] = 8099;
		addr[10] = 10000;
		addr[11] = 2344;
		addr[12] = 2454;
		addr[13] = 3122;
		addr[14] = 1111;
		addr[15] = 1134;
		addr[16] = 332;
		addr[17] = 3125;
		addr[18] = 5567;
		addr[19] = 3213;

	}

}





/************************************
* Function name : ifPageInMemory
* Description : �鿴ҳ�Ƿ�������
* Variables : int page
************************************/
bool ifPageInMemory(int page){

	for (int i = 0; i < PAGE_TABLE_LENGTH; i++){

		if (Current->pages[i] == page)
			// �����ָ�ҳ�����棬������
			return true;

	}

	// ��ҳ�����κ�һ������飬���ط�
	return false;

}





/************************************
* Function name : ifExistNullBlock
* Description : �鿴ҳ���Ƿ��пհ�����
* Variables : void
************************************/
bool ifExistNullBlock(){

	for (int i = 0; i < PAGE_TABLE_LENGTH; i++){

		if (Current->pages[i] == -1){

			// �����ֿհ����������
			return true;

		}

	}

	// ��û�з����κοհ�������ط�
	return false;

}






/************************************
* Function name : fifo_findFirstIn
* Description : �Ƚ��ȳ��㷨�������Ƚ����ҳ��
* Variables : void
************************************/
int fifo_findFirstIn(){

	int index = 0;
	int IN = 999;
	for (int i = 0; i < PAGE_TABLE_LENGTH; i++){

		if (Current->in[i] < IN){
			// ����Сֵ������λ��
			index = i;
			IN = Current->in[i];
		}

	}

	return index;

}





/************************************
* Function name : lru_findLeastUseBlock
* Description : ������δʹ���㷨�ҵ�����ʹ�õ�ҳ��
* Variables : void
************************************/
int lru_findLeastUseBlock(){

	int index = 0;
	int USE = 999;
	for (int i = 0; i < PAGE_TABLE_LENGTH; i++){

		if (Current->changed[i] < USE){
			// ����Сֵ������λ��
			index = i;
			USE = Current->changed[i];
		}

	}

	return index;

}





/************************************
* Function name : PRINT_BLOCKS
* Description : ������δʹ���㷨�ҵ�����ʹ�õ�ҳ��
* Variables : void
************************************/
void PRINT_BLOCKS(){

	// �����ӡ
	block *cur = NULL;
	cur = Block;
	int n = 1;
	while (cur->next){
		printf("[%d]\t��ַ��%8d\tҳ�棺%5d\t���棺%3d%3d%3d\n"
			, n++
			, addr[n - 2]
			, page[n - 2]
			, cur->next->pages[0]
			, cur->next->pages[1]
			, cur->next->pages[2]);
		cur = cur->next;
	}

	// ����ȱҳ��
	double lackRate = (double)LACKS / 20.0;

	// ��ʾȱҳ��
	printf("\n\nȱҳ�ʣ�%lf", lackRate);

	// ��ʾ����
	string aaa;
	printf("\n������Լ���...\n");
	cin >> aaa;
}