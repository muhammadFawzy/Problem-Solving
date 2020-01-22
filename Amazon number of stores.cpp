#include <stdc++.h>

using namespace std;

void visitAll(pair<int, int> point, map<pair<int, int>, set<pair<int, int>>> &graph, set<pair<int, int>> &visited)
{
    visited.insert(point);
    set<pair<int, int>> s = graph.find(point)->second;
    set<pair<int, int>>::iterator it;

    for (it = s.begin(); it != s.end(); it++)
    {

        if (visited.find((*it)) == visited.end())
            visitAll((*it), graph, visited);
    }
}
void buildGraph(int rows, int column, vector<vector<int>> grid, map<pair<int, int>, set<pair<int, int>>> &graph)
{

    vector<int> should = {1, 0,
                          0, 1,
                          0, -1,
                          -1, 0};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (grid[i][j] == 1)
            {

                set<pair<int, int>> s;
                s.insert(make_pair(i, j));
                // cout << "i= " << i << ":j= " << j << " row " << i << " col " << j << endl;
                for (int k = 0; k < should.size(); k += 2)
                {

                    int row = should[k] + i;
                    int col = should[k + 1] + j;
                    if (row < rows && row >= 0 && col < column && col >= 0)
                    {
                        if (grid[row][col] == 1)
                        {
                            s.insert(make_pair(row, col));
                            // cout << "i= " << i << ":j= " << j << " row " << row << " col " << col << endl;
                        }
                    }
                }

                graph.insert(make_pair(make_pair(i, j), s));
            }
        }
    }
}
int numberAmazongoStore(int rows, int column, vector<vector<int>> grid)
{
    map<pair<int, int>, set<pair<int, int>>> graph;
    set<pair<int, int>> visited;
    buildGraph(rows, column, grid, graph);

    map<pair<int, int>, set<pair<int, int>>>::iterator it;
    int count = 0;
    for (it = graph.begin(); it != graph.end(); it++)
    {
        set<pair<int, int>> all = (*it).second;
        if (visited.find((*it).first) == visited.end()) //not visited
        {
            cout << (*it).first.first << "  " << (*it).first.second << endl;

            count++;
            visitAll((*it).first, graph, visited);
        }
    }

    return count;
}

int main()
{

    vector<vector<int>> v = {
        {1, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 0, 1, 1},
        {1, 1, 1, 1}};
    cout << numberAmazongoStore(5, 4, v) << endl;
}
