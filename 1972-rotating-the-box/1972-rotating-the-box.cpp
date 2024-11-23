class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows=box.size();
        int cols=box[0].size();

        vector<vector<char>> res(cols, vector<char>(rows, '.'));

        for(int r=0; r<rows;r++){
            int i=cols-1;
            for(int c=cols-1; c>=0;c--){
                if(box[r][c]=='#'){
                    res[i][rows-r-1]='#';
                    i--;
                }
                else if (box[r][c]=='*'){
                    res[c][rows-r-1] ='*';
                    i=c-1;
                }
            }
        }
        return res;
    }
};