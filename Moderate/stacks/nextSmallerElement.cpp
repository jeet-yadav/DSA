#include<iostream>
#include<stack>
using namespace std;
//https://www.naukri.com/code360/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio
void find(int arr[], int n){
    stack<int> s;
    s.push(-1);
    int ans[n];

    for(int i=n-1; i>=0; i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int n = 4;
    int arr[n] = {2,1,4,3};

    // On2 T_T
    for(int i=0; i<n; i++){
        cout<<"for : "<<arr[i]<<" -> ";
        for(int j=i; j<n; j++){
            if(arr[j] < arr[i]){
                cout<<arr[j]<<" ";
                break;
            }
        }
        cout<<endl;
    }

    //to get rid of the complexity, we can use stacks
    find(arr,n);
    return 0;
}