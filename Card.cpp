#include "Card.hpp"

////////BIG 5 + CONSTRUCTOR


/**
    Default Constructor
    @post: Construct a new Card object 
*/
Card::Card()
: cardType_(CardType::POINT_CARD), instruction_(" "), bitmap_(nullptr), drawn_(false)
{}



/**
    Destructor
    @post: Destroy the Card object
*/
Card::~Card()
{
    //deallocate bitmap_ if it's not a nullptr
    if (bitmap_ != nullptr)
    {
        delete[] bitmap_;
    }
}



/**
 * Copy Constructor
 * @post: Construct a new Card object
 * @param: const reference to a Card object
 */
Card::Card(const Card& rhs) : cardType_(rhs.cardType_), instruction_(rhs.instruction_), drawn_(false), bitmap_(nullptr) {
  /**  if (rhs.bitmap_ != nullptr) 
    {
        bitmap_ = new int(*(rhs.bitmap_));
  
    }
	*/
}




/**
 * Copy Assignment Operator
 * @param const reference to a Card object
 * @return this Card object
 */
Card& Card::operator=(const Card& rhs) {
    if (this == &rhs) {
        return *this;
    }

    // Free existing resources
    delete[] bitmap_;
    bitmap_ = nullptr;

    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;

    return *this;
}



/**
    Move Constructor
    @param: rvalue reference to a Card object 
*/
Card::Card(Card&& rhs)
{
    bitmap_ = std::move(rhs.bitmap_);
    rhs.bitmap_ = nullptr;
    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);
    drawn_ = rhs.drawn_;
}



/**
	Move assignment operator
	@param: rvalue reference to a Card object
	@return this card object
 */
Card& Card::operator=(Card&& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    if (bitmap_ != nullptr)
    {
        delete[] bitmap_;
    }

    bitmap_ = std::move(rhs.bitmap_);
    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);
    drawn_ = rhs.drawn_;

    rhs.bitmap_ = nullptr;

    return *this;
}


////////SETTERS AND GETTERS

/**
    @return the string representation of the card type
*/
std::string Card::getType() const
{
    if(cardType_ == CardType::POINT_CARD)
    {
        return "POINT_CARD";
    }
    else
    {
        return "ACTION_CARD";
    }
}


/**
    @post: set the card type
    @param const reference to a CardType object
*/
void Card::setType(const CardType& type)
{
    cardType_ = type;
}


/**
    @return the string representation of the card instruction
*/
const std::string& Card::getInstruction() const
{
    return instruction_;
}


/**
    @post: set the card instruction
    @param: const reference to an instruction 
*/
void Card::setInstruction(const std::string& instruction)
{
    instruction_ = instruction;
}

/**
    @return the image data
*/
const int* Card::getImageData() const
{
    return bitmap_;
}


/**
    @post: Set the image data
    @param pointer to an array of integers
*/
void Card::setImageData(int* data)
{
    bitmap_ = data;
}


/**
    @return the drawn status of the card
*/
bool Card::getDrawn() const
{
    return drawn_;
}


/**
    @post: set the drawn status of the card
    @param: const reference to a boolean
*/
void Card::setDrawn(const bool& drawn)
{
    drawn_ = drawn;
}

