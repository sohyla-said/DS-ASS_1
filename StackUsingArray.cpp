// Stack using Array

#include<bits/stdc++.h>
using namespace std;

class Stack{
private:
    int size;
    int top;
    int *s;
    int cnt =0;
public:
    Stack(){top = NULL;}
    void Create(int sizee);
    void push(int x);
    int pop();
    void display();
    int isEmpty();
    int isFull();
    int Top();
    int Size();
    void Clear();
};
void Stack::Create(int size){
    this->size = size;
    top = -1;
    s = new int[size];
}
void Stack::display(){
    for(int i=top;i>=0;i--){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
void Stack::push(int x){
    if(top == size-1)
        cout<<"Stack Overflow\n";
    else{
        top ++;
        s[top]=x;
        cnt++;
    }
}
int Stack::pop(){
    int x=-1;
    if(top==-1)
        cout<<"Stack is empty\n";
    else{
        x=s[top--];
        cnt--;
    }
    return x;
}
int Stack::isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}
int Stack::isFull(){
    return top == size - 1;
}
int Stack::Top(){
    if(!isEmpty())
        return s[top];
    else
        return -1;
}
int Stack::Size(){
    return cnt;
}

void Stack::Clear() {
    while (top != -1){
        pop();
    }
}

int main(){
    Stack st;
    st.Create(4);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(40);
    st.pop();
    cout<<st.Top()<<endl;
    cout<<st.Size()<<endl;
    if(st.isEmpty())
        cout<<"YES"<<endl;
    else
        cout<<"No"<<endl;
    if(st.isFull())
        cout<<"YES"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
