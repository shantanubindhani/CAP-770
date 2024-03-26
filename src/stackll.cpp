#ifndef STACKLL_CPP
#define STACKLL_CPP



#include<iostream>
#include "textFormater.cpp"
#include "linkedList.cpp"
using namespace std;

template<class T>
class Stackll{
    private:
        TextFormater tf; // user defined
        LinkedList<T> stack; // user defined
    public:

    bool isFull(){ return stack.isFull();}
    bool isEmpty(){ return stack.isEmpty();}

    Stackll(){}
    Stackll(int limit){
        stack = new LinkedList<int>(limit);
    }

    void extend(int size){
        stack.extend(size);
    }

    void push(T data){
        if(!stack.isFull()){
            stack.insertAtStart(data);
        }
        else{
            tf.printColored("\n [ERROR] : Stack Overflow!\n", ColorCode::RED);
        }
    }

    T pop(){
        T data;
        if(!stack.isEmpty()){
            data = stack.deleteAtStart();
            return data;
        }
        else{
            tf.printColored("\n [ERROR] : Stack Underflow!\n", ColorCode::RED);
        }
        return data;
    }

    T peek(){
        T data;
        if(!stack.isEmpty()){
            return stack.get();
        }
        else{
            tf.printColored("\n [NOTICE] : Stack Empty!\n", ColorCode::BLUE);
        }
        return data;
    }

    void display(){
        stack.display("Linked List Stack");
    }

};

#endif