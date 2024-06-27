#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool is_valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

array<int, 2> find_start(const vector<string>& maze) {
    int n = maze.size();
    int m = maze[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'S') {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

array<int, 2> find_end(const vector<string>& maze) {
    int n = maze.size();
    int m = maze[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'E') {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int getMinimumTime(vector<string> maze) {
    array<int, 2> start = find_start(maze);
    array<int, 2> end = find_end(maze);
    int n = maze.size();
    int m = maze[0].size();

    map<array<int, 3>, int> dist;
    dist[{start[0], start[1], 0}] = 0;

    priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;
    pq.push({0, start[0], start[1], 0}); // {distance, x, y, doubleSpeedDistance}

    int ans = numeric_limits<int>::max();

    while (!pq.empty()) {
        array<int, 4> node = pq.top();
        pq.pop();

        int distance = node[0], x = node[1], y = node[2], doubleSpeedDistance = node[3];

        if (x == end[0] && y == end[1]) {
            ans = min(ans, distance);
            
        }

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (is_valid(new_x, new_y, n, m) && maze[new_x][new_y] != 'W') {
                int newDistance = distance + 1;
                int newDoubleSpeedDistance = doubleSpeedDistance;

                if (newDoubleSpeedDistance == 0) newDistance++;
                else newDoubleSpeedDistance--;

                if (maze[new_x][new_y] == 'C') {
                    newDoubleSpeedDistance = 3;
                }

                if (dist.find({new_x, new_y, newDoubleSpeedDistance}) == dist.end() || dist[{new_x, new_y, newDoubleSpeedDistance}] > newDistance) {
                    dist[{new_x, new_y, newDoubleSpeedDistance}] = newDistance;
                    pq.push({newDistance, new_x, new_y, newDoubleSpeedDistance});
                }
            }
        }
    }

    return ans == numeric_limits<int>::max() ? -1 : ans;
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

    int result = getMinimumTime(maze);

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
