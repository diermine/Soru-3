#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* mergedList = NULL;

    if (head1 == NULL) {
        return head2;
    }
    else if (head2 == NULL) {
        return head1;
    }

    if (head1->data <= head2->data) {
        mergedList = head1;
        mergedList->next = mergeLists(head1->next, head2);
    }
    else {
        mergedList = head2;
        mergedList->next = mergeLists(head1, head2->next);
    }

    return mergedList;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    insertNode(&head1, 5);
    insertNode(&head1, 4);
    insertNode(&head1, 1);

    insertNode(&head2, 6);
    insertNode(&head2, 4);
    insertNode(&head2, 2);

    printf("Liste 1: ");
    printList(head1);

    printf("Liste 2: ");
    printList(head2);

    struct Node* mergedList = mergeLists(head1, head2);

    printf("Çýkýþ: ");
    printList(mergedList);

    return 0;
}
