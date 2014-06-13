/*
 * Name: Chengbin Hu
 *05/24/2014
 * Description.
 */

#include <iostream>

#include "Life.h"

using namespace std;

// Constructor 
Life::Life(int nrows, int ncols) :
    max_row(nrows), max_col(ncols)//is this already assign nrows to max_row?
{
    this->grid = this->build_grid();
}

// Destructor
Life::~Life()
{
    this->destroy_grid(this->grid);
}

// Initialize the game (reading from the user)
void
Life::initialize()
{
    int row, col;
    

    // TODO: Initialize next_state to all 0 values (all cells die by default).
    for(int i=0; i<2; ++i)
    {
        for(int j=0; j<9; ++j)
            next_state[i][j]=0;
    }
    //Done by Chengbin
    cout << "Enter the live neighbor counts (between 0 and 8) ";
    cout << "that will cause a dead cell " << endl;
    cout << "to become alive in the next generation, ";
    cout << "terminating input with -1" << endl << endl;

    // TODO: Read counts from the user and update next_state.
    int live_count;
    cin >> live_count;
    while(live_count != -1){
        if(live_count >= 0 && live_count <=8)
        {
            next_state[0][live_count]=1;
        }
        else
            cout<<"count "<<live_count<<" is out of range." << endl;
        cin >> live_count;
    }
    //Done by Chengbin
    cout << "Enter the live neighbor counts (between 0 and 8) ";
    cout << "that will cause a live cell " << endl;
    cout << "to continue living in the next generation, ";
    cout << "terminating input with -1" << endl;

    // TODO: Read counts from the user and update next_state.
    cin>>live_count;
    while(live_count != -1){
        
        if(live_count >= 0 && live_count <=8)
        {
            next_state[1][live_count]=1;
        }
        else
            cout<<"count "<<live_count<<" is out of range." << endl;
        cin >> live_count;
    }
    //Done Chengbin

    cout << "List the coordinates for living cells." << endl;
    cout << "Terminate the list with the special pair -1 -1" << endl;

    // TODO: Read coordinates from the user, verify their validity,
    // and update the grid.
    cin>>row>>col;

    while(row!=-1||col!=-1){
    if(row>=1 && row<=max_row)
        if(col>=1 && col<=max_col)
            grid[row][col]=1;
        else
            cout<<"Column "<<col<<" is out of range."<<endl;
    else
        cout<<"Row " << row<<" is out of range."<<endl;
    cin>>row>>col;
    }    
    
//Chengbin
}

// Print the grid to cout.
void
Life::print()
{
    cout << "\nCurrent Life configuration:\n\n";
    for (int row = 1; row < max_row + 1; ++row)
    {
        for (int col = 1; col < max_col + 1; ++col)
        {
            cout << (grid[row][col] ? '*' : ' ');
        }
        cout << endl;
    }
    cout << endl;
}

// Update the contents of the grid to the next generation.
void
Life::update()
{
    // TODO: Create a new grid.
    int **replace_grid = this->build_grid();
    int row, col;

    // TODO: Populate the new grid according to the rules.
    for(row=1; row<=max_row;++row)
        for(col=1; col<=max_col; ++col)
            replace_grid[row][col] = next_state[grid[row][col]][neighborCount(row,col)];

    // TODO: Update the game with the new configuration.
    // (You can either copy the data back or replace the original grid,
    // but be sure to destroy the grid you no longer need.)
    for(row=1; row<=max_row;++row)
        for(col=1; col<=max_col; ++col)
            grid[row][col]=replace_grid[row][col];

    this->destroy_grid(replace_grid);
}
// Build a new empty grid.
int **
Life::build_grid()
{
    int **new_grid;
    new_grid= new int* [max_row+2];
    for(int i=0; i<max_col+2;++i)
        new_grid[i] = new int [max_col+2];

    // TODO: Create and initialize the new grid.
    int j;
    for(int k = 0; k< max_row+2; ++k)
    {
        for(j=0; j<max_col+2; ++j)
        {
            new_grid[k][j]=0;
        }
    }
    return new_grid;
    //Done by Chengbin
}

// Destroy the specified grid.
void
Life::destroy_grid(int ** grid)
{
    // TODO: Implement the method.
    for(int i=0; i<max_row+2; i++)
    {
        delete [] grid[i];
    }
    delete [] grid;
    //Done by chengbin
}

// Count the neighbors of the specified cell.
int
Life::neighborCount(int row, int col)
{
    int count = 0;

    for (int i = row - 1; i <= row+1; ++i)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            count += grid[i][j];
        }
    }

    count -= grid[row][col];
    return count;
}

/* vim: set et sw=4 ts=4: */
