/***************************************

Tree Traversal
CSC - 301
Author: Prabir Pradhan

***************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**************************************
// Utility Functions
***************************************/
void check_pointer(void * p) {
	if (p == NULL){
		printf("Memory Allocation Failed. Exiting...\n");
		exit(1);
	}
}


/**************************************
// Function declarations
***************************************/

// creates an int array from the content of the given file,
// and stores the size of the return array in size
int * create_array (char * filename, int * size);


/******** Tree Functions *********/

int parent_of(int i);

int left_child_of(int i);

int right_child_of(int i);

/******* Traversal *************/

void preorder_depth_first (int * tree, int size);

void inorder_depth_first (int * tree, int size);

void postorder_depth_first (int * tree, int size);

void breadth_first (int * tree, int size);


/**************************************
// Implementations
***************************************/

int * create_array (char * filename, int * size) {
	FILE * stream = fopen(filename, "r");
	char[] buffer = char[16];
	int count = 0;

	// find out how many entries are in the file
	while (fscanf(stream, "%s", buffer) > 0) 
		count++;

	// go to the beginning of the file
	rewind(stream);

	// allocate the return array
	int * arr = (int *) malloc(count * sizeof(int));
	check_pointer(arr);

	// read from file
	for (int i = 0; i < count; i++) {
		fscanf("%d", arr + (i * sizeof(int)));
	}

	*size = count;

	return arr;
}


int parent_of(int i) {
	return (i - 1) / 2;
}

int left_child_of(int i) {
	return 2 * i + 1;
}

int right_child_of(int i) {
	return 2 * i + 2;
}

void preorder_depth_first (int * tree, int size) {
	preorder_helper(tree, size, 0);
}

void preorder_helper (int * tree, int size, int cur_index) {
	if (cur_index < size) {
		printf ("%d\n", tree[cur_index]);
		preorder_helper(tree, size, left_child_of(cur_index));
		preorder_helper(tree, size, right_child_of(cur_index));
	}
}

void inorder_depth_first (int * tree, int size) {
	inorder_helper(tree, size, 0);
}

void inorder_helper (int * tree, int size, int cur_index) {
	if (cur_index < size) {
		inorder_helper(tree, size, left_child_of(cur_index));
		printf ("%d\n", tree[cur_index]);
		inorder_helper(tree, size, right_child_of(cur_index));
	}
}

void postorder_depth_first (int * tree, int size) {
	postorder_helper(tree, size, 0);
}

void postorder_helper (int * tree, int size, int cur_index) {
	if (cur_index < size) {
		postorder_helper(tree, size, left_child_of(cur_index));
		postorder_helper(tree, size, right_child_of(cur_index));
		printf ("%d\n", tree[cur_index]);
	}
}

void breadth_first (int * tree, int size) {
	for (int i = 0; i < size; i++) {
		printf ("%d\n", tree[cur_index]);
	}
}

/**************************************
// main
***************************************/

int main() {

	char * filename = "in-order.txt";

	int size = 0;
	int * tree = create_array(filename, &size);

	printf("filename: %s\n", filename);


	return 0;
}



