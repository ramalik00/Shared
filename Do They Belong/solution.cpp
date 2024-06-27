#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'pointsBelong' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER y1
 *  3. INTEGER x2
 *  4. INTEGER y2
 *  5. INTEGER x3
 *  6. INTEGER y3
 *  7. INTEGER xp
 *  8. INTEGER yp
 *  9. INTEGER xq
 *  10. INTEGER yq
 */
bool valid_triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    double ab = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    double bc = std::sqrt(std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2));
    double ac = std::sqrt(std::pow(x3 - x1, 2) + std::pow(y3 - y1, 2));
    return ab + bc > ac && bc + ac > ab && ab + ac > bc;
}

bool point_in_triangle(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y) {
    double area = std::abs((x1 * (y2-y3) + x2 * (y3-y1) + x3 * (y1-y2)) / 2);
    double area1 = std::abs((x1 * (y2-y) + x2 * (y-y1) + x * (y1-y2)) / 2);
    double area2 = std::abs((x1 * (y-y3) + x * (y3-y1) + x3 * (y1-y)) / 2);
    double area3 = std::abs((x * (y2-y3) + x2 * (y3-y) + x3 * (y-y2)) / 2);
    return area == area1 + area2 + area3;
}



int pointsBelong(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp, int xq, int yq) {
    if (!valid_triangle(x1, y1, x2, y2, x3, y3)) {
        return 0;
    }

    bool p_in_triangle = point_in_triangle(x1, y1, x2, y2, x3, y3, xp, yp);
    bool q_in_triangle = point_in_triangle(x1, y1, x2, y2, x3, y3, xq, yq);
    
    if (p_in_triangle && q_in_triangle) {
        return 3;
    } else if (p_in_triangle) {
        return 1;
    } else if (q_in_triangle) {
        return 2;
    } else {
        return 4;
    }
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string x1_temp;
    getline(cin, x1_temp);

    int x1 = stoi(ltrim(rtrim(x1_temp)));

    string y1_temp;
    getline(cin, y1_temp);

    int y1 = stoi(ltrim(rtrim(y1_temp)));

    string x2_temp;
    getline(cin, x2_temp);

    int x2 = stoi(ltrim(rtrim(x2_temp)));

    string y2_temp;
    getline(cin, y2_temp);

    int y2 = stoi(ltrim(rtrim(y2_temp)));

    string x3_temp;
    getline(cin, x3_temp);

    int x3 = stoi(ltrim(rtrim(x3_temp)));

    string y3_temp;
    getline(cin, y3_temp);

    int y3 = stoi(ltrim(rtrim(y3_temp)));

    string xp_temp;
    getline(cin, xp_temp);

    int xp = stoi(ltrim(rtrim(xp_temp)));

    string yp_temp;
    getline(cin, yp_temp);

    int yp = stoi(ltrim(rtrim(yp_temp)));

    string xq_temp;
    getline(cin, xq_temp);

    int xq = stoi(ltrim(rtrim(xq_temp)));

    string yq_temp;
    getline(cin, yq_temp);

    int yq = stoi(ltrim(rtrim(yq_temp)));

    int result = pointsBelong(x1, y1, x2, y2, x3, y3, xp, yp, xq, yq);

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
