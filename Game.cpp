#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player
{
private:
    int money; // 籌碼
    // Card hand[2]; // 手牌

public:
    bool isInGame;    // 玩家破產或自行離開
    void Check();     // 過牌
    void Call();      // 跟注
    void Raise();     // 加注
    void Fold();      // 蓋牌
    void Limp();      // 跟進(跟進大盲)
    void AllIn();     // 全下
    void LeaveGame(); // 離開遊戲
};

class AI // 比玩家多了判斷執行甚麼動作的函數
{
private:
    int money;
    // Card hand[2];

public:
    bool isInGame; // 電腦破產
    void Check();  // 過牌
    void Call();   // 跟注
    void Raise();  // 加注
    void Fold();   // 蓋牌
    void Limp();   // 跟進(跟進大盲)
};

class Card
{
public:
    int suit;
    int rank;

    Card(int suit, int rank);
    bool operator>(const Card &anothercard); // 單張卡牌比大小(純看點數不看花色)
    void operator=(const Card &anotherCard); // 卡牌複製
};

Card::Card(int suit, int rank)
{
    this->suit = suit;
    this->rank = rank;
}

// 單張卡牌比大小(純看點數不看花色)
bool Card::operator>(const Card &anotherCard)
{
    if (this->rank == 1 && anotherCard.rank != 1)
        return true;
    else if (anotherCard.rank == 1 && this->rank != 1)
        return false;
    else
        return (this->rank > anotherCard.rank);
}

// 卡牌複製
void Card::operator=(const Card &anotherCard)
{
    this->suit = anotherCard.suit;
    this->rank = anotherCard.rank;
}

int main()
{
    int opponentNum;
    cout << "請輸入電腦對手人數(2~6人): ";
    cin >> opponentNum;
    cout << opponentNum;
    return 0;
}