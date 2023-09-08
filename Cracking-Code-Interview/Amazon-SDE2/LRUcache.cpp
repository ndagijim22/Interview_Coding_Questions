//Source: https://www.interviewkickstart.com/problems/lru-cache
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

/*
* Asymptotic complexity in terms of size of input arrays(number of operations) \`n\` and \`capacity\`:
* Time: O(n).
* Auxiliary space: O(min(capacity, n)).
* Total space: O(n).
*/

class LRU_cache
{
    int capacity;

    // Doubly linked list that stores {key, value} pairs.
    list<pair<int, int>> actual_storage;

    // key -> pointer to the linked list node.
    unordered_map<int, list<pair<int, int>>::iterator> key_to_actual_storage_mapping;

public:

    LRU_cache(int _capacity)
    {
        capacity = _capacity;
    }

    /*
    Add {key, value} to the front of the linked list.
    Also add the mapping (key -> pointer to where it is stored in linked list).
    That is, (key -> head of the linked list).
    */
    void add_to_front(int key, int value)
    {
        actual_storage.push_front({key, value});
        key_to_actual_storage_mapping[key] = actual_storage.begin();
    }

    /*
    Remove one {key, value} from the tail of the linked list.
    Also remove the mapping (key -> pointer to where it is stored in the linked list).
    */
    void remove_least_recently_used()
    {
        int key = actual_storage.back().first;
        key_to_actual_storage_mapping.erase(key);
        actual_storage.pop_back();
    }

    // If a value for the given key is cached, makes it the MRU and returns it; else returns -1.
    int get(int key)
    {
        unordered_map<int, list<pair<int, int>>::iterator>::iterator it =
            key_to_actual_storage_mapping.find(key);

        if (it == key_to_actual_storage_mapping.end())
        {
            // Key isn't found.
            return -1;
        }

        // it->second points to node in the linked list; let's get its value.
        int value = it->second->second;
        // Remove from the original position.
        actual_storage.erase(it->second);
        // Add to the front of the list.
        add_to_front(key, value);
        return value;
    }

    // Adds or updates the cached value for the given key.
    // Evicts the LRU cached value if necessary to avoid exceeding capacity of the cache.
    // Makes the newly added/updated cache entry the MRU one.
    void set(int key, int value)
    {
        unordered_map<int, list<pair<int, int>>::iterator>::iterator it =
            key_to_actual_storage_mapping.find(key);

        if (it == key_to_actual_storage_mapping.end())
        {
            // The key isn't found in the cache; so it needs to be added.
            if (key_to_actual_storage_mapping.size() == capacity)
            {
                // Cache is at capacity. Let's evict the LRU element.
                remove_least_recently_used();
            }
            // Add the key->value to the cache.
            add_to_front(key, value);
        }
        else
        {
            // Key is found in the cache; so we need to update the value and make it the MRU.
            // Remove it from the original position in the list.
            actual_storage.erase(it->second);
            // Add to the front of the list and to the hashmap.
            add_to_front(key, value);
        }
    }
}; // class LRU_cache

vector<int> implement_lru_cache(int capacity, vector<int> &query_type, vector<int> &key, vector<int> &value)
{
    int n = query_type.size();
    // Setup cache.
    LRU_cache* cache = new LRU_cache(capacity);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (query_type[i] == 0)
        {
            ans.push_back(cache->get(key[i]));
        }
        else
        {
            cache->set(key[i], value[i]);
        }
    }
    return ans;
}