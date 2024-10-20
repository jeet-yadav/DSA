#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

//https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/


int SumOfKsubArray(vector<int> arr, int n, int k){
    deque<int> maxi(k);
    deque<int> mini(k);

    int ans = 0;

    for(int i=0; i<k; i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    for(int i=k; i<n; i++){
        ans += arr[maxi.front()] + arr[mini.front()];

        while(!maxi.empty() && i - maxi.front() >= k){
            maxi.pop_front();
        }
        while(!maxi.empty() && i - mini.front() >= k){
            mini.pop_front();
        }

        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }
    
    ans += arr[maxi.front()] + arr[mini.front()];
    
    return ans;

}

int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(-1);
    v.push_back(7);
    v.push_back(-3);
    v.push_back(-1);
    v.push_back(-2);

    cout << SumOfKsubArray(v,7,4);

    return 0;
}