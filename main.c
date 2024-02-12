#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

void print(struct node *list) {
    while(list != NULL) {
        printf("%d -> ", list -> data);
        list = list -> next;
    }
    printf("\n");
}

int push_front(struct node **list, int value) {
    int status = 0;
    struct node* head = (struct node*) malloc(sizeof(struct node));
    
    //this could be improved to not have two return sentences
    if(head == NULL){
        return -1;
    }

    head->data = value;
    head->next = NULL;
    
    if( *list != NULL ){
        head->next = *list;
    }
    *list = head;
    
    return status;
}

int pop_front(struct node **list, int *value) {
    int status = 0;

    if( *list == NULL ){
        return -1;
    }

    struct node* new_head = (*list)->next;
    *value = (*list)->data;
    free(*list);
    *list = new_head;
    
    return status;
}

int remove_at(struct node **list, int index) {
    int status = 0;
    
    if( index > 0 ){
        int current_index = 0;
        struct node *aux = *list;

        while( (aux->next != NULL) && (current_index < index - 1) ){
            current_index++;
            aux = aux->next;
        }

        if( current_index != index-1 ){
            printf("\nIndex out of bounds\n"); 
            return -1;
        }
        else{
            struct node* deleted_node = aux->next;
            aux->next = deleted_node->next;
            free(deleted_node);
        }
    }
    else{
        struct node *tmp = *list;
        *list = (*list)->next;
        free( tmp );
    }


    return status;
}

int main(int argc, char *argv[]) {
    
    struct node *my_list = NULL;
    
    push_front(&my_list, 5);
    push_front(&my_list, 4);
    push_front(&my_list, 3);
    push_front(&my_list, 2);
    push_front(&my_list, 1);
    print(my_list);
    
    remove_at(&my_list, 0);
    print(my_list);
    remove_at(&my_list, 6);
    print(my_list);
    remove_at(&my_list, 2);
    print(my_list);
    remove_at(&my_list, 16);
    print(my_list);

    int value;
    
    if(pop_front(&my_list, &value) == 0) {
        printf("\nPopped value is %d\n", value);
    } else {
        printf("Empty list");
    }
    print(my_list);
    
    if(pop_front(&my_list, &value) == 0) {
        printf("\nPopped value is %d\n", value);
    } else {
        printf("Empty list");
    }
    print(my_list);
    
    return 0;
}
