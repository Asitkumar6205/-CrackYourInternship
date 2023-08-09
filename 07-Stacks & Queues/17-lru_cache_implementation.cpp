class LRUCache {
private:
    int capacity;
    list<pair<int, int>> dq; // Doubly linked list to store key-value pairs in order of usage
    unordered_map<int, list<pair<int, int>>::iterator> mp; // Hash map to store key-node mappings

public:
    // Constructor to initialize the cache with a given capacity
    LRUCache(int cap) {
        capacity = cap;
    }

    // Function to get the value corresponding to the key from the cache
    int GET(int key) {
        // If the key is present in the cache
        if (mp.find(key) != mp.end()) {
            auto cacheNode = mp[key];

            // Move the accessed node to the front (most recently used) of the linked list
            dq.splice(dq.begin(), dq, cacheNode);

            // Return the value corresponding to the key
            return cacheNode->second;
        }
        
        // If the key is not present in the cache, return -1
        return -1;
    }

    // Function to store a key-value pair in the cache
    void SET(int key, int value) {
        // If the key is already present in the cache
        if (mp.find(key) != mp.end()) {
            auto cacheNode = mp[key];

            // Update the value of the existing node
            cacheNode->second = value;

            // Move the updated node to the front (most recently used) of the linked list
            dq.splice(dq.begin(), dq, cacheNode);
        } 
        
        // If the key is not present in the cache
        else {
            // If the cache has reached its maximum capacity, remove the least recently used node (tail node)
            if (dq.size() == capacity) {
                auto lastNode = dq.back();
                mp.erase(lastNode.first);
                dq.pop_back();
            }

            // Add the new key-value pair to the front (most recently used) of the linked list and update the hash map
            dq.push_front(make_pair(key, value));
            mp[key] = dq.begin();
        }
    }
};
