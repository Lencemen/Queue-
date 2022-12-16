#include <iostream>
using namespace std;
typedef struct nodetype{
    int info;
    struct nodetype *next;
}node;
void enqueue(node **front,node **rear,int item){
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->info=item;
    if(*front==NULL){
        cout<<"LL is empty"<<endl;
        ptr->next=ptr;
        *front=*rear=ptr;
    }
    else{
        ptr->next=(*rear)->next;
        (*rear)->next=ptr;
        *rear=ptr;
    }
}
void dequeue(node **front,node **rear){
    node *ptr;
    if(*front==NULL){
        cout<<"LL is empty"<<endl;
        return;
    }
    ptr=*front;
    cout<<"deleted item is "<<ptr->info;
    if(*front==*rear){
        *front=*rear=NULL;
    }
    else{
        *front=ptr->next;
        (*rear)->next=ptr->next;
    }
    free(ptr);
}
void display(node *front,node *rear){
    if(front==NULL){
        cout<<"LL is empty"<<endl;
        return;
    }
    while(front!=rear){
        cout<<front->info<<endl;
        front=front->next;
    }
        cout<<rear->info<<endl;
}
