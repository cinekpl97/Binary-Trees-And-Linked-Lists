#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int val;
    node *next;
};

struct BST {
    int val;
    BST *left;
    BST *right;
    BST *parent;
};

void push_front(node *&head, int value) {
    auto *p = new node;
    p->val = value;
    p->next = nullptr;
    if (head == nullptr) head = p;
    else {
        p->next = head;
        head = p;
    }
}

void push_back(node *&head, int value) {
    node *p = head;
    node *newone = new node;
    newone->val = value;
    newone->next = nullptr;


    if (head == nullptr) head = newone;
    else {
        while (p->next != nullptr) p = p->next;
        p->next = newone;
    }
}

void push_node(node *&head2, node *element) {
    node *p = head2;
    if (head2 == nullptr) {
        head2 = element;
        element->next = nullptr;
    } else {
        while (p->next != nullptr) p = p->next;
        p->next = element;
        element->next = nullptr;
    }
}

void push_sorted(node *&head, int x) {
    node *p = head;
    auto *newnode = new node;
    newnode->val = x;
    newnode->next = nullptr;

    if (head == nullptr) head = newnode;

    while (p != nullptr) {
        if (head->val < x) {

        }
    }
}       //wroc tutaj :(

void print(node *&head) {
    node *p = head;
    while (p != nullptr) {
        cout << p->val << "->";
        p = p->next;
    }
    cout << "NULL";
}

void pop_back(node *&head) {
    node *p = head;
    while (p->next->next != nullptr) p = p->next;
    p->next = nullptr;
}

void pop_front(node *&head) {
    if (head == nullptr) exit(0);
    else {
        head = head->next;
    }
}

int average(node *&head) {
    node *p = head;
    int sum = 0;
    int count = 0;
    while (p != nullptr) {
        sum = sum + p->val;
        count++;
        p = p->next;
    }

    int average = sum / count;
    return average;
}

void higher_than_average_at_the_end(node *&head, node *&head2) {
    if (head->next == nullptr) exit(0);
    node *p = head;
    int count = 0;
    int amount = 0;
    while (p != nullptr) {
        count++;
        amount = p->val + amount;
        p = p->next;
    }
    int average = 0;
    average = amount / count;
    cout << average;
    p = head->next;
    node *temphead = head;
    while (p->next != nullptr) {
        if (head->val > average) {
            node *temp = head;
            head = head->next;
            push_node(head2, temp);
            temphead = head;
            p = temphead->next;
        } else {
            if (p->val > average) {
                temphead->next = p->next;
                push_node(head2, p);
                p = temphead->next;
            } else {
                p = p->next;
                temphead = temphead->next;
            }
        }
    }
    if (p->val > average) {
        push_node(head2, p);
        temphead->next = nullptr;
    }
    cout << temphead->val << endl;
    cout << p->val << endl;
    head->next = head2;
}       //wersja na dwie listy

void higher_than_average_end_of_list(node *&head) {
    node *p = head;
    int average = 0;
    int count = 0;
    int sum = 0;
    while (p != nullptr) {
        sum += p->val;
        count++;
        p = p->next;
    }
    average = sum / count;
    p = head;
    node *current = head->next;
    node *remember = head;
    node *last;
    while (remember->next != nullptr) remember = remember->next;
    last = remember;
    while (current != remember) {
        if (head->val > average) {
            head = head->next;
            last->next = p;
            p->next = nullptr;
            p = head;
            current = head->next;
            last = last->next;
        } else {
            if (current->val > average) {
                p->next = current->next;
                last->next = current;
                current->next = nullptr;
                last = last->next;
                current = p->next;
            } else {
                p = p->next;
                current = current->next;
            }
        }
    }
}                    //wersja na jedna liste

void append_by_even(node *&head) {
    node *p = head;
    while (p != nullptr) {
        if (p->val % 2 == 0) {
            int n = p->val;
            for (int i = 0; i < n; i++) {
                auto *newone = new node;
                newone->val = p->val;
                newone->next = p->next;
                p->next = newone;
                p = p->next;
                cout << p->val;
            }
            p = p->next;

        } else p = p->next;
    }
}

void higher_than_x_at_beginning(node *&head, int x) {
    node *p = head;
    node *current = head;
    p = p->next;
    while (p != nullptr) {
        if (p->val > x) {
            current->next = p->next;
            p->next = head;
            head = p;
            p = current->next;
        } else {
            p = p->next;
            current = current->next;
        }
    }
}

