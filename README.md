The game of Bulls and Cows is a two-player game, in which both the players choose a secret number and have to guess the same of the opponent. The one who guesses it in the least number of attempts, wins the game. If number of attempts are same for both the players, it is a tie.

### Rules ###
The secret number should have distinct digits and should not start with 0.
* A guess is also a four-digit number but can start with 0 and has repetitions allowed.
* A bull occurs when a digit is in the same position in both the guess and in the secret number, whereas a cow occurs when a digit is present both in the guess and in the secret number, but in a different position.
* In case of a guess with repeated digits, if the repeated digit occurs in the secret code in the bulls position, it is counted as a bull and not as a cow. For example, if for a secret number of 3480, a guess of 3395 is made, then the answer to the guess would be 1 bull, 0 cow.

### Previous Research ###
**Optimization techniques applied to any deductive 2-player
games have two objectives:**
1. Minimizing the maximum numbers of guesses it can take to complete the game, or the worst case for a game.
2. Minimizing the average number of guesses it will take to guess a randomly assigned number, or the expected game length.

**Known theoretical results for a generic four-place B&C game:**
1. The minimum expected game length is 5.089, and was proved by Tetsuro Tanaka in 1996.
2. The maximum number of guesses in which a number can be correctly deduced is 7, proved by multiple researchers.

### My Strategy ###
We use the concept of pruned set here. A pruned set is one where using on the outcomes of a guess, impossible combinations are eliminated. The logic is after giving a guess, treat it to be the secret number and check for all the numbers that return the same number of bulls and cows as given by the opponent.


### Algorithm ###
Implementing the same idea, an array was created that initially stored all the distinct four-digit numbers.

Every time given a guess, all the numbers that didn’t match with the given number of bulls and cows for the guess, were replaced by “-1” in the array.

The effective size of the array reduces with each iteration and after 6-7 rounds, we are left with only one number, which is the secret number of the opponent.

### References ###
1. Namanyay Goel and Aditya Garg. A Mathematical Approach to Simple Bulls and Cows 2015.
2. John Francis. Strategies for playing MOO, or “Bulls and Cows”.
