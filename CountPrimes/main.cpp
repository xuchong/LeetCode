class Solution {
public:
    int countPrimes(int n) {
        if(n<3)
          return 0;
        vector<bool> data(n+1,true);
        int result=0;
        long i,j;
        for(i=2;i<n;i++)
        {
          if(data[i]){
            result++;
              for(j=i;j*i<n;j++)
              {
                data[j*i]=false;
              }
          }
        }
        return result;
    }
};
