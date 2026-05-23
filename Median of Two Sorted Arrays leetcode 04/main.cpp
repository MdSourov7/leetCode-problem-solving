/*
 *
 *
 * 4. Median of Two Sorted Arrays
Hard

Topics
premium lock icon
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively,
 return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Solution {
public:
    double static findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> nums3;

        for (int i = 0; i < nums1.size(); i++) {
            nums3.push_back(nums1[i]);
        }
        for (int j = 0; j < nums2.size(); j++) {
            nums3.push_back(nums2[j]);
        }
        sort(nums3.begin(), nums3.end());
        int n = nums3.size();
        if (n % 2 != 0) {
            return nums3[nums3.size() / 2];
        } else {
            return (nums3[n / 2 - 1] + nums3[n / 2]) /2.0;
        }
    }
};


int main(){
    Solution obj;

    vector<int> nums1 = {10,11,12,13,45,61};
    vector<int> nums2 = {10,34,42,43,45,61};

    double result = obj.findMedianSortedArrays( nums1, nums2 );
    cout<< fixed<< setprecision(5)<<result<<endl;

}