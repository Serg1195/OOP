
#include <iostream>
#include <vector>

using namespace std;

class Card
{
public:
    enum rank {
        ACE=1,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JECK,QUEEN,KING
    };
    enum suit
    {
        CLUBS,DIMONDS,HEARTS,SPADES
    };
    friend ostream& operator<<(ostream& os, const Card& aCard);
    Card(rank r = ACE, suit s = SPADES, bool ifu = true);
    int GetValue() const;
    void Flip();
private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};
int Card::GetValue() const
{
    int value = 0;
    if (m_IsFaceUp)
    {
        value = m_Rank;
        if (value > 10)
            value = 10;
    }
    return value;
}
void Card::Flip()
{
    m_IsFaceUp = !m_IsFaceUp;
}

class Hand
{
public:
    Hand();
    virtual ~Hand();
    void Add(Card* pCard);
    void Clear();
    int GetTotal() const;
protected:
    vector<Card*> m_Cards;
};

Hand::~Hand()
{
    Clear();
}
void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}
void Hand::Clear()
{
    vector<Card*>::iterator iter = m_Cards.begin();
    for ( m_Cards.begin(); iter !=m_Cards.end(); ++iter)
    {
        Card* card = *iter;
        delete card;
        *iter = nullptr;
    }
    m_Cards.clear();
}

int Hand::GetTotal() const
{
    if (m_Cards.empty())
        return 0;
    if (m_Cards[0]->GetValue() == 0)
        return 0;
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (m_Cards.begin(); iter != m_Cards.end(); ++iter)
        total += (*iter)->GetValue();
    bool containsAce = false;
    for (m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        if (m_Cards[0]->GetValue() == Card::ACE)
            containsAce = true;
    }
    if (containsAce && total <= 11)
        total += 10;
    return total;
}

class Deck:public Hand {
public:
    Deck() {

    }
    void Populate();
    void Shuffle();
    void Deal(Hand& aHand);
    void AddltionalCards(GenericPlayer& aGenerlcPlayer);
private:
};

class GenericPlayer :public Hand {
public:
    GenericPlayer() {

    }
    virtual bool IsHitting() const;
    bool IsBoosted() const;
    void Bust() const;
private:
    string m_Name;
};

class Player :public GenericPlayer {
public:
    Player() {

    }
    virtual bool IsHitting() const;
    void Win() const;
    void Lose() const;
    void Push() const;
private:
};

class House :public GenericPlayer {
public:
    House() {

    }
    virtual bool IsHitting() const;
    void FlipFirstCard();
private:
};

class Game {
public:
    Game() {

    }
    void Play();
private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
};

int main()
{
    cout << "\t\tWelcome to Blackjack!\n\n";
    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }
    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    Game aGame();
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }
}
