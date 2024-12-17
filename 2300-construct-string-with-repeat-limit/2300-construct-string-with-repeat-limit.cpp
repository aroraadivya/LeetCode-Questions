class Solution {
public:
    string repeatLimitedString(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.push({'a' + i, freq[i]});
        }
        
        string result;
        while (!pq.empty()) {
            auto [ch, count] = pq.top(); pq.pop();
            int used = min(k, count);
            result.append(used, ch);
            count -= used;

            if (count > 0) {
                if (pq.empty()) break;
                auto [nextCh, nextCount] = pq.top(); pq.pop();
                result += nextCh;
                nextCount--;

                if (nextCount > 0) pq.push({nextCh, nextCount});
                pq.push({ch, count});
            }
        }
        return result;
    }
};