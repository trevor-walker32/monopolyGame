
#include "monopoly.hpp"
#include <array>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <unistd.h>
#include "display.cpp"


void displayBoard(){
    
    cout << board11 << endl;
    cout << board12 << endl;
    cout << board13 << endl;
    cout << board14 << endl;
    cout << board15 << endl;
    cout << board16 << endl;
    cout << board17 << endl;
    cout << board18 << endl;
    cout << board19 << endl;
    cout << board20 << endl;
    cout << board21 << endl;
}

//messy function!
void updateBoard(int currentSpot){
    if (currentSpot < 11){ //board21
        if(currentSpot == 0){
            board21[21] = '*';
        }
        else if(currentSpot == 1){
            board21[19] = '*';
        }
        else if(currentSpot == 2){
            board21[17] = '*';
        }
        else if(currentSpot == 3){
            board21[15] = '*';
        }
        else if(currentSpot == 4){
            board21[13] = '*';
        }
        else if(currentSpot == 5){
            board21[11] = '*';
        }
        else if(currentSpot == 6){
            board21[9] = '*';
        }
        else if(currentSpot == 7){
            board21[7] = '*';
        }
        else if(currentSpot == 8){
            board21[5] = '*';
        }
        else if(currentSpot == 9){
            board21[3] = '*';
        }
        else{
            board21[1] = '*';
        }
    }
    else if (currentSpot == 11 || currentSpot ==39){ //board20
        if (currentSpot == 11){
            board20[1] = '*';
        }
        else{
            board20[21] = '*';
        }
    }
    else if (currentSpot == 12 || currentSpot ==38){ //board19
        if (currentSpot == 12){
            board19[1] = '*';
        }
        else{
            board19[21] = '*';
        }
    }
    else if (currentSpot == 13 || currentSpot ==37){ //board18
        if (currentSpot == 13){
            board18[1] = '*';
        }
        else{
            board18[21] = '*';
        }
    }
    else if (currentSpot == 14 || currentSpot ==36){ //board17
        if (currentSpot == 14){
            board17[1] = '*';
        }
        else{
            board17[21] = '*';
        }
    }
    else if (currentSpot == 15 || currentSpot ==35){ //board16
        if (currentSpot == 15){
            board16[1] = '*';
        }
        else{
            board16[21] = '*';
        }
    }
    else if (currentSpot == 16 || currentSpot ==34){ //board15
        if (currentSpot == 16){
            board15[1] = '*';
        }
        else{
            board15[21] = '*';
        }
    }
    else if (currentSpot == 17 || currentSpot ==33){ //board14
        if (currentSpot == 17){
            board14[1] = '*';
        }
        else{
            board14[21] = '*';
        }
    }
    else if (currentSpot == 18 || currentSpot ==32){ //board13
        if (currentSpot == 18){
            board13[1] = '*';
        }
        else{
            board13[21] = '*';
        }
    }
    else if (currentSpot == 19 || currentSpot ==31){ //board12
        if (currentSpot == 19){
            board12[1] = '*';
        }
        else{
            board12[21] = '*';
        }
    }
    else if (currentSpot > 19 && currentSpot < 31 ){ //board11
        if(currentSpot == 30){
            board11[21] = '*';
        }
        else if(currentSpot == 29){
            board11[19] = '*';
        }
        else if(currentSpot == 28){
            board11[17] = '*';
        }
        else if(currentSpot == 27){
            board11[15] = '*';
        }
        else if(currentSpot == 26){
            board11[13] = '*';
        }
        else if(currentSpot == 25){
            board11[11] = '*';
        }
        else if(currentSpot == 24){
            board11[9] = '*';
        }
        else if(currentSpot == 23){
            board11[7] = '*';
        }
        else if(currentSpot == 22){
            board11[5] = '*';
        }
        else if(currentSpot == 21){
            board11[3] = '*';
        }
        else{
            board11[1] = '*';
        }
    }

}

void resetBoard(){
    strncpy(board21, board10,24);
    strncpy(board20, board9, 24);
    strncpy(board19, board8, 24);
    strncpy(board18, board7, 24);
    strncpy(board17, board6, 24);
    strncpy(board16, board5, 24);
    strncpy(board15, board4, 24);
    strncpy(board14, board3, 24);
    strncpy(board13, board2, 24);
    strncpy(board12, board1, 24);
    strncpy(board11, board0, 24);
}

Game::Game()
{
    //start the game
    Board* newGame = new Board();
    
    while(!newGame->winner){
        newGame->turn();
    }
    string answer = "";
    cin >> answer;
    if(answer == "yes"){
        Game();
    }
    else{
        cout << "thank you for playing!" << endl;
    }
    // need to destroy the new players and tiles
}


// TODO make the destructor
// Game::~Game()
// {
//     for(int i = 0; i < 40; ++i){
//         delete gameboard->tiles[i];
//     }
//     for(int i = 0; i < 2; ++i){
//         delete gameboard->players[i];
//     }
//     delete *gameboard;
// }

