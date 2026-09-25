#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> vistos; //guardo primero indice, despues valor
        for(int i = 0; i < nums.size(); i++){
            int complemento = target - nums[i];
            if(vistos.find(complemento) != vistos.end()){
                return {vistos[complemento], i};
            }
            vistos[nums[i]] = i;
        }
        return {};
    }
};