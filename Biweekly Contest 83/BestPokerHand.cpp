class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits)
    {
        unordered_map<int,int>mr;
        unordered_map<char,int>ms;
        string ans="";//it will store the final answer
        
        //storing the frequency of all the ranks
        for(auto val:ranks)
            mr[val]++;
        
        //storing frequency of the elements of suits
        for(auto val:suits)
            ms[val]++;
        
        //case 1
        if(ms.size() == 1)
        {
            ans = "Flush";
            return ans;
        }
        
        if(mr.size() == 5)
        {
            ans = "High Card";
            return ans;
        }
        
        for(auto current : mr)
        {
            if(current.second >= 3)
            {
                ans = "Three of a Kind";
                return ans;
            }
        }
        
        ans = "Pair";
        return ans;
    }
};