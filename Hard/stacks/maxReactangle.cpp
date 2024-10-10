#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Video : https://www.youtube.com/watch?v=9u2BJfmWNEg&t=1640s
//Question : https://www.geeksforgeeks.org/problems/max-rectangle/1
vector<int> rightMost(vector<int> arr, int n){
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

vector<int> leftMost(vector<int> arr, int n){
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

int findArea(vector<int> arr, int n){
    vector<int> right = rightMost(arr,n);
    vector<int> left = leftMost(arr,n);

    int maxArea = 0;
    for(int i=0; i<n; i++){
        int l = arr[i];
        if(right[i] == -1){
            right[i] = n;
        }
        int b = right[i] - left[i] - 1;

        int area = l * b;
        maxArea = max(maxArea,area);
    }
    return maxArea;
}

int maxArea(vector<vector<int>> arr, int n){
    int area = findArea(arr[0], n);

    for(int i=1; i<n; i++){ 
        for(int j=0; j<n; j++){
            if(arr[i][j] != 0){
                arr[i][j] = arr[i][j] + arr[i-1][j];
            }
            else{
                arr[i][j] = 0;
            }
        }
        area = max(area,findArea(arr[i], n));
    }
    return area;
}

int main(){
    vector<vector<int>> arr = {{0,1,1,0},
                               {1,1,1,1},
                               {1,1,1,1},
                               {1,1,0,0}};

    int largestArea = maxArea(arr, 4);
    cout<<"Largest Rectangle Area: "<<largestArea<<endl;
    return 0;
}