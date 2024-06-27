#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long maximizeWorth(int shelfCapacity, vector<vector<int>>& products, vector<vector<int>>& offers) {
    int n = products.size();

    // Generate offer combinations
    vector<pair<int, int>> combined_items;
    vector<int>marked(n);
    for(auto i:offers){
        marked[i[0]] = 1;
        marked[i[1]] = 1;
        int price1 = products[i[0]][0];
        int volume1 = products[i[0]][1];
        int price2 = products[i[1]][0];
        int volume2 = products[i[1]][1];
        int combined_price = max(price1, price2);
        int combined_volume = volume1 + volume2;
        combined_items.push_back({combined_price, combined_volume});
    }
    for (int i = 0; i < n; ++i) {
        if (!marked[i])combined_items.push_back({products[i][0], products[i][1]});  // Add individual products
    }


    // DP array to store maximum worth at each capacity
    vector<long long> dp(shelfCapacity + 1, 0);

    // Process each item (product or offer)
    for (const auto& item : combined_items) {
        long long price = item.first;
        int volume = item.second;
        for (int cap = shelfCapacity; cap >= volume; --cap) {
            dp[cap] = max(dp[cap], dp[cap - volume] + price);
        }
    }

    return dp[shelfCapacity];
}

// Test case
int main() {
    int shelfCapacity;
    cin>>shelfCapacity;
    int n;
    cin>>n;
    int m ;
    cin>>m;
    vector<vector<int>> products(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>products[i][j];
        }
    }
    int k;
    cin>>k;
    cin>>m;
    vector<vector<int>> offers(k, vector<int>(2));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin>>offers[i][j];
        }
    }
    cout<<maximizeWorth(shelfCapacity, products, offers);

    return 0;
}
