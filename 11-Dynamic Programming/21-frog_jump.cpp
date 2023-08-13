class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int , unordered_set<int>> map;    
        map[stones[0] + 1] = {1};       
        for(int i = 1 ; i < stones.size() ; ++i){      
            int position = stones[i];               
            for(auto it : map[position]){           
                map[position + it].insert(it);      
                map[position + it + 1].insert(it + 1);
                map[position + it - 1].insert(it - 1);
            }
        }
        return map[stones.back()].size() != 0;    
    }
};