class NumberContainers {
public:
    
    unordered_map<int,int>m1;//index : number
    unordered_map<int,set<int>>m2;// number : [indices]
    
    NumberContainers()
    {
        
    }
    
    void change(int index, int number)
    {
        //if we are already having a number at index position
        //then we need to replace it in m1 and remove its index from m2
        //after that we'll also have to add the index of current number in m2
        if(m1.find(index) != m1.end())
        {
            int prev = m1[index];//the previous value at index in m1
            m2[prev].erase(index);   
        }
        m1[index] = number;
        m2[number].insert(index);
    }
    
    int find(int number) 
    {
        return m2[number].empty() ? -1 : *m2[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */