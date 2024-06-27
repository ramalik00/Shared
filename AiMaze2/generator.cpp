#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,m;
vector<string>maze;
void print(){
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<maze[i]<<endl;
    }
}
void writeTest(int test)
{
    startTest(test);
    /*
        Generator Code
    */
   maze.clear();
//    if(test==0){
//     n = 2000;
//     m = 2000;
    
//     char a[n][m];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             a[i][j] = '.';
//         }
//     }
//     int startx = rnd.next(0LL,3LL);
//     int starty = rnd.next(0LL,1LL);
//     int endx = rnd.next(n-3,n-1);
//     int endy = rnd.next(m-2,m-1);
//     a[startx][starty] = 'S';
//     a[endx][endy] = 'E';
//     // int walls = rnd.next(n*m/7,n*m/5);
//     // for(int i=0;i<walls;i++){
//     //     int x = rnd.next(0LL,n-1);
//     //     int y = rnd.next(0LL,m-1);
//     //     if(a[x][y] == '.'){
//     //         a[x][y] = 'W';
//     //     }
//     // }
//     int coins = rnd.next(4,5);
//     for(int i=0;i<coins;i++){
//         int x = rnd.next(0LL,n-1);
//         int y = rnd.next(0LL,m-1);
//         if(a[x][y] == '.'){
//             a[x][y] = 'C';
//         }
//     }
//     for(int i=0;i<n;i++){
//         string s = "";
//         for(int j=0;j<m;j++){
//             s+=a[i][j];
//         }
//         maze.push_back(s);
//     }
    
   
    
//     print();
//    }
   if(test==0){
    n = 3;
    m = 5;
    maze = {"S.W..", ".WCW.", "W.E.."};
    print();
   }
   if(test==1){
     n = 3;
    m = 5;
    maze = {"C.W.S", ".W.C.", "W..E."};
    print();
   }
   if(test==3){
    n = 1,m = 2;
    maze = {"SE"};
    print();
    
   }
   if(test==2 || test == 4 || test == 5){
    n = rnd.next(10,12);
    m = rnd.next(10,15);
    if(test==2){
        n = 6;
        m = 5;
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
    int endy = rnd.next(m-2,m-1);
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
    int coins = rnd.next(n*m/9,n*m/4);
    for(int i=0;i<coins;i++){
        int x = rnd.next(0LL,n-1);
        int y = rnd.next(0LL,m-1);
        if(a[x][y] == '.'){
            a[x][y] = 'C';
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
   if(test==6){
    n = rnd.next(150,260);
    m = rnd.next(250,360);
    
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j] = '.';
        }
    }
    int startx = rnd.next(0LL,n-1);
    int starty = rnd.next(0LL,1LL);
    int endx = rnd.next(0LL,n-1);
    int endy = rnd.next(m-2,m-1);
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
    int coins = rnd.next(n*m/9,n*m/4);
    for(int i=0;i<coins;i++){
        int x = rnd.next(0LL,n-1);
        int y = rnd.next(0LL,m-1);
        if(a[x][y] == '.'){
            a[x][y] = 'C';
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
   if(test>=7 && test<=8){
    n = rnd.next(200,350);
    m = rnd.next(150,350);
    
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            a[i][j] = '.';
        }
    }
    int startx = rnd.next(0LL,n-1);
    int starty = rnd.next(0LL,1LL);
    int endx = rnd.next(0LL,n-1);
    int endy = rnd.next(m-2,m-1);
    a[startx][starty] = 'S';
    a[endx][endy] = 'E';
    if(endx-1>=0)a[endx-1][endy] = 'W';
    if(endx+1<n)a[endx+1][endy] = 'W';
    if(endy-1>=0)a[endx][endy-1] = 'W';
    if(endy+1<m)a[endx][endy+1] = 'W';
    int walls = rnd.next(n*m/6,n*m/5);
    for(int i=0;i<walls;i++){
        int x = rnd.next(0LL,n-1);
        int y = rnd.next(0LL,m-1);
        if(a[x][y] == '.'){
            a[x][y] = 'W';
        }
    }
    int coins = rnd.next(n*m/12,n*m/8);
    for(int i=0;i<coins;i++){
        int x = rnd.next(0LL,n-1);
        int y = rnd.next(0LL,m-1);
        if(a[x][y] == '.'){
            a[x][y] = 'C';
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
   if(test>=9 && test<=11){
    n = 800;
    m = 800;
    
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
    int startx = rnd.next(0LL,n-1);
    int starty = rnd.next(0LL,1LL);
    int endx = rnd.next(0LL,n-1);
    int endy = rnd.next(m-2,m-1);
    a[0][0] = 'S';
    a[n-1][m-1] = 'E';
    
    int coins = rnd.next(100,150);
    for(int i=0;i<coins;i++){
        int x = rnd.next(0LL,n-1);
        int y = rnd.next(0LL,m-1);
        if(a[x][y] == '.'){
            a[x][y] = 'C';
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
   if(test>=12 && test<=14){
    n = 800;
    m = 800;
    
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j] = '.';
        }
    }
    int startx = rnd.next(0LL,3LL);
    int starty = rnd.next(0LL,1LL);
    int endx = rnd.next(n-3,n-1);
    int endy = rnd.next(m-2,m-1);
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
    int coins = rnd.next(4,5);
    for(int i=0;i<coins;i++){
        int x = rnd.next(0LL,n-1);
        int y = rnd.next(0LL,m-1);
        if(a[x][y] == '.'){
            a[x][y] = 'C';
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
   
   
   
}


int main(int argc, char* argv[])
{
    int tests = atoi(argv[1]);
    for (int i = 0; i < tests; i++)
        writeTest(i);
    return 0;
}
