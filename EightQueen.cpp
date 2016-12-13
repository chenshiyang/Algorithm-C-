#include<iostream>
#include<vector>

using namespace std;
const int NUM = 8;

void print_table(vector<vector<bool>> &table) {
    cout <<  "A valid solution: " << endl;
    for(int i = 0; i != NUM; ++ i) {
        for(int j = 0; j != NUM; ++ j) {
            cout << (table[i][j] ? "Q " : "+ ");
        }
        cout << "\n";
    }
    cout << endl;
}

bool dangerous(vector<bool> &row, vector<bool> &col, vector<bool> &left_slant, vector<bool> &right_slant, int i, int j) {
    return (row[i] || col[j] || left_slant[i + j] || right_slant[i + NUM - 1 - j]);
}

void backtrack(vector<vector<bool>> &table, vector<bool> &row, vector<bool> &col, vector<bool> &left_slant, vector<bool> &right_slant, int index) {
    if(index == NUM) {
        print_table(table);
        return;
    }

    for(int j = 0; j != NUM; ++ j) {
        if(!dangerous(row, col, left_slant, right_slant, index, j)) {
            table[index][j] = true;;
            row[index] = true;
            col[j] = true;
            left_slant[index + j] = true;
            right_slant[index - j + NUM - 1] = true;
            backtrack(table, row, col, left_slant, right_slant, index + 1);
            table[index][j] = false;
            row[index] = false;
            col[j] = false;
            left_slant[index + j] = false;
            right_slant[index - j + NUM - 1] = false;
        }
    }
}

void solve(vector<vector<bool>> &table) {
    vector<bool> row(NUM, false);
    vector<bool> col(NUM, false);
    vector<bool> left_slant(2 * NUM - 1, false);
    vector<bool> right_slant(2 * NUM - 1, false);

    backtrack(table, row, col, left_slant, right_slant, 0);
}


int main() {
    vector<vector<bool>> table;
    vector<bool> line(NUM, false);
    for(int i = 0; i != NUM; ++ i) {
        table.push_back(line);
    }
    solve(table);
}
