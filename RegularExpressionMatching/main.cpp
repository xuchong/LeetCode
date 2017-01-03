#include <iostream>
#include<cstring>
#include<string>
using namespace std;
#define TIMELIMIT
#ifdef TIMELIMIT
class Solution {
public:
    bool isMatch(string s, string p) {
        return is(s,p);

    }

private:
    bool is(string s,string p)
    {
        while(p.length()>2&&p[1]=='*'&&p[0]==p[2])
        {
            if(p.length()>3&&p[3]=='*')
                p=p.substr(2,p.length()-2);
            else
                break;
        }
        if(s.length()==0)
            if((p.length()==0||(p.length()>=2&&p[1]=='*'&&is(s,p.substr(2,p.length()-2)))))
                return 1;
            else
                return 0;
        if(s.length()>0&&p.length()==0)
            return 0;
        //s ,p not null
        if(p.length()>=2)
            if(s[0]==p[0]||p[0]=='.')
                if(p[1]=='*')
                    if(p.length()==2||(p.length()>2&&p[2]!=s[0]&&p[2]!='.'))
                        return is(s.substr(1,s.length()-1),p.substr(2,p.length()-2))||is(s.substr(1,s.length()-1),p)||is(s,p.substr(2,p.length()-2));
                    else
                        return is(s.substr(1,s.length()-1),p.substr(2,p.length()-2))||is(s.substr(1,s.length()-1),p)||is(s.substr(1,s.length()-1),p.substr(3,p.length()-3))||is(s,p.substr(2,p.length()-2));
                else
                    return is(s.substr(1,s.length()-1),p.substr(1,p.length()-1));
            else if(p[1]=='*')
                return is(s,p.substr(2,p.length()-2));
            else
                return 0;
        else
        {
            if(s[0]==p[0]||p[0]=='.')
                return is(s.substr(1,s.length()-1),p.substr(1,p.length()-1));
            else
                return 0;
        }
    }
};

#endif


int main() {
    Solution ss;
    string s="",p="c*c*";
    while(true)
    {
        cin>>s>>p;
        cout<<ss.isMatch(s,p)<<endl;
    }
    return 0;
}