#ifndef PMERGE_HPP
 #define PMERGE_HPP

 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <iterator>
 #include <list>
 #include <sys/time.h>

 class PMergeMe
 {
	private:
		std::list<int> _list;
		std::vector<int> _vec;

	public:
		PMergeMe();
		PMergeMe(const PMergeMe& other);
		PMergeMe& operator=(const PMergeMe& other);
		~PMergeMe();

		int jacobsthal(int count);

		void checkSorted();

		void insertionSortVec(std::vector<std::pair<int, int> > &vec);
		void insertVec(std::vector<int> vec);
		void sortVec();

		void insertionSortList(std::list<std::pair<int, int> > &lst);
		void insertList(std::vector<int> vec);
		void sortList();

		void printVec();
		void printList();

 };

#endif