#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'checkPath' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts STRING_ARRAY maze as parameter.
 */
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool check(int x,int y,int n,int m){
    return x>=0 && x<n && y>=0 && y<m;
}
array<int,2> findStart(vector<string> maze){
    int n = maze.size();
    int m = maze[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j] == 'S'){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}
bool checkPath(vector<string> maze) {
    int n = maze.size();
    int m = maze[0].size();
    queue<array<int,3>>q;
    array<int,2>start = findStart(maze);
    q.push({start[0],start[1],0});
    map<array<int,3>,bool>visited;
    visited[{start[0],start[1],0}] = true;
    while(!q.empty()){
        array<int,3>cur = q.front();
        q.pop();
        if(maze[cur[0]][cur[1]] == 'E'){
            return true;
        }
        for(int i=0;i<4;i++){
            int x = cur[0]+dx[i];
            int y = cur[1]+dy[i];
            int z = cur[2];
            if(!check(x,y,n,m) || maze[x][y]=='W')continue;
            if(maze[x][y] == 'T')z++;
            if(z>=2)continue;
            if(visited[{x,y,z}])continue;
            visited[{x,y,z}] = true;
            q.push({x,y,z});
        }

    }
    return false;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string maze_count_temp;
    getline(cin, maze_count_temp);

    int maze_count = stoi(ltrim(rtrim(maze_count_temp)));

    vector<string> maze(maze_count);

    for (int i = 0; i < maze_count; i++) {
        string maze_item;
        getline(cin, maze_item);

        maze[i] = maze_item;
    }

    bool result = checkPath(maze);

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