Game::Board::Board()
{
    cout << "How many players are playing?" << endl;
    cin >> numPlayers;
    if(numPlayers > 4){
        numPlayers = 4;
        cout << "4 players will play then" << endl;
    }
    else if(numPlayers < 0){
        numPlayers = 2;
        cout << "2 players will play then" << endl;
    }
    else{
        cout << "lets play!" << endl;
    }

    initProps();
    initChance();
    initComm();

    for(int i = 0; i < numPlayers; i++){
        string name1 = "";
        players[i] = new Player();
        cout << "Name of Player " << i+1 << endl;
        cin >> name1;
        players[i]->name_ = name1;
    }
    players[0]->turn_ = true;
}
void Game::Board::initProps(){

    //init all tile spaces
    for(int i = 0; i < 40; ++i){
        tiles[i] = new Tile("",false,0,0,0,false,0,0,"");
    }
    tiles[0]->name_ = "Go";

    tiles[1]->name_ = "Mediterranean";
    tiles[1]->value_ = 60;
    tiles[1]->rent_ = 2;
    tiles[1]->mortgage_ = 30;
    tiles[1]->houseCost_ = 50;
    
    tiles[2]->name_ = "Community Chest";

    tiles[3]->name_ = "Baltic";
    tiles[3]->value_ = 60;
    tiles[3]->rent_ = 4;
    tiles[3]->mortgage_ = 30;
    tiles[3]->houseCost_ = 50;

    tiles[4]->name_ = "Income Tax";

    tiles[5]->name_ = "Railroad1";
    tiles[5]->value_ = 200;
    tiles[5]->rent_ = 25;
    tiles[5]->mortgage_ = 100;


    tiles[6]->name_ = "Oriental";
    tiles[6]->value_ = 100;
    tiles[6]->rent_ = 6;
    tiles[6]->mortgage_ = 50;
    tiles[6]->houseCost_ = 50;

    tiles[7]->name_ = "Chance";

    tiles[8]->name_ = "Vermont";
    tiles[8]->value_ = 100;
    tiles[8]->rent_ = 6;
    tiles[8]->mortgage_ = 50;
    tiles[8]->houseCost_ = 50;

    tiles[9]->name_ = "Connecticut";
    tiles[9]->value_ = 120;
    tiles[9]->rent_ = 8;
    tiles[9]->mortgage_ = 50;
    tiles[9]->houseCost_ = 50;

    tiles[10]->name_ = "Jail";

    tiles[11]->name_ = "StCharles";
    tiles[11]->value_ = 140;
    tiles[11]->rent_ = 10;
    tiles[11]->mortgage_ = 70;
    tiles[11]->houseCost_ = 100;

    tiles[12]->name_ = "ElectricCompany";
    tiles[12]->value_ = 150;
    tiles[12]->rent_ = 75;
    tiles[12]->mortgage_ = 75;

    tiles[13]->name_ = "States";
    tiles[13]->value_ = 140;
    tiles[13]->rent_ = 10;
    tiles[13]->mortgage_ = 70;
    tiles[13]->houseCost_ = 100;

    tiles[14]->name_ = "Virginia";
    tiles[14]->value_ = 160;
    tiles[14]->rent_ = 12;
    tiles[14]->mortgage_ = 80;
    tiles[14]->houseCost_ = 100;
    
    tiles[15]->name_ = "Railroad2";
    tiles[15]->value_ = 200;
    tiles[15]->rent_ = 25;
    tiles[15]->mortgage_ = 100;

    tiles[16]->name_ = "StJames";
    tiles[16]->value_ = 180;
    tiles[16]->rent_ = 14;
    tiles[16]->mortgage_ = 90;
    tiles[16]->houseCost_ = 100;

    tiles[17]->name_ = "Community Chest";

    tiles[18]->name_ = "Tennessee";
    tiles[18]->value_ = 180;
    tiles[18]->rent_ = 14;
    tiles[18]->mortgage_ = 90;
    tiles[18]->houseCost_ = 100;

    tiles[19]->name_ = "NewYork";
    tiles[19]->value_ = 200;
    tiles[19]->rent_ = 16;
    tiles[19]->mortgage_ = 100;
    tiles[19]->houseCost_ = 100;

    tiles[20]->name_ = "Free Parking";

    tiles[21]->name_ = "Kentucky";
    tiles[21]->value_ = 220;
    tiles[21]->rent_ = 18;
    tiles[21]->mortgage_ = 110;
    tiles[21]->houseCost_ = 150;

    tiles[22]->name_ = "Chance";

    tiles[23]->name_ = "Indiana";
    tiles[23]->value_ = 220;
    tiles[23]->rent_ = 18;
    tiles[23]->mortgage_ = 110;
    tiles[23]->houseCost_ = 150;

    tiles[24]->name_ = "Illinois";
    tiles[24]->value_ = 220;
    tiles[24]->rent_ = 20;
    tiles[24]->mortgage_ = 120;
    tiles[24]->houseCost_ = 150;

    tiles[25]->name_ = "Railroad3";
    tiles[25]->value_ = 200;
    tiles[25]->rent_ = 25;
    tiles[25]->mortgage_ = 100;

    tiles[26]->name_ = "Atlantic";
    tiles[26]->value_ = 260;
    tiles[26]->rent_ = 22;
    tiles[26]->mortgage_ = 130;
    tiles[26]->houseCost_ = 150;

    tiles[27]->name_ = "Ventnor";
    tiles[27]->value_ = 260;
    tiles[27]->rent_ = 22;
    tiles[27]->mortgage_ = 130;
    tiles[27]->houseCost_ = 150;

    tiles[28]->name_ = "WaterWorks";
    tiles[28]->value_ = 150;
    tiles[28]->rent_ = 75;
    tiles[28]->mortgage_ = 75;
    
    tiles[29]->name_ = "MarvinGardens";
    tiles[29]->value_ = 280;
    tiles[29]->rent_ = 24;
    tiles[29]->mortgage_ = 140;
    tiles[29]->houseCost_ = 150;

    tiles[30]->name_ = "Go to Jail";

    tiles[31]->name_ = "Pacific";
    tiles[31]->value_ = 300;
    tiles[31]->rent_ = 26;
    tiles[31]->mortgage_ = 150;
    tiles[31]->houseCost_ = 200;

    tiles[32]->name_ = "NorthCarolina";
    tiles[32]->value_ = 300;
    tiles[32]->rent_ = 26;
    tiles[32]->mortgage_ = 150;
    tiles[32]->houseCost_ = 200;

    tiles[33]->name_ = "Community Chest";

    tiles[34]->name_ = "Pennsylvannia";
    tiles[34]->value_ = 320;
    tiles[34]->rent_ = 28;
    tiles[34]->mortgage_ = 160;
    tiles[34]->houseCost_ = 200;

    tiles[35]->name_ = "Railroad4";
    tiles[35]->value_ = 200;
    tiles[35]->rent_ = 25;
    tiles[35]->mortgage_ = 100;

    tiles[36]->name_ = "Chance";

    tiles[37]->name_ = "ParkPlace";
    tiles[37]->value_ = 350;
    tiles[37]->rent_ = 35;
    tiles[37]->mortgage_ = 175;
    tiles[37]->houseCost_ = 200;

    tiles[38]->name_ = "Luxury Tax";

    tiles[39]->name_ = "Boardwalk";
    tiles[39]->value_ = 400;
    tiles[39]->rent_ = 50;
    tiles[39]->mortgage_ = 200;
    tiles[39]->houseCost_ = 200;

}


/*------------------------------------------
Constructors
------------------------------------------*/
Game::Board::Player::Player()
{
    for(int i = 0; i < 28; i++){
        deeds_[i] = new Tile();
    }
}

Game::Board::Player::Player(string name, bool inPlay, int money, bool turn, int properties, int mortgages, bool jail, int turnsInJail, int currentLoc, bool getOutOfJailFree)
:
name_{name},
inPlay_{inPlay},
money_{money},
turn_{turn},
properties_{properties},
mortgages_{mortgages},
jail_{jail},
turnsInJail_{turnsInJail},
currentLoc_{currentLoc},
getOutOfJailFree_{getOutOfJailFree}
{}

Game::Board::Tile::Tile()
{}

Game::Board::Tile::Tile(string name, bool owned, int value, int rent, int mortgage, bool mortgaged, int houseCost, int houses, string owner)
:
name_{name},
owned_{owned},
value_{value},
rent_{rent},
mortgage_{mortgage},
mortgaged_{mortgaged},
houseCost_{houseCost},
houses_{houses},
owner_{owner}
{}


/*------------------------------------------
local functions
------------------------------------------*/

int roll()
{
    int roll;
    int min = 2; // the min number a die can roll is 1
    int max = 12;// this->dieSize; // the max value is the die size
    roll = rand() % (max - min + 1) + min;
    return roll;
}

/*------------------------------------------
Game functions
------------------------------------------*/
void Game::reset()
{
    //TODO
}

/*------------------------------------------
Board functions
------------------------------------------*/
Game::Board::Player* Game::Board::getCurrentPlayer()
{
    for(int i = 0; i < numPlayers; i++){
        if(players[i]->turn_ == true){
            return players[i];
        }
    }
    cout << "could not find the current player" << endl;
    return NULL;
} // going to need to make an assignment operator for Player*


void Game::Board::switchTurns()
{   
    for(int i = 0; i < numPlayers; i++)
    {
        if(players[i]->turn_ == true)
        {
            players[i]->turn_ = false;
            if(i == (numPlayers-1))
            {
                players[0]->turn_ = true;
                return;
            }
            else
            {
                players[i+1]->turn_ = true;
                return;
            }
        }
    }
}

