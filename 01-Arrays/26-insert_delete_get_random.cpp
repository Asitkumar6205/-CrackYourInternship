class RandomizedCollection {
public:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> map; //val: {index in arr}
    
    RandomizedCollection() {}
    
    bool insert(int val) {
        arr.push_back(val);
        map[val].insert(arr.size()-1);
        return map[val].size() <= 1;
    }
    
    bool remove(int val) {
        if(map[val].size()==0) return false;
        int ind= *map[val].begin();
        map[val].erase(ind);
        
        int num= arr.back();
        swap(arr[ind], arr[arr.size()-1]);
        map[num].insert(ind);
        map[num].erase(arr.size()-1);
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};