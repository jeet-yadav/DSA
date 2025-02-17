#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool matches(char top, char ch){
    if((top == '(' && ch == ')') || 
        (top == '{' && ch == '}') || 
        (top == '[' && ch == ']')){
        return true;
    }
    return false;
}

bool checkValid(string str){
    stack<int> s;

    for(int i=0; i<str.length(); i++){

        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top = s.top();

                if(matches(top,ch)){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string str = "[()]{}{[()()]()}";
    checkValid(str) ? cout<<"Valid" : cout<<"Invalid";
    cout<<endl;
    return 0;
}