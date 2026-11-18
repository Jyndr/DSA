/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> umap; //node_val, Node
        unordered_map<int, int> visited;
        Node* newnode = new Node;

        if(node == nullptr) return nullptr;
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node *temp = q.front();
            q.pop();
            
            Node *newtemp;
            
            if(umap.find(temp->val)!= umap.end()) newtemp = umap[temp->val];
            else{
                newtemp = new Node(temp->val);
                if(umap.empty()) newnode = newtemp;
                umap[temp->val]= newtemp;
            } 

            if(visited[temp->val] != 1) visited[temp->val]=1;
            
            for(auto it: temp->neighbors){
                if(umap.find(it->val) == umap.end()){
                    Node *neigh= new Node(it->val);
                    newtemp->neighbors.push_back(neigh);
                    umap[it->val]= neigh;
                }
                else{
                    newtemp->neighbors.push_back(umap[it->val]);
                }
                
                if(visited[it->val] != 1){
                    visited[it->val]= 1;
                    q.push(it);
                }
            }
        } 
        return newnode;
    }
};