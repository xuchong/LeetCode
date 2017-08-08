#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) {
      _capacity=capacity;
    }

    int get(int key) {
      unordered_map<int,pair<int,list<int>::iterator>>::iterator it=dict.find(key);
      if(it!=dict.end())
      {
        //update dict and que;
        que.push_front(it->first);
        que.erase(it->second.second);
        it->second.second=que.begin();
        return it->second.first;
      }else
      {
        return -1;
      }
    }

    void put(int key, int value) {
      unordered_map<int,pair<int,list<int>::iterator>>::iterator it=dict.find(key);
      if(it!=dict.end())
      {
        //update dict and que;
        que.push_front(it->first);
        que.erase(it->second.second);
        it->second.first=value;
        it->second.second=que.begin();
      }else
      {
        //determine whether up to capacity
        if(dict.size()==_capacity)
        {
          //erase old; add new
          dict.erase(que.back());//map can erase key and iterator!!!
          que.pop_back();

          que.push_front(key);
          dict[key]={value,que.begin()};
        }else
        {
          que.push_front(key);
          dict[key]={value,que.begin()};
        }
      }
    }
private:
  //why use list? : because when erase, it costs O(1).
  list<int> que;
  unordered_map<int,pair<int,list<int>::iterator>> dict;
  int _capacity;
};
int main()
{
  return 0;
}
