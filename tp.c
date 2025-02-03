#include "tp.h"

Note* creerNote(float duree_note, float frequence_note) {
    Note* note1 = malloc(sizeof(Note));
    note1->duree = duree_note;
    note1->frequence = frequence_note;

    return note1;
}

void simulerPiano(Note **notes, int nbr_notes) {
    while(1) {
        if (_kbhit()) {
            char touche = _getch();
            switch(touche) {
                case 'a':
                    Beep(notes[0]->frequence, notes[0]->duree);
                    break;
                case 'z':
                    Beep(notes[1]->frequence, notes[1]->duree);
                    break;
                case 'e':
                    Beep(notes[2]->frequence, notes[2]->duree);
                    break;
                case 'r':
                    Beep(notes[3]->frequence, notes[3]->duree);
                    break;
                case 't':
                    Beep(notes[4]->frequence, notes[4]->duree);
                    break;
                case 'y':
                    Beep(notes[5]->frequence, notes[5]->duree);
                    break;
                case 'u':
                    Beep(notes[6]->frequence, notes[6]->duree);
                    break;
                case 'i':
                    Beep(notes[7]->frequence, notes[7]->duree);
                    break;
                case 'o':
                    Beep(notes[8]->frequence, notes[8]->duree);
                    break;
                case 'p':
                    Beep(notes[9]->frequence, notes[9]->duree);
                    break;
                case 's':
                    Beep(notes[10]->frequence, notes[10]->duree);
                    break;
                case 'd':
                    Beep(notes[11]->frequence, notes[11]->duree);
                    break;
                case 'q':
                    exit(0);
                    break;
                default:
                    break;
            }
        }
    }
}

void libererNotes(Note **notes, int nbr_notes) {    
    for (int i = 0; i < nbr_notes; i++) {
        if (notes[i] != NULL) {
            free(notes[i]);
        }
    }
    free(notes);
    notes = NULL;
}