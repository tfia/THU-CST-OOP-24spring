#pragma once
#include <list>
#include <memory>

class MyList
{
private:
	bool is_slice;
	std::shared_ptr< std::list<int> > pt; // a pointer to the real container
	std::list<int>::iterator left, right; // the position of slice is [left, right). 'left' is included, 'right' is excluded.

	std::list<int>::iterator forward(int pos) const{
		// count from 'left', find the element at position 'pos'.
		auto now = left;
		while(pos--) now++;
		return now;
	}
	MyList(std::shared_ptr< std::list<int> > pt, std::list<int>::iterator left, std::list<int>::iterator right, bool is_slice)
	: pt(pt), left(left), right(right), is_slice(is_slice) {}

public:
	MyList(): pt(new std::list<int>()){
		left = pt->begin();
		right = pt->end();
		is_slice = 0;
		// Actually, left = right = pt->end(), because there is no element in the list.
	}

	void append(int i){
		right = pt->insert(right, i); //insert i just before 'right'. 'right' and 'left' will be still valid (because we use list, not vector).
		// DEBUG !! Why I can't insert i??
		right++;
		if(left == right) left--;
		// std::cout << "l: " << (left == pt->begin()) << ", r: " << (right == pt->end()) << ". ";
		// for(auto & it : *pt) std::cout << it << " ";
		// std::cout << std::endl;
	}

	std::list<int>::iterator operator[](int pos) const{
		return forward(pos); // access the element at the 'pos'
	}

	MyList operator()(int s, int e)
	{
		auto l = forward(s), r = forward(e);
		return MyList(pt, l, r, 1);
	}

	void output(std::ostream & out) const{
		out << "[";
		for(std::list<int>::iterator it = left; it != right; it++)
		{
			out << *it;
			auto t = it;
			t++;
			if(t != right) out << ",";
		}
		out << "]";
	}

	friend std::ostream & operator << (std::ostream & os, MyList x)
	{
		x.output(os);
		return os;
	}
};

std::ostream & operator << (std::ostream & os, std::list<int>::iterator x)
{
	os << *x;
	return os;
}

void operator += (std::list<int>::iterator it, int x)
{
	*it = *it + x;
}