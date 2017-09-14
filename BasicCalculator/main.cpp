class Solution {
public:
    int calculate(string s) {
        vector<int> result;
        vector<char> operators;
        int number,item=0;
        char op='0';
        for(int i=0;i<s.length();i++)
        {
          if(s[i]>='0'&&s[i]<='9')
          {
            number=0;
            while(i<s.length()&&s[i]>='0'&&s[i]<='9')
            {
              number*=10;
              number=s[i]-'0';
              i++;
            }
            if(i!=s.length())
            {
              i--;

            }
            if(op=='+')
            {
              item+=number;
            }else if(op=='-')
            {
              item-=number;
            }else
            {
              item=number;
            }
          }else if(s[i]=='+'||s[i]=='-')
          {
            op=s[i];
          }else if(s[i]=='(')
          {
            if(op!='0')
            {
              result.push_back(item);
              operators.push_back(op);
            }
            op='0';
            item=0;
            operators.push_back('(');
          }else if(s[i]==')')
          {
            operators.pop_back();
            if(operators.size()>0&&operators.back()!='(')
            {
              if(operators.back()=='+')
              {
                item+=result.back();
              }else
              {
                item=result.back()-item;
              }
              result.pop_back();
              operators.pop_back();
            }
          }
        }
        return item;
    }
};
