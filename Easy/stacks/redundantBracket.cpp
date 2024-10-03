#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &str){
    stack<char> s;

    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            s.push(ch);
        }
        else{
            if(ch == ')'){
                bool flag = true;

                while(s.top() != '('){
                    char top = s.top();

                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        flag = false;
                        break;
                    }
                    s.pop();
                }

                if(flag){
                    return true;
                }
                s.pop();
            }
        }
    }
    return false;
}

int main(){
    string str = "(2 (5 * 4)"; 
    findRedundantBrackets(str) ? cout<<"Not Redundant" : cout<<"Redundant";
    return 0;
}