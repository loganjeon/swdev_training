
#include <iostream>
#include <iomanip>
#include <array>

#if 1
int main()
{
	const unsigned int min_wt {100U};
	const unsigned int max_wt {250U};
	const unsigned int wt_step {10U};
	const size_t wt_count {1 + (max_wt - min_wt) / wt_step};

	std::array<unsigned int, wt_count> weight_lbs;
	std::array<unsigned int, ht_count> height_ins;

	const double lbs_per_kg {2.20462};
	const double ins_per_m {39.3701};

	for (size_t i {}, w {min_wt}; i < wt_count; w += wt_step, ++i) {
		weight_lbs.at(i) = w;
	}

	unsigned int h {min_ht};

	for(auto& height : height_ins) {
		height = h;
		h += ht_step;
	}

	for(auto h {min_ht} : height_ins) {
		h += ht_step;
	}

	std::cout << std::setw(7) << std::endl;
	for (const auto& w : weight_lbs) {
		std::cout << setw(5) << w << std::endl;
	}
	std::cout << std::endl;

	for (size_t i {1}; i < wt_count; ++i)
		std::cout << "--------" ;
	std::cout << std::endl;

	for (const auto& h : height_ins) {
		std::cout << std::fixed << std:;setprecision(1); 
	}

}
#else
int main()
{
	std::array<int, 10> arr_base {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int h {3};

	for(auto& i : arr_base) {
		i = h;
		h += 2;

		std::cout << i << std::endl;
	}

	for (auto j : arr_base) {
		std::cout << j << std::endl;
	}
}
#endif
