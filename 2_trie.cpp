#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

class Trie{
public:
	void add(const string& str);
	int search(const string& pattern);
private:
	//defination of node
	struct node{
		//data members
		map<char, node*> key;
		int count;
		//member functions
		node() :count(0)
		{}
		void add(char key, node* lead_to)
		{
			this->key.insert(make_pair(key, lead_to));
		}
		void add_count(){ ++count; }
		bool has_key(char key)
		{
			return this->key.find(key) == this->key.end() ? false : true;
		}
		node* get_node(char key)
		{
			return this->key[key];
		}
		int get_count()
		{
			return count;
		}
	};
	//private data menber
	static node root;
};

Trie::node Trie::root;

void Trie::add(const string& str)
{
	typedef Trie::node node_t;
	node_t *root = &(Trie::root);
	for (size_t key = 0; key != str.length(); key++)
	{	
		if (!root->has_key(str.at(key)))
			root->add(str.at(key), new node());
		root = root->get_node(str.at(key));
		root->add_count();
	}
}

int Trie::search(const string& pattern)
{
	typedef Trie::node node_t;
	node_t *root = &(Trie::root);
	for (size_t key = 0; key != pattern.length(); key++)
	{
		char ch = pattern.at(key);
		if (root->has_key(ch))
		{
			root = root->get_node(ch);
		}
		else
		{
			return 0;
		}
	}
	return root->get_count();
}


int main()
{
	int nu = 0;
	//cout << "input how many string you want to add to the trie:" << endl;
	cin >> nu;
	string word;
	Trie trie;
	while (nu-- && cin >> word)
	{
		trie.add(word);
	}
	cin >> nu;
	while (nu--)
	{
		cin >> word;
		cout << trie.search(word) << endl;;
	}
	return 0;
}