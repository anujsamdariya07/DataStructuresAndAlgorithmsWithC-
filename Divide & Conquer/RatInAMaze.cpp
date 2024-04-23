#include<iostream>
#include<string>
#include<vector>

using namespace std;

// We will create a function to handle the below listed possibilities
// 3 possibilities:
    // --> path closed
    // --> out of bounds
    // --> check if position is already visited
bool isSafe(int srcx, int srcy, int newx, int newy, int maze[][4], int row, int column, vector <vector<bool> > &visited)
{
    if(
        (newx >= 0 && newx < row) &&
        (newy >= 0 && newy < column) &&
        (maze[newx][newy] == 1) &&
        visited[newx][newy] == false
    ) {
        return true;
    } else {
        return false;
    }
}

void printAllPaths(int maze[][4], int row, int column, int srcx, int srcy, string &output, vector<vector<bool> > &visited)
{
    // Output is at [row-1][column-1]

    // Base condition
    if(srcx == row-1 && srcy == column-1)
    {
        cout << output << endl;
        return;
    }

    // 3 possibilities:
    // --> path closed
    // --> out of bounds
    // --> check if position is already visited

    int newx, newy;

    // Up
    newx = srcx-1;
    newy = srcy;
    if(isSafe(srcx, srcy, newx, newy, maze, row, column, visited))
    {
        // Mark visited
        visited[newx][newy] = true;
        output.push_back('U');
        // Recursive Call
        printAllPaths(maze, row, column, newx, newy, output, visited);
        // Bactracking --> Unmark visited
        output.pop_back();
        visited[newx][newy] = false;
    }

    // Right
    newx = srcx;
    newy = srcy+1;
    if(isSafe(srcx, srcy, newx, newy, maze, row, column, visited))
    {
        // Mark visited
        visited[newx][newy] = true;
        output.push_back('R');
        // Recursive Call
        printAllPaths(maze, row, column, newx, newy, output, visited);
        // Bactracking --> Unmark visited
        output.pop_back();
        visited[newx][newy] = false;
    }

    // Down
    newx = srcx+1;
    newy = srcy;
    if(isSafe(srcx, srcy, newx, newy, maze, row, column, visited))
    {
        // Mark visited
        visited[newx][newy] = true;
        output.push_back('D');
        // Recursive Call
        printAllPaths(maze, row, column, newx, newy, output, visited);
        // Bactracking --> Unmark visited
        output.pop_back();
        visited[newx][newy] = false;
    }

    // Left
    newx = srcx;
    newy = srcy-1;
    if(isSafe(srcx, srcy, newx, newy, maze, row, column, visited))
    {
        // Mark visited
        visited[newx][newy] = true;
        output.push_back('L');
        // Recursive Call
        printAllPaths(maze, row, column, newx, newy, output, visited);
        // Bactracking --> Unmark visited
        output.pop_back();
        visited[newx][newy] = false;
    }
}

int main()
{
    
    int maze[4][4] = {
        {1, 0, 0, 0}, 
        {1, 1, 0, 0}, 
        {1, 1, 1, 0}, 
        {1, 1, 1, 1}
    };
    int row = 4, column = 4;
    int srcx = 0, srcy = 0;
    string output = "";
    vector <vector<bool> > visited(row, vector<bool>(column, false));

    if(maze[0][0] == 0)
    {
        cout << "No path exists" << endl;
    } else {
        visited[srcx][srcy] = true;
        printAllPaths(maze, row, column, srcx, srcy, output, visited);
    }
}