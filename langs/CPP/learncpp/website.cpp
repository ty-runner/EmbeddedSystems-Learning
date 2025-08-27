/*You are running a website, and you are trying to calculate your advertising revenue. Write a program that allows you to enter 3 pieces of data:

How many ads were watched.
What percentage of users clicked on an ad.
The average earnings per clicked ad.
Store those 3 values in a struct. Pass that struct to another function that prints each of the values. 
The print function should also print how much you made for that day (multiply the 3 fields together).*/
#include <iostream>
struct web_data{
    int num_ads_watched = 0;
    double ad_percent_clicked = 0.0;
    double avg_earning_per_clicked = 0.0;
};

void print_web_data(const web_data& data){
    std::cout << "NUM ADS WATCHED: " << data.num_ads_watched << "\n";
    std::cout << "PERCENT OF ADS CLICKED: " << data.ad_percent_clicked << "\n";
    std::cout << "AVG EARNING PER AD " << data.avg_earning_per_clicked << "\n";
    double res = data.num_ads_watched * data.avg_earning_per_clicked * data.ad_percent_clicked;
    std::cout << "TOTAL REVENUE: " << res << "\n";
}

int main(){
    web_data website = {100, 0.90, 1};
    print_web_data(website);
    return 0;
}
