class Solution {
public:
    bool isHappy(int n) {
      vector<int> data(1000,0);
      int tmp;
      while(n!=1)
      {
        if(data[n]==1)
          return false;
        data[n]=1;
        tmp=0;
        while(n){
          tmp+=n%10*n%10;
          n=n/10;
        }
        n=tmp;
      }
      return true;
    }
};
