#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,C;
vector<array<ll,3>>edges;
void print(){
    cout<<n<<" "<<m<<endl;
    for(auto i:edges){
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
    }
    cout<<C;

}
void writeTest(int test)
{
    startTest(test);
    /*
        Generator Code
    */
   edges.clear();
   if(test==0){
    n = 3,m=3,C=12;
    edges = {{1,3,6},{1,2,5},{2,3,3}};
    print();
   }
   if(test==1){
    n = 3,m=3,C=10;
    edges = {{1,3,5},{1,2,5},{2,3,6}};
    print();
   }
   if(test==2){
    n = 4,m = 5;
    edges = {{3,4,15},{4,5,5},{1,3,10},{4,5,2},{1,5,10}};
    C = 20;
    print();
   }
   if(test==3){
    n = 2,m=1,C=1;
    edges = {{1,2,1}};
    print();
   }
   if(test>=4 && test<=8){
    n = rnd.next(200,300);
    m = rnd.next(200,300);
    map<ll,ll>mp;
    ll z = rnd.next(3*m/4,4*m/5);
    for(int i=0;i<z;i++){
        ll u = rnd.next(1LL,n/2);
        ll v = rnd.next(u+1,n);
        ll w = rnd.next(1,1);
        edges.push_back({u,v,w});
        mp[u]+=w;
        mp[v]-=w;
    }
    for(int i=z;i<m;i++){
        ll u = rnd.next(n/2+1,n-1);
        ll v = rnd.next(u+1,n);
        ll w = rnd.next(50,60);
        edges.push_back({u,v,w});
        mp[u]+=w;
        mp[v]-=w;
    }
    shuffle(edges.begin(),edges.end());

    ll maxm = 0;
    for(auto i:mp){
        maxm = max(maxm,abs(i.second));
    }
    C = rnd.next(max(1LL,maxm-3),maxm);
    C= min(C,1000LL);
    print();
   }
   if(test==9){
    n = 1000;
    m = 1000;
    C = 1000;
    for(int i=0;i<m;i++){
        ll u = rnd.next(1LL,n-1);
        ll v = rnd.next(u+1,n);
        ll w = 100;
        edges.push_back({u,v,w});
    }
    print();
   }
   if(test==10){
       n = 1000;
    m = 1000;
    map<ll,ll>mp;
    ll z = rnd.next(3*m/4,4*m/5);
    for(int i=0;i<z;i++){
        ll u = rnd.next(1LL,n/2);
        ll v = rnd.next(u+1,n);
        ll w = rnd.next(1,1);
        edges.push_back({u,v,w});
        mp[u]+=w;
        mp[v]-=w;
    }
    for(int i=z;i<m;i++){
        ll u = rnd.next(n/2-5,n-1);
        ll v = rnd.next(u+1,n);
        ll w = rnd.next(50,65);
        edges.push_back({u,v,w});
        mp[u]+=w;
        mp[v]-=w;
    }
    shuffle(edges.begin(),edges.end());
    ll maxm = 0;
    for(auto i:mp){
        maxm = max(maxm,abs(i.second));
    }
    C = rnd.next(max(1LL,maxm-2),maxm);
    C= min(C,1000LL);
    C-=rnd.next(1,2);
    print();

   }
   if(test>=11 && test<=14){
        n = 1000;
    m = 1000;
    map<ll,ll>mp;
    C = 1000;
    ll z = rnd.next(910,920);
    for(int i=0;i<z;i++){
        ll u = 1;
        ll v = n;
        ll w = rnd.next(1,1);
        edges.push_back({u,v,w});
    }
    z = m-z;
    vector<ll>loc;
    for(ll i=0;i<3;i++){
        if(i==2)loc.push_back(rnd.next(n-50,n-35));
        else loc.push_back(rnd.next(2LL,n-1));
    }
    sort(loc.begin(),loc.end());
    for(auto x:loc){
        int ed_size = 0;
        if(z>=4)ed_size=rnd.next(1LL,z/3);
        z-=ed_size;
        for(int i=0;i<ed_size;i++){
            edges.push_back({x,n,1});
        }
    }
    if(z>0){
        loc.clear();
        if(test==14)loc.push_back(n-1);
        else loc.push_back(rnd.next(n-45,n-3));
        for(auto x:loc){
        int ed_size = z;
        z-=ed_size;
        for(int i=0;i<ed_size;i++){
            ll w = rnd.next(2,4);
            edges.push_back({x,n,w});
        }
    }

    }
    shuffle(edges.begin(),edges.end());
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
