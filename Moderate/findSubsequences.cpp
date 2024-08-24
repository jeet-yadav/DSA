#include<iostream>
using namespace std;

int findSubsequences(string str, string output, int index){
    if(index >= str.length()){
        cout<<"-> "<<output<<endl;
        return 1;
    }
    char ch = str[index];

    output.push_back(ch);
    findSubsequences(str,output,index+1);

    output.pop_back();
    findSubsequences(str,output,index+1);
}

int main(){
    string str = "abc";
    findSubsequences(str,"",0);
    return 0;
}