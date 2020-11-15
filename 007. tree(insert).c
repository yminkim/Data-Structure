#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* l_link;
	struct node* r_link;
}Tree;


Tree* get_node() {
	Tree* temp = (Tree*)malloc(sizeof(Tree));
	temp->l_link = 0;
	temp->r_link = 0;
	return temp;
}


void insert(Tree* *root, int data) {
	Tree* temp = *root;
	if (temp == 0) {
		*root = get_node();
		(**root).data = data;
		return;
	}
	else {
		while (temp != 0) {
			if (data >= temp->data)
				temp = temp->r_link;
			else
				temp = temp->l_link;
		}
		temp = get_node();
		temp->data = data;
	}



	
}


int main() {
	Tree* root = 0;
	insert(&root, 10);
	insert(&root, 20);
	insert(&root, 30);



	return 0;
}


