#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,t1,t2;
vector<ll>a;
void print(){
    cout<<n<<endl;
    for(auto x:a)cout<<x<<endl;
    cout<<t1<<endl;
    cout<<t2;

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
    a={10,15,5};
    t1 = 16;
    t2 = 14;
    print();
   }
   if(test==1){
    n = 4;
    a={10,10,10,20};
    t1 = 40;
    t2 = 20;
    print();
   }
   if(test==3){
    n = 1;
    a={1};
    t1 = 1;
    t2 = 1;
    print();
   }
   if(test==2 || test == 4 || test == 5){
    n = rnd.next(10,15);
    if(test==2)n=8;
    t1 = rnd.next(100,200);
    t2 = rnd.next(100,200);
    for(int i=0;i<3;i++){
        a.push_back(rnd.next(1,2));
    }
    ll m = min(t1,t2);
    for(int i=3;i<n;i++){
        a.push_back(rnd.next(m+1,m+10));
    }
    shuffle(a.begin(),a.end());
    print();
   }
   if(test>=6 && test<=8){
    n = 100;
    t1  = rnd.next(200,300);
    t2 = rnd.next(200,300);
    int sum = 0;
    int cur = 0;
    for(int i=0;i<3;i++){
        a.push_back(2*rnd.next(3,5)+1);
        sum+=a.back();
        cur++;
    }
    sum = t1-sum;
    a.push_back(rnd.next(sum-3,sum-1));
    cur++;
    sum = 0;
    for(int i=0;i<3;i++){
        a.push_back(2*rnd.next(16,20)+1);
        sum+=a.back();
        cur++;
    }
    sum = t2-sum;
    a.push_back(rnd.next(sum-4,sum-1));
    cur++;
    int z = rnd.next(9*n/10,n-1);
    for(int i=cur;i<z;i++){
        a.push_back(2*rnd.next(100,150)+1);
    }
    for(int i=z;i<n;i++){
        a.push_back(rnd.next(300,500));
    }
    shuffle(a.begin(),a.end());
    print();
   }
   if(test==9){
    n = 500;
    t1 = 500;
    t2 = 500;
    for(int i=0;i<n/2;i++){
        a.push_back(500);
    }
    for(int i=n/2;i<n;i++){
        a.push_back(500);
    }
    shuffle(a.begin(),a.end());
    print();
   }
   if(test>=10 && test<=14){
    n = 500;
    t1  = rnd.next(490,500);
    t2 = rnd.next(490,497);
    int sum = 0;
    int cur = 0;
    for(int i=0;i<3;i++){
        a.push_back(2*rnd.next(3,5)+1);
        sum+=a.back();
        cur++;
    }
    sum = t1-sum;
    a.push_back(rnd.next(sum-3,sum-1));
    cur++;
    sum = 0;
    for(int i=0;i<3;i++){
        a.push_back(2*rnd.next(18,20)+1);
        sum+=a.back();
        cur++;
    }
    sum = t2-sum;
    a.push_back(rnd.next(sum-4,sum-1));
    cur++;
    int z = rnd.next(9*n/10,n-1);
    for(int i=cur;i<z;i++){
        a.push_back(2*rnd.next(150,200));
    }
    for(int i=z;i<n;i++){
        a.push_back(rnd.next(260,350));
    }
    shuffle(a.begin(),a.end());
    if(test%2==0)swap(t1,t2);
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
