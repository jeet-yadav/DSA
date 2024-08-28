#include<iostream>
using namespace std;


int subsequence(string str, string output, int index){
    if(index >= str.length()){
        cout<<output<<endl;
        return 1;
    }
    char ch = str[index];

    output.push_back(ch);
    subsequence(str,output,index+1);

    output.pop_back();
    subsequence(str,output,index+1);

    // subsequence(str,output,index+1);

    // output.push_back(ch);
    // subsequence(str,output,index+1);
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int arr2[1] = {1};
    cout<<check(arr2,5,0)<<endl;
    cout<<babbarCheck(arr2,1,1)<<endl;
    cout<<binaryRecursion(arr,0,4,5)<<endl;
    cout<<subsequence("abc"," ",0)<<endl;
    return 0;
}