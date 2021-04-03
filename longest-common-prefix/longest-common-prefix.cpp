class Solution {

public:
    bool static comparator(string s1, string s2)
    {
        return s1.size() < s2.size();
    }
    
    vector<string> custom_sorter(vector<string>& arr)
    {
        sort(arr.begin(), arr.end(), comparator);
        return arr;
    }
    
    string longestCommonPrefix(vector<string>& arr) {
        int arr_size = arr.size();
        if(arr_size == 0)
        {
            return "";
        }
        
        
        arr = custom_sorter(arr); //nlog(n)
        

        bool breakItHere = true;
        
        

        if(arr_size == 1)
        {
            return arr[0];
        }


        // take the smallest size 1.e first element
        string smallestString = arr[0];
        int smallestStringLength = arr[0].size();


        //return lcp
        string lcp = "";

        for(int i = 0; i < smallestStringLength; i++)
        {
            char cur_char = smallestString[i];

            // Now check for this character in every other strings in the array
            int j = 1;
            while(j < arr_size)
            {
                if(cur_char != arr[j][i])
                {
                    breakItHere = false;
                    break;
                }
                j++;
            }

            if(!breakItHere)
            {
                break;
            }

            lcp += cur_char;
        }



        return lcp;
    }
};