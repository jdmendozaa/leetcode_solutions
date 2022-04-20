#include <vector>
#include <iostream>
#include <limits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {

        ListNode *currentNode = head;
        ListNode *prevNode = NULL;
        int i = 0;
        vector<int> criticalPoint;


        while (true) {
            // Validate if current node is NULL and finish loop
            if (!currentNode) {
                break;
            }

            if (isCritical(currentNode, prevNode)) {
                criticalPoint.push_back(i);
            }

            prevNode = currentNode;
            currentNode = currentNode->next;
            i++;
        }

        if (criticalPoint.size() < 2) {
            return {-1, -1};
        }

        int max = criticalPoint[criticalPoint.size() - 1] - criticalPoint[0];
        int min = numeric_limits<int>::max();

        for (int j = 0; j < criticalPoint.size() - 1; j++) {
            int localMin = abs(criticalPoint[j] - criticalPoint[j + 1]);
            if (localMin < min) min = localMin;
            cout << criticalPoint[j] << " ";
        }
        cout << criticalPoint[criticalPoint.size() -1 ] << "\n";

        return {min, abs(max)};
    }

private:
    bool isCritical(ListNode *node, ListNode *prev) {

        // If node doesn't have any neighbor then is can't be critical
        if (!node->next || !prev) {
            return false;
        }

        int nexVal = node->next->val;
        int prevVal = prev->val;
        int currentVal = node->val;

        // Defines when a node is critical
        if ((currentVal > nexVal && currentVal > prevVal) || (currentVal < nexVal && currentVal < prevVal)) {
            return true;
        }

        return false;

    }

};

int main() {

}