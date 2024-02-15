#include<iostream>
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
        int size;
        Node<T> *head;
    
    public:    
        LinkedList(){
            limit = 10;
            size = 0;
            head = nullptr;
        }
        void extend(int bySize){ limit += bySize; }
       
        bool isFull(){ return (size==limit)?true:false;}
       
        int capacity(){return limit;}
       
        int size(){return size;}

        void insert(T data){
            if(!isFull){    
                Node<T> *node = new Node(data);
                if(head == nullptr) head = node;
                else{
                    Node<T> *current = head;
                    while(current->nextNode != nullptr){ current = current->nextNode;}
                    current->nextNode = node;
                }
                ++size;
            }
            else cout<<""
        }

        void insert(T data, int index){
            if(!isFull){
                Node<T> *node = new Node(data);
                //for(int i = 0; i<)
            }
        }
    

};



int main(int arc, char * args[]){
    if(args[1] == "demo"){
        LinkedList<int> list = new LinkedList<int>();
    }

    return 0;
}