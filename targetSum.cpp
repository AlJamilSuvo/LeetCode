#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> getTargetSum(vector<int> numbers,int target){
    int lo=0;
    int hi=numbers.size()-1;
    vector<pair<int,int>> results;
    while (lo<hi)
    {
        int sum=numbers[lo]+numbers[hi];
        if(sum==target){
            pair<int,int> res;
            res.first=numbers[lo];
            res.second=numbers[hi];
            results.push_back(res);
            while(numbers[lo]==res.first) lo++;
            while(numbers[hi]==res.second) hi--;
        }
        else if(sum>target) hi--;
        else lo++;
    }
    return results;
}

int main(){
    int n;
    vector<int> numbers;
    int target;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        numbers.push_back(x);
    }
    cin>>target;
    vector<pair<int,int>> results=getTargetSum(numbers,target);
    for(int i=0;i<results.size();i++){
        cout<<results[i].first<<","<<results[i].second<<endl;
    }
    return 0;
}