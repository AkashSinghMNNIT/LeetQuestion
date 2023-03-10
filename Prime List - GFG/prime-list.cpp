//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    
    Node *primeList(Node *head){
        int arr[100000] = {0};
        vector<int> prime;
        for(long long i = 2; i<1e5; ++i)
        {
            if(!arr[i])
            {
                prime.push_back(i);
                for(long long j = i*i; j<1e5; j += i) arr[j] = 1;
            }
        }
        Node *temp = head;
        while(temp != NULL)
        {
            int val = temp->val;
            auto it = lower_bound(prime.begin(), prime.end(), val);
            if(it != prime.begin() && (*it + *(it-1)) >= 2*val) temp->val = *(it-1);
            else temp->val = *it;
            temp = temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends