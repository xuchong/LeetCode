class Solution {
public:
    int countDigitOne(int n) {
      if(n<=0)
        return 0;
      int count=0;
      int digitNum=int(log(n)/log(10));
      int number=n;
      int digit=int(n/pow(10,digitNum));
      if(digit==1)
      {
        count+=n-pow(10,digitNum)+1+countDigitOne(n-pow(10,digitNum))+countDigitOne(pow(10,digitNum)-1);
      }else
      {
        count+=pow(10,digitNum)+countDigitOne(n-digit*pow(10,digitNum))+(digit)*countDigitOne(pow(10,digitNum)-1);
      }
      return count;
    }
};
