#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

// https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/1411439413/

vector<int> nextSmallerElement(vector<int> arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0; i<n; i++){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestRactangleAreaInHistogram(vector<int> arr, int n){
    vector<int> next = nextSmallerElement(arr,n);
    vector<int> prev = prevSmallerElement(arr,n);

    int maxArea = INT_MIN;
    for(int i=0; i<n; i++){
        int l = arr[i];
        if(next[i] == -1){
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;

        int area = l * b;
        maxArea = max(maxArea,area);
    }
    return maxArea;
}
int main(){
    //TLE marega bhot bhenkar wala yeh, maine likha hai kyuki 
    int n = 6;
    int arr[n] = {2,1,5,6,2,3};
    int maxArea = 0;

    // Display the array
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // Calculate the area for each bar by extending to left and right
    for(int i=0; i<n; i++){
        int height = arr[i];
        int width = 1;

        // Extend to the left
        for(int j=i-1; j>=0 && arr[j] >= height; j--){
            width++;
        }

        // Extend to the right
        for(int j=i+1; j<n && arr[j] >= height; j++){
            width++;
        }

        // Calculate area with height arr[i]
        int area = height * width;
        maxArea = max(maxArea, area);
    }

    cout<<"Max area: "<<maxArea<<endl;

    //optimized
    vector<int> heights= {2,1,5,6,2,3};
    int largestOne = largestRactangleAreaInHistogram(heights,n);
    cout<<"Max area Optimized: "<<largestOne<<endl;
    return 0;
}