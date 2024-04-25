#include <algorithm>
#include <iterator>
#include <list>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

#include "gtest/gtest.h"

TEST(IteratorTest, RandomAccess)
{
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto it1 = arr.begin();
  it1 += 5;
  ++it1;

  int dst1 = it1 - arr.begin();
  EXPECT_EQ(dst1, 6);
}

TEST(IteratorTest, Bidirectional)
{
  std::list<int> lst = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto it1 = lst.begin();
  std::advance(it1, 5);
  ++it1;

  int dst1 = std::distance(lst.begin(), it1);
  EXPECT_EQ(dst1, 6);
}

TEST(RangeTest, Copy)
{
  std::vector<int> data{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> out(7, 0);

  std::copy(data.begin(), data.end(), // input range
            out.begin()               // output range, end iterator is implied
  );
  for (std::size_t i = 0; i < data.size(); i++)
  {
    ASSERT_EQ(out[i], data[i]);
  }
}

TEST(RangeTest, SubrangeIsSorted)
{
  std::vector<int> data{1, 4, 5, 7, 9, 2, 3};
  std::vector<int> expectedSorted{1, 4, 5, 7, 9};

  // is_sorted_until returns the first out of order element.
  auto result = std::is_sorted_until(data.begin(), data.end());
  EXPECT_EQ(result, data.begin() + 5);

  // [begin, result) is the maximal sorted sub-range
  std::vector<int> resultSortedIterated;
  for (auto it = data.begin(); it != result; it++)
  {
    // Iterate over all elements in the sorted sub-range.
    // {1, 4, 5, 7, 9}
    resultSortedIterated.push_back(*it);
  }
  for (std::size_t i = 0; i < expectedSorted.size(); i++)
  {
    EXPECT_EQ(resultSortedIterated[i], expectedSorted[i]);
  }

  std::vector<int> resultSortedSubrange;
  for (auto v : std::ranges::subrange(data.begin(), result))
  {
    // Same, but using a range-based for loop.
    resultSortedSubrange.push_back(v);
  }
  for (std::size_t i = 0; i < expectedSorted.size(); i++)
  {
    EXPECT_EQ(resultSortedSubrange[i], expectedSorted[i]);
  }
}

TEST(RangeTest, SubrangeFromLowerBound)
{
  std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto lb = std::lower_bound(data.begin(), data.end(), 4);

  auto rangeLTBound = std::ranges::subrange(data.begin(), lb);
  EXPECT_EQ(rangeLTBound.size(), 3);
  EXPECT_EQ(rangeLTBound.front(), 1);
  EXPECT_EQ(rangeLTBound.back(), 3);

  auto rangeGTEBound = std::ranges::subrange(lb, data.end());
  EXPECT_EQ(rangeGTEBound.size(), 6);
  EXPECT_EQ(rangeGTEBound.front(), 4);
  EXPECT_EQ(rangeGTEBound.back(), 9);
}

TEST(RangeTest, StringFromIterators)
{
  std::string str("Hello World!");

  auto it = std::find(str.begin(), str.end(), ' ');
  EXPECT_EQ(std::string_view(str.begin(), it), "Hello");
}