#include "algo1.h"
#include "game.h"
#include <iostream>
using namespace std;

int main() {
    words dict("wordle-valid-answers.txt");

    int trials = dict.wordvec.size(); // number of random games to simulate
    long long total_moves = 0;
    int solved = 0;

    for (int t = 0; t < trials; t++) {
        string secret = dict.wordvec[t];   // pick a random secret word
        game gamer(secret);
        algo1 alg("valid-wordle-words.txt");

        int moves = 0;
        string guess = "salet";
        bool win = false;

        while (moves < 6) {
            string feedback = gamer.verify(guess);
            moves++;

            // check if all correct
            bool checker = true;
            for (char c : feedback) {
                if (c != '*') {
                    checker = false;
                    break;
                }
            }
            if (checker) {
                win = true;
                break;
            }

            alg.remove(guess, feedback);
            guess = alg.guess();
        }

        if (win) {
            total_moves += moves;
            solved++;
        }
    }

    if (solved > 0) {
        double avg = (double) total_moves / solved;
        cout << "Solved " << solved << " / " << trials << " games" << endl;
        cout << "Average moves: " << avg << endl;
    } else {
        cout << "No words solved." << endl;
    }

    return 0;
}
