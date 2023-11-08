#include "Hand.hpp"
#include "algorithm"

/**
    @post: Construct a new Hand object
*/
Hand::Hand()
{
    cards_ = std::deque<PointCard>();
}

/**
    @post: Destroy the Hand object
*/
Hand::~Hand()
{
    cards_.clear();
}


/**
    Copy Constructor
    @param: other Hand object
*/
Hand::Hand(const Hand& other)
{
    cards_ = other.cards_;
}

/**
    Copy Assignment Operator
    @param: other Hand object
    @return this Hand 
*/
Hand& Hand::operator=(const Hand& other) 
{
    if (this != &other) 
    {
        cards_ = other.cards_;
    }
    return *this;
}


/**
    Move Constructor
    @param: other Hand object
*/
Hand::Hand(Hand&& other)
{
    cards_ = std::move(other.cards_);
}
 

/**
    Move assignment operator
    @param: other Hand object
    @return this Hand
*/
Hand& Hand::operator=(Hand&& other)
{
    if (this != &other) 
    {
        cards_ = std::move(other.cards_);
    }
    return *this;
}

/**
    @return Hand
*/
const std::deque<PointCard>& Hand::getCards() const
{
    return cards_;
}
        
/**
    @post: Add a card to the hand
    @param PointCard object
*/
void Hand::addCard(PointCard&& card)
{
    card.setDrawn(true);
    cards_.push_back(std::move(card));
}

/**
    @return true if hand is empty, false otherwise
*/
bool Hand::isEmpty() const 
{
    return cards_.empty();
}
      

/**
    @post: Reverse the hand
*/
void Hand::Reverse() 
{
    int left = 0;
    int right = cards_.size() - 1;

    while (left < right) 
    {
        // Swap the elements at the left and right positions
        std::swap(cards_[left], cards_[right]);

        // Move the indices toward the center
        ++left;
        --right;
    }
}


/**
    @post: Play the card at the front of the hand, removing it from the hand
    Throws an exception if the hand is empty or the card is not playable
    If the card is not playable, the card is removed from the hand
    @return the points earned from playing the card
*/
int Hand::PlayCard() {
    if (isEmpty()) 
    {
        throw std::runtime_error("Cannot play a card; the hand is empty");
    }

    PointCard card = std::move(cards_.front());
    cards_.pop_front();

    if (card.isPlayable()) 
    {
        // Check if the card is a POINT card
        return std::stoi(card.getInstruction());

    } 
    else 
    {
       return 0;
    }
    //points earned from cards    
    return std::stoi(card.getInstruction());
}
