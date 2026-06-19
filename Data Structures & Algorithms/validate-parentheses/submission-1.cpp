class Solution {
   public:
    bool isValid(string s) {
        vector<char> stack(0);

        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '[':
                    stack.push_back(']');
                    break;
                case '{':
                    stack.push_back('}');

                    break;
                case '(':
                    stack.push_back(')');
                    break;
                default:
                    if(stack.empty() || stack.back() != s[i]) return false;
                    stack.pop_back();
                    break;
            }
            
        }

        return stack.empty();
    }
};
