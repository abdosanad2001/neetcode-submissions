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
        //Time=O(V+E);space=O(V)

        if(!node) return nullptr;

        unordered_map<Node*,Node*> cloned;//O(V)

        auto bfs=[&](Node* startNode){
            queue<Node*> q;

            //cloner le point de depart
            cloned[startNode]=new Node(startNode->val);
            q.push(startNode);

            while(!q.empty()){
                Node* curr=q.front();
                q.pop();

                for(Node* neighbor: curr->neighbors){
                    if(cloned.find(neighbor)==cloned.end()){
                        cloned[neighbor]=new Node(neighbor->val);
                        q.push(neighbor);
                    }
                    
                      cloned[curr]->neighbors.push_back(cloned[neighbor]);
                }
            }
        

        };
        bfs(node);
        return cloned[node];
    }
};
