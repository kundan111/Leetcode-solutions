class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // find the maxm
        int i = 0;
        int maxi = INT_MIN;
        int childerenCount = candies.size();
        while(i<childerenCount)
        {
            int choclate_val = candies[i];
            if(choclate_val > maxi)
            {
                maxi = choclate_val;
            }
            i++;
        }
        
        vector<bool> res;
        for(int i = 0; i < childerenCount ; i++)
        {
            int choclate_val = candies[i];
            if(choclate_val + extraCandies >= maxi)
            {
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        
        return res;
        
        
    }
};