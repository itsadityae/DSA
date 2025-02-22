#include<iostream>
#include <climits>
using namespace std;

int main(){
    
    int array[] = {-1,2,-3,4,5,-6,7,8,-9,-10};
    int maxSum = INT_MIN;

    for(int start=0; start<10; start++){
        int currentSum = 0;
        
        for(int end=start; end<10; end++){
            currentSum+= array[end];
            maxSum = max(maxSum, currentSum);
            
        }
        
    }
    cout<<"Maximum Subarray sum: "<<maxSum<<endl;

    return 0;
}