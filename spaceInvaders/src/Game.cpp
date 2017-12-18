#include "Game.h"
#include "windows.h"
#include <iostream>
using namespace std;
Game::~Game()
{
    //dtor
}
void Game::draw(char arr[n][m], int x)
{
    /// clears screen;
    system("CLS");
    /// sets player char;
    arr[n-1][x]='X';
    /// draws;
    for(int i =0; i <n; i++)
    {
        for(int p = 0; p<m; p++)
            cout << arr[i][p];
        cout << endl;
    }
    /// stops the game so it doesn't redraw too fast;
    Sleep(50);
}
Game::Game()
{
    ///Fills field with space;
    for(int i =0; i <n; i++)
        for(int p = 0; p<m; p++)
            space[i][p]=' ';
            draw(space, x);
}
//main game function
void Game::main_game()
{
    ///mobs
    space[5][8]='O';
    space[5][7]='O';
    space[5][6]='O';
    space[5][5]='O';
    space[5][4]='O';
    space[0][8]='O';
    space[0][7]='O';
    space[0][6]='O';
    space[0][5]='O';
    space[0][4]='O';
    ///move
    while(mob!=0)
    {
        ///move
        tempx = x;
        if(GetAsyncKeyState(VK_RIGHT))
        {
            x++;
            moved=true;
            if(x>n-1)
            {
                x--;
                moved=false;
            }

        }
        ///move left
        if(GetAsyncKeyState(VK_LEFT))
        {

            x--;
            moved=true;
            if(x<0)
            {
                x++;
                moved=false;
            }
        }
        ///shoot
        if(GetAsyncKeyState(VK_SPACE)&&!shot)
        {
            buly = n-2;
            bulx = x;
            shot=true;
            space[buly][bulx]='.';
        }
        ///checks if player moved, if moved fills last positions with blank;
        if(moved)
        {
            space[n-1][tempx]=' ';
            moved =false;
        }
        if(shot)
        {
            //hit
            if(space[buly-1][bulx]=='O')
            {
                space[buly-1][bulx]=' ';
                space[buly][bulx]=' ';
                shot=false;
                score+=10;
                mob-=1;
            }
            //miss
            else if(buly-1<=0)
            {
                space[buly][bulx]=' ';
                shot=false;
            }
            else
            {
                space[buly--][bulx]=' ';
                space[buly][bulx]='.';
            }
        }
        //redraws
        draw(space, x);
    }
    //clears
    system("CLS");
    // end game text
    cout << "GG WP!" << endl;
    cout << "Score - "<<score << endl;
    system("pause");
}
