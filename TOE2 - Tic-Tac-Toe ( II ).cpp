// https://www.spoj.com/problems/TOE2/
#include <bits/stdc++.h>

using namespace std;


bool is_win(string config) {

    bool rows =
        (config[0] != '.' && config[0] == config[1] && config[1] == config[2]) ||
        (config[3] != '.' && config[3] == config[4] && config[4] == config[5]) ||
        (config[6] != '.' && config[6] == config[7] && config[7] == config[8]);

    bool columns =
        (config[0] != '.' && config[0] == config[3] && config[3] == config[6]) ||
        (config[1] != '.' && config[1] == config[4] && config[4] == config[7]) ||
        (config[2] != '.' && config[2] == config[5] && config[5] == config[8]);

    bool diagonals =
        (config[0] != '.' && config[0] == config[4] && config[4] == config[8]) ||
        (config[2] != '.' && config[2] == config[4] && config[4] == config[6]);

    return rows || columns || diagonals;
}

bool is_last(string config)
{   if(is_win(config))
    return true;
    
    for(int i=0;i<config.length();i++)
        if(config[i]=='.')
            return false;
    
    return true;
}

int main() {
    
    while(true){
        
        string board="";
        cin>>board;
        if(board=="end")
            break;
        
        string start=".........";
        queue<pair<string, bool>> boards;
        boards.push({start, 1});
        string value="invalid";
                
    
        
        while(boards.size()){
            
            string cur_board=boards.front().first;
            bool X=boards.front().second;
            boards.pop();
            
            if(cur_board==board)
            {
                if(is_last(cur_board))
                value="valid";
                break;
            }
            
            if(is_win(cur_board)) continue;
                        
            for(int i=0;i<9;i++)
            {
                if(cur_board[i]=='.')
                {
                    cur_board[i]= X?'X':'O';
                    if(cur_board[i]==board[i])
                    {
                        boards.push({cur_board,!X});
                        
                    }
                    cur_board[i]='.';
                }
            }
            
        }
        
        cout<<value<<endl;
        
    }
    
    return 0;
}
