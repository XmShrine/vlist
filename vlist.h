
#ifndef vlist_h
#define vlist_h

#include <stdlib.h>
#include <string.h>
#define malloction(p)               \
void* malloction_##p(p t) {         \
void* pointer = malloc(sizeof(p));  \
*(p*)pointer  = t;                  \
return pointer;}
#define mallocation_char                    \
char* mallocation_str(char* t) {            \
char* pointer = (char*)malloc(strlen(t));   \
for (int i=0; i<strlen(t); i++)             \
pointer[i] = t[i];                          \
return pointer;}

struct Node {
    struct Node* next;
    struct Node* back;
    void* content;
};

typedef struct {
    struct Node* ptr;
}vlist;

vlist* vlist_init(void);
int vlist_strlen(vlist* ptr);
struct Node* vlist_fget(vlist* ptr, int size);
struct Node* vlist_fget_begin(vlist* ptr);
struct Node* vlist_fget_end(vlist* ptr);
void* vlist_get_front(vlist* ptr);
void* vlist_get_back(vlist* ptr);
void* vlist_get(vlist* ptr, int size);
void vlist_append(vlist* ptr, struct Node* fail, void* content);
void vlist_remove(vlist* ptr, struct Node* fail);
void vlist_clear(vlist* ptr);
void vlist_push_front(vlist* ptr, void* content);
void vlist_push_back(vlist* ptr, void* content);
#endif /* vlist_h */
