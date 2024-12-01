#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book {
    char title[100];
    char author[100];
    int publicationYear;
};
struct Library {
    struct Book *books;
};

void inputBookDetails(struct Library *library) {
    for (int i = 0; i < 5; i++) {
        printf("Enter details for book %d:\n", i + 1);
        printf("Title: ");
        getchar();
        fgets(library->books[i].title, sizeof(library->books[i].title), stdin);
        library->books[i].title[strcspn(library->books[i].title, "\n")] = '\0';  

        printf("Author: ");
        fgets(library->books[i].author, sizeof(library->books[i].author), stdin);
        library->books[i].author[strcspn(library->books[i].author, "\n")] = '\0';  

        printf("Publication Year: ");
        scanf("%d", &library->books[i].publicationYear);
    }
}

void displayBooksAfter2000(struct Library library) {
    printf("\nBooks published after the year 2000:\n");
    for (int i = 0; i < 5; i++) {
        if (library.books[i].publicationYear > 2000) {
            printf("Title: %s\n", library.books[i].title);
        }
    }
}

int main() {
    struct Library library;
    library.books = (struct Book *)malloc(5 * sizeof(struct Book));

    if (library.books == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    inputBookDetails(&library);

    displayBooksAfter2000(library);
    free(library.books);

    return 0;
}
