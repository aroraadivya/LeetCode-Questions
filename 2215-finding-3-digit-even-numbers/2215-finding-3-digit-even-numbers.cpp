#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int digit : digits) {
            freq[digit]++;
        }

        set<int> result;

        for (int num = 100; num <= 999; ++num) {
            if (num % 2 != 0) continue;

            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int> needed(10, 0);
            needed[a]++;
            needed[b]++;
            needed[c]++;

            bool canForm = true;
            for (int d = 0; d < 10; ++d) {
                if (needed[d] > freq[d]) {
                    canForm = false;
                    break;
                }
            }

            if (canForm) {
                result.insert(num);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
