#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int>a;
void print(){
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        if(i!=n-1)cout<<a[i]<<endl;
        else cout<<a[i];
    }

}
void writeTest(int test)
{
    startTest(test);
    /*
        Generator Code
    */
   a.clear();
   if(test==0){
    n = 6;
    a={5,6,5,7,5,5};
    print();
    
   }
   if(test==1){
    n = 2;
    a = {4,4};
    print();
    
   }
   if(test==2){
    n = 4;
    a={4,1,1,1};
    print();
   
   }
   if(test==3){
    n = 1;
    a={1};
    print();
    
   }
   if(test>=4 && test<=8){
    n = rnd.next(2000,3000);
    ll x = rnd.next(1e8,1e9-1000000);
    ll z = rnd.next(n/4,n/3);
    for(int i=0;i<z;i++){
        a.push_back(x+rnd.next(-1,1));
    }
    for(int i=z;i<n;i++){
        a.push_back(x+rnd.next(-1000,1000));
    }
    print();
    

  
   }
   if(test==9){
    n = 1e5;
    for(int i=0;i<n;i++){
        a.push_back((int)1e9);
    }
    print();
    
   }
   if(test>=10 && test<=12){
    n = rnd.next(1e5-300,1e5-100);
    ll x = rnd.next(1e8,1e9-100);
    for(int i=0;i<n;i++){
        a.push_back(x+rnd.next(-2,2));
    }
    print();
       

   }
   if(test>=13 && test<=14){
    n = 1e5;
    ll x = rnd.next(1e8,1e9-1000000);
    ll z = rnd.next(n/3,2*n/3);
    for(int i=0;i<z;i++){
        a.push_back(x+rnd.next(-50,50));
    }
    for(int i=z;i<n;i++){
        a.push_back(x+rnd.next(-10000,10000));
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
