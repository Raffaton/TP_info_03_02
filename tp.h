#ifndef TP_H
#define TP_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct {
    float frequence;
    float duree;
}Note;

Note* creerNote(float duree_note, float frequence_note);
void simulerPiano(Note **notes, int nbr_notes);
#endif