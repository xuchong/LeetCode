/***********************************************************************
 @Author: xuchong
 @Created Time : 三 10/ 9 00:26:50 2019
 @File Name: main.cpp
 @Description:
 ***********************************************************************/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution{
private:
    string part(int num, string number[]){
        if(num==0)
            return "";
        else {
            string result = "";
            if(num / 100){
                result += number[num/100] + " Hundred";
                num %= 100;
            }
            if(num == 0)
            {
                return result;
            }
            else if(num <= 20)
            {
                if(result!="")
                    result += " " + number[num];
                else
                    result = number[num];
            } else
            {
                int a = num/10 * 10;
                if(result!="")
                    result += " " + number[a];
                else
                    result = number[a];
                a = num - a;
                if(a!=0)
                    result += " " + number[a];
            }
            return result;
        }
    }
public:
    string numberToWords(int num) {
        string number[101];
        number[0]= "Zero";
        number[1]= "One";
        number[2]="Two";
        number[3]="Three";
        number[4]="Four";
        number[5]="Five";
        number[6]="Six";
        number[7]="Seven";
        number[8]="Eight";
        number[9]="Nine";
        number[10]="Ten";
        number[11]="Eleven";
        number[12]="Twelve";
        number[13]="Thirteen";
        number[14]="Fourteen";
        number[15]="Fifteen";
        number[16]="Sixteen";
        number[17]="Seventeen";
        number[18]="Eighteen";
        number[19]="Nineteen";
        number[20]="Twenty";
        number[30]="Thirty";
        number[40]="Forty";
        number[50]="Fifty";
        number[60]="Sixty";
        number[70]="Seventy";
        number[80]="Eighty";
        number[90]="Ninety";
        number[100] = "Hundred";
        string digits[3]= {"Thousand", "Million", "Billion"};
        int level = -1, partnumber;
        string result = "";
        do {
            partnumber = num % 1000;
            if(partnumber!=0) {
                if (level >= 0) {
                    if (result != "") {
                        result = this->part(partnumber, number) + " " + digits[level] + " " + result;
                    } else {
                        result = this->part(partnumber, number) + " " + digits[level];
                    }
                }else{
                    result = this->part(partnumber, number);
                }
            }
            level ++;
            num = num / 1000;
        }while (num);
        if(result=="")
            result=number[0];
        return result;
    }
};

int main(){
    int a[] = {1,2};
    cout<<a[1]<<endl;
    cout<< sizeof(a)/ sizeof(int)<<endl;
    string c="123", d="456";
    cout<<c+d<<endl;

    Solution s = Solution();
    cout<<s.numberToWords(200)<<endl;
    cout<<s.numberToWords(200001001)<<endl;
    cout<<s.numberToWords(2019239)<<endl;
    cout<<s.numberToWords(1000)<<endl;
    return 0;
}
/*
 * 2000,001
 */