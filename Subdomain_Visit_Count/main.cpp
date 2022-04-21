#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        unordered_map<string, int> countVisits;
        vector<string> ans;

        for (auto cpdomain: cpdomains) {
            int f = cpdomain.find(' ');
            int cp = stoi(cpdomain.substr(0, f));
            string domain = cpdomain.substr(f + 1, -1);
            countVisits[domain] += cp;

            f = domain.find('.');
            while (f != -1) {
                domain = domain.substr(f + 1, -1);
                countVisits[domain] += cp;
                f = domain.find('.');
            }
        }
        for (auto v: countVisits) {
            ans.push_back(to_string(v.second) + " " + v.first);
        }

        return ans;
    }
};


int main() {

    auto s = new Solution();

    vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    s->subdomainVisits(cpdomains);

}
