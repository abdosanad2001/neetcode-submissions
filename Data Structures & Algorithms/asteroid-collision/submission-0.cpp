class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //T=O(n);space=O(n)
        int n=asteroids.size();
        vector<int> v;
        stack<int> st;
        for(int i=0;i<n;i++){
            bool alive=true;
            while(!st.empty() &&
                st.top()>0 && asteroids[i]<0)    {

                if(abs(asteroids[i])>abs(st.top()))
                st.pop();
                else if(abs(asteroids[i])==abs(st.top())){
                    st.pop();
                    alive=false;
                    break;
                }else{
                    alive=false;
                    break;
                }
            }
                if (alive){
                    st.push(asteroids[i]);
                }
           }
            
        
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }

    
};