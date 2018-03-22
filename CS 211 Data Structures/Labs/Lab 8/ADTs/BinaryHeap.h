
#ifndef HEAP_H
#define HEAP_H

#include "Vector.h"
#include "Queue.h"
using namespace std;

template<typename T>
class BinaryHeap : Queue<T>
{
private:
	Vector<T> _items;

	void buildHeap()
	{
		for (int i = _items.getSize() / 2; i >= 0; i--)
		{
			adjustHeap(i);
		}
	}

	//Percolates the item specified at by index down into its proper location within a heap.  Used
	//for dequeue operations and array to heap conversions
	void adjustHeap(int index)
	{
		// grab a copy of whatever we're examining
		T item = _items[index];

		// first leaf node is size / 2
		int first_leaf_location = _items.getSize() / 2;



		// go until we can't go any further
		while (index < first_leaf_location)
		{
			// variables to help track children
			// this is potentially dangerous,
			// as the child indices may be out of bounds
			int left_child_index = ((2 * index) + 1);
			int right_child_index = ((2 * index) + 2);
			int most_important_index = left_child_index;

			// if we have a right child, we may need to swap
			// most_important_child
			if (index < (first_leaf_location - 1))
			{
				if (_items[right_child_index] < _items[left_child_index])
				{
					most_important_index = right_child_index;
				}
			}

			// is current item less important than most important child?
			if (item > _items[most_important_index])
			{
				_items[index] = _items[most_important_index];
				_items[most_important_index] = item;

				// update index
				index = most_important_index;
			}
			else
			{
				// no swap needed.
				break;
			}
		}
	}

public:
    BinaryHeap()
    {
    }

    BinaryHeap(const Vector<T> &unsorted)
    {
        for (int i = 0; i < unsorted.getSize(); i++)
        {
            _items.addElement(unsorted.getElementAt(i));
        }
        buildHeap();
    }

    bool isEmpty()
    {
        return _items.getSize() == 0;
    }

    virtual int getSize() const
    {
        return _items.getSize();
    }


	// enqueue item onto tree
    virtual void enqueue(const T &item)
    {
		// adding the item to the tree such that
		// completeness rule is maintained.
		_items.addElement(item);

		// however, we cannot guarantee that the completeness rule
		// is true, so we must adjust the heap until the newly placed
		// item is in the correct location

		// tracks location of new item in our tree
		int current_index = (_items.getSize() - 1);
		
		// tracks location of new item's parent
		int parent_index = ((current_index - 1) / 2); // floored by default

		// keep going until new item is in the correct location
		while (parent_index > -1 && _items[parent_index] > item)
		{
			//swap parent and child, update indices
			_items[current_index] = _items[parent_index];
			_items[parent_index] = item;
			current_index = parent_index;
			parent_index = ((current_index - 1) / 2);
		}
    }

    virtual T& getFirst()
    {
        return _items[0];
    }

    virtual const T& getFirst() const
    {
        return _items[0];
    }

    virtual T dequeue()
    {
        // we will return the top element to the User.
		T first_item = _items[0];

		int last_position = (_items.getSize() - 1);
		_items[0] = _items[last_position];
		_items.removeElementAt(last_position);

		if (_items.getSize() > 1)
		{
			adjustHeap(0);
		}
        return T{};
    }

};

#endif