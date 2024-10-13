#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q; // Create a queue of integers
    queue<int> qt; // Create another queue of integers

    // Adding values to the back of the queue
    q.push(1);
    q.push(2);
    q.push(3);
    
    // Remove the front element
    q.pop();

    // Output the front and back elements of the queue
    cout<<"Front element of q: " <<q.front()<<endl;
    cout<<"Back element of q: " <<q.back()<<endl;

    // Output the size and emptiness of the queue
    cout<<"Size of q: " <<q.size()<<endl;          
    cout<<"Is q empty? "<<(q.empty() ? "Yes" : "No")<<endl; 

    // Clear the queue by swapping with an empty queue
    q.swap(qt); // Swap with empty queue

    cout<<"After clearing, is q empty? "<<(q.empty() ? "Yes" : "No")<<endl;
    
    // Output the front and back elements of the swapped queue
    cout<<"After swap, front element of q: "<<qt.front()<<endl;
    cout<<"After swap, back element of q: "<<qt.back()<<endl;

    return 0;
}
