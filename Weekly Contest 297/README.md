**For Question 1:**

  * Time Complexity: O(N)
  * Space Complexity: O(1)
  
  Approach:
  
   ```
     The first upper0 dollars earned are taxed at a rate of percent0.  
     The next upper1 - upper0 dollars earned are taxed at a rate of percent1.  
     The next upper2 - upper1 dollars earned are taxed at a rate of percent2.
  ```
  
  * The Approach is given in detailed in code approach with comments.
  
**For Question 2:**

  * Space Complexity: O(1)
  * Time Complexity: 
  
  Approach:
  
  
  * grid[i][j] will store the minimum cost required to go to the last row
  * For the m-1 leave it as it is because we are the last row.
  * For the m-2 row try every possible comibanation and find the minimum for each grid[i][j].
  * For the m-3 row do the same but we have already calculated minimum for each grid[i][j] for the m-2 row so just use that for calculating minimum for m-3 row and calulating tille 1st row.
  
 
**For Question 3:**

  * Space Complexity: O(K), Where K is the Size of Array. 
  * Time Complexity: O(K!)
  
  Approach:
  
  * Go through the Code given in the solution, there is the detailed approach given.

**For Question 4:**

  * Space Complexity: O(26*26)
  * Time Complexity: O(26*26*N)
  
  Approach:
  
  * Approach is for every pair of loweCase englist letter {x, y} (where x and y can be {'a', 'b', 'c', ..... 'z'}),
  * we will pre-compute that in how many we can take letter x while giving letter y

  * Now, for each element ideas[i], we know that take any letter execpt first letter of any such that
    ideas[k] such that ideas[i].substr(1, ideas[i].size()-1) == ideas[j].substr(1, ideas[j].size()-1).
    while ideas[i] an only give its first letter(i.e, ideas[i][j]);
