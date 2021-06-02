#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

void list_init(Node ** pHead, int data){
    Node * tmp = *pHead;
    if(!tmp) {
        Node * tmp2 = malloc(sizeof(Node));
        tmp2->data = data;
        tmp2->next = NULL;
        *pHead = tmp2;
    }
}
int list_length(Node ** pHead){
    Node * tmp = *pHead;
    if(!tmp) return 0;
    int count = 0;
    Node * current = tmp;
    while (current){
        count++;
        current = (Node *)current->next;
    }
    return count;
}
int list_get(Node ** pHead, int index){
    int err_no = list_index_errno(pHead, index);
    if( !err_no ){
        Node * tmp = *pHead;
        Node * current = tmp;
        for (int i = 0; i<index; i++){
            current=(Node *)current->next;
        }
        return current->data;
    }
    return 0;
}
void list_delete(Node ** pHead, int index){
    Node * tmp = *pHead;
    int err_no = list_index_errno(pHead, index);
    if(!err_no) {
        Node * current;
        Node * previous;
        current = tmp;
        for (int i = 0; i<index; i++){
            previous=current;
            current=(Node *)current->next;
        }
        if(index==0){
            *pHead = (Node *)current->next;
            free(tmp);
        } else{
            previous->next=current->next;
            free(current);
        }
    }
}
int list_index_errno(Node ** pHead, int index){
    Node * tmp = *pHead;
    if( !tmp ){
        return 1;
    } else {
        int len = list_length(pHead);
        if(index < 0){
            return 2;
        } else if(index>=len){
            return 3;
        }
    }
    return 0;
}
void list_add(Node ** pHead, int index, int data){
    Node * tmp = *pHead;
    if(!tmp) {
        list_init(pHead, data);
    } else {
        int err_no = list_index_errno(pHead, index-1);
        if(! err_no ){
            Node * current = tmp;
            Node * previous = NULL;
            for (int i = 0; i<index; i++){
                previous=current;
                current=(Node *)current->next;
            }
            Node * new_node = malloc(sizeof (Node));
            new_node->data = data;
            new_node->next = (struct Node *)current;

            if(index==0){
                *pHead = new_node;
            } else{
                previous->next = (struct Node *)new_node;
            }
        }
    }
}
void list_show(Node ** pHead){
    Node * tmp = *pHead;
    if(!tmp) {
        printf("no data!\n");
    } else {
        int len = list_length(pHead);
        for(int i = 0; i<len; i++){
            int data = list_get(pHead, i);
            printf("data %d => %d \n", i, data);
        }
    }
}
void list_push(Node ** pHead, int data){
    int index = list_length(pHead);
    list_add(pHead,index,data);
}
void list_unshift(Node ** pHead){
    Node * tmp = *pHead;
    int data;
    printf("Enter data: "); scanf("%d", &data);

    if(!tmp) {
        Node * tmp2 = malloc(sizeof(Node));
        tmp2->data = data;
        tmp2->next = NULL;
        *pHead = tmp2;
    } else {
        Node * tmp2 = malloc(sizeof(Node));
        tmp2->data = data;
        tmp2->next = (struct Node *)pHead;
        *pHead = tmp2;
    }
}
void list_pop(Node ** pHead){
    int index = list_length(pHead);
    list_delete(pHead, index-1);
}
void list_shift(Node ** pHead){
    list_delete(pHead, 0);
}
void list_clear(Node ** pHead){
    Node * tmp = *pHead;
    if(!tmp) {
        printf("no data!\n");
    } else {
        int len = list_length(pHead);
        for(int i = 0; i<len; i++){
            list_pop(pHead);//just use pop
        }
    }
}
