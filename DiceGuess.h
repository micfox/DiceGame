#include <string>
#include <vector>

using namespace std;

const string doubt_word = "dbt";

enum class Dice : char {
    One=1, Two, Three, Four, Five, Six
};

struct Claim {
    string name;
    int num;
    Dice dice;
	Claim() : name{ "" }, num{ 0 }, dice{ Dice::One } { }
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


class Game {
    vector<Player*> players;
    Game_info game_info;
    
    void add_player(Player* player);
public:
    Game()
    {
        //UserPlayer p1 {"Super", game_info};
        //UserPlayer p2 {"Another", game_info};
        //add_player(p1);
        //add_player(p2);

        add_player(new UserPlayer{"SuperMe", game_info});
        add_player(new UserPlayer{"AnotherMe", game_info});
//        add_player(ComputerPlayer{"Computer01", claims});
    }

	~Game() { for (auto p : players) delete p; }
    void display_players_dices() const;
    void start();
    void judge();
};

