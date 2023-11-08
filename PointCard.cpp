#include "PointCard.hpp"


/**
    @post: Construct a new Point Card object
*/
PointCard::PointCard()
{
    setType(POINT_CARD);
}

/**
    @return true if the card is playable, false otherwise
    For a card to be playable, it has to be drawn and the instruction has to be a valid number
*/
bool PointCard::isPlayable() 
{
    // Check if the card is drawn
    if (getDrawn()) 
    {
        try 
        {
            std::stoi(getInstruction());
            return true; // Successfully converted to an integer, it's a whole number and playable
        } 
        catch (const std::invalid_argument& e) 
        {
            return false; // Failed to convert, not a whole number, not playable
        }
    } 
    else 
    {
        return false; // Not drawn, not playable
    }
}



/**
    @post: Print the Point Card in the following format:
    Type: [CardType]
    Points: [Instruction]
    Card: [ImageData]
    Note: For [ImageData]: If there is no image data, print "No image data" instead
*/
void PointCard::Print() const
{
    std::string instruction = getInstruction();

    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " <<  instruction <<std::endl; 
    std::cout << "Card: " << std::endl;
    
    const int* imageData = getImageData();

    if (imageData != nullptr) 
    {
        // Print the image data
        for (int i = 0; i < 80; ++i) 
        {
            std::cout << imageData[i] << " ";
        }
        std::cout << std::endl;
    } 
    else 
    {
        // Print "No image data"
        std::cout << "No image data" << std::endl;
    }
}


