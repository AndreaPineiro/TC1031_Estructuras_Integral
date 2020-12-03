// =================================================================
//
// File: trie.h
// Author: Andrea Pineiro Cavazos
// Description: Esta clase contiene la implementación de un 
// Trie (Eficiente para búsqueda de información )
// =================================================================

#ifndef TRIE_H_
#define TRIE_H_

#include <string>
#include <iostream>
using namespace std;


// =================================================================
// Definition of the Trie class
// =================================================================
class Trie {
	private:
		bool endOfWord;
		Trie *children[26];

	public:
		Trie();
		void insert(string);
		bool search (string);
		void display(Trie *root, char str[], int level);
};


// =================================================================
// Constructor. Initializes the Node as not the end of a word, and 
// sets its children to NULL pointers.
// Complexity O(1)
// =================================================================
Trie::Trie(){
	this -> endOfWord = false;
	for (int i = 0; i < 26; i++){
		this -> children[i] = NULL;
	}
}

// =================================================================
// Adds a string into the tree. It sets each char to be a node and 
// you can get  the word from the root to the node were endOfWord
// is true. The function does not return anything and it has to 
// receive a valid string.
// Complexity O(n) n-> length of the string. 
// =================================================================
void Trie::insert(string word){
	// We set the start as the root 
	Trie* current = this;
	// We add each character of the string in the proper place 
	for (int i = 0; i < word.length(); i++){
		int index = tolower(word[i]) - 'a';
		// If the node containing the character doesn't exist,
		// we create a new node to store the character there.
		if (!current->children[index]){
			current ->  children[index] = new Trie();
		}
		// Now our current node is going to be the child with the character
		current = current -> children[index];
	}
	// Once we've place every character, on the final one
	// we set it to be the end of a word.
	current -> endOfWord = true;
	cout << " ";
}


// =================================================================
// Searchs for a string in the tree. It returns true if the word
// is in the tree and receives a valid string.
// It moves in the tree through the characters of the string and if it
// gets to the end of the word, returns true.
// Complexity O(n) n-> length of the string. 
// =================================================================
bool Trie::search(string word){
	// We set the start as the root
	//cout << word;
	Trie* current = this;
	// We move in the tree by moving to the node with the next 
	// character of the string
	for (int i = 0; i < word.length(); i++){
		int index = tolower(word[i]) - 'a';
		// If it's null it means there is no conection
		// between the las char of the word and the current one
		// so the word is not in the tree.
		if (!current -> children[index]){
			return false;
		}
		// It moves to the next node containing the 
		// character
		current = current -> children[index];
	}
	// Returns true if we have got to the last character and this
	// is the end of a word
	cout << " ";
	return (current -> endOfWord);

}

#endif