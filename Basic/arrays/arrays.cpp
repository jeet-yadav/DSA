#include<iostream>
#include<climits>
using namespace std;
//Things i did with arrays
int min(int arr[], int size){//       to find the smallest element in array
        int min = INT_MAX;
        for(int i=0; i<size; i++){
                if(arr[i] < min){
                        min = arr[i];
                }
        }
        cout << "minimun : " << min << endl;
}

int max(int arr[], int size){//        to find the biggest element in array
        int max = INT_MIN;
        for(int i=0; i<size; i++){
                if(arr[i] > max){
                        max = arr[i];
                }
        }
        cout << "maximum : " << max << endl;
}

int linearSearch(int arr[], int size){//       linear search
    int key;
    cout << "Enter element for searching : ";
    cin >> key;
    bool flag = 0;
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            cout << "(using linear search) element found at " << i+1 << " location " << endl;
            flag = 1;
            break;
        }
    }
    if(flag = 0){
        cout << "Element ont found" << endl;
    }
}

int output(int arr[], int size){//                                           to print elements of the array
    cout << "output : ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int reverse(int arr[], int size){//                                       (cheating method) reversing an array
    cout << "reversed output : ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int reverse2(int arr[], int size){//                                      (real method by me) reversing an array
    int arr2[size];
    int count  = 0;
    for(int i=size-1; i>=0; i--){
        arr2[count] = arr[i]; 
        count ++;
    }
    output(arr2,size);
}

int reverse3(int arr[], int size){//                                      (real method by me) reversing an array
    for(int i=0; i<size; i++){
        int temp  = arr[i];          
        arr[i] = arr[size - i];       
        arr[size - i] = temp;
        
    }
    output(arr,size);
}

void reverse4(int arr[], int n){//                                          reversing an array by love babbar
    int start = 0;
    int end = n-1;
    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int sum(int arr[], int size){//                                               sum of all elements of an array
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += arr[i];
    }
    cout << "Sum of all elements : " << sum;
}

int alternateSwap(int arr[], int size){//                                 swaping alternate elements of an array
    for(int i=0; i<size; i+=2){
        if(i+1<size){
            swap(arr[i], arr[i+1]);
        }    
    }
    cout << "Alternate Swapped : ";
    output(arr,size);
    cout << endl;
}

int unique(int arr[], int n){                  //finding unique element when array is n =  2m + 1(even number of pairs of equal and 1 is unique)
    int ans = 0;
    for(int i=0; i<n; i++){
        ans ^= arr[i];
    }
    cout << "Unique element : " << ans;
}

int intersection(int arr[], int arr2[], int a, int b){//                            to find the intersection of 2 arrays
    cout << " similar elements are : ";
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            if(arr[i]==arr2[j]){
                cout << arr[i] << " ";
                arr[j] = INT_MIN;
                break;
            }
        }
    }
}

int intersection2(int arr[], int arr2[], int a, int b){//                       to find the intersection of 2 arrays (optimized)
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            if(arr[i] < arr2[j]){
                i++;
            }
            if(arr[i]==arr2[j]){
                cout << arr[i] << " ";
                i++;
                j++;
            }

        }
    }
}

int SumSum(int arr[], int n, int num){//                             find combination of 2 elements of an array which is equal to given num
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == num){
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }
}

int triplet(int arr[], int n){//                                (by me)    find combination of 3 elements of an array which is equal to given num                          
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){               
            for(int k=j+1; k<n; k++){
                if(arr[i] + arr[j] + arr[k] == 12){
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                }
            }
        }
    }
}

int sort01(int arr[], int n){//                         sort all the 0's in left and 1's in right
    int left = 0;//                              doubt : what if left and right both are 1 0r both are 0
    int right  = n-1;
    while(left < right){
        while(arr[left] == 0 && left<right){
            left++;
        }

        while(arr[right] == 1 && left<right){
            right--;
        }

        if(left<right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}


int BinarySearch(int arr[], int size){//                                   Binary Search
    int key;
    cout << "Enter element for searching : ";
    cin >> key;
    int s = 0;
    int e = size-1;
    int mid = (size-1)/2; // (by me)                       works for all cases
    //                       int mid = (s+e)/2;            doesnt work for all cases
    //                       int mid = s + (e-s)/2;        (s+e)/2;
    while(s<=e){
        if(key == arr[mid]){
            cout << "(using Binary Search) Element found at " << mid << " index";
            return 1;
    }
    if(key>arr[mid]){
        s = mid + 1;
    }
    else{
        e = mid - 1;
    }
    mid = (s+e)/2;
    }
    cout << "Element not found";
}

int main(){
    int arr[100];
    int n;
    cout << "How many elements to store : ";
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    BinarySearch(arr,n);

    // int num2;
    // cout << "Enter number :";
    // cin >> num2;


    return 0;
}