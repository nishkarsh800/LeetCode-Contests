
## [Best Poker Hand](https://leetcode.com/problems/best-poker-hand/)

#### Approach

- In this question we are having 4 cases :-
                
                i.If all the characters of suits vector are same the return "Flush"
                
                ii.If any of the value in the values in the rank vector has frequency greater than or equal to 3 then return "Three of a Kind"
                
                iii.Else if any of the values in the rank vector has frequency equals to 2 then return "Pair"
                
                iv.Else if all the values in the rank vector are differnt then return "High Card"

1. Store the frequencies of each elements of rank vector in an unordered map(say mr) and similarly, Store the frequencies of each characters of suits vector in another unordered map(say ms).

2. Take an empty string ans to store the answer.

3. If the size of ms is equal to 1,then it implies that we have all the values same in suits ,so set ans as "Flush" and return ans.

4. If the size of mr is 5,then it implies that we have all distinct values in rank , so set ans as "High Card" and return ans.

5. Otherwise traverse mr and if any of the key is having frequency greater than or equal to 3 ,then set ans as "Three of a Kind" and return ans.

6. If none of the above holds then simply set ans as "Pair" and return it.


#### Time Complexity = O(N)

- Where N = 5,its because the size of rank & suits vector is fixed and is equal to 5.

#### Space Complexity = O(N) + O(N)

- because we are using two unordered maps



## [Shortest Impossible Sequence of Rolls](https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/)

#### Approach

- In this question we are supposed to find the minimum length L for which a sequence of possible dice moves of length L is not possible. 

- Take an empty set.

- Now, iterate untill the size of the set becomes equals k i.e. we'll find all the k sequence.

- If we haven't got k sequences even after completing the iteration then this implies that this length combinations can not be created, therefore this lenght is the answer.

- Otherwise if we have found all the k sequences before completing the whole iteration, then this implies that we can create all the combinations of given length, therefore we have to make the set empty and increment length by one.

#### Time Complexity = O(nlogk)

#### Space Complexity = O(k)


## [Design a Number Container System](https://leetcode.com/problems/design-a-number-container-system/)

#### Approach

- Take two unordered map :- 1) m1 -> for storing elements corresponding to each given index.

                            2) m2 -> for storing all indices at which an element is present.

- when change() function is called ,then :- 1) if there is an element already present at that index then store that element in a variable(say prev)
                                        and then earse its occurence i.e. index from m2.

                                        2) Now update the value of m1[index] to the given number and add index corresponding to m2[number].

- when find() function is called the check if m2[number] is empty then return -1 otherwise return the very 1st index.


#### Time Complexity = O(N)

#### Space Complexity = O(2N)

## [Number of Zero-Filled Subarrays](https://leetcode.com/problems/number-of-zero-filled-subarrays/)

If we are having 1 zero then we'll add 1 to answer (because :- [0])

If we are having 2 zeros then we'll add 2 to answer ([0],[0,0])

If we are having 3 zeros then we'll add 3 to answer (because :- [0],[0,0],[0,0,0])

and will do the same

#### Time Complexity = O(N)

#### Space Complexity = O(1)
