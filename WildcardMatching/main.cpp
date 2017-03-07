#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;
#define  TLL
#ifndef TL
class Solution {
private:
    unordered_map<int,unordered_map<int,bool>> list;
public:

	bool backTracking( string s, string p,int sindex,int pindex)
	{
        if(list.find(sindex)!=list.end()){
            if(list[sindex].find(pindex)!=list[sindex].end())
                return list[sindex][pindex];
        }
		int i;
		if (sindex == s.length())
		{
			if (pindex == p.length()) {
                if(list.find(sindex)==list.end()){
                    unordered_map<int,bool> item;
                    item[pindex]=true;
                    list[sindex]= item;
                }
                return true;
            }
			else
			{
				while (p[pindex] == '*'&&pindex < p.length())
					pindex++;
				if (pindex == p.length()) {
                    if(list.find(sindex)==list.end()){
                        unordered_map<int,bool> item;
                        item[pindex]=true;
                        list[sindex]= item;
                    }
                    return true;

                }
				else {
                    if(list.find(sindex)==list.end()){
                        unordered_map<int,bool> item;
                        item[pindex]= false;
                        list[sindex]= item;
                    }
                    return false;

                }
			}
		}
		if (pindex == p.length() && sindex != s.length()) {
            if(list.find(sindex)==list.end()){
                unordered_map<int,bool> item;
                item[pindex]= false;
                list[sindex]= item;
            }
            return false;
        }
		
		if (p[pindex] == '?')
		{
			//index[pindex] = sindex;
            bool result=backTracking(s, p, sindex + 1, pindex + 1);
            if(list.find(sindex)==list.end()){
                unordered_map<int,bool> item;
                item[pindex]= result;
                list[sindex]= item;
            }
			return result;
		}
		else if (p[pindex] == '*')
		{
			if (pindex == p.length() - 1)
				return true;
			int next_start = p.find("*", pindex+1);
			string substrP;
			if (next_start == -1)
			{
				substrP = p.substr(pindex + 1, p.length() - pindex-1);
				int a = s.length(), b = substrP.length();
				cout <<s.length()<<" "<<substrP.length()<<" "<< (int)(s.length() - substrP.length()) << endl;
				if ((a-b)>= sindex)
					return backTracking(s, p, s.length() - substrP.length(), pindex + 1);
				else
					return false;
			}
			else
			{
				substrP = p.substr(pindex + 1, next_start - pindex - 1);
				int i , j , flag = 0;
				for (i = sindex; i < s.length() - substrP.length()+1; i++)
				{
					for ( j = 0; j < substrP.length(); j++)
					{
						//cout << s[i + j] << substrP[j] << endl;
						if ((i+j)>=s.length()||(s[i+j] != substrP[j] && substrP[j] != '?'))
							break;
					}
					if (j == substrP.length())
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
				{
					return backTracking(s,p,i+substrP.length(),next_start);
				}
				else{
					return false;
				}
			}
		}
		else
		{
			if (s[sindex] == p[pindex])
			{
                bool result=backTracking( s, p, sindex+1, pindex + 1);
                if(list.find(sindex)==list.end()){
                    unordered_map<int,bool> item;
                    item[pindex]= result;
                    list[sindex]= item;
                }
                return result;
			}
			else
            {
                bool result=false;
                if(list.find(sindex)==list.end()){
                    unordered_map<int,bool> item;
                    item[pindex]= result;
                    list[sindex]= item;
                }
                return result;
            }
		}

	}
	bool isMatch(string s, string p) {
		int i;
		list.clear();
		if (s.empty())
		{
			if (p.empty())
				return true;
			else{
				i = 0;
				while (p[i] == '*'&&i<p.length())
				{
					i++;
				}
				if (i == p.length())
					return true;
				else
					return false;
			}	
		}
		if (p.empty()&&!s.empty())
		{
			return false;
		}
		//s , p string not empty then:  consider this condition ,*****
		i = 1;
		int count = 0;
		while (i < p.length())
		{
			if (p[i] == p[i - 1] && p[i] == '*')
				count++;
			else
				p[i - count] = p[i];
			i++;
		}
		p = p.substr(0, p.length() - count);
		return backTracking(s,p,0,0);
	}
};
#else
class Solution {
public:
	bool isMatch(string s, string p) {

	}
};
#endif

//"abefcdgiescdfimde"
//"bb"
//"*?bb"
int main()
{
	Solution ss;
	string s = "bb", p = "*?bb";
	while (true)
	{
		cout << ss.isMatch(s, p) << endl;
		cin >> s;
		cin >> p;
	}
	return 0;
}