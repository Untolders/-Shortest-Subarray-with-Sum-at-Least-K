##########################################################################################  Question  ############################################################################################################################################

Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1], k = 1
Output: 1
Example 2:

Input: nums = [1,2], k = 4
Output: -1
Example 3:

Input: nums = [2,-1,2], k = 3
Output: 3
 

Constraints:
1 <= nums.length <= 105
-105 <= nums[i] <= 105
1 <= k <= 109

########################################################################################################  Solution  ##############################################################################################################################


````class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);
        
        // Step 1: Compute prefix sums
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> dq; // Monotonic queue
        int minLength = INT_MAX;

        // Step 2: Process prefix sums
        for (int i = 0; i <= n; ++i) {
            // Remove indices from the front if the condition is met
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }

            // Maintain monotonicity of the deque
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }

            // Add the current index to the deque
            dq.push_back(i);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
````

  
