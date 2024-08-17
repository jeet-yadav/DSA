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

int main(){
    char arr[4] = {'j','e','i','t'};
    string name = "jeit";

    reverse(arr,0,3);
    reverseString(name,0,name.length()-1);
    cout<<name<<endl;
    return 0;
}