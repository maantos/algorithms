/* 
 Given an integer array nums, return all the triplets 
 [nums[i], nums[j], nums[k]] such that 
 i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

/*
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Exiample 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to
*/
#include <iostream>
#include <vector>
#include <unordered_set> 
#include <algorithm>
#include <set>
#include <string>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  
  std::set<std::vector<int>> resultSet;
  std::sort(nums.begin(), nums.end());
  for(int i = 0; i < nums.size(); i++){
    auto pforward = i+1;
    auto pbackward = nums.size()-1;
    while(pforward < pbackward) {
      auto sum = nums[i] + nums[pforward] + nums[pbackward]; 
      if(sum == 0) {
        resultSet.insert({nums[i], nums[pforward], nums[pbackward]});
        pbackward--;
        pforward++;
      } else if (sum > 0){
        pbackward--;
      } else {
        pforward++;
      }
    }
  }
  
  std::vector<std::vector<int>> resultVec = {{}};

  for(const auto& x : resultSet) {
    resultVec.push_back(x);
  }

  return resultVec;
}



int main() {
    
  std::vector<int> N {-1,0,1,2,-1,-4};
  auto r = threeSum(N);

  for(std::vector<int> &v : r) {
    std::string s = "[";
    for(auto x : v) {
      s += std::to_string(x) + ",";
    }
    s.replace(s.size()-1, 1, "]");
    printf("Tripe found: %s\n", s.c_str());
  }

  return 0;
}
