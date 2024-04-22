#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Queue {
private:
    int first, last;
    T* arr;
    int size;
    int length;
public:
    Queue(int s);
    bool isEmpty();
    bool isFull();
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
Queue<T>::Queue(int s) {
    size = s;
    length=0;
    first = last = -1;
    arr = new T[size];
}
template<typename T>
bool Queue<T>::isEmpty() {
    return first == -1;
}
template<typename T>
bool Queue<T>::isFull() {
    return first==0 && last==size-1 || last == first -1;
}
template<typename T>
T Queue<T>::front() {
    if(first == -1) {
        cout<<"Queue is empty ";
        return T();
    }
    return arr[first];
}
template<typename T>
T Queue<T>::back() {
    if(first == -1) {
        cout<<"Queue is empty ";
        return T();
    }
    return arr[last];
}
template<typename T>
void Queue<T>::print() {
    if (first == -1)
        cout<<"Can't print, Queue is empty \n";
    else {
        if (last>=first)
            for(int i=first;i<=last;i++)
                cout<<arr[i]<<' ';
        else{
            for(int i=first;i<size;i++)
                cout<<arr[i]<<' ';
            for(int i=0;i<=last;i++)
                cout<<arr[i]<<' ';
    }
        cout<<endl;
    }
}
template<typename T>
int Queue<T>::Size() {
    return length;
}
template<typename T>
void Queue<T>::enqueue(T el) {
    if(!isFull()) {
        if(last == -1 || last == size-1) {
            arr[0] = el;
            last=0;
            if(first == -1)
                first=0;
        }
        else {
            arr[++last] = el;
        }
        length++;
    }
    else {
        cout<<"Queue is full, can't insert \n";
    }
}
template<typename T>
T Queue<T>::dequeue() {
    //if the queue is empty
    if(first==-1) {
        cout<<"Can't dequeue, Queue is empty \n";
        return T();
    }
    else {
        T temp = arr[first];
        //if there is only 1 element in the array
        if(first==last) {
            first=last=-1;
        }
        else if(first == size-1) {
            first = 0;
        }
        else {
            first++;
        }
        length--;
        return temp;
    }

}
template<typename T>
void Queue<T>::clear() {
    first  = last= -1;
}
template<typename T>
Queue<T>::~Queue() {
    delete[] arr;
}

class test {
private:
    int x,y;
public:
    test(){};
    test(int xx,int yy){x=xx;y=yy;}
    friend ostream& operator<<(ostream& os, const test t) {
        os <<t.x<<' '<<t.y<<endl;
        return os;
    }
};
// int main() {
//     Queue<int> q1(4);
//     q1.enqueue(1);
//     q1.enqueue(2);
//     q1.enqueue(3);
//     q1.enqueue(4);
//     q1.print();
//     cout<<q1.dequeue()<<endl;
//     q1.enqueue(7);
//     q1.print();
//     cout<<q1.Size()<<endl;
//     cout<<q1.front()<<' '<<q1.back()<<endl;
//     // q1.clear();
//     // q1.print();
//     cout<<q1.dequeue()<<endl;
//     cout<<q1.dequeue()<<endl;
//     cout<<q1.Size()<<endl;
//     cout<<q1.dequeue()<<endl;
//     cout<<q1.dequeue()<<endl;

    // cout<<q1.front()<<' '<<q1.back()<<endl;
    // cout<<q1.Size();

    // Queue<string> q2(5);
    // q2.print();
    // q2.enqueue("sohyla");
    // q2.enqueue("ahmed");
    // q2.enqueue("farida");
    // q2.enqueue("farah");
    // q2.enqueue("sandy");
    // q2.enqueue("hassan");
    // q2.print();
    // cout<<"size: "<<q2.Size();
    // cout<<q2.dequeue()<<endl;
    // cout<<q2.dequeue()<<endl;
    // cout<<q2.dequeue()<<endl;
    // q2.enqueue("hassan");
    // q2.print();
    // cout<<"size: "<<q2.Size()<<endl;
    // cout<<q2.isFull()<<endl;

    // test t1(1,1);
    // test t2(2,2);
//     test t3(3,3);
//     Queue<test> q3(3);
//     q3.enqueue(t1);
//     q3.enqueue(t2);
//     q3.enqueue(t3);
//     q3.enqueue(t1);
//     q3.print();
//     cout<<q3.front();
//     cout<<q3.back();
//     q3.dequeue();
//     q3.print();
// }