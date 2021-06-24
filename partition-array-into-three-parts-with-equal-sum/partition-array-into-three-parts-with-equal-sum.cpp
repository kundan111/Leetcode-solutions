class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
       
        int arr_sum = accumulate(arr.begin(),arr.end(),0);
        int sz = arr.size();
        if(arr_sum % 3 != 0)
            return false;
        
        int perPartSum = arr_sum/3;
        int part = 0;
        int count = 0;
        
         for (int num : arr) {
             if(count == 2)
                 return true;
            part += num;
            if (part == perPartSum) {
                part = 0;
                count++;
                
            }
        }
        
        return false;
}
        
    
};