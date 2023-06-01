#include "HuffmanTree.h"


void HuffmanTree::build(const std::string& text)
{
	int n = text.length();
	std::list<Node*> nodes;
	for (int i = 0; i < n; i++) {
		nodes[i]->symbols() = text[i];
	}



	/*std::sort(nodes.begin(), nodes.end(), [](Node* first, Node* second) {
		return first->frequency() < second->frequency();
		});*/
}

void HuffmanTree::Table(const std::string& text, int Tab[256])
{
	int n = text.length();
	for (int i = 0; i < n; i++) {
		Tab[text[i]]++;
	}
}

HuffmanTree::Node::Node(std::string symbols)
{
	m_symbols = symbols;
	
}
