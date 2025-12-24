class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalapples=0;
        for(int a:apple){
            totalapples+=a;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        int boxCount=0;
        int currentCapacity=0;

        for (int cap:capacity){
            currentCapacity += cap;
            boxCount++;

            if (currentCapacity >= totalapples){
                return boxCount;
            }
        }
        return boxCount;
    }
};