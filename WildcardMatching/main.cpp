#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;
#define  TL
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
			i = 0;
			i+=backTracking(s, p, sindex, pindex+1);
            if(i>0)
            {
                bool result=i;
                if(list.find(sindex)==list.end()){
                    unordered_map<int,bool> item;
                    item[pindex]= result;
                    list[sindex]= item;
                }
                return result;
            }
			for (sindex = sindex+1; sindex <= s.length(); sindex++)
			{
				if (i > 0)
					break;
				i+=backTracking( s, p, sindex, pindex);
				i+=backTracking(s, p, sindex, pindex + 1);
			}
            bool result=i;
            if(list.find(sindex)==list.end()){
                unordered_map<int,bool> item;
                item[pindex]= result;
                list[sindex]= item;
            }
            return result;
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
#endif
class Solution {
public:
    bool isMatch(string s, string p) {

    }
};

int main()
{
	Solution ss;
	string s = "babaaababaabababababbaaa", p = "***bba**a*bbba**aab";
	while (true)
	{
		cout << ss.isMatch(s, p) << endl;
		cin >> s;
		cin >> p;
	}
	return 0;
}