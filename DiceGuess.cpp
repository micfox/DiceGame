//立意: 实现一个猜骰子游戏，通过与机器对战，研究可能获胜的概率和取胜策略。可以设置机器的策略。可以与玩家对战。有统计胜率的功能。

#include <iostream> 
#include <string>
#include <vector>

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
    int r;
    for (int i = 0; i != 5; ++i)
    {
        r = rand() % 6 + 1;
        dices[i] = r;
    }
}

void Player::showDices()
{
    cout << "Player: " << name << endl;
    cout << "{ ";
    for (int i = 0; i != DiceNumber)
    {
        cout << dice[i] << ' ';
    }
    cout << "}\n";
}
