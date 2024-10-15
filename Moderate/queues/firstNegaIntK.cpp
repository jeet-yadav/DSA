#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<int> printFirstNegativeInteger(queue<int> q, int k){
    vector<int> v;
    int size = q.size();

    for(int i=0; i<=size-k; i++){
        bool foundNegative = false;

        for(int j=0; j<k; j++){
            int value = q.front();
            q.pop();

            if(value < 0 && !foundNegative){
                v.push_back(value);
                foundNegative = true;
                
            }
            q.push(value);

            if(!foundNegative){
                v.push_back(0);
            }
        }
        cout<<v[i]<<" ";
    }

    return v;
}

int main(){
    queue<int> q;

    q.push(-8);
    q.push(-2);
    q.push(3);
    q.push(-6);
    q.push(10);

    vector<int> v = printFirstNegativeInteger(q,2);
    return 0;
}