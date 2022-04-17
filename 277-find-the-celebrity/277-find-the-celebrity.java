/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

public class Solution extends Relation {
    
    int totalNumberofPeopleAtParty;
    
    public int findCelebrity(int n) {
        return approach1(n);
    }
    
    public int approach1(int n) {

        this.totalNumberofPeopleAtParty = n;
        
        for (int i = 0; i < n; i++) {
            if(isCelebrity(i))
            {
                return i;
            }
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