#ifndef PANIC_BOOKSTORE_BPTREE_H_
#define PANIC_BOOKSTORE_BPTREE_H_

#include <ak/file/bptree.h>

template <typename KeyType, typename ValueType, size_t szChunk = ak::file::kDefaultSzChunk>
class BpTree {
 private:
  ak::file::BpTree<KeyType, ValueType, szChunk> store_;
 public:
  BpTree () = delete;
  BpTree (const char *filename) : store_(filename) {}
  void add (const KeyType &key, const ValueType &value) {
    store_.insert(key, value);
  }
  void del (const KeyType &key, const ValueType &value) {
    store_.remove(key, value);
  }
  // 检查树中是否有 (key, value)
  bool find (const KeyType &key, const ValueType &value) {
    return store_.includes(key, value);
  }
  void query (const KeyType &key, std::vector<ValueType> &result) {
    result = store_.findMany(key);
  }
  void queryAll (std::vector<std::pair<KeyType, ValueType>> &result) {
    result = store_.findAll();
  }
  void clearCache () {
    store_.clearCache();
  }
};

#endif
