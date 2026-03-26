#include "PMergeMe.hpp"

PMergeMe::PMergeMe(){};

PMergeMe::PMergeMe(const PMergeMe& other)
{
	*this = other;
}

PMergeMe& PMergeMe::operator=(const PMergeMe& other)
{
	(void)other;
	return (*this);
}

PMergeMe::~PMergeMe() {};

void PMergeMe::checkSorted()
{
	bool isVecSorted = true;
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
	{
		std::vector<int>::iterator next = it;
		++next;
		if (next != _vec.end() && *it > *next)
		{
			isVecSorted = false;
			break;
		}
	}

	bool isListSorted = true;
	for(std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		std::list<int>::iterator next = it;
		++next;
		if (next != _list.end() && *it > *next)
		{
			isListSorted = false;
			break;
		}
	}
	std::cout << "Vector sorted : " << (isVecSorted ? "True" : "False") << std::endl;
	std::cout << "List sorted : " << (isListSorted ? "True" : "False") << std::endl;
}

void PMergeMe::printVec()
{
	for (std::vector<int>::iterator it = _vec.begin(); it < _vec.end(); it++)
	{
		std::cout << " " << *it;
	}
}

void PMergeMe::printList()
{
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		std::cout << " " << *it;
	}
}

void PMergeMe::insertVec(std::vector<int>vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		_vec.push_back(*it);
	}
}

void PMergeMe::insertionSortVec(std::vector<std::pair<int, int> > &vec)
{
	if (vec.size() < 2)
		return ;
	
	std::vector<std::pair<int, int> >::iterator itMiddle = vec.begin();
	for(int i = 0; i < (int)vec.size()/ 2; i++)
	{
		itMiddle++;
	}
	std::vector<std::pair<int, int> > front(vec.begin(), itMiddle);
	std::vector<std::pair<int, int> > back(itMiddle,vec.end());

	insertionSortVec(front);
	insertionSortVec(back);

	vec.clear();

	std::vector<std::pair<int, int> >::iterator itFront = front.begin();
	std::vector<std::pair<int, int> >::iterator itBack = back.begin();

	while (itFront != front.end() && itBack != back.end())
	{
		if ((*itFront).second < (*itBack).second)
		{
			vec.push_back(*itFront);
			itFront++;
		}
		else
		{
			vec.push_back(*itBack);
			itBack++;
		}
	}

	while (itFront != front.end())
	{
		vec.push_back(*itFront);
		itFront++;
	}
	while (itBack != back.end())
	{
		vec.push_back(*itBack);
		itBack++;
	}
}

int PMergeMe::jacobsthal(int count)
{
	if (count == 0)
		return (0);
	if (count == 1)
		return (1);
	return (jacobsthal(count - 1) + (2 * jacobsthal(count - 2)));
}

void PMergeMe::sortVec()
{
	std::vector<std::pair<int, int> > pair;
	std::pair<int, int> tmp;

	bool hasStraggler = false;
	int straggler;

	if (_vec.size() <= 1)
		return ;
	if (_vec.size() % 2 == 1)
	{
		hasStraggler = true;
		straggler = *(_vec.end() - 1);
		_vec.pop_back();
	}

	for (std::vector<int>::iterator it = _vec.begin(); it < _vec.end(); it +=2)
	{
		tmp = std::make_pair(*it, *(it + 1));
		if (tmp.first > tmp.second)
		{
			int swap = tmp.first;
			tmp.first = tmp.second;
			tmp.second = swap;
		}
		pair.push_back(tmp);
	}

	insertionSortVec(pair);

	_vec.clear();
	std::vector<int> append;
	for (std::vector<std::pair<int, int> >::iterator it = pair.begin(); it != pair.end(); it++)
	{
		_vec.push_back((*it).second);
		append.push_back((*it).first);
	}

	int count = 2;
	int jacob = 0;
	std::vector<int>::iterator itAppend = append.begin();
	std::vector<int>::iterator itTemp;

	while (true)
	{
		itTemp = append.begin();
		jacob = jacobsthal(count);
		if (jacob >= (int)append.size())
			break;
		std::advance(itTemp, jacob - 1);
		append.insert(itAppend, *itTemp);
		append.erase(itTemp + 1);
		++count;
		++itAppend;
	}

	for (std::vector<int>::iterator it = append.begin(); it != append.end(); ++it)
	{
		_vec.insert(std::lower_bound(_vec.begin(), _vec.end(), *it), *it);
	}

	if (hasStraggler == true)
		_vec.insert(std::lower_bound(_vec.begin(), _vec.end(), straggler), straggler);
}

