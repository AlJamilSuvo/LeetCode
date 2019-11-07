#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int,int> seen;
        map<int,int> index;
        for(int i=0;i<nums[0];i++){
            if(seen[target-nums[i]]==1){
                result.push_back(index[target-nums[i]]);
                result.push_back(i);
                cout<<i;
                return result;
            }
            seen[nums[i]]=1;
            index[nums[i]]=i;

        }
    }
};

int main(){
    Solution s;
    vector<int> input;
    input.push_back(3);
    input.push_back(3);
    input.push_back(2);
    s.twoSum(input,6);
}