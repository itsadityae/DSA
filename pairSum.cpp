#include<iostream>
#include<vector>

using namespace std;


vector<int> pairSum(vector<int> nums, int target){
    int n = nums.size();
    int i = 0, j=n-1;
    vector<int> ans;
    
    while(i<j){

        nums[i] + nums[j] == target;

        if(nums[i] + nums[j] == target){
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }

        else if(nums[i] + nums[j] < target){
            i++;
        }
        else{
            j--;
        }

    }
    return ans;
}


int main(){

    vector<int> arr = {2,7,11,15};
    int target = 26;

    cout<<pairSum(arr, target)[0]<<" "<<pairSum(arr, target)[1]<<endl;

    
    return 0;
    
    
}