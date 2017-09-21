// The playing card implementation.
//
// This is an implementation of the Card ADT, which represents a single
// playing card in the game of Final Card-Down.
//
// By ... (z0000000)
//    ... (z0000000)
// Written on 2017-09-??
// Tutor (dayHH-lab)

#include<stdlib.h>
#include "Card.h"

// The following typedef is included in Card.h:
//         typedef struct _card *Card;
// This means that a struct card has to be implemented *somewhere*, but
// not necessarily in the .h file, as we have done with concrete types.
//
// The way we implement this in an ADT is that you design your own card
// struct, with the fields etc that you need to implement your ADT.

typedef struct _card {
    // Insert the fields here that you need for your
    // implementation.
    char number;
    suit suit;
    color color;
} card;

// Place the prototypes for your own functions here.
// Don't forget to make them static!



// The interface functions are below. You need to implement these.

// Create a new card.
// These values can only be set at creation time.
// The number should be between 0x0 and 0xF.
Card newCard(char number, color color, suit suit) {
    //return NULL; // Replace this with your own code.
    Card myCard = calloc(1,sizeof(card));
    myCard->number = number;
    myCard->color = color;
    myCard->suit = suit;
    return myCard;
}

// Destroy an existing card.
void destroyCard(Card card) {
    //return; // Replace this with your own code.
    free(card);
}

// Get the card suit (HEARTS, DIAMONDS, etc).
suit cardSuit(Card card) {
    //return HEARTS; // Replace this with your own code.
    return(card->suit);
}

// Get the card number (0x0 through 0xF).
char cardNumber(Card card) {
    //return 0x0; // Replace this with your own code.
    return(card->number);
}

// Get the card's color (RED, BLUE, etc).
color cardColor(Card card) {
    //return RED; // Replace this with your own code.
    return(card->color);
}


// Implement your own functions here, don't forget to make them static!
