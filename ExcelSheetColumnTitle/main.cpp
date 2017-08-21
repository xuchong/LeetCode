class Solution {
public:
    string convertToTitle(int n) {
        vector<int> result;
        while(n>0)
        {
          result.push_back(n%26);
          if(result.back()==0)
          {
            result.back()=26;
            n--;
          }
          n=n/26;
        }
        string output="";
        while(!result.empty())
        {
          output+='A'+result.back()-1;
          result.pop_back();
        }
        return output;
    }
};
