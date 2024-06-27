#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,shelfCapacity,k;
vector<array<ll,3>>products;
void print(){
    cout<<shelfCapacity<<endl;
    cout<<k<<endl;
    cout<<n<<endl;
    cout<<3<<endl;
    for(auto i:products){
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
    }


}
int get_random(vector<int>& tags){
    return tags[rnd.next(0,(int)tags.size()-1)];

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
    products = {{1,30,4},{2,50,5},{1,90,6},{2,100,7}};
    k = 1;
    print();
   }
   if(test==1){
    shelfCapacity = 10;
    n = 4;
    products = {{1,50,3},{2,60,4},{1,40,2},{1,30,1}};
    k = 2;
    print();
   }
   if(test==3){
    n = 1;
    shelfCapacity = 1;
    products = {{1,1,1}};
    k = 1;
    print();
    
   }
   if(test==2 || test == 4 || test == 5 || test == 6){
    n = rnd.next(70,80);
    shelfCapacity = rnd.next(400,700);
    k = rnd.next(n/8,n/6);
    int uq = rnd.next(6,8);
    vector<int>tags;
    for(int i=0;i<uq;i++){
        tags.push_back(rnd.next(1e2,1e7));
    }
    if(test==2){
        n = 6;
        shelfCapacity = 55;
        k = 2;
        products = {{1,50,3},{2,60,4},{1,40,2},{1,30,1},{2,70,5},{1,80,6}};
        print();
        return;
    }
    
    
    int cur = shelfCapacity/n;
    cur+=rnd.next(3,4);
    
    ll price = rnd.next(1e8,1e9-100);
    
    products = vector<array<ll,3>>(n);
    for(int i=0;i<n;i++){
        products[i] = {get_random(tags),price+rnd.next(-10,10),cur + rnd.next(-2,2)};
    }
    print();
   }
   if(test==7){
    n = 200;
    shelfCapacity = 800;
    
    for(int i=0;i<n;i++){
        ll a = 1e9;
        ll b = shelfCapacity/n;
        products.push_back({a,a,b});
    }
    k = 200;
    
    shuffle(products.begin(),products.end());
    print();
   }
   if(test>=8 && test<=14){
    n = 200;
    shelfCapacity = 800;
    int cur = shelfCapacity/n;
    cur+=rnd.next(2,4);
    int uq = rnd.next(2,4);
    k = n/uq;
    vector<int>tags;
    for(int i=0;i<uq;i++){
        tags.push_back(rnd.next(1e2,1e7));
    }
    ll price = rnd.next(1e8,1e9-100);
    
    products = vector<array<ll,3>>(n);
    for(int i=0;i<n;i++){
        products[i] = {get_random(tags),price+rnd.next(-10,10),cur + rnd.next(-2,2)};
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
