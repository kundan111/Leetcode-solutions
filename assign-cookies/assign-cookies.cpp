class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        priority_queue <int, vector<int>, greater<int> > bookh;
        priority_queue <int, vector<int>, greater<int> > khana;
        
        for(auto b: g)
            bookh.push(b);
        
        for(auto k: s)
            khana.push(k);
        
        int res = 0;
        while(!khana.empty() && !bookh.empty())
        {
            int curKhana = khana.top();
            int curBookh = bookh.top();
            if(curKhana < curBookh )
            {
                khana.pop();
            }else{
                khana.pop();
                bookh.pop();
                res++;
            }
        }
        
        
        return res;
    }
};