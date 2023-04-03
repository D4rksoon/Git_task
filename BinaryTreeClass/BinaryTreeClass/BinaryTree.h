#pragma once
class BinaryTree
{
	class Node // private
	{
	public:
		Node(int key = 0, Node* leftChild = nullptr, Node* rightChild = nullptr)
		{
			m_key = key;
			m_leftChild = leftChild;
			m_rightChild = rightChild;
		}
		~Node() = default;
		int key() const
		{
			return m_key;
		}
		void setKey(const int key)
		{
			m_key = key;
		}
		Node* leftChild() const
		{
			return m_leftChild;
		}
		void setLeftChild(Node* newChild)
		{
			m_leftChild = newChild;
		}
		Node* rightChild() const
		{
			return m_rightChild;
		}
		void setLeftChild(Node* newChild)
		{
			m_rightChild = newChild;
		}


	private:
		friend class BinaryTree;
		int m_key = 0;
		Node* m_leftChild;
		Node* m_rightChild;
	};

public:
	BinaryTree();
	~BinaryTree();


private:
	Node* m_root = nullptr;

};

