#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

void permute(vector<int>& nums, vector<vector<int>>& ans, int index){
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=index; i<nums.size(); i++){
        swap(nums[index],nums[i]);
        permute(nums,ans,index+1);
        swap(nums[index],nums[i]);
    }
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    permute(nums,ans,0);
    print(ans);
    return 0;
}