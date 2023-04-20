//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/


int dfs(Node* bheem, Node* pre, unordered_map<Node*, Node*> &par, int steps, int k)
{
    if(steps > k) return 0;
    if(bheem == NULL) return 0;
    int ans = bheem->data;
    if(par[bheem] && par[bheem] != pre) ans += dfs(par[bheem], bheem, par, steps+1, k);
    if(bheem->left != pre) ans += dfs(bheem->left, bheem, par, steps + 1, k);
    if(bheem->right != pre) ans += dfs(bheem->right, bheem, par, steps + 1, k);
    return ans;
}


class Solution{

    public:
    int ladoos(Node* root, int home, int k)
    {
        unordered_map<Node*, Node*> par;
        Node *bheem;
        queue<Node*> q;
        q.push(root);
        par[bheem] = NULL;
        while(!q.empty()) 
        {
            auto curr = q.front();
            if(curr->data == home) bheem = curr;
            q.pop();
            if(curr->left) q.push(curr->left), par[curr->left] = curr;
            if(curr->right) q.push(curr->right), par[curr->right] = curr;
        }
        int ans = dfs(bheem, NULL, par, 0, k);
        return ans;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends