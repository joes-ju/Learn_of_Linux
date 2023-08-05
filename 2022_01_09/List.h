#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int DataType;
typedef struct ListNode{
    struct ListNode* prev;
    struct ListNode* next;
    DataType data;
}LTNode;

LTNode* BuyNode(DataType x){
    LTNode* node = (LTNode*) malloc(sizeof(LTNode));
    if(node == NULL){
        perror("malloc failed");
        exit(-1);
    }

    node->data=x;
    node->prev=NULL;
    node->next=NULL;

    return node;
}

LTNode* Iint(){
    LTNode* phead = BuyNode(-1);
    phead->prev = phead;
    phead->next = phead;
    return phead;
}

void PushBack(LTNode* phead, DataType x){
    assert(phead);

    LTNode* newnode = BuyNode(x);
    LTNode* tail = phead->prev;
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = phead;
    phead->prev = newnode;
}

void PushFront(LTNode* phead, DataType x){
    assert(phead);

    LTNode* newnode = BuyNode(x);
    LTNode* head = phead->next;

    phead->next = newnode;
    newnode->prev = phead;
    newnode->next = head;
    head->prev = newnode;
}

void PopBack(LTNode* phead){
    assert(phead);

    LTNode* tail = phead->prev;
    LTNode* tailPrev = tail->prev;
    free(tail);
    tailPrev->next = phead;
    phead->prev = tailPrev;
}

void PopFront(LTNode* phead){
    assert(phead);

    LTNode* first = phead->next;
    LTNode* second = first->next;
    free(first);
    phead->next = second;
    second->prev = phead;
}

void Insert(LTNode* pos, DataType x){
    assert(pos);  

    LTNode* posPrev = pos->prev;
    LTNode* newnode = BuyNode(x) ;
    posPrev->next = newnode;
    newnode->prev = posPrev;
    newnode->next = pos;
    pos->prev = newnode;
}

void Erase(LTNode* pos){
    assert(pos);

    LTNode* posPrev = pos->prev;
    LTNode* posNext = pos->next;
    free(pos);
    posPrev->next = posNext;
    posNext->prev = posPrev;
}

LTNode* Find(LTNode* phead, DataType x){
    assert(phead);

    LTNode* cur = phead->next;
    while(cur != phead){
        if(cur->data == x){
            return cur;
        }else{
            cur = cur->next;
        }
    }
    return NULL;
}

void print(LTNode* phead){
    LTNode* cur = phead->next;
    while(cur != phead){
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void Destroy(LTNode* phead){
    assert(phead);

    LTNode* cur = phead->next;
    while(cur != phead){
        free(cur);
        cur=cur->next;
    }
    free(phead);
}