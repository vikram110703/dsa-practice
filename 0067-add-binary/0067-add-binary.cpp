#include<bits/stdc++.h>
class Solution {
    
string addBinary2(string A, string B)
{
    
    if (A.length() > B.length())
        return addBinary(B, A);
    
    int diff = B.length() - A.length();

    string padding;
    for (int i = 0; i < diff; i++)
        padding.push_back('0');
 
    A = padding + A;
    string res;
    char carry = '0';
 
    for (int i = A.length() - 1; i >= 0; i--) {
        // This if condition solves 110 111 possible cases
        if (A[i] == '1' && B[i] == '1') {
            if (carry == '1')
                res.push_back('1'), carry = '1';
            else
                res.push_back('0'), carry = '1';
        }
        // This if condition solves 000 001 possible cases
        else if (A[i] == '0' && B[i] == '0') {
            if (carry == '1')
                res.push_back('1'), carry = '0';
            else
                res.push_back('0'), carry = '0';
        }
        // This if condition solves 100 101 010 011 possible
        // cases
        else if (A[i] != B[i]) {
            if (carry == '1')
                res.push_back('0'), carry = '1';
            else
                res.push_back('1'), carry = '0';
        }
    }
 
    // If at the end there is carry then just add it to the
    // result
    if (carry == '1')
        res.push_back(carry);
    // reverse the result
    reverse(res.begin(), res.end());
 
    // To remove leading zeroes
    int index = 0;
    while (index + 1 < res.length() && res[index] == '0')
        index++;
    return (res.substr(index));
}
            
 
    
public:
    
    
    string addBinary(string a, string b) {
       string ans=addBinary2(a,b);
        return ans;
        
    }
};