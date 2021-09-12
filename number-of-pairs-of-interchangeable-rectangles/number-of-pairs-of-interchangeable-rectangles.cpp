class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        map<pair<int, int>, int> mp;
        long long result = 0;
        
        for(int i = 0; i <n; i++) {
            int gcd = __gcd(rectangles[i][0],rectangles[i][1]);
            
            // cout << "gcd: " << gcd ;
            
            //Have I seen this pair
            if(mp.find({rectangles[i][0]/gcd, rectangles[i][1]/gcd}) != end(mp))
                result += mp[{rectangles[i][0]/gcd, rectangles[i][1]/gcd}];
            
            // cout << " result: " << result << endl;

            //Increase the count
            mp[{rectangles[i][0]/gcd, rectangles[i][1]/gcd}]++;
        }
        
        /*for(auto &val: mp)
        {
            cout << "(" << val.first.first << "," << val.first.second << ") " << " => " << val.second << endl;
        }
        */
        
        
        return result;
    }
};