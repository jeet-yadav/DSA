#include<iostream>
using namespace std;

class Hero {
    public:
    char level;
    int health;
};

int main(){
    Hero h1;
   cout<<sizeof(h1)<<endl;
   //size shows 8 bit due to padding of 3 bits exta in int health, which takes 4 bytes
   //This padding is included beacause of memory alignment, which makes program faster
   //4 bits of storage is stored in multiple of 4, so extra 3 bits are added as padding 
    return 0;
}