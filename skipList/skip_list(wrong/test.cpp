#include "skip_list.h"

#include <sys/time.h>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <set>

static int64_t current_ms();
int main(int argc, char *argv[])
{
	if (argc != 2)
		return 0;

	const int num = ::atoi(argv[1]);

	int64_t t1 = current_ms();	
	skip_list *sl = new skip_list;
	for (int i = 0; i < num; ++i)
		if (sl->insert(i) != 0)
			std::cout << "skip_list insert " << i << " failed." << std::endl;
	int64_t t2 = current_ms();
	std::cout << "skip_list insert used " << t2 - t1 << " ms" << std::endl;
	int64_t t3 = current_ms();
	for (int i = 0; i < num; ++i)
		if (!sl->find(i))
			std::cout << "skip_list not found " << i << std::endl;
	int64_t t4 = current_ms();
	std::cout << "skip_list find used " << t4 - t3 << " ms" << std::endl;
	delete sl;

	std::set<int> si;
	int64_t t5 = current_ms();
	for (int i = 0; i < num; ++i)
		si.insert(i);
	int64_t t6 = current_ms();
	std::cout << "rb_tree insert used " << t6 - t5 << " ms" << std::endl;
	int64_t t7 = current_ms();
	for (int i = 0; i < num; ++i)
		if (si.find(i) == si.end())
			std::cout << "rb_tree not found " << i << std::endl;
	int64_t t8 =current_ms();
	std::cout << "rb_tree find used " << t8 - t7 << " ms" << std::endl;
	return 0;
}

static int64_t current_ms()
{
	struct timeval tv;
	::gettimeofday(&tv, NULL);
	return int64_t(tv.tv_sec) * 1000 + tv.tv_usec / 1000;
}