void lower_than_x_at_end(node *&head, int x) {
    node *p = head;
    node *current = head;
    if (head->next == nullptr) exit(0);
    node *last = head;
    while (last->next != nullptr) last = last->next;
    node *remember = last;
    current = current->next;
    while (current != remember->next) {
        if (head->val < x) {
            last->next = head;
            head = head->next;
            current = head->next;
            p = head;
            last = last->next;
            last->next = nullptr;
        } else {
            if (current->val < x) {
                last->next = current;
                p->next = current->next;
                current->next = nullptr;
                last = last->next;
            } else {
                p = p->next;
                current = current->next;
            }
        }
    }


}

void append_by_value_at_the_end(node *&head) {
    node *p = head;
    node *sentry = head;
    while (sentry->next != nullptr) sentry = sentry->next;
    node *remember = sentry;
    while (p->next != nullptr and p != remember) {
        int temp = 0;
        temp = p->val;
        cout << temp;
        for (int i = 0; i < temp; i++) {
            node *newone = new node;
            newone->val = temp;
            newone->next = nullptr;
            sentry->next = newone;
            sentry = sentry->next;
        }
        p = p->next;
    }
}

void change_by_x_with_previous(node *&head, int x) {

    node *p = head;
    node *previous = head;
    node *current = head;
    if (head->next->val == x) {
        p = head->next;
        head->next = p->next;
        p->next = head;
        head = p;
    }
    current = current->next;
    p = p->next->next;
    while (p != nullptr) {
        if (p->val == x) {
            current->next = p->next;
            p->next = current;
            previous->next = p;
            p = current;
            current = previous->next;
        } else {
            p = p->next;
            current = current->next;
            previous = previous->next;
        }
    }
}

void change_by_x_with_next(node *&head, int x) {
    node *p = head;
    node *current = head;
    p = p->next;
    if (head->val == x) {
        head->next = p->next;
        p->next = head;
        head = p;
        p = head->next;
        current = head;
    }
    while (p->next != nullptr) {
        if (p->val == x) {
            current->next = p->next;
            p->next = p->next->next;
            current = current->next;
            current->next = p;
            p = p->next;
            current = current->next;
        } else {
            p = p->next;
            current = current->next;
        }
    }
}

void add_new_element_after_x(node *&head, int x) {
    node *p = head;
    int value = 997;

    while (p != nullptr) {
        if (p->val == x) {
            auto *newone = new node;
            newone->val = value;
            newone->next = p->next;
            p->next = newone;
        }
        p = p->next;
    }
}

void append_by_value_after_x(node *&head, int x) {
    node *p = head;
    while (p != nullptr) {
        if (p->val == x) {
            int temp = p->val;
            for (int i = 0; i < temp; i++) {
                auto *newone = new node;
                newone->val = temp;
                newone->next = p->next;
                p->next = newone;
                p = p->next;
            }
        }
        p = p->next;
    }
}

void add_new_element_before_x(node *&head, int x) {
    node *p = head;
    auto *current = new node;
    if (head->val == x) {
        auto *newone = new node;
        newone->val = 999;
        newone->next = head;
        head = newone;
    }

    current = head->next->next;
    while (current != nullptr) {
        if (current->val == x) {
            auto *newone = new node;
            newone->val = 999;
            newone->next = p->next;
            p->next = newone;
            p = p->next;
        }
        p = p->next;
        current = current->next;
    }
}

void delete_by_x(node *&head, int x) {
    auto *p = head;
    auto *current = head->next;
    while (current->next != nullptr) {
        if (head->val == x) {
            head = head->next;
            p = head;
            current = head->next;
        } else {
            while (current->val == x) {
                p->next = current->next;
                current = p->next;
            }
        }
        p = p->next;
        current = current->next;
    }
    if (current->val == x) p->next = nullptr;
}

void delete_duplicate(node *&head) {
    node *p = head;
    node *current = head;
    node *previous = head;
    current = current->next;
    while (p != nullptr) {

        while (current != nullptr) {
            if (p->val == current->val) {
                current = current->next;
                previous->next = current;
            } else {
                current = current->next;
                previous = previous->next;
            }

        }
        p = p->next;
        previous = p;
        current = p;
    }
}

