#include "PMergeMe.hpp"

bool isNumber(std::string arv)
{
	if (arv.find_first_not_of("0123456789") == std::string::npos)
		return (true);
	else
		return (false);
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Error: please provide numbers" << std::endl;
		exit(1);
	}
	if (ac == 2)
	{
		std::cout << "Error: only 1 number" << std::endl;
		exit (1);
	}

	std::string argv;
	std::vector<int> ori;

	for (int i = 1; i < ac; i++)
	{
		argv = av[i];
		if (isNumber(argv) == true)
			ori.push_back(std::atoi(argv.c_str()));
		else
		{
			std::cout << "Error, invalid arguments" << std::endl;
			exit(1);
		}
	}

	PMergeMe merge;
	merge.insertVec(ori);
	merge.insertList(ori);

	std::cout << "before: ";
	merge.printVec();
	std::cout << std::endl;

	struct timeval tv;
	gettimeofday(&tv, NULL);
	unsigned long startSec = tv.tv_sec;
	unsigned long startMicro = tv.tv_usec;

	merge.sortVec();
	gettimeofday(&tv,NULL);
	float endSec = tv.tv_sec;
	float endMicro = tv.tv_usec;
	float time = float(endSec - startSec) + (float)((endMicro = startMicro) / 10000);
	std::cout << "after: ";
	merge.printVec();
	std::cout << std::endl;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << time << " µs " << std::endl;

	gettimeofday(&tv, NULL);
	startSec = tv.tv_sec;
	startMicro = tv.tv_usec;

	merge.sortList();

	gettimeofday(&tv, NULL);
	endSec = tv.tv_sec;
	endMicro = tv.tv_usec;
	time = float(endSec - startSec) + (float)((endMicro - startMicro) / 10000);
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::list : " << time << " µs" << std::endl;

	merge.checkSorted();
}