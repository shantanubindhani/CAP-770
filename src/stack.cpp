#ifndef STACK_CPP
#define STACK_CPP

#include<iostream>
#include "textFormater.cpp"

template<class T>
class Stack{
    private:
        TextFormater tf;
        T *tower;
        int limit;
        int top;
    public:

    bool isFull(){ return ((top+1)>=limit);}
    bool isEmpty(){ return (top <= -1);}

    Stack(){
        limit = 10;
        top = -1;
        tower = new T[limit];
    }

    Stack(int n){
        if(n <= 0) n = 10;
        top = -1;
        limit = n;
        tower = new T[n];
    }

    void extend(int size){
        limit += size;
        T *temp = new T[limit];
        if(!isEmpty()){
            for(int i = 0; i<=top; ++i){
                temp[i] = tower[i];
            }
        }
        T *mid = temp;
        temp=tower;
        tower = mid;
        delete temp;
    }

    void push(T data){
        if(!isFull()){
            tower[top+1] = data;
            top = top+1;
        }
        else{
            tf.printColored("\n [ERROR] : Stack Overflow!\n", ColorCode::RED);
        }
    }

    T pop(){
        if(!isEmpty()){
            top = top-1;
            return tower[top+1];
        }
        else{
            tf.printColored("\n [ERROR] : Stack Underflow!\n", ColorCode::RED);
        }
        return 0;
    }

    T peek(){
        if(!isEmpty()){
            return tower[top];
        }
        else{
            tf.printColored("\n [NOTICE] : Stack Empty!\n", ColorCode::BLUE);
        }
        return 0;
    }

    void display(){
        printf("\033[1;32m");
        std::cout<<"\n\n=======[ Stack ]======= | "<<top+1<<" out of "<<limit<<"\n\n ";
        for(int i = 0; i<=top; ++i) std::cout<<"----"; std::cout<<"---"<<endl<<" | ";
        for(int i = 0; i<= top; ++i) std::cout<<tower[i]<<" : "; std::cout<<endl<<" ";
        for(int i = 0; i<=top; ++i) std::cout<<"----"; std::cout<<"---"<<endl;

        std::cout<<"\n============================="<<endl<<endl;
        printf("\033[0m");
    }

};

#endif