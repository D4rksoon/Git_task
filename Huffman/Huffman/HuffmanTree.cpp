#include<vector> 
#include<list> 
#include<algorithm> 
#include<iostream> 

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
// std::string encodedText - ������ ���� �������� (01 000 100) + ������� ��������� ������ (double)
double HuffmanTree::encode(Node* root, std::string text, std::string &encodedText)
{
	if (!root) {
		return -1;
	}
	double encodeSum = 0;
	for (int i = 0; i < text.size(); i++) {
		Node* tmp = root;
		while (!isLeaf(tmp)) {
			std::string nodeSymbols = tmp->left()->symbols();
			if (nodeSymbols.find(text[i]) <= nodeSymbols.size()) {
				tmp = tmp->left();
				encodedText += "0";
			}
			else {
				tmp = tmp->right();
				encodedText += "1";
			}
			encodeSum++;
		}
	}
	if (root->left() == nullptr and root->right() == nullptr) {
		for (int i = 0; i < text.size(); i++) {
			encodedText += "0";
			encodeSum += 1;
		}
	}
	double compressionRatio = (text.size()) * 8 / encodeSum;
	return compressionRatio;
}

double HuffmanTree::encode(std::string text, std::string& encodedText)
{
	if (m_root == nullptr) {
		build(text);
	}
	return encode(m_root, text, encodedText);
}

bool HuffmanTree::decode(const std::string encodedText, std::string& decodedText)
{
	return decode(m_root, encodedText, decodedText);
}

// �� encodedText (01 000 100) -> decodedText(a b c)
bool HuffmanTree::decode(Node* root, const std::string encodedText, std::string &decodedText)
{
	if (!root) {
		return false;
	}
	Node* tmp = root;
	for (int i = 0; i < encodedText.size(); i++) {
		if (encodedText[i] == '0' and tmp->left()) {
			tmp = tmp->left();			
		}
		else if (encodedText[i] == '1' and tmp->right()) {
			tmp = tmp->right();
		}

		if (isLeaf(tmp)) {
			decodedText += tmp->symbols();
			tmp = root;
		}
	}
	return true;
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
	codePrint(root->left(), code + "0");
	codePrint(root->right(), code + "1");


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

HuffmanTree::Node* HuffmanTree::root()
{
	return m_root;
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


