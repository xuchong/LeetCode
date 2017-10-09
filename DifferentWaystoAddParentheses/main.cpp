// class Solution {
// private:
//
//   vector<int> recursive(string input)
//   {
//     vector<int> res;
//     char op='0';
//     int num,start=0,end=0,tmp;
//     int flag=1;
//     int i;
//     for(i =0;i<input.length();i++)
//     {
//       if(input[i]>='0'&&input[i]<='9')
//       {
//         tmp=0;
//         if(op!='0')
//           end=i;
//         if(flag==-1)
//           end=i-1;
//         while(i<input.length()&&input[i]>='0'&&input[i]<='9')
//         {
//           tmp*=10;
//           tmp+=input[i]-'0';
//           i++;
//         }
//         //cout<<tmp<<" "<<op<<endl;
//         tmp=tmp*flag;
//
//
//           num=tmp;
//           if(i==input.length())
//             {
//               res.push_back(num);
//               return res;
//             }
//
//         flag=1;
//         i--;
//       }else if(input[i]=='+')
//       {
//         op=input[i];
//         break;
//       }else if(input[i]=='-')
//       {
//         if(i==0||op!='0')
//         {
//           flag=-1;
//         }else
//         {
//             op=input[i];
//             break;
//         }
//       }else if(input[i]=='*')
//       {
//         op=input[i];
//         break;
//       }
//     }
//     //num op vector
//     i++;
//     vector<int> sub=recursive(input.substr(i,input.length()-i));
//     for(int j=0;j<sub.size();j++)
//     {
//       if(op=='+')
//         sub[i]+=num;
//       else if(op=='-')
//         sub[i]-=num;
//       else
//         sub[i]*=num;
//     }
//     flag=1;
//     for(i;i<input.length();i++)
//     {
//       if(input[i]>='0'&&input[i]<='9')
//       {
//         tmp=0;
//         if(op!='0')
//           end=i;
//         if(flag==-1)
//           end=i-1;
//         while(i<input.length()&&input[i]>='0'&&input[i]<='9')
//         {
//           tmp*=10;
//           tmp+=input[i]-'0';
//           i++;
//         }
//         //cout<<tmp<<" "<<op<<endl;
//         tmp=tmp*flag;
//         if(i==input.length())
//         {
//           break;
//         }
//         if(op=='+')
//           num+=tmp;
//         else if(op=='-')
//           num-=tmp;
//         else
//           num*=tmp;
//         flag=1;
//         i--;
//       }else if(input[i]=='+')
//       {
//         op=input[i];
//         break;
//       }else if(input[i]=='-')
//       {
//         if(i==0||op!='0')
//         {
//           flag=-1;
//         }else
//         {
//             op=input[i];
//             break;
//         }
//       }else if(input[i]=='*')
//       {
//         op=input[i];
//         break;
//       }
//     }
//     vector<int> sub2;
//     i++;
//     if(i<input.length())
//     {
//       sub2=recursive(input.substr(i,input.length()-i));
//       for(int j=0;j<sub2.size();j++)
//       {
//         if(op=='+')
//           sub2[i]+=num;
//         else if(op=='-')
//           sub2[i]-=num;
//         else
//           sub2[i]*=num;
//       }
//     }
//     sub.insert(sub.end(),sub2.begin(),sub2.end());
//     return sub;
//   }
// public:
//     vector<int> diffWaysToCompute(string input) {
//       vector<int>result;
//       if(input.empty())
//         return result;
//       result=recursive(input);
//       return result;
//     }
// };
class Solution{
public:
  vector<int> diffWaysToCompute(string input)
  {
    vector<int>result;
    if(input.empty())
      return result;
    char op='0';
    int i,num=0;
    for(i=0;i<input.length();i++)
    {
      if(input[i]=='+'||input[i]=='-'||input[i]=='*'){
        op=input[i];
        num=0;
        {
          vector<int>a=diffWaysToCompute(input.substr(0,i));
          vector<int>b=diffWaysToCompute(input.substr(i+1));
          for(int m=0;m<a.size();m++)
            for(int n=0;n<b.size();n++)
            {
              if(op=='+')
                result.push_back(a[m]+b[n]);
              else if(op=='-')
                result.push_back(a[m]-b[n]);
              else
                result.push_back(a[m]*b[n]);
            }
        }

      }
      num*=10;
      num+=input[i]-'0';
    }
    if(op=='0')
    {
      result.push_back(num);
    }
    return result;
  }
};
