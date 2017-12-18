#ifndef GAME_H
#define GAME_H

const int n = 10, m =20;
class Game
{
public:
    Game();
    virtual ~Game();
    void main_game();
protected:
    char space[n][m];
private:
    int x = m/2, tempx, bulx, buly, score=0, mob=10;
    bool moved = false, shot=false;
    void draw(char arr[n][m], int x);
};

#endif // GAME_H
