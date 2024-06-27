#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,shelfCapacity;
vector<array<ll,2>>products;
void print(){
    cout<<shelfCapacity<<endl;
    cout<<n<<endl;
    cout<<2<<endl;
    for(auto i:products){
        cout<<i[0]<<" "<<i[1]<<endl;
    }

}
void writeTest(int test)
{
    products.clear();
    startTest(test);
    /*
        Generator Code
    */
   
   if(test==0){
    shelfCapacity = 8;
    n = 4;
    products = {{30,4},{50,5},{90,6},{100,7}};
    print();
   }
   if(test==1){
    shelfCapacity = 10;
    n = 5;
    products = {{50,3},{60,4},{70,6},{80,7},{30,2}};
    print();
   }
   if(test==3){
    n = 1;
    shelfCapacity = 1;
    products = {{1,1}};
    print();
    
   }
   if(test==2 || test == 4 || test == 5 || test == 6){
    n = rnd.next(75,80);
    shelfCapacity = rnd.next(140,150);
    
    if(test==2){
        n = rnd.next(5,6);
        shelfCapacity = rnd.next(15,20);
    }
    ll lim = rnd.next(10,13);
    if(test==2)lim = 4;
    int z = rnd.next(n/3,n/2);
    for(int i=0;i<z;i++){
        ll a = rnd.next(1LL,200LL);
        ll b = rnd.next(lim-3,lim);
        products.push_back({a,b});
    }
    for(int i=z;i<n;i++){
        ll a = rnd.next(100LL,300LL);
        ll b = rnd.next(lim+1,shelfCapacity);
        products.push_back({a,b});
    }
    shuffle(products.begin(),products.end());
    print();
   }
   if(test==7){
    n = 100;
    shelfCapacity = 500;
    
    ll lim = rnd.next(10,13);
    int z = rnd.next(1LL,n/2);
    for(int i=0;i<n;i++){
        ll a = 1e9;
        ll b = shelfCapacity;
        products.push_back({a,b});
    }
    shuffle(products.begin(),products.end());
    print();
   }
   if(test>=8 && test<=14){
    n = 100;
    shelfCapacity = rnd.next(498,500);
    
    ll lim = rnd.next(10,13);
    int z = rnd.next(n/3,n/2);
    ll P = 1e9;
    for(int i=0;i<z;i++){
        ll a = rnd.next(P/10,P/5);
        ll b = rnd.next(lim-3,lim);
        products.push_back({a,b});
    }
    for(int i=z;i<n;i++){
        ll a = rnd.next(P/4,P);
        ll b = rnd.next(60LL,shelfCapacity);
        products.push_back({a,b});
    }
    shuffle(products.begin(),products.end());
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
