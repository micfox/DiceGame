#include <string>

enum class Dice : char {
    One=1, Two, Three, Four, Five, Six
};

class PlayOrder {
    enum Order { UserFirst = 0, CounterFirst};
    
};

const static int DiceNumber = 5;
    
using namespace std;

class Player {
    Dice dices[DiceNumber];
    string name;
public:
    Player(string n) {name = n;}
    void generate();
    void showDices();
};

class Game {
    Player user;
    Player counter;
    PlayOrder playOrder;
    
public:
    Game()
        :user{Player{"SuperMe"}},
        counter{Player{"Computer01"}}
        {}
    void start();
    
};
