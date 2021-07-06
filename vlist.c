
#include "vlist.h"

vlist* vlist_init(void) {
    vlist* ptr = (vlist*)malloc(sizeof(vlist));
    ptr->ptr   = (struct Node*)malloc(sizeof(struct Node));
    ptr->ptr->next = 0;
    ptr->ptr->content = 0;
    return ptr;
}
int vlist_strlen(vlist* ptr) {
    int length = -1;
    struct Node* move = ptr->ptr;
    while (1) {
        if (move==0) break;
        move = move->next;
        length++;
    }
    return length;
}
struct Node* vlist_fget(vlist* ptr, int size) {
    struct Node* move = ptr->ptr;
    if (size>vlist_strlen(ptr)) return 0;
    for (int i=0; i<size+1; i++) move = move->next;
    return move;
}
void* vlist_get(vlist* ptr, int size) {
    struct Node* move = vlist_fget(ptr, size);
    return move->content;
}
void vlist_append(vlist* ptr, struct Node* fail, void* content) {
    struct Node* find = ptr->ptr;
    struct Node* move = (struct Node*)malloc(sizeof(struct Node));
    int length = vlist_strlen(ptr);
    for (int i=0; i<length+1; i++) {
        if (find==fail) break;
        find = find->next;
        if (i==length) return;
    }
    move->content = content;
    move->next = find->next;
    move->back = find;
    if (move->next!=0) move->next->back = move;
    find->next = move;
}
void vlist_remove(vlist* ptr, struct Node* fail) {
    struct Node* find = ptr->ptr;
    int length = vlist_strlen(ptr);
    for (int i=0; i<length+1; i++) {
        if (find==fail) break;
        find = find->next;
        if (i==length) return;
    }
    find->back->next = find->next;
    if (find->next!=0) find->next->back = find->back;
    free(find);
}
void vlist_clear(vlist* ptr) {
    struct Node* find = ptr->ptr;
    while (find!=0) find = find->next;
    while (1) {
        struct Node* move = find->back;
        if (find==ptr->ptr) break;
        free(find);
        find = move;
    }
    return;
}
