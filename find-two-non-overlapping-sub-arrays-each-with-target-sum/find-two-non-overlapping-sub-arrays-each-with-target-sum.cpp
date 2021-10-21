class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        unordered_map<int,int>hmap;
        int sum=0,lsize=INT_MAX,result=INT_MAX;
        hmap[0] = -1;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            hmap[sum] = i; 
        }
        sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(hmap.count(sum-target)){
                lsize= min(lsize,i-hmap[sum-target]);      
            }
			
            if(hmap.count(sum+target) && lsize<INT_MAX){
                result= min(result,hmap[sum+target]-i+lsize); 
            }
            
            // cout << "i: " << i << endl  << "lsize: " << lsize << endl << "rsize: " << hmap[sum+target]-i << endl << "result: " << result << endl << endl;
        }
        return result==INT_MAX?-1:result;
    }
    
    
};