#include<iostream>
#include<queue> 
#include<stack>
using namespace std;

// FAMOUS QUESTION 
//https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1

int tour(int petrol[], int distance[], int n){
    int deficit = 0;// Tracks the total deficit when the truck can't move forward
    int balance = 0;// Tracks the current fuel balance at each step
    int start = 0;// Potential starting point of the tour

    for(int i=0; i<n; i++){
        // Calculate balance: how much petrol is left after moving to the next pump
        balance += petrol[i] - distance[i];

        // If balance becomes negative, this means we can't continue from the current starting point
        if(balance < 0){
            // Add the current negative balance to deficit
            deficit += balance;

            // Update the starting point to the next petrol pump
            start = i+1;

            // Reset the balance as we're considering a new starting point
            balance = 0;
        }
    }


    // After the loop, if the total balance (balance + deficit) is non-negative, the tour is possible
    if(deficit + balance >= 0){
        return start;   // Return the starting point from which the tour can be completed
    }
    else{
        return -1;  // If it's not possible to complete the tour, return -1
    }
}

int main(){
    int petrol[4] = {4,6,7,4};
    int distance[4] = {5,1,2,3};

    int canTour = tour(petrol, distance, 4);
    cout<<canTour;
    return 0; 
}