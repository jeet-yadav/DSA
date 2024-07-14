#include<iostream>
using namespace std;
int main(){
    int arr[3][3];
    cout<<"Enter elements row-wise for a 3x3 array:"<<endl;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];//   taking input in 2d array
        }
    }
 
    for(int i=0; i<3; i++){//   outer loop for each row
        if(i%2!=0){
            for(int j=2; j>=0; j--){// inner loop for odd row
                cout<<arr[i][j];
                cout<<" ";
            }
        }
        else{
            for(int j=0; j<3; j++){// inner loop for even row
                cout<<arr[i][j];
                cout<<" ";
            }
        }
        cout<<endl;
    }

    // for(int col=0; col<3; col++){ //TO print column wise wave
    //     if(col%2==0){
    //         for(int row=2; row>=0; row--){
    //             cout<<arr[row][col];
    //             cout<<" ";
    //         }
    //     }
    //     else{
    //         for(int row=0; row<3; row++){
    //             cout<<arr[row][col];
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }
    return 0;
}