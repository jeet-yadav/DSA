#include<iostream>
using namespace std;

void reverse(char arr[], int s, int e){//reversing an array using recursion
    if(s>=e)
        return;
    swap(arr[s++], arr[e--]);
    reverse(arr,s,e);
}

void reverseString(string& name, int s, int e){//reversing an array using recursion
    if(s>=e)
        return;
    swap(name[s++], name[e--]);
    reverseString(name,s,e);
}

//new approach can use 1 pointer, and alter it by size of array to be as second pointer
void optimized(string& name, int s, int n){//reversing an array using recursion
    if(s >= n/2)
        return;
    swap(name[s], name[n-s-1]);
    optimized(name,s+1,n);
}

int main(){
    char arr[4] = {'j','e','i','t'};
    
    string name = "abcde";
    int n = name.length();

    optimized(name,0,n);
    cout<<name<<endl;
    return 0;
}