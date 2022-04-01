class Solution {
    public void sortColors(int[] arr) {
        int sz = arr.length;
        
        int low = 0;
        int mid = 0;
        int high = sz-1;

        while(mid <= high)
        {
            if(arr[mid] == 0)
            {
                swap(arr,low++,mid++);
                
            }else if(arr[mid] == 1)
            {
                mid++;
            }else{
                swap(arr,mid,high);
                high--;
            }
        }
    }
    void swap(int[] arr, int i, int j)
        
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}