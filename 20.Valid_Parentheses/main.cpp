#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for (int i = 0 ; i < s.length(); i++) {
            char current_char = s[i];
            if (current_char == '{' || current_char == '[' || current_char == '('){
                q.push(current_char);
            }else{
                if (q.size() == 0) return false;
                char top_queue = q.top();
                if ((current_char == '}' && top_queue != '{') || (current_char == ']' && top_queue != '[') || (current_char == ')' && top_queue != '(')) {
                    return false;
                }
                q.pop();
            }
        }
        if (q.size() != 0) return false;
        return true;
    }
};

int main() {
    Solution *s = new Solution();

    cout << s->isValid("(]");
}
