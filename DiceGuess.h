// Dice guess game
//立意: 实现一个猜骰子游戏，通过与机器对战，研究可能获胜的概率和取胜策略。可以设置机器的策略。可以与玩家对战。有统计胜率的功能。

#include <string>
#include <vector>

using namespace std;

enum class Dice : char {
    One=1, Two, Three, Four, Five, Six
};

struct Claim {
    string name;
    int num;
    Dice dice;
	Claim() { }
	Claim(string name, int num, Dice dice) {
		this->name = name;
		this->num = num;
		this->dice = dice;
	}
    operator bool() const { return num != 0; }
};


class Game_info {
    vector<string> player_list;
    int play_turn;
public:
    vector<Claim> claims;

    void add_player_name(string name) {player_list.push_back(name);}
    string get_player_name(int idx) { return player_list[idx]; }
    void init();
    int& get_turn() {return play_turn;}
    string get_last_player_name() const { return player_list[play_turn]; }
    string get_2ndlast_player_name() const; 
};

const static int DiceNumber = 5;

class Player {
protected:
    Dice dices[DiceNumber];
    string name;
    Game_info game_info;
public:
    Player(string n) {name = n;}
    Player(string name, const Game_info& game_info) { this->name = name; this->game_info = game_info; }
    
    void generate();
    void show_dices();
    int get_num(Dice dice) const;
    string get_name() const { return name; }
    virtual Claim action() = 0;
};

class UserPlayer : public Player {
public:
    UserPlayer(string name, const Game_info& game_info)
    : Player(name, game_info) { }
    Claim action();
};

class ComputerPlayer : public Player {
public:
    ComputerPlayer(string name, const Game_info& game_info)
    : Player(name, game_info) { }
    Claim action();
};

class Brain {
//devise a Claim
};

class Game {
    vector<Player*> players;
    Game_info game_info;
    
    void add_player(Player* player);
public:
    Game()
    {
        add_player(new UserPlayer{"SuperMe", game_info});
        add_player(new ComputerPlayer{"BeatCPU", game_info});
    }

	~Game() { for (auto p : players) delete p; }
	
    void display_players_dices() const;
    void start();
    void judge();
};

