#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,shelfCapacity,k;
vector<array<ll,2>>products;
vector<array<ll,2>>offers;
void print(){
    cout<<shelfCapacity<<endl;
    cout<<n<<endl;
    cout<<2<<endl;
    for(auto i:products){
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    cout<<k<<endl;
    cout<<2<<endl;
    for(auto i:offers){
        cout<<i[0]<<" "<<i[1]<<endl;
    }


}
void writeTest(int test)
{
    products.clear();
    offers.clear();
    startTest(test);
    /*
        Generator Code
    */
   
   if(test==0){
    shelfCapacity = 12;
    n = 6;
    products = {{100,5},{90,4},{60,6},{80,3},{70,2},{40,1}};
    k = 3;
    offers = {{0,1},{2,3},{4,5}};
    print();
   }
   if(test==1){
    shelfCapacity = 10;
    n = 4;
    products = {{50,3},{60,4},{40,2},{30,1}};
    k = 1;
    offers = {{0,1}};
    print();
   }
   if(test==3){
    n = 2;
    shelfCapacity = 1;
    products = {{1,1},{1,1}};
    k = 1;
    offers = {{0,1}};
    print();
    
   }
   if(test==2 || test == 4 || test == 5 || test == 6){
    n = rnd.next(100,200);
    shelfCapacity = rnd.next(1000-2,2000);
    k = rnd.next(n/3,n/2 - 5);
    if(test==2){
        n = 6;
        shelfCapacity = 55;
        k = 2;
    }
    
    int cur = shelfCapacity/n;
    cur+=rnd.next(3,4);
    
    vector<int>indices;
    for(int i=0;i<n;i++){
        indices.push_back(i);
    }
    ll price = rnd.next(1e8,1e9-100);
    shuffle(indices.begin(),indices.end());
    products = vector<array<ll,2>>(n);
    for(int i=0;i<k;i+=2){
        offers.push_back({indices[i],indices[i+1]});
        products[indices[i]] = {price+rnd.next(-10,10),cur/2 + rnd.next(-2,2)};
        products[indices[i+1]] = {price+rnd.next(-10,10),cur/2 + rnd.next(-2,2)};
    }
    for(int i=k;i<n;i++){
        products[indices[i]] = {price+rnd.next(-10,10),cur + rnd.next(-2,2)};
    }
    shuffle(offers.begin(),offers.end());
    print();
   }
   if(test==7){
    n = 1000;
    shelfCapacity = 5000;
    
    for(int i=0;i<n;i++){
        ll a = 1e9;
        ll b = rnd.next(1LL,shelfCapacity);
        products.push_back({a,b});
    }
    k = 500;
    for(int i=0;i<n;i+=2){
        offers.push_back({i,i+1});
    }
    shuffle(products.begin(),products.end());
    shuffle(offers.begin(),offers.end());
    print();
   }
   if(test>=8 && test<=14){
    n = 1000;
    shelfCapacity = rnd.next(5000-2,5000);
    int cur = shelfCapacity/n;
    cur+=rnd.next(3,4);
    k = rnd.next(n/5,n/4);
    vector<int>indices;
    for(int i=0;i<n;i++){
        indices.push_back(i);
    }
    ll price = rnd.next(1e8,1e9-100);
    shuffle(indices.begin(),indices.end());
    products = vector<array<ll,2>>(n);
    for(int i=0;i<k;i+=2){
        offers.push_back({indices[i],indices[i+1]});
        products[indices[i]] = {price+rnd.next(-10,10),cur/2 + rnd.next(-2,2)};
        products[indices[i+1]] = {price+rnd.next(-10,10),cur/2 + rnd.next(-2,2)};
    }
    for(int i=k;i<n;i++){
        products[indices[i]] = {price+rnd.next(-10,10),cur + rnd.next(-2,2)};
    }
    shuffle(offers.begin(),offers.end());
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
