#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int n;
vector<vector<int>>employeePerformance;
void printTest() {
    cout << n << endl;
    for(int i=0;i<n;i++){
        cout << employeePerformance[i][0] << " " << employeePerformance[i][1] << " " << employeePerformance[i][2] << " " << employeePerformance[i][3] << " " << employeePerformance[i][4] << endl;
    }

    
}

void writeTest(int test) {
    startTest(test);
    employeePerformance.clear();
    if(test == 0){
        n = 4;
       employeePerformance = {{1 ,95, 9, 5, 98},
       {2, 75, 8, 2, 78},
       {3, 68, 7, 1, 70},
       {4, 85, 8, 4, 90},
       {5, 45, 5, 0, 40}};
        printTest();
    }
    if(test == 1){
        n = 4;
        employeePerformance = {{1 ,60, 6, 1, 65},
       {2, 80, 8, 3, 85},
       {3, 90, 9, 5, 95},
       {4, 70, 7, 2, 75},
       {5, 95, 9, 5, 98}};
        printTest();

    }
    if(test >= 2){
        if(test<=5)n = rnd.next(10,20);
        if(test>=6 && test<=8)n = rnd.next(100,200);
        if(test>=9 && test<=14)n = rnd.next(10000,20000);
        for(int i=0;i<n;i++){
            employeePerformance.push_back({i+1,rnd.next(20,100),rnd.next(1,10),rnd.next(1,5),rnd.next(4,100)});
        }
        shuffle(employeePerformance.begin(),employeePerformance.end());
        printTest();
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int tests = atoi(argv[1]);
    for (int i = 0; i < tests; i++)
        writeTest(i);
    return 0;
}
