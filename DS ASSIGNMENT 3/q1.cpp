#include <iostream>
#include <string>
#include<fstream>
#include<ctime>
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
			//cout << data << endl;
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
	void search1(string gameID)
	{
		
		if (search2(gameID, root) == NULL)
		{
			cout << "Game with ID " << gameID << " not found.";
		}
		
	}
	gameNode* search2(string gameID , gameNode* temp)
	{
		if (temp == NULL)
		{
			return NULL;
		}
		if (gameID == temp->gameId)
		{
			temp->print();
			return temp;
		}
		else if (gameID > temp->gameId)
		{
			return search2 (gameID , temp->right);
		}
		else
		{
			return search2 (gameID ,temp->left);
		}
	}
	void showLayerNum(string gameID)
	{
		int height = 1;
		showLayerNum1(gameID, root, height);
		if (height > 0)
		{
			cout << "The depth of Node: " << height;
		}
		else
		{
			cout << "Node With ID " << gameID << " not found." << endl;
		}
	}

	gameNode* showLayerNum1(string gameID , gameNode* temp , int& height)
	{
		if (temp == NULL)
		{
			height = 0;
			return NULL;
		}
		if (gameID == temp->gameId)
		{
			return temp;
		}
		else if (gameID > temp->gameId)
		{
			
			return showLayerNum1(gameID, temp->right,height );
		}
		else
		{
			height += 1;
			return showLayerNum1(gameID, temp->left, height);
		}
	}
	
};
class gamesPlayed
{
public:
	string gameId;
	float hoursPlayed;
	int achievementUnlocked;
	gamesPlayed* left  , *right;
	gamesPlayed()
	{
		left = right = NULL;
		gameId = "";
		hoursPlayed = 0;
		achievementUnlocked = 0.0;
	}
	void preOrder(gamesPlayed* temp)

	{

		if (temp != NULL)

		{

			cout << "\tGame ID: " << temp->gameId << ' , ' << " Hours Played: " << temp->hoursPlayed << ' , ' << " Achievement Unlocked: " << temp->achievementUnlocked << endl;
			preOrder(temp->getLeft());
			preOrder(temp->getRight());

		}
	}
	gamesPlayed* getLeft()
	{
		return left;
	}
	gamesPlayed* getRight()
	{
		return right;
	}
};
class playerNode
{
public:
	string playerId, name, phone, email, password;
	gamesPlayed *played;
	playerNode* left, * right;
	playerNode()
	{
		played = NULL;
		playerId = name = phone = email = password = "";
		left = right = NULL;
	}


	gamesPlayed* insertNode(gamesPlayed* rootCopy, gamesPlayed* temp)
	{

		if (rootCopy == NULL)
		{
			return temp;
		}
		else
		{
			if (rootCopy->gameId < temp->gameId)
			{
				rootCopy->right = insertNode(rootCopy->right, temp);
			}
			else if (rootCopy->gameId > temp->gameId)
			{
				rootCopy->left = insertNode(rootCopy->left, temp);
			}
		}
		return rootCopy;
	}
	void print()
	{
		cout << " Player ID: " << playerId << " , " << " Name: " << name <<  " , "  << " Phone: " << phone << " , " << " Email: " << email << " , " << " Password: " << password << endl;
		played->preOrder(played);
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
		srand(time(0));
		string data;
		fstream read;
		int i = 0 , j =0;
		read.open("Players.txt", ios::in);
		while (getline(read, data))
		{
			if(!((rand() % 1000 + 1) < ((45 * 10) + 100)))
			{
				
				playerNode* tempPlayer = new playerNode();
				stringstream ss(data);
				string temp;
				getline(ss, tempPlayer->playerId, ',');
				getline(ss, tempPlayer->name, ',');
				getline(ss, tempPlayer->phone, ',');
				getline(ss, tempPlayer->email, ',');
				getline(ss, tempPlayer->password, ',');

				while (getline(ss, temp, ','))
				{
					gamesPlayed* tempGamesPlayed = new gamesPlayed();
					tempGamesPlayed->gameId = temp;
					string tempHours;
					getline(ss, tempHours, ',');
					tempGamesPlayed->hoursPlayed = stof(tempHours);
					string tempAchievement;
					getline(ss, tempAchievement, ',');
					tempGamesPlayed->achievementUnlocked = stof(tempAchievement);
					tempPlayer->played = tempPlayer->insertNode(tempPlayer->played , tempGamesPlayed);
				}
				
				root = insertNode(root, tempPlayer);
				i++;
			}
			
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


	void search1(string gameID)
	{

		if (search2(gameID, root) == NULL)
		{
			cout << "Game with ID " << gameID << " not found.";
		}

	}
	playerNode* search2(string gameID, playerNode* temp)
	{
		if (temp == NULL)
		{
			return NULL;
		}
		if (gameID == temp->playerId)
		{
			temp->print();
			return temp;
		}
		else if (gameID > temp->playerId)
		{
			return search2(gameID, temp->right);
		}
		else
		{
			return search2(gameID, temp->left);
		}
	}



	void showLayerNum(string gameID)
	{
		int height = 1;
		showLayerNum1(gameID, root, height);
		if (height > 0)
		{
			cout << "The depth of Node: " << height;
		}
		else
		{
			cout << "Node With ID " << gameID << " not found." << endl;
		}
	}

	playerNode* showLayerNum1(string gameID, playerNode* temp, int& height)
	{
		if (temp == NULL)
		{
			height = 0;
			return NULL;
		}
		if (gameID == temp->playerId)
		{
			return temp;
		}
		else if (gameID > temp->playerId)
		{
			height += 1;
			return showLayerNum1(gameID, temp->right, height);
		}
		else
		{
			height += 1;
			return showLayerNum1(gameID, temp->left, height);
		}
	}
};
int main()
{
	//gameTree t1;
	//t1.insert();
	//t1.preorder(t1.getRoot());
	//t1.search1("124");
	//t1.showLayerNum("7659216917");
	
	playerTree p1;
	p1.insert();
	//p1.preOrder(p1.getRoot());
	p1.showLayerNum("1590084481");
}