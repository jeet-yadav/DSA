#include<iostream>
using namespace std;

int main(){
    int n, m;
    cout<<"enter number of rows : ";
    cin>>n;
    cout<<"enter number of columns : ";
    cin>>m;
    int arr[n][m];
    cout<<"Enter elements : ";

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];//   taking input in 2d array
        }
    }

    cout<<"printing array......"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j];
            cout<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
    int row = n;//total number of rows
    int col = m;//total number of columns

    int count = 0;
    int total = row * col;//total number of elements

    //indexes of all four edges, which whill change in each complete iteration
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;

    while(count<total){
        //starting Row
        for(int i = startingCol; i<=endingCol && count < total; i++){
            cout<<arr[startingRow][i]<<" ";
            count++;
        }
        startingRow++;

        //ending column
        for(int i = startingRow; i<=endingRow && count < total; i++){
            cout<<arr[i][endingCol]<<" ";
            count++;
        }
        endingCol--;

        //ending row
        for(int i=endingCol; i>=startingCol && count < total; i--){
            cout<<arr[endingRow][i]<<" ";
            count++;
        }
        endingRow--;

        //starting column
        for(int i=endingRow; i>=startingRow && count < total; i--){
            cout<<arr[i][startingCol]<<" ";
            count++;
        }
        startingCol++;
    }
    return 0;
}