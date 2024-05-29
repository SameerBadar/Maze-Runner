#include<iostream>
#include"MyNode.h"
#include"Stack.h"
#include<fstream>
using namespace std;
void insertNode(MyNode*&, char, MyNode*&);
void playGame(MyNode*);
void displayGrid(MyNode*,int,char &,Stack &);
int checkNodeNum(MyNode * , int,MyNode * );
int main() {
	cout << endl;
	cout << endl;
	cout << "							 Maze Runner 							  " << endl;
	int opt = 0;
	while (opt != 4) {
		cout << endl;
		cout << endl;
		cout << "Press 1 For Controls	" << endl;
		cout << "Press 2 To For Instructions " << endl;
		cout << "Press 3 To Play Game " << endl;
		cout << "Press 4 To Exit " << endl;
		cin >> opt;
		if (opt == 1) {
			cout << endl;
			cout << endl;
			cout << "Press   A  To Move Left " << endl;
			cout << endl;
			cout << "Press   D  To Move Right " << endl;
			cout << endl;

			cout << "Press   S  To Move Down " << endl;
			cout << endl;

			cout << "Press   W To Move Up " << endl;
			cout << endl;
			cout << endl;
		}
		else if (opt == 2) {
			cout << endl;
			cout << endl;
			cout << "You Will  Have 3 Lives And A Score Board " << endl;
			cout << " * This Represents Your Current Position " << endl;
			cout << " & This Means That You Have Visited That Placed Already And Will Have No Effect On Your Character When You Visit That Place Back " << endl;
			cout << " + This Will Increase Your Score By 10 " << endl;
			cout << " x This Represents A Monster That When You Reached That Place Your 1 Life Will Deduct " << endl;
			cout << " 1 This Represents Your Final Destination Where You Need To Reached To Finish This Game " << endl;
			cout << endl;
			cout << endl;
		}
		else if (opt == 3) {
			cout << endl;
			cout << endl;
			MyNode* head = nullptr;
			MyNode* tail = nullptr;
			ifstream fin;
			int level = 0;
			fin.open("count.txt");
			fin >> level;
			fin.close();
			if (level == 0) {
				fin.open("level1.txt");
				int count = 0;
			if (!fin.is_open()) {
				cout << "File Not Found " << endl;
			}
			else {
				while (!fin.eof()) {
					char waste;
					fin >> waste;
					count++;
				}
			}

			fin.close();
			fin.open("level1.txt");
			if (!fin.is_open()) {
				cout << "File Not Found " << endl;
			}
			else {
				for (int i = 0; i < count - 1; i++) {
					char waste;
					fin >> waste;
					if (waste != ' ') {
						insertNode(tail, waste, head);
					}
				}
			}
			fin.close();

			}
			if (level == 1) {
				fin.open("level2.txt");

				int count = 0;
				if (!fin.is_open()) {
					cout << "File Not Found " << endl;
				}
				else {
					while (!fin.eof()) {
						char waste;
						fin >> waste;
						count++;
					}
				}

				fin.close();
				fin.open("level2.txt");

				if (!fin.is_open()) {
					cout << "File Not Found " << endl;
				}
				else {
					for (int i = 0; i < count - 1; i++) {
						char waste;
						fin >> waste;
						if (waste != ' ') {
							insertNode(tail, waste, head);
						}
					}
				}
				fin.close();

			}
			if (level == 2) {
				fin.open("level3.txt");
				int count = 0;
				if (!fin.is_open()) {
					cout << "File Not Found " << endl;
				}
				else {
					while (!fin.eof()) {
						char waste;
						fin >> waste;
						count++;
					}
				}

				fin.close();
				fin.open("level3.txt");

				if (!fin.is_open()) {
					cout << "File Not Found " << endl;
				}
				else {
					for (int i = 0; i < count - 1; i++) {
						char waste;
						fin >> waste;
						if (waste != ' ') {
							insertNode(tail, waste, head);
						}
					}
				}
				fin.close();

			
			}
			if (level == 3) {
				fin.open("level4.txt");

				int count = 0;
				if (!fin.is_open()) {
					cout << "File Not Found " << endl;
				}
				else {
					while (!fin.eof()) {
						char waste;
						fin >> waste;
						count++;
					}
				}

				fin.close();
				fin.open("level4.txt");
				if (!fin.is_open()) {
					cout << "File Not Found " << endl;
				}
				else {
					for (int i = 0; i < count - 1; i++) {
						char waste;
						fin >> waste;
						if (waste != ' ') {
							insertNode(tail, waste, head);
						}
					}
				}
				fin.close();

			
			}
			if (level == 4) {
				fin.open("level5.txt");
				int count = 0;
				if (!fin.is_open()) {
					cout << "File Not Found " << endl;
				}
				else {
					while (!fin.eof()) {
						char waste;
						fin >> waste;
						count++;
					}
				}

				fin.close();
				fin.open("level5.txt");
				if (!fin.is_open()) {
					cout << "File Not Found " << endl;
				}
				else {
					for (int i = 0; i < count - 1; i++) {
						char waste;
						fin >> waste;
						if (waste != ' ') {
							insertNode(tail, waste, head);
						}
					}
				}
				fin.close();

			}
			if (level == 4) {
				ofstream fout;
				fout.open("count.txt");
				level = 0;
				fout << level << endl;
				fout.close();
			}
			else {
				ofstream fout;
				fout.open("count.txt");
				fout << level + 1 << endl;
				fout.close();
			}


			playGame(head);
			delete head;
			delete tail;
		}
		else if (opt == 4) {
			cout << endl;
			cout << "Thanks For Playing This Game " << endl;
			cout << endl;
		}
	}
	return 0;
}


