// Double Linked List
#include <bits/stdc++.h>
using namespace std;
template <class T>
class Node{
public:
    T data;
    Node<T> *next;
    Node<T>* prev;
    Node(T element){
        data=element;
        next=NULL;
        prev=NULL;
    }

};
template <class T>
class DoubleLinkedList{
private:
    Node<T>* head;
    Node<T>* last;
    int size;
public:
    DoubleLinkedList(){
        head=NULL;
        last = NULL;
        size = 0;

    }
    void insertAtHead (T element);
    void insertAtTail (T element);
    void insertAt (T element, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt (T newElement, int index);
    bool isExist (T element);
    bool isItemAtEqual(T element, int index);
    void swap(T firstItemIdx,T secondItemIdx);
    bool isEmpty();
    int Size();
    void clear();
    void print();

};

template <class T>
void DoubleLinkedList<T>::insertAtHead(T element){
    Node<T>* newNode = new Node<T>(element);
    if (head == NULL) {
        head = newNode;
        last = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}
template <class T>
void DoubleLinkedList<T>::insertAtTail(T element) {
    Node<T> *newNode = new Node<T>(element);
    if (last == NULL) {
        head = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }
    size++;
}

template <class T>
void DoubleLinkedList<T>::insertAt(T element, int index) {
    if (index < 0 || index > size) {
        cerr << "Index out of list"<<endl;
        return;
    }
    if (index == 0) {
        insertAtHead(element);
    } else if (index == size) {
        insertAtTail(element);
    } else {
        Node<T> *newNode = new Node<T>(element);
        Node<T>* current = head;
        int i = 0;
        while (i < index - 1 && current != NULL) {
            current = current->next;
            i++;
        }
        if (current == NULL) {
            cerr << "Index out of list"<<endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        size++;
    }
}
template <class T>
void DoubleLinkedList<T>::removeAtHead() {
    if(head == NULL){ //means empty list
        cerr<<"sorry, List is empty cannot delete from empty list";
        return;
    }
    Node<T> *temp = head;
    head = head->next;
    if (head != NULL){
        head->prev=NULL;
    }
    else{
        last = NULL;
    }
    delete temp;
    size--;

}
template <class T>
void DoubleLinkedList<T>::removeAtTail(){
    if(last == NULL){ //means empty list
        cerr<<"sorry, List is empty cannot delete from empty list";
        return;
    }
    Node<T> *temp = last;
    last = last->prev;
    if (last != NULL) {
        last->next = NULL;
    } else {
        head = NULL;
    }
    delete temp;
    size--;
}
template <class T>
void DoubleLinkedList<T>::removeAt(int index){
    if (index < 0 || index > size) {
        cerr << "Index out of list"<<endl;
        return;
    }
    if (index == 0) {
        removeAtHead();
        return;
    }
    else if (index == size-1) {
        removeAtTail();
        return;
    }
    Node<T> *current = head;
    int i = 0;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;

}
template <class T>
T DoubleLinkedList<T>::retrieveAt(int index) {
    if (index < 0 || index >= size) {
        cerr << "Index out of list"<<endl;
        return T();
    }
    Node<T> *current = head;
    int i=0;
    while(current != NULL && i < index){
        current = current->next;
        i++;
    }
    return current->data;
}
template <class T>
void DoubleLinkedList<T>::replaceAt(T newElement, int index) {
    if (index < 0 || index >= size) {
        cerr << "Index out of list"<<endl;
        return;
    }
    Node<T> *current = head;
    int i=0;
    while(current != NULL && i < index){
        current = current->next;
        i++;
    }
    current->data = newElement;
}

template <class T>
bool DoubleLinkedList<T>::isExist(T element) {
    bool found = false;
    Node<T> *current = head;
    while(current != NULL){
        if(current->data == element){
            return found = true;
        }
        else{
            current = current->next;
        }
    }
    return found;

}
template<class T>
bool DoubleLinkedList<T>::isItemAtEqual(T element, int index) {
    if (index < 0 || index >= size) {
        cerr << "Index out of list"<<endl;
        return false;
    }
    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    if(current->data == element)
        return true;
    else
        return false;
}

template<class T>
void DoubleLinkedList<T>::swap(T firstItemIdx, T secondItemIdx) {
    if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size) {
        cerr << "Index out of list"<<endl;
        return;
    }
    if (isEmpty()) {
        cerr << "sorry, List is empty!" << endl;
        return;
    }
    if (firstItemIdx == secondItemIdx) {
        cerr << "sorry, items with same index can not be swapped!" << endl;
        return;
    }
    Node<T>* firstNode = head;
    for (int i = 0; i < firstItemIdx; i++) {
        firstNode = firstNode->next;
    }

    Node<T>* secondNode = head;
    for (int i = 0; i < secondItemIdx; i++) {
        secondNode = secondNode->next;
    }

    T temp = firstNode->data;
    firstNode->data = secondNode->data;
    secondNode->data = temp;
}




template <class T>
bool DoubleLinkedList<T>::isEmpty() {
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}
template <class T>
int DoubleLinkedList<T>::Size() {
    return size;
}
template <class T>
void DoubleLinkedList<T>::clear() {
    while (head != NULL) {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    last = NULL;
    size = 0;
    cout<<"list is cleared!"<<endl;
}
template <class T>
void DoubleLinkedList<T>::print() {
    Node<T>* temp=head;
    while(temp!=NULL){
        cout <<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    DoubleLinkedList<int> dll;
    if(dll.isEmpty())
        cout<<"List is empty!"<<endl;
    else
        cout<<"List is not empty!"<<endl;
    dll.insertAtHead(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.insertAt(25, 2);
    dll.print();
    dll.removeAt(1);
    dll.print();
    cout << "Item at index 1: " << dll.retrieveAt(1) <<endl;
    dll.replaceAt(100, 1);
    dll.print();

    if(dll.isExist(11))
        cout <<"element is found!"<<endl;
    else
        cout <<"element not found!"<<endl;

    cout << "the size of list is: " << dll.Size() << endl;

    if(dll.isItemAtEqual(10,0))
        cout <<"element is at equal!"<<endl;
    else
        cout <<"element not at equal!"<<endl;

    dll.swap(0, 1);
    dll.print(); //100 10 30

    //dll.clear();

    return 0;
}