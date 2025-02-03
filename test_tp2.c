#include <stdio.h>
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; if (message) return message; } while (0)

int tests_run = 0;

int carre(int a)
{
    return a * a;
}

const char* categorize_age(int age) {
    if (age < 0) {
        return "Invalid age";
    }
    else if (age < 13) {
        return "Child";
    }
    else if (age < 20) {
        return "Teenager";
    }
    else if (age < 65) {
        return "Adult";
    }
    else {
        return "Senior";
    }
}

static char* test_categorize_age_inferieur_0() {
    const char* a = categorize_age(-8);
    mu_assert("L'age doit etre superieur a 0\n", a == "Invalid age");
    return 0;
}

static char* test_categorize_age_inferieur_13() {
    const char* a = categorize_age(5);
    mu_assert("L'age doit etre superieur a 0\n", a == "Child");
    return 0;
}

static char* test_categorize_age_inferieur_20() {
    const char* a = categorize_age(15);
    mu_assert("L'age doit etre superieur a 0\n", a == "Teenager");
    return 0;
}

static char* test_categorize_age_inferieur_65() {
    const char* a = categorize_age(38);
    mu_assert("L'age doit etre superieur a 0\n", a == "Adult");
    return 0;
}

static char* test_categorize_age_supperieur_65() {
    const char* a = categorize_age(88);
    mu_assert("L'age doit etre superieur a 0\n", a == "Senior");
    return 0;
}

static char* test_carre_positif() {
    int c = carre(3);
    mu_assert("le carre de 3 est 9\n", c == 9); 
    return 0;
}

static char* test_carre_negatif() {
    int c = carre(-3);
    mu_assert("le carre de -3 est 9\n", c == 9);   
    return 0;
}

static char* test_carre_nul() {
    int c = carre(0);
    mu_assert("le carre de 0 est 0\n", c == 2);   
    return 0;
}

static char* all_test() {
    mu_run_test(test_carre_positif);
    mu_run_test(test_carre_negatif);
    mu_run_test(test_carre_nul);

    return 0;
}

static char* all_test_2() {
    mu_run_test(test_categorize_age_inferieur_0);
    mu_run_test(test_categorize_age_inferieur_13);
    mu_run_test(test_categorize_age_inferieur_20);
    mu_run_test(test_categorize_age_inferieur_65);
    mu_run_test(test_categorize_age_supperieur_65);

    return 0;
}

int main()
{
    char *result = all_test_2(); // on lance tous les tests
    if (result != 0) // il y a eu une erreur
    {
        printf("%s\n", result); // on affiche le message d’erreur
    }
    else
    {
        printf("All tests passed.\n");
    }
    printf("Tests run: %d\n", tests_run); // on affiche le nombre de tests lancés
    return result != 0; 
}
