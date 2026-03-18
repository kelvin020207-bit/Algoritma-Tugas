/* amphoreus.c
   Terminal-style Amphoreus Experiment Archive
   - Authentication: LykoS / ID:001
   - Menu maps to 8 section files (one file per section)
   - If a file is missing, you can create it by pasting its content (end with EOF on its own line)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SECTIONS 8
#define FNAME_LEN 64
#define TITLE_LEN 128
#define BUFFER_SIZE 4096
#define CREDENTIAL_MAX 64
#define MAX_INPUT_LINE 2048

typedef struct {
    char title[TITLE_LEN];
    char filename[FNAME_LEN];
} Section;

typedef struct {
    char user[CREDENTIAL_MAX];
    char code[CREDENTIAL_MAX];
} Credentials;

/* ---------- Function declarations ---------- */
int authenticate(const Credentials *valid);
void show_header();
void build_sections(Section sections[]);
int show_menu_and_get_choice();
int file_exists(const char *fname);
void create_file_from_stdin(const char *fname);
void display_file(const char *fname);
void pause_for_enter();

/* ---------- Main ---------- */
int main(void) {
    Section sections[MAX_SECTIONS];
    Credentials valid = {"LykoS", "ID:001"};
    int authenticated;

    build_sections(sections);

    show_header();
    authenticated = authenticate(&valid);

    if (!authenticated) {
        printf("\nAccess denied. Goodbye.\n");
        return 0;
    }

    while (1) {
        int choice = show_menu_and_get_choice();
        if (choice == 0) {
            printf("\nLogging out. Connection terminated.\n");
            break;
        }
        if (choice < 0 || choice > MAX_SECTIONS) {
            printf("Invalid selection.\n");
            continue;
        }

        Section *s = &sections[choice - 1];
        printf("\n--- Selected: %s ---\n\n", s->title);

        if (!file_exists(s->filename)) {
            printf("Section file '%s' not found.\n", s->filename);
            printf("Would you like to create it now? (y/n): ");
            int c = getchar();
            while (c == '\n') c = getchar();
            if (c == 'y' || c == 'Y') {
                clearerr(stdin);
                // consume rest of line
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
                printf("\nPaste the full section text. End input with a single line that contains only:\nEOF\n\n");
                create_file_from_stdin(s->filename);
                printf("\nFile created and saved as '%s'.\n\n", s->filename);
                display_file(s->filename);
            } else {
                // consume rest of line
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
                printf("Skipped creating file for this section.\n");
            }
        } else {
            display_file(s->filename);
        }

        pause_for_enter();
    }

    return 0;
}

/* ---------- Implementations ---------- */

void build_sections(Section sections[]) {
    // Using the exact section titles you requested (a-h)
    strncpy(sections[0].title, "a. Experiment Fundamentals", TITLE_LEN);
    strncpy(sections[0].filename, "section_a_experiment_fundamentals.txt", FNAME_LEN);

    strncpy(sections[1].title, "b. Experiment Progress : InOrganic", TITLE_LEN);
    strncpy(sections[1].filename, "section_b_inorganic.txt", FNAME_LEN);

    strncpy(sections[2].title, "c. Experiment Progress : Organic", TITLE_LEN);
    strncpy(sections[2].filename, "section_c_organic.txt", FNAME_LEN);

    strncpy(sections[3].title, "d. Experiment Progress : Human", TITLE_LEN);
    strncpy(sections[3].filename, "section_d_human.txt", FNAME_LEN);

    strncpy(sections[4].title, "e. Experiment Progress : Era Nova", TITLE_LEN);
    strncpy(sections[4].filename, "section_e_era_nova.txt", FNAME_LEN);

    strncpy(sections[5].title, "f. Experiment Progress : Eternal Recurrence", TITLE_LEN);
    strncpy(sections[5].filename, "section_f_eternal_recurrence.txt", FNAME_LEN);

    strncpy(sections[6].title, "g. Experiment Progress : Error Log", TITLE_LEN);
    strncpy(sections[6].filename, "section_g_error_log.txt", FNAME_LEN);

    strncpy(sections[7].title, "h. Experiment Phase : Final Cycle", TITLE_LEN);
    strncpy(sections[7].filename, "section_h_final_cycle.txt", FNAME_LEN);
}

