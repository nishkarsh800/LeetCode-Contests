class Solution {
public:

/*
Two pointer approach. Compare characters in both the strings one by one and if they matches increment 
the counter and return the ans by subtracting it from other string size.

TIME COMPLEXITY : O(N)
SPACE COMPLEXITY : O(1)
*/ 
    int appendCharacters(string s, string t)
    {
          int j=0;
        
           for(int i=0; i<s.size(); i++)
           {
               if(s.at(i) == t.at(j))
                   j++;
               if(j == t.size()) return 0;
           } 
    
          return t.size()-j;
    }
};