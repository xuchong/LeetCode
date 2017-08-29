class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==n)
          return m;
        int a=(int)(log(m)/log(2));
        int b=(int)(log(n)/log(2));
        int result=0;
        if(a<b)
          return 0;
        while(a==b)
        {
          result+=pow(2,a);
          m-=pow(2,a);
          n-=pow(2,b);
          a=(int)(log(m)/log(2));
          b=(int)(log(n)/log(2));
        }
        //can be change to bit operation
        return result;
    }
};
