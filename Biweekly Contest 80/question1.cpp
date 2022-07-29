/*
Strong Password Checker II
(Easy)

A password is said to be strong if it satisfies all the following criteria:
It has at least 8 characters.
It contains at least one lowercase letter.
It contains at least one uppercase letter.
It contains at least one digit.
It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).
Given a string password, return true if it is a strong password. Otherwise, return false.

Approach :
Simply brute force the questions,
while checking each character,
put the if conditions accordingly to check for
1. lower case,
2. upper case,
3. special characters,
4.adjacent characters,
5. numbers and
6. size of string.

*/

class Solution
{
public:
    bool strongPasswordCheckerII(string password)
{
		if(password.size()<8) return false;
        //l=lower, u=upper, d=digit, s=special
		bool l=false, u=false, d=false, s=false;
		for(int  i=0; i<password.size(); i++)
            {
            //check password contains same char in adjacent
			if(i>0 && password[i]==password[i-1])
                return false;
            //checking for lowercase letter
			if(islower(password[i]))
                l=true;
            //checking for uppercase letter
			else if(isupper(password[i]))
                u=true;
            //checking for digit
			else if(isdigit(password[i]))
                d=true;
			else
                //checking for special characters
                s=true;
		}
		return l && u && d && s;
	}
};
/*
Time complexity: O(n)
Space complexity: O(1)
*/