void Game::Board::transferProps(Player* player1, Player* player2)
{
    if(player1->name_ != player2->name_)
    {
        if(player1->inPlay_ == true && player2->inPlay_ == true)
        {
            for(int i = 0; i < player1->properties_; i++)
            {   
                string name3 = player1->deeds_[i]->name_;
                bool owned3 = true;
                int value3 = player1->deeds_[i]->value_;
                int rent3 = player1->deeds_[i]->rent_;
                int mortgage3 = player1->deeds_[i]->mortgage_;
                bool mortgaged3 = true;
                int houseCost3 = player1->deeds_[i]->houseCost_;
                int houses3 = 0;
                string owner3 = player2->name_;

                player2->deeds_[player2->properties_] = new Tile(name3,owned3,value3,rent3,mortgage3,mortgaged3,houseCost3,houses3,owner3);

                player2->properties_++;
                delete player1->deeds_[i];
            }
            player2->mortgages_ += player1->mortgages_;
            
            cout << "here are the new list of properties for " << player2->name_ << endl;
            for(int i = 0; i < player2->properties_; i++)
            {
                cout << "property name: " << player2->deeds_[i]->name_ << endl;
            }
        }
        else{
            cout << "one of the players does not exist anymore!" << endl;
            return;
        }
    }
}

void Game::Board::initChance()
{
    insertChance("advance to the nearest railroad!",1);
    insertChance("your building a loan matures, collect 150$",2);
    insertChance("get out of jail free card",3);
    insertChance("advance to Go!",4);
    insertChance("go directly to jail!",5);
    insertChance("go back three spaces",6);
    insertChance("pay poor tax of 15$",7);
    insertChance("bank pays you a dividend of 50$",8);
    insertChance("advance to the nearest railroad!",9);
    insertChance("you have been elected chairman of the board, pay each player 50$",10);
    insertChance("advance to Illinois ave",11);
    insertChance("Make general repairs on all properties",12);
    insertChance("advance to the nearest utility",13);
    insertChance("advance to boardwalk",14);
    insertChance("advance to st. charles place!",15);
    insertChance("take a ride on the reading railroad",16);
}
void Game::Board::initComm()
{
    insertComm("Income tax refund, collect 20$",1);
    insertComm("you have won second prize in a beauty contest, collect 10$",2);
    insertComm("You are assessed for street repairs",3);
    insertComm("from sale of stock, you get 45$",4);
    insertComm("Life insurance matures, collect 150$",5);
    insertComm("You inherit 100$",6);
    insertComm("pay hospital 100$",7);
    insertComm("Grand Opening at the Opera, collect 50$ from every player",8);
    insertComm("Go to jail, go directly to jail, do not pass go, do not collect 200$",9);
    insertComm("get out of jail free card!",10);
    insertComm("doctors fee, pay 50$",11);
    insertComm("bank error in your favor, collect 200$",12);
    insertComm("advance to go!",13);
    insertComm("Christmas fund matures, collect 100$",14);
    insertComm("Pay school tax of 150$",15);
    insertComm("Receive for services, 25$",16);
}

void Game::Board::insertChance(string description, int cardNum)
{
    ChanceCard* newCard = new ChanceCard();
    newCard->description_ = description;
    newCard->cardNum_ = cardNum;
    newCard->nextCard_ = chanceHead;
    chanceHead = newCard;
}

void Game::Board::insertComm(string description, int cardNum)
{
    CommCard* newCard = new CommCard();
    newCard->description_ = description;
    newCard->cardNum_ = cardNum;
    newCard->nextCard_ = commHead;
    commHead = newCard;
}

void Game::Board::getChanceCard()
{   
    Player* currentPlayer = getCurrentPlayer();
    int currentSpot = currentPlayer->currentLoc_;
    ChanceCard* currentCard = chanceHead;
    chanceHead = chanceHead->nextCard_;
    
    if(chanceHead == NULL){
        initChance();
    }

    cout << "your card says: " << endl;
    cout << currentCard->description_ << endl;
    int number = currentCard->cardNum_;

    if(number == 3) //get out of jail free card
    {
        currentPlayer->getOutOfJailFree_ = true;
    }
    else if(number == 1 || number == 9) //advance to the nearest railroad
    {
        for(int i = currentSpot; i < 45; i++)
        {
            if(i == 5)
            {
                currentSpot = i;
                break;
            }
            else if(i == 15)
            {
                currentSpot = i;
                break;
            }
            else if(i == 25)
            {
                currentSpot = i;
                break;
            }
            else if(i == 35)
            {
                currentSpot = i;
                break;
            }
            else if(i == 45)
            {
                currentSpot = 5;
                break;
            }
        }
        currentPlayer->currentLoc_ = currentSpot;
    }
    else if(number == 2) //building loan matures
    {
        currentPlayer->money_ += 150;
    }
    else if(number == 4) //advance to go
    {
        currentPlayer->currentLoc_ = 0;
    }
    else if(number == 5) //go to jail
    {
        currentPlayer->currentLoc_ = 9;
        currentPlayer->jail_ = true;
        currentPlayer->turnsInJail_ = 3;
    }
    else if(number == 6) //go back three spaces
    {
        currentPlayer->currentLoc_ -= 3;
    }
    else if(number == 7) //pay poor tax
    {
        currentPlayer->money_ -= 15;
    }
    else if(number == 8) //collect 50
    {
        currentPlayer->money_ += 50;
    }
    else if(number == 10) //pay each player 50
    {
        int counter = 0;
        for(int i = 0; i < numPlayers; i++){
            if(players[i]->name_ != currentPlayer->name_){
                if(players[i]->inPlay_ == true){
                    players[i]->money_ += 50;
                    counter++;
                }
            }
        }
        currentPlayer->money_ -= (counter * 50);
        
    }
    else if(number == 11) //advance to illinois
    {
        currentPlayer->currentLoc_ = 24;
    }
    else if(number == 12) //make general repairs
    {
        int houseCount = 0;
        for(int i = 0; i < currentPlayer->properties_;i++){
            if(currentPlayer->deeds_[i]->mortgaged_ == false){
                houseCount += currentPlayer->deeds_[i]->houses_;
            }
        }
        currentPlayer->money_ -= (houseCount * 50);
    }
    else if(number == 13) //advance to nearest utility
    {
        for(int i = currentSpot; i < 53; i++)
        {
            if(i == 12)
            {
                currentSpot = i;
                break;
            }
            else if(i == 28)
            {
                currentSpot = i;
                break;
            }
            else if(i == 52)
            {
                currentSpot = 12;
                break;
            }
        }
        currentPlayer->currentLoc_ = currentSpot;
    }
    else if(number == 14) //advance to boardwalk
    {
        currentPlayer->currentLoc_ = 39;
    }
    else if(number == 15)
    {
        currentPlayer->currentLoc_ = 11;
    }
    else
    {
        currentPlayer->currentLoc_ = 5;
    }

    Player* owner = new Player();
    string ownerName = tiles[currentSpot]->owner_;
    if(ownerName != "")
    {
        cout << "this property is owned by " << ownerName << endl;
        for(int i = 0; i < numPlayers; i++)
        {
            if(players[i]->name_ == ownerName)
            {
                owner = players[i];
            }
        }
        if(currentSpot == 12 || currentSpot == 28){ //player owns utility
            cout << "roll to see amount paid" << endl;
            int rollNum = roll();
            cout << "you rolled a " << rollNum << endl;
            int amount = 10*rollNum;
            owner->money_ += amount;
            currentPlayer->money_ -= amount;
        }
        else if(currentSpot == 5 || currentSpot == 15 || currentSpot == 25 || currentSpot == 35){ //player owns railroad
            owner->money_ += (2 * tiles[currentSpot]->rent_);
            currentPlayer->money_ -= (2 * tiles[currentSpot]->rent_);
        }
        else{ //player owns reg property
            owner->money_ += tiles[currentSpot]->rent_;
            currentPlayer->money_ -= tiles[currentSpot]->rent_;
        }
        if(currentPlayer->money_ < 0){
            mortgage();
        }
    }
    else
    {
        string choice = "";
        cout << "would you like to buy this property? yes/no" << endl;
        cin >> choice;
        int newSpot = currentPlayer->currentLoc_;
        if(choice == "yes")
        {
            if(currentPlayer->money_ < tiles[newSpot]->value_)
            {
                cout << "you do not have enough money for this property" << endl;
                return;
            }
            else
            {
                currentPlayer->money_ -= tiles[newSpot]->value_;
                tiles[newSpot]->owned_ = true;
                tiles[newSpot]->owner_ = currentPlayer->name_;

                string name1 = tiles[newSpot]->name_;
                bool owned1 = tiles[newSpot]->owned_;
                int value1 = tiles[newSpot]->value_;
                int rent1 = tiles[newSpot]->rent_;
                int mortgage1 = tiles[newSpot]->mortgage_;
                bool mortgaged1 = tiles[newSpot]->mortgaged_;
                int houseCost1 = tiles[newSpot]->houseCost_;
                int houses1 = tiles[newSpot]->houses_;
                string owner1 = tiles[newSpot]->owner_;

                currentPlayer->deeds_[currentPlayer->properties_] = new Tile(name1, owned1, value1, rent1, mortgage1, mortgaged1, houseCost1, houses1, owner1);
                currentPlayer->properties_++;

                availableProps--;
            }
        }
    }
}

