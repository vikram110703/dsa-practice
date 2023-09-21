class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int n=nums1.size()+nums2.size();
        int cnt=0;double ans=0.0,ans2=0.0;
        int ind=n/2;
        if(n%2==0)ind-=1;
    
            while(i<nums1.size()||j<nums2.size()){
                if(i<nums1.size()&&j<nums2.size()){
                    if(nums2[j]>nums1[i]){
                        
                        if(cnt==ind){
                            // cout<<"yes "<<i<<" "<<j<<endl;
                            ans+=(nums1[i]*1.0);
                        }
                        if(cnt==ind+1){
                            ans2+=(nums1[i]*1.0);
                            break;
                        }
                        i+=1;
                    }
                    else{
                        
                        
                         if(cnt==ind){
                             // cout<<" 2 : "<<i<<" "<<j<<endl;
                            ans+=(nums2[j]*1.0);
                        }
                        if(cnt==ind+1){
                            ans2+=(nums2[j]*1.0);
                            break;
                        }
                        j+=1;
                    }
                    // cnt+=1;
                }
                else if(i<nums1.size()){
                     if(cnt==ind){
                            ans+=(nums1[i]*1.0);
                        }
                        if(cnt==ind+1){
                            ans2+=(nums1[i]*1.0);
                            break;
                        }
                    i+=1;
                }
                else{
                     if(cnt==ind){
                            ans+=(nums2[j]*1.0);
                        }
                        if(cnt==ind+1){
                            ans2+=(nums2[j]*1.0);
                            break;
                        }
                    j+=1;
                }
                cnt+=1;
            }
        cout<<cnt<<endl;
    if(n%2==0)
    {
        return (ans+ans2)/(2.0);
    }
    else {
        return (ans*1.0);
    }
        
      
    }
};