class Solution {
public:
    string isPossible(int n, vector<int> freq, string cur, char &mid, string& target){
        // this gives the max palindrome achievable with the current prefix 
        //(descending order)
        for(int i=25; i>=0; i--){
            while(freq[i]){
                cur += (char)('a'+i);
                freq[i]--;
            }
        }
        if(mid!='#'){
            string temp = cur;
            cur += mid;
            reverse(temp.begin(), temp.end());
            cur.append(temp.begin(), temp.end());
        }
        else {
            string temp = cur;
            reverse(temp.begin(), temp.end());
            cur.append(temp.begin(), temp.end());
        }
        return cur>target? cur : "";
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        if(n==1){
            if(s>target) return s;
            else return "";
        }
        for(char c : s) freq[c-'a']++; 

        char mid = '#';
        int oddCount = 0;

        for(int i=0; i<26; i++){
            if(freq[i]%2){
                mid = (char)('a'+i);
                freq[i]--;
                oddCount++;
            }

            freq[i] /= 2; 

            if(oddCount>=2) return ""; 
        }

        n /= 2; 
        string res = "", prefix = "";

        for(int i=0; i<n; i++){

            string cur = prefix;
            bool isThereAny = false;

            for(int j=0; j<26; j++){
                if(freq[j]){
                    freq[j]--;
                    cur += (char)('a'+j);

                    string isPos = isPossible(n, freq, cur, mid, target);

                    if(isPos!=""){
                        prefix = cur; 
                        isThereAny = true;

                        if(res=="") res = isPos;
                        else res = min(res, isPos); 
                        break;
                    }

                    freq[j]++;
                    cur.pop_back();
                }
            }

            if(!isThereAny)
                return ""; 
        }

        return res; 
    }
};