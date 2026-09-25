#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>vistos; //guardo valor
        for(int i = 0; i < nums.size(); i++){
            if(vistos.find(nums[i]) != vistos.end()){
                return true;
            }
            vistos[nums[i]] = i;
        }
        return false;
    }
};