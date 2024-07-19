#include<iostream>
using namespace std;

int print(int arr[][3], int row, int col){// print an 2D-array
    cout<<"printing array......"<<endl;;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
}

int rotate(int arr[][3], int row, int col){// using swaping to rotate an matrix( first transpose it/swap adjecent elements then swap adjecent columns)
    for(int i=1; i<row; i++){
        for(int j=i; j<col-1; j++){
            swap(arr[row][col], arr[col][row]);
        }
    }

    for (int i=0; i<row; i++) {
        for (int j=0; j<col/2; j++) {
            swap(arr[i][j], arr[i][col-j-1]);
        }
    }
    print(arr, row, col);
}

int rotate2(int arr[][3], int row, int col){// eassypeassy
    for(int i=0; i<col; i++){
        for(int j=row-1; j>=0; j--){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    // print(arr, 3, 3);
    rotate2(arr, 3, 3);

    return 0;
}