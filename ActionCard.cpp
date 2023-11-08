#include "ActionCard.hpp"

/**
    @post: Construct a new Action Card object
*/
ActionCard::ActionCard()
{
    // Constructor code for ActionCard
    setType(ACTION_CARD);
}



/**
    @return true if the card is playable, false otherwise
    For a card to be playable, it has to be drawn and the instruction has to be valid
    Valid instructions:
    DRAW x CARD(S) : assume x is a positive integer
    PLAY x CARD(S) : assume x is a positive integer
     REVERSE HAND : reverse the order of the cards in the hand
    SWAP HAND WITH OPPONENT : swap the hand with the opponent
*/
bool ActionCard::isPlayable() 
{
    if (!getDrawn()) 
    {
        return false;  // The card must be drawn to be playable
    }

    const std::string instruction = getInstruction();

    if (instruction == "REVERSE HAND" || instruction == "SWAP HAND WITH OPPONENT") 
    {
        return true;  // These instructions are always valid
    }

    // Define regular expressions for valid instructions
    std::regex drawCardRegex(R"(DRAW (\d+) CARD\(S\))");
    std::regex playCardRegex(R"(PLAY (\d+) CARD\(S\))");

    if (std::regex_match(instruction, drawCardRegex) || std::regex_match(instruction, playCardRegex)) 
    {
        int x = std::stoi(std::regex_replace(instruction, std::regex(R"(\D)"), ""));
        return x > 0;  // Check if 'x' is a positive integer
    }

    return false;  // Invalid instruction
}


/**
    @post: Print the ActionCard in the following format:
    Type: [CardType]
    Instruction: [Instruction]
    Card: [ImageData]
    Note: For [ImageData]: If there is no image data, print "No image data" instead
*/
void ActionCard::Print() const {
    std::string instruction = getInstruction();

    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << instruction << std::endl; 
    std::cout << "Card: " << std::endl;

    const int* imageData = getImageData();

    if (imageData != nullptr) {
        // Print the image data
        for (int i = 0; i < 80; ++i) {
            std::cout << imageData[i] << " ";
        }
        std::cout << std::endl;
    } else {
        // Print "No image data"
        std::cout << "No image data" << std::endl;
    }
}
