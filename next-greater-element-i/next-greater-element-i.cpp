class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        
        
        
        
        vector<int> res(nums1.size());
        int sz = nums2.size();
        
        unordered_map<int,int>m;
        stack<int>s;
        
        for(int i = sz-1; i >=0 ; i--)
        {
            if(s.size() == 0)
            {
                m[nums2[i]] = -1;
                s.push(nums2[i]);
            }else if(s.size() && s.top() > nums2[i])
            {
                m[nums2[i]] = s.top();
                s.push(nums2[i]);
            }else if(s.size() && s.top() <= nums2[i])
            {
                while(s.size() && s.top() <= nums2[i])
                {
                    s.pop();
                    
                }
                
                if(s.size() == 0)
                {
                    m[nums2[i]] = -1;
                }else{
                    m[nums2[i]] = s.top();
                }
                s.push(nums2[i]);
            }
        }
        
        int cur = 0;
        for(int v : nums1)
        {
            res[cur] = m[v];
            cur++;
        }
        
        
        return res;
        
    }
};