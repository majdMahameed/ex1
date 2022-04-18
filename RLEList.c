#include "RLEList.h"
#include <string.h>

struct RLEList_t{
    //TODO: implement
    // DONE!
    char value;
    int amount;
    struct RLEList* next;
};

//implement the functions here 
//majd
RLEList RLEListCreate() {
    RLEList ptr = malloc(sizeof(ptr));
    if (!ptr) {
        return NULL;
    }
    ptr->value = '';
    ptr->amount = 0;
    ptr->next = NULL;
    return ptr;
}

// feras
void RLEListDestroy(RLEList list) {
    RLEList ptr, store;
    ptr = list;
    while (ptr) {
        store = ptr->next;
        free(ptr);
        ptr = store;
    }
}

//majd
RLEListResult RLEListAppend(RLEList list, char value) {
    if (!list || !value) {
           return RLE_LIST_NULL_ARGUMENT;
    }
    RLEList ptr = list;
    while (ptr->next) {
        ptr = ptr->next;
    }
    if (ptr->value==value) {
        ptr->amount += 1;
        return RLE_LIST_SUCCESS;
    }
    RLEList newHead = RLEListCreate(newHead);
    if (!newHead) {
           return RLE_LIST_OUT_OF_MEMORY;
    }
    newHead->value = value;
    newHead->amount = 1;
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
        count += list->amount;
        list = list->next;
    }
    return count;
}


//majd
RLEListResult RLEListRemove(RLEList list, int index) {
    if (!list) {
           return RLE_LIST_NULL_ARGUMENT;
    }
    if (RLEListSize(list)<index) {
            return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    RLEList ptr = list, ptrNext;
    for (int i = 0; i < index-1; i++) {
        ptr = ptr->next;
    }
    if (index==0) {
        if (list->next) {
            if (list->amount==1)
                 list = list->next;
            else list->amount -= 1;
            return RLE_LIST_SUCCESS;
        }
        if(list->amount==1)
            list = NULL;
        else list->amount -= 1;
        return RLE_LIST_SUCCESS;
    }
    //ptrNext is the pointer to the index we want to remove
    ptrNext = ptr->next;
    if (ptrNext->next) {
        if (ptrNext->amount==1)
             ptr->next = ptrNext->next;
        else ptrNext->amount -= 1;
        return RLE_LIST_SUCCESS;
    }
    if (ptrNext->amount==1)
    ptr->next = NULL;
    else ptrNext->amount -= 1;
    return RLE_LIST_SUCCESS;
}

// feras
char RLEListGet(RLEList list, int index, RLEListResult *result) {
    if (!list) {
        if (result) {
            *result = RLE_LIST_NULL_ARGUMENT;
        }
        return 0;
    }
    if (RLEListSize(list) <= index || index < 0) {
        if (result) {
            *result = RLE_LIST_INDEX_OUT_OF_BOUNDS;
        }
        return 0;
    }
    RLEList ptr = list;

    while (ptr && ptr->amount <= index) {
        index -= ptr->amount;
        ptr = ptr->next;
    }
    if (result) {
        *result = RLE_LIST_SUCCESS;
    }
    return ptr->value;
}
//feras
char* RLEListExportToString(RLEList list, RLEListResult* result) {
    if (!list) {
        if (result) {
            *result = RLE_LIST_NULL_ARGUMENT;
        }
        return NULL;
    }
    RLEList list_ptr = list;
    char *out = malloc(sizeof(*out) * RLEListSize(list) * DEFAULT_EXPORTED_LINE_LENGTH + 1)
    char *out_ptr = out;
    int cur_line_length;

    while (list_ptr) {
        cur_line_length = sprintf(out_ptr, "%c%d\n", list_ptr->value, list_ptr->amount);
        out_ptr += cur_line_length;
        list_ptr = list_ptr->next;
    }
    if (result) {
        *result = RLE_LIST_SUCCESS;
    }
    return out;
} 
 //majd
RLEListResult RLEListMap(RLEList list, MapFunction map_function) {
        if (!list) {
          return  RLE_LIST_NULL_ARGUMENT;
        }
        RLEList ptr = list;
        while (ptr) {
            ptr->value = map_function(ptr->value);
        }
        return RLE_LIST_SUCCESS;
    }
} 