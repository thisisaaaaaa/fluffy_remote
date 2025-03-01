#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*旨在以节点中数据的大小，从大到小合并两个链表*/

typedef struct node{
    int num;
    struct node *next;
}Node;

Node* CreateNewNode(int num);
Node* CreateNewList(int len);
void PrintList(Node *L);
Node* SortList(Node *L1,int len);
Node* MergeList(Node *L1,Node *L2);

int main(){
    srand(time(0));//

    Node *pa = CreateNewList(5);
    Node *pb = CreateNewList(7);

    PrintList(pa);
    PrintList(pb);

    SortList(pa,5);
    SortList(pb,7);

    PrintList(pa);
    PrintList(pb);

    PrintList(MergeList(pa,pb));//
}


Node* CreateNewNode(int num){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node -> num = num;
    new_node -> next = NULL;//
    return new_node;
}

Node* CreateNewList(int len){
    
    Node *L = CreateNewNode(-1);
    Node *p = L;
    for(int i = 0;i < len;i ++){
        Node *now_node = CreateNewNode(rand() % 100);//
        p -> next = now_node;
        p = p -> next;
        /*now_node -> next = NULL;*/
    }
    return L;
}

void PrintList(Node *L){
    Node *p = L -> next;//
    while(p){
        printf("%d ",p -> num);
        p = p -> next;
    }
    printf("\n");
}

Node* SortList(Node *L1,int len){
    if(!L1 || !L1 -> next) return L1;
    for(int i = 0;i < len - 1;i ++){
        Node *p1 = L1 -> next;
        Node *pre = L1;
        while(p1 && p1->next){
            if(p1 -> num < p1->next->num){
                Node *temp = p1 -> next;
                p1 -> next = temp -> next;
                temp -> next = p1;
                pre -> next = temp;
            }
            pre = p1;
            p1 = p1 -> next;
        }
    }
    return L1;
}

Node* MergeList(Node *L1,Node *L2){
    Node *p1 = L1 -> next,*p2 = L2 -> next;
    Node *p = L1;

    while(p1 && p2){
        if(p1 -> num < p2 -> num){
            p -> next = p2;
            p2 = p2 -> next;
        }else {
            p -> next = p1;
            p1 = p1 -> next;
        }
        p = p -> next; 
    }
    p -> next = p1 ? p1 : p2;
    return L1;
}