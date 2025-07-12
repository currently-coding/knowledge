// #include <iostream>
// #include <string>


// struct bintree {
// 	bintree* left;
// 	bintree* right;
// 	std::string value;
	
// 	bintree(const std::string& val) : left(nullptr), right(nullptr), value(val) {}

// 	void delete_tree() {
// 		if (left) {
// 			left->delete_tree();
// 		}
// 		if (right) {
// 			right->delete_tree();
// 		}
// 		delete this; // free(root)
// 	}

// 	void print_tree() {
// 		std::cout << "(";
// 		if (left) {
// 			left->print_tree();
// 		}
// 		std::cout << this->value;
// 		if (right) {
// 			right->print_tree();
// 		}
// 		std::cout << ")";

// 	};

// 	void insert_tree(bintree* sub) {
// 		if (sub->value < value) {
// 			if (left) {
// 				left->insert_tree(sub);
// 			} else {
// 				left = sub;
// 			}
// 		} else {
// 			if (right) {
// 				right->insert_tree(sub);
// 			} else {
// 				right = sub;
// 			}
// 		}
// 	}

// 	bintree* create_tree(std::string value) {
// 		bintree* res = new bintree(""); // malloc(sizeof(bintree));
// 		return res;
// 	}

// 	void insert_value(bintree* root, std::string value) {
// 		root->insert_tree(create_tree(value));
// 	}

// };


// int main() {
// 	bintree t1 = {nullptr, nullptr, "abr"};
// 	bintree t2 = {nullptr, nullptr, "ra"};
// 	bintree t3 = {nullptr, nullptr, "aca"};
// 	bintree t4 = {nullptr, nullptr, "dab"};
// 	t1.insert_tree(&t2);
// 	t1.insert_tree(&t3);
// 	t1.insert_tree(&t4);
// 	t1.print_tree();
//     std::cout << std::endl; // printf("\n");
	
// 	bintree* t5 = new bintree("abr");
// 	t5->insert_value("ra");
// 	t5->insert_value("aca");
// 	t5->insert_value("dab");
// 	t5->print_tree();
// 	t5->delete_tree();
// 	std::cout << std::endl; // printf("\n");
	
// 	return 0;
// }
