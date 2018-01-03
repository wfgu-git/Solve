#include <list>
#include <unordered_map>
using namespace std;

/*
146. LRU Cache
*/
class LRUCache {
 public:
  LRUCache(int capacity) : size(capacity) {}

  int get(int key) {
    auto it = mep.find(key);
    if (it != mep.end()) {
      L.splice(L.begin(), L, it->second);
      return it->second->second;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    auto it = mep.find(key);
    if (it != mep.end()) {
      it->second->second = value;
      L.splice(L.begin(), L, it->second);
      return;
    }

    L.push_front({key, value});
    mep[key] = L.begin();

    if ((int)L.size() > size) {
      mep.erase(L.back().first);
      L.pop_back();
    }
  }

 private:
  int size;
  unordered_map<int, list<pair<int, int>>::iterator> mep;
  list<pair<int, int>> L;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
