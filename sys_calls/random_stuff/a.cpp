#include<stdio.h>
int queue[256];
int stack[256];
int qc=0,st=0;
void push_Queue(int n){
    queue[qc++]=n;
}
int pop_Queue(){
    if(qc == 0)
    return -1;
    int front = queue[0];
    qc--;
    for(int i=0;i<qc;i++)
    queue[i]=queue[i+1];
    return front;
}    
void push_Stack(int n){
    stack[st++]=n;
}
int pop_Stack(){
    st--;
    if(st<0)
    return -1;
    int top = stack[st];
    return top;
}
int main()
{
    push_Queue(1);
    push_Queue(2);
    push_Queue(3);
    push_Queue(4);

    for(int i=0;i<5;i++)
    printf("%d\n",pop_Queue());

    printf("\n");
    push_Stack(1);
    push_Stack(2);
    push_Stack(3);
    push_Stack(4);

    for(int i=0;i<5;i++)
    printf("%d\n",pop_Stack());
}