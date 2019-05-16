#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct EngRusMap {
	string eng;
	string rus;
	int count;
};

struct node
{
	EngRusMap key; //s eng, s rus, i count
	struct node *left, *right;
};

ostream& operator<<(ostream& stream, EngRusMap& erm) {
	stream << erm.eng << " : " << erm.rus << " ( " << erm.count << " )";
	return stream;
}

bool operator<(EngRusMap& rhs, EngRusMap& lhs) {
	return rhs.eng < lhs.eng;
}

bool operator>(EngRusMap& rhs, EngRusMap& lhs) {
	return rhs.eng > lhs.eng;
}

bool operator==(EngRusMap& rhs, EngRusMap& lhs) {
	return rhs.eng == lhs.eng;
}

node *newNode(EngRusMap item)
{
	node *temp = new node();
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

node *newNode_int(int item)
{
	node *temp = new node();
	temp->key.count = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->key << endl;
		inorder(root->right);
	}
}

node* FindMin(node* root) {
	node* cur = root;
	while (cur->left != NULL) {
		cur = cur->left;
	}
	return cur;
}

node* Delete(node* root, EngRusMap key) {
	if (root == NULL) return root;
	else if (key < root->key) root->left = Delete(root->left, key);
	else if (key > root->key) root->right = Delete(root->right, key);
	else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
			return root;
		}
		else if (root->left == NULL) {
			node *temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		else if (root->right == NULL) {
			node *temp = root;
			root = root->left;
			delete temp;
			return root;
		}
		else {
			node *temp = FindMin(root->right);
			root->key = temp->key;
			root->right = Delete(root->right, temp->key);
		}
	}
	return root;
}

node* Insert(node* root, EngRusMap key)
{
	if (root == NULL) return newNode(key);

	if (key < root->key)
		root->left = Insert(root->left, key);
	else if (key > root->key)
		root->right = Insert(root->right, key);

	return root;
}

node* Insert_int(node* root, EngRusMap key)
{
	if (root == NULL) return newNode(key);

	if (key.count < root->key.count)
		root->left = Insert(root->left, key);
	else if (key.count > root->key.count)
		root->right = Insert(root->right, key);

	return root;
}

EngRusMap FindMaxCount(node* root) {
	EngRusMap r = { "", "", 0 };
	if (root != NULL)
	{
		FindMaxCount(root->left);
		if (root->key.count > r.count) {
			r.count = root->key.count;
			r.eng = root->key.eng;
			r.rus = root->key.rus;
		}
		FindMaxCount(root->right);
	}
	return r;
}

node* newOrdnung(node* root) {
	node* cur = root;
	node* temp = NULL;
	while (cur != NULL) {
		EngRusMap m = FindMaxCount(cur);
		temp = Insert_int(temp, m);
		cur = Delete(cur, m);
	}
	return temp;
}

bool Exist(node* root, string eng) {
	if (root == NULL) return false;
	else if (root->key.eng == eng) return true;
	else if (eng <= root->key.eng) return Exist(root->left, eng);
	else return Exist(root->right, eng);
}

string foundRus(node* root, string eng) {
	if (root == NULL) return "";
	else if (root->key.eng == eng) return root->key.rus;
	else if (eng <= root->key.eng) return foundRus(root->left, eng);
	else return foundRus(root->right, eng);
}

int foundCount(node* root, string eng) {
	if (root == NULL) return 0;
	else if (root->key.eng == eng) return root->key.count;
	else if (eng <= root->key.eng) return foundCount(root->left, eng);
	else return foundCount(root->right, eng);
}

void IncrementCount(node* root, string eng) {
	if (root->key.eng == eng) root->key.count++;
	else if (eng <= root->key.eng) IncrementCount(root->left, eng);
	else IncrementCount(root->right, eng);
}

//class Node {
//	Node();
//
//	Node *right;
//	Node *left;
//	EngRusMap data;
//
//	Node *newNode(EngRusMap item);
//	void inorder(Node *root);
//	Node* insert(Node* node, EngRusMap key);
//};
//Node * Node::newNode(EngRusMap item)
//{
//	Node *temp = new Node();
//	temp->data = item;
//	temp->left = temp->right = NULL;
//	return temp;
//}
//
//void Node::inorder(Node * root)
//{
//	if (root != NULL)
//	{
//		inorder(root->left);
//		cout << root->data << endl;
//		inorder(root->right);
//	}
//}
//
//Node * Node::insert(Node * node, EngRusMap key)
//{
//	if (node == NULL) return newNode(key);
//
//	/* Otherwise, recur down the tree */
//	if (key < node->data)
//		node->left = insert(node->left, key);
//	else if (key > node->data)
//		node->right = insert(node->right, key);
//
//	return node;
//}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	node *root = NULL;
	node *newroot = NULL;

	while (1) {
		cout << "1) Добавить n слов в словарь" << endl
			<< "2) Найти значение английского слова" << endl
			<< "3) Сформировать новое представления словаря" << endl
			<< "4) Вывести словарь" << endl
			<< "5) Вывести новое представление словаря" << endl
			<< "6) Выход" << endl;

		int c;
		cin >> c;
		system("cls");
		switch (c) {
		case 1: {
			int n, count;
			string eng, rus;
			cout << "Сколько слов вы хотите добавить?" << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				EngRusMap m;
				cout << "Введите " << i + 1 << " английское слово, соответствующее ему русское слово и количество обращений" << endl;
				cin >> m.eng >> m.rus >> m.count;

				root = Insert(root, m);
			}
			system("cls");
			break;
		}
		case 2: {
			string eng;
			cout << "Введите нужное вам слово" << endl;
			cin >> eng;
			if (Exist(root, eng)) {
				cout << eng << " : " << foundRus(root, eng) << " ( " << foundCount(root, eng) << " ) " << endl;
				IncrementCount(root, eng);
			}
			else
				cout << "Такого слова в словаре нет!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			newroot = newOrdnung(root);
			break;
		}
		case 4: {
			inorder(root);
			system("pause>nul");
			system("cls");
			break; }
		case 5: {
			inorder(newroot);
			system("pause>nul");
			system("cls");
			break; }
		case 6: {
			cout << "Удачи! До скорой встречи)" << endl;
			system("pause>nul");
			return 0;
		}
		default: {
			cout << "Неправильный ввод" << endl;
			system("pause");
			system("cls");
		}
		}
	}

	system("pause");
	return 0;
}