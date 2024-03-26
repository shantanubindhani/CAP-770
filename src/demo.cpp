#include <iostream>
#include "textFormater.cpp"


#include "generatePrimeNumbers.cpp"
#include "numberSum_withoutarray.cpp"
#include "balancedBrackets.cpp"
#include "arrayInsert.cpp"
#include "arrayRemove.cpp"
#include "linkedList.cpp"
#include "stack.cpp"
#include "stackll.cpp"
#include "queue.cpp"
#include "linearSearch.cpp"
#include "jumpSearch.cpp"
#include "binarySearch.cpp"
#include "bubbleSort.cpp"
#include "selectionSort.cpp"
#include "quickSort.cpp"

using namespace std;


void stack_demo();
void stackll_demo();
void generatePrimeNumbers_demo();
void numberSum_withoutarray_demo();
void balancedBrackets_demo();
void arrayInsert_demo();
void arrayRemove_demo();
void linkedList_demo();
void stack_demo();
void queue_demo();
void mergeSort_demo();
void priorityQueue_demo();
void binaryTree_demo();
void binarySearchTree_demo();



int main(){
    TextFormater tf;
    bool mainloop = true;
    string bound = "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    while(mainloop){
        int choice;
        tf.printColored(bound,ColorCode::YELLOW);
        cout<<"Which DSA demo do you want to see ?"<<endl;
        cout<<" 0. QUIT"<<endl;
        cout<<" 1. generate Prime Numbers"<<endl;
        cout<<" 2. number Sum-withoutarray"<<endl;
        cout<<" 3. balanced Brackets"<<endl;
        cout<<" 4. array Insert"<<endl;
        cout<<" 5. array Remove"<<endl;
        cout<<" 6. linked List"<<endl;
        cout<<" 7. stack"<<endl;
        cout<<" 8. queue"<<endl;
        cout<<" 9. linear Search"<<endl;
        cout<<" 10. jump Search"<<endl;
        cout<<" 11. binary Search"<<endl;
        cout<<" 12. bubble Sort"<<endl;
        cout<<" 13. selection Sort"<<endl;
        cout<<" 14. quick Sort"<<endl;
        cout<<" 15. stack (linked-list)"<<endl;
        cout<<" 16. merge Sort [TODO]"<<endl;
        cout<<" 17. priority Queue [TODO]"<<endl;
        cout<<" 18. binary tree [TODO]"<<endl;
        cout<<" 19. binary search tree [TODO]"<<endl;
        cout<<" => ";
        cin>>choice;
    
        switch (choice)
        {
        case 0:
            tf.printColored("[ NOTICE ] Exiting the menu . . .\n", ColorCode::YELLOW);
            mainloop = false;
            break;
        case 1:
            generatePrimeNumbers();
            break;
        case 2:
            numberSum_withoutarray();
            break;
        case 3:
            balancedBrackets();
            break;
        case 4:
            arrayInsert_demo();
            break;
        case 5:
            arrayRemove_demo();
            break;
        case 6:
            linkedList_demo();
            break;
        case 7:
            stack_demo();
            break;
        case 8:
            queue_demo();
            break;
        case 9:
            linearSearch_demo();
            break;
        case 10:
            jumpSearch_demo();
            break;
        case 11:
            binarySearch_demo();
            break;
        case 12:
            bubbleSort_demo();
            break;
        case 13:
            selectionSort_demo();
            break;
        case 14:
            quickSort_demo();
            break;
        case 15:
            stackll_demo();
            break;
        case 16:
            mergeSort_demo();
            break;
        case 17:
            priorityQueue_demo();
            break;
        case 18:
            binaryTree_demo();
            break;
        case 19:
            binarySearchTree_demo();
            break;
        default:
            tf.printColored(" [ ERROR ] Invalid choice!.\n", ColorCode::RED);
            break;
        }
        tf.printColored(bound, ColorCode::YELLOW);
    }
}

void arrayInsert_demo(){arrayInsert();}

void arrayRemove_demo(){arrayRemove();}

void linkedList_demo(){
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
    cout<<"Deleted : "<<list.deleteAtStart()<<" from the start"<<endl;   // Deleting from the beginning
    cout<<"Deleted : "<<list.deleteAtEnd()<<" from the end"<<endl;     // Deleting from the end
    cout<<"Deleted : "<<list.deleteAtIndex(1)<<" at index "<<"1"<< endl;  // Deleting at index 1

    list.display();
}

void stack_demo(){
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

void queue_demo(){
    int intArr[] = {34, 89, 74, 34};
    runDemo<int>(intArr);
    char charArr[] = {'h', 'e', 'l', 'o'};
    runDemo<char>(charArr);
    string strArr[] = {"hey", "there", "BLANK", "whatsup"};
    runDemo<string>(strArr);
}
void stackll_demo(){
    cout<<endl;
    Stackll<int> stack;
    
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

void mergeSort_demo(){cout<<" TO BE UPDATED!."<<endl;}
void priorityQueue_demo(){cout<<" TO BE UPDATED!."<<endl;}
void binaryTree_demo(){cout<<" TO BE UPDATED!."<<endl;}
void binarySearchTree_demo(){cout<<" TO BE UPDATED!."<<endl;}
