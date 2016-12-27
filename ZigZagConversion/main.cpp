#include <iostream>
#include<string>
#include <cstring>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string newstr="";
        int count=s.length();
        int i,j;
        if (numRows==1)
            return s;
        for(i=0;i<numRows;i++) {
            for (j = i; j < count; j=j+numRows*2-2) {
                newstr+=s[j];
                if(i!=0&&i!=numRows-1&&j+numRows*2-2-2*i<count)
                    newstr+=s[j+numRows*2-2-2*i];
            }
        }
        return  newstr;
    }
};
int main() {
    Solution s;
    string str;
    int n;
    while(true)
    {
        cin>>str>>n;
        cout<<s.convert(str,n)<<endl;
    }
    return 0;
}