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
            if(count==2):
                while(i+1<n and s[i]==s[i+1]):
                    i+=1
                    count=1
            i+=1

        return tmp


# class Solution:
#     def makeFancyString(self, s: str) -> str:

#         prev = s[0]
#         frequency = 1
#         ans = s[0]

#         for i in range(1, len(s)):
#             if s[i] == prev:
#                 frequency += 1
#             else:
#                 prev = s[i]
#                 frequency = 1

#             if frequency < 3:
#                 ans += s[i]

#         return ans