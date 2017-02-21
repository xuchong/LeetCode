#include <iostream>
#include <vector>
using namespace std;
//多元一次方程
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.size()==0)
            return result;
        sort(candidates.begin(),candidates.end());
        vector<int> item;
        for(int i=0;i<candidates.size();i++)
        {
            
        }
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}