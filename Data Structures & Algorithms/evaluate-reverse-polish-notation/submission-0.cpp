class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> st;//O(n)
        //T=O(n) ;space=O(n)
        for(int i=0;i<n;i++){
            if(tokens[i]!="+" && tokens[i]!="-" && 
            tokens[i]!="/" && tokens[i]!="*"){
                st.push(stoi(tokens[i]));
            }else{
                string op=tokens[i];
                int total;
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                if(op=="+"){
                    
                    total=a+b;
                }else if(op=="*"){
                    total=a*b;
                }else if(op=="-"){
                    total=b-a;
                }else if(op=="/"){
                    total=b/a;
                }
            st.push(total);
                
            }
        }
        return st.top();
    }
};
