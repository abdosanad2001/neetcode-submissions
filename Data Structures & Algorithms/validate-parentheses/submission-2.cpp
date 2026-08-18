#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Complexité : O(n) Temps | O(n) Espace
    bool isValid(string s) {
        int n = s.size();

        unordered_map<char, char> opened;
        opened[')'] = '(';
        opened['}'] = '{';
        opened[']'] = '[';

        stack<char> st;

        for (int i = 0; i < n; i++) {
            
            if (opened.contains(s[i])) {

                if (st.empty() || st.top() != opened[s[i]]) {
                    return false;
                }
                st.pop(); 
            } 
            
            else {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};