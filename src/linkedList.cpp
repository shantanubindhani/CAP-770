#include <iostream>
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
    Node<T> *head;

public:
    LinkedList(){
        limit = 10;
        listSize = 0;
        head = nullptr;
    }
    void extend(int bySize = 10){ limit += bySize; }

    bool isFull(){ return (listSize == limit); }

    int capacity(){ return limit; }

    int size(){ return listSize; }

    void insertAtEnd(T data){
        if (!isFull()) {
            Node<T> *node = new Node<T>(data);
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

    void deleteAtStart() {
        if (head != nullptr) {
            Node<T> *temp = head;
            head = head->nextNode;
            delete temp;
            --listSize;
        } else {
            std::cout << "List is empty." << std::endl;
        }
    }

    void deleteAtEnd() {
        if (head != nullptr) {
            if (head->nextNode == nullptr) {
                delete head;
                head = nullptr;
            } else {
                Node<T> *current = head;
                while (current->nextNode->nextNode != nullptr) {
                    current = current->nextNode;
                }
                delete current->nextNode;
                current->nextNode = nullptr;
            }
            --listSize;
        } else {
            std::cout << "List is empty." << std::endl;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= 0 && index < listSize) {
            if (index == 0) {
                deleteAtStart();
            } else {
                Node<T> *current = head;
                for (int i = 0; i < index - 1; ++i) {
                    current = current->nextNode;
                }
                Node<T> *temp = current->nextNode;
                current->nextNode = current->nextNode->nextNode;
                delete temp;
                --listSize;
            }
        } else {
            std::cout << "Invalid index." << std::endl;
        }
    }

    void display(){
            cout<<"\n\n=======[ Linked List ]======= | "<<listSize<<" out of "<<limit<<"\n\n    ";
            Node<T> *current = head;
            while(current!= nullptr){
                cout<<"["<<current->data<<"]->";
                current = current->nextNode;
            }
            cout<<"END"<<endl;

            cout<<"\n============================="<<endl<<endl;
        }

};

int main(int argc, char* argv[]) {
    cout<<argv[1];
    string s = "demo";
    if(argv[1] == s){
        LinkedList<int> list;
        
        // Insert elements
        list.insertAtEnd(5); // Inserting at the end
        list.insertAtEnd(10);
        list.display();

        list.insertAtStart(3);// Inserting at the beginning
        list.insertAtStart(1);
        list.display();

        list.extend(40);
        list.insertAtIndex(7, 2);// Inserting at index 2
        list.display(); 

        // Delete elements
        list.deleteAtStart();   // Deleting from the beginning
        list.deleteAtEnd();     // Deleting from the end
        list.deleteAtIndex(1);  // Deleting at index 1

        list.display();
    }
    return 0;
}

