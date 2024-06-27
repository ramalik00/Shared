#include <bits/stdc++.h>

using namespace std;

// string ltrim(const string &);
// string rtrim(const string &);
// vector<string> split(const string &);


/*
 * Complete the 'getMaxScore' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY assignments
 *  2. INTEGER numDays
 *  3. INTEGER numHours
 */

int f(int i,int day,int hour,vector<vector<vector<int>>> &dp,vector<vector<int>> &assignments,int numDays,int numHours){
    if(i>=assignments.size())return 0;
    if(day>numDays)return 0;
    if(dp[i][day][hour]!=-1)return dp[i][day][hour];
    int deadline = assignments[i][0];
    int score = assignments[i][1];
    int base_time = assignments[i][2];
    int ans = 0;
    ans = max(ans,f(i+1,day,hour,dp,assignments,numDays,numHours));
    if(day<=deadline && hour+base_time<=numHours){
        int new_day = day;
        int new_hour = hour+base_time;
        if(new_hour==numHours){
            new_day++;
            new_hour = 0;
        }
        ans = max(ans,f(i+1,new_day,new_hour,dp,assignments,numDays,numHours)+score);
    }
    int new_day = day;
    int new_hour = hour+1;
    if(new_hour==numHours){
        new_day++;
        new_hour = 0;
    }
    ans = max(ans,f(i,new_day,new_hour,dp,assignments,numDays,numHours));
    return dp[i][day][hour] = ans;
}
int getMaxScore(vector<vector<int>> assignments, int numDays, int numHours) {
    sort(assignments.begin(),assignments.end());
    vector<vector<vector<int>>>dp(assignments.size(),vector<vector<int>>(numDays+2,vector<int>(numHours+2,-1)));
    return f(0,1,0,dp,assignments,numDays,numHours);
}
// int getMaxScore(vector<vector<int>> assignments, int numDays, int numHours) {
//     sort(assignments.begin(),assignments.end());
//     int n = assignments.size();
//     vector<vector<vector<int>>>dp(n,vector<vector<int>>(numDays+2,vector<int>(numHours+2,0)));
//     for(int i=0;i<n;i++){
//         int deadline = assignments[i][0];
//         int score = assignments[i][1];
//         int base_time = assignments[i][2];
//         for(int day = 1;day<=numDays;day++){
//             for(int hour = 0;hour<=numHours;hour++){
//                 // do not complete the assignment
//                 if(i>0){
//                     dp[i][day][hour] = max(dp[i][day][hour],dp[i-1][day][hour]);
//                 }
               
//                 if(hour>0){
//                     dp[i][day][hour]=max(dp[i][day][hour],dp[i][day][hour-1]);
//                 }
//                 // try to complete on current day
                
//                 if(hour-base_time>=0 && day<=deadline){
//                     if(i==0){
//                         dp[i][day][hour] = score;
//                     }
//                     else{
//                         dp[i][day][hour] = max(dp[i][day][hour],dp[i-1][day][hour-base_time]+score);
//                     }
//                 }
                
//                 if(hour==numHours)dp[i][day+1][0]=dp[i][day][hour];
//             }
//         }
//     }

//     return dp[n-1][numDays][numHours];
// }
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<vector<int>>assignments(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>assignments[i][j];
        }
    
    }
    int numDays,numHours;
    cin>>numDays;
    cin>>numHours;
    cout<<getMaxScore(assignments,numDays,numHours)<<endl;
}
// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string assignments_rows_temp;
//     getline(cin, assignments_rows_temp);

//     int assignments_rows = stoi(ltrim(rtrim(assignments_rows_temp)));

//     string assignments_columns_temp;
//     getline(cin, assignments_columns_temp);

//     int assignments_columns = stoi(ltrim(rtrim(assignments_columns_temp)));

//     vector<vector<int>> assignments(assignments_rows);

//     for (int i = 0; i < assignments_rows; i++) {
//         assignments[i].resize(assignments_columns);

//         string assignments_row_temp_temp;
//         getline(cin, assignments_row_temp_temp);

//         vector<string> assignments_row_temp = split(rtrim(assignments_row_temp_temp));

//         for (int j = 0; j < assignments_columns; j++) {
//             int assignments_row_item = stoi(assignments_row_temp[j]);

//             assignments[i][j] = assignments_row_item;
//         }
//     }

//     string numDays_temp;
//     getline(cin, numDays_temp);

//     int numDays = stoi(ltrim(rtrim(numDays_temp)));

//     string numHours_temp;
//     getline(cin, numHours_temp);

//     int numHours = stoi(ltrim(rtrim(numHours_temp)));

//     int result = getMaxScore(assignments, numDays, numHours);

//     fout << result << "\n";

//     fout.close();

//     return 0;
// }

// string ltrim(const string &str) {
//     string s(str);

//     s.erase(
//         s.begin(),
//         find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//     );

//     return s;
// }

// string rtrim(const string &str) {
//     string s(str);

//     s.erase(
//         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//         s.end()
//     );

//     return s;
// }

// vector<string> split(const string &str) {
//     vector<string> tokens;

//     string::size_type start = 0;
//     string::size_type end = 0;

//     while ((end = str.find(" ", start)) != string::npos) {
//         tokens.push_back(str.substr(start, end - start));

//         start = end + 1;
//     }

//     tokens.push_back(str.substr(start));

//     return tokens;
// }


