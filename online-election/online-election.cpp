class TopVotedCandidate {
private:
    vector<int>persons1;
    vector<int>times1;
    vector<int>rel;
    vector<int>temp;
    int max_time;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        persons1 = move(persons);
        times1 = move(times);
        int sz = times1.size();
        
        temp.resize(sz);
        rel.resize(sz);
        int mx = INT_MIN;
        int max_cand;
        for(int i = 0; i < sz; i++)
        {
            temp[persons1[i]]++;
            
            if(temp[persons1[i]] >= mx)
            {
                mx = temp[persons1[i]];
                rel[i] = persons1[i];
                max_cand = persons1[i];
            }else{
                rel[i] = max_cand;
            }
            
        }
        
//         for(int i = 0; i < sz;i++)
//         {
//             cout << i << " -> " << rel[i] << endl;
//         }
        
        
    }
    
    int q(int t) {
        int time = bs(times1,t);
        return rel[time];
    }
    
    
   int bs(vector<int>& times1, int target)
    {
        int sz = times1.size();
        int l = 0;
        int r = sz-1;
        
        int ret;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            int curVal = times1[mid];
            if( curVal == target)
            {
                return mid;
            }else if(curVal < target)
            {
                ret = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ret;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */