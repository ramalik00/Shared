#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getResponseTimeSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY responseTime as parameter.
 */
const int MOD = 1e9 + 7;

int getResponseTimeSum(vector<int>& responseTime) {
    int n = responseTime.size();
    vector<int> left_boundaries(n, -1), right_boundaries(n, n);
    stack<int> s;
    
    // Finding the left boundaries
    for (int i = 0; i < n; i++) {
        while (!s.empty() && responseTime[s.top()] <= responseTime[i])
            s.pop();
        
        if (!s.empty())
            left_boundaries[i] = s.top();
        
        s.push(i);
    }

    // Finding the right boundaries
    while (!s.empty())
        s.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && responseTime[s.top()] < responseTime[i])
            s.pop();
        
        if (!s.empty())
            right_boundaries[i] = s.top();
        
        s.push(i);
    }

    // Calculating the sum of response times
    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long Li = left_boundaries[i];
        long long Ri = right_boundaries[i];
        long long x = ((Ri - i) * (i - Li) * (Ri - Li)) / 2;
        x%=MOD;
        result += (x * responseTime[i])%MOD;
        result %= MOD;
    }
    
    return result;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string responseTime_count_temp;
    getline(cin, responseTime_count_temp);

    int responseTime_count = stoi(ltrim(rtrim(responseTime_count_temp)));

    vector<int> responseTime(responseTime_count);

    for (int i = 0; i < responseTime_count; i++) {
        string responseTime_item_temp;
        getline(cin, responseTime_item_temp);

        int responseTime_item = stoi(ltrim(rtrim(responseTime_item_temp)));

        responseTime[i] = responseTime_item;
    }

    int result = getResponseTimeSum(responseTime);

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
