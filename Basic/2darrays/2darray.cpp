#include<iostream>
using namespace std;
int print(int arr[][3], int row, int col){// print an 2D-array
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
}
void search(int arr[][3], int row, int col, int target){//              to search an element in an 2D array(it will be easy if maid using bool function)
    bool found = false;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j]==target){
                cout<<"element found at : ROW "<<i<<"   COL "<<j<<endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }
    if (!found) {
        cout<<"Element not found :("<<endl;
    }
}
void rowWiseSum(int arr[][3], int row, int col){
    
}
int main(){
    int arr[3][3];
    int arr2[3][3] = {{1,11,111}, {2,22,222}, {3,33,333}};//Hardcode
    cout << "Enter elements row-wise for a 3x3 array:" << endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];//row wise input in 2d array
        }
    }
    int target = 5;
    search(arr, 3, 3, target);
    print(arr,3,3);
    return 0;
}