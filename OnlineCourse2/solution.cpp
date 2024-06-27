#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

typedef long long ll;
int getMaxBatches(vector<int>& course_duration) {
    int n = course_duration.size();
    sort(course_duration.begin(), course_duration.end());
    ll prevSum = 0, curSum = 0;
    ll prevCount = 0, curCount = 0, res = 0;
    ll unique_elements = 0;
    for(int i=0;i<n;i++){
        if(i==0 || course_duration[i] != course_duration[i-1]){
            unique_elements++;
        }
    }
    for(int i=0;i<n;i++){
        curSum += course_duration[i];
        curCount++;
        if(curCount >= prevCount && curSum > prevSum){
            res++;
            prevSum = curSum; prevCount = curCount;
            curSum = curCount = 0;
        }
    }
    res = max(res, unique_elements);
    return res;
}
int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string course_duration_count_temp;
    getline(cin, course_duration_count_temp);

    int course_duration_count = stoi(ltrim(rtrim(course_duration_count_temp)));

    vector<int> course_duration(course_duration_count);

    for (int i = 0; i < course_duration_count; i++) {
        string course_duration_item_temp;
        getline(cin, course_duration_item_temp);

        int course_duration_item = stoi(ltrim(rtrim(course_duration_item_temp)));

        course_duration[i] = course_duration_item;
    }

    int result = getMaxBatches(course_duration);

    cout << result << "\n";

    //fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
