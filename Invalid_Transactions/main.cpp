#include <iostream>
#include <unordered_map>
#include <vector>
#include <array>

using namespace std;

class Solution {

    struct Transaction {
        string name;
        int time;
        int amount;
        string city;
        bool isValid;
    };

public:
    vector<string> invalidTransactions(vector<string> &transactions) {
        string tName;
        int time;
        int amount;
        string city;
        int pos;
        int prevPos;
        bool isValid;
        unordered_multimap<string, Transaction> tMap;
        vector<string> ans;

        for (auto t: transactions) {
            //Parse. There's probably a more readable way to parse this, like in the example below.
//            vector<string> vs(4);
//            int j = 0;
//            for (int i = 0; i < t.size(); ++i) {
//                if (t[i] == ',') {
//                    ++j;
//                } else {
//                    vs[j] += t[i];
//                }
//            }
//            move(vs[0]), stoi(vs[1]), stoi(vs[2]), move(vs[3])

            pos = t.find(',');
            tName = t.substr(0, pos);

            prevPos = pos;
            pos = t.find(',', pos + 1);
            time = stoi(t.substr(prevPos + 1, pos - prevPos - 1));

            prevPos = pos;
            pos = t.find(',', pos + 1);
            amount = stoi(t.substr(prevPos + 1, pos - prevPos - 1));

            prevPos = pos;
            pos = t.find(',', pos + 1);
            city = t.substr(prevPos + 1, pos - prevPos - 1);

            if (amount > 1000) {
                isValid = false;
            } else {
                isValid = true;
            }

            // There are previous transactions with the same name
            if (tMap.count(tName) > 0) {
                //Find all the transactions with the same name and iterate over it
                auto range = tMap.equal_range(tName);
                for (auto it = range.first; it != range.second; ++it) {
                    if (city != it->second.city && abs(time - it->second.time) <= 60) {
                        isValid = false;
                        it->second.isValid = false;
                    }
                }
            }

            Transaction ts = {
                    tName,
                    time,
                    amount,
                    city,
                    isValid
            };
            tMap.insert({tName, ts});
        }

        for (auto m: tMap) {
            if (!m.second.isValid) {
                ans.push_back(m.second.name + "," + to_string(m.second.time) + "," + to_string(m.second.amount) + "," +
                              m.second.city);
            }
        }

        return ans;
    }
};


int main() {
    auto s = new Solution();
    vector<string> transactions = {"alice,20,800,mtv", "bob,50,1200,mtv"};

    s->invalidTransactions(transactions);
}
