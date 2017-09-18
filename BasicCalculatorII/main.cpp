class Solution {
public:
    int calculate(string s) {
        if(s.empty())
          return 0;
        vector<int> results;
        vector<char> operations;
        int item,number;
        char operation='0';
        for(int i=0;i<s.length();i++)
        {
          if(s[i]>='0'&&s[i]<='9')
          {
            number=0;
            while(s[i]>='0'&&s[i]<='9'&&i<s.length())
            {
              number*=10;
              number+=s[i]-'0';
              i++;
            }
            while(i<s.length()&&s[i]==' ')
            {
                i++;
            }
            if(i==s.length())
            {
              if(operation=='0')
              {
                results.push_back(number);
              }if(operation=='*')
              {
                item*=number;
                results.push_back(item);
              }else if(operation=='/')
              {
                item/=number;
                results.push_back(item);
              }
            }else
            {
              if(operation=='0')
              {
                item=number;
              }if(operation=='*')
              {
                item*=number;
              }else if(operation=='/')
              {
                item/=number;
              }
              i--;
            }
          }else if(s[i]=='+'||s[i]=='-')
          {
            operations.push_back(s[i]);
            results.push_back(item);
            operation='0';
            item=0;
          }else if(s[i]=='*'||s[i]=='/')
          {
            operation=s[i];
          }
        }
        int result=results[0];
        for(int i=1;i<results.size();i++)
        {
          if(operations[i-1]=='+')
          {
            result+=results[i];
          }else
          {
            result-=results[i];
          }
        }
        return result;
    }
};
