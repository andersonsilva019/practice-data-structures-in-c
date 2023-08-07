// list.c
#include "list.h"
#include "student.h"
#include <stdlib.h>
#include <stdio.h>

struct node_t {
    student_t* student;
    node_t* next;
};

List* create_list(){
    List* li = (List*) malloc(sizeof(List));

    if(li != NULL) *li = NULL;
        
    return li;
}

void show_list(List* li){
    if(li != NULL){
        node_t* auxNode;
        auxNode = *li;

        while(auxNode != NULL){
            
            printf("| %s ", student_get_name(auxNode->student));

            auxNode = auxNode->next;
        }
    }
}

void free_list(List* li){
    if(li != NULL){
        node_t* auxNode;

        while(*li != NULL){
            auxNode = *li;          // initialized node with the first element of the list
            *li = (*li)->next;      // update the first element of the list
            free(auxNode);          // free the first element of the list
        }
        free(li);
    }
}

int size_list(List* li){
    if(li == NULL) return 0;

    int counter = 0;

    node_t* auxNode = *li;

    while(auxNode != NULL){
        counter++;
        auxNode = auxNode->next;
    }

    return counter;

}

bool is_full_list(List* li) {
    return false;
}

bool is_empty_list(List* li){
    if(li == NULL) return true; // list doesn't exist

    if(*li == NULL) return true; // list is empty

    return false;
}

bool insert_in_front_list(List* li, student_t* student){
    if(li == NULL) return false;
    
    node_t* node = (node_t*) malloc(sizeof(node_t));

    if(node == NULL) return false;

    node->student = student;
    
    node->next = *li;

    *li = node;

    return true;
}

bool insert_in_end_list(List* li, student_t* student) {
    if(li == NULL) return false;

    node_t* node = (node_t*) malloc(sizeof(node_t));

    if(node == NULL) return false;

    node->student = student;

    node->next = NULL;    
    
    if(is_empty_list(li)) {
        *li = node;
    }else {
        node_t* auxNode;
        auxNode = *li;

        while (auxNode->next != NULL){
            auxNode = auxNode->next;
        }
        
        auxNode->next = node;

        return true;
    }
}

bool insert_in_order_list(List* li, student_t* student){
    if(li == NULL) return false;

    node_t* node = (node_t*) malloc(sizeof(node_t));

    if(node == NULL) return false;

    node->student = student;

    if(is_empty_list(li)){
        node->next = NULL; 
        *li = node;
        return true;
    }else{
        node_t* old;
        node_t* current = *li;

        while (current != NULL && student_get_code(current->student) < student_get_code(student)){
            old = current;
            current = current->next;
        }
        
        if(current == *li){ 
            node->next = *li;
            *li = node;
        }else{
            node->next = current;
            old->next = node;
        }

        return true;

    }
}

bool remove_from_front_list(List* li){
    if(li == NULL) return false;

    if(is_empty_list(li)) return false;

    node_t* auxNode;

    auxNode = *li;

    *li = auxNode->next;

    free(auxNode);

    return true;
}

bool remove_from_end_list(List* li){
    if(li == NULL) return false;

    if(is_empty_list(li)) return false;

    node_t* old;
    node_t* auxNode;

    auxNode = *li;

    while(auxNode->next != NULL){
        old = auxNode;
        auxNode = auxNode->next;
    }

    if(auxNode == *li){ // only one element in the list
        *li = auxNode->next;
        return true;
    }else{
        old->next = auxNode->next;
        free(auxNode);
        return true;
    }
}

bool remove_from_order_list(List* li, unsigned int code){
    if(li == NULL) return false;

    if(is_empty_list(li)) return false;

    node_t* old;
    node_t* auxNode;
    auxNode = *li;

    while(auxNode != NULL && student_get_code(auxNode->student) != code){
        old = auxNode;
        auxNode = auxNode->next;
    }

    if(auxNode == NULL){
        return false;
    }

    if(auxNode == *li){
        *li = auxNode->next;
        return true;
    }else {
        old->next = auxNode->next;
        free(auxNode);
        return true;
    }
}
