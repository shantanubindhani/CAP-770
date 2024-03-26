#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include <iostream>
#include "textFormater.cpp"

using namespace std;

template<class T>
class Node{
public:
    T data;
    Node * nextNode;
    Node(){}
    Node(T value){
        data = value;
        nextNode = nullptr;
    }
};

template<class T>
class LinkedList{
private:
    int limit;
    int listSize;
    TextFormater tf;
    Node<T> *head;

public:
    LinkedList(){
        limit = 10;
        listSize = 0;
        head = nullptr;
    }
    LinkedList(int limit){
        this.limit = limit;
        listSize = 0;
        head = nullptr;
    }
    void extend(int bySize = 10){ limit += bySize; }

    bool isFull(){ return (listSize == limit); }
    bool isEmpty(){ return (head == nullptr); }

    int capacity(){ return limit; }

    int size(){ return listSize; }

    T get(int index = 0){
        T data;
        if(head != nullptr){
            
            if(index>=0 && index <= listSize){
                Node<T> *current = head;
                while(index){
                    current = current->nextNode;
                    --index;
                }
                data = current->data;
            }
            else{
                tf.printColored(" [ERROR] : invalid index!.", ColorCode::RED);
            }
        }
        return data;
    }

    void insertAtEnd(T data){
        if (!isFull()) {
            Node<T> *node = new Node<T>(data);
            if(!node){return;} //TODO
            if (head == nullptr)
                head = node;
            else {
                Node<T> *current = head;
                while (current->nextNode != nullptr) {
                    current = current->nextNode;
                }
                current->nextNode = node;
            }
            ++listSize;
        } else {
            std::cout << "List is full." << std::endl;
        }
    }

    void insertAtStart(T data) {
        if (!isFull()) {
            Node<T> *node = new Node<T>(data);
            node->nextNode = head;
            head = node;
            ++listSize;
        } else {
            std::cout << "List is full." << std::endl;
        }
    }

    void insertAtIndex(T data, int index){
        if (!isFull() && index >= 0 && index <= listSize) {
            Node<T> *node = new Node<T>(data);
            if (index == 0) {
                node->nextNode = head;
                head = node;
            } else {
                Node<T> *current = head;
                for (int i = 0; i < index - 1; ++i) {
                    current = current->nextNode;
                }
                node->nextNode = current->nextNode;
                current->nextNode = node;
            }
            ++listSize;
        } else {
            std::cout << "Invalid index or list is full." << std::endl;
        }
    }

    T deleteAtStart() {
        T data;
        if (head != nullptr) {
            Node<T> *temp = head;
            data = head->data; 
            head = head->nextNode;
            delete temp;
            --listSize;
        } else {
            std::cout << "List is empty." << std::endl;
        }
        return data;

    }

    T deleteAtEnd() {
        T data;
        if (head != nullptr) {
            if (head->nextNode == nullptr) {
                data = head->data;
                delete head;
                head = nullptr;
            } else {
                Node<T> *current = head;
                while (current->nextNode->nextNode != nullptr) {
                    current = current->nextNode;
                }
                data = current->nextNode->data;
                delete current->nextNode;
                current->nextNode = nullptr;
            }
            --listSize;
        } else {
            std::cout << "List is empty." << std::endl;
        }
        return data;
    }

    T deleteAtIndex(int index) {
        T data;
        if (index >= 0 && index < listSize) {
            if (index == 0) {
                return deleteAtStart();
            } else {
                Node<T> *current = head;
                for (int i = 0; i < index - 1; ++i) {
                    current = current->nextNode;
                }
                Node<T> *temp = current->nextNode;
                current->nextNode = current->nextNode->nextNode;
                data = temp->data;
                delete temp;
                --listSize;
                return data;
            }
        } else {
            std::cout << "Invalid index." << std::endl;
        }
        return data;
    }

    void display(string title = ""){

            if(title == "") title = "Linked List";
            printf("\033[1;32m");
            cout<<"\n\n=======[ "<<title<<" ]======= | "<<listSize<<" out of "<<limit<<"\n\n    ";
            Node<T> *current = head;
            while(current!= nullptr){
                cout<<"["<<current->data<<"]->";
                current = current->nextNode;
            }
            cout<<"END"<<endl;

            cout<<"\n============================="<<endl<<endl;
            printf("\033[0m");
        }

};

#endif