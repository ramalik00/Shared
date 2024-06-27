#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMinDevTime' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY feature_dev_time
 *  2. INTEGER_ARRAY feature_type
 *  3. INTEGER max_dev_time
 */

int getMinDevTime(vector<int> feature_dev_time, vector<int> feature_type, int max_dev_time) {
    int n = feature_dev_time.size();
    map<int,vector<int>>featureMap;
    for(int i=0;i<n;i++){
        featureMap[feature_type[i]].push_back(feature_dev_time[i]);
    }
    int ans = 0;
    for(auto & [key,list] : featureMap){
        sort(list.begin(),list.end());
        int nx = list.size();
        int l=0,r = nx-1;
        ans+=nx;
        while(l<r){
            if(list[l]+list[r]<=max_dev_time){
                ans--;
                l++;
            }
            r--;
        }
        
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string feature_dev_time_count_temp;
    getline(cin, feature_dev_time_count_temp);

    int feature_dev_time_count = stoi(ltrim(rtrim(feature_dev_time_count_temp)));

    vector<int> feature_dev_time(feature_dev_time_count);

    for (int i = 0; i < feature_dev_time_count; i++) {
        string feature_dev_time_item_temp;
        getline(cin, feature_dev_time_item_temp);

        int feature_dev_time_item = stoi(ltrim(rtrim(feature_dev_time_item_temp)));

        feature_dev_time[i] = feature_dev_time_item;
    }

    string feature_type_count_temp;
    getline(cin, feature_type_count_temp);

    int feature_type_count = stoi(ltrim(rtrim(feature_type_count_temp)));

    vector<int> feature_type(feature_type_count);

    for (int i = 0; i < feature_type_count; i++) {
        string feature_type_item_temp;
        getline(cin, feature_type_item_temp);

        int feature_type_item = stoi(ltrim(rtrim(feature_type_item_temp)));

        feature_type[i] = feature_type_item;
    }

    string max_dev_time_temp;
    getline(cin, max_dev_time_temp);

    int max_dev_time = stoi(ltrim(rtrim(max_dev_time_temp)));

    int result = getMinDevTime(feature_dev_time, feature_type, max_dev_time);

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
