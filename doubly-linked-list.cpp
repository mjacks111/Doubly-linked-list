#include <iostream>
#include <string>

using namespace std;

struct Element     // our node to holding pointers to traverse in a doubly linked list, and a float value piece of data
{
	float value;
	Element* next;
	Element* previous;
};

class dLinked_List
{
private:
	Element* m_pBegin;   // member variables to at a start of list, and end.
	Element* m_pEnd;

public:
	dLinked_List()     // constrctor for my class, setting our pointer to NULL
	{
		m_pBegin = NULL;
		m_pEnd = NULL;
	}

	~dLinked_List()     // our destructer which will call a clear function for later code reuse
	{
		clear();
	}

	Element* begin()  // a function to call the head of the list, the start
	{
		return m_pBegin;
	}

	void setBegin(Element* node) // ability to change our member variable since it is private
	{
		m_pBegin = node;
	}

	Element* end()  // function to call tail of list, the end
	{
		return m_pEnd;
	}

	void setEnd(Element* node) // abillity to change the ending member variable, as its private
	{
		m_pEnd = node;
	}

	void clear()  // a function to clear our linked list
	{
		Element *it = begin();
		while (it != NULL)     // want to traverse while nodes are not empty
		{
			Element *next = it->next;     // need to keep reference of next node
			delete it;                    // safe to delete now 
			it = next;                    // we move on to the next node which was refernced, and proceed
		}
		m_pBegin = NULL; // reseting our member variables
		m_pEnd = NULL;
	}

	bool isEmpty()  // checks if the list is empty
	{
		if (begin() == NULL)
		{
			return true;
		}
		return false;
	}

	int size()  // to see how many nodes we have in our list
	{
		Element* it = begin();
		int counter = 0;

		while (it != NULL)
		{
			counter++;
			it = it->next;
		}
		return counter;
	}

	Element* pushFront(float value) // pushing an element to the front of the list
	{
		if (isEmpty())
		{
			Element* node = new Element;
			node->value = value;
			node->previous = NULL;
			node->next = NULL;
			setBegin(node);
			setEnd(node);
			return node;
		}
		else
		{
			Element* original = begin();
			Element* newElement = new Element;

			newElement->value = value;
			newElement->next = begin();
			newElement->previous = NULL;
			original->previous = newElement;
			setBegin(newElement);
		}
	}

	Element* insert(Element* insertAfter, float value) //inserting where you would like fom a certain elemnt
	{
		if (isEmpty() == true)
		{
			return pushFront(value);
		}
		else
		{
			Element* nextt = insertAfter->next;
			Element* newElement = new Element{ value, insertAfter->next, insertAfter };
			insertAfter->next = newElement;
			nextt->previous = newElement;
		}
	}

	Element* pushBack(float value) //pushing to the end of the list.
	{
		if (isEmpty() == true)
		{
			return pushFront(value);
		}
		else
		{
			Element* endNode = m_pEnd;
			Element* newElement = new Element;
			endNode->next = newElement;
			newElement->previous = endNode;
			newElement->next = NULL;
			newElement->value = value;
			m_pEnd = newElement;
			return newElement;

		}
	}

	Element* Find(Element* it, float value) // finding an element, and returning the pointer of the element.
	{
		while (it != NULL)
		{
			if (it->value == value)
			{
				return it;
			}
			else
			{
				it = it->next;
			}
		}
		return NULL;
	}
};

		int main()  // maniupulation to see how it works.
		{
			dLinked_List d;
			d.pushFront(10);
			d.pushFront(20);
			d.pushBack(50);
			cout << "The size is:" << d.size() << endl;
			Element* it = d.begin();
			while (it != NULL)
			{
				cout << it->value << " -> ";
				it = it->next;
			}
			cout << "NULL";
			return 0;
		}
