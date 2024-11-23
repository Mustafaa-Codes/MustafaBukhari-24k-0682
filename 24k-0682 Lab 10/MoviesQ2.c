#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100 

struct Movie {
    char title[50];
    char genre[20];
    char director[50];
    int releaseYear;
    float rating;
};

void addMovie(struct Movie movies[], int movieCount) {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie list is full! Cannot add more movies.\n");
        return;
    }

    printf("Enter movie title: ");
    scanf(" %[^\n]", movies[movieCount].title); 
    printf("Enter genre: ");
    scanf(" %[^\n]", movies[movieCount].genre);
    printf("Enter director: ");
    scanf(" %[^\n]", movies[movieCount].director);
    printf("Enter release year: ");
    scanf("%d", &movies[movieCount].releaseYear);
    printf("Enter rating (0.0 - 10.0): ");
    scanf("%f", &movies[movieCount].rating);

    printf("Movie added successfully!\n");
}

void searchMoviesByGenre(struct Movie movies[], int movieCount, char searchGenre[]) {
    int found = 0;
    printf("\nMovies in genre '%s':\n", searchGenre);
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movies[i].genre, searchGenre) == 0) { 
            printf("Title: %s, Director: %s, Year: %d, Rating: %.1f\n",
                   movies[i].title, movies[i].director, movies[i].releaseYear, movies[i].rating);
            found = 1;
        }
    }
     if (!found) {
        printf("No movies found in genre '%s'.\n", searchGenre);
    }
}

void displayMovies(struct Movie movies[], int movieCount) {
    if (movieCount == 0) {
        printf("No movies available.\n");
        return;
    }
    printf("\nAll Movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Release Year: %d\n", movies[i].releaseYear);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("----------------------\n");
    }
}

int main() {
    struct Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (movieCount < MAX_MOVIES) {
                    addMovie(movies, movieCount);
                    movieCount++; 
                } else {
                    printf("Cannot add more movies. Movie list is full.\n");
                }
                break;
            case 2: {
                char searchGenre[20];
                printf("Enter genre to search: ");
                scanf(" %[^\n]", searchGenre);
                searchMoviesByGenre(movies, movieCount, searchGenre);
                break;
            }

            case 3:
                displayMovies(movies, movieCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
