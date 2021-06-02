#include<stdio.h>
#include "linked_list.h"

int main() {
    Node * head = NULL;
    int menu=0;
    do {
        printf("1. Show \t 6. Shift \n");
        printf("2. Get \t\t 7. Delete \n");
        printf("3. Push \t 8. Clear \n");
        printf("4. Unshift \t 9. exit \n");
        printf("5. Pop \t \n");
        printf("Select Menu: ");
        scanf("%d", &menu);
        switch (menu) {
            case 1: {
                list_show(&head);
                break;
            }
            case 2: {
                int index;
                printf("index: "); scanf("%d", &index);
                printf("data : %d \n", list_get(&head, index));
                break;
            }
            case 3: {
                int data;
                printf("enter data: "); scanf("%d", &data);
                list_push(&head, data);
                break;
            }
            case 4: {
                list_unshift(&head);
                break;
            }
            case 5: {
                list_pop(&head); break;
            }
            case 6: {
                list_shift(&head); break;
            }
            case 7: {
                int index;
                printf("index: "); scanf("%d", &index);
                list_delete(&head, index);
                break;
            }
            case 8: {
                list_clear(&head);
                break;
            }
            default: {
                if(menu!=9){
                    printf("Invalid menu code!\n");
                }
                break;
            }
        }
    } while (menu!=9);
    return 0;
}
