#include "Player.hpp"

Player::Player() 
{
    // Initialize member variables
    //hand_ = Hand();  // initialize the hand with the default constructor
    score_ = 0;  // Initialize the score to zero
    //opponent_ = nullptr;  // Initialize the opponent to nullptr (no opponent initially)
    actiondeck_ = new Deck<ActionCard>;  // Initialize the action deck to new because construcing new deck
    pointdeck_ = new Deck<PointCard>;   // Initialize the point deck to new because construcing new deck
}


Player::~Player() 
{
	//delete actiondeck_;
    //delete pointdeck_;
}


const Hand& Player::getHand() const {
    return hand_;
}

void Player::setHand(const Hand& hand) 
{
    hand_ = hand;
}

int Player::getScore() const 
{
    return score_;
}

void Player::setScore(const int& score) 
{
    score_ = score;
}


/**
 * @post: Play a given action card
 * @param: an Actioncard object
 * Begin the function by reporting the instruction of the card:
 * PLAYING ACTION CARD: [instruction]
 */
void Player::play(ActionCard&& card) 
{
    std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;

    std::regex drawCardRegex(R"DRAW (\d+) CARD\(S\))");
    std::regex playCardRegex(R"PLAY (\d+) CARD\(S\))");
	std::regex reverseCardRegex("REVERSE HAND");
	std::regex swapCardRegex("SWAP HAND WITH OPPONENT");
	
	const std::string &instruction = card.getInstruction();

    if (std::regex_match(instruction, drawCardRegex)) 
    {
        std::smatch test;
        if (std::regex_search(instruction, test, drawCardRegex))
        {
            int numCardsDrawn = std::stoi(test[1]);
            for (int i = 0; i < numCardsDrawn; ++i) 
            {
                drawPointCard();
            }
        }
    }
    else if (std::regex_match(instruction, playCardRegex)) 
    {
        std::smatch test;
        if (std::regex_search(instruction, test, playCardRegex))
        {
            int numCardsPlayed = std::stoi(test[1]);
            for (int i = 0; i < numCardsPlayed; ++i) 
            {
                playPointCard();
            }
        }
    }
    else if (std::regex_match(instruction, reverseCardRegex)) 
    {
        hand_.Reverse();
    } 
    else if (std::regex_match(instruction, swapCardRegex)) 
    {
        Hand tempHand = this->hand_;
        this->hand_ = opponent_->hand_;
        opponent_->hand_= tempHand; 
    } 
    else 
    {
        std::cout << "Invalid action card instruction: " << instruction << std::endl;
    }
}






/**
    @post: Draw a point card and place it in the player's hand
*/
void Player::drawPointCard() 
{
    if (pointdeck_ != nullptr) 
    {
        PointCard card = pointdeck_->Draw();
        hand_.addCard(std::move(card));
    } 
}


/**
    @post: Play a point card from the player's hand and update the player's score
*/
void Player::playPointCard() 
{
    if (!hand_.isEmpty()) 
	{
        int pointsEarned = hand_.PlayCard();
        score_ += pointsEarned;
    } 
}


void Player::setOpponent(Player* opponent) 
{
    opponent_ = opponent;
}


Player* Player::getOpponent() 
{
    return opponent_;
}


void Player::setActionDeck(Deck<ActionCard>* actiondeck) 
{
    actiondeck_ = actiondeck;
}


Deck<ActionCard>* Player::getActionDeck() 
{
    return actiondeck_;
}

/**
	@post: set the point deck of the player
	@param: A pointer to a deck holding Point cards
*/
void Player::setPointDeck(Deck<PointCard>* pointdeck) 
{
    pointdeck_ = pointdeck;
}

/**
	@return: a pointer to the player's point deck
*/
Deck<PointCard>* Player::getPointDeck() 
{
    return pointdeck_;
}
