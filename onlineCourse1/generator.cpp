#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,m;
int scores[2001][2001];
void print(){
    cout<<n<<endl;
    cout<<m<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j==0)cout<<scores[i][j];
            else cout<<" "<<scores[i][j];
        }
        cout<<endl;
    }
    
}
void writeTest(int test)
{
    startTest(test);
    /*
        Generator Code
    */
 
   if(test==0){
    n = 2;
    m = 3;
    scores[0][0] = 85;
    scores[0][1] = 80;
    scores[0][2] = 95;
    scores[1][0] = 90;
    scores[1][1] = 70;
    scores[1][2] = 100;

    
    print();
   }
   if(test==1){
     n = 3,m = 4;
    scores[0][0] = 90;
    scores[0][1] = 80;
    scores[0][2] = 70;
    scores[0][3] = 100;
    scores[1][0] = 85;
    scores[1][1] = 95;
    scores[1][2] = 75;
    scores[1][3] = 80;
    scores[2][0] = 70;
    scores[2][1] = 75;
    scores[2][2] = 85;
    scores[2][3] = 90;

    print();
   }
   if(test==3){
    n = 1;
    m = 1;
    scores[0][0] = 1;
    print();
   }
   if(test==2 || test == 4 || test == 5){
    n = rnd.next(10,12);
    m = rnd.next(10,15);
    if(test==2){
        n = 6;
        m = 5;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scores[i][j] = rnd.next(1,100);
        }
    }
    
    print();
   }
   if(test>=6 && test<=8){
    n = rnd.next(200,350);
    m = rnd.next(150,350);
    for(int i=0;i<n;i++){
        int x1 = 88;
        int x2 = 100;
        if(i%5==0)x1=30;
        for(int j=0;j<m;j++){
            scores[i][j] = rnd.next(x1,x2);
        }
    }
    
    
    print();

   }
   if(test==9){
    n = 2000;
    m = 2000;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scores[i][j] = 100;
        }
    }
    print();
   }
   if(test>=10 && test<=14){
    n = 2000;
    m = 2000;
    for(int i=0;i<n;i++){
        int x1 = 88;
        int x2 = 100;
        if(i%5==0)x1=30;
        for(int j=0;j<m;j++){
            scores[i][j] = rnd.next(x1,x2);
        }
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
