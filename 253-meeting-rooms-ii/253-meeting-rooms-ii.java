class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int[] startArr = new int[intervals.length];
        int[] endArr = new int[intervals.length];

        for (int i = 0; i < endArr.length; i++) {
            startArr[i] = intervals[i][0];
            endArr[i] = intervals[i][1];
        }

        Arrays.sort(startArr);
        Arrays.sort(endArr);

        int roomCount = 0;
        int i = 0;
        int j = 0;

        while (i < intervals.length) {
            if(startArr[i] < endArr[j])
            {
                roomCount++;
                i++;
            }else{
                i++;
                j++;
            }
        }

        
        return roomCount;
    }
}