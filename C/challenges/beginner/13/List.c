#include "List.h"
#include <stdio.h>
#include <stdlib.h>

//List Methods-----------------------------------------------------------------
List* createList() {
    List* l = (List*) malloc(sizeof(List));
    l->size = 0;
    l->head = NULL;
    return l;
}

void destroyList(List* list) {
    if (list == NULL) return;
    if (list->head == NULL) return;
    Node* iter = list->head;
    Node* temp;
    do {
        temp = iter;
        iter = iter->next;
        destroyNode(temp);
    } while (iter != NULL);
    free(list);
}

Node* findAccount(List* list, unsigned int acc_num) {
    if (list == NULL) return NULL;
    if (list->head == NULL) return NULL;
    Node* iter;
    for (iter = list->head; iter != NULL; iter = iter->next) {
        if (iter->acc_num == acc_num) return iter;
    }
    return NULL;
}

int makeAccount(List* list, unsigned int acc_num, int amount) {
    if (list == NULL) return ERROR;
    Node* iter = list->head;
    Node* node = createNode(acc_num, amount);
    if (iter != NULL) {
        while (iter->next != NULL) {
            iter = iter->next;
        }
        iter->next = node;
    } else {
        list->head = node;
    }
    node->next = NULL;
	list->size++;
    return OK;
}

int withdrawList(List* list, unsigned int acc_num, int amount) {
    if (list == NULL) return ERROR;
    Node* node = findAccount(list, acc_num);
    if (node != NULL) {
        int res = withdrawNode(node, amount);
        return res;
    } else {
        return NO_ACCOUNT;
    }
}

int depositList(List* list, unsigned int acc_num, int amount) {
    if (list == NULL) return ERROR;
    Node* node = findAccount(list, acc_num);
    if (node == NULL) {
        return makeAccount(list, acc_num, amount);
    } else {
        return depositNode(node, amount);
    }
}

int feeList(List* list, unsigned int acc_num, int amount) {
	if (list == NULL) return ERROR;
	Node* node = findAccount(list, acc_num);
	if (node == NULL) {
		return NO_ACCOUNT;
	} else {
		return feeNode(node, amount);
	}
}

void printList(List* list) {
    if (list == NULL) return;
    Node* iter = list->head;
    while (iter != NULL) {
        printf("Acount Number: %d\n", iter->acc_num);
        printf("Balance: %d\n\n", iter->balance);
        iter = iter->next;
    }
}
//End List Methods-------------------------------------------------------------

//Node Methods-----------------------------------------------------------------
Node* createNode(unsigned int acc_num, int balance) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->acc_num = acc_num;
    node->balance = balance;
    return node;
}

void destroyNode(Node* node) {
    if (node == NULL) return;
    free(node);
}

int withdrawNode(Node* node, int amount) {
    if (node == NULL) return ERROR;
    if (node->balance - amount < 0) return WITHDRAW_ERROR;
    node->balance -= amount;
    return OK;
}

int depositNode(Node* node, int amount) {
    if (node == NULL) return ERROR;
    if (node->balance + amount < 0) return DEPOSIT_ERROR;
    node->balance += amount;
    return OK;
}

int feeNode(Node* node, int amount) {
    if (node == NULL) return ERROR;
    node->balance -= amount;
    return OK;
}
//End Node Methods-------------------------------------------------------------
