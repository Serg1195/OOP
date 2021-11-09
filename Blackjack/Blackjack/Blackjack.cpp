
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

int main()
{
    std::cout << "Blackjack\n";
}
