// container_1000.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "additional_func.h"
#include "my_shared_ptr.h"
#include "my_vector.h"
#include "shape.h"


int main()
{
	size_t choice = 0;
	std::cout << "Choose the mod :\n	1 - Test mod\n	2 - Work mod" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		system("CLS");
		vector<shared_ptr<Shape>> test_array = test_create(10);
		vector<neighbours> test_pairs = neigh_search(test_array);
		vector<size_t> expected_vec;
		for (size_t i = 0; i < 10; i++)
			expected_vec.push_back(i);
		assert(ident_vect(expected_vec, test_pairs) == true);
		expected_vec.resize(0);
		for (size_t i = 0; i < 10; i++)
			expected_vec.push_back(10);
		assert(ident_vect(expected_vec, test_pairs) == false);
		expected_vec.resize(0);
		for (int i = 0; i< test_pairs.size(); i++)
		{
		std::cout << "First: " << test_pairs[i].first << " Second: " << test_pairs[i].second << std::endl;
		}
		std::cout << "Amount of elments : " << test_pairs.size() << std::endl;
		system("pause");
		system("CLS");
		vector<dual_un> test_sort_arr = dual_diap_union(0, 5, 5, 10, test_array);
		for (size_t i = 0; i < 10; i+=2)
			expected_vec.push_back(i);
		for (size_t i = 1; i < 10; i += 2)
			expected_vec.push_back(i);
		assert(ident_vect(expected_vec, test_sort_arr) == true);
		expected_vec.resize(0);
		for (size_t i = 0; i < 10; i++)
			expected_vec.push_back(10);
		assert(ident_vect(expected_vec, test_sort_arr) == false);
		expected_vec.resize(0);
		for (int i = 0; i< test_sort_arr.size(); i++)
		{
			std::cout << "Number: " << test_sort_arr[i].num << " Value: " << test_sort_arr[i].val << std::endl;
		}
		std::cout << "Amount of elments : " << test_sort_arr.size() << std::endl;
	}
	break;
	case 2:
	{
		system("CLS");
		vector<shared_ptr<Shape>> array = create_arr(1000);
		vector<neighbours> pairs = neigh_search(array);
		for (int i = 0; i< pairs.size(); i++)
		{
			std::cout << "First: " << pairs[i].first << " Second: " << pairs[i].second << std::endl;
		}
		std::cout << "Amount of elments : " << pairs.size() << std::endl;
		system("pause");
		system("CLS");
		vector<dual_un> sort_arr = dual_diap_union(rand() % 20, rand() % 20 + 40, rand() % 100 + 540, rand() % 50 + 700, array);
		for (int i = 0; i< sort_arr.size(); i++)
		{
			std::cout << "Number: " << sort_arr[i].num << " Value: " << sort_arr[i].val << std::endl;
		}
		std::cout << "Amount of elments : " << sort_arr.size() << std::endl;;
	}
	break;
	default:
		std::cout << "Chose an option" << std::endl;
	}
	system("pause");
    return 0;
}

