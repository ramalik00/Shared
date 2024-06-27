#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getMinimumTime' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY maze
 *  2. 2D_INTEGER_ARRAY portals
 */
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool is_valid(int x,int y,int n,int m){
    return x>=0 && x<n && y>=0 && y<m;
}
array<int,2>find_start(vector<string> maze){
    for(int i=0;i<maze.size();i++){
        for(int j=0;j<maze[i].size();j++){
            if(maze[i][j]=='S'){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}
array<int,2> find_end(vector<string> maze){
    for(int i=0;i<maze.size();i++){
        for(int j=0;j<maze[i].size();j++){
            if(maze[i][j]=='E'){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}


int getMinimumTime(vector<string> maze, vector<vector<int>> portals) {
    int n = maze.size();
    int m = maze[0].size();
    array<int,2> start = find_start(maze);
    array<int,2> end = find_end(maze);
    queue<array<int,2>>q;
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    q.push(start);
    dist[start[0]][start[1]] = 0;
    map<array<int,2>,vector<array<int,2>>>portal_map;
    for(auto x : portals){
        portal_map[{x[0],x[1]}].push_back({x[2],x[3]});
    }
    while(!q.empty()){
        array<int,2> curr = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x = curr[0] + dx[i];
            int y = curr[1] + dy[i];
            if(is_valid(x,y,n,m) && maze[x][y]!='W' && dist[x][y]>dist[curr[0]][curr[1]]+1){
                dist[x][y] = dist[curr[0]][curr[1]]+1;
                q.push({x,y});
            }
        }
        for(auto points : portal_map[curr]){
            if(maze[points[0]][points[1]]=='W'){
                continue;
            }
            if(dist[points[0]][points[1]]>dist[curr[0]][curr[1]]+1){
                dist[points[0]][points[1]] = dist[curr[0]][curr[1]]+1;
                q.push(points);
            }
        }
    }
    return dist[end[0]][end[1]]==1e9?-1:dist[end[0]][end[1]];

}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string maze_count_temp;
    getline(cin, maze_count_temp);

    int maze_count = stoi(ltrim(rtrim(maze_count_temp)));

    vector<string> maze(maze_count);

    for (int i = 0; i < maze_count; i++) {
        string maze_item;
        getline(cin, maze_item);

        maze[i] = maze_item;
    }

    string portals_rows_temp;
    getline(cin, portals_rows_temp);

    int portals_rows = stoi(ltrim(rtrim(portals_rows_temp)));

    string portals_columns_temp;
    getline(cin, portals_columns_temp);

    int portals_columns = stoi(ltrim(rtrim(portals_columns_temp)));

    vector<vector<int>> portals(portals_rows);

    for (int i = 0; i < portals_rows; i++) {
        portals[i].resize(portals_columns);

        string portals_row_temp_temp;
        getline(cin, portals_row_temp_temp);

        vector<string> portals_row_temp = split(rtrim(portals_row_temp_temp));

        for (int j = 0; j < portals_columns; j++) {
            int portals_row_item = stoi(portals_row_temp[j]);

            portals[i][j] = portals_row_item;
        }
    }

    int result = getMinimumTime(maze, portals);

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
