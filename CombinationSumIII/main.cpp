class Solution {
private:
vector<vector<int>> result;
void recursive(int k,int n,int left,vector<int> item)
{
  if(n==0&&k==0)
  {
    result.push_back(item);
    return;
  }else if(n<0 || k==0 || left==0)
  {
    return;
  }
  if(n>(left-k+1+left)*k/2)
  {
    return;
  }
  recursive(k,n,left-1,item);
  item.push_back(left);
  recursive(k-1,n-left,left-1,item);
}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      result.clear();
      vector<int> item;
      recursive(k,n,9,item);
      return result;
    }
};
