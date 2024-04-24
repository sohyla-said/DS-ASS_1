#include<bits/stdc++.h>
using namespace std;
// Stack using Array
template <typename T>
class Stack{
private:
    int size;
    int top;
    T *s;
    int cnt =0;
public:
    Stack(){top = -1;}
    void Create(int size);
    void push(T x);
    T pop();
    void display();
    bool isEmpty();
    bool isFull();
    T Top();
    int Size();
    void Clear();
    ~Stack();
};
template <typename T>
void Stack<T>::Create(int size){
    this->size = size;
    top = -1;
    s = new T[size];
}
template <typename T>
void Stack<T>::display(){
    for(int i=top;i>=0;i--){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
template <typename T>
void Stack<T>::push(T x){
    if(top == size-1)
        cout<<"Stack Overflow\n";
    else{
        top ++;
        s[top]=x;
        cnt++;
    }
}
template <typename T>
T Stack<T>::pop(){
    T x;
    if(top==-1)
        cout<<"Stack is empty\n";
    else{
        x=s[top--];
        cnt--;
    }
    return x;
}
template <typename T>
bool Stack<T>::isEmpty(){
    if(top==-1)
        return true;
    else
        return false;
}
template <typename T>
bool Stack<T>::isFull(){
    return top == size - 1;
}
template<typename T>
T Stack<T>::Top() { // check again
    if (!isEmpty()&& top >= 0)
        return s[top];
    else
        return T();
}
template <typename T>
int Stack<T>::Size(){
    return cnt;
}
template <typename T>
void Stack<T>::Clear() {
    while (top != -1){
        pop();
    }
}
template<class T>
Stack<T>::~Stack() {
    delete []s;
}
int main(){
    Stack<int> st;
    st.Create(4);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(40);
//    st.pop();
    cout<<st.Top()<<endl;
    cout<<st.Size()<<endl;
    st.Clear();
    if(st.isEmpty())
        cout<<"YES"<<endl;
    else
        cout<<"No"<<endl;
    if(st.isFull())
        cout<<"YES"<<endl;
    else
        cout<<"No"<<endl;
    cout<<st.Top()<<endl;


    Stack<string> strStack;
    strStack.Create(3);
    strStack.push("Hello");
//    strStack.push("World");
//    strStack.Clear();
    cout << strStack.Top() << endl;
    cout << strStack.Size() << endl;
    strStack.display();
    return 0;
}
