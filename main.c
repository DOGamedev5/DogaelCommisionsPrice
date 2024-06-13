#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>


char commisionTypes[2][16] = {
    "sprite",
    "tileset"
};

int commisionPrice[2] = {
    20,
    15
};
int animatedPrice = 2;
int difficultPrice = 3;
int animatedFrames = 0;

int currenCommision = 0;
int difficult = 0;
float quality = 0.0;

void help(int argc, char **argv) {
    if (argc > 2) {
        if (strcmp(argv[2], "commisionType") == 0) 
            printf("the type os the commision\n\ntileset: tileset type, price: %d\nsprite: sprite type, price: %d\n\n", commisionPrice[0], commisionPrice[1]);

        else if (strcmp(argv[2], "animatedFrames") == 0) 
            printf("the quantidy frames of animation, if is not animated, simply give a 0 as argument\nthe animatedFrames is multiply by th animatedPrice: %d\n\n", animatedPrice);
        
        else if (strcmp(argv[2], "difficult") == 0) 
            printf("the difficult of the commision, from 0 to 10,\nis subtracted by 5 and multiply by the dificultPrice: %d\n\nit can make the price more expensive or cheap, from %d to +%d\n\n", difficultPrice, difficultPrice * -5, difficultPrice*5);

        else if (strcmp(argv[2], "quality") == 0)
            printf("the quality od the commition, from 1 to 5, is divided by 5 and is used to be a multiply of the final price\n\n");
        
        else if (strcmp(argv[2], "calculation") == 0)
            printf("how the calculation works:\n\n(commisionPrice + (animatedFrames*%d) + ((difficult-5)*%d))*(quality/5) = price\n\n", animatedPrice, difficultPrice);

        else
            printf("'%s' is not a tab of help, see this tabs:\n\ncommisionType\nanimatedFrames\ndifficult\nquality\ncalculation\n\n", argv[2]);

        return;
    }
    
    printf("./main <string: commisionType> <int: animatedFrames> <int: dificult> <int: quality>\n");
}

int main(int argc, char **argv) {

     if (argc > 1 && strcmp(argv[1], "help") == 0) {
        help(argc, argv);
        return 0;
     }

    if (argc <5) {
        printf("ERROR, expected argument, type './main help' to more information\n");
        return 1;
    }

    if (strcmp(argv[1], commisionTypes[0]) == 0)
        currenCommision = 0;

    else if (strcmp(argv[1], commisionTypes[1]) == 0)
        currenCommision = 1;

    else {
        printf("ERROR, expected 'sprite' or 'tileset', got %s instead\n", argv[1]);
        return 1;
    }

    animatedFrames = strtol(argv[2], (char **)NULL, 10);
    difficult = strtol(argv[3], (char **)NULL, 10) - 5;
    quality = (float)strtol(argv[4], (char **)NULL, 10) / 5;

    float price = (commisionPrice[currenCommision] + (animatedFrames*animatedPrice) + (difficult*difficultPrice))*(quality);

    printf("calculation:\n\n(%d + (%d*%d) + ((%d-5)*%d))*(%.2f) = %.2f\n\n", commisionPrice[currenCommision], animatedFrames, animatedPrice, difficult + 5, difficultPrice, quality, price);
    


    return 0;
}

