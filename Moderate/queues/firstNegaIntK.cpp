#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// ASS APPROACH BY ME COMMENTED
// vector<int> printFirstNegativeInteger(queue<int> q, int k){
//     vector<int> v;
//     int size = q.size();

//     for(int i=0; i<=size-k; i++){
//         bool foundNegative = false;

//         for(int j=0; j<k; j++){
//             int value = q.front();
//             q.pop();

//             if(value < 0 && !foundNegative){
//                 v.push_back(value);
//                 foundNegative = true;
                
//             }
//             q.push(value);

//             if(!foundNegative){
//                 v.push_back(0);
//             }
//         }
//         cout<<v[i]<<" ";
//     }

//     return v;
//  }
 
vector<int> printFirstNegativeInteger(vector<int> a, int n, int k){
    deque<int> dq;
    vector<int> ans;

    // Step 1: Process the first window of size 'k'
    for(int i=0; i<k; i++){
        // If the current element is negative, store its index in the deque
        if(a[i] < 0){
            dq.push_back(i);
        }
    }

    // Step 2: Store the result for the first window
    // If the deque is not empty, the first element of the deque is the first negative in the window
    if(dq.size() > 0){
        ans.push_back(a[dq.front()]);
    }
    else{
        ans.push_back(0);
    }

    // Step 3: Process the rest of the windows (from index 'k' to 'n-1')
    for(int i=k; i<n; i++){
        // Remove elements that are out of the current window
        if(!dq.empty() && i - dq.front() >= k){
            dq.pop_front();
        }

        // Add the current element if it is negative
        if(a[i] < 0){
            dq.push_back(i);
        }

        // Step 4: Store the result for the current window
        if(dq.size() > 0){
            ans.push_back(a[dq.front()]);// First negative number
        }
        else{
            ans.push_back(0);// No negative number in the window
        }
    }
    return ans;
}

int main(){
    vector<int> v;
    v.push_back(-8);
    v.push_back(2);
    v.push_back(3);
    v.push_back(-6);
    v.push_back(10);

    vector<int> ans = printFirstNegativeInteger(v,5,2);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}