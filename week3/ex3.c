#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Cell{
    int value;
    struct Cell *next; // Pointer to the next cell
};
typedef struct Cell* List;

struct Cell* make_cell(int v){
    struct Cell* cell =(struct Cell*) malloc(sizeof(struct Cell));
    cell->value = v;
    return cell;
}

void put_first(struct Cell* head, List* tail){
    head->next = *tail;
    *tail = head;
}

void insert_node(struct Cell* cell, struct Cell* new_cell){
    new_cell->next = cell->next;
    cell->next = new_cell;

}

/* void delete_node(List* list, struct Cell* cell){ */
/*     List initial = *list; */
/*     if(*list == cell){ */
/*         *list = cell; */
/*         return; */
/*     } */
/*     while((*list)->next != cell || (*list)->next == NULL){ */
/*         *list = (*list)->next; */
/*     } */
/*     if((*list)->next == NULL) */
/*         *list = initial; */
/*         return; */
/*     (*list)->next = cell->next; */
/*     *list = initial; */
/*     free(cell); */
/* } */

void remove_head(List* lp){
    List tmp = *lp;
    *lp = tmp->next;
    free(tmp);
}

void delete_node(List* lp, struct Cell* cell){
    if(*lp == cell){
        remove_head(lp);
        return;
    }
    List list = *lp;
    while(list->next != cell || list->next == NULL){
        list = list->next;
    }
    if(list->next == NULL)
        return;
    list->next = cell->next;
    free(cell);
}




/* void printList(List list){ */
/*   printf("%s ", list->str); */
/*   if(list->next != NULL){ */
/*     printList(list->next); */
/*   } */
/* } */

void print_list(List list){
    while(list != NULL){
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

List find(int v, List list){
    while(list != NULL){
        if(list->value == v){
            return list;
        }
        list = list->next;
    }
    return NULL;
}


int main(){
    int a[] = {34, 45, 2, 12, 41};
    List list = make_cell(0);
    for(int i = 4; i >= 0; i--){
        struct Cell* cell = make_cell(a[i]);
        put_first(cell, &list);
    }
    print_list(list);

    struct Cell* cell = make_cell(42);
    insert_node(list, cell);

    print_list(list);
    delete_node(&list, cell);
    print_list(list);
    cell = find(12, list);
    delete_node(&list, cell);
    print_list(list);
    delete_node(&list, list);
    print_list(list);
    remove_head(&list);
    print_list(list);





}