void Game::Board::getCommCard()
{
    Player* currentPlayer = getCurrentPlayer();
    CommCard* currentCard = commHead;
    commHead = commHead->nextCard_;

    if(commHead == NULL)
    {
        initComm();
    }

    cout << "your card says: " << endl;
    cout << currentCard->description_ << endl;
    int number = currentCard->cardNum_;
    
    if(number == 10)
    {
        currentPlayer->getOutOfJailFree_ = true;
    }
    else if(number == 1)
    {
        currentPlayer->money_ += 20;
    }
    else if(number == 2)
    {
        currentPlayer->money_ += 10;
    }
    else if(number == 4)
    {
        currentPlayer->money_ += 45;
    }
    else if(number == 5)
    {
        currentPlayer->money_ += 150;
    }
    else if(number == 6)
    {
        currentPlayer->money_ += 100;
    }
    else if(number == 7)
    {
        currentPlayer->money_ -= 100;
    }
    else if(number == 8)
    {
        for(int i = 0; i < numPlayers; i++){
            if(players[i]->name_ != currentPlayer->name_){
                if(players[i]->inPlay_ == true){
                    players[i]->money_ -= 50;
                    currentPlayer->money_ += 50;
                }
            }
        }        
    }
    else if(number == 9)
    {
        currentPlayer->currentLoc_ = 9;
        currentPlayer->jail_ = true;
        currentPlayer->turnsInJail_ = 3;
    }
    else if(number == 3)
    {
        int houseCount = 0;
        for(int i = 0; i < currentPlayer->properties_;i++){
            if(currentPlayer->deeds_[i]->mortgaged_ == false){
                houseCount += currentPlayer->deeds_[i]->houses_;
            }
        }
        currentPlayer->money_ -= (houseCount * 50);

        if(currentPlayer->money_ < 0){
            mortgage();
        }
    }
    else if(number == 11)
    {
        currentPlayer->money_ -= 50;
    }
    else if(number == 12)
    {
        currentPlayer->money_ += 200;
    }
    else if(number == 13)
    {
        currentPlayer->currentLoc_ = 0;
        currentPlayer->money_ += 500;
    }
    else if(number == 14)
    {
        currentPlayer->money_ += 100;
    }
    else if(number == 15)
    {
        currentPlayer->money_ -= 150;
    }
    else
    {
        currentPlayer->money_ += 25;
    }
}

/*------------------------------------------
Player functions
------------------------------------------*/

void Game::Board::rollTurn()
{
    Player* currentPlayer = getCurrentPlayer();
    
    if(currentPlayer == NULL)
    {
        return;
    }
    int currentSpot = currentPlayer->currentLoc_;

    if(currentPlayer->jail_ == true)
    { //is the current player in jail?
        if(currentPlayer->turnsInJail_ == 0 || currentPlayer->getOutOfJailFree_ == true)
        {
            currentPlayer->jail_ = false;
            currentPlayer->turnsInJail_ = 0;
            currentPlayer->currentLoc_ = 10;
        }
        else
        {
            cout << "you are in jail, roll the same roll twice to see if you get out" << endl;
            int roll1 = roll();
            cout << "you rolled a " << roll1 << endl;
            int roll2 = roll();
            cout << "you rolled a " << roll2 << endl;
            if(roll1 == roll2)
            {
                currentPlayer->jail_ = false;
                currentPlayer->turnsInJail_ = 0;
                cout<<"congrats, you rolled the same roll twice."<<endl;
                cout<<"roll again to start your turn"<<endl;
            }
            else
            {
                currentPlayer->turnsInJail_--;
                return;
            }
        }
    }

    int rollNum = roll();
    cout<<"you rolled a "<<rollNum<<endl;

    currentSpot = (currentSpot + rollNum) % 40;
    
    currentPlayer->currentLoc_ = currentSpot;
    cout << "player landed on: " << tiles[currentSpot]->name_ <<endl;

    if(currentSpot == 30)
    {//go to jail
        cout<<"go to jail, go directly to jail, do not pass go, do not collect 200$"<<endl;
        currentPlayer->jail_ = true;
        currentPlayer->turnsInJail_ = 3;
        currentPlayer->currentLoc_ = 10;
    }
    else if(currentSpot == 0 || currentSpot == 20)
    {//land on go or free parking
        currentPlayer->money_ += 500;
    }
    else if(currentSpot == 2 || currentSpot == 17 || currentSpot == 33)
    {//community chest
        getCommCard();
        if(currentPlayer->money_ < 0)
        {
            mortgage();
        }
    }
    else if(currentSpot == 7 || currentSpot == 22 || currentSpot == 36)
    {//chance
        getChanceCard();
        if(currentPlayer->money_ < 0)
        {
            mortgage();
        }
    }
    else if(currentSpot == 4 || currentSpot == 38)
    {//tax spaces
        currentPlayer->money_ -= 100;
        if(currentPlayer->money_ < 0)
        {
            mortgage();
        }
    }
    else if(currentSpot == 10)
    {//land on jail
        //bail out
        for(int i = 0; i < numPlayers; i++){
            string choice = "";
            if(players[i]->jail_ == true){
                cout << "would you like to bail " << players[i]->name_ << " out? (yes/no)" <<endl; 
                cin >> choice;
                if(choice == "yes"){
                    currentPlayer->money_ -= 50;
                    players[i]->jail_ = false;
                    players[i]->turnsInJail_ = 0;
                    players[i]->currentLoc_ = 10;
                }
            }
        }
    }
    else if(tiles[currentSpot]->owned_ == true)
    {//land on owned property
        if(tiles[currentSpot]->mortgaged_ == true){
            cout << tiles[currentSpot]->name_ << " is mortgaged, no rent will be collected" << endl;
        }
        else if(tiles[currentSpot]->owner_ == currentPlayer->name_){ 
            cout << "you own this property" << endl;
            return;
        }
        else{
            pay(); // current players money gets deducted
            
        }
    }
    else
    {//land on unowned property
        if(availableProps == 0)
        {
            return;
        }
        string decision = "";
        cout<<"Would you like to buy this property? (yes/no)"<<endl;
        cin>>decision;
        if(decision == "yes")
        {
            if(currentPlayer->money_ < tiles[currentSpot]->value_)
            {
                cout<<"You do not have enough money for this property"<<endl;
                return;
            }
            else
            {
                currentPlayer->money_ -= tiles[currentSpot]->value_;
                tiles[currentSpot]->owned_ = true;
                tiles[currentSpot]->owner_ = currentPlayer->name_;

                string name1 = tiles[currentSpot]->name_;
                bool owned1 = tiles[currentSpot]->owned_;
                int value1 = tiles[currentSpot]->value_;
                int rent1 = tiles[currentSpot]->rent_;
                int mortgage1 = tiles[currentSpot]->mortgage_;
                bool mortgaged1 = tiles[currentSpot]->mortgaged_;
                int houseCost1 = tiles[currentSpot]->houseCost_;
                int houses1 = tiles[currentSpot]->houses_;
                string owner1 = tiles[currentSpot]->owner_;

                currentPlayer->deeds_[currentPlayer->properties_] = new Tile(name1, owned1, value1, rent1, mortgage1, mortgaged1, houseCost1, houses1, owner1);
                currentPlayer->properties_++;

                availableProps--;
            }
        }
    }
}

