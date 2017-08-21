class Solution {
public:
    int trailingZeroes(int n) {
        int noOf5;
        if(n==0)
          return 0;
        int extra=(int)floor(log(n)/log(5));
        if(extra==0)
        {
          return 0;
        }else
        {
          int result=0;
          while(extra!=0){
            result+=5*(pow(5,extra-1)-1)/4+1;
            n=n-pow(5,extra);
            if(n==0)
            {
              break;
            }
            extra=(int)floor(log(n)/log(5));
          }
          return result;
        }
    }
};
