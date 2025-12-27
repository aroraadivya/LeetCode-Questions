class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        
        for (int i = 0; i < n; i++){
            available.push(i); 
        }
        
        vector<int> count(n, 0);
        
        for (auto& m : meetings) {
            long long start = m[0], end = m[1];
        
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }
            
            if (!available.empty()) {
                int room = available.top();
                available.pop();
                count[room]++;
                busy.push({end, room});
            } else {
                auto [finishTime, room] = busy.top();
                busy.pop();
                count[room]++;
                busy.push({finishTime + (end - start), room});
            }
        }
        
        return max_element(count.begin(), count.end()) - count.begin();
    }
};