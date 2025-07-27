class Solution:
    def makeFancyString(self, s: str) -> str:
        n=len(s)
        if(n==1):
            return s
        tmp=s[0]
        prev=s[0]
        count=1
        i=1
        while(i<n):
            if(s[i-1]==s[i]):
                count+=1
            else:
                count=1

            prev=s[i]

            if(count<=2):
                tmp+=s[i]
            i+=1

        return tmp
