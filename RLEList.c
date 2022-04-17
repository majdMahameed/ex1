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
    RLEList newList = malloc(sizeof(newList*));
    if (!newList) {
        return NULL;
    }
    newList->value = '';
    ptnewListr->next = NULL;
    return newList;
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
RLEListResult RLEListAppend(RLEList list, char value) {
    if (!list||!value) {
           return RLE_LIST_NULL_ARGUMENT;
    }
    RLElist newHead = RLEListCreate(newHead);
    if (!newHead) {
           return RLE_LIST_OUT_OF_MEMORY;
    }
    newHead->value = value;
    RLElist *ptr=list;
    while(ptr->next)
        ptr->next = ptr->next;
    ptr->next = newHead;
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
        list->next;   //msh lazm hon list=list->next?
    }
    return count;
}
//majd
RLEListResult RLEListRemove(RLEList list, int index) {
    if (!list||!value) {
           return RLE_LIST_NULL_ARGUMENT;
    }
    if (RLEListSize(list)<index) {
            return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    RLElist* ptr = list, ptrNext;
    for(int i=0; i<index-1; i++) {
        ptr = ptr->next;
    }
    ptrNext = ptr->next;
    if (ptrNext->next) {
        ptr->next = ptrNext->next;
        RLEListDestroy(ptrNext);
            return RLE_LIST_SUCCESS;
    }
    ptr->next  NULL;
    RLEListDestroy(ptrNext);
    return RLE_LIST_SUCCESS;
}
