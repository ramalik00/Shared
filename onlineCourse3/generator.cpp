#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,numDays,numHours;
vector<vector<ll>>assignments;
void print(){
    cout<<n<<endl;
    cout<<3<<endl;
    for(auto x:assignments){
        cout<<x[0]<<" "<<x[2]<<" "<<x[3]<<endl;
    }
    cout<<numDays<<endl;
    cout<<numHours;
}
vector<int> split_score(int score){
    int X = score/2;
    int Y = X-rnd.next(1,20);
    return {Y,score-Y};

}
void writeTest(int test)
{
    startTest(test);
    /*
        Generator Code
    */

   assignments.clear();
   if(test == 0){
    n = 4;
    assignments = {{2,30,20,4},{1,15,20,3},{1,10,25,4},{1,3,60,5}};
    numDays = 3;
    numHours = 6;
    print();
   }
   if(test == 1){
    n = 2;
    assignments = {{1,15,60,5},{1,20,50,3}};
    numDays = 2;
    numHours = 6;
    print();
   }
   if(test == 2){
    n = 5;
    numDays = 3;
    numHours = 12;
    for(int i=0;i<n;i++){
        vector<ll>temp;
        temp = {rnd.next(1LL,numDays),rnd.next(10,20),rnd.next(30,50),rnd.next(1LL,numHours/2)};
        assignments.push_back(temp);
    }
    print();
   }
   if(test==3){
    n = 1;
    numDays = 1;
    numHours = 1;
    assignments = {{1,1,1,1}};
    print();
   }
   if(test>=4 && test<=5){
    n = 60;
    numDays = rnd.next(20,22);
    numHours = 2*rnd.next(3,6);
    for(int i=0;i<n/4;i++){
        vector<ll>temp1,temp2,temp3,temp4;
        int score = 2*rnd.next(700,900);
        vector<int>split1 = split_score(score);
        vector<int>split2 = split_score(score);
        int X = rnd.next(700,800);
        vector<int>pen1={X+rnd.next(0,5),X+rnd.next(0,5)};
        vector<int>pen2={X-rnd.next(0,5),X-rnd.next(0,5)};
        temp1 = {i+1,pen1[0],split1[0],numHours/2};
        temp2 = {i+1,pen1[1],split1[1],numHours/2};
        temp3 = {i+1,pen2[0],split2[0],numHours/2 - 1};
        temp4 = {i+1,pen2[1],split2[1],numHours/2 + 1};
        assignments.push_back(temp1);
        assignments.push_back(temp2);
        assignments.push_back(temp3);
        assignments.push_back(temp4);
    }
    shuffle(assignments.begin(),assignments.end());
    print();

   }
   if(test>=6 && test<= 8){
    n = 300;
    numDays = rnd.next(n/3,n/2);
    numHours = rnd.next(4,12);
    for(int i=0;i<n;i++){
        vector<ll>temp;
        temp = {rnd.next(numDays/2,numDays),rnd.next(400,700),rnd.next(900,1000),rnd.next(1LL,numHours)};
        assignments.push_back(temp);
    }
    print();
   }
   if(test==9){
    n = 1000;
    numDays = 1000;
    numHours = 12;
    for(int i=0;i<n;i++){
        vector<ll>temp;
        temp.push_back(numDays);
        temp.push_back(1000);
        temp.push_back(1000);
        temp.push_back(numHours);
        assignments.push_back(temp);
    }
    print();

   }
   if(test>=10 && test<=12){
    n = 1000;
    numDays = rnd.next(n/3,n/2);
    numHours = 2*rnd.next(3,6);
    for(int i=0;i<n/4;i++){
        vector<ll>temp1,temp2,temp3,temp4;
        int score = 2*rnd.next(700,900);
        vector<int>split1 = split_score(score);
        vector<int>split2 = split_score(score);
        int X = rnd.next(700,800);
        vector<int>pen1={X+rnd.next(0,5),X+rnd.next(0,5)};
        vector<int>pen2={X-rnd.next(0,5),X-rnd.next(0,5)};
        temp1 = {i+1,pen1[0],split1[0],numHours/2};
        temp2 = {i+1,pen1[1],split1[1],numHours/2};
        temp3 = {i+1,pen2[0],split2[0],numHours/2 - 1};
        temp4 = {i+1,pen2[1],split2[1],numHours/2 + 1};
        assignments.push_back(temp1);
        assignments.push_back(temp2);
        assignments.push_back(temp3);
        assignments.push_back(temp4);
    }
    shuffle(assignments.begin(),assignments.end());
    print();
   }
   if(test>=13 && test<=14){
    n = 1000;
    numDays = rnd.next(n/3,n/2);
    numHours = rnd.next(7,12);
    for(int i=0;i<n;i++){
        vector<ll>temp;
        temp = {rnd.next(numDays/2,numDays),rnd.next(400,700),rnd.next(900,1000),rnd.next(1LL,numHours-2)};
        assignments.push_back(temp);
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
