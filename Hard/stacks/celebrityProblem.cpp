#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbWl0djlCMVlHNWFJTVlnanRjRGhjUHoxOEt1Z3xBQ3Jtc0trOHl0MXNtSTFrQXpYalBTdTlnMGU2a0c2ZFI2WGdxaU1jU095UTZRdFJfY3dxdldYVG1kdW1FQnNxOWhSN0V3OXIwczc1bUhWLXFuaHUyTW02OGxtVmRPdDVEbWtFS0VZdm16eExrUkc1Qm9hZGZEWQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fthe-celebrity-problem%2F1%2F&v=9u2BJfmWNEg
void find(vector<vector<int>> arr, int n){
    stack<int> s;

    // Push all the people (0 to n-1) onto the stack
    for(int i=0; i<n; i++){
        s.push(i);
    }

    // Compare pairs of people and eliminate non-celebrities
    while(s.size() > 1){
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        // If person 'a' knows person 'b', then 'a' cannot be a celebrity
        // So we push 'b' back as a potential candidate
        //Check if a knows b
        if(arr[a][b]){
            s.push(b);
        }
        // Else, person 'b' cannot be a celebrity, so push 'a' back as a candidate
        else{
            s.push(a);
        }
    }
    // The last remaining person in the stack is the potential celebrity
    int candidate = s.top();

    bool rowCheck = false;
    int rowCount = 0;
    for(int i=0; i<n; i++){
        if(arr[candidate][i] == 0){
            rowCount++;// Count how many zeros are in the candidate's row
        }
    }
    if(rowCount == n){// All entries should be 0 for the row to pass
        rowCheck = true;
    }

    // Check column: Everyone should know the candidate (all entries in their column except their own should be 1)
    bool colCheck = false;
    int colCount = 0;
    for(int i=0; i<n; i++){
        if(arr[i][candidate] == 1){
            colCount++;// Count how many ones are in the candidate's column
        }
    }
    if(colCount == n-1){// There should be n-1 ones in the column (everyone except the candidate themselves)
        colCheck = true;
    }

    // If both rowCheck and colCheck are true, we have found the celebrity
    if(rowCheck && colCheck){
        cout<<"Celebrity is person : "<<candidate<<endl;
    }
}


// Without using Stack, but same logic
void findCelebGPT(vector<vector<int>> arr, int n ){
    int a = 0;
    int b = n-1;

    while(a < b) {
        //Check if a knows b
        if(arr[a][b]) {
            a++;
        }
        else{
            b--;
        }
    }
    // Now a is the celebrity candidate
    // Verify if a is the celebrity
    bool isCelebrity = true;
    for(int i=0; i<n; i++){
        //skip when i and a are same, Check if a knows someone || Check if someone knows a 
        if(i != a && (arr[a][i] || !arr[i][a])) {
            isCelebrity = false;
            break;
        }
    }

    if(isCelebrity){
        cout<<"Celebrity is person: "<<a+1<<endl;
    }
    else{
        cout<<"No celebrity"<<endl;
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
            cout<<"Celebrity is person : "<<col<<endl;
            break;
        }
    }
    find(arr,3);
    return 0;
}