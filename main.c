#include "tp.h"

int main() {
    float frequencies[12] = { 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88 };
    
    Note **notes = malloc(12 * sizeof(Note*));

    for (int i = 0; i < 12; i++) {
        notes[i] = creerNote(400, frequencies[i]);
    }

    simulerPiano(notes, 12);

    return 0;
}