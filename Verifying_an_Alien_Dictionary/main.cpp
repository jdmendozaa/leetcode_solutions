#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order) {

        if (words.size() < 2) {
            return true;
        }

        unordered_map<char, int> orderMap;

        //add the order in a hashmap with the position
        for (int i = 0; i < order.size(); i++) {
            orderMap[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];

            int smallerSize = word1.size() < word2.size() ? word1.size() : word2.size();
            bool diff = false;

            for (int j = 0; j < smallerSize; j++) {
                char charWord1 = word1[j];
                char charWord2 = word2[j];
                if (orderMap[charWord1] > orderMap[charWord2]) {
                    return false;
                }

                if (orderMap[charWord1] < orderMap[charWord2]) {
                    diff = true;
                    break;
                }

            }

            if (!diff && word1.size() > word2.size()) return false;
        }
        return true;
    }
};


int main() {
    vector<string> words = {"apple", "app"};
    string order = "abcdefghijklmnopqrstuvwxyz";

    auto s = new Solution();

    cout << s->isAlienSorted(words, order);

}
