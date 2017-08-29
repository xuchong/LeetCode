class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      vector<int> bits(32,0);
      int tmp;
      while(n!=0)
      {
        tmp=(int)(log(n)/log(2));
        bits[tmp]=1;
        n=n-pow(2,tmp);
      }
      int start=0,end=31;
      while(start<end)
      {
        tmp=bits[start];
        bits[start]=bits[end];
        bits[end]=tmp;
        start++;
        end--;
      }
      uint32_t result=0;
      for(int i=0;i<32;i++)
      {
        if(bits[i])
          result+=pow(2,i);
      }
      return result;
    }
};
