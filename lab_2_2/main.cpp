#include <Windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;


struct list {
    int data;
    list* right;
    list* left;
    list* top;
    list* bot;
};

void push_right(list*, int);
void push_top(list* head, int data);
void find_moves(char, int, list*);

int main()
{
    list* head = new list;
    head->data = 11;
    head->right = NULL;
    head->left = NULL;
    head->bot = NULL;
    head->top = NULL;
    for (int i = 2; i <= 8; i++) {
        int data = 10 + i;
        push_right(head, data);
    }
    list* buf = head;
    for (int i = 1; i <= 8; i++) {
        for (int j = 2; j <= 8; j++) {
            int data = j * 10 + i;
            push_top(head, data);
        }
        head = head->right;
    }
    head = buf;
    buf = head;
    for (int j = 1; j <= 7; j++) {
        list* tmp = head;
        for (int i = 1; i <= 7;i++) {
            tmp->top->right = tmp->right->top;
            tmp->right->top->left = tmp->top;
            tmp = tmp->right;
        }
        head = head->top;
    }
    head = buf;
    cout << "Enter pos and type\n(m-king q-queen r-rook b-bishop k-knight p-paw)\n";
    int cell;
    char figure;
    cin >> cell;
    cin >> figure;
    list* tmp = head;
    find_moves(figure, cell, head);
    system("pause");
    return 0;
}
void push_right(list* head,int data) {
    if (head->bot == NULL) {
        while (head->right != NULL) {
            head = head->right;
        }
        list* tmp = new list;
        tmp->data = data;
        head->right = tmp;
        tmp->left = head;
        tmp->bot = NULL;
        tmp->top = NULL;
        tmp->right = NULL;
    }
    else {
        while (head->right != NULL) {
            head = head->right;
        }
        list* tmp = new list;
        tmp->data = data;
        head->right = tmp;
        tmp->left = head;
        tmp->right = NULL;
        tmp->top = NULL;
    }

}
void push_top(list* head, int data) {
    if (head->left == NULL) {
        while (head->top != NULL) {
            head = head->top;
        }
        list* tmp = new list;
        tmp->data = data;
        head->top = tmp;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->bot = head;
        tmp->top = NULL;
    }
    else {
        while (head->top != NULL) {
            head = head->top;
        }
        list* tmp = new list;
        tmp->data = data;
        head->top = tmp;
        tmp->bot = head;
        tmp->top = NULL;
        tmp->right = NULL;
    }

}
void find_moves(char type, int pos,list* head) {
    list* tmp = head;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 1; i < (pos / 10); i++) {
        tmp = tmp->top;
    }
    for (int i = 1; i < (pos % 10); i++) {
        tmp = tmp->right;
    }
    int moves[40];
    int number_of_moves = 0;
    switch (type)
    {
        case 'm': {
            list* m_tmp = tmp;
            if (tmp->top != NULL) {
                cout << tmp->top->data<<" ";
                moves[number_of_moves] = tmp->top->data;
                number_of_moves++;
            }
            if (tmp->top != NULL && tmp->top->right != NULL) {
                cout << tmp->top->right->data << " ";
                moves[number_of_moves] = tmp->top->right->data;
                number_of_moves++;
            }
            if (tmp->right != NULL) {
                cout << tmp->right->data << " ";
                moves[number_of_moves] = tmp->right->data;
                number_of_moves++;
            }
            if (tmp->right != NULL && tmp->right->bot != NULL) {
                cout << tmp->right->bot->data << " ";
                moves[number_of_moves] = tmp->right->bot->data;
                number_of_moves++;
            }
            if (tmp->bot != NULL) {
                cout << tmp->bot->data << " ";
                moves[number_of_moves] = tmp->bot->data;
                number_of_moves++;
            }
            if (tmp->bot != NULL&& tmp->bot->left != NULL) {
                cout << tmp->bot->left->data << " ";
                moves[number_of_moves] = tmp->bot->left->data;
                number_of_moves++;
            }
            if (tmp->left != NULL) {
                cout << tmp->left->data << " ";
                moves[number_of_moves] = tmp->left->data;
                number_of_moves++;
            }
            if (tmp->left != NULL && tmp->left->top != NULL) {
                cout << tmp->left->top->data << " ";
                moves[number_of_moves] = tmp->left->top->data;
                number_of_moves++;
            }
            tmp = m_tmp;
            break;
        }
        case 'q': {
            list* r_tmp = tmp;
            while (tmp != NULL) {

                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                tmp = tmp->top;
            }
            tmp = r_tmp;
            while (tmp != NULL) {
                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                tmp = tmp->right;
            }
            tmp = r_tmp;
            while (tmp != NULL) {
                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                tmp = tmp->bot;
            }
            tmp = r_tmp;
            while (tmp != NULL) {
                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                tmp = tmp->left;
            }
            tmp = r_tmp;
            while (tmp != NULL) {

                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                if (tmp->top != NULL && tmp->top->right != NULL) {
                    tmp = tmp->top->right;
                }
                else {
                    tmp = NULL;
                }

            }
            tmp = r_tmp;
            while (tmp != NULL) {
                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                if (tmp->right != NULL && tmp->right->bot != NULL) {
                    tmp = tmp->right->bot;
                }
                else {
                    tmp = NULL;
                }
            }
            tmp = r_tmp;
            while (tmp != NULL) {
                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                if (tmp->bot != NULL && tmp->bot->left != NULL) {
                    tmp = tmp->bot->left;
                }
                else {
                    tmp = NULL;
                }
            }
            tmp = r_tmp;
            while (tmp != NULL) {
                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                if (tmp->left != NULL && tmp->left->top != NULL) {
                    tmp = tmp->left->top;
                }
                else {
                    tmp = NULL;
                }
            }
            tmp = r_tmp;
            break;
        }
        case 'r': {
            list* r_tmp = tmp;
            while (tmp != NULL) {

                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                tmp = tmp->top;
            }
            tmp = r_tmp;
            while (tmp != NULL) {
                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                tmp = tmp->right;
            }
            tmp = r_tmp;
            while (tmp != NULL) {
                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                tmp = tmp->bot;
            }
            tmp = r_tmp;
            while (tmp != NULL) {
                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                tmp = tmp->left;
            }
            tmp = r_tmp;
            break;
        }
        case 'b': {
            list* r_tmp = tmp;
            while (tmp != NULL) {

                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                if (tmp->top != NULL && tmp->top->right != NULL) {
                    tmp = tmp->top->right;
                }
                else {
                    tmp = NULL;
                }

            }
            tmp = r_tmp;
            while (tmp != NULL) {
                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                if (tmp->right != NULL && tmp->right->bot != NULL) {
                    tmp = tmp->right->bot;
                }
                else {
                    tmp = NULL;
                }
            }
            tmp = r_tmp;
            while (tmp != NULL) {
                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                if (tmp->bot != NULL && tmp->bot->left != NULL) {
                    tmp = tmp->bot->left;
                }
                else {
                    tmp = NULL;
                }
            }
            tmp = r_tmp;
            while (tmp != NULL) {
                moves[number_of_moves] = tmp->data;
                number_of_moves++;
                if (tmp->left != NULL && tmp->left->top != NULL) {
                    tmp = tmp->left->top;
                }
                else {
                    tmp = NULL;
                }
            }
            tmp = r_tmp;
            break;
        }
        case 'k': {
            if (tmp->top != NULL && tmp->top->top != NULL && tmp->top->top->left != NULL) {
                moves[number_of_moves] = tmp->top->top->left->data;
                number_of_moves++;
            }
            if (tmp->top != NULL && tmp->top->top != NULL && tmp->top->top->right != NULL) {
                moves[number_of_moves] = tmp->top->top->right->data;
                number_of_moves++;
            }
            if (tmp->right!=NULL&& tmp->right->right != NULL&& tmp->right->right->top != NULL) {
                moves[number_of_moves] = tmp->right->right->top->data;
                number_of_moves++;
            }
            if (tmp->right != NULL && tmp->right->right != NULL && tmp->right->right->bot != NULL) {
                moves[number_of_moves] = tmp->right->right->bot->data;
                number_of_moves++;
            }
            if (tmp->bot != NULL && tmp->bot->bot != NULL && tmp->bot->bot->right != NULL) {
                moves[number_of_moves] = tmp->bot->bot->right->data;
                number_of_moves++;
            }
            if (tmp->bot != NULL && tmp->bot->bot != NULL && tmp->bot->bot->left != NULL) {
                moves[number_of_moves] = tmp->bot->bot->left->data;
                number_of_moves++;
            }
            if (tmp->left != NULL && tmp->left->left != NULL && tmp->left->left->bot != NULL) {
                moves[number_of_moves] = tmp->left->left->bot->data;
                number_of_moves++;
            }
            if (tmp->left != NULL && tmp->left->left != NULL && tmp->left->left->top != NULL) {
                moves[number_of_moves] = tmp->left->left->top->data;
                number_of_moves++;
            }
            break;
        }
        case 'p': {
            cout << "Black or white pow?(b or w)";
            char color;
            cin >> color;
            if (color == 'w') {
                if ((pos / 10) == 2) {
                    moves[number_of_moves] = tmp->top->data;
                    number_of_moves++;
                    moves[number_of_moves] = tmp->top->top->data;
                    number_of_moves++;
                }
                else {
                    if ((pos / 10) == 1|| (pos / 10) == 8) {
                        cout << "No such pos ";
                    }
                    else {
                        moves[number_of_moves] = tmp->top->data;
                        number_of_moves++;
                    }

                }
            }
            else {
                if ((pos / 10) == 7) {
                    moves[number_of_moves] = tmp->bot->data;
                    number_of_moves++;
                    moves[number_of_moves] = tmp->bot->bot->data;
                    number_of_moves++;
                }
                else {
                    if ((pos / 10) == 1 || (pos / 10) == 8) {
                        cout << "No such pos ";
                    }
                    else {
                        moves[number_of_moves] = tmp->bot->data;
                        number_of_moves++;
                    }

                }
            }

            break;
        }
        default:
            break;
    }
    cout << endl;
    for (int i = 8; i >= 1; i--) {
        for (int j = 1; j <= 8; j++) {
            if ((i * 10 + j) == tmp->data) {
                SetConsoleTextAttribute(console, 12);//12-red 11-light blue

                cout << i << j << " ";
            }
            else {
                bool miss=false;
                for (int k = 0; k < number_of_moves; k++) {
                    if ((i*10+j)==moves[k]) {
                        SetConsoleTextAttribute(console, 11);
                        cout << i << j << " ";
                        miss = true;
                    }
                }
                SetConsoleTextAttribute(console, 15);
                if (miss == false) {
                    cout << i << j << " ";
                }

            }


        }
        cout << endl;
    }
}