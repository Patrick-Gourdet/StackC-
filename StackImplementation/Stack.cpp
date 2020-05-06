#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>


class solution2
{
public:
	solution2()
	{
	};
	~solution2();

	int removeDuplicates(std::vector<int>& nums) const
	{
		int size = nums.size();
		if (nums.empty()) return NULL;
		if (size == 0) return 1;
		int checker = 0;
		int c = 1;
		while (true)
		{
			if (c == size)break;
			if (nums[checker] == nums[c])
			{
				c++;
				continue;
			}
			nums[checker + 1] = nums[c];
			checker++;
		}
		return checker + 1;
	}
};

class solution1
{
public:
	solution1()
	{
	};
	~solution1();

	int removeDuplicates(std::vector<int>& nums) const
	{
		int max = std::numeric_limits<int>::max();
		if (nums.empty()) return NULL;
		if (nums.size() == 0) return 1;
		int checker = 0;
		for (auto i = 1; i < nums.size(); i++)
		{
			if (nums[i] == nums[i - 1])
				nums[i - 1] = max;
		}
		std::sort(nums.begin(), nums.end());
		auto t = std::find(nums.begin(), nums.end(), max);
		return std::distance(nums.begin(), t);
	}
};

int main()
{
	auto* s1 = new solution1();
	auto* s2 = new solution2();

	std::vector<int> v1 = {2, 2, 4, 6, 8, 9};
	std::vector<int> v2 = {2, 2, 4, 6, 8, 9};

	std::cout << s1->removeDuplicates(v1);
	std::cout << s2->removeDuplicates(v2);
}
