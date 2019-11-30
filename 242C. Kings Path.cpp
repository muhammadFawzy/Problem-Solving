//https://codeforces.com/contest/242/problem/C
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    
    int n;
    cin>>n;
    
    set<pair<int, int>> segments;
    queue<pair<int,int>> edges;
    map<pair<int, int>, int> len;
    
    while(n--)
    {
        int r,a,b;
        cin>>r>>a>>b;
        
        for(int i=a;i<=b;i++)
        {
            segments.insert({r,i});
        }
        
    }
    
    
    
    edges.push({x1,y1});
    len.insert({{x1,y1},0});
    
    
    int dx[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
    int dy[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
    
    
    //build
    while (!edges.empty()) {
        pair<int, int> curr=edges.front();
        int curr_len= len[curr];
        edges.pop();
    
    for (int d = 0; d < 8; ++d) {
            
            int nx = curr.first + dx[d];
            int ny = curr.second + dy[d];
            
            
            if(len.count({nx,ny})>0)  // visited before
                continue;
        
           
            
            
                
        if(segments.count({nx,ny})>0)
            {
                edges.push({nx,ny});
                len.insert({{nx,ny},curr_len+1});

                if(nx==x2&&ny==y2){
                    cout<< curr_len+1<<endl;
                    return 0;
                    
                }
            }
           
        }
       }
    
   
    cout<<-1<<endl;
    return 0;
}
