#include "History.h"
//#include "Arena.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols) {
    m_rows = nRows;
    m_cols = nCols;
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            m_grid[i][j] = '.';
        }
    }
}

bool History::record(int r, int c) {
    if (r < 1  ||  r > m_rows  ||  c < 1  || c > m_cols){
        return false;
    }
    else
    {
        if (m_grid[r-1][c-1] == '.')
            m_grid[r-1][c-1] = 'A';
        else if (m_grid[r-1][c-1] == 'Z')
            m_grid[r-1][c-1] = 'Z';
        else
            m_grid[r-1][c-1] += 1;
        return true;
    }
};

void History::display() const {
    clearScreen();
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            cout << m_grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
};

