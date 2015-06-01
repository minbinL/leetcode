//O(n)
class Solution1 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	if (k <= 0 || nums.size() < 2 || t < 0) return false;
    	unordered_map<int, int> um; 
    	int first_idx(0);
    	for (int i = 0; i < nums.size(); i++) {
    		int j = t == 0 ? nums[i] : nums[i] / t;
    		if (um.find(j) != um.end() || 
				(um.find(j-1) != um.end() && abs((long long)um[j-1] - (long long)nums[i]) <= t) || 
				(um.find(j+1) != um.end() && abs((long long)um[j+1] - (long long)nums[i]) <= t) ) return true;
			if (um.size()==k) {
				if (t == 0) um.erase(nums[first_idx]);
				else um.erase(nums[first_idx]/t);
				first_idx++;
			}
			um[j] = nums[i];
		}
		return false;
	}
};

//O(nlogk)
class Solution2 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	if (k <= 0 || nums.size() < 2 || t < 0) return false;
    	set<int> s;
    	int first_idx;
    	for (int i = 0; i < nums.size(); i++) {
    		if (s.size() == 0) 
			{
				s.insert(nums[i]);
				first_idx = 0;
			}
			else if (s.size() < k) {
				if ( abs( (long long)(*s.begin())-(long long)nums[i]) <= t || abs( (long long)(*s.rbegin())-(long long)nums[i]) <= t) return true;
				s.insert(nums[i]);
			}
			else {
				if ( abs( (long long)(*s.begin())-(long long)nums[i]) <= t || abs( (long long)(*s.rbegin())-(long long)nums[i]) <= t) return true;
				s.erase(nums[first_idx]);
				first_idx++;
				s.insert(nums[i]);
			}
		}
		return false;
    }
};
