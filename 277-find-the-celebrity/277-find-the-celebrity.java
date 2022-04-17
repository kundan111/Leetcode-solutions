/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

public class Solution extends Relation {
    
    int totalNumberofPeopleAtParty;
    
    public int findCelebrity(int n) {
        return approach2(n);
    }
    
    public int approach2(int n) {
        this.totalNumberofPeopleAtParty = n;
        
        int candidate = 0;

        for (int i = 0; i < n; i++) {
            
            if(candidate == i)
            {
                continue;
                
            }
            
            if(knows(candidate, i))
            {
                // candidate no longer remains the candidate for celebrity
                candidate = i;
            }
        }
        
        if(isCelebrity(candidate))
        {
            return candidate;
        }
        
        return -1;
    }
    
    boolean isCelebrity(int candidate)
    {
        for (int i = 0; i < totalNumberofPeopleAtParty; i++) {
            if(i != candidate)
            {
                if(knows(candidate,i) || !knows(i, candidate))
                {
                    return false;
                }
            }
        }

        return true;
    }
}