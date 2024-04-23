#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct node {
    T info;
    node<T>* next;
};
template<typename T>
class Queue {
private:
    node<T> *first;
    node<T> *last;
    int length;
public:
    Queue();
    bool isEmpty();
    // bool isFull();
    void clear();
    T front();
    T back();
    void print();
    int Size();
    void enqueue(T el);
    T dequeue();
    ~Queue();
};
template<typename T>
Queue<T>::Queue() {
    first = last = nullptr;
    length=0;
}
template<typename T>
bool Queue<T>::isEmpty() {
    return first == nullptr;
}
template<typename T>
T Queue<T>::front() {
    assert(first!=nullptr);
    return first->info;
}
template<typename T>
T Queue<T>::back() {
    assert(last!=nullptr);
    return last->info;
}
template<typename T>
void Queue<T>::print() {
    if(first == nullptr) {
        cout<<"Queue is empty\n";
        return;
    }
    node<T>* current = first;
    while(current != nullptr) {
        cout<<current->info<<' ';
        current = current -> next;
    }
    cout<<endl;
}
template<typename T>
int Queue<T>::Size() {
    return length;
}
template<typename T>
void Queue<T>::enqueue(T el) {
    node<T>* newnode = new node<T>;
    newnode->info = el;
    newnode -> next = nullptr;
    if(first == nullptr) {
        first = last = newnode;
    }
    else {
        last -> next = newnode;
        last = newnode;
    }
    length++;
}
template<typename T>
T Queue<T>::dequeue() {
    if(first == nullptr) {
        cout<<"Queue is empty, can't dequeue";
        return T();
    }
    node<T>* current = first;
    T val;
    first = first->next;
    val = current -> info;
    if(first == nullptr)
        last=nullptr;
    delete current;
    length--;
    return val;
}
template<typename T>
void Queue<T>::clear() {
    node<T> *current;
    while(first != nullptr) {
        current = first;
        first = first->next;
        delete current;
    }
    last = nullptr;
    length = 0;
}
template<typename T>
Queue<T>::~Queue() {
    clear();
}

int main() {
     Queue<int> q1;
     q1.enqueue(1);
     q1.enqueue(2);
     q1.enqueue(3);
     q1.enqueue(4);
     q1.print();
     cout<<q1.dequeue()<<endl;
     q1.enqueue(7);
     q1.print();
     cout<<q1.Size()<<endl;
     cout<<q1.front()<<' '<<q1.back()<<endl;
     // q1.clear();
     // q1.print();
     cout<<q1.dequeue()<<endl;
     cout<<q1.dequeue()<<endl;
     cout<<q1.Size()<<endl;
     cout<<q1.dequeue()<<endl;
     cout<<q1.dequeue()<<endl;
     q1.print();
     q1.enqueue(8);
     cout<<q1.front()<<' '<<q1.back()<<endl;
     cout<<q1.Size();

     Queue<string> q2;
     q2.print();
     q2.enqueue("sohyla");
     q2.enqueue("ahmed");
     q2.enqueue("farida");
     q2.enqueue("farah");
     q2.enqueue("sandy");
     q2.enqueue("hassan");
     q2.print();
     cout<<"size: "<<q2.Size();
     cout<<q2.dequeue()<<endl;
     cout<<q2.dequeue()<<endl;
     cout<<q2.dequeue()<<endl;
     q2.enqueue("hassan");
     q2.print();
     cout<<"size: "<<q2.Size()<<endl;
     cout<<q2.isEmpty()<<endl;
     q2.clear();
     cout<<boolalpha<<q2.isEmpty()<<endl;
}