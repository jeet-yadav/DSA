#include<iostream>
using namespace std;

void reverse(char arr[], int s, int e){//reversing an array using recursion
    if(s>=e)
        return;
    swap(arr[s++], arr[e--]);
    reverse(arr,s,e);
}

int main(){
    char arr[4] = {'j','e','i','t'};
    reverse(arr,0,3);

    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}