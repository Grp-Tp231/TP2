#define __liste_H__
#ifndef __liste_h__

typedef struct listElement
{
    int value;
    struct listElement *next;
    
}listElement,*list;

typedef struct doublelistElement
{
    int value;
    struct doublelistElement *prev;
    struct doublelistElement *next;

}doublelistElement,*dlist;



list insert_queue(list li,int x);
list insert_front(list li,int x);
dlist insert_front_dlist(dlist li,int x);
dlist insert_queue_dlist(dlist li,int x);
list delete_occurence(list *li,int x);









#endif
