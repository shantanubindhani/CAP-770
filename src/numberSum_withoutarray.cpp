#include<iostream>
using namespace std;

void numberSum_withoutarray(){
    int p, sum = 0;
    cout<<" enter the number that you want to add(space separated), \nany non digit charachter will terminate the input and produce the output. ->";
    while(cin>>p){
        sum += p;
    } 
    cin.clear();
    char ch; cin>>ch;
    cout<<" the sum is : "<<sum;
}