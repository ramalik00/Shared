#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getMaxTotalGrades' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY grades as parameter.
 */

int dp[2001][2001];
vector<int> getMaxTotalGrades(vector<vector<int>> grades) {
    int n = grades.size();
    int m = grades[0].size();
    for(int i=0; i<n; i++){
        dp[i][0] = grades[i][0];

        for(int j=1; j<m; j++){
            int max_grade_without_consecutive = (j >= 2) ? dp[i][j - 2] : 0;
            dp[i][j] = max(dp[i][j - 1], max_grade_without_consecutive + grades[i][j]);
        }
    }

    vector<int> result;
    for(int i=0; i<n; i++){
        result.push_back(dp[i][m - 1]);
    }

    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grades_rows_temp;
    getline(cin, grades_rows_temp);

    int grades_rows = stoi(ltrim(rtrim(grades_rows_temp)));

    string grades_columns_temp;
    getline(cin, grades_columns_temp);

    int grades_columns = stoi(ltrim(rtrim(grades_columns_temp)));

    vector<vector<int>> grades(grades_rows);

    for (int i = 0; i < grades_rows; i++) {
        grades[i].resize(grades_columns);

        string grades_row_temp_temp;
        getline(cin, grades_row_temp_temp);

        vector<string> grades_row_temp = split(rtrim(grades_row_temp_temp));

        for (int j = 0; j < grades_columns; j++) {
            int grades_row_item = stoi(grades_row_temp[j]);

            grades[i][j] = grades_row_item;
        }
    }

    vector<int> result = getMaxTotalGrades(grades);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

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
