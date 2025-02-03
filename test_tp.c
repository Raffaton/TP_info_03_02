#include "tp.h"

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; if (message) return message; } while (0)

int tests_run = 0;

char* test_creerNote() {
    Note* note = creerNote(400.0f, 261.63f);
    mu_assert("Erreur creerNote: l'allocation a echoue", note != NULL);
    mu_assert("Erreur creerNote: mauvaise duree", note->duree == 400.0f);
    mu_assert("Erreur creerNote: mauvaise frequence", note->frequence == 261.63f);
    free(note);

    return 0;
}

char* test_libererNotes() {
    Note **notes = malloc(3 * sizeof(Note*));
    mu_assert("Erreur libererNotes: allocation du tableau echouee", notes != NULL);
    
    for(int i = 0; i < 3; i++) {
        notes[i] = creerNote(400.0f, 261.63f + i);
        mu_assert("Erreur libererNotes: allocation de note echouee", notes[i] != NULL);
    }
    
    libererNotes(notes, 3);
    mu_assert("Erreur libererNotes: le pointeur n'a pas ete mis a NULL", notes == NULL);    
    
    return 0;
}

char* test_simulerPiano() {
    Note **notes = malloc(12 * sizeof(Note*));
    mu_assert("Erreur simulerPiano: allocation du tableau echouee", notes != NULL);
    
    float frequencies[12] = { 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88 };
    
    for(int i = 0; i < 12; i++) {
        notes[i] = creerNote(400.0f, frequencies[i]);
        mu_assert("Erreur simulerPiano: allocation de note echouee", notes[i] != NULL);
        mu_assert("Erreur simulerPiano: mauvaise frequence", notes[i]->frequence == frequencies[i]);
    }
    
    libererNotes(notes, 12);
    return 0;
}

static char* all_test() {
    mu_run_test(test_creerNote);
    mu_run_test(test_libererNotes);
    mu_run_test(test_simulerPiano);

    return 0;
}

int main()
{
    char *result = all_test();
    if (result != 0) 
    {
        printf("%s\n", result); 
    }
    else
    {
        printf("All tests passed.\n");
    }
    printf("Tests run: %d\n", tests_run); 
    return result != 0; 
}