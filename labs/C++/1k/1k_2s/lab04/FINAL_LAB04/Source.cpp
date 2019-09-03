#include <iostream>
#include "AFuntions.h"

using namespace std;

int eval(node* root) // tree =
{
	// empty tree  
	if (!root)
		return 0;

	// leaf node i.e, an integer  
	if (!root->left && !root->right)
		return toInt(root->data);

	// Evaluate left subtree  
	int l_val = eval(root->left);

	// Evaluate right subtree  
	int r_val = eval(root->right);

	// Check which operator to apply  
	if (root->data == "+")
		return l_val + r_val;

	if (root->data == "-")
		return l_val - r_val;

	if (root->data == "*")
		return l_val * r_val;

	if (root->data == "^")
		return pow(l_val, r_val);
	return l_val / r_val;
}

void DeleteSpaces(string& postfix) {
	for (size_t i = 0; i < postfix.size(); i++) {
		if (postfix[i] == ' ') {
			postfix.erase(i, (size_t)1);
		}
	}
}

int main(int argc, char **argv) {
	string infix, postfix, tmp;
	cout << "Write down the infix expression with spaces =>" << endl;
	getline(cin, infix);
	char postfix_c[256];

	postfix = InfixToPostfix(infix);
	tmp = postfix;
	DeleteSpaces(tmp);
	strcpy_s(postfix_c, tmp.c_str());


	node *root_tmp = constructTree(postfix_c);
	

	cout << "Infix:   " << infix << endl;
	cout << "Postfix: " << postfix << endl;
	cout << endl << "Visualible Tree in new window: " << endl;

	InizializeGlutRoot(root_tmp);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(1200, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("A Binary search tree");

	// Register function pointers to the drawing framework
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	system("pause>nul");
	return 0;
}