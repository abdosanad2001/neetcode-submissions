
class Solution {
public:
    // Complexité : T = O(n) | space = O(n) 
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;//O(n)

        for (int i = 0; i < n; i++) {
            if(s[i]=='{'){
                st.push('}');
            }
            else if(s[i]=='('){
                st.push(')');
            }
            else if(s[i]=='['){
                st.push(']');
            }
            else if(st.empty() || st.top()!=s[i]){
    
                return false;
            }else{
                st.pop();
            }
        }

        return st.empty();
    }
};