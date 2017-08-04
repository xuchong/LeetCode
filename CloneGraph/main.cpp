#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
private:
  unordered_map<int,UndirectedGraphNode*> index;
  void recursive(UndirectedGraphNode* node,UndirectedGraphNode*& clone)
  {
    if(node==NULL)
    {
      clone=node;
      return;
    }
    if(index.find(node->label)!=index.end())
    {
      clone=index[node->label];
      return;
    }
    clone=new UndirectedGraphNode(node->label);
    index[node->label]=clone;
    
    UndirectedGraphNode* tmp;
    for(int i=0;i<node->neighbors.size();i++)
    {
      recursive(node->neighbors[i],tmp);
      clone->neighbors.push_back(tmp);
    }
  }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
      index.clear();
      UndirectedGraphNode* clone=NULL;
      recursive(node,clone);
      return clone;
    }
};
int main()
{
  UndirectedGraphNode* node=new UndirectedGraphNode(0);
  UndirectedGraphNode* node1=node;//new UndirectedGraphNode(0);
  UndirectedGraphNode* node2=node;//=new UndirectedGraphNode(0);
  //UndirectedGraphNode* node3=new UndirectedGraphNode(0);
  cout<<node<<" "<<node->neighbors.size()<<endl;
  node->neighbors.push_back(node1);
  node->neighbors.push_back(node2);
  //node->neighbors.push_back(node3);
  Solution s;
  UndirectedGraphNode* clone=s.cloneGraph(node);
  cout<<clone<<" "<<clone->label<<" "<<clone->neighbors.size()<<endl;
  return 0;
}
