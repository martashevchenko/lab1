#include <iostream>
#include <fstream>
const static int MAX = 100;

struct Node
        {
    int value;
    int row;
    int column;
    Node* next= nullptr;

};


void createNewNode(Node** head,  int row_index, int column_index, int x)
{
    Node* temp;
    Node* p;
    temp = *head;
    if(temp==nullptr)
    {
        temp = new Node();
        temp->row = row_index;
        temp->column = column_index;
        temp->value = x;
        temp->next = nullptr;
        *head = temp;
    }
    else
    {
        while(temp->next!= nullptr)
             temp = temp->next;

        p = new Node();
        p->row = row_index;
        p->column = column_index;
        p->value = x;
        p->next = nullptr;
        temp->next = p;
    }
}
void printNode(Node* head)
{
    Node* ptr = head;
    std::cout<<"row_position: ";
    while(ptr!= nullptr)
    {
        std::cout<<ptr->row;
        ptr=ptr->next;
    }
    std::cout<<std::endl;
    std::cout<<"column_position: ";

    ptr = head;

    while(ptr != nullptr)
    {
        std::cout<<ptr->column;
        ptr=ptr->next;
    }
    std::cout<<std::endl;
    std::cout<<"Value: ";

    ptr = head;
     while(ptr != nullptr)
     {
         std::cout<<ptr->value;
         ptr=ptr->next;
     }

}

/*Node* push_after_current(Node* list3,int a, int b, int data)
{
    if (list3==nullptr)
    {
        list3=new Node;
        list3->row=a;
        list3->column=b;
        list3->value=data;
        list3->next=nullptr;
        return list3;
    } else
    {
        Node* tmp=new Node;
        tmp->row=a;
        tmp->column=b;
        tmp->value=data;
        tmp->next=list3;
        return tmp;
    }
}*/



Node* addMatrices(Node* listA, Node* listB)
{
    Node* list3 = nullptr;
    while(listA!= nullptr && listB!= nullptr)
    {
        if (listA->row == listB->row)
        {
            if (listA->column == listB->column)
            {
                createNewNode(&list3, listA->row, listA->column, listA->value + listB->value);
                listA = listA->next;
                listB = listB->next;
            } else {
                if (listA->column < listB->column)
                {
                    createNewNode(&list3, listA->row, listA->column, listA->value);
                    listA = listA->next;
                } else
                    {
                    createNewNode(&list3, listB->row, listB->column, listB->value);
                        listB = listB->next;
                }
            }
        } else {
            if (listA->row < listB->row)
            {
                createNewNode(&list3, listA->row, listA->column, listA->value);
                listA = listA->next;
            } else
                {
                createNewNode(&list3, listB->row, listB->column, listB->value);
                    listB = listB->next;
            }

        }

    }
    return list3;

}

int main()
{
    

    int sparseMatrixA[4][5] =
            { {0, 0, 3 , 0 , 4},
              { 0, 0, 5, 7, 0 },
              { 0, 0, 0, 0, 0 },
              { 0, 2, 6, 0, 0 }
    };

    int sparseMatrixB[4][5] =
            { {1, 0, 0, 0 , 2},
              { 0, 3, 0, 1, 0 },
              { 7, 0, 0, 0, 0 },
              { 0, 2, 0, 0, 0 }
            };

    int sparseMatrixC[3][3] =
            { {7, 0, 0},
              {0, 0, 0},
              {0, 0, 1}
            };

    int sparseMatrixF[2][3] =
            { {1, 0, 0},
              {-1, 0, 3}
            };

    int sparseMatrixG[2][3] =
            { {0, 0, 0},
              {0, 0, 0}
            };

    Node *list1 = nullptr;
    for (int i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(sparseMatrixA[i][j]!=0)
            {
                createNewNode(&list1, i, j, sparseMatrixA[i][j]);
            }
        }
    }

    Node* list2 = nullptr;
    for (int i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(sparseMatrixB[i][j]!=0)
            {
                createNewNode(&list2, i, j, sparseMatrixB[i][j]);
            }
        }
    }

    Node* list5 = nullptr;
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if (sparseMatrixC[i][j]!=0)
            {
                createNewNode(&list5, i, j, sparseMatrixC[i][j]);
            }
        }
    }

    Node* list4 = nullptr;
    for(int i=0; i<2; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (sparseMatrixF[i][j]!=0)
            {
                createNewNode(&list4, i, j, sparseMatrixF[i][j]);
            }
        }
    }

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<3; k++)
            {
                sparseMatrixG[i][j] += sparseMatrixF[i][k]*sparseMatrixC[k][j];
            }
        }
    }

    Node* list6= nullptr;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            if (sparseMatrixG[i][j]!=0)
            {
                createNewNode(&list6, i, j, sparseMatrixG[i][j]);
            }
        }
    }



    Node* list3;
    printNode(list1);
    std::cout<<std::endl;
    printNode(list2);
    std::cout<<std::endl;
    list3=addMatrices(list1, list2);
    std::cout<<std::endl;
    printNode(list3);
    std::cout<<"\n";
    printNode(list4);
    std::cout<<std::endl;
    printNode(list5);
    std::cout<<std::endl;
    printNode(list6);



    return 0;
}
