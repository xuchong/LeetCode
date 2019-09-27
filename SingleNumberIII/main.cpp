/***********************************************************************
 @Author: xuchong
 @Created Time : 五  9/27 00:37:36 2019
 @File Name: main.cpp
 @Description:
 ***********************************************************************/
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // zero init
        vector<int> result(2);
        if(nums.size() < 4)
            return nums;
        int val = nums[0];
        int i;
        for(i=1;i<nums.size();i++)
        {
            val ^= nums[i];
        }
        // exist two different integer, so val != 0.
        // split nums into two part according to non-zero bit.
        int non_zero_bit_index = 0;
        while(val%2==0)
        {
            non_zero_bit_index += 1;
            val = val>>1;
        }
        cout<< val << endl;
        cout<< non_zero_bit_index << endl;
        // part A store 1, part B store 0
        int part_A, part_B;
        int j=-1, k=-1, m = 0;
        for(i=0; i< nums.size(); i++)
        {
            val = nums[i];
            val = val >> non_zero_bit_index;
            if(val%2==0)
            {
                if(k==-1)
                {
                    part_B = nums[i];
                    k ++;
                }else
                {
                    part_B ^= nums[i];
                }
            }else
            {
                if(j==-1)
                {
                    part_A = nums[i];
                    j ++;
                }else
                {
                    part_A ^= nums[i];
                }
            }
        }
        result[0] = part_A;
        result[1] = part_B;
        return result;
    }
};

int main(){
    // 补码cc
    std::string binary = std::bitset<8>(-1).to_string(); //to binary
    cout<< binary <<endl;
    cout<<(2>>1)<<endl;

    vector<int> input = {1, 2, 1, 3, 2, 5};

    Solution ss = Solution();
    vector<int> result = ss.singleNumber(input);
    cout<< result[0] << ',' << result[1] <<endl;
    return 0;
}

/*
 * [1,2,1,3,2,5]
 * Output: [3,5]   3: 0011  5:0101
 *
 * 8 4 8 16
 * 8 4 16 8
 *
 *
 */