class Solution {
    public int maxOperations(int[] nums, int k) {


        HashMap<Integer, Integer> freqHash = buildHash(nums);

        int res = 0;
        
        for (java.util.Map.Entry<Integer, Integer> e: freqHash.entrySet()) {
            
            int curVal = e.getKey();
            int searhingFor = k - curVal;

            if(freqHash.get(curVal) <= 0)
            {
                continue;
            }

            if(searhingFor == curVal)
            {
                int curFreq = freqHash.get(curVal);
                if( curFreq > 1)
                {
                    if(curFreq % 2 == 1)
                    {
                        // odd
                        freqHash.put(curVal, 1);

                    }else{
                        // even
                        freqHash.put(curVal,0);
                    }
                    // make pairs
                    res += curFreq/2;
                }
            }else{

                if(freqHash.containsKey(searhingFor))
                {

                    int toAdd = Math.min(freqHash.get(curVal), freqHash.get(searhingFor));
                    res += toAdd;
                    freqHash.put(curVal, freqHash.get(curVal)-toAdd);
                    freqHash.put(searhingFor, freqHash.get(searhingFor)-toAdd);
                    
                    
                }
                
                // both are different

            }
        }




        return res;
        
    }

    HashMap<Integer,Integer> buildHash(int[] nums)
    {
        HashMap<Integer,Integer> hm = new HashMap<>();

        for (int key : nums) {
            if(hm.containsKey(key))
            {
                int val = hm.get(key);
                hm.put(key, val+1);
            }else{
                hm.put(key, 1);
            }
        }
        
        return hm;
    }


}