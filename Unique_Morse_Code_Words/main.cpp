#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        vector<string> alphabet = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                                   "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                                   "-.--", "--.."};

        int offsetAscii = 97;
        string transformation;
        unordered_set<string> morseWords;

        for (auto word: words) {

            transformation = "";

            for (auto c: word) {
                transformation += alphabet[(int) c - offsetAscii];
            }
            morseWords.insert(transformation);
        }

        return morseWords.size();
    }
};


int main() {

    vector<string> words = {"a"};
    auto s = new Solution();

    cout << s->uniqueMorseRepresentations(words);

}
