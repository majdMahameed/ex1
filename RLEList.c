#include "RLEList.h"

struct RLEList_t{
    //TODO: implement
    // DONE!
    char value;
    struct RLEList* next;
};

//implement the functions here
//majd
RLEList RLEListCreate() {
    RLEList ptr = malloc(sizeof(ptr*));
    if (!ptr) {
        return NULL;
    }
    ptr->value ='';
    ptr->next =NULL;
    return ptr;
}

// feras
void RLEListDestroy(RLEList list) {
    RLElist *ptr, *store;
    ptr = list;
    while (ptr) {
        store = ptr->next;
        free(ptr);
        ptr = store;
    }
}

//majd
RLEListResult RLEListAppend(RLEList list, char val) {
    if (!list||!value) {
           return RLE_LIST_NULL_ARGUMENT;
    }
    RLElist newHead = RLEListCreate(newHead);
    if (!newHead) {
           return RLE_LIST_OUT_OF_MEMORY;
    }
    newHead->value=val;
    list->next=newHead;
    return RLE_LIST_SUCCESS;
}

// feras
int RLEListSize(RLEList list) {
    if (!list) {
        return -1;
    }
    int count = 0;
    while (list) {
        count++;
        list->next;
    }
    return count;
}
