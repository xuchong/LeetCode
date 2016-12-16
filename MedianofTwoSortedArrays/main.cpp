#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int al = nums1.size();
		int bl = nums2.size();
		if ((al + bl) % 2 == 0)
			return (recursive(nums1, nums2, (al + bl) / 2, 0, 0, al, bl) + recursive(nums1, nums2, (al + bl) / 2 + 1, 0, 0, al, bl))/2;
		else
			return recursive(nums1, nums2, (al + bl) / 2+1, 0, 0, al, bl);
	}
private:
	//find k-th  biggest
	double recursive(vector<int>&a, vector<int>&b, int k, int starta, int startb, int enda, int endb)
	{
		if (starta >= enda)
			return b[startb + k - 1];
		if (startb >= endb)
			return a[starta + k - 1];
		if (k == 1)
			return a[starta] > b[startb] ? b[startb] : a[starta];
		//k is even
		int median = k / 2 - 1;
		int valuea, valueb;
		if (starta + median >= enda)
		{
			valuea = a[enda - 1];
			valueb = b[startb + median];
			if (valuea <= valueb)
			{
				return recursive(a, b, k - enda + starta , enda, startb, enda, endb);
			}
		}else if (startb + median >= endb)
		{
			valuea = a[starta +median];
			valueb = b[endb-1];
			if (valuea >= valueb)
			{
				return recursive(a, b, k - endb + startb , starta, endb, enda, endb);
			}
		}
		else
		{
			valuea = a[starta + median];
			valueb = b[startb + median];
		}
		if (valuea < valueb)
		{
			return recursive(a, b, k - median - 1, starta + median + 1, startb, enda, endb);
		}
		else if (valuea>valueb)
		{
			return recursive(a, b, k - median - 1, starta, startb + median + 1, enda, endb);
		}
		else
		{
			if (k % 2 == 0)
				return valuea;
			else
				return recursive(a, b, 1, starta + median + 1, startb + median + 1, enda, endb);
		}

	}
};
int main()
{
	Solution a;
	vector<int> m;
	vector<int> n;
	int ml, nl;
	int tm, tn;
	while (true)
	{
		cin >> ml >> nl;
		m.clear();
		n.clear();
		while (ml--)
		{
			cin >> tm;
			m.push_back(tm);
		}
		while (nl--)
		{
			cin >> tn;
			n.push_back(tn);
		}
		cout << a.findMedianSortedArrays(m,n)<<endl;
	}
	return 0;
}