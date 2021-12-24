#include "student_record.cc"

template <typename K, typename V>
class HashTable {
public:
    void add(K key, V value);
    V get(int key);
    void clear();
    int size();
};
