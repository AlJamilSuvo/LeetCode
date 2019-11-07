#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> x,y;
        if(nums1.size()<=nums2.size()){
            x=nums1;
            y=nums2;
        }
        else{
            x=nums2;
            y=nums1;
        }
     
        int lenX=x.size();
        int lenY=y.size();
        int leftX,rightX,midX,midY,xl,xr,yl,yr,flag=-2;
        leftX=0;
        rightX=lenX;

        do{
            if(flag==1){
                leftX=midX+1;
            }else if(flag==-1){
                rightX=midX-1;
            }
            midX=(leftX+rightX)/2;
            midY=(lenX+lenY+1)/2-midX;
            xl=midX>0 ? nums1[midX] : -100000;
            xr=midX<lenX ? nums1[midX+1] : 100000;
            yl=midY>0 ? nums2[midY] : -100000;
            yr=midY<lenY ? nums2[midY+1] : 100000;

            cout<<xl<<" "<<xr<<endl;
            cout<<yl<<" "<<yr<<endl;

            if(xl<=yr && xr>=yl) flag=0;
            else if(xl>yr) flag=-1;
            else if(xr<yl) flag=1;
        }while(flag!=0);

        if((lenX+lenY)%2!=0){
            return max(xl,yl);
        }
        else return (double)(max(xl,yl)+min(xr,yr))/2.0;



    }


};

int main(){
  
    Solution s;
    vector<int> num1;
    vector<int> num2;
    num1.push_back(1);
    num1.push_back(3);
    num2.push_back(4);
    cout<<s.findMedianSortedArrays(num1,num2)<<endl;

}
