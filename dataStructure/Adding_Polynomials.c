#include <stdio.h>
#include <stdlib.h>
// 다항식의 항을 저장할 구조체
typedef struct Node {
    int coef;   // 계수
    int expo;   // 지수
    struct Node* next;  // 다음 노드를 가리키는 포인터
} Node;

void poly_split(Node* head, Node** a, Node** b);

// 다항식의 항을 추가하는 함수
void append(Node** poly, int coef, int expo) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->coef = coef;
    new_node->expo = expo;
    new_node->next = NULL;
    
    if (*poly == NULL) {
        *poly = new_node;
    } else {
        Node* last_node = *poly;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
}
// 두 개의 다항식을 더하는 함수
Node* poly_add(Node* poly1, Node* poly2){
    Node* result = NULL;// 두 개의 다항식을 더할 다항식
    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 == NULL) {
            append(&result, poly2->coef, poly2->expo);
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            append(&result, poly1->coef, poly1->expo);
            poly1 = poly1->next;
        } else if (poly1->expo > poly2->expo) {
            append(&result, poly1->coef, poly1->expo);
            poly1 = poly1->next;
        } else if (poly1->expo < poly2->expo) {
            append(&result, poly2->coef, poly2->expo);
            poly2 = poly2->next;
        } else {
            int coef_sum = poly1->coef + poly2->coef;
            if (coef_sum != 0) {
                append(&result, coef_sum, poly1->expo);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    return result;
}

/*
// 버블 정렬 O(n^2)
void poly_sort(Node* poly) {
    Node* i, *j;
    int temp_coef, temp_expo;
    for (i = poly; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->expo < j->expo) {
                temp_coef = i->coef;
                temp_expo = i->expo;
                i->coef = j->coef;
                i->expo = j->expo;
                j->coef = temp_coef;
                j->expo = temp_expo;
            }
        }
    }
}
*/

// merge 정렬 O(n*log n)

// 분할하는 함수
void poly_split(Node* head, Node** a, Node** b) {
    Node* fast = head->next;
    Node* slow = head;
    // fast 포인터를 사용해 다항식을 두 부분으로 나누기
    while (fast != NULL) {// fast는 2번 이동하고 slow는 1번 이동하는 점을 이용해 절반으로 나눔
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;// 중간 지점
            fast = fast->next;
        }
    }
    // slow 포인터를 사용해 나눈 두 부분으로 나누기
    *a = head;
    *b = slow->next;
    slow->next = NULL;
}


// 정렬하며 정복하는 함수
Node* merge(Node* a, Node* b) {
    Node* result = NULL;
    // 두 다항식 중 하나가 NULL일 경우
    if (a == NULL) {
        return b;
    }
    else if (b == NULL) {
        return a;
    }
    // a와 b를 비교하면서 정렬하여 큰 값부터 result에 연결(추가)
    if (a->expo >= b->expo) {
        result = a;
        result->next = merge(a->next, b);
    }
    else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

// 분할 정복하는 함수
void merge_sort(Node** poly) {
    Node* head = *poly;
    Node* a = NULL;
    Node* b = NULL;

    // 다항식의 길이가 0이거나 1일 경우
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    // 다항식을 절반으로 나누기
    poly_split(head, &a, &b);
    // 나눈 다항식을 각각 재귀 호출하여 분할
    merge_sort(&a);
    merge_sort(&b);
    // 두 다항식을 정렬하며 병합
    *poly = merge(a, b);
}

// 출력하는 함수
void print_poly(Node* poly) {
    if (poly == NULL) {
        printf("\n");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d", poly->coef, poly->expo);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main(){
    // 파일 접근
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL) {// 파일에 접근되지 않은 경우
        printf("Failed to open input file.\n");
        return 1;
    }
    
    Node* poly1 = NULL; // 첫 번째 다항식
    Node* poly2 = NULL; // 두 번째 다항식

    // 첫 번째 다항식 읽어오기
    while (1) {
        int coef, expo;
        if (fscanf(fp, "(%d,%d)", &coef, &expo) == !2) {
            break;
        }
        append(&poly1, coef, expo);
    }
    fscanf(fp,"\n");// 개행을 읽어 다음 항 읽을 때 오류가 없게 하기 위함
    // 두 번째 다항식 읽어오기
    while (1) {
        int coef, expo;
        if (fscanf(fp, "(%d,%d)", &coef, &expo) == EOF) {
            break;
        }
        append(&poly2, coef, expo);
    }
    fclose(fp);
    merge_sort(&poly1);// 첫 번째 다항식 정렬
    merge_sort(&poly2);// 두 번째 다항식 정렬
    Node* result = poly_add(poly1, poly2);
    print_poly(result);// 더한 결과값 출력
    return 0;
}

//연결리스트가 아니라 배열로 만들면 더 효율적임