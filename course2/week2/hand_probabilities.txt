#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define ITERATIONS 1000000
#define DECK_SIZE 52
#define HAND_SIZE 7
#define EMPTY -1

struct Stats {
    int no_pair;
    int one_pair;
    int two_pair;
    int three_of_a_kind;
    int full_house;
    int four_of_a_kind;
} stats = {0, 0, 0, 0, 0, 0}; // global stats variable

typedef enum Suits {
    spades,
    hearts,
    clubs,
    diamonds
} Suit;

typedef struct Cards {
    Suit suit;
    int pips;
} Card;

///////////////////////////////////
// stack representing card deck
// and associated methods
typedef struct Deck {
    Card cards[DECK_SIZE];
    int top;
} Deck;

void reset_deck(Deck *deck) {
    deck->top=EMPTY;
}

void push_deck(Card c, Deck *deck) {
    deck->top++;
    deck->cards[deck->top] = c;
}

Card pop_deck(Deck *deck) {
    return (deck->cards[deck->top--]);
}
///////////////////////////////////


// Initialize deck with all cards
void build_deck(Deck *pdeck) {
    reset_deck(pdeck); // reset before filling stack
    for (int s=0; s<4; s++) {
        for (int n=1; n<14; n++) {
            Card card = {s, n};
            push_deck(card, pdeck);
        }
    } 
}

// shuffle the deck using Fisher-Yates
void shuffle(Deck *pdeck){
    int i, j;
    Card tmp;
    // Card cards[] = pdeck->cards;

    for (i=DECK_SIZE-1; i>0; i--) {
        j = rand() % (i + 1);
        tmp = pdeck->cards[j];
        pdeck->cards[j] = pdeck->cards[i];
        pdeck->cards[i] = tmp;
    }
}

// deal cards from top of deck
void deal(Deck *pdeck, Card hand[HAND_SIZE]) {
    for (int i = 0; i < DECK_SIZE; i++) {
        Card card = pop_deck(pdeck);
        hand[i] = card;
    }
}

// helper function to print hand
void print_hand(Card hand[HAND_SIZE]) {
    for (int i=0; i<HAND_SIZE; i++) {
        printf("{%d, %d} ", hand[i].pips, hand[i].suit);
    }
    printf("\n");
}

void analyze(Card hand[HAND_SIZE]) {
    int counts[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int pair = 0;
    int triplet = 0;
    int quartet = 0;
    for (int i = 0; i<HAND_SIZE; i++) {
        counts[hand[i].pips] += 1;
    }
    for (int i = 0; i < 13; i++) {
        // printf("%d ", counts[i]);
        switch (counts[i]) {
            case 2: pair += 1; break;
            case 3: triplet += 1; break;
            case 4: quartet += 1; break;
            default: break;
        }
    }
    stats.four_of_a_kind += (quartet == 1) ? 1 : 0;
    stats.full_house += ((triplet >= 1) && (pair >= 1)) ? 1 : 0;
    stats.three_of_a_kind += ((triplet >= 1) && (pair == 0) && (quartet == 0)) ? 1 : 0;
    stats.two_pair += ((pair >= 2) && (triplet == 0) && (quartet == 0)) ? 1 : 0;
    stats.one_pair += ((pair == 1) && (triplet == 0) && (quartet == 0)) ? 1 : 0;
    stats.no_pair += ((pair == 0) && (triplet == 0) && (quartet == 0)) ? 1 : 0;
}

void print_stats() {
    printf("four_of_a_kind:   %f\n", 1.0 * stats.four_of_a_kind / ITERATIONS);
    printf("full_house:       %f\n", 1.0 * stats.full_house / ITERATIONS);
    printf("three_of_a_kind:  %f\n", 1.0 * stats.three_of_a_kind / ITERATIONS);
    printf("two_pair:         %f\n", 1.0 * stats.two_pair / ITERATIONS);
    printf("one_pair:         %f\n", 1.0 * stats.one_pair / ITERATIONS);
    printf("no_pair:          %f\n", 1.0 * stats.no_pair / ITERATIONS);
    printf("Total:            %d\n", stats.four_of_a_kind + stats.full_house + stats.three_of_a_kind + stats.two_pair + stats.one_pair + stats.no_pair);
}

int main() {
    srand(time(NULL)); // initialize the random seed

    for (int i=0; i<ITERATIONS; i++) {
        // initialize the deck and hand
        Deck deck;
        static Card hand[HAND_SIZE];
        
        // generate the deck
        build_deck(&deck);

        // shuffle the deck
        shuffle(&deck);

        // deal a hand
        deal(&deck, hand);
        // print_hand(hand);

        // update stats based on hand
        analyze(hand);
    }
    print_stats(stats);
    return 0;
}
