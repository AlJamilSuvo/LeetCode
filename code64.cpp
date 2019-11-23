#include <bits/stdc++.h>

using namespace std;


class Solution {
private:
    map<string,int> dp;
    int m,n;
    

public:
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size()-1;
        n=grid[0].size()-1;
        return findMinSum(grid,0,0);
    }
    int findMinSum(vector<vector<int>>& grid,int x,int y){
        if (x==m && y==n) return grid[x][y];
        string key=to_string(x)+','+to_string(y);
        if(dp[key]!=0) return dp[key];
        int right_sum=1e7;
        int down_sum=1e7;
        if(y<n) right_sum=findMinSum(grid,x,y+1);
        if(x<m) down_sum=findMinSum(grid,x+1,y);

        int min_sum=right_sum<down_sum ? right_sum : down_sum;
        min_sum+=grid[x][y];
        dp[key]=min_sum;
        return min_sum;


    }
};


int main(){
    vector<vector<int>> grd;
    int m,n;
    cin>>m>>n;
    for (int i=0;i<m;i++){
        vector<int> vct;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            vct.push_back(x);
        }
        grd.push_back(vct);
    }
    Solution s;
    cout<<s.minPathSum(grd)<<endl;

}