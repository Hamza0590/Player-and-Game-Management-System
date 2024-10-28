#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
using namespace std;
class gameNode
{
public:
	string gameId, name, developer, publisher;
	int download;
	float fileSize;
	gameNode* left , *right;
	gameNode()
	{
		gameId = name = developer = publisher = "";
		download = 0;
		fileSize = 0;
		right = NULL;
		left = NULL;
	}
	gameNode* getLeft() const
	{
		return left;
	}
	gameNode* getRight() const
	{
		return right;
	}
	void print() const
	{
		cout << "Game Id: " << gameId << endl << "Name: " << name << endl << "Developer: " << developer << endl << "Publisher: " << publisher << endl << "Download: " << download << endl << "File Size in GB's: " << fileSize << endl << endl;;
	}
};
class gameTree
{
	gameNode * root;
public:
	gameTree()
	{
		root = NULL;
	}
	void insert()
	{
		string data;
		fstream read;
		read.open("Games.txt", ios::in);
		while (getline(read, data))
		{
			cout << data << endl;
			stringstream ss(data);
			gameNode* temp = new gameNode();
			getline(ss, temp->gameId, ',');
			getline(ss, temp->name, ',');
			getline(ss, temp->developer, ',');
			getline(ss, temp->publisher, ',');
			string tempFileSize, tempDown;
			getline(ss, tempFileSize, ',');
			temp->fileSize = stof(tempFileSize);
			getline(ss, tempDown, ',');
			temp->download = stoi(tempDown);
			root = insertNODE(root, temp);

		}
		read.close();

	}
	gameNode* insertNODE(gameNode* rootCopy, gameNode* temp)
	{
					
		if (rootCopy == NULL)
		{
			return temp;
		}
		else
		{
			if (rootCopy->gameId < temp->gameId)
			{
				rootCopy->right = insertNODE(rootCopy->right, temp);
			}
			else if (rootCopy->gameId > temp->gameId)
			{
				rootCopy ->left = insertNODE(rootCopy->left, temp);
			}
		}
		return rootCopy;
	}
	void preorder(gameNode* treeNode)

	{

		if (treeNode != NULL)

		{

			treeNode->print();
			preorder(treeNode->getLeft());
			preorder(treeNode->getRight());

		}

	}
	gameNode* getRoot()
	{
		return root;
	}
		
	
};
class gamesPlayed
{
public:
	string gameId;
	float hoursPlayed;
	int achievementUnlocked;
	gamesPlayed* next;
	gamesPlayed()
	{
		next = NULL;
		gameId = "";
		hoursPlayed = 0;
		achievementUnlocked = 0.0;
	}
};
class playerNode
{
public:
	string playerId, name, phone, email, password;
	gamesPlayed *played;
	playerNode* left, * right;
	playerNode():played()
	{
		playerId = name = phone = email = password = "";
		left = right = NULL;
	}
	void insertNode(gamesPlayed * temp)
	{
		if (played == NULL)
		{
			played = temp;
		}
		else
		{
			gamesPlayed* traverse = played;
			while (traverse->next != NULL)
			{
				traverse = traverse->next;
			}
			traverse->next = temp;
		}
	}
	void print()
	{
		cout << " Player ID: " << playerId << ' , ' << " Name: " << name << ' , ' << " Phone: " << phone << ' , ' << " Email: " << email << ' , ' << " Password: " << password << endl;
		gamesPlayed* temp = played;
		while (temp != NULL)
		{
			cout << "\tGame ID: " << temp->gameId << ' , ' << " Hours Played: " << temp->hoursPlayed << ' , ' << " Achievement Unlocked: " << temp->achievementUnlocked << endl;
			temp = temp->next;
		}
	}
	playerNode* getLeft() const
	{
		return left;
	}
	playerNode* getRight() const
	{
		return right;
	}
};

class playerTree
{
public:
	playerNode* root;
	playerTree()
	{
		root = NULL;
	}
	void insert()
	{
		string data;
		fstream read;
		int i = 0;
		read.open("Players.txt", ios::in);
		while (getline(read, data))
		{
			playerNode* tempPlayer = new playerNode();
			stringstream ss(data);
			string temp;
			getline(ss, tempPlayer->playerId, ',');
			getline(ss, tempPlayer->name, ',');
			getline(ss, tempPlayer->phone, ',');
			getline(ss, tempPlayer->email, ',');
			getline(ss, tempPlayer->password, ',');
			while (getline(ss, temp , ','))
			{
				gamesPlayed* tempGamesPlayed = new gamesPlayed();
				tempGamesPlayed->gameId = temp;
				string tempHours;
				getline(ss, tempHours, ',');
				tempGamesPlayed->hoursPlayed = stof(tempHours);
				string tempAchievement;
				getline(ss, tempAchievement, ',');
				tempGamesPlayed->achievementUnlocked = stof(tempAchievement);
				tempPlayer->insertNode(tempGamesPlayed);
				//tempGamesPlayed->print(tempGamesPlayed);
			}
			root = insertNode(root, tempPlayer);
		}
		read.close();

	}
	playerNode* insertNode(playerNode* rootCopy, playerNode* temp)
	{

		if (rootCopy == NULL)
		{
			return temp;
		}
		else
		{
			if (rootCopy->playerId < temp->playerId)
			{
				rootCopy->right = insertNode(rootCopy->right, temp);
			}
			else if (rootCopy->playerId > temp->playerId)
			{
				rootCopy->left = insertNode(rootCopy->left, temp);
			}
		}
		return rootCopy;
	}
	void preOrder(playerNode* temp)
	{
		if (temp != NULL)

		{

			temp->print();
			preOrder(temp->getLeft());
			preOrder(temp->getRight());

		}

	}
	playerNode*  getRoot() const
	{
		return root;
	}

};
int main()
{
	/*gameTree t1;
	t1.insert();
	cout << endl << endl << endl;
	t1.preorder(t1.getRoot());*/
	playerTree p1;
	p1.insert();
	p1.preOrder(p1.getRoot());
}