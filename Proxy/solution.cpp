#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'checkRequest' function below.
 *
 * The function is expected to return a BOOLEAN_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY request
 *  2. INTEGER rate_limit
 */

vector<bool> checkRequest(vector<int> request, int rate_limit) {
    int n = request.size();
    map<int,vector<vector<int>>>mp;
    for(int i=0;i<n;i++){
        mp[request[i]/60].push_back({request[i],i});
    }
    vector<bool> ans(n,0);
    for(auto x:mp){
        sort(x.second.begin(),x.second.end());
        int sz = x.second.size();
        sz = min(sz,rate_limit);
        for(int i=0;i<sz;i++)ans[x.second[i][1]]=1;
    }
    return ans;

}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string request_count_temp;
    getline(cin, request_count_temp);

    int request_count = stoi(ltrim(rtrim(request_count_temp)));

    vector<int> request(request_count);

    for (int i = 0; i < request_count; i++) {
        string request_item_temp;
        getline(cin, request_item_temp);

        int request_item = stoi(ltrim(rtrim(request_item_temp)));

        request[i] = request_item;
    }

    string rate_limit_temp;
    getline(cin, rate_limit_temp);

    int rate_limit = stoi(ltrim(rtrim(rate_limit_temp)));

    vector<bool> result = checkRequest(request, rate_limit);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

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
