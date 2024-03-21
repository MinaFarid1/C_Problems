#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "english_words.h"

extern const char *englishWords[];

const char* getRandomWord(int dictionaryLength) {
    int index = rand() % dictionaryLength;
    return englishWords[index];
}

int updateGuesses(char character, char guesses[], const char word[], int wordLen) {
    int updated = 0;
    for(int i = 0; i < wordLen; i++) {
        if(word[i] == character) {
            guesses[i] = character;
            updated = 1;
        }
    }
    return updated;
}

void inputChar(char* input) {
    if (scanf(" %c", input) != 1) {
        printf("Invalid input, Please enter a letter: ");
        while (getchar() != '\n');
        inputChar(input);
    }
}

int main() {
    srand(time(NULL));
    int dictionaryLength = sizeof(englishWords) / sizeof(englishWords[0]);
    const char* word = getRandomWord(dictionaryLength);
    int wordLen = strlen(word);
    int correct = 0;
    int n_trials = 10;
    char guesses[wordLen];
    char input;
    
    for(int i = 0; i < wordLen; i++) {
        guesses[i] = '_';
    }
    
    while(n_trials > 0) {
        printf("%s, Number of tries: %d\nEnter a letter:", guesses, n_trials);
        inputChar(&input);
        if(!updateGuesses(input, guesses, word, wordLen)) {
            n_trials--;
        } else {
            int correct = strcmp(guesses, word) == 0;
            if(correct)
                break;
        }
    }
    
    if(n_trials == 0)
        printf("Correct word was: %s\nMan is Executed :(", word);
    else
        printf("Correct word was: %s\nWIIIIIN!",word);
    
    return 0;
}
