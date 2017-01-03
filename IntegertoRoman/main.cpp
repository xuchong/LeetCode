#include <iostream>
#include<string>
#include<cstring>
using namespace std;
class Solution {
private:
    string list[7]={"I","V","X","L","C","D","M"};
public:
    string intToRoman(int num) {
        string result="";
        int tmp,i;
        while(num>0)
        {
            if(num>=1000)
            {
                tmp=num/1000;
                for(i=0;i<tmp;i++)
                    result+=list[6];
                num%=1000;
            }else if(num>=900)
            {
                result=result+list[4]+list[6];
                num-=900;
            }else if(num>=500)
            {
                result+=list[5];
                tmp=(num-500)/100;
                for(i=0;i<tmp;i++)
                    result+=list[4];
                num%=100;
            }else if(num>=400)
            {
                result+=list[4]+list[5];
                num-=400;
            }else if(num>=100)
            {
                tmp=num/100;
                for(i=0;i<tmp;i++)
                    result+=list[4];
                num%=100;
            }else if(num>=90)
            {
                result+=list[2]+list[4];
                num-=90;
            }else if(num>=50)
            {
                result+=list[3];
                tmp=(num-50)/10;
                for(i=0;i<tmp;i++)
                    result+=list[2];
                num%=10;
            }else if(num>=40)
            {
                result+=list[2]+list[3];
                num-=40;
            }else if(num>=10)
            {
                tmp=num/10;
                for(i=0;i<tmp;i++)
                    result+=list[2];
                num%=10;
            }else if(num==9)
            {
                result+=list[0]+list[2];
                num-=9;
            }else if(num>=5)
            {
                result+=list[1];
                tmp=(num-5);
                for(i=0;i<tmp;i++)
                    result+=list[0];
                num%=1;
            }else if(num==4)
            {
                result+=list[0]+list[1];
                num=0;
            }else
            {
                tmp=num;
                for(i=0;i<tmp;i++)
                    result+=list[0];
                num%=1;
            }
        }
        return result;
    }
};
int main() {
    Solution s;
    int n;
    while(true)
    {
        cin>>n;
        cout<<s.intToRoman(n)<<endl;
    }
    return 0;
}