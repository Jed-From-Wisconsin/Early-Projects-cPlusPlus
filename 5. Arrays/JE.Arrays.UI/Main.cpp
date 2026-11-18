#include <iostream>
#include <conio.h>

using namespace std;

struct Card
{
    int Rank; // 2–14 (Ace)
    int Suit; // 0 spade, 1 heart, 2 club, 3 diamond
};

int main()
{
    

    const int NUM_SUITS = 4;
    const int NUM_RANKS = 13;
    const int NUM_CARDS = NUM_SUITS * NUM_RANKS;

    string suits[NUM_SUITS] = { "spades", "hearts", "clubs", "diamonds" };

    string ranks[NUM_RANKS] =
    {
        "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"
    };

    Card cards[NUM_CARDS];
    int index = 0;

    // Build the deck
   for (int suit = 0; suit < NUM_SUITS; suit++)
    {
        for (int rank = 2; rank <= 14; rank++)
        {
            cards[index] = { rank, suit };
            index++;
        }
    }

    // Print the deck
    for (int i = 0; i < NUM_CARDS; i++)
    {
        int rank = cards[i].Rank - 2;
        int suit = cards[i].Suit;

        cout << "The " << ranks[rank]
            << " of " << suits[suit] << endl;
    }

    (void)_getch();
    return 0;
}
