#include<iostream>
#include<math.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isPrime(int n){
    for(int i = 3; i<sqrt(n); ++i){
        if(n%i == 0) return false;
    }
    return true;
}

int main() {
    int n, count = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    cout << "How many numbers? : ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Node* temp = new Node();
        int x; cin>>x;
        temp->data = x;
        temp->next = nullptr;
        if (head == nullptr) {
            head = temp;
            tail = head;
        } 
        else {
            tail->next = temp;
            tail = temp;
        }
        if(isPrime(x)) ++count;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n\n";

    return 0;
}
