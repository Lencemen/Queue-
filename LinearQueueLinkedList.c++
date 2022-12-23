#include <iostream>
using namespace std;
#define MAX 100
typedef struct nodetype {
    int info;
    struct nodetype *next;
}node;
void enqueue(node **front,node **rear,int item){
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->info=item;
    ptr->next=NULL;
    if(*front==NULL){
        *front=*rear=ptr;
    }
    else{
        (*rear)->next=ptr;
        *rear=ptr;
    }
}
void dequeue(node **front,node **rear){
    node *ptr;
    if(*front==NULL){
        cout<<"queue is empty"<<endl;
        return;
    }
    ptr=*front;
    cout<<"deleted value is "<<ptr->info;
    if(*front==*rear){
        *front=*rear=NULL;
    }
    else{
        *front=ptr->next;
    }
    free(ptr);
}
void display(node *front,node *rear){
    if(front==NULL){
        cout<<"queue is empty"<<endl;
        return;
    }
    while(front!=rear){
        cout<<front->info<<endl;
        front=front->next;
    }
    cout<<rear->info<<endl;
}
int main(){
    node queue[MAX];
    node *front,*rear;
    front=NULL;
    rear=NULL;
    int choice,item;
    while(1){
        cout<<"Welcome to Queue "<<endl;
        cout<<"Enter choice"<<endl;
        cout<<"1.Enqueue"<<endl;
        cout<<"2.Dequeue"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter Item"<<endl;
            cin>>item;
            enqueue(&front,&rear,item);
            break;
        case 2:
            dequeue(&front,&rear);
            break;
        case 3:
            display(front,rear);
        default:
        exit(1);
        }
    }
return 0;
}
