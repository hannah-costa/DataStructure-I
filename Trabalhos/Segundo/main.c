#include "collection.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(void){
    int opNum, colSize, stop = false;
    char input;
    Col* c = NULL;

    do{
        system("cls");
        opNum = menu();
        if (opNum< 1 || opNum>6){
            printf("Invalid operation number. Please try again.\n\n");
            continue;
        }

        switch(opNum){
            case 1:
                if (c != NULL){
                    printf("A collection already exists.\n");
                    break;
                }
                printf("Please enter the size of the collection.  ");
                scanf(" %d", &colSize);

                c = colCreate(colSize);
                if (c != NULL){
                    printf("Collection created successfully.\n");
                }else{
                    printf("An error occurred.\n");
                }
                break;
            case 2:
                if (c == NULL){
                    printf("You can't destroy a collection that doesn't exist!\n");
                    break;
                }
                if (colDestroy(c) == true){
                    printf("Collection destroyed successfully.\n");
                    c = NULL;
                }else{
                    printf("An error occurred.\n");
                }
                break;
            case 3:
                if (c == NULL){
                    printf("Please create a collection first.\n");
                    break;
                }else if (c->nElms-1 < c->maxElms){
                    Car* newCar;
                    newCar = (Car*)malloc(sizeof(Car));
                    if (newCar != NULL){
                        printf("Please insert the information about the new car.\n");

                        printf("Brand:  ");
                        scanf(" %[^\n]s", newCar->brand);
                        printf("\n");

                        printf("Number of doors:  ");
                        scanf(" %d", &newCar->nDoors);
                        printf("\n");

                        printf("Power:  ");
                        scanf(" %d", &newCar->power);
                        printf("\n");

                        printf("Price:  ");
                        scanf(" %f", &newCar->price);
                        printf("\n");

                        printf("License plate:  ");
                        scanf(" %ld", &newCar->plate);
                        printf("\n");

                        if (colInsert(c,(void*)newCar) != false){
                            printf("Successfully registered a new car.\n");
                            printsCar(newCar);
                            break;
                        }
                    }
                printf("An error occurred.\n");
                }else{
                    printf("The collection is already full.\n");
                }
                break;
            case 4:
                if (c == NULL){
                    printf("You can't search for a car because the collection doesn't exist.\n");
                    break;
                }

                printf("Please enter the brand and the license plate of the car you want to find.\n");

                Car* searchedCar;
                searchedCar = (Car*)malloc(sizeof(Car));

                if (searchedCar == NULL){
                    printf("An error occurred.\n");
                    break;
                }

                char searchedBrand[20];
                long int searchedPlate;

                printf("Car brand:  ");
                scanf(" %[^\n]s", searchedBrand);
                printf("\n");

                printf("License plate:  ");
                scanf(" %ld", &searchedPlate);
                printf("\n");

                searchedCar = (Car*)colQuery(c, (void*)searchedBrand, (void*)searchedPlate);
                if (searchedCar != NULL){
                    printf("Car found.\n");
                    printsCar(searchedCar);
                    free(searchedCar);
                }else{
                    printf("Car not found.\n");
                    free(searchedCar);
                }
                break;
            case 5:
                if (c == NULL){
                    printf("You can't remove a from the collection because the collection doesn't exist.\n");
                    break;
                }else if (c->nElms == 0){
                    printf("There are no cars in the collection.\n");
                    break;
                }else{
                    printf("Please enter the brand and the license plate of the car you want to remove.\n");

                    Car* removeCar;
                    removeCar = (Car*)malloc(sizeof(Car));

                    if (removeCar == NULL){
                        printf("An error occurred.\n");
                        break;
                    }

                    char removeBrand[20];
                    long int removePlate;

                    printf("Car brand:  ");
                    scanf(" %[^\n]s", removeBrand);
                    printf("\n");

                    printf("License plate:  ");
                    scanf(" %ld", &removePlate);
                    printf("\n");

                    removeCar = (Car*)colRemoveSpec(c, (void*)removeBrand, (void*)removePlate);
                    if (removeCar != NULL){
                        printf("The following car has been removed:\n");
                        printsCar(removeCar);
                        free(removeCar);
                    }else{
                        printf("Car not found.\n");
                        free(removeCar);
                    }
                }
                break;
            case 6:
                if (c == NULL){
                    printf("It's not possible to list the cars in the collection because the collection doesn't exist.\n");
                }else if (c->nElms > 0){
                    for (int i=0; i<c->nElms; i++){
                        printf("[%d]:", i+1);
                        printsCar(c->elms[i]);
                    }
                }else{
                    printf("There are no cars in the collection yet.\n");
                }
                break;
            default:
                printf("There was a problem.\n");
                break;
            }

        printf("Continue operations? [Y/N]:  ");
        scanf(" %c", &input);
        input = toupper(input);
        while(input != 'Y' && input != 'N'){
            printf("Invalid input. Please enter [Y/N].  ");
            scanf(" %c", &input);
            input = toupper(input);
            printf("\n");
        }
        if (input ==  'N'){
            stop = true;
        }
    }while(stop == false);

    return 0;
}
