class Solution {
public:
  int countVowelStrings(int n) {
        if(n==1)
            return 5;
        if(n==2)
            return 15;
      
      vector<int> temp = {5,4,3,2,1};
      n = n -2;
      
      while(n)
      {
          int sum = accumulate(temp.begin(),temp.end(),0);
          int curSz = temp.size();
          temp.push_back(sum);
          int prev = 0;
          for(int i = 0; i < curSz-1; i++)
          {
              int curVal = sum - (temp[i] + prev);
              prev = temp[i] + prev;
              temp.push_back(curVal);
          }
          temp.erase(temp.begin(),temp.begin()+curSz);
          n--;
      }
      
      return accumulate(temp.begin(),temp.end(),0);  
      
  }
    
    
};