#include<iostream>
#include<vector>
using namespace std;
//https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650

int stair(int n){//yeh TLE maar rha, use dynamic programming jo sikha nahi abhi tak :(
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
    int ans = stair(n-1) + stair(n-2);
}

void numbers(int n){// made myself
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    vector<string> arr2;
    while(n != 0){
        int num = n % 10;
        arr2.push_back(arr[num]);
        n = n/10;
    }
    for(int i=arr2.size()-1; i>=0; i--){
        cout<<arr2[i]<<" ";
    }
}

int nums(int n){// made myself too
    if(n==0)
        return 0;
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int num = n % 10;
    nums(n/10);
    cout<<arr[num]<<" ";//if printed before function call numbers will be reversed     
}

int main(){
    // print(10);
    nums(132);
    return 0;
}