#include<iostream>
using namespace std;

bool binarySearch(int arr[],int s, int e,int key){
    if(s>e)
        return 0;

    int mid = s+(e-s)/2;
    if(arr[mid]==key)
        return 1;
    if(key > arr[mid]){
        return binarySearch(arr,mid+1,e,key);
    }
    else{
        return binarySearch(arr,s,mid-1,key);
    }
}

int firstOccurence(int arr[],int n, int key){
    int s=0, e=n-1;
    int first = -1;

    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]==key){
            first = mid;
            e = mid-1;
        }
        else if(key > arr[mid]){
            s = mid+1;
        }
        else
            e = mid-1;
    }
    return first;
}
int lastOccurence(int arr[],int n, int key){
    int s=0, e=n-1;
    int last = -1;

    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]==key){
            last = mid;
            s = mid+1;
        }
        else if(key > arr[mid]){
            s = mid+1;
        }
        else
            e = mid-1;
    }
    return last;
}
//above 2 functions as recursion for practice
int firstRecursion(int arr[], int s, int e, int key){ 
    if(s > e)
        return -1;

    int mid = (s+e)/2;

    if(arr[mid] == key){
        int left = firstRecursion(arr,s,mid-1,key);
        return (left != -1) ? left : mid;//this shit is fire
    }
    else if(arr[mid] > key){
        return firstRecursion(arr,s,mid-1,key);
    }
    else{
        return firstRecursion(arr,mid+1,e,key);
    }
}

int lastRecursion(int arr[], int s, int e, int key){ 
    if(s > e)
        return -1;

    int mid = (s+e)/2;

    if(arr[mid] == key){
        int right = lastRecursion(arr,mid+1,e,key);
        return (right != -1) ? right : mid;//this shit is fire too
    }
    else if(arr[mid] > key){
        return lastRecursion(arr,s,mid-1,key);
    }
    else{
        return lastRecursion(arr,mid+1,e,key);
    }
}

int main(){
    int n = 5;
    int arr[5] = {1,2,3,4,5};
    int key = 48;
    cout<<"Binary Search "<<binarySearch(arr,0,4,key)<<endl;

    int arr2[10] = {1,2,2,2,3,4,4,5,6,6};
    cout<<"first occurence "<<firstOccurence(arr2,10,4)<<endl;
    cout<<"last occurence "<<lastOccurence(arr2,10,2)<<endl;

    cout<<"first occurence using bs in recursion "<<firstRecursion(arr2,0,9,4)<<endl;
    cout<<"last occurence using bs in recursion "<<lastRecursion(arr2,0,9,2)<<endl;
    return 0;
}