#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getMinimumDistance' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER depotX
 *  2. INTEGER depotY
 *  3. 2D_INTEGER_ARRAY customerLocations
 *  4. INTEGER k
 */
int inf = 1e9;
int n;
int memo[11][11][1<<10];
int dist(int i,int j,vector<vector<int>>&customerLocations){
    return abs(customerLocations[i][0]-customerLocations[j][0])+
    abs(customerLocations[i][1]-customerLocations[j][1]);
}
int dp(int i,int k,int mask,vector<vector<int>>&customerLocations){
    if(mask == ((1<<n) - 1))return dist(i,n,customerLocations);
    if(k == 0)return inf;
    if(memo[i][k][mask] != -1)return memo[i][k][mask];
    // assuming expedition of this vehicle ends here
    int ans = dist(i,n,customerLocations) + dp(n,k-1,mask,customerLocations);
    // assuming expedition of this vehicle continues
    for(int j=0;j<n;j++){
        if((mask & (1<<j)) == 0){
            ans = min(ans,dist(i,j,customerLocations) + dp(j,k,mask|(1<<j),customerLocations));
        }
    }
    return memo[i][k][mask] = ans;
}
int getMinimumDistance(int depotX, int depotY, vector<vector<int>> customerLocations, int k) {
    n = customerLocations.size();
    customerLocations.push_back({depotX,depotY});
    memset(memo,-1,sizeof(memo));
    return dp(n,k,0,customerLocations);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string depotX_temp;
    getline(cin, depotX_temp);

    int depotX = stoi(ltrim(rtrim(depotX_temp)));

    string depotY_temp;
    getline(cin, depotY_temp);

    int depotY = stoi(ltrim(rtrim(depotY_temp)));

    string customerLocations_rows_temp;
    getline(cin, customerLocations_rows_temp);

    int customerLocations_rows = stoi(ltrim(rtrim(customerLocations_rows_temp)));

    string customerLocations_columns_temp;
    getline(cin, customerLocations_columns_temp);

    int customerLocations_columns = stoi(ltrim(rtrim(customerLocations_columns_temp)));

    vector<vector<int>> customerLocations(customerLocations_rows);

    for (int i = 0; i < customerLocations_rows; i++) {
        customerLocations[i].resize(customerLocations_columns);

        string customerLocations_row_temp_temp;
        getline(cin, customerLocations_row_temp_temp);

        vector<string> customerLocations_row_temp = split(rtrim(customerLocations_row_temp_temp));

        for (int j = 0; j < customerLocations_columns; j++) {
            int customerLocations_row_item = stoi(customerLocations_row_temp[j]);

            customerLocations[i][j] = customerLocations_row_item;
        }
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    int result = getMinimumDistance(depotX, depotY, customerLocations, k);

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
