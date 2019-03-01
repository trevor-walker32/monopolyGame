#ifndef MONOPOLY_HPP_INCLUDED
#define MONOPOLY_HPP_INCLUDED 1

#include <string>
#include <iostream>
using namespace std;

class Game{
    
    public:
        Game();
        // ~Game();
        void reset();

    private:

        class Board{
            public:
                Board();
                void initProps();

                struct Tile{
                    Tile();
                    Tile(string name, bool owned, int value, int rent,
                        int mortgage, bool mortgaged, int houseCost, int houses, string owner);

                    string name_ = "";
                    bool owned_;
                    int value_;
                    int rent_;
                    int mortgage_;
                    bool mortgaged_;
                    int houseCost_;
                    int houses_ = 0;
                    string owner_ = "";
                };

                struct Player{
                    Player();
                    Player(string name, bool inPlay, int money, bool turn, int properties, int mortgages, bool jail, int turnsInJail, int currentLoc, bool getOutOfJailFree);
            
                    string name_ = "";
                    bool inPlay_ = true;
                    int money_ = 500;
                    bool turn_ = false;
                    int properties_ = 0;
                    int mortgages_ = 0;
                    bool jail_ = false;
                    int turnsInJail_ = 0;
                    int currentLoc_ = 0;
                    bool getOutOfJailFree_ = false;
                    Tile* deeds_[28];
                };

                struct ChanceCard{ // linked list
                    int cardNum_ = 0;
                    string description_ = "";
                    ChanceCard* nextCard_;
                };

                struct CommCard{ // linked list
                    int cardNum_ = 0;
                    string description_ = "";
                    CommCard* nextCard_;
                };
                
                //data members
                bool winner = false;
                int numPlayers;
                Tile* tiles[40];
                int availableProps = 28;
                Player* players[4];
                int turnNum = 0;

                ChanceCard* chanceHead = NULL;
                CommCard* commHead = NULL;

                //member functions
                Player* getCurrentPlayer();
                void switchTurns();
                void transferProps(Player* player1, Player* player2);


                void initChance();
                void initComm();

                void insertChance(string description, int cardNum);
                void insertComm(string description, int cardNum);

                void getChanceCard(); //TODO
                void getCommCard(); //TODO
                

                
                //player functions
                void rollTurn();
                void buyTurn();
                void sellTurn();
                void tradeTurn();
                void turn();
                void mortgage();
                
                void pay();

                Player& operator=(const Player& rhs); //implement this for getCurrentPlayer
                Tile& operator=(const Tile& rhs);

            private:
                friend class Game;
        };
    Board* gameboard;
};

#endif // MONOPOLY_HPP_INCLUDED