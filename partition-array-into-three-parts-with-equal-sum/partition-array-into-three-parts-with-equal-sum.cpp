class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
       
        int arr_sum = accumulate(arr.begin(),arr.end(),0);
        int sz = arr.size();
        if(arr_sum % 3 != 0)
            return false;
        
        int perPartSum = arr_sum/3;
        int part = 0;
        int count = 0;
        
         for (int num : arr) {
            part += num;
            if (part == perPartSum) {
                part = 0;
                count++;
                if (count == 3) {
                    return true;
                }
            }
        }
        
        return false;
}
        
    
};