
#include <bits/stdc++.h>
using namespace std;

long maximizeWorth(int shelfCapacity,int k, vector<vector<int>>& products) {
    int n = products.size();
    map<int,vector<vector<int>> >productCatalog;
    for(auto product:products){
        productCatalog[product[0]].push_back({product[1],product[2]});
    }
    vector<vector<vector<long>>>prevDP;
    long ans = 0;
    for(auto &productVector:productCatalog){
        vector<vector<vector<long>>>dp(productVector.second.size()+1,
        vector<vector<long>>(shelfCapacity+1,vector<long>(k+1,0)));
        vector<long>maxValues(shelfCapacity+1,0);
        if(!prevDP.empty()){
        for(int j=1;j<=shelfCapacity;j++){
            for(int l=0;l<=k;l++){
             maxValues[j] = prevDP.back()[j][k];
            }
        }
        }
        for(int j=1;j<=shelfCapacity;j++){
            for(int l = 0;l<=k;l++){
                dp[0][j][l] = maxValues[j];
            }
        }
        for(int i=1;i<=productVector.second.size();i++){
            long price = productVector.second[i-1][0];
            long volume = productVector.second[i-1][1];
            for(int j=1;j<=shelfCapacity;j++){
                for(int l=1;l<=k;l++){
                    dp[i][j][l]=dp[i-1][j][l];
                    if(j>=volume){
                        dp[i][j][l]=max(dp[i][j][l],dp[i-1][j-volume][l-1]+price);
                    }
                    ans = max(ans,dp[i][j][l]);
                }
            }
        }
        prevDP = dp;
    }
    return ans;
    
}

// Test case
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int shelfCapacity;
    cin>>shelfCapacity;
    int k;
    cin>>k;
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
    
    cout<<maximizeWorth(shelfCapacity,k, products);

    return 0;
}
