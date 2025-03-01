#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int num;
    struct node *next;
} Node;

Node* CreateNewNode(int num);
Node* CreateNewList(int len);
void PrintList(Node *L);
Node* SortList(Node *L1, int len);
Node* MergeList(Node *L1, Node *L2);

int main() {
    srand(time(0)); // 只调用一次，避免随机数重复

    Node *pa = CreateNewList(5);
    Node *pb = CreateNewList(7);

    PrintList(pa);
    PrintList(pb);

    pa = SortList(pa, 5);
    pb = SortList(pb, 7);

    PrintList(pa);
    PrintList(pb);

    Node *mergedList = MergeList(pa, pb);
    PrintList(mergedList);

    return 0;
}

Node* CreateNewNode(int num) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->num = num;
    new_node->next = NULL;
    return new_node;
}

Node* CreateNewList(int len) {
    Node *L = CreateNewNode(-1);
    Node *p = L;
    for (int i = 0; i < len; i++) {
        Node *now_node = CreateNewNode(rand() % 100);
        p->next = now_node;
        p = p->next;
    }
    return L;
}

void PrintList(Node *L) {
    Node *p = L->next;
    while (p) {
        printf("%d ", p->num);
        p = p->next;
    }
    printf("\n");
}

Node* SortList(Node *L1, int len) {
    if (!L1 || !L1->next) return L1;

    for (int i = 0; i < len - 1; i++) {
        Node *p = L1->next;
        Node *prev = L1;
        while (p && p->next) {
            if (p->num < p->next->num) {
                Node *temp = p->next;
                p->next = temp->next;
                temp->next = p;
                prev->next = temp;
            }
            prev = p;
            p = p->next;
        }
    }
    return L1;
}

Node* MergeList(Node *L1, Node *L2) {
    Node *dummy = CreateNewNode(-1);
    Node *p = dummy, *p1 = L1->next, *p2 = L2->next;

    while (p1 && p2) {
        if (p1->num >= p2->num) {
            p->next = p1;
            p1 = p1->next;
        } else {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    p->next = p1 ? p1 : p2;
    
    return dummy->next;
}
