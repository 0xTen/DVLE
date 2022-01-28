#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define banner "                                                                                            \n                                                                                            \nDDDDDDDDDDDDD      VVVVVVVV           VVVVVVVVLLLLLLLLLLL             EEEEEEEEEEEEEEEEEEEEEE\nD::::::::::::DDD   V::::::V           V::::::VL:::::::::L             E::::::::::::::::::::E\nD:::::::::::::::DD V::::::V           V::::::VL:::::::::L             E::::::::::::::::::::E\nDDD:::::DDDDD:::::DV::::::V           V::::::VLL:::::::LL             EE::::::EEEEEEEEE::::E\n  D:::::D    D:::::DV:::::V           V:::::V   L:::::L                 E:::::E       EEEEEE\n  D:::::D     D:::::DV:::::V         V:::::V    L:::::L                 E:::::E             \n  D:::::D     D:::::D V:::::V       V:::::V     L:::::L                 E::::::EEEEEEEEEE   \n  D:::::D     D:::::D  V:::::V     V:::::V      L:::::L                 E:::::::::::::::E   \n  D:::::D     D:::::D   V:::::V   V:::::V       L:::::L                 E:::::::::::::::E   \n  D:::::D     D:::::D    V:::::V V:::::V        L:::::L                 E::::::EEEEEEEEEE   \n  D:::::D     D:::::D     V:::::V:::::V         L:::::L                 E:::::E             \n  D:::::D    D:::::D       V:::::::::V          L:::::L         LLLLLL  E:::::E       EEEEEE\nDDD:::::DDDDD:::::D         V:::::::V         LL:::::::LLLLLLLLL:::::LEE::::::EEEEEEEE:::::E\nD:::::::::::::::DD           V:::::V          L::::::::::::::::::::::LE::::::::::::::::::::E\nD::::::::::::DDD              V:::V           L::::::::::::::::::::::LE::::::::::::::::::::E\nDDDDDDDDDDDDD                  VVV            LLLLLLLLLLLLLLLLLLLLLLLLEEEEEEEEEEEEEEEEEEEEEE\n                                                                                            \n                                                                                            \n                                                                                            \n                                                                                            \n                                                                                            \n                                                                                            \n                                                                                            "

extern char** environ;
struct data {
    char buf[1024];
};
struct data *chunks[60] = {NULL};
int counter = 0;

int alloc(){
    int option;
    int size;
    int idx;
    printf("1 - malloc\n2 - calloc\n3 - realloc\n\n> ");
    scanf("%d", &option);
    switch(option){
        case 1:
            printf("size: ");
            scanf("%ul", &size);
            chunks[counter] = malloc(size);
            break;
        case 2:
            printf("size: ");
            scanf("%ul", &size);
            chunks[counter] = calloc(1, size);
            break;
        case 3:
            printf("size: ");
            scanf("%ul", &size);
            printf("index: ");
            scanf("%d", &idx);
            chunks[counter] = realloc(chunks[idx], size);
            break;
        default:
            printf("No such option\n\n");
            return counter;

    }
    counter = counter + 1;
    printf("New Chunk added\n\n");
    return counter;
}

void edit(){
    int idx;
    printf("index: ");
    scanf("%d", &idx);
    printf("data: ");
    gets(chunks[idx]->buf);
    printf("Chunk edited\n\n");
}

void dump(){
    int idx;
    printf("index: ");
    scanf("%d", &idx);
    printf("data:\n\n%s\n\n", chunks[idx]->buf);
}

void delete(){
    int idx;
    printf("index: ");
    scanf("%d", &idx);
    free(chunks[idx]->buf);
    printf("Chunk deleted\n");
}

void show_ptr(){
    int idx;
    printf("index: ");
    scanf("%d", &idx);
    printf("%d: %p\n\n", idx, chunks[idx]);
}

void echo(){
    char in[1024];
    printf("string: ");
    scanf("%s", in);
    printf(in);
    printf("\n");
}

void shellz(){
    system("/bin/sh");
}

void leak_libc(){
    printf("puts() @ %p\n\n", puts);
}

void leak_elf(){
    printf("shellz() @ %p\n\n", shellz);
}

void leak_stack(){
    printf("environ @ %p\n\n", environ);
}

void stack_overflow(){
    char overflowme[20];
    printf("overflow me: ");
    gets(overflowme);
}

int main(){
    printf("%s", banner);
    int option;
    while (1){
        printf(
            "1 - Allocate\n" \
            "2 - Edit\n" \
            "3 - Dump\n" \
            "4 - Delete\n" \
            "5 - Show pointer\n" \
            "6 - Leak libc\n" \
            "7 - Leak ELF\n" \
            "8 - Leak stack\n" \
            "9 - Echo\n" \
            "10 - Pop shell\n" \
            "11 - Stack Overflow\n" \
            "12 - Exit\n" \
            "\n> ");
        scanf("%d", &option);
        switch(option){
            case 1:
                counter = alloc();
                break;
            case 2:
                edit();
                break;
            case 3:
                dump();
                break;
            case 4:
                delete();
                break;
            case 5:
                show_ptr();
                break;
            case 6:
                leak_libc();
                break;
            case 7:
                leak_elf();
                break;
            case 8:
                leak_stack();
                break;
            case 9:
                echo();
                break;
            case 10:
                shellz();
                break;
            case 11:
                stack_overflow();
                break;
            case 12:
                printf("exiting...\n");
                return 0;
            default:
                printf("No such option\n\n");

        }
    }
    printf("Error!");
    return 1;
}
