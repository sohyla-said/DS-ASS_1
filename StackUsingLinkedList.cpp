// Stack using linked list

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};
class Stack{
private:
    Node *top;
    int size=0;
public:
    Stack(){top = NULL;}
    void push(int x);
    int pop();
    void Display();
    int isFull();
    int isEmpty();
    int Size();
    int Top();
    void Clear();
};
void Stack::push(int x){
    Node*t = new Node;
    if(t==NULL)
        cout<<"Stack is Full\n";
    else{
        t->data = x;
        t->next = top;
        top = t;
        size++;
    }
}
int Stack::pop(){
    int x=-1;
    if(top == NULL)
        cout<<"Stack is empty\n";
    else{
        x=top->data;
        Node *t=top;
        top = top->next;
        size--;
        delete t;
    }
    return x;
}
void Stack::Display(){
    Node *p=top;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int Stack::isFull() {
    Node *t =new Node;
    int r=t?1:0;
    delete t;
    return r;
}
int Stack::isEmpty() {
    return top?0:1;
}
int Stack::Top(){
    if(top)
        return top->data;
    return -1;
}
int Stack::Size(){
    return size;
}
void Stack::Clear(){
    while(top!=NULL)
    {
        pop();
    }
}
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.isEmpty()<<endl;
    st.Display();
}
