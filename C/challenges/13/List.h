#ifndef LIST_H_
#define LIST_H_

#define ERROR -1
#define WITHDRAW_ERROR 1
#define NO_ACCOUNT 2
#define CREATE_ACCOUNT_ERROR 3
#define DEPOSIT_ERROR 4
#define OK 0

typedef struct Node {
	unsigned int acc_num;
	int balance;
	struct Node* next;
} Node;

typedef struct List {
	Node* head;
	unsigned int size;
} List;

//List Methods-----------------------------------------------------------------
List* createList(void);
void destroyList(List* list);
Node* findAccount(List* list, unsigned int acc_num);
int makeAccount(List* list, unsigned int acc_num, int amount);
int withdrawList(List* list, unsigned int acc_num, int amount);
int depositList(List* list, unsigned int acc_num, int amount);
int feeList(List* list, unsigned int acc_numb, int amount);
//End List Methods--------------------------------------------------------------

//Node Methods-----------------------------------------------------------------
Node* createNode(unsigned int acc_num, int balance);
void destroyNode(Node* node);
int withdrawNode(Node* node, int amount);
int depositNode(Node* node, int amount);
int feeNode(Node* node, int amount);
//End Node Methods-------------------------------------------------------------

#endif
