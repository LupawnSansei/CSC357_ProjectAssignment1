#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void unique(FILE*in);
int main(int argc, char *argv[]) {
    FILE *fptr;
    char *Fname;
    if (argc > 2) {
        printf("Error: Too many arguments.");
        return 1;
    }
    if (argc == 1) {
        fptr= stdin;
    }
    else {
        Fname = argv[1];
        fptr = fopen(Fname, "r");
    }

    if (fptr == NULL) {
        printf("Error: Can't open file.");
        return 1;
    }

        unique(fptr);
        fclose(fptr);
        return 0;

}

void unique(FILE *in) {
    char *prev = NULL;
    char *curr = NULL;
    char *tmp = NULL;
    size_t tcap =0;
    size_t prev_cap =0;
    size_t curr_cap =0;
    ssize_t now;
    now = getline(&prev, &prev_cap, in);
    if (now == -1) return;
    printf("%s", prev);

    while ((now = getline(&curr, &curr_cap, in)) != -1) {
        if (strcmp(curr, prev) != 0) {
            printf("%s", curr);

            tmp = prev;
            prev = curr;
            curr = tmp;
            tcap = prev_cap;
            prev_cap = curr_cap;
            curr_cap = tcap;
        }
    }
    free(prev);
    free(curr);


}
