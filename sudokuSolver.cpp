#include <iostream>

using namespace std;
#define N 9
int sB[N][N] =
    {
        {0, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 1, 0, 0, 0},
        {0, 7, 8, 0, 0, 0, 0, 0, 1},
        {0, 0, 4, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 2, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};

bool checkCol(int c, int val)
{
    for (int r = 0; r < N; r++)
    {
        if (sB[r][c] == val)
            return true;
    }
    return false;
}
bool checkRow(int r, int val)
{
    for (int c = 0; c < N; c++)
    {
        if (sB[r][c] == val)
            return true;
    }
    return false;
}
bool checkBox(int init_row, int init_col, int val)
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < 3; c++)
            if (sB[r + init_row][c + init_col] == val)
                return true;
    }
    return false;
}
void startGame()
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            if (c == 3 || c == 6)
            {
                cout << " |  ";
            }
            cout << sB[r][c] << " ";
        }
        if (r == 2 || r == 5)
        {
            cout << endl;
            for (int k = 0; k < N; k++)
            {
                cout << "---";
            }
        }
        cout << endl;
    }
}
bool findBox(int &r, int &c)
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            if (sB[r][c] == 0)
                return true;
        }
    }
    return false;
}
bool canEnter(int r, int c, int val)
{
    return !checkRow(r, val) && !checkCol(c, val);
}
bool finalSolution()
{
    int r, c;
    if (!findBox(r, c)) // when all places are filled
        return true;
    for (int val = 1; val <= 9; val++)
    {
        if (canEnter(r, c, val))
        {
            sB[r][c] = val;    // assigns number in a empty place
            if (finalSolution) // recursively calls till all other places are filled
                return true;
            sB[r][c] = 0; // returns to 0 if other conditions won't get satisfied
        }
    }
    return false;
}
int main()
{
    if (finalSolution() == true)
    {
        startGame();
    }
    else
    {
        cout << "Solution doesn't exist";
    }
}