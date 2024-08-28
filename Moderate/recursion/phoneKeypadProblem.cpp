#include<iostream>
#include<vector>
using namespace std;
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

//yeh toh practice hai 
// int main(){ 
//     string mainStr = "23";
//     string strMap[] = {"", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//     int index = 0;
//     int d1 = mainStr[index++] - '0';
//     int d2 = mainStr[index] - '0';
                                   
//     string str1 = strMap[d1];
//     string str2 = strMap[d2];

//     for(int i=0; i<str1.length(); i++){
//         for(int j=0; j<str2.length(); j++){
//             cout<<str1[i]<<str2[j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


//yeh mera leetcode ka answer hai
// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         if (digits.empty()) {
//             return {};
//         }
//         string strMap[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//         vector<string> result;
//         result.push_back("");
//         for (char digit : digits) {
//             int d = digit - '0';
//             if (d < 2 || d > 9) continue;
//             string str = strMap[d];
//             vector<string> temp;
//             for (string combination : result) {
//                 for (char letter : str) {
//                     temp.push_back(combination + letter);
//                 }
//             }
//             result.swap(temp);
//         }

//         return result;
//     }
// };


//using recursion
void solve(string digits, string map[], int index, vector<string>& ans, string output){
    if(index >= digits.length()){
        ans.push_back(output);
        return;
    }
    int n = digits[index] - '0';
    string str = map[n];
    for(int i=0; i<str.length(); i++){
        output.push_back(str[i]);
        solve(digits,map,index+1,ans,output);
        output.pop_back();
    }
}

int main(){
    string digits = "23";
    string output;
    vector<string> ans;
    string map[] = {"", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int index = 0;
    solve(digits,map,index,ans,output);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}