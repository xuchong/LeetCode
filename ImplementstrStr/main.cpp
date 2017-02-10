#include <iostream>
#include<string>
#include<cstring>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
int main() {
    Solution s;
    string a,b;
    while(true)
    {
        cin>>a>>b;
        cout<<s.strStr(a,b)<<endl;
    }
    return 0;
}