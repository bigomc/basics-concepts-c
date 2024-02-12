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
    int status = -1;
    
    struct node *new_element = malloc(sizeof(struct node));
    if(new_element != NULL) {
        new_element -> data = value;
        new_element -> next = NULL;
        
        if(*list == NULL) {
            *list = new_element;
        } else {
            new_element -> next = *list;
            *list = new_element;
        }
        
        status = 0;
    }
    
    return status;
}

int pop_front(struct node **list, int *value) {
    int status = -1;
    
    if(*list != NULL) {
        struct node *tmp = *list;
        *value = tmp -> data;
        *list = tmp -> next;
        free(tmp);
        
        status = 0;
    }
    
    return status;
}

int remove_at(struct node **list, int index) {
    int status = -1;
    
    if(*list != NULL) {
        int length = 0;
        struct node *tmp = *list;
        while(tmp != NULL) {
            length++;
            tmp = tmp -> next;
        }

        int limit = length - index;
        tmp = * list;
        struct node *prev = NULL;
        while(limit > 0) {
            limit--;
            prev = tmp;
            tmp = tmp -> next;
        }
        
        if(prev == NULL) {
            *list = tmp -> next;
        } else {
            prev -> next = tmp -> next;
        }
        free(tmp);
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
    
    int value;
    
    if(pop_front(&my_list, &value) == 0) {
        printf("Popped value is %d\n", value);
    } else {
        printf("Empty list");
    }
    print(my_list);
    
    return 0;
}
