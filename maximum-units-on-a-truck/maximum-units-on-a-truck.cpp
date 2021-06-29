class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comparator);
        int curBoxes = 0;
        int i = 0;
        int res = 0;
        while(i < boxTypes.size() && curBoxes < truckSize)
        {
            while(i < boxTypes.size() && boxTypes[i][0] > 0 && curBoxes < truckSize)
            {
                  curBoxes = curBoxes +  1;
                  res  = res + boxTypes[i][1];
                  boxTypes[i][0] = boxTypes[i][0] - 1;
                
            }
            i++;
        }
        
        
        return res;
        
    }
    static bool comparator(vector<int>a,vector<int>b)
    {
        return a[1] > b[1];
    }
};