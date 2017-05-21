
enum class Dice {
    One=1, Two, Three, Four, Five, Six
};

enum class PlayOrder {
    UserFirst, CounterFirst
};

const static int DiceNumber = 5;
    
class Player {

    Dice dices[DiceNumber];
    string name;
public:
    Player(string n) {name = n;}
    void generate();
    void showDices();
}

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