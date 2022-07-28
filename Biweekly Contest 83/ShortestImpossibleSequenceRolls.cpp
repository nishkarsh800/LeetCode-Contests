class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int len = 1;
        set<int> sequence;
        
        for (int i = 0; i < rolls.size(); i++) {
            sequence.insert(rolls[i]);
            
            if (sequence.size() == k) {
                len++;
                sequence = set<int>();
            }
        }
        
        return len;
    }
};
