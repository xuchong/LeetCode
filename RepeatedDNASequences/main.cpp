class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
      unordered_map<unsigned int,int> dicts;
      // and
      unsigned int a=(int)(pow(2,20)-1);
      unordered_set<int> result_set;
      vector<string> result;

      if(s.length()<10)
        return result;
      //first one
      //A C G T
      unsigned int number=0;
      for(int i=0;i<10;i++)
      {
        number=number<<2;
        if(s[i]=='C')
        {
          number+=1;
        }else if(s[i]=='G')
        {
          number+=2;
        }else if(s[i]=='T')
        {
          number+=3;
        }
      }
      dicts[number]=0;
      for(int i=10;i<s.length();i++)
      {
        number=number<<2&a;
        cout<<number<<endl;
        if(s[i]=='C')
        {
          number+=1;
        }else if(s[i]=='G')
        {
          number+=2;
        }else if(s[i]=='T')
        {
          number+=3;
        }
        if(dicts.find(number)!=dicts.end())
        {
          if(result_set.find(dicts[number])==result_set.end())
          {
            result_set.insert(dicts[number]);
          }
        }else
        {
          dicts[number]=i-9;
        }
      }
      // change
      for(unordered_set<int>::iterator it=result_set.begin();it!=result_set.end();it++)
      {
        result.push_back(s.substr(*it,10));
      }
      return result;
    }
};
