class FindSumPairs {

    private:
        vector<int> f;
        vector<int> s;
        unordered_map<int,int>m;
    public:
        FindSumPairs(vector<int>& nums1, vector<int>& nums2) {

            f = nums1;
            s = nums2;

            for(int &val: s)
            {
                m[val]++;
            }
        }

        void add(int index, int val) {
            int prev = s[index];
            s[index] += val;   
            
            m[prev]--;
            if(m[prev] == 0)
            {
                m.erase(prev);
            }
            
            m[s[index]]++;
        }

        int count(int tot) {
            int res = 0;
            for(int &val: f)
            {
                if(tot-val < 0)
                {
                    continue;
                    
                }
                
                auto itr = m.find(tot-val);
                if( itr != m.end())
                {
                    res = res + itr->second; 
                }
            }

            return res;


        }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */