#include "game.h"

std::string game::verify(std::string input) {
    std::string out(input.size(), '-');
    std::vector<int> used(winner.size(), 0);

    // Pass 1: exact matches
    for (size_t i = 0; i < input.size() && i < winner.size(); i++) {
        if (input[i] == winner[i]) {
            out[i] = '*';
            used[i] = 1; // mark this letter in winner as used
        }
    }

    // Pass 2: partial matches
    for (size_t i = 0; i < input.size() && i < winner.size(); i++) {
        if (out[i] == '*') continue; // already matched
        for (size_t j = 0; j < winner.size(); j++) {
            if (!used[j] && input[i] == winner[j]) {
                out[i] = '$';
                used[j] = 1; // consume this letter
                break;
            }
        }
    }

    return out;
}