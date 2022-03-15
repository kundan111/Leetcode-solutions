class Solution {
    public int[] plusOne(int[] digits) {
        
        
        int carry = 0;
        int len = digits.length;
        for (int i = digits.length - 1; i >= 0; i--) {
            
            int newVal; 

            if(i == digits.length - 1)
            {
                newVal = (digits[i] + carry + 1);
            }else{
                newVal = (digits[i] + carry );
            }
            if(newVal > 9)
            {
                carry = 1;
            }else{
                carry = 0;
            }
            digits[i] = newVal % 10;
        }

        if(carry == 0)
        {
            return digits;
        }else
        {
            int[] ret = new int[len+1];
            ret[0] = 1;
            for (int i = 0; i < digits.length; i++) {
                ret[i+1] = digits[i];
            }

            return ret;
            
        }
        
    }
}