#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool knows(vector<vector<int>> arr, int a, int b, int n){
    for(int i=0; i<n; i++){
        if(arr[a][i] == 1){
            return true;
        }
    }
    return false;
}

void find(vector<vector<int>> arr, int n){
    stack<int> s;
    for(int i=0; i<n; i++){
        s.push(i);
    }
    while(s.size() == 1){
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(arr,a,b,n)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int candidate = s.top();

    bool rowCheck = false;
    int rowCount = 0;
    for(int i=0; i<n; i++){
        if(arr[candidate][i] == 0){
            rowCount++;
        }
    }
    if(rowCount == n){
        rowCheck = true;
    }


    bool colCheck = false;
    int colCount = 0;
    for(int i=0; i<n; i++){
        if(arr[i][candidate] == 1){
            colCount++;
        }
    }
    if(colCount == n-1){
        colCheck = true;
    }

    if(rowCheck && colCheck){
        cout<<"Celebrity is person : "<<candidate<<endl;
    }
}

int main(){
    vector<vector<int>> arr = {{0,1,0},
                   {0,0,0},
                   {0,1,0}};
    // BRUTE FORCE GOES BRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
    for(int col=0; col<3; col++){// Bad complexity On2
        bool flag = true;
        for(int row=0; row<3; row++){
            if((row != col && arr[row][col] == 0) || (arr[col][row] == 1)){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"Celebrity is person : "<<col+1<<endl;
            break;
        }
    }
    find(arr,3);
    return 0;
}