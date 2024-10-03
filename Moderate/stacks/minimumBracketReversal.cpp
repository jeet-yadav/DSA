#include<iostream>
#include<stack>
using namespace std;

int remaining(string &str){
    // Odd length strings cannot be balanced
    if(str.length()%2 == 1){
        return -1; 
    }

    stack<char> s;

    // Process the string and remove balanced braces
    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        if(ch == '{'){
            s.push(ch);// Push opening brace
        }
        else{
            if(!s.empty() && s.top() == '{'){
                s.pop();// Pop if there is a matching opening brace
            }
            else{
                s.push(ch);// Push unmatched closing brace
            }
        }
    }

    // Count remaining unmatched opening and closing braces
    // a is number of open braces, b is count of closed braces
    int a=0, b=0;
    while(!s.empty()){
        if(s.top() == '{'){
            b++;
        }
        else{
            a++;
        }
        s.pop();
    }

    // Calculate minimum number of swaps to balance the string
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}

int main(){
    string str = "}{";
    cout<<"string is : "<<str<<endl;

    int ans = remaining(str);
    cout<<"Minimum swaps to balance: "<<ans<<endl;
    return 0;
}