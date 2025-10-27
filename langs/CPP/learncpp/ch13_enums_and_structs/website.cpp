#include <iostream>

struct Data{
	int num_ads_watched {};
	double percentage_clicked {};
	double avg_earnings_per_ad {};
};


int main(){
	Data view_data {};
	std::cout << "Enter ads watched: ";
	std::cin >> view_data.num_ads_watched;
	std::cout << "\n";

	std::cout << "Enter percentage clicked: ";
	std::cin >> view_data.percentage_clicked;
	std::cout << "\n";

	std::cout << "Avg earnings: ";
	std::cin >> view_data.avg_earnings_per_ad;
	std::cout << "\n";

	std::cout << "Total earnings: ";
	std::cout << view_data.num_ads_watched * (view_data.percentage_clicked / 100) * view_data.avg_earnings_per_ad;

	return 0;
}
