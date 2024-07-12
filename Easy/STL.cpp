#include<iostream>
#include<bits/stdc++.h>
// #include<array>                         THE FOLLOWING FILE CONTAINS STL(STANDARD TEMPLATE LIBRARIES)
// #include<vector>                                                 IN C++
// #include<deque>
// #include<list>
// #include<stack>
// #include<queue>
// #include<set>
// #include<map>
#include<algorithm>

using namespace std;
int main(){
    //ARRAY
    // int basic[3] = {1,2,3};                          //normal array
    // array<int,4> a = {1,2,3,4};                      //
    // cout<<"Size "<<a.size()<<endl;                   //size of array
    // cout<<"Element at 2nd index is "<<a.at(2)<<endl;
    // cout<<"Empty or not "<<a.empty()<<endl;          // GIves a logial value
    // cout<<"First element"<<a.front()<<endl;          //Gives first element
    // cout<<"Last element"<<a.back()<<endl;            //Gives last element

    //VECTOR
    // vector<int> v;
    // cout<<"Capicity of vector "<<v.capacity()<<endl;//To check the capacity or the number of element the current vector can hold
    // v.push_back(4);                                 //To add an element in an vector at last
    // cout<<"Capicity of vector "<<v.capacity()<<endl;//Capacity increased by 1
    // v.push_back(7);                                 //added one more element capacity increased by 1
    // v.push_back(3);                                 //added another now capacity is doubled
    // cout<<"Capicity of vector "<<v.capacity()<<endl;
    // cout<<"Capicity of vector "<<v.capacity()<<endl;
    // cout<<"Size of vector "<<v.size()<<endl;        //Total number of elements vector have
    // cout<<"Element at 2nd index is "<<v.at(2)<<endl;
    // cout<<"First element"<<v.front()<<endl;         //Gives first element
    // cout<<"Last element"<<v.back()<<endl;           //Gives last element
    // v.pop_back;                                     //Removes 1 element 
    // v.clear()                                       //Removes all the element but not the capacity
    // vector<int> b(5,1);                             //Initalize all the elements by 1
    // vector<int> b2(b);                            //copies all element from another vector

    // //DEQUE
    // deque<int> d;   
    // d.push_back(1);                                  //adds element from back
    // d.push_front(2);                                 //adds element from front
    // d.pop_back();                                    //removes element from back
    // d.pop_front();                                   //removes element from front
    // cout<<"First Element"<<d.at(1);                  //access a specific element
    // cout<<"is Empty or not"<<d.empty()               //check if the dequr is empty or not
    // d.erase(d.begin(),d.begin()+1);                  //delete 1 element

    //LIST                                              
    // list<int> l;                                     //creating a list
    // l.push_back(4);                                  //add element from back
    // l.push_front(3);                                 //add element from front
    // l.push_back(7);                                  
    // l.erase(l.begin());                              
    // l.pop_back();
    // l.pop_front();
    // l.size();

    //STACK
    // stack<string> s;
    // s.push("Hello");
    // s.push("World");
    // cout<<s.top()<<endl;
    // s.pop()

    //QUEUE
    // priority_queue<int> maxi; //priortize maximum element first
    // priority_queue<int,vector<int> , greater<int> > mini;// priortize minimum element first
    // maxi.push(1);
    // maxi.push(3);
    // maxi.push(9);
    // maxi.push(4);
    // n = maxi.size();
    // for(int i=0; i<n; i++){
    //     cout<<maxi.top()<<endl;
    //     maxi.pop();
    // }

    //SET
    // set<int> s = {1,9,4,1,1,1,1,2,65,3};
    // s.insert(0);
    // s.erase(s.begin());
    // cout<<s.count(-1);
    // for(auto i : s){
    //     cout<<i<<" ";
    // }
    // set<int>::iterator itr = s.find(5);
    // for(auto it=itr; it!=s.end(); it++){
    // cout<<*it<<" ";
    // }

    //MAP
    // map<int,string> m;
    // m[1] = "my"; //1 is the key and "hello" is the value
    // m[13] = "is";
    // m.insert({2,"name"});
    // for(auto i : m){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    // cout<<"is the second element present "<<m.count(2);//check if the key 2 is present in map or not
    // m.erase(m.count(13));
    // cout<<endl;
    // for(auto i : m){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    // auto it = m.find(2);
    // for(auto i=it; i!=m.end(); i++){
    //     cout<<(*i).first<<endl;
    // }

    //ALGORITHM
    // vector<int> vec = {1,3,5,6,7,9,10,12,15};
    // cout<<"is 6 in vec or not?? "<<binary_search(vec.begin(),vec.end(),6)<<endl;
    // cout<<"upper bound "<<upper_bound(vec.begin(),vec.end(),6) -vec.begin()<<endl;
    // cout<<"lower bound "<<lower_bound(vec.begin(),vec.end(),6) -vec.begin()<<endl;
    
    // int a1 = 3;
    // int b1 = 5;
    // cout<<"max "<<max(a1,b1)<<endl;
    // cout<<"min "<<min(a1,b1)<<endl;

    // swap(a1,b1);
    // cout<<"a is "<<a1<<endl;
    // cout<<"b is "<<b1<<endl;

    // string abcd = "abcd";
    // reverse(abcd.begin(),abcd.end());
    // cout<<"reverse of abcd is "<<abcd<<endl;

    // rotate(vec.begin(),vec.end()+1,vec.end());
    // for(int i:vec){
    //     cout<<i<<" ";
    // }

    // vector<int> vec2 = {6,4,1,5,2,56,8,3,21,5};//Based on intro auto, combination of quick, heap and insertion sort
    // sort(vec2.begin(),vec2.end());
    // for(int i:vec2){
    //     cout<<i<<" ";
    // }
    return 0;

}