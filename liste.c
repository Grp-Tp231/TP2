#include<stdio.h>
#include<stdlib.h>
#include "liste.h"


list insert_queue(list li,int x){
    listElement *element;
    element = malloc(sizeof(*element));
    if(element == NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire.\n");
        exit(EXIT_FAILURE);
    }
    element->value = x;
    if(li == NULL){
        element->next = element;
        li = element;
    }
    else{
        element->next = li->next;
        li->next=element;
        li = element;
    }

    return li;
    
}

list push_front_list(list li,int x){
    listElement *element;
    element = malloc(sizeof(*element));
    if(element == NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire.\n");
        exit(EXIT_FAILURE);
    }
    element->value = x;
    if(is_empty_list(li))
        element->next = NULL;
    else
        element->next = li;

    return element;
}


void deleteAllOccurrences(list *li, int value) {
    listElement* current = li;
    listElement* nas = NULL;

    while (current != NULL) {
        if (current->value == value) {
            nas = current;
            *current = *nas->next;
            free(nas);
        }
        else{
            current = &*current->next;
        }
    }
}

dlist insert_front_dlist(dlist li,int x)
{
    doublelistElement *element=malloc(sizeof(element));
    if(element == NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire.\n");
        exit(EXIT_FAILURE);
    }
    element->value = x;
    if(li == NULL){
        element->next = element;
        element->prev = element;
        li = element;
    }
    else{
        doublelistElement *head = li->next;
        element->next = head;
        element->prev = li;
        head->next = element;
        li->next = element;
    }

    return li;

}


list insert_front(list li,int x){
      listElement *element;
    element = malloc(sizeof(*element));
    if(element == NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire.\n");
        exit(EXIT_FAILURE);
    }
    element->value = x;
    if(li == NULL){
        element->next = element;
        li = element;
    }
    else{
        element->next = li->next;
        li->next=element;
    }

    return li;
    

}

dlist insert_queue_dlist(dlist li,int x){
        doublelistElement *element=malloc(sizeof(element));
    if(element == NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire.\n");
        exit(EXIT_FAILURE);
    }
    element->value = x;
    if(li == NULL){
        element->next = element;
        element->prev = element;
        li = element;
    }
    else{
        doublelistElement *head = li->next;
        element->next = head;
        element->prev = li;
        li->next = element;
        head->prev = element;
        li = element;
    }

    return li;
}


void sortedInsert(list *li, int x) {

    listElement *element =malloc(sizeof(element));

    if (element == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return;
    }
    element->value = x;
    element->next = NULL;

    listElement *current = *li;

    // CAS 1 & 2 : Insertion en début de liste ou liste vide
    // Si la liste est vide OU la nouvelle donnée est plus petite que la tête
    if (current == NULL || element->value <= current->value) {
        element->next = *li; 
        *li = element;       
        return;
    }
    // CAS 3 : Recherche de la position d'insertion (milieu ou fin)
    while (current->next != NULL && current->next->value < x) {
        current = current->next;
    }
    element->next = current->next;
    current->next = element;
}


void sortedDoubleInsert(dlist *li, int x) {
    doublelistElement *element = malloc(sizeof(element));
    if (element == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return;
    }
    element->value = x;
    element->prev = NULL;
    element->next = NULL;

    doublelistElement *current = *li;

    // CAS 1 & 2 : Insertion en début de liste ou liste vide
    if (current == NULL || element->value <= current->value) {
        
        element->next = *li;
        if (*li != NULL) {
            (*li)->prev = element;
        }
        *li = element;
        return;
    }

    // CAS 3 : Recherche de la position d'insertion (milieu ou fin)
    while (current->next != NULL && current->next->value < x) {
        current = current->next;
    }
    element->next = current->next;
    element->prev = current;
    if (current->next != NULL) {
        current->next->prev = element;
    }
    current->next = element;
}