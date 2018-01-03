#include <list>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
460. LFU Cache
*/
class LFUCache {
 public:
  LFUCache(int capacity, int used = 0) : now(used), size(capacity) {}

  int get(int key) {
    if (!ValueMap.count(key)) return -1;

    int value = ValueMap[key].first;
    FreqMap[ValueMap[key].second].erase(ItMap[key]);
    ValueMap[key].second++;
    FreqMap[ValueMap[key].second].push_back(key);
    ItMap[key] = --FreqMap[ValueMap[key].second].end();

    if (FreqMap[MinFreq].empty()) {
      MinFreq++;
    }

    return value;
  }

  void put(int key, int value) {
    if (size > 0) {
      int value_in_map = get(key);
      if (value_in_map != -1) {
        ValueMap[key].first = value;
        return;
      }

      if (now >= size) {
        int delete_key = FreqMap[MinFreq].front();
        ItMap.erase(delete_key);
        ValueMap.erase(delete_key);
        FreqMap[MinFreq].pop_front();
        now--;
      }

      ValueMap[key] = {value, 1};
      FreqMap[1].push_back(key);
      ItMap[key] = --FreqMap[1].end();
      MinFreq = 1;
      now++;
    }
  }

 private:
  int now;
  int size;
  int MinFreq;
  unordered_map<int, pair<int, int>> ValueMap;    // key--{value, freq}
  unordered_map<int, list<int>::iterator> ItMap;  // key--iterator
  unordered_map<int, list<int>> FreqMap;          // freq--list
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
