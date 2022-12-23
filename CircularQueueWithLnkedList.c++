#include <iostream>
using namespace std;
#define MAX 100
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
int main(){
node queue[MAX],*front,*rear;
front=NULL,rear=NULL;
int choice,item;
while(1){
    cout<<"Welcome to Circular Queue program"<<endl;
    cout<<"Enter your Choice"<<endl;
    cout<<"1.Enqueue"<<endl;
    cout<<"2.Dequeue"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Exit"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Enter item"<<endl;
        cin>>item;
        enqueue(&front,&rear,item);
        break;
        case 2:
        dequeue(&front,&rear);
        break;
        case 3:
        display(front,rear);
        break;
        default:
        exit(1);
    }
}
}
