#include<iostream>
#include<stack>

//https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio

using namespace std;
// int main(){// my solution E_E
//     int n = 4;

//     stack<int> s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     s.push(5);

//     int mid  = s.size()/2; // Find the middle element index (0-based)

//     // Store elements until reaching the middle
//     int arr[mid+1];
//     int i=0;

//     while(i < mid){
//         arr[i++] = s.top();
//         s.pop();
//     }
//     s.pop();

//     // Push elements back from the array
//     i = mid-1;
//     while(i >= 0){
//         s.push(arr[i--]);
//     }

//     // Print the updated stack
//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
//     return 0;
// }

// babbar solution
void solve(stack<int> &s, int count , int size){
    if(count == size/2){
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();
    solve(s,count+1,size);
    s.push(num);
}

int main(){
    int n = 4;

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    solve(s,0,s.size());

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}