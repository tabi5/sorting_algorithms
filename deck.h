#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Enumeration of card suits.
 * @SPADE: Represents the suit of Spades. Explicitly assigned a value of 0.
 * @HEART: Represents the suit of Hearts. As per the C language rules,
 * if the first enumerator has an initializer (a constant expression),
 * the value of each subsequent enumerator is the value of the
 * predecessor plus one. Therefore, HEART will have a value of 1.
 * @CLUB: Represents the suit of Clubs. Following the rule above,
 * CLUB will have a value of 2.
 * @DIAMOND: Represents the suit of Diamonds.
 * Following the rule above, DIAMOND will have a value of 3.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Structure representing a card in a deck of cards.
 *
 * @value: A pointer to a constant character, representing the value
 * of a card (like '2', '3', '4', ..., '10', 'J', 'Q', 'K', 'A').
 * The data this pointer points to cannot be changed.
 * From "Ace" to "King"
 * @kind: An instance of the kind_t enumeration,
 * representing the suit of the card (SPADE, HEART, CLUB, DIAMOND).
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Structure representing a node in
 * a doubly linked list for a deck of cards.
 *
 * @card: A pointer to a constant card_t type, representing
 * a card in a deck. The data this pointer points to cannot be changed.
 * @prev:  A pointer to the previous node in the deck, allowing the
 * list to be traversed backwards.
 * @next:  A pointer to the next node in the deck,
 * allowing the list to be traversed forwards.
 * Returns: This is a structure definition, so it does not
 * return a value. It is used to define variables
 * or allocate memory blocks of this type.
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */


