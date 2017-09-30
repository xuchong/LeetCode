class Solution {
private:
  unordered_set<int> res;
  void recursive(string input)
  {
    char op='0';
    int num,start=0,end=0,tmp;
    for(int i =0;i<input.length();i++)
    {
      if(input[i]>='0'&&input[i]<='9')
      {
        tmp=0;
        if(op!='0')
          end=i;
        while(i<input.length()&&input[i]>='0'&&input[i]<='9')
        {
          tmp*=10;
          tmp+=input[i]-'0';
          i++;
        }
        //cout<<tmp<<" "<<op<<endl;
        if(op!='0')
        {
          if(op=='+')
            num+=tmp;
          else if(op=='-')
            num-=tmp;
          else
            num*=tmp;
          stringstream ss;
          ss<<num;
          string a=input;
          recursive(a.replace(start,i-start,ss.str()));
          start=end;
          num=tmp;
          op='0';
        }else
        {
          num=tmp;
          if(i==input.length())
            res.insert(num);
        }
        i--;
      }else if(input[i]=='+')
      {
        op=input[i];
      }else if(input[i]=='-')
      {
        if(i==0)
        {

        }else
        {
            op=input[i];
        }
      }else if(input[i]=='*')
      {
        op=input[i];
      }
    }
  }
public:
    vector<int> diffWaysToCompute(string input) {
      vector<int>result;
      if(input.empty())
        return result;
      recursive(input);
      for(auto it: res)
      {
        result.push_back(it);
      }
      return result;
    }
};
