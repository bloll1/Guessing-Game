#include <iostream>
#include <stdlib.h>
#include "GuessingGame.h"
int main() {
long guess;
std::string awnser = "false";
srand (time(NULL));
long secret = rand() % 1000000000000000000 + 1;

while (awnser == "false") {
  printf ("\nPlayer or AI? ");
  std::cin >> awnser;
}
if (awnser == "AI" || awnser == "ai") {
  return solve(secret);
} else {

  for (int i = 60; i > 0; i--) {
    printf ("\nYou have ");
    std::cout << i;
    printf (" guesses to find a number between 0-1000000000000000000  \n Enter your guess: ");
    std::cin >> guess;
    if (guess < 0 || guess > 1000000000000000000 ) {
        i++;
        printf("Please guess between 0-1000000000000000000\n");
    } else if (guess == secret) {
        printf("You have found it congratulations!");
        printf("\n Goodbye.\n");
        return 0;
    } else if (guess < secret) {
        printf("\nYour guess was less than the secret number\n");
    } else if (guess > secret) {
        printf("\nYour guess was greater than the secret number\n");
      }
    }
    printf ("You have failed to find: ");
    std::cout << secret;
    printf ("\n Good luck next time!");
    return 0;
  }
}

int solve(int secret) {
  long guess = 1000000000000000000 / 2;
  long b_guess = 1000000000000000000;
  long small = 0;
  for (long i = 60; i > 0; i--) {
    printf ("\nYou have ");
    std::cout << i;
    printf (" guesses to find a number between 0-1000000000000000000  \n Enter your guess: ");
    std::cout << guess;

    if (guess < 0 || guess > 1000000000000000000) {
        i++;
        printf("Please guess between 0-1000000000000000000\n");
    } else if (guess == secret) {
        printf("\nYou have found it congratulations!\n");
        printf("\n Goodbye.\n");
        return 0;
    } else if (guess < secret) {
        printf("\nYour guess was less than the secret number\n");
        small = guess;
        guess = ((b_guess - guess) / 2) + guess;

    } else if (guess > secret) {
        printf("\nYour guess was greater than the secret number\n");
        b_guess = guess;
        guess = ((guess - small) / 2) + small;
      }
    }
    printf ("You have failed to find: ");
    printf ("%d", secret);
    printf ("\n Good luck next time!");
    return 0;
}
