#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[100], sname[100];
    struct node *next;
};

struct node *head = NULL; // Initialize head to NULL

void createPlaylist(char *name1, char *name2) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(temp->name, name1);
    strcpy(temp->sname, name2);
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void RemoveSongfromplaylist(char *name1) {
    struct node *temp, *ptr;
    if (head == NULL) {
        printf("\n Your playlist is empty");
        return;
    }
    
    if (strcmp(head->name, name1) == 0) {
        temp = head;
        head = head->next;
        free(temp);
    } else {
        ptr = head;
        while (ptr->next != NULL && strcmp(ptr->next->name, name1) != 0) {
            ptr = ptr->next;
        }
        if (ptr->next == NULL) {
            printf("\n Song not found in the playlist");
        } else {
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
        }
    }
}

void display() {
    struct node *temp;
    int count = 0;
    if (head == NULL) {
        printf("\n Your playlist is empty");
        return;
    }
    
    temp = head;
    while (temp != NULL) {
        count++;
        printf("\n Song name: %s, Singer name: %s", temp->name, temp->sname);
        temp = temp->next;
    }
    printf("\n Number of songs in the playlist = %d", count);
}

void search(char *name1) {
    struct node *temp = head;
    int count = 0;
    if (temp == NULL) {
        printf("\n Music playlist is empty");
        return;
    }
    
    while (temp != NULL) {
        count++;
        if (strcmp(temp->name, name1) == 0) {
            printf("\n The song is at location %d and name: %s", count, temp->name);
            return;
        }
        temp = temp->next;
    }
    printf("\n Song not found");
}

void common(char *name1) {
    struct node *temp = head;
    int count = 0;
    if (temp == NULL) {
        printf("\n No songs in playlist");
        return;
    }
    
    while (temp != NULL) {
        if (strcmp(temp->name, name1) == 0) {
            count++;
        }
        temp = temp->next;
    }
    if (count > 0) {
        printf("\n %s is %d times in playlist", name1, count);
    } else {
        printf("\n %s is not in the playlist", name1);
    }
}

void num_of_song_by_singer(char *name2) {
    struct node *ptr = head;
    int count = 0;
    if (head == NULL) {
        printf("\n No songs found in playlist");
        return;
    }
    
    while (ptr != NULL) {
        if (strcmp(ptr->sname, name2) == 0) {
            count++;
        }
        ptr = ptr->next;
    }
    printf("\n Sung by %s, Number of songs: %d", name2, count);
}

int main() {
    int ch;
    char name1[100], name2[100];
    while (1) {
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\n Enter song name: ");
                scanf("%s", name1);
                printf("\n Enter singer name: ");
                scanf("%s", name2);
                createPlaylist(name1, name2);
                break;
            case 2:
                printf("\n Enter song name: ");
                scanf("%s", name1);
                RemoveSongfromplaylist(name1);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n Enter the song to search: ");
                scanf("%s", name1);
                search(name1);
                break;
            case 5:
                printf("\n Enter the song to search: ");
                scanf("%s", name1);
                common(name1);
                break;
            case 6:
                printf("\n Enter singer name: ");
                scanf("%s", name2);
                num_of_song_by_singer(name2);
                break;
            case 7:
                exit(0);
            default:
                printf("\n Enter correct choice");
        }
    }
    return 0;
}
