#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Card.h"

int main(void) {
    color newColor = RED;
    suit newSuit = HEARTS;
    char newNumber = 2;
    Card c = newCard (newNumber, newColor, newSuit);
    assert (c != NULL);
    assert (cardNumber (c) == newNumber);
    assert (cardColor (c) == newColor);
    assert (cardSuit (c) == newSuit);
}
