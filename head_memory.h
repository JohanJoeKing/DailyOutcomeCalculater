/********************************************************
* - Project name : MyOperateSystem
* - Filename : head_memory.h
* - Author : ����
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : �洢����ͷ�ļ�
* - Others : ʯ��ׯ������ѧ��Ϣ��ѧ�뼼��ѧԺ
			 �������ѧ�뼼��ϵ
			 �༶ - ��1501-1
			 ѧ�� - 20153178
* - Function list : MEMORY_PRINT_DEFAULT_PANEL
					GENERATE_ADDRESS
					VISIT_LOOP
					RAND_ADDRESS
					ifPageInMemory
					ifExistNullBlock
					fifo_findFirstIn
					lru_findLeastUseBlock
					PRINT_BLOCKS
********************************************************/



/************************************
* Function name :
* Description :
* Variables :
************************************/



/****************************
		 Ԥ����ָ��
****************************/
#include "head.h"
#include <cstdlib>
#include <ctime>


/****************************
		 �ṹ��˵��
****************************/
struct block{
	int pages[3];    // �����
	int changed[3];  // �����仯��ʱ��
	int in[3];       // �����ʱ��
	bool lack;     // �Ƿ���ȱҳ
	block *next;   // nextָ��

	block(){
		for (int i = 0; i < 3; i++){
			pages[i] = -1;    // -1��ʾNULL
			changed[i] = -1;  // -1��ʾδ�������޸�
			in[i] = -1;       // -1��ʾNULL
		}
		lack = false;         // Ĭ��δȱҳ
		next = NULL;
	}
};



/****************************
		 ��������
****************************/
void MEMORY_PRINT_DEFAULT_PANEL();
void GENERATE_ADDRESS();
void VISIT_LOOP();
void RAND_ADDRESS();
bool ifPageInMemory(int page);
bool ifExistNullBlock();
int fifo_findFirstIn();
int lru_findLeastUseBlock();
void PRINT_BLOCKS();




/****************************
		 ȫ�ֱ���
****************************/
int ALGORITHM;       // ��̭�㷨����
int *addr;           // ָ���ַ����
int *page;           // ��Ӧҳ������
block *Block;        // �����ı仯��¼����ͷָ�룬�����¼
block *Current;      // ��ǰ�����
int LACKS = 0;       // ����ȱҳ�Ĵ���
const int FIFO = 1;  // �Ƚ��ȳ��㷨Ϊ1
const int LRU = 2;   // �������ʹ���㷨Ϊ2
const int ADDRESS = 20;   // �����ĵ�ַ����Ϊ20��
const int PAGE_SIZE = 1024;   // ҳ��ߴ�
const int PAGE_TABLE_LENGTH = 3;   // ҳ����
const bool AUTO_RANDOM_ADDRESS = true;