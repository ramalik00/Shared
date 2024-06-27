#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int n;
vector<string> correctAnswers;
vector<string> studentAnswers;
void printTest() {
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << correctAnswers[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << studentAnswers[i] << " ";
    }

    
}

void writeTest(int test) {
    startTest(test);
    if(test == 0){
        n = 4;
        correctAnswers = {"a", "b", "c", "d"};
        studentAnswers = {"a", "b", "c", "d"};
        printTest();
    }
    if(test == 1){
        n = 4;
        correctAnswers = {"a", "a", "b", "b"};
        studentAnswers = {"b", "c", "a", "d"};
        printTest();

    }
    if(test >= 2){
        if(test<=5)n = rnd.next(10,20);
        if(test>=6 && test<=8)n = rnd.next(100,200);
        if(test>=9 && test<=14)n = rnd.next(10000,20000);
        for(int i=0;i<n;i++){
            int p = rnd.next(1,2);
            char c = 'a' + rnd.next(0,25);
            string s = "";
            s+=c;
            correctAnswers.push_back(s);
            if(p == 1)studentAnswers.push_back(s);
            else{
                char c = 'a' + rnd.next(0,25);
                string s = "";
                s+=c;
                studentAnswers.push_back(s);
            }
        }
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
