// 1. Two Sum

// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:
// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums, result;
    int n, i, number, target;
    Solution solution;

    cout << "Input the number of nums:"<<endl;
    cin >> n;
    cout << "Input the nums:"<<endl;
    for(i=0; i<n; i++){
        cin >> number;
        nums.push_back(number);
    }
    cout << "Input the target:"<<endl;
    cin >> target;
    result = solution.twoSum(nums, target);
    cout<<"Result:"<<endl;
    for(i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}