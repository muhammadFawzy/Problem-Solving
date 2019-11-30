// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=380
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char x1c, x2c;
    int y1, y2;
    while (cin >> x1c >> y1 >> x2c >> y2) {
        int x1 = x1c - 'a' + 1;
        int x2 = x2c - 'a' + 1;

        queue<pair<int, int> > edges;
        map<pair<int, int>, int> len;

        edges.push({ x1, y1 });
        len.insert({ { x1, y1 }, 0 });

        int dx[8] = { 2, 2, -2, -2, 1, -1, 1, -1 };
        int dy[8] = { 1, -1, 1, -1, 2, 2, -2, -2 };

        //build
        while (!edges.empty()) {
            pair<int, int> curr = edges.front();
            int curr_len = len[curr];
            edges.pop();

            for (int d = 0; d < 8; ++d) {

                int nx = curr.first + dx[d];
                int ny = curr.second + dy[d];

                if (len.count({ nx, ny }) > 0) // visited before
                    continue;

                if (nx >= 1 && ny >= 1 && nx <= 8 && ny <= 8) {
                    edges.push({ nx, ny });
                    len.insert({ { nx, ny }, curr_len + 1 });
                }
            }
        }

        if (len[{ x2, y2 }])
            cout << "To get from " << x1c << y1 << " to " << x2c << y2 << " takes " << len[{ x2, y2 }] << " knight moves." << endl;
        else
            cout << "To get from " << x1c << y1 << " to " << x2c << y2 << " takes " << 0 << " knight moves." << endl;
    }

    return 0;
}
