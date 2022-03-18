#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> PII;

void dfs(vector<vector<int>>& matrix, PII p[3][3], vector<vector<int>>& ans, int st) {
    if (st == 9) {
        vector<int> temp;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                //cout << matrix[i][j] << ' ';
                temp.emplace_back(matrix[i][j]);
            }
        }
        ans.emplace_back(temp);
        return;
    }
    if (matrix[st / 3][st % 3] != -1)
    {
        dfs(matrix, p, ans, st + 1);
        return;
    }
        
    //分别放入1，2，3
    for (int cur = 1; cur <= 3; cur++) {
        int line = st / 3, col = st % 3;
        matrix[line][col] = cur;
        if (matrix[(line + 1) % 3][col] == cur || matrix[(line + 2) % 3][col] == cur)
            continue;
        if (matrix[line][(col + 1) % 3] == cur || matrix[line][(col + 2) % 3] == cur)
            continue;
        
        int idx1 = 0, idx2 = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (line == p[i][j].first && col == p[i][j].second) {
                    idx1 = i; idx2 = j;
                }
            }
        }
        int a1 = p[idx1][(idx2 + 1) % 3].first, b1 = p[idx1][(idx2 + 1) % 3].second;
        int a2 = p[idx1][(idx2 + 2) % 3].first, b2 = p[idx1][(idx2 + 2) % 3].second;
        if (matrix[a1][b1] == cur) continue;
        if (matrix[a2][b2] == cur) continue;
        
        dfs(matrix, p, ans, st + 1);        
    }
    matrix[st/3][st%3] = -1;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<vector<int>> ans;
        vector<vector<int>> matrix(3,vector<int>(3));
        PII p[3][3];
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                char c;
                cin >> c;
                if (c == '*') matrix[i][j] = -1;
                else matrix[i][j] = c - '0';
            }
        }
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                int a, b;
                cin >> a >> b;
                p[i][j] = { a,b };
            }
        }
        dfs(matrix, p, ans, 0);
        if (ans.size() >= 2) cout << "Multiple" << endl;
        else if (ans.size() == 0) cout << "No" << endl;
        else
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << ans[0][i * 3 + j];
                }
                cout << endl;
            }
        }


    }


}