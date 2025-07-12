#include <iostream>
#include <string>


struct bintree {
	bintree* left;
	bintree* right;
	char* value;

    void print_tree() {
        printf("(");
        if (left) {
            left->print_tree();
        }
        printf("%s", value);
        if (right) {
            right->print_tree();
        }
        printf(")");
    }

    void insert_value(char* value) {
        this->insert_tree(create_tree(value));
    }

    void insert_tree(bintree* sub) {
        if (sub->value < value) {
            if (left) {
                left->insert_tree(sub);
            } else {
                left = sub;
            }
        } else {
            if (right) {
                right->insert_tree(sub);
            } else {
                right = sub;
            }
        }
    }
    void delete_tree() {
        if (left) {
            left->delete_tree();
        }
        if (right) {
            delete_tree();
        }
    }
};


bintree* create_tree(char* value) {
    bintree* res = malloc(sizeof(bintree));
    *res = (bintree) {NULL, NULL, value};
    return res;
}



void delete_tree(bintree* root) {
    if (root->left) {
        delete_tree(root->left);
    }
    if (root->right) {
        delete_tree(root->right);
    }
}





int main() {
	bintree t1 = {NULL, NULL, "abr"};
	bintree t2 = {NULL, NULL, "ra"};
	bintree t3 = {NULL, NULL, "aca"};
	bintree t4 = {NULL, NULL, "dab"};
	t1.insert_tree(&t2);
	t1.insert_tree(&t3);
	t1.insert_tree(&t4);
	t1.print_tree();
	printf("\n");
	
	bintree* t5 = create_tree("abr");
	t5->insert_value("ra");
	t5->insert_value("aca");
	t5->insert_value("dab");
	t5->print_tree();
	t5->delete_tree();
	printf("\n");
	
	return 0;
}
