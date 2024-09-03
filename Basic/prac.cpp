#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool safe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& maze){
    if((x >= 0 && x <= n-1) && (y >= 0 && y <= n-1) && (visited[x][y] == 0) && maze[x][y] == 1){
        return true;
    }
    return false;
}

void routes(vector<vector<int>>& maze, int n,vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    int newx = x+1;
    int newy = y;
    if(safe(newx, newy, n, visited, maze)){
        path.push_back('D');
        routes(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    newx = x;
    newy = y-1;
    if(safe(newx, newy, n, visited, maze)){
        path.push_back('L');
        routes(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    newx = x;
    newy = y+1;
    if(safe(newx, newy, n, visited, maze)){
        path.push_back('R');
        routes(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    newx = x-1;
    newy = y;
    if(safe(newx, newy, n, visited, maze)){
        path.push_back('U');
        routes(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> maze(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>maze[i][j];
        }
    }

    if(maze[0][0] == 0){
        cout<<"No path available"<<endl;
        return 0;
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<string> ans;
    string path = "";

    routes(maze, n, ans, 0, 0, visited, path);
    sort(ans.begin(), ans.end());

    for(const string& p : ans){
        cout<<p<<endl;
    }
    return 0;
}