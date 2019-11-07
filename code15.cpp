#include <bits/stdc++.h>
using namespace std;
void show(vector<int> nums){
    cout<<"[ ";
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<"]"<<endl;
}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        show(nums);
        sort(nums.begin(),nums.end());
        show(nums);
    }
};

int  main(){
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);
    Solution s;
    s.threeSum(nums);
    cout<<"EE"<<endl;
    return 0;


}