void blend_two_lists_in_one(node *&head, node *&firsthead) {
    auto *p = head;
    while (p->next != nullptr) p = p->next;
    p->next = firsthead;
}

void last_in_front_of_head(node *&head) {
    auto *p = head;
    while (p->next->next != nullptr) p = p->next;
    p->next->next = head;
    head = p->next;
    p->next = nullptr;
}

void head_at_the_end(node *&head) {
    auto *p = head;
    auto *temp = head;
    while (p->next != nullptr) p = p->next;
    p->next = head;
    temp = temp->next;
    head->next = nullptr;
    head = temp;
}

void delete_every_second_one(node *&head) {
    auto *p = head;
    auto *previous = head;
    bool finish = false;
    p = p->next;
    while (p != nullptr) {
        if (finish == false) {
            previous->next = p->next;
            p = p->next;
            finish = true;
        } else {
            previous = previous->next;
            p = p->next;
            finish = false;
        }
    }
}

void delete_every_third_one(node *&head) {
    node *p = head;
    node *previous = head;
    int count = 2;
    p = p->next;
    while (p != nullptr) {
        if (count == 3) {
            previous->next = p->next;
            p = p->next;
            count = 1;
        } else {
            p = p->next;
            previous = previous->next;
            count++;
        }
    }
/*          ALTERNATYWNA
    node *p=head;
    node *current=head;
    bool doit=true;
    p=p->next;
    current=current->next;
    current=current->next;
    while(current->next!=nullptr){
        if(doit){
            p->next=current->next;
            current->next=nullptr;
            current=p->next;
            p=p->next;
            current=current->next;
            doit=false;
        }
        else{
            p=p->next;
            current=current->next;
            doit=true;
        }
    }
    if(doit){
        p->next=nullptr;
    }
    */
}

void delete_n_elements_after_x(node *&head, int n, int x) {
    node *p = head;
    node *previous;
    while (p->next != nullptr and p->val != x) p = p->next;
    cout << p->val;
    int check = 0;
    while (n != check) {
        if (p->next == nullptr) check = n;
        else {
            p->next = p->next->next;
            check++;
        }
    }
}

void append_whole_list(node *&head) {
    node *p = head;
    node *lastone = head;
    while (lastone->next != nullptr) lastone = lastone->next;
    node *remember = lastone;
    while (p != remember->next) {
        auto *newone = new node;
        newone->val = p->val;
        newone->next = nullptr;
        lastone->next = newone;
        lastone = lastone->next;
        p = p->next;
    }
}

void append_x_at_beginning(node *&head, int x) {
    node *p = head;
    while (p != nullptr) {
        if (p->val == x) push_front(head, p->val);
        p = p->next;
    }
}

void element_from_first_list_to_second_one(node *&head, node *&head2, int x) {
    node *p = head;
    node *current = head;
    current = current->next;
    if (head->val == x) {
        node *temp = head;
        head = head->next;
        push_node(head2, temp);
    }

    while (current != nullptr and head != nullptr) {

        if (head->val == x) {
            node *temp = head;
            head = head->next;
            push_node(head2, temp);

        } else {
            if (current->val == x) {
                p->next = current->next;
                push_node(head2, current);
            }
            current = current->next;
            p = p->next;
        }
    }
}

void append_reversed_list_with_normal(node *&head) {
    node *p = head;
    node *remember = head;
    node *last = head;
    while (remember->next != nullptr) remember = remember->next;
    last = remember;
    while (p != remember->next) {
        auto *newnode = new node;
        if (p == head) {

            last->next = newnode;
            newnode->next = nullptr;
            newnode->val = p->val;
            last = last->next;
            p = p->next;

        } else {
            newnode->val = p->val;
            remember->next = newnode;
            newnode->next = last;
            last = newnode;
            p = p->next;
        }
    }
}

void reverse_list(node *&head) {
    node *p, *current;
    if (head != nullptr) {
        p = head;
        while (p->next != nullptr) {
            current = p->next;
            p->next = current->next;
            current->next = head;
            head = current;
        }
    }
}

void reverse_first_half_and_second(node *&head) {
    node *p = head;
    node *current = head;
    int count = 0;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    p = head;
    count = count / 2;

    if (head != nullptr) {
        p = head;
        for (int i = 0; i < count - 1; i++) {
            current = p->next;
            p->next = current->next;
            current->next = head;
            head = current;
        }
        node *remember = p;
        p = p->next;
        while (p->next != nullptr) {
            current = p->next;
            p->next = current->next;
            current->next = remember->next;
            remember->next = current;
        }
    }
}

