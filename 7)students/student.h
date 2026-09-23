#ifndef STUDENT_H
#define STUDENT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student Student;

Student* create(int id, int age, int curs, const char* name);
Student* createNull(void);
void destroy(Student* student);

void set_id(Student* student, int id);
void set_age(Student* student, int age);
void set_curs(Student* student, int curs);
void set_name(Student* student, const char* name);

int get_id(const Student* student);
int get_age(const Student* student);
int get_curs(const Student* student);
const char* get_name(const Student* student);
bool is_registered(const Student* student);

void show(const Student* student);

void registered(Student* student);
void read(Student* student, int id);

Student* entered(void);

#endif
