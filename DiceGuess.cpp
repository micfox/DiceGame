//立意: 实现一个猜骰子游戏，通过与机器对战，研究可能获胜的概率和取胜策略。可以设置机器的策略。可以与玩家对战。有统计胜率的功能。

#include <iostream> 
#include <vector>
#include "DiceGuess.h"
#include "Rand_int.h"

using namespace std;


void Game::start()
{
    user.generate();
    counter.generate();
    
    user.showDices();
    counter.showDices();
}

void Player::generate()
{
    Rand_int rnd {1, 6};
    int r;
    for (int i = 0; i != 5; ++i)
    {
        r = rnd();
        dices[i] = static_cast<Dice>(r);
    }
}

void Player::showDices()
{
    cout << "Player: " << name << endl;
    cout << "{ ";
    for (int i = 0; i != DiceNumber; ++i)
    {
        cout << static_cast<int>(dices[i]) << ' ';
    }
    cout << "}\n";
}
