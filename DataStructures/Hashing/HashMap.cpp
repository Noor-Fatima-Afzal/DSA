#include <iostream>
#include <list>
#include <cmath>
using namespace std;

template <typename K, typename V>
class HashMap {
private:
    class Node {
    public:
        K key;
        V value;

        Node(K key, V value) {
            this->key = key;
            this->value = value;
        }
    };

    int n; // number of nodes
    int N; // number of buckets
    list<Node>** buckets; // array of linked lists (pointer to pointer)

    int hashFunction(K key) {
        int bi = 0;
        for (int i = 0; i < key.length(); i++) {
            bi += key[i];
        }
        return abs(bi) % N;
    }

    int searchInLL(K key, int bi) {
        int idx = 0;
        for (typename list<Node>::iterator it = buckets[bi]->begin(); it != buckets[bi]->end(); ++it) {
            if (it->key == key) {
                return idx;
            }
            idx++;
        }
        return -1;
    }

    void rehash() {
        list<Node>** oldBuckets = buckets;
        int oldN = N;

        N = N * 2; // Double the number of buckets
        buckets = new list<Node>*[N];
        for (int i = 0; i < N; i++) {
            buckets[i] = new list<Node>();
        }
        n = 0;

        // Rehash the old elements into the new buckets
        for (int i = 0; i < oldN; i++) {
            list<Node>* ll = oldBuckets[i];
            for (auto node : *ll) {
                put(node.key, node.value); // Re-insert each element
            }
            delete ll; // Free old list memory
        }
        delete[] oldBuckets; // Free the old array of buckets
    }

public:
    HashMap() {
        N = 4;  // Initial bucket size
        n = 0;  // Initial number of elements
        buckets = new list<Node>*[N];
        for (int i = 0; i < N; i++) {
            buckets[i] = new list<Node>();
        }
    }

    void put(K key, V value) {
        int bi = hashFunction(key);
        int di = searchInLL(key, bi);

        if (di == -1) {
            buckets[bi]->push_back(Node(key, value)); // Insert new element
            n++;
        } else {
            // Manually iterate through the list to find the matching key
            list<Node>& bucket = *buckets[bi];
            int idx = 0;
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                if (idx == di) {
                    it->value = value;
                    return;
                }
                ++idx;
            }
        }

        // Check load factor and rehash if needed
        double lambda = (double)n / N;
        if (lambda > 2.0) {
            rehash();
        }
    }

    bool containsKey(K key) {
        int bi = hashFunction(key);
        int di = searchInLL(key, bi);

        return (di != -1); // Key exists if found in linked list
    }

    V remove(K key) {
        int bi = hashFunction(key);
        int di = searchInLL(key, bi);

        if (di == -1) {
            return V(); // Return default value if key not found
        } else {
            // Manually iterate through the list to find the matching key
            list<Node>& bucket = *buckets[bi];
            int idx = 0;
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                if (idx == di) {
                    V val = it->value; // Save value before removal
                    bucket.erase(it);  // Remove the element
                    n--;
                    return val;
                }
                ++idx;
            }
        }
        return V();
    }

    V get(K key) {
        int bi = hashFunction(key);
        int di = searchInLL(key, bi);

        if (di == -1) {
            return V(); // Return default value if key not found
        } else {
            // Manually iterate through the list to find the matching key
            list<Node>& bucket = *buckets[bi];
            int idx = 0;
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                if (idx == di) {
                    return it->value; // Return value
                }
                ++idx;
            }
        }
        return V();
    }

    K* keySet(int& keyCount) {
        keyCount = 0;
        for (int i = 0; i < N; i++) {
            keyCount += buckets[i]->size(); // Count total keys
        }

        K* keys = new K[keyCount]; // Array to store keys
        int idx = 0;
        for (int i = 0; i < N; i++) {
            list<Node>& bucket = *buckets[i];
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                keys[idx++] = it->key; // Store key in array
            }
        }
        return keys;
    }

    bool isEmpty() {
        return n == 0; // Map is empty if no elements
    }

    ~HashMap() {
        for (int i = 0; i < N; i++) {
            delete buckets[i]; // Free memory for each list
        }
        delete[] buckets; // Free memory for the array of buckets
    }
};

int main() {
    HashMap<string, int> map;
    map.put("India", 190);
    map.put("China", 200);
    map.put("US", 50);

    int keyCount;
    string* keys = map.keySet(keyCount);
    for (int i = 0; i < keyCount; i++) {
        cout << keys[i] << " " << map.get(keys[i]) << endl;
    }
    delete[] keys; // Free memory

    map.remove("India");
    cout << map.get("India") << endl; // Should print 0 (default int value)

    return 0;
}
