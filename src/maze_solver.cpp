#include "maze_solver.h"
#include <stack>
using namespace std;

bool MazeSolver::dfs(Maze& maze, int r, int c, vector<vector<bool>>& visited){
    //Bounds check
    if (r < 0 || r >= maze.grid.size() || c < 0 || c >= maze.grid[0].size())
        return false;

    //Wall or already visited
    if (maze.grid[r][c] == '#' || visited[r][c])
        return false;

    //Finish check
    if (maze.grid[r][c] == 'F') {
        maze.path.push_back({r, c});
        return true;
    }

    //Mark as visited
    visited[r][c] = true;

    //Explore north, east, south, west
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; ++i) {
        int nextRow = r + dr[i];
        int nextCol = c + dc[i];
        if (dfs(maze, nextRow, nextCol, visited)) {
            maze.path.push_back({r, c});
            return true;
        }
    }

    return false;
}

bool MazeSolver::solveDFS(Maze& maze) {
    // Clear any existing path
    maze.path.clear();
    
    // Create visited matrix
    vector<vector<bool>> visited(maze.grid.size(), 
                               vector<bool>(maze.grid[0].size(), false));
    
    // Start DFS from the start position
    bool found = dfs(maze, maze.start.row, maze.start.col, visited);
    
    // If path found, add the start position to the path
    if (found) {
        maze.path.push_back(maze.start);
    }
    
    return found;
}
