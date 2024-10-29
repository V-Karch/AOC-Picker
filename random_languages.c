#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *familiar_languages[] = {
    "JavaScript", "Python", "Shell", "Java", "Rust", "Go",
    "C++", "C#", "C"
};

const char *unfamiliar_languages[] = {
    "Typescript", "Fortran", "Haskell", "Kotlin", "Cobol",
    "Lisp", "Ruby", "Lua", "Zig", "R"
};

// Function to get a random language
const char *get_random_language() {
    int total_languages = sizeof(familiar_languages) / sizeof(familiar_languages[0])
                        + sizeof(unfamiliar_languages) / sizeof(unfamiliar_languages[0]);

    int random_index = rand() % total_languages;

    if (random_index < sizeof(familiar_languages) / sizeof(familiar_languages[0])) {
        return familiar_languages[random_index];
    } else {
        return unfamiliar_languages[random_index - sizeof(familiar_languages) / sizeof(familiar_languages[0])];
    }
}

int main(int argc, char *argv[]) {
    // Initialize random seed
    srand(time(NULL));

    if (argc != 2) {
        printf("Received %d arguments but expected 1\n", argc - 1);
        return 1;
    }

    char *endptr;
    long language_count = strtol(argv[1], &endptr, 10);

    if (*endptr != '\0' || language_count <= 0) {
        printf("Argument `%s` could not be parsed into a positive integer.\n", argv[1]);
        return 1;
    }

    // Print random languages
    for (long i = 0; i < language_count; i++) {
        printf("%s\n", get_random_language());
    }

    return 0;
}
