#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
    struct node *prev;
    char song[50];
    struct node *next;
};

struct node *create(char *song) {
    struct node *new_n = (struct node *)malloc(sizeof(struct node));
    if (new_n == NULL) {
        printf("Memory Allocation Failed\n");
        exit(0);
    }
    new_n->prev = NULL;
    strcpy(new_n->song, song);
    new_n->next = NULL;
    return new_n;
}

void add(struct node **head, char *song) {
    struct node *new_n = create(song);
    if (*head == NULL) {
        *head = new_n;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_n;
        new_n->prev = temp;
    }
    printf("Added song: %s\n", song);
}

void play(struct node *head) {
    if (head == NULL) {
        printf("No songs in the playlist!\n");
        return;
    }

    struct node *temp = head;
    int ch;
    printf("\nPlaying first song: %s\n", temp->song);

    while (true) {
        printf("\nEnter choice (1->Next | 2->Previous | 3->Exit): ");
        scanf("%d", &ch);

        if (ch == 1) { // Next
            if (temp->next == NULL)
                printf("No next song exists!\n");
            else {
                temp = temp->next;
                printf("Playing next song: %s\n", temp->song);
            }
        } else if (ch == 2) { // Previous
            if (temp->prev == NULL)
                printf("No previous song exists!\n");
            else {
                temp = temp->prev;
                printf("Playing previous song: %s\n", temp->song);
            }
        } else if (ch == 3) {
            printf("Stopping playback.\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
}

int main() {
    struct node *head = NULL;
    int mood;
    char song[50];

    printf("Welcome to the Playlist!\n");
    printf("1. Add Song\n2. Play Songs\n3. Exit\n");

    while (true) {
        printf("\nEnter your choice: ");
        scanf("%d", &mood);
        getchar(); // clear newline from buffer

        switch (mood) {
            case 1:
                printf("Enter song name: ");
                fgets(song, sizeof(song), stdin);
                song[strcspn(song, "\n")] = '\0'; // remove newline
                add(&head, song);
                break;

            case 2:
                play(head);
                break;

            case 3:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
