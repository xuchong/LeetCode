#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        TreeNode* dataa[10000],*tmpa[10000],*datab[10000],*tmpb[10000];
        int starta,startb,newstarta,newstartb,num;
        starta=0;
        startb=0;
        dataa[starta]=root->left;
        datab[startb]=root->right;
        while(starta!=-1&&starta==startb)
        {
          newstarta=-1;
          newstartb=-1;
          //遍历每一层
          while(starta!=-1&&starta==startb){
            if(dataa[starta]!=NULL&&datab[startb]!=NULL)
            {
              if(dataa[starta]->val==datab[startb]->val)
              {
                  tmpa[++newstarta]=dataa[starta]->left;
                  tmpa[++newstarta]=dataa[starta]->right;

                  tmpb[++newstartb]=datab[startb]->right;
                  tmpb[++newstartb]=datab[startb]->left;
                  starta--;
                  startb--;
              }else
              {
                return false;
              }
            }else if(dataa[starta]==NULL&&datab[startb]==NULL)
            {
              starta--;
              startb--;
            }else{
              return false;
            }
          }
          starta=newstarta;
          startb=newstartb;
          for(int i=0;i<=starta;i++)
          {
             dataa[i]=tmpa[i];
             datab[i]=tmpb[i];
          }
        }
        return true;
    }
};
int main()
{
    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}
