#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,rate;
vector<ll>a;
void print(){
    cout<<n<<endl;
    for(auto x:a)cout<<x<<endl;
    cout<<rate;

}
void writeTest(int test)
{
    startTest(test);
    /*
        Generator Code
    */
   a.clear();
   if(test>=0 && test<=5){
    n = 2e5;
    rate = rnd.next(5,12);
    int z = rnd.next(100,150);
    int x = rnd.next(1e5,1e7);
    for(int i=0;i<z;i++){
        a.push_back(rnd.next(x,x+15));
    }
    int start = 1200;
    for(int i=z;i<n;i++){
        int l = start;
        int r = start+60;
        start+=60;
        a.push_back(rnd.next(l,r));
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
