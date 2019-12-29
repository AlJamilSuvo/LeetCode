#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk_index;
        stack<int> stk_height;
        heights.push_back(0);
        int max_area=-1;
        for(int i=0;i<heights.size();i++){
            int last_index=i;
            while(!stk_height.empty() && stk_height.top()>heights[i]){
                int h=stk_height.top();
                int w=i-stk_index.top();
                int area=h*w;
                if(area>max_area) max_area=area;
                last_index=stk_index.top();
                stk_height.pop();
                stk_index.pop();
            }
            stk_height.push(heights[i]);
            stk_index.push(last_index);
        }
        if(max_area==-1) max_area=0;
        return max_area;

    }
};



int main(){
    vector<int> vals;
    vals.push_back(0);
    vals.push_back(0);
    vals.push_back(0);
    vals.push_back(1);
    vals.push_back(0);
    vals.push_back(0);
    vals.push_back(0);
    Solution sol;
    cout<<sol.largestRectangleArea(vals)<<endl;


}
