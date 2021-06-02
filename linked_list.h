typedef struct {
    int data;
    struct Node * next;
} Node;

void list_init(Node ** pHead, int data);
int list_length(Node ** pHead);
int list_get(Node ** pHead, int index);
void list_delete(Node ** pHead, int index);
int list_index_errno(Node ** pHead, int index);
void list_add(Node ** pHead, int index, int data);
void list_show(Node ** pHead);
void list_push(Node ** pHead, int data);
void list_unshift(Node ** pHead);
void list_pop(Node ** pHead);
void list_shift(Node ** pHead);
void list_clear(Node ** pHead);
