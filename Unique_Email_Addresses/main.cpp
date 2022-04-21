#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    int numUniqueEmails(vector<string> &emails) {
        unordered_map<string, bool> uniqueEmail;

        for (auto email: emails) {
            uniqueEmail[transformEmail(email)] = true;
        }

        return uniqueEmail.size();
    }

private:
    string transformEmail(string email) {

        int atPos = email.find('@');

        string local_name = email.substr(0, atPos);
        string domain = email.substr(atPos + 1, string::npos);
        string newEmail;

        for (auto c: email) {
            if (c == '+' || c == '@') {
                break;
            }

            if (c != '.') {
                newEmail.push_back(c);
            }
        }

        newEmail += "@" + domain;

        return newEmail;

    }
};


int main() {

    vector<string> email = {"a@leetcode.com", "b@leetcode.com", "c@leetcode.com"};

    auto *s = new Solution();

    cout << s->numUniqueEmails(email);

}
