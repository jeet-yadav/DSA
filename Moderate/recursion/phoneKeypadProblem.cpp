#include<iostream>
using namespace std;
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

//yeh toh practice hai 
// int main(){ 
//     string mainStr = "23";
//     string strMap[] = {"", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
//     int index = 0;
//     int d1 = mainStr[index] - '0';
//     int d2 = mainStr[index+1] - '0';
        
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

void combi(string str, string Map[], int index, string ans){
    
}

int main(){
    string str = "23";
    string output;
    string ans;
    string Map[] = {"", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int index = 0;
    combi(str,Map,index,ans);
    return 0;
}