void DB_list_higher_than_average_to_new_list(node *&head2) {
    node *DB[50];

    for (int i = 0; i < 50; i++) {
        DB[i] = nullptr;
        for (int j = 0; j < 10; j++) {
            push_back(DB[i], j);
        }
    }

    for (int i = 0; i < 50; i++) {
        node *p = DB[i];
        int average = 0;
        int sum = 0;
        while (p != nullptr) {
            sum = sum + p->val;
            p = p->next;
        }
        average = sum / 10;
        p = DB[i];
        while (DB[i] != nullptr) {
            if (DB[i]->val > average) {
                p = DB[i];
                DB[i] = DB[i]->next;
                push_node(head2, p);
            } else DB[i] = DB[i]->next;
        }

    }
}

void one_list_into_two(node *&head, node *&head2, node *&head3) {
    node *p = head;
    node *remember = head;
    bool maybe = true;
    while (head != nullptr) {
        if (maybe == true) {
            head = head->next;
            push_node(head2, p);
            p = head;
            maybe = false;
        } else {
            head = head->next;
            push_node(head3, p);
            p = head;
            maybe = true;
        }
    }
}

void pushnodereverse(node *&head2, node *element) {
    if (head2 == nullptr) {
        head2 = element;
        head2->next = nullptr;
    } else {
        element->next = head2;
        head2 = element;
    }
}

//trening
void insert(node *&head, int x) {
    node *newone = new node;
    newone->next = NULL;
    newone->val = x;
    if (head == NULL) {
        head = newone;
    } else {
        node *p = head;
        while (p->next != NULL)p = p->next;
        p->next = newone;
    }
}

void iterat(BST *&root, int x) {
    BST *newone = new BST;
    newone->left = newone->right = newone->parent = NULL;
    newone->val = x;
    if(root==NULL) root=newone;
    else{
        BST *p=root, *r;
        while(p!=NULL){
            r=p;
            if(p->val >= x) p=p->left;
            else p=p->right;
        }
        if(r->val >= x) r->left=newone;
        else r->right=newone;
        newone->parent=r;
    }
}

void DBtolists(node *DB[], node *&head, BST *&root) {

    for (int i = 0; i < 50; i++) {
        node *p = DB[i];
        while (p != NULL) {
            node *tmp = p;
            p = p->next;
            if(tmp->val %2==0)push_node(head, tmp);
            else {
                int x=tmp->val;
                iterat(root, x);
            }
        }
    }
}

void printer(BST *&root){
    if(root!=NULL){
        printer(root->left);
        cout<<root->val<<" ";
        printer(root->right);
    }
}

void deleteeverysecond(node *&head, BST *&root){
    node *p=head;
    bool doit=true;
    p=p->next;
    while(p!=NULL){
        if(doit==true){
            int x=p->val;
            cout<<x;
            iterat(root,x);
            doit=false;
        }
        else {
            p=p->next;
            doit=true;
        }
    }
}

BST *predecessor(BST *root){

    if(root->left!=NULL){
        root=root->left;
        while(root->right!=NULL) root=root->right;
        return root;
    }

    while(root->parent!=NULL and root->parent->left==root) root=root->parent;
    return root->parent;
}

void deleteleaf(BST *&root, BST *element){
    if(root==NULL or element==NULL) return;

    BST *p, *r;
    if(element->left==NULL or element->right==NULL) p=element;
    else p=predecessor(element);

    if(p->right!=NULL) r=p->right;
    else r=p->left;

    if(r!=NULL) r->parent=p->parent;

    if(p->parent==NULL)root = r;
    else if(p==p->parent->left) p->parent->left=r;
    else p->parent->right=r;

    if(p!=element) element->val=p->val;
}

void deleteall(BST *&root){
    if(root!=NULL){
        deleteall(root->left);
        deleteall(root->right);
        deleteleaf(root, root);
    }
}
int main() {

    node *DB[50];
    for (int i = 0; i < 50; i++) {
        DB[i] = nullptr;
        for (int j = 0; j < 10; j++) {
            insert(DB[i], j);
        }
    }


    return 0;
}