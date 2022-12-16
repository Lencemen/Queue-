#include <iostream>
using namespace std;
#define MAX 100
void enqueue(int queue[],int *front,int *rear,int item){
    if (*rear==MAX-1){
        cout<<"Queue is Full"<<endl;
        return;
    }
    if (*front==-1){
        *front=*rear=0;
    }
    else{
        *rear++;
    }
    queue[*rear]=item;
}
void dequeue(int queue[],int *front,int *rear){
    if (*front==-1){
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<"deleted element is "<<queue[*front];
    if (*front==*rear){
        *front=*rear=-1;
    }
    else{
        *front++;
    }
}
void display(int queue[],int front,int rear){
    if(front==-1){
        cout<<"queue is empty"<<endl;
        return;
    }
    for(int i=front;i<=rear;i++){
        cout<<queue[i]<<endl;
    }
}
int main(){
int queue[MAX],choice,item,front=-1,rear=-1;
while(1){
    cout<<"Welcome to linear Queue Program"<<endl;
    cout<<"Enter Choice"<<endl;
    cout<<"1.Enqueue"<<endl;
    cout<<"2.Dequeue"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Exit"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Enter item"<<endl;
        cin>>item;
        enqueue(queue,&front,&rear,item);
        break;
        case 2:
        dequeue(queue,&front,&rear);
        break;
        case 3:
        display(queue,front,rear);
        break;
        default:
        exit(1);
    }
}
return 0;
}
