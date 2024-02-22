#include<iostream>

using namespace std;


template<class T>
class Stack{
    private:
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
        if(!isEmpty){
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
            cout<<"\n [ERROR] : Stack Overflow!"<<endl;
        }
    }

    T pop(){
        if(!isEmpty()){
            top = top-1;
            return tower[top+1];
        }
        else{
            cout<<"\n [ERROR] : Stack Underflow!"<<endl;
        }
        return 0;
    }

    T peek(){
        if(!isEmpty()){
            return tower[top];
        }
        else{
            cout<<"\n [NOTICE] : Stack Empty!"<<endl;
        }
        return 0;
    }

    void display(){
        cout<<"\n\n=======[ Stack ]======= | "<<top+1<<" out of "<<limit<<"\n\n ";
        for(int i = 0; i<=top; ++i) cout<<"----"; cout<<"---"<<endl<<" | ";
        for(int i = 0; i<= top; ++i) cout<<tower[i]<<" : "; cout<<endl<<" ";
        for(int i = 0; i<=top; ++i) cout<<"----"; cout<<"---"<<endl;

        cout<<"\n============================="<<endl<<endl;
    }

};


int main(int argc, char* argv[]) {
    string s = "demo";
    if(argc >1 && argv[1] == s){
        cout<<endl;
        Stack<int> stack(3);
        
        // Insert elements
        if(stack.isFull()) cout<<"The Stack is full."<<endl;
        else if(stack.isEmpty()) cout<<"The Stack is Empty."<<endl;
        else cout<<"The Stack has elements."<<endl;

        stack.push(5); // Inserting to the stack
        stack.push(10);
        stack.display();

        stack.push(3);
        stack.push(1);
        stack.display();

        stack.extend(10);
        cout<<"Peeked and found : "<<stack.peek();
        stack.display(); 

        // Delete elements
        cout<<"Popped the element : "<<stack.pop()<<endl;
        cout<<"Popped the element : "<<stack.pop()<<endl;
        stack.display();
        

    }
    return 0;
}
