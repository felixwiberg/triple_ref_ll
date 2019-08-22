#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcs.h"

node *start = NULL;

int main(){

    char line[100];
    while(1){
        int operation = print_q();
        switch(operation){
            case 1:
                print_list(&start);
                break;
            case 2: 
                printf("Type text element to add: ");
                fgets(line, sizeof(line), stdin);
                line[strcspn(line, "\n")] = 0;
                insert_node(&start, new_element(line));
                printf("\n");
                break;
            case 3: 
                printf("Type text element to remove: ");
                fgets(line, sizeof(line), stdin);
                line[strcspn(line, "\n")] = 0;
                remove_node(&start, line);
                printf("\n");
                break;
            case 0:
                exit(0);
            default:
                break;
        }
        printf("\n");
    }
    return 0;
}
