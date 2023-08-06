#pragma once
#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DataType;
typedef struct Stack{
    DataType* a;
    int capacity;
    int top;
}ST;

void StackInit(ST* ps){
    assert(ps);

    ps->a = (DataType*)malloc(sizeof(DataType));
    if(ps->a == NULL){
        perror("malloc fail");
        exit(-1);
    }

    ps->top = 0;
    ps->capacity = 4;
}

void StackDestroy(ST* ps){
    assert(ps);

    free(ps->a);
    ps->a=NULL;
    ps->top = ps->capacity = 0;
}

void StackPush(ST* ps,DataType x){
    assert(ps);

    if(ps->top == ps->capacity){
        DataType* tmp = (DataType*)realloc(ps->a, ps->capacity * 2 * sizeof(DataType));
        if(tmp == NULL){
            perror("realloc fail");
            exit(-1);
        }

        ps->a = tmp;
        ps->capacity *= 2;
    }

    ps->a[ps->top] = x;
    ps->top++;
}

bool StackEmpty(ST* ps){
    assert(ps);

    // if(ps->top == 0){
    //     return true;
    // }else{
    //     return false;
    // }

    return ps->top==0;
}

void StackPop(ST* ps){
    assert(ps);
    assert(!StackEmpty(ps));

    ps->top--;
}

DataType StackTop(ST* ps){
    assert(ps);
    assert(!StackEmpty(ps));

    return ps->a[ps->top - 1];
}



int StackSize(ST* ps){
    assert(ps);

    return ps->top;
}