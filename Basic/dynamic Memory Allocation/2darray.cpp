#include<iostream>
using namespace std;

int main(){
    int row;
    cin >> row;

    int col;
    cin >> col;

    // int *arr0 = new int[n];//1darray

    int **arr = new int*[row];//2darray
    for(int i=0; i<row; i++){
        arr[i] = new int[col];
    }

    for(int i=0; i<row; i++){//input
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<row; i++){//output
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<row; i++){//memory-release
        delete [] arr[i];
        cout<<endl;
    }

    delete []arr;

    return 0;
}