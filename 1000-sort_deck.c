#include "deck.h"
#include <stdbool.h>

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);
/**
 * _strcmp - a function that compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Description: This function compares two strings character by character.
 *              If the characters are equal, it moves to the
 *              next pair of characters.
 *              When it finds a pair of characters that are not equal,
 *              it returns the difference between their ASCII values.
 *              If it reaches the end of the strings without finding
 *              any unequal pair,
 *              it returns 0, indicating that the strings are equal.
 *
 * Return: The difference between the ASCII values of the first
 * pair of unequal characters.
 *         If the strings are equal, it returns 0.
 */
int _strcmp(const char *s1, const char *s2)
{
	const char *str1 = s1;
	const char *str2 = s2;

	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}
/**
 * get_value - a function that returns the value of a card in a deck.
 * @card: A pointer to the card whose value is to be determined.
 *
 * Description: This function takes a pointer to a card as input and returns
 *              the value of the card. The card values are determined based on
 *              their names, with "Ace" being the lowest value and "King" being
 *              the highest. The function uses string comparison to determine
 *              the name of the card and return the corresponding value.
 *
 * Return: The value of the card. If the card's name does not
 * match any of the
 *         expected names, the function returns 13,
 *         which is the value for "King".
 */
char get_value(deck_node_t *card)
{
	const char *card_value = card->card->value;

	card_value = card->card->value;
	if (_strcmp(card_value, "Ace") == 0)
		return (0);
	if (_strcmp(card_value, "1") == 0)
		return (1);
	if (_strcmp(card_value, "2") == 0)
		return (2);
	if (_strcmp(card_value, "3") == 0)
		return (3);
	if (_strcmp(card_value, "4") == 0)
		return (4);
	if (_strcmp(card_value, "5") == 0)
		return (5);
	if (_strcmp(card_value, "6") == 0)
		return (6);
	if (_strcmp(card_value, "7") == 0)
		return (7);
	if (_strcmp(card_value, "8") == 0)
		return (8);
	if (_strcmp(card_value, "9") == 0)
		return (9);
	if (_strcmp(card_value, "10") == 0)
		return (10);
	if (_strcmp(card_value, "Jack") == 0)
		return (11);
	if (_strcmp(card_value, "Queen") == 0)
		return (12);
	return (13);
}
/**
 * insertion_sort_deck_kind - a function that sorts a deck of cards
 * by kind using the insertion sort algorithm.
 * @deck: A double pointer to the head of the deck.
 *
 * Description: This function sorts a deck of cards by kind using
 * the insertion sort algorithm.
 *              It iterates through the deck, and for each card,
 *              it finds the correct position
 *              for the card in the already sorted part of the
 *              deck and inserts it there.
 *
 * Return: This function does not return a value.
 * It modifies the input deck in-place.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp, *next_node, *prev_node;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			next_node = iter->next;
			prev_node = insert->prev;

			insert->next = next_node;
			if (next_node != NULL)
				next_node->prev = insert;
			iter->prev = prev_node;
			iter->next = insert;
			if (prev_node != NULL)
				prev_node->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = prev_node;
		}
	}
}

/**
 * insertion_sort_deck_value - Sorts a doubly linked list of cards
 * in ascending order based on the 'value' attribute of the card.
 * If two cards have the same 'kind', their order is
 * determined by their 'value'.
 *
 * @deck: A pointer to a pointer to the first node of the
 * doubly linked list.
 *              The list is sorted in-place, so the pointer to the
 *              first node may be modified.
 *
 * This function does not return a value. The list is sorted in-place.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp, *next_node, *prev_node;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
				insert->card->kind == iter->card->kind &&
				get_value(insert) > get_value(iter))
		{
			next_node = iter->next;
			prev_node = insert->prev;

			insert->next = next_node;
			if (next_node != NULL)
				next_node->prev = insert;
			iter->prev = prev_node;
			iter->next = insert;
			if (prev_node != NULL)
				prev_node->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = prev_node;
		}
	}
}

/**
 * sort_deck - This function sorts a deck of cards.
 *
 * The function first checks if the deck is not empty and
 * has more than one node.
 * If these conditions are met, it sorts the deck by kind
 * and value using the
 * insertion sort algorithm.
 *
 * @deck: A double pointer to the head of the deck.
 * The deck is a linked list
 *             where each node represents a card.
 *
 * Return : void This function does not return a value.
 * It modifies the deck in place.
 */
void sort_deck(deck_node_t **deck)
{

	bool isDeckNotEmpty = deck != NULL && *deck != NULL;
	bool hasMoreThanOneNode = isDeckNotEmpty && (*deck)->next != NULL;

	if (isDeckNotEmpty && hasMoreThanOneNode)
	{
		insertion_sort_deck_kind(deck);
		insertion_sort_deck_value(deck);
	}
}




