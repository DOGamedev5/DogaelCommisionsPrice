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
int dificultPrice = 3;


int currenCommision = 0;
int difficult = 0;

int main(int argc, char **argv) {

    if (argc > 1 && strcmp(argv[1], "help") == 0) {
        if (argc > 2) {
            if (strcmp(argv[2], "commisionType") == 0) 
                printf("the type os the commision\n\ntileset: tileset type, price: %d\nsprite: sprite type, price: %d\n\n", commisionPrice[0], commisionPrice[1]);

            else if (strcmp(argv[2], "animatedFrames") == 0) 
                printf("the quantidy frames of animation, if is not animated, simply give a 0 as argument\nthe animatedFrames is multiply by th animatedPrice: %d\n\n", animatedPrice);
            
            else if (strcmp(argv[2], "dificult") == 0) 
                printf("the dificult of the commision, from 0 to 10,\nis subtracted by 5 and multiply by the dificultPrice: %d\n\nit can make the price more expensive or cheap, from %d to +%d\n\n", dificultPrice, dificultPrice * -5, dificultPrice*5);

            else if (strcmp(argv[2], "quality") == 0)
                printf("the quality od the commition, from 1 to 5, is divided by 5 and is used to be a multiply of the final price\n\n");
            
            else if (strcmp(argv[2], "calculation") == 0)
                printf("how the calculation works:\n\n(commisionPrice + (animatedFrames*%d) + ((dificult-5)*%d))*(quality/5) = price\n\n", animatedPrice, dificultPrice);

            else
                printf("'%s' is not a tab of help, see this tabs:\n\ncommisionType\nanimatedFrames\ndificult\nquality\ncalculation\n\n", argv[2]);

            return 0;
        }
        printf("./main <string: commisionType> <int: animatedFrames> <int: dificult> <int: quality>\n");
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

    
    



    return 0;
}

