//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* tmp=head;
        Node* prev=NULL;
        int cnt=0;
        while(tmp!=NULL)
        {
            Node* new_tmp=tmp->next;
            tmp->next=prev;
            prev=tmp;
            tmp=new_tmp;
            cnt+=1;
        }
        
        Node* nn=prev;
        int rem=1;
        while(nn!=NULL)
        {
            int val=nn->data;
            if(val+rem>=10)
            {
                if(cnt==1||nn->next==NULL)
                {
                    nn->data=val+rem;
                }
                else
                nn->data=0;
                rem=1;
            }
            else
            {
                nn->data+=rem;
                rem=0;
            }
            nn=nn->next;
        }
        
          tmp=prev;
         Node* prev2=NULL;
        while(tmp!=NULL)
        {
            Node* new_tmp=tmp->next;
            tmp->next=prev2;
            prev2=tmp;
            tmp=new_tmp;
        }
        return prev2;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends