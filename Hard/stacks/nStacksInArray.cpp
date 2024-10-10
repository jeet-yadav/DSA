#include<iostream>
#include<stack>
using namespace std;

class NStack{
    int *arr;
    int *top;
    int *next;

    int n,s;
    int freespot;

    public:

    NStack(int N, int S){
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        for(int i=0; i<n; i++){
            top[i] = -1;
        }

        for(int i=0; i<s; i++){
            top[i] = i+1;
        }
        top[s-1] = -1;

        freespot = 0;
    }

    // pushes 'X' into the Mth stack. Returns true if it get pushed into the Mth stack else false.
    bool push(int X, int M){
        if(freespot == -1){return false;}
        
        int index = freespot;
        freespot = next[index];
        arr[index] = X;
        next[index] = top[M-1];
        top[M-1] = index;

        return true;
    }

    int pop(int M){
        if(top[M-1] == -1){return false;}

        int index = top[M-1];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main(){
    NStack n(3,6);
    n.push(1,1);
    n.pop(1);
    return 0;
}