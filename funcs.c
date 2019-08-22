#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcs.h"

typedef struct _node{
    char *item;
    struct _node *next;
} node;

node *new_element(char *text){
    node *newp;
    newp = (node *) malloc (sizeof(node));
    newp -> item = (char *)malloc(strlen(text) + 1);
    strcpy(newp -> item, text);
    newp -> next = NULL;
    return newp;
}

void insert_node(node **head, node *newp){
    node **tracer = head;

    while((*tracer) && strcmp((*tracer)->item, newp->item) < 1){
        tracer = &(*tracer)->next;
    }

    newp->next = *tracer;
    *tracer = newp;
}

void remove_node(node **head, char *text){
    bool present = false;
    node *old;
    node **tracer = head;

    while((*tracer) && !(present = (strcmp(text,(*tracer)->item) == 0) )){
        tracer = &(*tracer)->next;
    }

    if(present){
        old = *tracer;
        *tracer = (*tracer)->next;
        free(old->item);
        free(old);
    }
}

void print_list(node **head){
    node **tracer = head;
    if(*tracer == NULL){
        printf("<empty>\n");
    }else{
        printf("HEAD -> ");
        while(*tracer){
            printf("%s -> ", (*tracer)->item);
            tracer = &(*tracer)->next;
        }
        printf("NULL\n");
    }
}

int print_q(){

    char line[100];
    int answer;

    answer = -1;
    while(answer == -1){
        printf("Linked-list menu: \n");
        printf("[1] Print list\n");
        printf("[2] Add to list\n");
        printf("[3] Remove from list\n");
        printf("[0] Exit\n");
        printf("Input: ");

        fgets(line, sizeof(line), stdin);
        int sscanf_result = sscanf(line, "%d", &answer);
        if(answer > 3 | answer < 0 | sscanf_result == EOF){
            printf("\n *** You have to enter one of the integers! ***\n\n");
            answer = -1;
        }
    }
    return answer;
}

