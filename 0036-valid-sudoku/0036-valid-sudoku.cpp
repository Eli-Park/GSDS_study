class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int rnum = 0; rnum < 9 ; rnum++) {
            unordered_map<char, vector<char>> check_row;
            for(int cnum = 0; cnum < 9 ; cnum++) {
                char element = board[rnum][cnum];
                if(element != '.') {
                    check_row[element].push_back(element);
                }
                if(check_row[element].size() > 1) {
                    std::cout<<element<<std::endl;
                    return false;
                }
            }
        }

        for(int cnum = 0; cnum < 9 ; cnum++) {
            unordered_map<char, vector<char>> check_col;
            for(int rnum = 0; rnum < 9 ; rnum++) {
                char element = board[rnum][cnum];
                if(element != '.') {
                    check_col[element].push_back(element);
                }
                if(check_col[element].size() > 1) {
                    std::cout<<element<<std::endl;
                    return false;
                }
            }
        }


        for(int rnum_lim = 3; rnum_lim <= 9; rnum_lim += 3) {
            for(int cnum_lim = 3; cnum_lim <= 9; cnum_lim += 3) {
                std::cout<<"[";                   
                unordered_map<char, vector<char>> check_sqr;
                for(int rnum = rnum_lim-3; rnum < rnum_lim ; rnum++) {
                   for(int cnum = cnum_lim-3; cnum < cnum_lim ; cnum++) {
                        char element = board[rnum][cnum];
                        std::cout<<element<<" ";
                        if(element != '.') {
                            check_sqr[element].push_back(element);
                        }   
                        if(check_sqr[element].size() > 1) {
                            return false;
                        }
                    }                    
                }
                std::cout<<"]"<<std::endl;;
            }
        }
        return true;  
        
    }
};