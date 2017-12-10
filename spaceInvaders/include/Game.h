#ifndef GAME_H
#define GAME_H


class Game
{
public:
    Game();
    virtual ~Game();
    static void MainGame();
   void getmob_count(int mob_count);

protected:

private:
    int mob_count;

};

#endif // GAME_H
