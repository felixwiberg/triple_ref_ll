#ifndef FUNCS_H
#define FUNCS_H

typedef struct _node node;

node *new_element(char *text);

void insert_node(node **head, node *newp);

void remove_node(node **head, char *text);

void print_list(node **head);

int print_q();

#endif /*FUNCS_H*/
