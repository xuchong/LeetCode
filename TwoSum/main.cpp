#include<iostream>
#include<vector>
using namespace std;
struct DATA{
	int index;
	int data;
};
class Solution {
public:
	void quicksort(vector<int>&data,int start,int end)
	{
		if(start<end)
		{
			int i=start-1;
			int x=data[end];
			int tmp;
			for(int j=start;j<end-1;j++)
			{
				if(data[j]<=x)
				{
					i++;
					tmp=data[j];
					data[j]=data[i];
					data[i]=tmp;
				}
			}
			data[end]=data[i+1];
			data[i+1]=x;
			quicksort(data,start,i);
			quicksort(data,i+2,end);
		}
	}
	void quicksort2(int start,int end)
	{
		if(start<end)
		{
			int i=start-1;
			int x=newdata[end].data;
			int tmp;
			for(int j=start;j<end;j++)
			{
				if(newdata[j].data<=x)
				{
					i++;
					tmp=newdata[j].data;
					newdata[j].data=newdata[i].data;
					newdata[i].data=tmp;

					tmp=newdata[j].index;
					newdata[j].index=newdata[i].index;
					newdata[i].index=tmp;
				}
			}
			newdata[end].data=newdata[i+1].data;
			tmp=newdata[i+1].index;
			newdata[i+1].data=x;
			newdata[i+1].index=newdata[end].index;
			newdata[end].index=tmp;
			quicksort2(start,i);
			quicksort2(i+2,end);
		}
	}
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> indixes;
		for(int i=0;i<nums.size();i++)
		{
			newdata[i].data=nums[i];
			newdata[i].index=i;
		}
		quicksort2(0,nums.size()-1);

		int start=0,end=nums.size()-1;

		while(start<end)
		{
			if(newdata[start].data+newdata[end].data==target)
			{
				indixes.push_back(newdata[start].index);
				indixes.push_back(newdata[end].index);
				break;
			}else if(newdata[start].data+newdata[end].data<target)
			{
				start++;
			}
			else if(newdata[start].data+newdata[end].data>target)
			{
				end--;
			}
		}

		//for(int i=0;i<nums.size();i++)
		//{
		//	cout<<newdata[i].data<<"\t"<<newdata[i].index<<endl;
		//}
		return indixes;
    }
private:
	DATA newdata[100000];
};
int main()
{
	Solution a;
	vector<int> abc;
	int t;
	int n;
	int aa;
	cin>>t;
	while(t--){
		cin>>n;
		abc.clear();
		while(n--){
			cin>>aa;
			abc.push_back(aa);
		}
		cin>>aa;
		vector<int>result=a.twoSum(abc,aa);
		cout<<result[0]<<"\t"<<result[1]<<endl;
	}
	return 0;
}