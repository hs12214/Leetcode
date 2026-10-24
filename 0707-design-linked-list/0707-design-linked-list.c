typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node dummy;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = malloc(sizeof(MyLinkedList));
    obj->dummy.next = NULL;
    obj->size = 0;
    return obj;
}

Node* nodeBefore(MyLinkedList* obj, int index) {
    Node* cur = &obj->dummy;
    for (int i = 0; i < index; i++) cur = cur->next;
    return cur;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;
    return nodeBefore(obj, index)->next->val;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) return;
    Node* prev = nodeBefore(obj, index);
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = prev->next;
    prev->next = node;
    obj->size++;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, obj->size, val);
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;
    Node* prev = nodeBefore(obj, index);
    Node* gone = prev->next;
    prev->next = gone->next;
    free(gone);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* cur = obj->dummy.next;
    while (cur) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/