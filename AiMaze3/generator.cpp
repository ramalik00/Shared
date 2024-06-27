#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,m,k;
vector<string>maze;
vector<vector<int>>portals;
array<int,2> findClosestWallToEnd(){
    array<int,2> start;
    array<int,2> end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j] == 'S'){
                start = {i,j};
            }
            if(maze[i][j] == 'E'){
                end = {i,j};
            }
        }
    }
    int x = end[0];
    int y = end[1];
    int dist = 1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j] == 'W'){
                int d = abs(i-x) + abs(j-y);
                if(d<dist){
                    dist = d;
                    start = {i,j};
                }
            }
        }
    }
    return start;

}
void print(){
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<maze[i]<<endl;
    }
    cout<<k<<endl;
    cout<<4<<endl;
    for(int i=0;i<k;i++){
        cout<<portals[i][0]<<" "<<portals[i][1]<<" "<<portals[i][2]<<" "<<portals[i][3]<<endl;
    }
}
void writeTest(int test)
{
    startTest(test);
    /*
        Generator Code
    */
   maze.clear();
   portals.clear();
   if(test==0){
    n = 5;
    m = 4;
    maze = {"S..W", "WWW.", "..W.", "..E.", "...."};
    k = 2;
    portals = {{0, 2, 2, 0}, {2, 0, 3, 1}};
    print();
   }
   if(test==1){
     n = 3;
    m = 3;
    maze = {"S.W", "WW.", ".EW"};
    k = 1;
    portals = {{0, 1, 1, 2}};
    print();
   }
   if(test==3){
    n = 1,m = 2;
    k = 1;
    portals = {{0,0,0,1}};
    maze = {"SE"};
    print();
    
   }
   if(test==2 || test == 4 || test == 5){
    
    n = rnd.next(40,50);
    m = rnd.next(50,60);
    k = 50;
    if(test==2){
        n = 6;
        m = 6;
        k = 3;
    }
    
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j] = '.';
        }
    }
    int startx = rnd.next(0LL,n-1);
    int starty = rnd.next(0LL,1LL);
    int endx = rnd.next(0LL,n-1);
    int endy = rnd.next(n-2,n-1);
    a[startx][starty] = 'S';
    a[endx][endy] = 'E';
    int walls = rnd.next(n*m/6,n*m/5);
    for(int i=0;i<walls;i++){
        int x = rnd.next(0LL,n-1);
        int y = rnd.next(0LL,m-1);
        if(a[x][y] == '.'){
            a[x][y] = 'W';
        }
    }
    for(int i=0;i<n;i++){
        string s = "";
        for(int j=0;j<m;j++){
            s+=a[i][j];
        }
        maze.push_back(s);
    }
    array<int,2> start = findClosestWallToEnd();
    vector<array<int,2>>v,v2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j] == '.'){
                v.push_back({i,j});
            }
            if(maze[i][j] == 'W'){
                v2.push_back({i,j});
            }
        }
    }
    int z = 1;
    if(test!=2)z = rnd.next(4*k/5,k-7);
    for(int i=0;i<z;i++){
        int x = rnd.next(0,(int)v.size()-1);
        int y = rnd.next(0,(int)v.size()-1);
        if(x == y)continue;
        portals.push_back({v[x][0],v[x][1],v[y][0],v[y][1]});
    }
    for(int i=0;i<k-z;i++){
        int x = rnd.next(0,(int)v.size()-1);
        int y = rnd.next(0,(int)v2.size()-1);
        if(i<10){
            portals.push_back({v[x][0],v[x][1],start[0],start[1]});
        }
        else portals.push_back({v[x][0],v[x][1],v2[y][0],v2[y][1]});
    }
    k = portals.size();
    shuffle(portals.begin(),portals.end());
    
    print();
   }
   if(test>=6 && test<=8){
    n = rnd.next(100,220);
    m = rnd.next(100,220);
    k = 1e3;
    
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j] = '.';
        }
    }
    int startx = rnd.next(0LL,n-1);
    int starty = rnd.next(0LL,1LL);
    int endx = rnd.next(0LL,n-1);
    int endy = rnd.next(n-2,n-1);
    a[startx][starty] = 'S';
    a[endx][endy] = 'E';
    if(test>=7 && test<=8){
        if(endx-1>=0)a[endx-1][endy] = 'W';
        if(endx+1<n)a[endx+1][endy] = 'W';
        if(endy-1>=0)a[endx][endy-1] = 'W';
        if(endy+1<m)a[endx][endy+1] = 'W';
    }
    int walls = rnd.next(n*m/6,n*m/5);
    for(int i=0;i<walls;i++){
        int x = rnd.next(0LL,n-1);
        int y = rnd.next(0LL,m-1);
        if(a[x][y] == '.'){
            a[x][y] = 'W';
        }
    }
    for(int i=0;i<n;i++){
        string s = "";
        for(int j=0;j<m;j++){
            s+=a[i][j];
        }
        maze.push_back(s);
    }
    array<int,2> start = findClosestWallToEnd();
    vector<array<int,2>>v,v2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j] == '.'){
                v.push_back({i,j});
            }
            if(maze[i][j] == 'W'){
                v2.push_back({i,j});
            }
        }
    }
    int z = rnd.next(4*k/5,k-10);
    for(int i=0;i<z;i++){
        int x = rnd.next(0,(int)v.size()-1);
        int y = rnd.next(0,(int)v.size()-1);
        if(x == y)continue;
        portals.push_back({v[x][0],v[x][1],v[y][0],v[y][1]});
    }
    for(int i=0;i<k-z;i++){
        int x = rnd.next(0,(int)v.size()-1);
        int y = rnd.next(0,(int)v2.size()-1);
        if(i<10){
            portals.push_back({v[x][0],v[x][1],start[0],start[1]});
        }
        else portals.push_back({v[x][0],v[x][1],v2[y][0],v2[y][1]});
    }
    k = portals.size();
    shuffle(portals.begin(),portals.end());
    
    print();
   }
   if(test>=9 && test<=11){
    n = 500;
    m = 500;
    k = 1e5;
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j] = '.';
        }
    }
    int startx = rnd.next(0LL,n-1);
    int starty = rnd.next(0LL,1LL);
    int endx = rnd.next(0LL,n-1);
    int endy = rnd.next(n-2,n-1);
    a[startx][starty] = 'S';
    a[endx][endy] = 'E';
    int walls = rnd.next(n*m/6,n*m/5);
    for(int i=0;i<walls;i++){
        int x = rnd.next(0LL,n-1);
        int y = rnd.next(0LL,m-1);
        if(a[x][y] == '.'){
            a[x][y] = 'W';
        }
    }
    for(int i=0;i<n;i++){
        string s = "";
        for(int j=0;j<m;j++){
            s+=a[i][j];
        }
        maze.push_back(s);
    }
    array<int,2> start = findClosestWallToEnd();
    vector<array<int,2>>v,v2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j] == '.' && i<n/2 && j<m/2){
                v.push_back({i,j});
            }
            if(maze[i][j] == 'W'){
                v2.push_back({i,j});
            }
        }
    }
    int z = rnd.next(4*k/5,k-10);
    for(int i=0;i<z;i++){
        int x = rnd.next(0,(int)v.size()-1);
        int y = rnd.next(0,(int)v.size()-1);
        //if(x == y)continue;
        portals.push_back({v[x][0],v[x][1],v[y][0],v[y][1]});
    }
    for(int i=0;i<k-z;i++){
        int x = rnd.next(0,(int)v.size()-1);
        int y = rnd.next(0,(int)v2.size()-1);
        if(i<10){
            portals.push_back({v[x][0],v[x][1],start[0],start[1]});
        }
        else portals.push_back({v[x][0],v[x][1],v2[y][0],v2[y][1]});
    }
    k = portals.size();
    shuffle(portals.begin(),portals.end());
    
    print();
   }
   if(test==12){
    n = 500;
    m = 500;
    k = 1;
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(j%2==0)a[i][j] = '.';
            else a[i][j] = 'W';
            if(i==n-1 && j%4==1)a[i][j]='.';
            if(i==0 && j%4==3)a[i][j]='.';
            if(j==m-1)a[i][j] = '.';
        }
    }
    int startx = 0;
    int starty = 0;
    int endx = n-1;
    int endy = m-1;
    a[startx][starty] = 'S';
    a[endx][endy] = 'E';
    for(int i=0;i<n;i++){
        string s = "";
        for(int j=0;j<m;j++){
            s+=a[i][j];
        }
        maze.push_back(s);
    }
    portals.push_back({0,1,1,1});
    
    print();
   }
   if(test>=13 && test<=14){
    n = 500;
    m = 500;
    k = rnd.next(10,12);
    char a[n][m];
    int cnt = rnd.next(3,4);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(j%2==0)a[i][j] = '.';
            else a[i][j] = 'W';
            if(i==n-1 && j%4==1)a[i][j]='.';
            if(i==0 && j%4==3)a[i][j]='.';
            if(j==m-1)a[i][j] = '.';
            int p = rnd.next(0,4);
            if(a[i][j]=='W' && cnt && p==0){
                a[i][j] = '.';
                cnt--;
            }
        }
    }
    int startx = rnd.next(0LL,n-1);
    int starty = rnd.next(0LL,1LL);
    int endx = rnd.next(0LL,n-1);
    int endy = rnd.next(n-2,n-1);
    a[startx][starty] = 'S';
    a[endx][endy] = 'E';
    // int walls = rnd.next(n*m/7,n*m/5);
    // for(int i=0;i<walls;i++){
    //     int x = rnd.next(0LL,n-1);
    //     int y = rnd.next(0LL,m-1);
    //     if(a[x][y] == '.'){
    //         a[x][y] = 'W';
    //     }
    // }
    for(int i=0;i<n;i++){
        string s = "";
        for(int j=0;j<m;j++){
            s+=a[i][j];
        }
        maze.push_back(s);
    }
    array<int,2> start = findClosestWallToEnd();
    vector<array<int,2>>v,v2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j] == '.' && i<n/4 && j<m/4){
                v.push_back({i,j});
            }
            if(maze[i][j] == 'W'){
                v2.push_back({i,j});
            }
        }
    }
    int z = k-2;
    for(int i=0;i<z;i++){
        int x = rnd.next(0,(int)v.size()-1);
        int y = rnd.next(0,(int)v.size()-1);
        //if(x == y)continue;
        portals.push_back({v[x][0],v[x][1],v[y][0],v[y][1]});
    }
    for(int i=0;i<k-z;i++){
        int x = rnd.next(0,(int)v.size()-1);
        int y = rnd.next(0,(int)v2.size()-1);
        portals.push_back({v[x][0],v[x][1],start[0],start[1]});
        
    }
    k = portals.size();
    shuffle(portals.begin(),portals.end());
    
    print();

   }
   
   
   
}


int main(int argc, char* argv[])
{
    int tests = atoi(argv[1]);
    for (int i = 0; i < tests; i++)
        writeTest(i);
    return 0;
}
