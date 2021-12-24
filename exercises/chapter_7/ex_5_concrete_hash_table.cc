#include "student_record.cc"
#include <map>

template <typename K, typename V>
class HashTable {
public:
    void add(K key, V value);
    V get(K key);
    void clear();
    int size();

private:
    std::map<K, V> _items;
};

template <typename K, typename V>
void HashTable<K, V>::add(K key, V value)
{
    _items.insert(std::pair<K, V>(key, value));
    // or _items[key] = value;
}

template <typename K, typename V>
V HashTable<K, V>::get(K key)
{
    return _items[key];
    // or _items.at(key);
}

template <typename K, typename V>
void HashTable<K, V>::clear()
{
    _items.clear();
}

template <typename K, typename V>
int HashTable<K, V>::size()
{
    return _items.size();
}

int main(int argc, const char *argv[])
{
    StudentRecord r(10, 1, "one");
    StudentRecord r2(20, 2, "two");
    StudentRecord r3(30, 3, "three");
    StudentRecord r4(40, 4, "four");
    StudentRecord r5(50, 5, "five");
    StudentRecord r6(60, 6, "six");
    StudentRecord r7(70, 7, "seven");

    HashTable<int, StudentRecord> students;
    students.add(r.studentId(), r);
    students.add(r2.studentId(), r2);
    students.add(r3.studentId(), r3);
    students.add(r4.studentId(), r4);
    students.add(r5.studentId(), r5);
    students.add(r6.studentId(), r6);
    students.add(r7.studentId(), r7);

    std::cout << students.get(3).grade() << "\n";
    std::cout << students.get(8).grade() << "\n";

    std::cout << students.size() << "\n";
    students.clear();
}
