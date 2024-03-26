#ifndef QUEUE_CPP
#define QUEUE_CPP

#include<iostream>

using namespace std;


template<class T>
class Queue{
    private:
        T *line;
        int limit;
        int front;
        int rear;
    public:

    bool isFull(){ return (rear>=limit);}
    bool isEmpty(){ return (front == rear);}
    void log(){ cout<<endl<<front<<" | "<<rear<<endl;}
    int size(){ return rear-front;}

    Queue(){
        limit = 10;
        front = -1;
        rear = -1;
        line = new T[limit];
    }

    Queue(int n){
        if(n <= 0) n = 10;
        front = -1;
        rear = -1;
        limit = n;
        line = new T[n];
    }

    void extend(int size){
        limit += size;
        T *temp = new T[limit];
        if(!isEmpty()){
            for(int i = front; i<rear; ++i){
                temp[i] = line[i];
            }
        }
        T *mid = temp;
        temp=line;
        line = mid;
    }

    void enqueue(T data){
        if(!isFull()){
            if(isEmpty()) front = (rear = 0);
            line[rear] = data;
            rear = rear+1;
        }
        else{
            cout<<"\n [ERROR] : Queue Overflow!"<<endl;
        }
    }

    T dequeue(){
        if(!isEmpty()){
            front += 1;
            return line[front-1];
        }
        else{
            //front = rear = -1;
            cout<<"\n [ERROR] : Queue Underflow!"<<endl;
        }
        return 0;
    }

    T peek(){
        if(!isEmpty()){
            return line[front];
        }
        else{
            cout<<"\n [NOTICE] : Queue Empty!"<<endl;
        }
        return 0;
    }

    void display(){
        cout<<"\n\n=======[ Queue ]======= | ("<<size()<<" out of "<<limit<<")\n\n ";
        for(int i = front; i<rear; ++i) cout<<"----"; cout<<"---"<<endl<<"<- ";
        for(int i = front; i< rear; ++i) cout<<line[i]<<" : "; cout<<"<-"<<endl<<" ";
        for(int i = front; i<rear; ++i) cout<<"----"; cout<<"---"<<endl;

        cout<<"\n============================="<<endl<<endl;
    }

};


template<class T>
void runDemo(T arr[]){
    cout<<endl;
    Queue<T> queue(3);
    
    // Insert elements
    if(queue.isFull()) cout<<"The Queue is full."<<endl;
    else if(queue.isEmpty()) cout<<"The Queue is Empty."<<endl;
    else cout<<"The Queue has elements."<<endl;

    queue.enqueue(arr[0]); // Inserting to the queue
    queue.enqueue(arr[1]);
    queue.display();
    
    queue.enqueue(arr[2]);
    queue.enqueue(arr[3]);
    queue.display();
    
    queue.extend(10);
    
    cout<<"Peeked and found : "<<queue.peek();
    
    queue.display(); 

    // Delete elements
    cout<<"Dequeued the element : "<<queue.dequeue()<<endl;
    cout<<"Dequeued the element : "<<queue.dequeue()<<endl;
    queue.display();
    cout<<"-----------------------------------------------------------"<<endl;
}


#endif
