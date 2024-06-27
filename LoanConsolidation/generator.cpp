#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,m;
vector<array<ll,3>>debt;
void print(){
    cout<<n<<endl;
    cout<<m<<endl;
    cout<<3<<endl;
    for(auto x:debt){
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
    }

}
void writeTest(int test)
{
    startTest(test);
    /*
        Generator Code
    */
   debt.clear();
   if(test==0){
    n = 4,m=3;
    debt = {{1,2,30},{2,3,20},{3,4,25}};
    print();
   }
   if(test==1){
    n = 3,m=3;
    debt = {{1,2,10},{2,3,10},{3,1,10}};
    print();
   }
   if(test==2){
    n = 4,m=5;
    debt = {{1,2,30},{2,3,20},{3,4,25},{4,2,10},{1,3,5}};
    print();
   }
   if(test==3){
    n = 1,m=0;
    debt={};
    print();
   }
   if(test>=4 && test<=8){
    n = rnd.next(2000,3000);
    m = rnd.next(2*n,3*n);
    int z = rnd.next(m/2,4*m/5);
    for(int i=0;i<z;i++){
        ll u = rnd.next(1LL,n/30);
        ll v = rnd.next(1LL,n/30);
        ll w = rnd.next(1e5,1e9);
        debt.push_back({u,v,w});
    }
    for(int i=z;i<m;i++){
        ll u = rnd.next(n/2,n-1);
        ll v = rnd.next(n/2,n-1);
        ll w = rnd.next(1e5,1e9);
        debt.push_back({u,v,w});
    }
    shuffle(debt.begin(),debt.end());
    print();
   }
   if(test==9){
    n = 1e5;
    m = 2e5;
    int z = rnd.next(m/2,4*m/5);
    for(int i=0;i<z;i++){
        ll u = rnd.next(1LL,n/2);
        ll v = rnd.next(1LL,n/2);
        ll w = rnd.next(1e9,1e9);
        debt.push_back({u,v,w});
    }
    for(int i=z;i<m;i++){
        ll u = rnd.next(n/2,n-1);
        ll v = rnd.next(n/2,n-1);
        ll w = rnd.next(1e9,1e9);
        debt.push_back({u,v,w});
    }
    shuffle(debt.begin(),debt.end());
    print();
   }
   if(test>=10 && test<=14){
    n = 1e5;
    m = 2e5;
    int z = rnd.next(m/2,4*m/5);
    for(int i=0;i<m-z;i++){
        ll u = rnd.next(1LL,n/30);
        ll v = rnd.next(1LL,n/30);
        ll w = rnd.next(1e7,1e9);
        debt.push_back({u,v,w});
    }
    for(int i=m-z;i<m;i++){
        if(i%30==0){
            ll u = n;
            ll v = rnd.next(n/30,n-5);
            ll w = rnd.next(1e8,1e9);
            ll p = rnd.next(0,3);
            if(p==0)swap(u,v);
            debt.push_back({u,v,w});
        }
        ll u = rnd.next(1LL,n);
        ll v = rnd.next(1LL,n);
        ll w = rnd.next(1e8,1e9);
        debt.push_back({u,v,w});
    }
    shuffle(debt.begin(),debt.end());
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
