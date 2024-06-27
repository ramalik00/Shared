#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll x1,x2,x3,Y1,y2,y3,xq,xp,yp,yq;
void print(){
    cout<<x1<<endl;
    cout<<Y1<<endl;
    cout<<x2<<endl;
    cout<<y2<<endl;
    cout<<x3<<endl;
    cout<<y3<<endl;
    cout<<xp<<endl;
    cout<<yp<<endl;
    cout<<xq<<endl;
    cout<<yq;
}
void writeTest(int test)
{
    startTest(test);
    /*
        Generator Code
    */
   x1 = 0;
   Y1 = 0;
   x2 = 1000;
    y2 = 0;
    x3 = 0;
    y3 = 1000;
    if(test>=0 && test<=7){
        int c = rnd.next(-1000,-670);
        vector<array<int,2>> v1,v2;
        for(int i=0;i<=1000;i++){
            for(int j=0;j<=1000;j++){
                if(i+j>1000){
                    v1.push_back({i,j});
                }
                else{
                    v2.push_back({i,j});
                }
            }
        }
        shuffle(v1.begin(),v1.end());
        shuffle(v2.begin(),v2.end());
        xp = v1[0][0];
        yp = v1[0][1];
        xq = v2[0][0];
        yq = v2[0][1];
        x1-=c;
        x2-=c;
        x3-=c;
        xp-=c;
        xq-=c;
        Y1-=c;
        y2-=c;
        y3-=c;
        yp-=c;
        yq-=c;
        if(test%2){
            swap(xp,xq);
            swap(yp,yq);
        }
        print();
    }
    if(test>=8 && test<=12){
        int c = rnd.next(-1000,-670);
        vector<array<int,2>> v1,v2;
        for(int i=0;i<=1000;i++){
            for(int j=0;j<=1000;j++){
                if(i+j>1000){
                    v1.push_back({i,j});
                }
                else{
                    v2.push_back({i,j});
                }
            }
        }
        shuffle(v1.begin(),v1.end());
        shuffle(v2.begin(),v2.end());
        xp = v1[0][0];
        yp = v1[0][1];
        xq = v1[1][0];
        yq = v1[1][1];
        x1-=c;
        x2-=c;
        x3-=c;
        xp-=c;
        xq-=c;
        Y1-=c;
        y2-=c;
        y3-=c;
        yp-=c;
        yq-=c;
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
