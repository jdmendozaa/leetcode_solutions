#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string a) {

        string str, ans;

        //Remove non-alphanumeric values
        for (char i : a) {
            if (isalnum(i)) {
                // making two copies of the string with only alphanumeric characters
                str.push_back(i);
                ans.push_back(i);
            }
        }
        //All to lowercase
        transform(a.begin(), a.end(), a.begin(), ::tolower);

        string b = a;
        reverse(b.begin(), b.end());

        if (a == b) {
            return true;
        }

        return false;
    }
};


int main() {
    string a = "A man, a plan, a canal: Panama";

}
