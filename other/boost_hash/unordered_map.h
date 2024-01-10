#include <boost/unordered/concurrent_flat_map.hpp>

#define USE_SET

template <typename K,
          typename V,
          class Hash = std::hash<K>,
          class KeyEqual = std::equal_to<K>>
struct unordered_map {
  using Table = boost::concurrent_flat_map<K, V, Hash, KeyEqual>;

  Table table;

  std::optional<V> find(const K& k) {
    std::optional<V> result;
    table.visit(k, [&](auto&& x) { result = x.second; });
    return result;
  }

  bool insert(const K& k, const V& v) {
    return table.emplace(k, v);
  }

  bool remove(const K& k) {
    return table.erase(k);
  }

  unordered_map(size_t n) {
    table.reserve(n);
  }

  long size() {return table.size();}
};


template <typename K,
	  class Hash = std::hash<K>,
	  class KeyEqual = std::equal_to<K>>
struct unordered_set {
  using Set = boost::concurrent_flat_map<K, bool, Hash, KeyEqual>;
  Set set;
  bool find(const K& k) { return set.count(k) > 0;}
  bool insert(const K& k) { return set.emplace(k,true); }
  bool remove(const K& k) { return set.erase(k); }
  unordered_set(size_t n) { }
  long size() {return set.size();}
};
