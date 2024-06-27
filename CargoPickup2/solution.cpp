#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMaximumWeight' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cargoWeights
 *  2. INTEGER truckCapacity1
 *  3. INTEGER truckCapacity2
 */

int getMaximumWeight(vector<int>& cargoWeights, int truckCapacity1, int truckCapacity2) {
    int n = cargoWeights.size();
    vector<vector<int>> dp(truckCapacity1 + 1, vector<int>(truckCapacity2 + 1, 0));
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        vector<vector<int>> curdp(truckCapacity1 + 1, vector<int>(truckCapacity2 + 1, 0));
        for (int c1 = 0; c1 <= truckCapacity1; ++c1) {
            for (int c2 = 0; c2 <= truckCapacity2; ++c2) {
                curdp[c1][c2] = dp[c1][c2]; // no cargo taken in this step

                if (c1 >= cargoWeights[i]) {
                    curdp[c1][c2] = max(curdp[c1][c2], dp[c1 - cargoWeights[i]][c2] + cargoWeights[i]);
                }

                if (c2 >= cargoWeights[i]) {
                    curdp[c1][c2] = max(curdp[c1][c2], dp[c1][c2 - cargoWeights[i]] + cargoWeights[i]);
                }
                ans = max(ans, curdp[c1][c2]);
            }
        }
        dp = curdp;
    }

    return ans;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string cargoWeights_count_temp;
    getline(cin, cargoWeights_count_temp);

    int cargoWeights_count = stoi(ltrim(rtrim(cargoWeights_count_temp)));

    vector<int> cargoWeights(cargoWeights_count);

    for (int i = 0; i < cargoWeights_count; i++) {
        string cargoWeights_item_temp;
        getline(cin, cargoWeights_item_temp);

        int cargoWeights_item = stoi(ltrim(rtrim(cargoWeights_item_temp)));

        cargoWeights[i] = cargoWeights_item;
    }

    string truckCapacity1_temp;
    getline(cin, truckCapacity1_temp);

    int truckCapacity1 = stoi(ltrim(rtrim(truckCapacity1_temp)));

    string truckCapacity2_temp;
    getline(cin, truckCapacity2_temp);

    int truckCapacity2 = stoi(ltrim(rtrim(truckCapacity2_temp)));

    int result = getMaximumWeight(cargoWeights, truckCapacity1, truckCapacity2);

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
