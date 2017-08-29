class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result=0;
        while(n!=0){
          if(n%2)
            result++;
          n=n/2;
        }
        return result;
    }
};
