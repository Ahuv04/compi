// https://leetcode.com/problems/insert-delete-getrandom-o1/
//380. Insert Delete GetRandom O(1)
class RandomizedSet {

private:
    unordered_map<int, int> pos;
    vector<int> nums;

public:
    RandomizedSet()
    :pos{}
    ,nums{}
    {
        
    }
    
    bool insert(int val) {
        
        if(pos.find(val)!=pos.end())
        {   return false;

        }
        else{
            nums.push_back(val);
            pos[val]=nums.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(pos.find(val)==pos.end())
        {   return false;}
        else{
            nums[pos[val]]=nums[nums.size()-1];
            pos[nums[pos[val]]]=pos[val];
            pos.erase(val);
            nums.pop_back();
            return true;
        }
    }
    
    int getRandom() {
        int rn=rand()%nums.size();
        return nums[rn];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */