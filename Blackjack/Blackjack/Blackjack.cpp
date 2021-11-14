
#include <iostream>
#include <vector>
#include <algorithm>

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
Deck::Deck()
{
    m_Cards.reserve(52);
    Populate();
}
Deck::~Deck()
{}
void Deck::Populate()
{
    Clear();
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
        {
            Add(new Card(static_cast<Card::rank>(r),
                static_cast<Card::suit>(s)));
        }
    }
}
void Deck::Shuffle()
{
    random_shuffle(m_Cards.begin(), m_Cards.end());
}
void Deck::Deal(Hand& aHand)
{
    if (!m_Cards.empty())
    {
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    }
    else
    {
        cout << "Out of cards. Unable to deal.";
    }
}
void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
    cout << endl;
    // продолжает раздавать карты до тех пор, пока у игрока не случается
    // перебор или пока он хочет взять еще одну карту
    while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
    {
        Deal(aGenericPlayer);
        cout << aGenericPlayer << endl;

        if (aGenericPlayer.IsBusted())
        {
            aGenericPlayer.Bust();
        }
    }
}


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

class Game
{
public:
    Game(const vector<string>& names);

    ~Game();
    void Play();

private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
};
Game::Game(const vector<string>& names)
{
    vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)
    {
        m_Players.push_back(Player(*pName));
    }
    srand(static_cast<unsigned int>(time(0)));
    m_Deck.Populate();
    m_Deck.Shuffle();
}

Game::~Game()
{}

void Game::Play()
{
    vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            m_Deck.Deal(*pPlayer);
        }
        m_Deck.Deal(m_House);
    }
    m_House.FlipFirstCard();
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        cout << *pPlayer << endl;
    }
    cout << m_House << endl;
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        m_Deck.AdditionalCards(*pPlayer);
    }
    m_House.FlipFirstCard();
    cout << endl << m_House;

    m_Deck.AdditionalCards(m_House);

    if (m_House.IsBusted())
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            if (!(pPlayer->IsBusted()))
            {
                pPlayer->Win();
            }
        }
    }
    else
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
            ++pPlayer)
        {
            if (!(pPlayer->IsBusted()))
            {
                if (pPlayer->GetTotal() > m_House.GetTotal())
                {
                    pPlayer->Win();
                }
                else if (pPlayer->GetTotal() < m_House.GetTotal())
                {
                    pPlayer->Lose();
                }
                else
                {
                    pPlayer->Push();
                }
            }
        }

    }

    // очищает руки всех игроков
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        pPlayer->Clear();
    }
    m_House.Clear();
}


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