void show_header() {
    printf("============================================================\n");
    printf("      AMPHOREUS EXPERIMENT — SCEPTER SYSTEM ARCHIVE\n");
    printf("============================================================\n\n");
    printf("System Status: ONLINE\n");
    printf("Authentication required to access experiment sections.\n\n");
}

int authenticate(const Credentials *valid) {
    char user_in[CREDENTIAL_MAX];
    char code_in[CREDENTIAL_MAX];
    int attempts = 0;
    const int max_attempts = 3;

    while (attempts < max_attempts) {
        printf("Primary ID: ");
        if (!fgets(user_in, sizeof(user_in), stdin)) return 0;
        user_in[strcspn(user_in, "\n")] = 0;

        printf("Access Code: ");
        if (!fgets(code_in, sizeof(code_in), stdin)) return 0;
        code_in[strcspn(code_in, "\n")] = 0;

        if (strcmp(user_in, valid->user) == 0 && strcmp(code_in, valid->code) == 0) {
            printf("\nSociety ID recognized. Scepter System access granted. Welcome, Entelechy.\n\n");
            return 1;
        } else {
            attempts++;
            printf("\nAuthentication failed. Attempts left: %d\n\n", max_attempts - attempts);
        }
    }

    printf("Maximum attempts exceeded. Security lockout initiated.\n");
    return 0;
}

int show_menu_and_get_choice() {
    printf("\n------------------------------------------------------------\n");
    printf("MAIN MENU\n");
    printf("------------------------------------------------------------\n");
    printf("[1] a. Experiment Fundamentals\n");
    printf("[2] b. Experiment Progress : InOrganic\n");
    printf("[3] c. Experiment Progress : Organic\n");
    printf("[4] d. Experiment Progress : Human\n");
    printf("[5] e. Experiment Progress : Era Nova\n");
    printf("[6] f. Experiment Progress : Eternal Recurrence\n");
    printf("[7] g. Experiment Progress : Error Log\n");
    printf("[8] h. Experiment Phase : Final Cycle\n");
    printf("[0] Exit\n");
    printf("------------------------------------------------------------\n");
    printf("Selection: ");

    int choice;
    if (scanf("%d", &choice) != 1) {
        // clear invalid input
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        return -1;
    }
    // consume newline leftover
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    return choice;
}

int file_exists(const char *fname) {
    FILE *f = fopen(fname, "r");
    if (!f) return 0;
    fclose(f);
    return 1;
}

/* Create a file by reading lines from stdin until a line "EOF" is entered */
void create_file_from_stdin(const char *fname) {
    FILE *f = fopen(fname, "w");
    if (!f) {
        printf("Error: Cannot create file '%s'.\n", fname);
        return;
    }

    char line[MAX_INPUT_LINE];
    while (1) {
        if (!fgets(line, sizeof(line), stdin)) break;
        // remove trailing newline
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') line[len - 1] = '\0';

        if (strcmp(line, "EOF") == 0) break;

        fprintf(f, "%s\n", line);
    }

    fclose(f);
}

/* Display file contents to stdout with basic paging */
void display_file(const char *fname) {
    FILE *f = fopen(fname, "r");
    if (!f) {
        printf("Error: Unable to open '%s' for reading.\n", fname);
        return;
    }

    char buffer[BUFFER_SIZE];
    int line_count = 0;
    const int PAGE_LINES = 24; // rudimentary paging

    while (fgets(buffer, sizeof(buffer), f)) {
        printf("%s", buffer);
        line_count++;
        if (line_count >= PAGE_LINES) {
            printf("\n-- more -- (press ENTER to continue) --");
            pause_for_enter();
            line_count = 0;
        }
    }
    fclose(f);
}

/* Wait for user to press ENTER */
void pause_for_enter() {
    printf("\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

