#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,k,depotX,depotY;
vector<array<ll,2>>a;
void print(){
    cout<<depotX<<endl;
    cout<<depotY<<endl;
    cout<<n<<endl;
    cout<<2<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i][0]<<" "<<a[i][1]<<endl;
    }
    cout<<k;
}
void writeTest(int test)
{
    startTest(test);
    /*
        Generator Code
    */
   a.clear();
   if(test==0){
    n = 3;
    depotX = 1;
    depotY = 1;
    k = 1;
    a = {{0,0},{1,1},{2,2}};
    print();
   }
   if(test==1){
    n = 4;
    depotX = 0;
    depotY = 1;
    k = 2;
    a={{0,0},{1,1},{4,2},{-1,0}};
    print();
   }
   if(test==3){
    n = 1;
    k = 1;
    depotX = 0;
    depotY = 0;
    a = {{0,0}};
    print();
    
   }
   if(test==2 || test == 4 || test == 5){
    n = 6;
    depotX = rnd.next(-100,100);
    depotY = rnd.next(-100,100);
    k = rnd.next(3,4);
    for(int i=0;i<n;i++){
        a.push_back({rnd.next(-100,100),rnd.next(-100,100)});
    }
    print();
   }
   if(test>=6 && test<=8){
    n = rnd.next(6,7);
    k = rnd.next(4,5);
    depotX = rnd.next(-100000,100000);
    depotY = rnd.next(-100000,100000);
    for(int i=0;i<n;i++){
        a.push_back({rnd.next(-100000,100000),rnd.next(-100000,100000)});
    }
    print();
   }
   if(test>=9 && test<=14){
    n = 10;
    k = rnd.next(3,7);
    if(test==9 || test==13)k = n;
    if(test==10)k = 4;
    if(test==11)k = 5;
    if(test==12)k = 3;
    if(test==14)k = 6;
    depotX = rnd.next(-100000,100000);
    depotY = rnd.next(-100000,100000);
    a.push_back({100000,100000});
    a.push_back({-100000,-100000});
    a.push_back({100000,-100000});
    a.push_back({-100000,100000});
    for(int i=0;i<n-4;i++){
        a.push_back({rnd.next(-100000,100000),rnd.next(-100000,100000)});
    }
    shuffle(a.begin(),a.end());
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
