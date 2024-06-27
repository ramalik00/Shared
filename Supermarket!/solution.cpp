#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximizeWorth' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER shelfCapacity
 *  2. 2D_INTEGER_ARRAY products
 */
typedef long long ll;
ll dp[101][501][501];
ll solve(ll i, ll w1, ll w2,ll shelfCapacity,vector<vector<int>>&products){
    if(i==products.size())return 0;
    ll ans = 0;
    if(dp[i][w1][w2]!=-1)return dp[i][w1][w2];
    if(w1+products[i][1]<=shelfCapacity){
        ans = max(ans,products[i][0]+solve(i+1,w1+products[i][1],w2,shelfCapacity,products));
    }
    if(w2+products[i][1]<=shelfCapacity){
        ans = max(ans,products[i][0]+solve(i+1,w1,w2+products[i][1],shelfCapacity,products));
    }
    ans = max(ans,solve(i+1,w1,w2,shelfCapacity,products));
    return dp[i][w1][w2]=ans;
}
long maximizeWorth(int shelfCapacity, vector<vector<int>> products) {
    memset(dp,-1,sizeof(dp));
    return solve(0,0,0,shelfCapacity,products);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string shelfCapacity_temp;
    getline(cin, shelfCapacity_temp);

    int shelfCapacity = stoi(ltrim(rtrim(shelfCapacity_temp)));

    string products_rows_temp;
    getline(cin, products_rows_temp);

    int products_rows = stoi(ltrim(rtrim(products_rows_temp)));

    string products_columns_temp;
    getline(cin, products_columns_temp);

    int products_columns = stoi(ltrim(rtrim(products_columns_temp)));

    vector<vector<int>> products(products_rows);

    for (int i = 0; i < products_rows; i++) {
        products[i].resize(products_columns);

        string products_row_temp_temp;
        getline(cin, products_row_temp_temp);

        vector<string> products_row_temp = split(rtrim(products_row_temp_temp));

        for (int j = 0; j < products_columns; j++) {
            int products_row_item = stoi(products_row_temp[j]);

            products[i][j] = products_row_item;
        }
    }

    long result = maximizeWorth(shelfCapacity, products);

    fout << result << "\n";

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
