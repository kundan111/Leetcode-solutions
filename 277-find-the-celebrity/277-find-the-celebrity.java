/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

public class Solution extends Relation {
    public int findCelebrity(int n) {
        return approach1(n);
        
    }
    
    
    public int approach1(int n) {
        
        int celebrity = -1;
        int maxCount = 0;
        for (int i = 0; i < n; i++) {
            
            int curCandidate = i;
            int curCount = 0;
            for (int j = 0; j < n; j++) {

                if(j != curCandidate)
                {
                    if(knows(j, curCandidate))
                    {
                        curCount++;
                        if(curCount > maxCount)
                        {
                            maxCount = curCount;
                            celebrity = curCandidate;
                        }
                    }

                }
            }
        }
        
        return maxCount == n-1 ? (checkIfCelebrityKnowsAnyoneelse(celebrity, n) ? -1 : celebrity) : -1;
    }
    
    
    boolean checkIfCelebrityKnowsAnyoneelse(int celebrity, int n)
    {
        for (int i = 0; i < n; i++) {
            if(celebrity != i)
            {
                if(knows(celebrity, i))
                {
                    return true;
                    
                }
            }
        }

        return false;
    }
}