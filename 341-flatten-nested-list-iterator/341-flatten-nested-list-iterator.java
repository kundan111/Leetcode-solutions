/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {

    List<Integer> res = new ArrayList<>();
    int start = -1;

    public NestedIterator(List<NestedInteger> nestedList) {

        for (int i = 0; i < nestedList.size(); i++) {
            dfs(nestedList.get(i), i);
        }
        
    }
    

    @Override
    public boolean hasNext() {
        return start+1 < res.size();
    }

    @Override
    public Integer next() {

        return res.get(++start);
    }

    void dfs(NestedInteger nestedInteger, int curIndex)
    {
      // check if contain single integer or list of interger
      if(nestedInteger.isInteger())
      {
          res.add(nestedInteger.getInteger());
        //   System.out.println(nestedInteger.getInteger());
          return;
      }

      List<NestedInteger> list = nestedInteger.getList();

      for (int i = 0; i < list.size(); i++) {
          dfs(list.get(i), i);
      }

    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */