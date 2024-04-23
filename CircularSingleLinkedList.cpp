#include <bits/stdc++.h>
using namespace std;
template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T element) {
        data = element;
        next = NULL;
    }
};

template <class T>
class CircularSingleLinkedList {
private:
    Node<T>* head;
    int size;

public:
    CircularSingleLinkedList() {
        head = NULL;
        size = 0;
    }

    ~CircularSingleLinkedList() {
        clear();
    }

    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertAt(T element, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T newElement, int index);
    bool isExist(T element);
    bool isItemAtEqual(T element, int index);
    void swap(int firstItemIdx, int secondItemIdx);
    bool isEmpty();
    int Size();
    void clear();
    void print();
};

template <class T>
void CircularSingleLinkedList<T>::insertAtHead(T element) {
    Node<T>* newNode = new Node<T>(element);
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        newNode->next = head;
        Node<T>* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        head = newNode;
    }
    size++;
}

template <class T>
void CircularSingleLinkedList<T>::insertAtTail(T element) {
    if (head == NULL) {
        insertAtHead(element);
        return;
    }
    Node<T>* newNode = new Node<T>(element);
    Node<T>* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    size++;
}

template <class T>
void CircularSingleLinkedList<T>::insertAt(T element, int index) {
    if ( index > size||index < 0  ) {
        cerr << "index out of the  list" << endl;
        return;
    }
    if (index == 0) {
        insertAtHead(element);
    } else if (index == size) {
        insertAtTail(element);
    } else {
        Node<T>* newNode = new Node<T>(element);
        Node<T>* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
}

template <class T>
void CircularSingleLinkedList<T>::removeAtHead() {
    if (head == NULL) {
        cerr << "List is empty, cannot delete from empty list" << endl;
        return;
    }
    Node<T>* temp = head;
    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node<T>* lastNode = head;
        while (lastNode->next != head) {
            lastNode = lastNode->next;
        }
        lastNode->next = head->next;
        head = head->next;
        delete temp;
    }
    size--;
}

template <class T>
void CircularSingleLinkedList<T>::removeAtTail() {
    if (head == NULL) {
        cerr << "List is empty, cannot delete from empty list" << endl;
        return;
    }
    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node<T>* temp = head;
        Node<T>* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }
    size--;
}
template <class T>
void CircularSingleLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= size) {
        cerr << "Index out of the list" << endl;
        return;
    }
    if (index == 0) {
        removeAtHead();
    } else if (index == size - 1) {
        removeAtTail();
    } else {
        Node<T>* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node<T>* temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }
}
template <class T>
T CircularSingleLinkedList<T>::retrieveAt(int index) {
    if (index >= size || index < 0 ) {
        cerr << "index out of the list " << endl;
        return T();
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <class T>
void CircularSingleLinkedList<T>::replaceAt(T newElement, int index) {
    if (index >= size ||index < 0  ) {
        cerr << "index out of the list" << endl;
        return;
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = newElement;
}

template <class T>
bool CircularSingleLinkedList<T>::isExist(T element) {
    Node<T>* current = head;
    do {
        if (current->data == element) {
            return true;
        }
        current = current->next;
    } while (current != head);
    return false;
}

template <class T>
bool CircularSingleLinkedList<T>::isItemAtEqual(T element, int index) {
    if ( index >= size|| index < 0) {
        cerr << "index out of the list" << endl;
        return false;
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data == element;
}

template <class T>
void CircularSingleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx == secondItemIdx || isEmpty() || size == 1) {
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
bool CircularSingleLinkedList<T>::isEmpty() {
    return head == NULL;
}

template <class T>
int CircularSingleLinkedList<T>::Size() {
    return size;
}

template <class T>
void CircularSingleLinkedList<T>::clear() {
    while (!isEmpty()) {
        removeAtTail();
    }
}

template <class T>
void CircularSingleLinkedList<T>::print() {
    if (isEmpty()) {
        cout << " The List is empty" << endl;
        return;
    }
    Node<T>* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main() {
    CircularSingleLinkedList<int> csll;
    if (csll.isEmpty()) {
        cout << "List is empty!" << endl;
    } else {
        cout << "List is not empty!" << endl;
    }
    csll.insertAtHead(10);
    csll.insertAtTail(20);
    csll.insertAtTail(30);
    csll.insertAt(25, 2);
    csll.print();
    csll.removeAt(1);
    csll.print();
    cout << "Item at index 1: " << csll.retrieveAt(1) << endl;
    csll.replaceAt(100, 1);
    csll.print();

    if (csll.isExist(11)) {
        cout << "Element is found!" << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    cout << "The size of list is: " << csll.Size() << endl;

    if (csll.isItemAtEqual(10, 0)) {
        cout << "Element is at equal!" << endl;
    } else {
        cout << "Element not at equal!" << endl;
    }

    csll.swap(0, 1);
    csll.print();
    // csll.clear();
    return 0;
}