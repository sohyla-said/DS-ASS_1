#include<bits/stdc++.h>
using namespace std;

// Stack using linked list
template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
};
template <typename T>
class Stack{
private:
    Node <T>*top;
    int size=0;
public:
    Stack(){top = NULL;}
    void push(T x);
    T pop();
    void Display();
    T isFull();
    T isEmpty();
    T Size();
    T Top();
    void Clear();
};
template <typename T>
void Stack<T>::push(T x){
    Node<T>*t = new Node<T>;
    if(t==NULL)
        cout<<"Stack is Full\n";
    else{
        t->data = x;
        t->next = top;
        top = t;
        size++;
    }
}
template <typename T>
T Stack<T>::pop(){
    T x;
    if(top == NULL)
        cout<<"Stack is empty\n";
    else{
        x=top->data;
        Node<T> *t=top;
        top = top->next;
        size--;
        delete t;
    }
    return x;
}
template <typename T>
void Stack<T>::Display(){
    Node<T> *p=top;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
template <typename T>
T Stack<T>::isFull() {
    Node<T> *t =new Node<T>;
    int r=t?1:0;
    delete t;
    return r;
}
template <typename T>
T Stack<T>::isEmpty() {
    return top?0:1;
}
template <typename T>
T Stack<T>::Top(){
    if(top)
        return top->data;
    return -1;
}
template <typename T>
T Stack<T>::Size(){
    return size;
}
template <typename T>
void Stack<T>::Clear(){
    while(top!=NULL)
    {
        pop();
    }
}
int main(){
    Stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.isEmpty()<<endl;
    st.Display();


    Stack<string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.Display();
}
