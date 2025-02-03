#include <tp.h>

Note* creerNote(float duree_note, float frequence_note) {
    Note* note1 = malloc(sizeof(Note));
    note1->duree = duree_note;
    note1->frequence = frequence_note;

    return note1;
}