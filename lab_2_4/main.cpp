#include <iostream>
#include <cstring>

struct node
{
    char data=0;
    node *right= nullptr;
    node *left= nullptr;
    node *parent= nullptr;
};
node *tree = new node;

int precedence(char a)
{
    if ((a=='-')||(a=='+'))
        return 1;
    if ((a=='*')||(a=='/'))
        return 2;
    else
        return 0;
}

void preorder(node *root)
{
    if (root== nullptr)
    {
        return;
    }
    std::cout<<root->data<<"  ";
    preorder(root->left);
    preorder(root->right);
}
void check_priority(char a)
{
    if((a>='1') && (a<='9'))
    {
        std::cout<<"here"<<std::endl;
        tree->data=a;
        tree=tree->parent;

    }
    else
    {
        if(tree->data==0)
        {
            tree->data=a;
            tree->right=new node;
            tree->right->parent=tree;
            tree=tree->right;
        }
        else
        {
            if(precedence(a)<=precedence(tree->data))
            {
                node *newnode = new node;
                newnode->data=a;
                while(tree->parent!= nullptr && (precedence(tree->data)>=precedence(a)))
                {
                    /*
                    newnode->left = tree;
                    newnode = newnode->right;
                    newnode->right=new node;
                    tree=newnode->right;*/
                    tree=tree->parent;
                }
                newnode->left = tree; //встановлюємо вказівник зліва на дерево
                newnode->left->parent=newnode; //робимо цей вузел батьківським
                newnode->right=new node; //створюємо новий вузел справа
                newnode->right->parent=newnode; // встановлюємо посилання на батьківський
                tree=newnode->right; //переходимо вправо
            }
            else /*if(precedence(a)>precedence(tree->data))*/
            {
                node *newnode = new node;
                newnode->data=a; //значення ноди *
                newnode->left=tree->right; // ліва дитина * рівна правій дитині + встановлюємо вказівник спрва на новий вузел
                newnode->left->parent=newnode;// батько встановлюємо посилання на батьківський вузел
                newnode->right=new node;// створили праву дитину
                newnode->right->parent=newnode;// зв'язали цю дитинубатько встановлюємо посилання на батьківський вузел
                tree->right=newnode;//
                tree->right->parent=tree;
                tree=tree->right->right;
            }
        }
    }
}

int main() {
    char a[10];
    tree->left = new node;
    tree->left->parent=tree;
    tree=tree->left;
    strcpy(a, "1+2*3-4+8");
    for(int i=0; i<9; i++)
    {
        std::cout<<a[i]<<std::endl;
        check_priority(a[i]);
        /* std::cout<<a[i]<<std::endl;*/
    }
    preorder(tree);

    return 0;
}



