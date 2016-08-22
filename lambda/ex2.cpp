#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
	
	std::vector<int> V(10);

	std::iota(V.begin(), V.end(), 1);

	std::cout<<"Original data" <<std::endl;

	std::for_each(V.begin(), V.end(), [](auto i) {std::cout<<i<<" ";});
	std::cout<<std::endl;


	//sort the data
	std::sort(V.begin(), V.end(), [](auto i, auto j){return (i<j);});
	std::cout<<"Sorted data"<<std::endl;
	std::for_each(V.begin(),V.end(), [](auto i){std::cout<<i<<" ";});


	return 0;
}
