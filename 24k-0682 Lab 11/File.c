#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5
#define PLAYER_FILE "player.dat"
#define BOWL_FILE "bowl.dat"
#define BAT_FILE "bat.dat"

// Structures
struct player {
    char name[20];
    char team[20];
};

struct bowl {
    char type[10];  // seamer, pacer, spinner or N/A
    char arm[5];    // left or right
    struct player ply;
};

struct bat {
    char type[10];      // top order, middle order, lower order
    char handed[8];     // lefty or righty
    struct bowl ply2;   // Nested bowl structure
};

void createPlayer(struct player *p);
void readPlayers();
void updatePlayer(char *name, struct player *updated);
void deletePlayer(char *name);

void createBowl(struct bowl *b);
void readBowls();
void updateBowl(char *type, struct bowl *updated);
void deleteBowl(char *type);

void createBat(struct bat *b);
void readBats();
void updateBat(char *type, struct bat *updated);
void deleteBat(char *type);

// CRUD Implementation for `player`
void createPlayer(struct player *p) {
    FILE *fp = fopen(PLAYER_FILE, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    fwrite(p, sizeof(struct player), 1, fp);
    fclose(fp);
}

void readPlayers() {
    FILE *fp = fopen(PLAYER_FILE, "rb");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    struct player p;
    printf("Players:\n");
    while (fread(&p, sizeof(struct player), 1, fp)) {
        printf("Name: %s, Team: %s\n", p.name, p.team);
    }
    fclose(fp);
}

void updatePlayer(char *name, struct player *updated) {
    FILE *fp = fopen(PLAYER_FILE, "rb+");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    struct player p;
    while (fread(&p, sizeof(struct player), 1, fp)) {
        if (strcmp(p.name, name) == 0) {
            fseek(fp, -sizeof(struct player), SEEK_CUR);
            fwrite(updated, sizeof(struct player), 1, fp);
            fclose(fp);
            return;
        }
    }
    fclose(fp);
    printf("Player not found.\n");
}

void deletePlayer(char *name) {
    FILE *fp = fopen(PLAYER_FILE, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!fp || !temp) {
        perror("Error opening file");
        return;
    }
    struct player p;
    while (fread(&p, sizeof(struct player), 1, fp)) {
        if (strcmp(p.name, name) != 0) {
            fwrite(&p, sizeof(struct player), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove(PLAYER_FILE);
    rename("temp.dat", PLAYER_FILE);
}

// CRUD Implementation for `bowl`
void createBowl(struct bowl *b) {
    FILE *fp = fopen(BOWL_FILE, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    fwrite(b, sizeof(struct bowl), 1, fp);
    fclose(fp);
}

void readBowls() {
    FILE *fp = fopen(BOWL_FILE, "rb");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    struct bowl b;
    printf("Bowlers:\n");
    while (fread(&b, sizeof(struct bowl), 1, fp)) {
        printf("Type: %s, Arm: %s, Player: %s, Team: %s\n", b.type, b.arm, b.ply.name, b.ply.team);
    }
    fclose(fp);
}

void updateBowl(char *type, struct bowl *updated) {
    FILE *fp = fopen(BOWL_FILE, "rb+");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    struct bowl b;
    while (fread(&b, sizeof(struct bowl), 1, fp)) {
        if (strcmp(b.type, type) == 0) {
            fseek(fp, -sizeof(struct bowl), SEEK_CUR);
            fwrite(updated, sizeof(struct bowl), 1, fp);
            fclose(fp);
            return;
        }
    }
    fclose(fp);
    printf("Bowler not found.\n");
}

void deleteBowl(char *type) {
    FILE *fp = fopen(BOWL_FILE, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!fp || !temp) {
        perror("Error opening file");
        return;
    }
    struct bowl b;
    while (fread(&b, sizeof(struct bowl), 1, fp)) {
        if (strcmp(b.type, type) != 0) {
            fwrite(&b, sizeof(struct bowl), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove(BOWL_FILE);
    rename("temp.dat", BOWL_FILE);
}

// CRUD Implementation for `bat`
void createBat(struct bat *b) {
    FILE *fp = fopen(BAT_FILE, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    fwrite(b, sizeof(struct bat), 1, fp);
    fclose(fp);
}

void readBats() {
    FILE *fp = fopen(BAT_FILE, "rb");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    struct bat b;
    printf("Batsmen:\n");
    while (fread(&b, sizeof(struct bat), 1, fp)) {
        printf("Type: %s, Handed: %s, Bowler: %s, Arm: %s, Player: %s\n",
               b.type, b.handed, b.ply2.type, b.ply2.arm, b.ply2.ply.name);
    }
    fclose(fp);
}

void updateBat(char *type, struct bat *updated) {
    FILE *fp = fopen(BAT_FILE, "rb+");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    struct bat b;
    while (fread(&b, sizeof(struct bat), 1, fp)) {
        if (strcmp(b.type, type) == 0) {
            fseek(fp, -sizeof(struct bat), SEEK_CUR);
            fwrite(updated, sizeof(struct bat), 1, fp);
            fclose(fp);
            return;
        }
    }
    fclose(fp);
    printf("Batsman not found.\n");
}

void deleteBat(char *type) {
    FILE *fp = fopen(BAT_FILE, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!fp || !temp) {
        perror("Error opening file");
        return;
    }
    struct bat b;
    while (fread(&b, sizeof(struct bat), 1, fp)) {
        if (strcmp(b.type, type) != 0) {
            fwrite(&b, sizeof(struct bat), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove(BAT_FILE);
    rename("temp.dat", BAT_FILE);
}
int main() {
    int choice;
    struct player p;
    char nameToDelete[20];

    do {
    printf("\n--- Player Management ---\n");
    printf("1. Add Player\n");
    printf("2. View Players\n");
    printf("3. Delete Player\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:  // Add a player
            printf("\nEnter player details:\n");
            printf("Name: ");
            scanf("%19s", p.name);
            printf("Team: ");
            scanf("%19s", p.team);
            createPlayer(&p);
            break;

        case 2:  // View all players
            readPlayers();
            break;

        case 3:  // Delete a player
            printf("\nEnter the name of the player to delete: ");
            scanf("%19s", nameToDelete);
            deletePlayer(nameToDelete);
            break;

        case 4:  // Exit
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }
    } while (choice != 4);

    return 0;
    }