// Single Linked List
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
class SingleLinkedList {
private:
    Node<T>* head;
    int size;

public:
    SingleLinkedList() {
        head = NULL;
        size = 0;
    }

    // Destructor
    ~SingleLinkedList() {
        Node<T>* current = head;
        while (current) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
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
void SingleLinkedList<T>::insertAtHead(T element) {
    Node<T>* newNode = new Node<T>(element);
    newNode->next = head;
    head = newNode;
    size++;
}

template <class T>
void SingleLinkedList<T>::insertAtTail(T element) {
    Node<T>* newNode = new Node<T>(element);
    if (head == NULL) {
        head = newNode;
    } else {
        Node<T>* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

template <class T>
void SingleLinkedList<T>::insertAt(T element, int index) {
    if (index < 0 || index > size) {
        cerr << "Index out of list" <<endl;
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
void SingleLinkedList<T>::removeAtHead() {
    if (head == NULL) {
        cerr << "List is empty, cannot delete from empty list" << endl;
        return;
    }
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    size--;
}

template <class T>
void SingleLinkedList<T>::removeAtTail() {
    if (head == NULL) {
        cerr << "List is empty, cannot delete from empty list" <<endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node<T>* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    size--;
}

template <class T>
void SingleLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= size) {
        cerr << "Index out of list" << endl;
        return;
    }
    if (index == 0) {
        removeAtHead();
    } else if (index == size - 1) {
        removeAtTail();
    } else {
        Node<T>* prev = NULL;
        Node<T>* del = head;
        for(int i = 0; i < index && del != NULL; ++i) {
            prev = del;
            del = del->next;
        }
        prev->next = del->next;
        delete del;
        size--;
    }
}

template <class T>
T SingleLinkedList<T>::retrieveAt(int index) {
    if (index < 0 || index >= size) {
        cerr << "Index out of list" <<endl;
        return T();
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <class T>
void SingleLinkedList<T>::replaceAt(T newElement, int index) {
    if (index < 0 || index >= size) {
        cerr << "Index out of list" << endl;
        return;
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = newElement;
}

template <class T>
bool SingleLinkedList<T>::isExist(T element) {
    Node<T>* current = head;
    while (current != NULL) {
        if (current->data == element) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <class T>
bool SingleLinkedList<T>::isItemAtEqual(T element, int index) {
    if (index < 0 || index >= size) {
        cerr << "Index out of list" << endl;
        return false;
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data == element;
}

template <class T>
void SingleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size) {
        cerr << "Index out of list" << endl;
        return;
    }
    if (firstItemIdx == secondItemIdx) {
        cerr << "Items with the same index cannot be swapped!" << endl;
        return;
    }

    Node<T>* current = head;
    Node<T>* firstPrev = NULL;
    Node<T>* secondPrev = NULL;
    Node<T>* firstNode = NULL;
    Node<T>* secondNode = NULL;

    for (int i = 0; i <= max(firstItemIdx, secondItemIdx); i++) {
        if (i == firstItemIdx - 1) {
            firstPrev = current;
        }
        if (i == firstItemIdx) {
            firstNode = current;
        }
        if (i == secondItemIdx - 1) {
            secondPrev = current;
        }
        if (i == secondItemIdx) {
            secondNode = current;
        }
        current = current->next;
    }

    // Swapping the nodes
    if (firstPrev != NULL) {
        firstPrev->next = secondNode;
    } else {
        head = secondNode;
    }
    if (secondPrev != NULL) {
        secondPrev->next = firstNode;
    } else {
        head = firstNode;
    }

    Node<T>* temp = secondNode->next;
    secondNode->next = firstNode->next;
    firstNode->next = temp;
}

template <class T>
bool SingleLinkedList<T>::isEmpty() {
    return head == NULL;
}

template <class T>
int SingleLinkedList<T>::Size() {
    return size;
}

template <class T>
void SingleLinkedList<T>::clear() {
    while (head != NULL) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

template <class T>
void SingleLinkedList<T>::print() {
    Node<T>* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    SingleLinkedList<int> sll;
    if (sll.isEmpty()) {
        cout << "List is empty!" << endl;
    } else {
        cout << "List is not empty!" << endl;
    }
    sll.insertAtHead(10);
    sll.insertAtTail(20);
    sll.insertAtTail(30);
    sll.insertAt(25, 2);
    sll.print();
    sll.removeAt(1);
    sll.print();
    cout << "Item at index 1: " << sll.retrieveAt(1) << endl;
    sll.replaceAt(100, 1);
    sll.print();

    if (sll.isExist(11)) {
        cout << "Element is found!" << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    cout << "The size of list is: " << sll.Size() << endl;

    if (sll.isItemAtEqual(10, 0)) {
        cout << "Element is at equal!" << endl;
    } else {
        cout << "Element not at equal!" << endl;
    }

    sll.swap(0, 1);
    sll.print();

    // sll.clear();

    return 0;
}