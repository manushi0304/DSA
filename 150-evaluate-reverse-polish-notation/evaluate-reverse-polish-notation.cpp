class Solution {
public:
    int evalRPN(vector<string>& tokens) {
  stack<int> st;
        
        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop top two operands
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b); // truncates toward zero
            } else {
                // Convert string to integer
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};