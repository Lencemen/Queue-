#include <iostream>
using namespace std;
#define MAX 100
void enqueue_rear(int queue[],int *front,int *rear,int item){
    if(*front==(*rear+1)%MAX){
        cout<<"Overflow"<<endl;
        return;
    }
    if(*front==-1){
        *front=*rear=0;
    }
    else{
        *rear=(*rear+1)%MAX;
    }
    queue[*rear]=item;
}
void dequeue_front(int queue[],int *front,int *rear){
    if(*front==-1){
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<"deleted item "<<queue[*front]<<endl;
    if(*front==*rear){
        *front=*rear=-1;
    }
    else{
        *front=(*front+1)%MAX;
    }
}
void display(int queue[],int front,int rear){
    if(front==-1){
        cout<<"underflow"<<endl;
        return;
    }
    if(front<=rear){
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<endl;
        }
    }
    else{
        for(int i=front;i<MAX;i++){
            cout<<queue[i]<<endl;
        }
        for(int i=0;i<=rear;i++){
            cout<<queue[i]<<endl;
        }
    }
}
int main(){
int queue[MAX],front=-1,rear=-1,choice,item;
while(1){
    cout<<"Welcome  to Circular Queue Program"<<endl;
    cout<<"Enter choice"<<endl;
    cout<<"1.Enqueue Rear"<<endl;
    cout<<"2.Dequeue Front"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Exit"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Enter item"<<endl;
        cin>>item;
        enqueue_rear(queue,&front,&rear,item);
        break;
        case 2:
        dequeue_front(queue,&front,&rear);
        break;
        case 3:
        display(queue,front,rear);
        break;
        case 4:
        exit(1);
    }
}
return 0;
}