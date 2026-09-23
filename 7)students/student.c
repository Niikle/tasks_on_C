#include "student.h"

#define STR_BUFFER 64

struct Student {
    int id, age, curs;
    char* name;
    bool reg;
};

static void strip_newline(char *str) {
    if (!str) return;
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

Student* create(int id, int age, int curs, const char* name) {
    Student* student = malloc(sizeof(Student));
    if (!student) return NULL;

    student->name = malloc(strlen(name) + 1);
    if (!student->name) {
        free(student);
        return NULL;
    }

    strcpy(student->name, name);

    student->reg = false;
    student->id = id;
    student->age = age;
    student->curs = curs;

    return student;
}

Student* createNull(void) {
    Student* student = malloc(sizeof(Student));
    if (!student) return NULL;

    student->name = malloc(1);
    if (!student->name) {
        free(student);
        return NULL;
    }
    student->name[0] = '\0';

    student->reg = false;
    student->id = -1;
    student->age = -1;
    student->curs = -1;

    return student;
}

void destroy(Student* student) {
    if (!student) return;
    if (student->name) {
        free(student->name);
        student->name = NULL;
    }
    free(student);
}

void set_id(Student* student, int id) { if(student) student->id = id; }
void set_age(Student* student, int age) { if(student) student->age = age; }
void set_curs(Student* student, int curs) { if(student) student->curs = curs; }

void set_name(Student* student, const char* name) {
    if (!student || !name) return;

    if (student->name) {
        free(student->name);
        student->name = NULL;
    }

    student->name = malloc(strlen(name) + 1);
    if (student->name) {
        strcpy(student->name, name);
    }
}

int get_id(const Student* student) { return student ? student->id : -1; }
int get_age(const Student* student) { return student ? student->age : -1; }
int get_curs(const Student* student) { return student ? student->curs : -1; }
const char* get_name(const Student* student) { return student ? student->name : ""; }
bool is_registered(const Student* student) { return student ? student->reg : false; }

void show(const Student* student) {
    if (!student) {
        printf("Student: (null)\n");
        return;
    }
    printf("Student:\n");
    printf("id:\t%d\n", student->id);
    printf("age:\t%d\n", student->age);
    printf("curs:\t%d\n", student->curs);
    printf("name:\t%s\n", student->name ? student->name : "(null)");
    printf("%s\n\n", student->reg ? "registered" : "not registered");
}

void registered(Student* student) {
    if (!student || student->reg) return;

    char filename[STR_BUFFER] = {0};
    snprintf(filename, sizeof(filename), "%d.txt", student->id);

    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Cannot open file %s for writing\n", filename);
        return;
    }

    fprintf(file, "%d\n%d\n%d\n%s\n", student->id, student->age, student->curs, student->name ? student->name : "");

    fclose(file);
    student->reg = true;
}

void read(Student* student, int id) {
    if (!student) return;

    char filename[STR_BUFFER] = {0};
    snprintf(filename, sizeof(filename), "%d.txt", id);

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Cannot open file %s for reading\n", filename);
        return;
    }

    char id_str[STR_BUFFER] = {0};
    char age_str[STR_BUFFER] = {0};
    char curs_str[STR_BUFFER] = {0};
    char name_str[STR_BUFFER] = {0};

    if (!fgets(id_str, sizeof(id_str), file)) { fclose(file); return; }
    if (!fgets(age_str, sizeof(age_str), file)) { fclose(file); return; }
    if (!fgets(curs_str, sizeof(curs_str), file)) { fclose(file); return; }
    if (!fgets(name_str, sizeof(name_str), file)) { fclose(file); return; }
    fclose(file);

    strip_newline(id_str);
    strip_newline(age_str);
    strip_newline(curs_str);
    strip_newline(name_str);

    student->id   = atoi(id_str);
    student->age  = atoi(age_str);
    student->curs = atoi(curs_str);

    if (student->name) {
        free(student->name);
        student->name = NULL;
    }
    student->name = malloc(strlen(name_str) + 1);
    if (student->name) strcpy(student->name, name_str);

    student->reg = true;
}

Student* entered(void) {
    int id, age, cours;
    char name[STR_BUFFER] = {0};

    printf("Enter data about student to register him:\n");
    printf("id:\t");   scanf("%d", &id);
    printf("age:\t");  scanf("%d", &age);
    printf("cours:\t"); scanf("%d", &cours);
    printf("name:\t");  scanf("%63s", name);

    Student* student = create(id, age, cours, name);
    return student;
}
