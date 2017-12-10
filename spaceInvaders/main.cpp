#include <iostream>
#include <windows.h>
using namespace std;
const int n = 10, m = 20;
void draw(char arr[n][m], int y)
{
    system("CLS");
    arr[n-1][y]='X';
    for(int i =0; i <n; i++)
    {
        for(int p = 0; p<m; p++)
            cout << arr[i][p];
        cout << endl;
    }
    Sleep(50);
}

int main()
{
///draw
    char space[n][m];
    /// x and y inversed
    int y = m/2, tempy, bulx, buly, score=0, mob=10;
    bool moved = false, shot=false;
    ///Fill
    for(int i =0; i <n; i++)
        for(int p = 0; p<m; p++)
            space[i][p]=' ';
    draw(space, y);
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
        tempy = y;
        if(GetAsyncKeyState(VK_RIGHT))
        {
            y++;
            moved=true;
            if(y>n-1)
            {
                y--;
                moved=false;
            }

        }

        if(GetAsyncKeyState(VK_LEFT))
        {

            y--;
            moved=true;
             if(y<0)
            {
                y++;
                moved=false;
            }
        }
        if(GetAsyncKeyState(VK_SPACE)&&!shot)
        {
            buly = n-2;
            bulx = y;
            shot=true;
            space[buly][bulx]='.';
        }
        if(moved)
        {
            space[n-1][tempy]=' ';
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
        draw(space, y);
    }
    system("CLS");
    cout << "GG WP!" << endl;
    cout << "Score - "<<score << endl;
    system("pause");
    return 0;
}
