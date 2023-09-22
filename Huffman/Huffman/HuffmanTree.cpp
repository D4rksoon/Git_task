#include<vector>
#include<list>
#include<algorithm>
#include<iostream>
#include<map>

#include "HuffmanTree.h"

bool checkRepeatString(const std::string text, char symb) {
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == symb) {
			return false;
		}
	}
	return true;
}

bool checkRepeatInt(std::vector<int> mas, int val) {
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i] == val) {
			return false;
		}
	}
	return true;
}

void HuffmanTree::build(const std::string& text)
{
	std::list<Node*> nodes;
	createAndSortList(text, nodes);
	while (nodes.size() > 1) {
		std::cout << '\n';
		Node* subTreeRoot1 = nodes.front();
		nodes.pop_front();
		Node* subTreeRoot2 = nodes.front();
		nodes.pop_front();
		std::string value = subTreeRoot1->symbols() + subTreeRoot2->symbols();
		int freq = subTreeRoot1->frequency() + subTreeRoot2->frequency();

		Node* sumNode = new Node(value);
		sumNode->setFrequency(freq);
		sumNode->m_left = subTreeRoot1;
		sumNode->m_right = subTreeRoot2;
		//nodes.push_back(sumNode);

		//Error
		/*std::sort(nodes.begin(), nodes.end(),
			[](const Node* first, const Node* second) {
			return first->frequency() < second->frequency();
		});*/

		//Ok
		/*nodes.sort([](const Node* first, const Node* second) {
			return first->frequency() < second->frequency();
		});*/




		std::list<Node*>::iterator seeker = nodes.begin();
		while (seeker != nodes.end() && (*seeker)->m_frequency <= sumNode->frequency()) {
			seeker++;
		}

		nodes.insert(seeker, sumNode);
	}
	m_root = nodes.back();
}
// std::string encodeText - строка всех значений (01 000 100) + вернуть коэфицент сжатия (double)
void HuffmanTree::encode(Node* root, const std::string encodeText)
{
	if (!m_root) {
		return;
	}

	if (isLeaf(root)) {
		std::cout << root->symbols() << ' ';
		std::cout << encodeText << "  \n";
		return;
	}
	codePrint(root->m_left, encodeText + "0");
	codePrint(root->m_right, encodeText + "1");
	std::cout << "__________- " << encodeText;
}
// из encodedText (01 000 100) -> decodedText(a b c)
bool HuffmanTree::decode(const std::string& encodedText, std::string& decodedText) const
{
	std::string str = encodedText;
	return false;
}

void HuffmanTree::Table(const std::string& text, int* Tab)
{
	int n = text.length();
	for (int i = 0; i < n; i++) {
		Tab[text[i]]++;
	}
}

void HuffmanTree::createAndSortList(const std::string& text, std::list<Node*>& nodes)
{
	int Tab[256] = { 0 };
	Table(text, Tab);

	std::string withoutRepeat;
	for (int i = 0; i < text.size(); i++) {
		if (checkRepeatString(withoutRepeat, text[i])) {
			withoutRepeat.push_back(text[i]);
		}
	}
	int lenString = withoutRepeat.length();

	std::vector<int> masWithoutRepeat;
	for (int i = 0; i < lenString; i++) {
		if (checkRepeatInt(masWithoutRepeat, Tab[withoutRepeat[i]])) {
			masWithoutRepeat.push_back(Tab[withoutRepeat[i]]);
		}
	}
	std::sort(masWithoutRepeat.begin(), masWithoutRepeat.end());
	int lenMas = masWithoutRepeat.size();

	for (int i = 0; i < lenMas; i++) {
		for (int j = 0; j < lenString; j++) {
			if (Tab[withoutRepeat[j]] == masWithoutRepeat[i]) {
				std::string symbl;

				Node* tmp = new Node(std::string(1, withoutRepeat[j]));
				tmp->setFrequency(masWithoutRepeat[i]);
				nodes.push_back(tmp);

			}
		}
	}
}

void HuffmanTree::codePrint(Node* root, const std::string code)
{
	if (!m_root) {
		return;
	}
	if (isLeaf(root)) {
		std::cout << root->symbols() << ' ';
		std::cout << code << "  \n";
		return;
	}
	codePrint(root->m_left, code + "0");
	codePrint(root->m_right, code + "1");


}

bool HuffmanTree::isLeaf(Node* root)
{
	if (root == nullptr) {
		return false;
	}
	if (root->left() == nullptr and root->right() == nullptr) {
		return true;
	}
	return false;
}

void HuffmanTree::print(std::list<Node*>& nodes)
{
	std::for_each(nodes.begin(), nodes.end(), [](auto& x)
		{
			std::cout << x->symbols() << ' ';
			std::cout << x->frequency() << ' ';
		}
	);
}

void HuffmanTree::printNode(Node* node)
{
	std::cout << "Symbols: " << node->symbols();
	std::cout << "  Frequency: " << node->frequency();
	std::cout << '\n';
}


