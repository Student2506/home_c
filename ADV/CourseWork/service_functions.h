#ifndef SERVICE_FUNCTIONS_H
#define SERVICE_FUNCTIONS_H
typedef float (*function)(float);

int signF(float x, function f);
int signF2(float x, function f, function f2);
float h(float x, function f1, function f2);
#endif