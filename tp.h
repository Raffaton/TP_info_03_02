#ifndef TP_H
#define TP_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; if (message) return message; } while (0)

typedef struct {
    float frequence;
    float duree;
}Note;

Note* creerNote(float duree_note, float frequence_note);
void simulerPiano(Note **notes, int nbr_notes);
void libererNotes(Note **notes, int nbr_notes);

#endif