void Game::Board::buyTurn() // pretty sure this works
{   
    Player* currentPlayer = getCurrentPlayer();
    cout << "what would you like to buy?" << endl;
    cout << "unmortgage | houses | go back"<< endl;
    string decision = "";
    while(cin >> decision)
    {
        if(decision == "unmortgage")
        {   
            Tile* property;
            string propertyName = "";
            cout << "for which property?" << endl;
            cin >> propertyName;
            for(int i = 0; i < currentPlayer->properties_; i++)
            {
                if(currentPlayer->deeds_[i]->name_ == propertyName)
                {
                    property = currentPlayer->deeds_[i];
                }
            }
            if(property == NULL)
            {
                cout << "property not found" << endl;
                cout << "unmortgage | houses | go back"<< endl;
            } 
            else if(property->owner_ != currentPlayer->name_)
            {
                cout << "property not in players possession" << endl;
                cout << "unmortgage | houses | go back"<< endl;
            }
            else if(property->mortgaged_ == true)
            {
                cout << "property is not mortgaged" << endl;
                cout << "unmortgage | houses | go back"<< endl;
            }
            else{
                if(currentPlayer->money_ < property->mortgage_){
                    cout << "you do not have enough money to unmortgage this property" << endl;
                    cout << "unmortgage | houses | go back"<< endl;
                }
                else{
                    string choice = "";
                    cout << "the cost to unmortgage is: " << property->mortgage_ << endl;
                    cout << "you have " << currentPlayer->money_ << endl;

                    currentPlayer->money_ -= property->mortgage_;
                    property->mortgaged_ = false;

                    cout << "would you like to buy something else? yes/no"<<endl;
                    cin >> choice;
                    if(choice == "yes"){
                        cout << "unmortgage | houses | go back"<< endl;
                    }
                    else{
                        break;
                    }
                }
                
            }

            
        }
        else if(decision == "houses")
        {
            Tile* property;
            string propertyName = "";
            cout << "for which property?" << endl;
            cin >> propertyName;
            for(int i = 0; i < currentPlayer->properties_; i++)
            {
                if(currentPlayer->deeds_[i]->name_ == propertyName)
                {
                    property = currentPlayer->deeds_[i];
                }
            }
            if(property == NULL)
            {
                cout << "property not found" << endl;
                cout << "unmortgage | houses | go back"<< endl;
            } 
            else if(property->owner_ != currentPlayer->name_)
            {
                cout << "property not in players possession" << endl;
                cout << "unmortgage | houses | go back"<< endl;
            }
            else if(property->mortgaged_ == true)
            {
                cout << "this property is mortgaged, you first need to unmortgage it before you buy houses" << endl;
                cout << "unmortgage | houses | go back"<< endl;
            }
            else{
                if(currentPlayer->money_ < property->houseCost_){
                    cout << "you do not have enough money to buy a house for this property" << endl;
                    cout << "unmortgage | houses | go back"<< endl;
                }
                else if(property->houses_ > 5)
                {
                    cout << "unfortunately, this property already has the maximum amount of buildings on it" << endl;
                    cout << "unmortgage | houses | go back"<< endl;
                }
                else
                {
                    cout << "the cost of one house is: " << property->houseCost_ << endl;
                    cout << "you have " << currentPlayer->money_ << endl;
                    int houseNum = 0;
                    cout << "how many would you like to buy?" << endl;
                    cin >> houseNum;
                    if(houseNum * property->houseCost_ > currentPlayer->money_){
                        cout << "you can not buy this many houses with the money you have" << endl;
                        cout << "unmortgage | houses | go back"<< endl; 
                    }
                    else if(property->houses_ + houseNum > 5)
                    {
                        cout << "you can not buy more than 5 houses for this property" << endl;
                        cout << "this property currently has " << property->houses_ << " houses" << endl;
                        cout << "unmortgage | houses | go back"<< endl;
                    }
                    else
                    {   
                        string choice = "";
                        currentPlayer->money_ -= (houseNum * property->houseCost_);
                        property->houses_ += houseNum;
                        cout << "would you like to buy something else? yes/no"<<endl;
                        cin >> choice;
                        if(choice == "yes"){
                            cout << "unmortgage | houses | go back"<< endl;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            break;
        }

    }
    
}

void Game::Board::sellTurn() // pretty sure this works too
{
    Player* currentPlayer = getCurrentPlayer();
    cout << "what would you like to sell?" << endl;
    cout << "mortgage | houses | go back"<< endl;
    string decision = "";
    while(cin >> decision)
    {
        if(decision == "mortgage")
        {   
            Tile* property;
            string propertyName = "";
            cout << "for which property?" << endl;
            cin >> propertyName;
            for(int i = 0; i < currentPlayer->properties_; i++)
            {
                if(currentPlayer->deeds_[i]->name_ == propertyName)
                {
                    property = currentPlayer->deeds_[i];
                }
            }
            if(property == NULL)
            {
                cout << "property not found" << endl;
                cout << "mortgage | houses | go back"<< endl;
            } 
            else if(property->owner_ != currentPlayer->name_)
            {
                cout << "property not in players possession" << endl;
                cout << "mortgage | houses | go back"<< endl;
            }
            else if(property->mortgaged_ == true)
            {
                cout << "property is already mortgaged" << endl;
                cout << "mortgage | houses | go back"<< endl;
            }
            else if(property->houses_ != 0){
                cout << "property has houses on it, you must sell them first" << endl;
                cout << "mortgage | houses | go back"<< endl; 
            }
            else{
                
                string choice = "";
                cout << "the value of mortgage is: " << property->mortgage_ << endl;
                cout << "you have " << currentPlayer->money_ << endl;

                currentPlayer->money_ += property->mortgage_;
                property->mortgaged_ = true;

                cout << "would you like to sell something else? yes/no"<<endl;
                cin >> choice;
                if(choice == "yes"){
                    cout << "mortgage | houses | go back"<< endl;
                }
                else{
                    break;
                }
                
            }

            
        }
        else if(decision == "houses")
        {
            Tile* property;
            string propertyName = "";
            cout << "for which property?" << endl;
            cin >> propertyName;
            for(int i = 0; i < currentPlayer->properties_; i++)
            {
                if(currentPlayer->deeds_[i]->name_ == propertyName)
                {
                    property = currentPlayer->deeds_[i];
                }
            }
            if(property == NULL)
            {
                cout << "property not found" << endl;
                cout << "mortgage | houses | go back"<< endl;
            } 
            else if(property->owner_ != currentPlayer->name_)
            {
                cout << "property not in players possession" << endl;
                cout << "mortgage | houses | go back"<< endl;
            }
            else if(property->mortgaged_ == true)
            {
                cout << "this property is mortgaged with no houses" << endl;
                cout << "mortgage | houses | go back"<< endl;
            }
            else{
                if(property->houses_ == 0){
                    cout << "there are no houses on this property" << endl;
                    cout << "mortgage | houses | go back"<< endl;
                }
                else
                {
                    cout << "the value of one house is: " << property->houseCost_ << endl;
                    cout << "you have " << property->houses_ << "houses on this property" << endl;
                    int houseNum = 0;
                    cout << "how many would you like to sell?" << endl;
                    cin >> houseNum;
                    if(property->houses_ - houseNum < 0){
                        cout << "you can not sell this many houses" << endl;
                        cout << "mortgage | houses | go back"<< endl; 
                    }
                    else
                    {   
                        string choice = "";
                        currentPlayer->money_ += (houseNum * property->houseCost_);
                        property->houses_ -= houseNum;
                        cout << "would you like to sell something else? yes/no"<<endl;
                        cin >> choice;
                        if(choice == "yes"){
                            cout << "mortgage | houses | go back"<< endl;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            break;
        }

    }
    
}

void Game::Board::tradeTurn() // TODO test this
{   
    string player = "";
    Player* currentPlayer = getCurrentPlayer();
    Player* otherPlayer;
    cout << "who would you like to trade with?" << endl;
    cin >> player;
    for(int i = 0; i < numPlayers; i++){
        if(player == players[i]->name_){
            otherPlayer = players[i];
        }
    }
    if(otherPlayer == NULL){
        cout << "player not found" << endl;
    }
    else if(otherPlayer->name_ == currentPlayer->name_){
        cout << "can not trade with yourself!" << endl;
    }
    else{
        string trade = "";
        cout << "what would you like to offer " << otherPlayer->name_ << "?" << endl;
        cout << "property | card | money" << endl;
        cin >> trade;
        string item = "";
        cout << "what would you like in return?" << endl;
        cout << "property | card | money" << endl;
        cin >> item;

        string decision = "";
        cout << "does " << otherPlayer->name_ << " even want to trade? yes/no" << endl;
        cin >> decision;
        if(decision == "yes"){
            if(trade == "property"){
                string propName = "";
                Tile* property;
                cout << "which deed would you like to trade?" << endl;
                cin >> propName;
                cout << "the for loop is the issue" <<endl;
                for(int i = 0; i < currentPlayer->properties_; i++){
                    if(currentPlayer->deeds_[i]->name_ == propName){ // TODO either this loop causes a seg fault, or the transfer of the properties is causing it.
                        property = currentPlayer->deeds_[i]; // nevermind, certain properties are the issue
                    }
                }
                cout << "got to line 1426" ;
                if(property == NULL){
                    cout << "property not found" << endl;
                    cout << "line1429" <<endl ;
                    return;
                }
                else if(property->owned_ == false){
                    cout << "no one owns this property" << endl;
                    cout << "line1434" <<endl ;
                    return;
                }
                else if(property->owner_ != currentPlayer->name_){
                    cout << "you can not trade someone else's property" << endl;
                    cout << "line1439" <<endl ;
                    return;
                }
                else{
                    cout << "got to line 1443" ;
                    if(item == "property"){ //trade a property for a property
                        string propName1 = "";
                        Tile* property1;
                        cout << "which deed would you like in return?" << endl;
                        cin >> propName1;
                        for(int i = 0; i < otherPlayer->properties_; i++){
                            if(otherPlayer->deeds_[i]->name_ == propName1){
                                property1 = otherPlayer->deeds_[i];
                            }
                        }
                        if(property1 == NULL){
                            cout << "property not found" << endl;
                            return;
                        }
                        else if(property1->owned_ == false){
                            cout << "no one owns this property" << endl;
                            return;
                        }
                        else if(property1->owner_ != otherPlayer->name_){
                            cout << "the other player does not own this property" << endl;
                            return;
                        }
                        else{
                            cout << "the trade is: "<< endl;
                            cout << currentPlayer->name_ << " will trade " << property->name_ << " for " << endl;
                            cout << otherPlayer->name_ << "'s " << property1->name_ << endl;
                            string deal = "";
                            cout << "do both players accept this deal?" << endl;
                            cin >> deal;
                            if(deal == "yes"){
                                
                                Tile* temp = new Tile(property->name_,property->owned_,property->value_,property->rent_,property->mortgage_,property->mortgaged_,property->houseCost_,property->houses_,property->owner_);
                                property = property1;
                                property1 = temp;
                                property->owner_ = currentPlayer->name_;
                                property1->owner_ = otherPlayer->name_;

                                for(int i = 0; currentPlayer->properties_;i++){ 
                                    if(currentPlayer->deeds_[i]->name_ == temp->name_){
                                        currentPlayer->deeds_[i] = property; //causes a seg fault TODO
                                    }
                                }

                                for(int i = 0; otherPlayer->properties_;i++){
                                    if(otherPlayer->deeds_[i]->name_ == property->name_){
                                        otherPlayer->deeds_[i] = property1; //causes a seg fault TODO
                                    }
                                }

                                delete temp;

                                for(int i = 0; i < 40; i++){ //change it on the actual board
                                    if(tiles[i]->name_ == property->name_){
                                        tiles[i]->owner_ = otherPlayer->name_;
                                    }
                                }
                                for(int i = 0; i < 40; i++){ //change it on the actual board
                                    if(tiles[i]->name_ == property1->name_){
                                        tiles[i]->owner_ = currentPlayer->name_;
                                    }
                                }
                                cout << "the deal is done" << endl;
                                return;
                            }
                            else{
                                cout << "the deal is off" << endl;
                                return;
                            }
                            
                        }
                    }
                    else if(item == "card"){ //trade a property for a get out of jail card
                        if(otherPlayer->getOutOfJailFree_ == false){
                            cout << "other player does not have a get out of jail free card" << endl;
                            return;
                        }
                        else{
                            cout << "the trade is: "<< endl;
                            cout << currentPlayer->name_ << " will trade "<< property->name_ << " for " << endl;
                            cout << otherPlayer->name_ << "'s get out of jail free card"<< endl;
                            string deal = "";
                            cout << "do both players accept this deal?" << endl;
                            cin >> deal; 
                            if(deal == "yes"){
                                otherPlayer->getOutOfJailFree_ = false;
                                currentPlayer->getOutOfJailFree_ = true;
                                
                                //add it to the other players list of deeds
                                otherPlayer->deeds_[otherPlayer->properties_] = new Tile(property->name_,property->owned_,property->value_,property->rent_,property->mortgage_,property->mortgaged_,property->houseCost_,property->houses_,property->owner_);
                                otherPlayer->deeds_[otherPlayer->properties_]->owner_ = otherPlayer->name_;

                                for(int i = 0; i < currentPlayer->properties_; i++){ //get rid of it in the current players list of deeds
                                    if(currentPlayer->deeds_[i]->name_ == property->name_){
                                        currentPlayer->deeds_[i] = NULL;
                                    }
                                }
                                
                                for(int i = 0; i < 40; i++){ //change it on the actual board
                                    if(tiles[i]->name_ == property->name_){
                                        tiles[i]->owner_ = otherPlayer->name_;
                                    }
                                }

                                //increment and decrement
                                otherPlayer->properties_++;
                                currentPlayer->properties_--;

                                cout << "the deal is done" << endl;
                                return;
                                }
                            else{
                                cout << "the deal is off" << endl;
                                return;
                            }
                        }
                    }
                    else if(item == "money"){ //trade a property for money
                        cout << "how much money would you like in return?" << endl;
                        int amount = 0;
                        cin >> amount;
                        cout << "the trade is: "<< endl;
                        cout << currentPlayer->name_ << "will trade " << property->name_ << " for " << endl;
                        cout << amount << " from " << otherPlayer->name_<< endl;
                        string deal = "";
                        cout << "do both players accept this deal?" << endl;
                        cin >> deal; 
                        if(deal == "yes"){
                            otherPlayer->money_ -= amount;
                            currentPlayer->money_ += amount;
                            
                            //add it to the other players list of deeds
                            cout << "got to line 1575" << endl;
                            otherPlayer->deeds_[otherPlayer->properties_] = new Tile(property->name_,property->owned_,property->value_,property->rent_,property->mortgage_,property->mortgaged_,property->houseCost_,property->houses_,property->owner_);
                            otherPlayer->deeds_[otherPlayer->properties_]->owner_ = otherPlayer->name_; //TODO this is the other place that may cause the seg fault.
                            // potential reason, we already initialize 28 properties in the Player constructor, so making a new one might override memory. 
                            cout << "got to line 1579" << endl;
                            for(int i = 0; i < currentPlayer->properties_; i++){ //get rid of it in the current players list of deeds
                                if(currentPlayer->deeds_[i]->name_ == property->name_){
                                    currentPlayer->deeds_[i] = NULL;
                                }
                            }
                            
                            for(int i = 0; i < 40; i++){ //change it on the actual board
                                if(tiles[i]->name_ == property->name_){
                                    tiles[i]->owner_ = otherPlayer->name_;
                                }
                            }

                            //increment and decrement
                            otherPlayer->properties_++;
                            currentPlayer->properties_--;

                            cout << "the deal is done" << endl;
                        }
                        else{
                            cout << "the deal is off" << endl;
                            return;
                        }
                    }
                    else{
                        cout << "you can not have " << item << " in return" << endl;
                        return;
                    }
                }
            }
            else if(trade == "card"){
                if(item == "property"){ //trading a get out of jail card for a property
                    string propName1 = "";
                    Tile* property1;
                    cout << "which deed would you like in return?" << endl;
                    cin >> propName1;
                    for(int i = 0; i < otherPlayer->properties_; i++){
                        if(otherPlayer->deeds_[i]->name_ == propName1){
                            property1 = otherPlayer->deeds_[i];
                        }
                    }
                    if(property1 == NULL){
                        cout << "property not found" << endl;
                        return;
                    }
                    else if(property1->owned_ == false){
                        cout << "no one owns this property" << endl;
                        return;
                    }
                    else if(property1->owner_ != otherPlayer->name_){
                        cout << "the other player does not own this property" << endl;
                        return;
                    }
                    else{
                        cout << "the trade is: "<< endl;
                        cout << currentPlayer->name_ << "will trade a get out of jail free card for " << endl;
                        cout << otherPlayer->name_ << "'s " << property1->name_ << endl;
                        string deal = "";
                        cout << "do both players accept this deal?" << endl;
                        cin >> deal;
                        if(deal == "yes"){
                            otherPlayer->getOutOfJailFree_ = true;
                            currentPlayer->getOutOfJailFree_ = false;
                            
                            //add it to the current players list of deeds
                            currentPlayer->deeds_[currentPlayer->properties_] = new Tile(property1->name_,property1->owned_,property1->value_,property1->rent_,property1->mortgage_,property1->mortgaged_,property1->houseCost_,property1->houses_,property1->owner_);
                            currentPlayer->deeds_[currentPlayer->properties_]->owner_ = currentPlayer->name_;

                            for(int i = 0; i < otherPlayer->properties_; i++){ //get rid of it in the other players list of deeds
                                if(otherPlayer->deeds_[i]->name_ == property1->name_){
                                    otherPlayer->deeds_[i] = NULL;
                                }
                            }
                            
                            for(int i = 0; i < 40; i++){ //change it on the actual board
                                if(tiles[i]->name_ == property1->name_){
                                    tiles[i]->owner_ = currentPlayer->name_;
                                }
                            }

                            // increment and decrement
                            otherPlayer->properties_--;
                            currentPlayer->properties_++;

                            cout << "the deal is done" << endl;
                            return;
                        }
                        else{
                            cout << "the deal is off" << endl;
                            return;
                        } 
                    }
                }
                else if(item == "card"){ //trading a card for a card
                    cout << "it doesnt make sense to trade a card for a card!" << endl;
                    return;
                }
                else if(item == "money"){ //trading a card for money
                    cout << "how much money would you like in return?" << endl;
                    int amount = 0;
                    cin >> amount;
                    cout << "the trade is: "<< endl;
                    cout << currentPlayer->name_ << "will trade a get out of jail free card for " << endl;
                    cout << amount << " from " << otherPlayer->name_<< endl;
                    string deal = "";
                    cout << "do both players accept this deal?" << endl;
                    cin >> deal; 
                    if(deal == "yes"){
                        otherPlayer->money_ -= amount;
                        currentPlayer->money_ += amount;
                        currentPlayer->getOutOfJailFree_ = false;
                        otherPlayer->getOutOfJailFree_ = true;
                        cout << "the deal is done" << endl;
                        return;
                    }
                    else{
                        cout << "the deal is off" << endl;
                        return;
                    }
                }
                else{
                    cout << "there is no return item of that type" << endl;
                    return;
                }
            }
            else if(trade == "money"){
                if(item == "property"){ //trading money for a property
                    cout << "how much money would you like to trade?" << endl;
                    Tile* property;
                    int amount = 0;
                    cin >> amount;
                    string propName = "";
                    cout << "for which property?" << endl;
                    cin >> propName;
                    for(int i = 0; i < otherPlayer->properties_; i++){
                        if(otherPlayer->deeds_[i]->name_ == propName){
                            property = otherPlayer->deeds_[i];
                        }
                    }
                    if(property == NULL){
                        cout << "property not found" << endl;
                        cout << "line1716" <<endl ;
                        return;
                    }
                    else{
                        cout << "line1720" <<endl ;
                        
                        cout << "the trade is: "<< endl;
                        cout << currentPlayer->name_ << " will trade "<< amount << " for " << endl;
                        cout << otherPlayer->name_ << "'s "<< property->name_ << endl;
                        string deal = "";
                        cout << "do both players accept this deal?" << endl;
                        cin >> deal;
                        if(deal == "yes"){

                            otherPlayer->money_ += amount;
                            currentPlayer->money_ -= amount;
                            
                            //add it to the other players list of deeds
                            currentPlayer->deeds_[currentPlayer->properties_] = new Tile(property->name_,property->owned_,property->value_,property->rent_,property->mortgage_,property->mortgaged_,property->houseCost_,property->houses_,property->owner_);
                            currentPlayer->deeds_[currentPlayer->properties_]->owner_ = currentPlayer->name_;

                            for(int i = 0; i < otherPlayer->properties_; i++){ //get rid of it in the current players list of deeds
                                if(otherPlayer->deeds_[i]->name_ == property->name_){
                                    otherPlayer->deeds_[i] = NULL;
                                }
                            }
                            for(int i = 0; i < 40; i++){ //change it on the actual board
                                if(tiles[i]->name_ == property->name_){
                                    tiles[i]->owner_ = currentPlayer->name_;
                                }
                            }

                            //increment and decrement
                            otherPlayer->properties_--;
                            currentPlayer->properties_++;
                            
                            cout << "the deal is done" << endl;
                            return;
                        }
                        else{
                            cout << "the deal is off" << endl;
                            return;
                        }
                    }

                }
                else if(item == "card"){ // trading money for a get out of jail free card
                    if(otherPlayer->getOutOfJailFree_ == false){
                        cout << "the other player does not even have a get out of jail free card!" << endl;
                        return;
                    }
                    else{
                        int amount = 0;
                        cout << "how much do you want to trade for the card?" << endl;
                        cin >> amount;
                        cout << "the trade is: "<< endl;
                        cout << currentPlayer->name_ << " will trade "<< amount << " for " << endl;
                        cout << otherPlayer->name_ << "'s get out of jail free card" << endl;
                        string deal = "";
                        cout << "do both players accept this deal?" << endl;
                        cin >> deal;
                        if(deal == "yes"){
                            otherPlayer->getOutOfJailFree_ = false;
                            currentPlayer->getOutOfJailFree_ = true;

                            otherPlayer->money_ += amount;
                            currentPlayer->money_ -= amount;

                            cout << "the deal is done" << endl;
                            return;
                        }
                        else{
                            cout << "the deal is off" << endl;
                            return;
                        }
                    }
                }
                else if(item == "money"){
                    cout << "it doesnt make sense to trade money for money!" << endl;
                    return;
                }
                else{
                    cout << "there is no return item of that type" << endl;
                    return;
                }

            }
            else{
                cout << trade << " is not one of the choices" << endl;
                return;
            }
        }
        else{
            return;
        }
    }
}

void Game::Board::mortgage()
{

    Player* currentPlayer = getCurrentPlayer();
    int currentSpot = currentPlayer->currentLoc_;

    while(currentPlayer->money_ < 0 && currentPlayer->inPlay_ == true)
    {
        if(currentPlayer->mortgages_ == currentPlayer->properties_) //no more properties to mortgage
        {
            cout << "It seems that you have no properties left to mortgage and you are still in debt." << endl;
            cout << "Unfortunately you will have to be eliminated from the game. Thank you for playing monopoly." << endl;
            cout << endl;

            if(currentSpot != 4 && currentSpot != 38 && currentSpot != 2 && currentSpot != 7 && currentSpot != 17 && currentSpot != 22 && currentSpot != 33 && currentSpot != 36) //did not land on a tax space or card space
            {
                Player* newOwner;
                for(int i = 0; i < numPlayers; i++){
                    if(players[i]->name_ == tiles[currentSpot]->owner_){
                        newOwner = players[i];
                        transferProps(currentPlayer,players[i]);
                    }
                }
                for(int i = 0; i < 40; i++){
                    if(tiles[i]->owner_ == currentPlayer->name_){
                        tiles[i]->owner_ = newOwner->name_;
                        tiles[i]->houses_ = 0;
                        tiles[i]->owned_ = true;
                        tiles[i]->mortgaged_ = true;
                    }
                }
            }
            else //bankrupted by a tax space or chance
            {
                for(int i = 0; i < currentPlayer->properties_; i++){
                    currentPlayer->deeds_[i]->owner_ = "";
                    currentPlayer->deeds_[i]->owned_ = false;
                    currentPlayer->deeds_[i]->houses_ = 0;
                }
                for(int i = 0; i < 40; i++){
                    if(tiles[i]->owner_ == currentPlayer->name_){
                        tiles[i]->owner_ = "";
                        tiles[i]->houses_ = 0;
                        tiles[i]->owned_ = false;
                    }
                }
            }
            currentPlayer->inPlay_ = false;

            int counter = 0;
            for(int i = 0; i < numPlayers; i++){
                if(players[i]->inPlay_ == true){
                    counter++;
                }
            }
            if(counter == 1){
                cout << "congratulations, you have won!" << endl; // TODO
                cout << "would you like to play again?" << endl; // call reset
                winner = true;
                return;
            }
            return;
        }

        cout << "you must mortgage some properties" <<endl;
        cout << "choose from this list of current properties" << endl;
        cout << "current funds: " << currentPlayer->money_ << endl;
        string prop = "";

        cout << endl;
        cout << "list of non-mortgaged: " << endl;

        for(int i=0; i < currentPlayer->properties_; i++) //list the properties
        {
            if(currentPlayer->deeds_[i]->mortgaged_ == false){
                cout << currentPlayer->deeds_[i]->name_ << endl;
            }
        }

        cout << endl;
        cout << "list of mortgaged: " << endl;

        for(int i=0; i < currentPlayer->properties_; i++) //list the properties
        {
            if(currentPlayer->deeds_[i]->mortgaged_ == true){
                cout << currentPlayer->deeds_[i]->name_ << endl;
            }
        }

        cout << endl;
        cout << endl;
        cin >> prop;

        for(int i = 0; i < currentPlayer->properties_; i++) //find the property and mortgage it
        {
            if(currentPlayer->deeds_[i]->name_ == prop)
            {
                if(currentPlayer->deeds_[i]->mortgaged_ == true)
                {
                    cout << "property already mortgaged" << endl;
                }
                else
                {
                    cout << "mortgaging propety: " << currentPlayer->deeds_[i]->name_ << endl;
                    currentPlayer->deeds_[i]->mortgaged_ = true;
                    currentPlayer->money_ += currentPlayer->deeds_[i]->mortgage_;
                    currentPlayer->mortgages_++;
                }
            }
        }
    }
}

void Game::Board::pay()
{
    Player* currentPlayer = getCurrentPlayer();
    int currentSpot = currentPlayer->currentLoc_;
    Player* owner;
    for(int i = 0; i < numPlayers; i++){
        if(players[i]->name_ == tiles[currentSpot]->owner_){
            owner = players[i];
        }
    }
    cout << currentPlayer->name_ << " has to pay " << owner->name_ << " " << tiles[currentSpot]->rent_ << endl;
    int numHouses = tiles[currentSpot]->houses_;

    if(tiles[currentSpot]->mortgaged_ == false){
        if(numHouses == 0){
            currentPlayer->money_ -= tiles[currentSpot]->rent_;
            owner->money_ += tiles[currentSpot]->rent_;
        }
        else{
            currentPlayer->money_ -= numHouses * tiles[currentSpot]->rent_ * 50;
            owner->money_ += numHouses * tiles[currentSpot]->rent_ * 50;
        }
    }
    
    if(currentPlayer->money_ < 0){
        mortgage();
    }
}

void Game::Board::turn()
{
    turnNum++;
    Player* currentPlayer = getCurrentPlayer();
    int currentSpot = currentPlayer->currentLoc_;

    updateBoard(currentSpot);
    displayBoard();
    resetBoard();

    if(currentPlayer->inPlay_ == false) 
    {
        switchTurns();
        return;
    }
    else{
        cout << endl; //TODO make the player interface look nice
        cout << currentPlayer->name_ << "'s turn" <<endl;
        cout << "-------------------"<<endl;
        cout << "money: "<<currentPlayer->money_ << endl;
        cout << "properties: "<< endl;
        for(int i = 0; i < currentPlayer->properties_; i++){
            cout << currentPlayer->deeds_[i]->name_ << endl;
        }
        
        cout << "cards: "<<currentPlayer->properties_ << endl;

        string decision = "";
        cout << "What would you like to do?" << endl;
        cout << "roll | trade | sell | buy" << endl;
        while(cin >> decision){
            if(decision == "roll"){
                rollTurn();
                break;
            }
            else if(decision == "trade"){
                tradeTurn();
            }
            else if(decision == "sell"){
                sellTurn();
            }
            else if(decision == "buy"){
                buyTurn();
            }
            else{
                cout << "enter a valid choice..." << endl;
            }
            cout << "what else would you like to do?" << endl;
            cout << "roll | trade | sell | buy" << endl;
            decision = "";
        }
        switchTurns();
    }
}

/*------------------------------------------
Main function
------------------------------------------*/

int main()
{
    srand(time(0)); //TODO fix the rolls, make it roll two 6 sided dice, check if doubles

    //TODO come up with a way to display current board and everything each player has
    
    displayBoard();
    Game();

    // TODO upload to github

    return 0;
}
