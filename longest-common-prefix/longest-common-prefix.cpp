class Solution {

public:
    pair<string,int> returnSmallestStringAndItsLength(vector<string> arr)
    {
            pair<string,int> returnVal;
            int i = 0;
            int sz = arr.size();
            int minLength = INT_MAX;
            string smallestString = arr[0];
            while(i < sz)
            {
                if(arr[i].size() < minLength)
                {
                    minLength = arr[i].size();
                    smallestString = arr[i];
                }
                i++;
            }

            returnVal = make_pair(smallestString,minLength);
            return returnVal;
    }
    
    string longestCommonPrefix(vector<string>& arr) {
        int arr_size = arr.size();
    if(arr_size == 0)
    {
        return "";
    }

    if(arr_size == 1)
    {
        return arr[0];
    }

    // sort the array in ascending order of size of string    
    // arr = custom_sorter(arr); //nlog(n)

    pair<string,int> res = returnSmallestStringAndItsLength(arr);
    

    bool breakItHere = true;


    
    // take the smallest size 1.e first element
    string smallestString = res.first;
    int smallestStringLength = res.second;


    //return lcp
    string lcp = "";

    for(int i = 0; i < smallestStringLength; i++)
    {
        char cur_char = smallestString[i];

        // Now check for this character in every other strings in the array
        int j = 0;
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