//立意: 实现一个猜骰子游戏，通过与机器对战，研究可能获胜的概率和取胜策略。可以设置机器的策略。可以与玩家对战。有统计胜率的功能。

#include <iostream> 
#include <vector>
#include "DiceGuess.h"
#include "Rand_int.h"

using namespace std;


void Game::start()
{
	while (true)
	{
		cout << "Round start!\n";
		game_info.init();

		for (auto player : players)
		{
			player->generate();
			player->show_dices();
		}


		Claim claim;
		for (int i = game_info.get_turn(); claim = players[i]->action(); ) {
			game_info.claims.push_back(claim);
			if (++i == players.size()) i = 0;
		}

		judge();

		cout << "\nContinue? [y/n]\n";
		char c;
		cin >> c;
		if (c == 'y') continue;
		break;
	}
}

void Game::display_players_dices() const
{
    for (auto player : players)
       player->show_dices();
}
 
void Game::add_player(Player* player)
{
    game_info.add_player_name(player->get_name());
    players.push_back(player);
}

void Game::judge()
{
    Claim last_claim = game_info.claims.back();
    // if this claim is true, doubt player lose game
    // otherwise doubt player win
    int dice_sum = 0;
    for (auto player : players)
        dice_sum += player->get_num(last_claim.dice);

	cout << "The sum of Dice " << static_cast<int>(last_claim.dice)
		<< " is " << dice_sum << endl;

    if (dice_sum >= last_claim.num)
    {
        cout << game_info.get_2ndlast_player_name() << " win!\n";
        cout << game_info.get_last_player_name() << " lose.\n";
    }
    else
    {
        cout << game_info.get_last_player_name() << " win!\n";
        cout << game_info.get_2ndlast_player_name() << " lose.\n";
    }
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

void Player::show_dices()
{
    cout << "[ " << name << " ] dices: ";
    cout << "{ ";
    for (int i = 0; i != DiceNumber; ++i)
    {
        cout << static_cast<int>(dices[i]) << ' ';
    }
    cout << "}\n";
}

int Player::get_num(Dice dice) const
{
    int sum = 0;
    for (auto d : dices)
        if (d == dice) ++sum;
    return sum;
}

Claim UserPlayer::action()
{
	cout << this->get_name() << "'s action:\n";

    
    int num;
    int dice;
    for (;cin >> num >> dice;)
    {
		if (num == 0)
		{
			// return a empty Claim as doubt
			return Claim{"", 0, Dice::One};
		}
		if (num > DiceNumber || num < 3) {
			cout << "dice num must >=3 <= 12!\n";
			continue;
		}
		if (dice < 1 || dice > 6) {
			cout << "invalid dice!\n";
			continue;
		}
		break;
    }
    
    return Claim{name, num, static_cast<Dice>(dice)};
}

void Game_info::init()
{
    claims.clear(); 
    play_turn = Rand_int(0, player_list.size() - 1)();
}

string Game_info::get_2ndlast_player_name() const
{
    int i = play_turn - 1;
    if (i < 0) return player_list[player_list.size() - 1];
    return player_list[i];
}

