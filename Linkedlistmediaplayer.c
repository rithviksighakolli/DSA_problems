#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a media file
struct MediaFile {
    char title[50];
    char filePath[100];
    struct MediaFile* next;
};

// Structure to represent the playlist
struct Playlist {
    struct MediaFile* head;
    struct MediaFile* current;
};

// Function to create a new media file node
struct MediaFile* createMediaFile(const char* title, const char* filePath) {
    struct MediaFile* newFile = (struct MediaFile*)malloc(sizeof(struct MediaFile));
    strncpy(newFile->title, title, sizeof(newFile->title));
    strncpy(newFile->filePath, filePath, sizeof(newFile->filePath));
    newFile->next = NULL;
    return newFile;
}

// Function to create an empty playlist
struct Playlist* createPlaylist() {
    struct Playlist* playlist = (struct Playlist*)malloc(sizeof(struct Playlist));
    playlist->head = NULL;
    playlist->current = NULL;
    return playlist;
}

// Function to add a media file to the playlist
void addToPlaylist(struct Playlist* playlist, const char* title, const char* filePath) {
    struct MediaFile* newFile = createMediaFile(title, filePath);
    if (playlist->head == NULL) {
        playlist->head = newFile;
        playlist->current = newFile;
    } else {
        playlist->current->next = newFile;
        playlist->current = newFile;
    }
}

// Function to remove a media file by title
void removeFromPlaylist(struct Playlist* playlist, const char* title) {
    struct MediaFile* current = playlist->head;
    struct MediaFile* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (prev == NULL) {
                playlist->head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to play the current media file and move to the next file
void playCurrentMedia(struct Playlist* playlist) {
    if (playlist->current != NULL) {
        printf("Playing: %s\n", playlist->current->title);
        playlist->current = playlist->current->next;
    } else {
        printf("Playlist is empty or all media files have been played.\n");
    }
}

// Function to display the title of the current playing media file
void displayCurrentMediaTitle(struct Playlist* playlist) {
    if (playlist->current != NULL) {
        printf("Currently playing: %s\n", playlist->current->title);
    } else {
        printf("Playlist is empty or all media files have been played.\n");
    }
}

// Function to free the memory used by the playlist
void freePlaylist(struct Playlist* playlist) {
    struct MediaFile* current = playlist->head;
    while (current != NULL) {
        struct MediaFile* temp = current;
        current = current->next;
        free(temp);
    }
    free(playlist);
}

int main() {
    struct Playlist* playlist = createPlaylist();

    // Add media files to the playlist
    addToPlaylist(playlist, "Song 1", "song1.mp3");
    addToPlaylist(playlist, "Video 1", "video1.mp4");
    addToPlaylist(playlist, "Song 2", "song2.mp3");

    // Display the current playing media file
    displayCurrentMediaTitle(playlist);

    // Play the current media file
    playCurrentMedia(playlist);

    // Display the current playing media file again
    displayCurrentMediaTitle(playlist);

    // Remove a media file
    removeFromPlaylist(playlist, "Video 1");

    // Play the next media file
    playCurrentMedia(playlist);

    // Display the current playing media file again
    displayCurrentMediaTitle(playlist);

    // Free the memory used by the playlist
    freePlaylist(playlist);

    return 0;
}
