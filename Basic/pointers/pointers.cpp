#include<iostream>
using namespace std;

void print(int *p){
    *p = *p + 1;
    cout <<"inside func "<<*p <<endl;
    p = p + 1;
    cout<<"inside func "<<p <<endl;
}


int getSum(int arr[], int n){// here ind=stead of arr[], we can use *arr
    cout<<sizeof(arr)<<endl;
    cout<<&arr<<endl;
    cout<<&arr[0]<<endl;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    // int num = 5;
    // cout<<"num is "<<num<<endl;
    // cout<<"address of num is "<<&num<<endl;

    // int *p = &num;
    // cout<<"p is "<<p<<endl;
    // cout<<"value at address p "<<*p<<endl;

    // cout<<sizeof(num)<<endl;
    // cout<<sizeof(p)<<endl;

    // cout<<"num is "<<num<<endl;
    // // (*p)++;
    // (*p)*=2;
    // cout<<"num after *p++ is "<<num<<endl;

    int arr[5] = {5,10,15,20,25};
    // cout<<"address of arr[0] is "<< arr <<endl;
    // cout<<"address of arr[0] is "<< &arr[0] <<endl;
    // cout<<"value at address of arr[0] is "<< *arr <<endl;

    // cout<< *(arr+1) <<endl;
    // cout<< (*arr)+1 <<endl;

    // int i = 2;
    // cout<< i[arr] <<endl;//arr[i] == *(arr+i) == i[arr] == *(i+arr)
    
    // int *ptr = &arr[0];
    // cout<<sizeof(arr) <<endl;
    // cout<<sizeof(ptr) <<endl;

    // cout<< arr <<endl;
    // cout<< &arr <<endl;
    // cout<< &arr[0] <<endl;
    // cout<< arr <<endl;


    char ch[6] = "abcde";
    // cout << ch <<endl;
    // cout << &ch <<endl;
    // cout << *ch <<endl;
    // cout << *(ch+1)+2 <<endl;

    // char *c = &ch[0];
    // cout << c <<endl;
    // cout << *c <<endl;
    
    // char temp = 'z';
    // char *tp = &temp;
    // cout<<tp<<endl;
    // cout<<&temp<<endl;


    // int value = 5;
    // int *p = &value;
    // cout <<"before "<<*p <<endl;
    // cout<<"before "<<p <<endl;
    // print(p);
    // cout <<"after "<<*p <<endl;
    // cout<<"after "<<p <<endl;
    // cout<<sizeof(arr)<<endl;
    // cout << "Sum is " << getSum(arr+1,5) << endl;
    return 0;
}  