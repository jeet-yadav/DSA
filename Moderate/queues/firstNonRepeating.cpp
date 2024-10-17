#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

// https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

string FirstNonRepeating(string str){
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";
    
    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        // Increase the count of the current character
        count[ch]++;

        // Push the current character into the queue
        q.push(ch);

        // Process the queue to find the first non-repeating character
        while(!q.empty()){
            if(count[q.front()] > 1){
                // If the front character is repeating, remove it from the queue
                q.pop();
            }
            else{
                // If the front character is non-repeating, add it to the result
                ans.push_back(q.front());
                break;
            }
        }
        // If the queue becomes empty, it means no non-repeating character was found
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
    string str = "aabbcxxoc";
    string ans = FirstNonRepeating(str);
    cout<<ans;
    return 0;
}