#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getLocation' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. WEIGHTED_INTEGER_GRAPH cargo
 *  2. INTEGER C
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int getLocation(int cargo_nodes, vector<int> cargo_from, vector<int> cargo_to, vector<int> cargo_weight, int C) {
    map<int,int>Carry;
    for(int i=0;i<cargo_from.size();i++){
        Carry[cargo_from[i]]+=cargo_weight[i];
        Carry[cargo_to[i]]-=cargo_weight[i];
        //cout<<cargo_from[i]<<" "<<cargo_to[i]<<" "<<cargo_weight[i]<<endl;
    }
    for(auto x : Carry){
        C-=x.second;
        //cout<<x.first<<" "<<x.second<<endl;
        if(C<0){
            return x.first;
        }
    }
    return -1;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string cargo_nodes_edges_temp;
    getline(cin, cargo_nodes_edges_temp);

    vector<string> cargo_nodes_edges = split(rtrim(cargo_nodes_edges_temp));

    int cargo_nodes = stoi(cargo_nodes_edges[0]);
    int cargo_edges = stoi(cargo_nodes_edges[1]);

    vector<int> cargo_from(cargo_edges);
    vector<int> cargo_to(cargo_edges);
    vector<int> cargo_weight(cargo_edges);

    for (int i = 0; i < cargo_edges; i++) {
        string cargo_from_to_weight_temp;
        getline(cin, cargo_from_to_weight_temp);

        vector<string> cargo_from_to_weight = split(rtrim(cargo_from_to_weight_temp));

        int cargo_from_temp = stoi(cargo_from_to_weight[0]);
        int cargo_to_temp = stoi(cargo_from_to_weight[1]);
        int cargo_weight_temp = stoi(cargo_from_to_weight[2]);

        cargo_from[i] = cargo_from_temp;
        cargo_to[i] = cargo_to_temp;
        cargo_weight[i] = cargo_weight_temp;
    }

    string C_temp;
    getline(cin, C_temp);

    int C = stoi(ltrim(rtrim(C_temp)));

    int result = getLocation(cargo_nodes, cargo_from, cargo_to, cargo_weight, C);

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
