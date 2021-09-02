class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int startingIndexOfZero = nums[0] == 0 ? 0 : 1;
        vector<int> decoded;
        numsDecoder(nums,decoded);
        
        
        int maxLen = -1;
        int sz = decoded.size();
        
        if(sz == 1 && startingIndexOfZero == 1)
        {
            return decoded[0];
        }
        
        // for(int val: decoded)
        // {
        //     cout << val << " ";
        // }
        
        
        // cout << endl;
        
        for(int i = startingIndexOfZero; i < sz; i = i + 2)
        {
            int temp = flipZeros(decoded,i,k);
            // cout << "temp: " << temp << endl;
            maxLen = max(temp,maxLen);
        }
        
        
        return maxLen;
         
    }
    
    void numsDecoder(vector<int>& nums,vector<int> &decoded)
    {
        
        int i = 0;
        int sz = nums.size();
        
        while( i < sz)
        {
            int count = 0;
            int curBit = nums[i];
            
            int j = i;
            
            while(j < sz && nums[j] == curBit)
            {
                count++;
                j++;
            }
            decoded.push_back(count);
            i = j;
        }
    }
    
    int flipZeros(vector<int> &decoded, int index, int k)
    {
         
        int sz = decoded.size();
        int maxLenWecanGet = 0;
        
        if(decoded[index] > k)
        {
            int Possibleleft = 0;
            int PossibleRight = 0;
            if(index - 1 >= 0)
            {
                Possibleleft = decoded[index - 1];
            }
            
            if(index+1 < sz)
            {
                PossibleRight = decoded[index + 1];
            }
            
            if(Possibleleft && PossibleRight)
            {
                return max(Possibleleft,PossibleRight) + k;
            }else if(Possibleleft && PossibleRight == 0){
                return Possibleleft + k;
            }else if(PossibleRight && Possibleleft == 0)
            {
                return k + PossibleRight;
            }else{
                return k;
            }
        }
        
        int oriIndex = index;
        if(index - 1 >= 0)
        {
            maxLenWecanGet = decoded[index-1];
        }
        bool flag = true;
        while(index < sz && k)
        {
            if(decoded[index] <= k){
                flag = false;
                maxLenWecanGet += decoded[index];
                k -= decoded[index];
                if(index + 1 < sz)
                {
                    maxLenWecanGet += decoded[index + 1];
                }
                index += 2;
                    
            }else{
                if(!flag)
                {
                    maxLenWecanGet += k;
                    k = 0;    
                }
                
            }
        }
        
        while(k && oriIndex-2 >=0)
        {
            oriIndex -= 2;
            if(decoded[oriIndex] >= k)
            {
                maxLenWecanGet += k;
                k=0;
            }else{
                maxLenWecanGet += decoded[oriIndex];
                k -= decoded[oriIndex];
            }
        }
        
        return maxLenWecanGet;
        
           
    }
};