void PMergeMe::insertList(std::vector<int> vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		_list.push_back(*it);
}

void PMergeMe::insertionSortList(std::list<std::pair<int, int> > &lst)
{
	if (lst.size() < 2)
		return ;
	std::list<std::pair<int, int> >::iterator itMiddle = lst.begin();
	for (int i = 0; i < (int)lst.size() / 2; i++)
		itMiddle++;
	std::list<std::pair<int, int> > front(lst.begin(), itMiddle);
	std::list<std::pair<int, int> > back(itMiddle, lst.end());

	insertionSortList(front);
	insertionSortList(back);

	lst.clear();

	std::list<std::pair<int, int> >::iterator itFront = front.begin();
	std::list<std::pair<int, int> >::iterator itBack = back.begin();

	while (itFront != front.end() && itBack != back.end())
	{
		if ((*itFront).second < (*itBack).second)
		{
			lst.push_back(*itFront);
			itFront++;
		}
		else
		{
			lst.push_back(*itBack);
			itBack++;
		}
	}

	while (itFront != front.end())
	{
		lst.push_back(*itFront);
		itFront++;
	}
	while (itBack != back.end())
	{
		lst.push_back(*itBack);
		itBack++;
	}
}

void PMergeMe::sortList()
{
	std::list<std::pair<int, int> > pair;
	std::pair<int, int> tmp;

	bool hasStraggler = false;
	int straggler;

	if (_list.size() <= 1)
		return;
	if (_list.size() % 2 == 1)
	{
		hasStraggler = true;
		straggler = *(--_list.end());
		_list.pop_back();
	}

	std::list<int>::iterator itTmp;
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); std::advance(it, 2))
	{
		itTmp = it;
		std::advance(itTmp, 1);
		tmp = std::make_pair(*it, *itTmp);
		if (tmp.first > tmp.second)
		{
			int swap = tmp.first;
			tmp.first = tmp.second;
			tmp.second = swap;
		}
		pair.push_back(tmp);
	}

	insertionSortList(pair);

	_list.clear();
	std::list<int> append;
	for(std::list<std::pair<int, int> >::iterator it = pair.begin(); it != pair.end(); it++)
	{
		_list.push_back((*it).second);
		append.push_back((*it).first);
	}

	_list.insert(_list.begin(), append.front());
	append.erase(append.begin());

	int count = 2;
	int jacob = 0;
	std::list<int>::iterator itAppend = append.begin();
	std::list<int>::iterator itTemp;
	std::list<int>::iterator itErase;

	while (true)
	{
		itTemp = append.begin();
		jacob = jacobsthal(count);
		if (jacob >= (int)append.size())
			break;
		std::advance(itTemp, jacob - 1);
		append.insert(itAppend, *itTemp);
		itErase = itTemp;
		std::advance(itErase, 1);
		append.erase(itErase);
		++count;
		++itAppend;
	}

	for (std::list<int>::iterator it = append.begin(); it != append.end(); ++it)
	{
		_list.insert(std::lower_bound(_list.begin(), _list.end(), *it), *it);
	}

	if (hasStraggler == true)
		_list.insert(std::lower_bound(_list.begin(), _list.end(), straggler), straggler);
}