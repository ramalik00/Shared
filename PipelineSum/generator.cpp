#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n;
vector<ll>responseTime;

void print(){
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<responseTime[i]<<endl;
    }
}
void writeTest(int test)
{
    startTest(test);
    /*
        Generator Code
    */
   responseTime.clear();
   if(test==0){
    n = 2;
    responseTime = {1,2};
    print();
   }
   if(test==1){
    n = 3;
    responseTime = {3,1,2};
    print();
   }
   if(test==3){
    n = 1;
    responseTime = {1};
    
    print();
   }
   if(test==2 || test == 4 || test == 5){
    n = rnd.next(200,300);
    if(test==2)n=6;
    for(int i=0;i<n;i++){
        responseTime.push_back(rnd.next(1e1,1e9));
    }
    
    print();
   }
   if(test>=6 && test<=8){
    n = rnd.next(2e3,2e3+ 100);
    for(int i=0;i<n;i++){
        responseTime.push_back(rnd.next(1e1,1e9));
    }
    print();
   }
   // After this only optimal solution test cases should be generated
   if(test==9){
    n = 3e5;
    for(int i=0;i<n;i++){
        responseTime.push_back(int(1e9));
    }
    
    print();
   }
   if(test>=10 && test<=14){
    n = 3e5;
    int nn = 1.5e5;
    if(test>12)n=rnd.next(3e5-3,3e5-1);
    int z = rnd.next(nn-100,nn+100);
    int x = rnd.next(1e7,1e8);
    for(int i=0;i<z;i++){
        responseTime.push_back(rnd.next(1e1,1e8));
    }
    sort(responseTime.begin(),responseTime.end());
    for(int i=0;i<n-z;i++){
        responseTime.push_back(x);
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
