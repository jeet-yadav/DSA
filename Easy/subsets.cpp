#include<iostream>
#include<vector>
using namespace std;
// https://leetcode.com/problems/subsets/
void subSet(vector<int>& arr, vector<vector<int>>& arr2, int index, vector<int>& output){
    if(index >= arr.size()){
        arr2.push_back(output);
        return;
    }
    output.push_back(arr[index]);
    subSet(arr,arr2,index+1,output);

    output.pop_back();
    subSet(arr,arr2,index+1,output);
}
int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> arr2;
    vector<int> output;
    int index = 0;

    subSet(arr,arr2,index,output);

    for (int i=0; i<arr2.size(); i++){
        cout<<"-> ";
        for (int j=0; j<arr2[i].size(); j++){
            cout << arr2[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}