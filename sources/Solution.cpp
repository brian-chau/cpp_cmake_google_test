#include "Solution.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <gmp.h>
#include <gmpxx.h>

Solution::Solution() {
}

Solution::~Solution() {
}

std::vector<int> Solution::runningSum(std::vector<int>& nums) {
    std::vector<int> result;
    int sum(0);
    for (auto val : nums) {
        sum += val;
        result.push_back(sum);
    }
    return result;
}

int Solution::pivotIndex(std::vector<int>& nums) {
    int n(nums.size());
    if (n == 1) {
        return 0;
    }
    int leftsum(0), rightsum(0);

    for (int i = 1; i < n; i++) {
        rightsum += nums[i];
    }
    if (leftsum == rightsum) {
        return 0;
    }
    for (int i = 1; i < n; i++) {
        leftsum += nums[i - 1];
        rightsum -= nums[i];
        if (leftsum == rightsum) {
            return i;
        }
    }
    return -1;
}

int getNext(int n) {
    int totalSum(0);
    while (n > 0) {
        int d = n % 10;
        n = n / 10;
        totalSum += d * d;
    }
    return totalSum;
}

bool Solution::isHappy(int n) {
    std::set<int> seen;
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = getNext(n);
    }
    return n == 1;
}

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen;
    for (size_t i = 0; i < nums.size(); i++) {
        if (seen.find(target - nums[i]) != seen.end()) {
            std::vector<int> result{(int)i, seen[target - nums[i]]};
            std::sort(result.begin(), result.end());
            return result;
        }
        seen[nums[i]] = i;
    }
    return {};
}

std::vector<int> Solution::answerQueries(std::vector<int>& nums, std::vector<int>& queries) {
    // Sort 'nums'
    sort(nums.begin(), nums.end());

    // For each query, collect numbers from lowest to highest.
    // If their sum exceeds the limit 'query', move on to the next query.
    std::vector<int> ans;
    for (auto query : queries) {
        int count(0);
        for (auto num : nums) {
            if (query >= num) {
                query -= num;
                count++;
            } else {
                break;
            }
        }
        ans.push_back(count);
    }

    return ans;
}
