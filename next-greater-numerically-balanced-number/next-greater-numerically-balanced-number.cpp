class Solution {
public:
    int base[13] = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666};
    int nextBeautifulNumber(int n) {
    int res = 1224444;
    string s = to_string(n);
    for (int nn : base) {
        string ss = to_string(nn);
        if (ss.size() < s.size())
            continue;
        if (ss.size() > s.size())
            res = min(res, nn);
        else
            do {
                if (ss > s)
                // {   cout << "ss: " << ss << endl;
                    res = min(res, stoi(ss));
                // }  
            } while(next_permutation(begin(ss), end(ss)));
        // cout << "nn: " << nn << endl << "res: " << res << endl;
    }
    return res;
}
};

