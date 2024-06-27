#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getLoanConsolidation' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY debtList
 */
typedef long long ll;
vector<vector<long>> getLoanConsolidation(int n, vector<vector<int>> debtList) {
    vector<ll> balance(n+1,0);
    for(auto x:debtList){
        balance[x[0]]+=x[2];
        balance[x[1]]-=x[2];
    }
    vector<array<ll,2>>excess,deficit;
    for(int i=1;i<=n;i++){
        if(balance[i]>0){
            excess.push_back({balance[i],i});
        }
        else if(balance[i]<0){
            deficit.push_back({-balance[i],i});
        }
    }
    vector<vector<long>>ans;
    int i=0,j=0;
    while(i<excess.size() && j<deficit.size()){
        ll x = min(excess[i][0],deficit[j][0]);
        ans.push_back({excess[i][1],deficit[j][1],x});
        excess[i][0]-=x;
        deficit[j][0]-=x;
        if(excess[i][0]==0)i++;
        if(deficit[j][0]==0)j++;
    }
    if(ans.size()==0)ans={{-1,-1,-1}};
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string debtList_rows_temp;
    getline(cin, debtList_rows_temp);

    int debtList_rows = stoi(ltrim(rtrim(debtList_rows_temp)));

    string debtList_columns_temp;
    getline(cin, debtList_columns_temp);

    int debtList_columns = stoi(ltrim(rtrim(debtList_columns_temp)));

    vector<vector<int>> debtList(debtList_rows);

    for (int i = 0; i < debtList_rows; i++) {
        debtList[i].resize(debtList_columns);

        string debtList_row_temp_temp;
        getline(cin, debtList_row_temp_temp);

        vector<string> debtList_row_temp = split(rtrim(debtList_row_temp_temp));

        for (int j = 0; j < debtList_columns; j++) {
            int debtList_row_item = stoi(debtList_row_temp[j]);

            debtList[i][j] = debtList_row_item;
        }
    }

    vector<vector<long>> result = getLoanConsolidation(n, debtList);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
