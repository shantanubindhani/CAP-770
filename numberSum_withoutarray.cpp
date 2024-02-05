#include<iostream>
using namespace std;

void nsum();

int main(){
    nsum();
}

void nsum(){
    int p, sum = 0;
    cout<<" enter the number that you want to add(space separated), \nany non digit charachter will terminate the input and produce the output. ->";
    while(cin>>p){
        sum += p;
    }
    cin.clear();
    cout<<sum;

}