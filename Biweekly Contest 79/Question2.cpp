// PROBLEM :-- Sender With Largest Word Count //

/* You have a chat log of n messages. You are given two string arrays messages and senders where messages[i] is a message sent by senders[i].

A message is list of words that are separated by a single space with no leading or trailing spaces. The word count of a sender is the total number of words sent by the sender. Note that a sender may send more than one message.

Return the sender with the largest word count. If there is more than one sender with the largest word count, return the one with the lexicographically largest name.

Note:

Uppercase letters come before lowercase letters in lexicographical order.
"Alice" and "alice" are distinct.
 

Example 1:

Input: messages = ["Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree"], senders = ["Alice","userTwo","userThree","Alice"]
Output: "Alice"
Explanation: Alice sends a total of 2 + 3 = 5 words.
userTwo sends a total of 2 words.
userThree sends a total of 3 words.
Since Alice has the largest word count, we return "Alice".
Example 2:

Input: messages = ["How is leetcode for everyone","Leetcode is useful for practice"], senders = ["Bob","Charlie"]
Output: "Charlie"
Explanation: Bob sends a total of 5 words.
Charlie sends a total of 5 words.
Since there is a tie for the largest word count, we return the sender with the lexicographically larger name, Charlie.
 

Constraints:

n == messages.length == senders.length
1 <= n <= 104
1 <= messages[i].length <= 100
1 <= senders[i].length <= 10
messages[i] consists of uppercase and lowercase English letters and ' '.
All the words in messages[i] are separated by a single space.
messages[i] does not have leading or trailing spaces.
senders[i] consists of uppercase and lowercase English letters only. */

// Approach :-- DFS Greedy Approach

1. Look up at the given statements and approach to the question.
2. We can see that a chat log of n messages is given.
3. Given two string arrays messages and senders where messages[i] is a message sent by senders[i].
4. Then return the sender with the largest word count.
5. If there is more than one sender with the largest word count, return the one with the lexicographically largest name.

class Solution
{
 public:
  string largestWordCount(vector<string>& messages, vector<string>& senders)
  {
    const int n = messages.size();
    string ans;
    int maxWordsSent = 0;
    unordered_map<string, int> count;  // {sender, # words sent}

    for (int i = 0; i < n; ++i)
    {
      const auto& message = messages[i];
      const auto& sender = senders[i];
      const int wordsCount = std::count(begin(message), end(message), ' ') + 1;
      count[sender] += wordsCount;
      const int numWordsSent = count[sender];
      if (numWordsSent > maxWordsSent)
      {
        ans = sender;
        maxWordsSent = numWordsSent;
      } else if (numWordsSent == maxWordsSent && sender > ans)
      {
        ans = sender;
      }
    }

    return ans;
  }
};

// Time Complexity: O(n)
// Space Complexity: O(n)


