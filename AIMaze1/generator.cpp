#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,m,k;
vector<string>maze;
void print(){
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<maze[i]<<endl;
    }
}
void trueCase(){
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
    int walls = rnd.next(n*m/10,n*m/5);
    for(int i=0;i<walls;i++){
        int x = rnd.next(0LL,n-1);
        int y = rnd.next(0LL,m-1);
        if(a[x][y] == '.'){
            a[x][y] = 'W';
        }
    }
    int traps = rnd.next(n*m/10,n*m/5);
    for(int i=0;i<traps;i++){
        int x = rnd.next(0LL,n-1);
        int y = rnd.next(0LL,m-1);
        if(a[x][y] == '.'){
            a[x][y] = 'T';
        }
    }
    for(int i=0;i<n;i++){
        string s = "";
        for(int j=0;j<m;j++){
            s+=a[i][j];
        }
        maze.push_back(s);
    }
    
    print();

}
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void falseCase(){
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
    
    int walls = rnd.next(n*m/10,n*m/5);
    for(int i=0;i<walls;i++){
        int x = rnd.next(0LL,n-1);
        int y = rnd.next(0LL,m-1);
        if(a[x][y] == '.'){
            a[x][y] = 'W';
        }
    }
    int traps = rnd.next(n*m/10,n*m/5);
    for(int i=0;i<traps;i++){
        int x = rnd.next(0LL,n-1);
        int y = rnd.next(0LL,m-1);
        if(a[x][y] == '.'){
            a[x][y] = 'T';
        }
    }
    for(int i=0;i<4;i++){
        int x = startx + dx[i];
        int y = starty + dy[i];
        if(x>=0 && x<n && y>=0 && y<m && a[x][y] == '.'){
            a[x][y] = 'T';
        }
    }
    for(int i=0;i<4;i++){
        int x = endx + dx[i];
        int y = endy + dy[i];
        if(x>=0 && x<n && y>=0 && y<m && a[x][y] == '.'){
            a[x][y] = 'T';
        }
    }
    for(int i=0;i<n;i++){
        string s = "";
        for(int j=0;j<m;j++){
            s+=a[i][j];
        }
        maze.push_back(s);
    }
    
    print();
}
void writeTest(int test)
{
    startTest(test);
    /*
        Generator Code
    */
   maze.clear();
   
   if(test==0){
    n = 5;
    m = 5;
    maze = {"S....", ".WWW.", "T...T", "WWWW.", "E...."};
    
    print();
   }
   if(test==1){
     n = 3;
    m = 3;
    maze = {"S.T", "T..", "ET."};
    
    print();
   }
   if(test==3){
    n = 1,m = 2;
   
    maze = {"SE"};
    print();
    
   }
   if(test==2 || test == 4 || test == 5){
    
    n = rnd.next(40,50);
    m = rnd.next(50,60);
    
    if(test==2){
        n = 6;
        m = 6;
       
    }
    
    falseCase();
   }
   if(test>=6 && test<=8){
    n = rnd.next(100,300);
    m = rnd.next(100,300);
    falseCase();
   }
   if(test>=9 && test<=14){
    n = 500;
    m = 500;
    if(test%2==0){
        trueCase();
    }
    else{
        falseCase();
    }
   }
   
   
   
}


int main(int argc, char* argv[])
{
    int tests = atoi(argv[1]);
    for (int i = 0; i < tests; i++)
        writeTest(i);
    return 0;
}
