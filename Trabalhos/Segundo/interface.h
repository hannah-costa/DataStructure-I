#ifndef interface_h
#define interface_h

#ifdef interface_c
int menu();
void printsCar(Car* car);

#else
extern int menu();
extern void printsCar(Car* car);
#endif
#endif
