#include<iostream>
using namespace std;

int& func(int a) {// bad practice coz ans is reference of num and num is a local variable
    int num = a;
    int& ans = num;
    return ans;
}

int getSum(int *arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    return sum;
}

void print(int &x, int y){//pass by reference
    x++;
    y++;
    cout<<"inside func  :"<<x<<" "<<y<<endl;
}

int main(){
    int a=5,b=10;
    print(a,b);
    cout<<"main func :"<<a<<" "<<b<<endl; 

    //Static and Dynamic Memory
    char ch = 'q';
    cout<<sizeof(ch)<<endl;

    char* c = &ch;
    cout<<sizeof(c)<<endl;
    
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum = getSum(arr,n);
    cout<<sum<<endl;
    cout<<arr<<endl;
    delete []arr;
    return 0;
}