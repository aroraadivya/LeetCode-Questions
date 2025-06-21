class Solution {
private:
    int solve(char a, char b, string& s, int k){
        int dist=0, mx=0;

        for(int i=0;i<s.size();i++){
            if(a==s[i] or b==s[i]){dist++;}
            else{
                if(k>0){k--; dist++;}
                else{
                    mx = max(mx, dist);
                    dist--;
                }
            }
        }
        mx = max(mx, dist);

        return mx;
    }
public:
    int maxDistance(string s, int k) {
        if(k==s.size()){return k;}

        int nw = solve('N','W',s, k);
        int ne = solve('N','E',s, k);
        int sw = solve('S','W',s, k);
        int se = solve('S','E',s, k);

        return max({nw, ne, sw, se});
    }
};