void insertNode(MyNode*& current,char value,MyNode *& _head) {
	if (_head == nullptr) {
		_head = new MyNode();
		_head->value = value;
		current = _head;
	}
	else {
		MyNode* temp = new MyNode();
		temp->value = value;
		temp->previous = current;
		temp->next = nullptr;
		current->next = temp;
		current = temp;
	}
}
void playGame(MyNode* head) {
	char opt = '\0';
	int lives = 3;
	int score = 0;
	cout << "							Lives : " << lives << endl;
	cout << "							Score : " << score << endl;
	MyNode* current = head;
	Stack obj;
	displayGrid(head, 0, opt,obj);
	while (lives!=0) {
		int count = 0;
		cin >> opt;
		if (opt == 'a' || opt == 'A') {
			if (current->previous == nullptr) {
				cout << "Road Block" << endl;
				cout << "							Lives : " << lives << endl;
				cout << "							Score : " << score << endl;
				displayGrid(head, 0, opt,obj);
				continue;
			}
			else {
				count = checkNodeNum(head, count, current);
				if (count == 4 || count == 8) {
					cout << "Road Block" << endl;
					cout<<"							Lives : "<<lives << endl;
					cout << "						Score : "<<score << endl;
					displayGrid(head, count, opt,obj);
					continue;
				}
				else {
					obj.push(current);
					current = current->previous;
					if (current->value == '1') { cout << "You Have Won The Game " << endl; break; }
					if (current->value == '+') { score += 10; }
					else if (current->value == 'x' || current->value == 'X') { lives -= 1; }
					cout << "							Lives : " << lives << endl;
					cout << "							Score : " << score << endl;
					displayGrid(head, count-1, opt,obj);
					continue;
				}
			}	
		}
		if (opt == 'd' || opt == 'D') {
			if (current->next != nullptr) {
				count = checkNodeNum(head, 0, current);
				if (count == 3 || count == 7) {
					cout << "Road Block " << endl;
					cout << "							Lives : " << lives << endl;
					cout << "							Score : " << score << endl;
					displayGrid(head, count, opt, obj);
					continue;
				}
				else {
					obj.push(current);

					current = current->next;
					if (current->value == '1') {
						cout << "You Have Won The Game " << endl;
						break;
					}
					if (current->value == '+') { score += 10; }
					else if (current->value == 'x' || current->value == 'X') { lives -= 1; }
					cout << "							Lives : " << lives << endl;
					cout << "							Score : " << score << endl;

					displayGrid(head, count + 1, opt, obj);

					continue;
				}
			}
			else {
				if (current->value == '1') {
					cout << "You Have Won The Game " << endl;
					break;
				}
				else {
					cout << "Road Block " << endl;
					cout << "							Lives : " << lives << endl;
					cout << "							Score : " << score << endl;
					displayGrid(head, count, opt, obj);
					continue;
				}
			}
		}
		if (opt == 's' || opt == 'S') {
			count = checkNodeNum(head, count, current);
			if (count >= 8 && count <= 11) {
				cout << "Road Block " << endl;
				cout << "							Lives : " << lives << endl;
				cout << "							Score : " << score << endl;
				displayGrid(head, count, opt,obj);
				continue;
			}
			else {
				obj.push(current);
				for (int i = 0; i < 4; i++) {
					if (current->next != nullptr) {
					current = current->next;
					}
				}
				if (current->value == '1') { cout << "You Have Won The Game " << endl; break; }
				if (current->value == '+') {
					score += 10;
				}
				else if (current->value == 'X' || current->value=='x') {
					lives -= 1;
				}
				count = checkNodeNum(head, 0, current);
				cout << "							Lives : " << lives << endl;
				cout << "							Score : " << score << endl;
				displayGrid(head, count, opt,obj);
				continue;
			}
		}
		if (opt == 'w' || opt == 'W') {
			count = checkNodeNum(head, count, current);
			if (count >= 0 && count <= 3) {
				cout << "Road Block " << endl;
				cout << "							Lives : " << lives << endl;
				cout << "							Score : " << score << endl;
				displayGrid(head, count, opt, obj);
				continue;
			}
			else {
				obj.push(current);
				for (int i = 0; i < 4; i++) {
					if (current->previous != nullptr) {
						current = current->previous;
					}
				}
				if (current->value == '1') { cout << "You Have Won The Game " << endl; break; }
				if (current->value == '+') {
					score += 10;
				}
				else if (current->value == 'X' || current->value == 'x') {
					lives -= 1;
				}
				count = checkNodeNum(head, 0, current);
				cout << "							Lives : " << lives << endl;
				cout << "							Score : " << score << endl;
				displayGrid(head, count, opt, obj);
				continue;
			}
		}
		else {
			cout << "Enter Valid Key " << endl;
			count = checkNodeNum(head, 0, current);
			cout << "							Lives : " << lives << endl;
			cout << "							Score : " << score << endl;
			displayGrid(head, count, opt, obj);

		}
	
	}
	if (lives == 0) {
	cout << endl;
	cout << "You Have Lost This Battle " << endl;
	}
}
void displayGrid(MyNode* head, int count,char & opt,Stack &obj) {
	MyNode* temp = head;
	MyNode* temp2 = obj.pop();
	if (temp2 != nullptr) {
		temp2->value = '&';
	}
	for (int i = 0; i < count; i++) {
		temp = temp->next;
	}
	temp->value = '*';
	
	temp = head;
	
	for (int i = 0; i < 3; i++) {
		cout << "|	";
		for (int j = 0; j < 4; j++) {
			cout << temp->value<<"	";
			temp = temp->next;
		}
		cout << "|" << endl;
	}
}



int checkNodeNum(MyNode* tempHead, int count, MyNode* current) {
	while (tempHead!=current) {
		count++;
		if (tempHead->next != nullptr) {
		tempHead = tempHead->next;
		}
		else { return count; }
	}
	return count;
}