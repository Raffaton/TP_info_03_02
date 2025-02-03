#ifndef TP_H
#define TP_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
    float frequence;
    float duree;
}Note;

Note* creerNote(float duree_note, float frequence_note);
#endif