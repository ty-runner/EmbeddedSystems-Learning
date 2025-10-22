
#include <iostream>
#include <vector>
#include <random>
#include <string>
//we want to make a deck of cards, 52 cards, 4 suits, 1-13 value, and color
//we want to design a draw method to randomly draw a card and discard from the pool of available cards
//
std::random_device rd;
std::mt19937 gen(rd());
struct Card{
	int value;
	std::string suit;
	std::string color;
};
class deck_of_cards{
	public:
		std::vector<Card> deck{std::vector<Card> (52)};
		deck_of_cards(){
			//populate all 52 unique cards
			for(int i = 1; i <= 13; i++){
				deck[i-1] = {i, "clubs", "black"}; //0-12 
				deck[i+(13-1)] = Card{i, "spades", "black"}; //13-25
				deck[i+(2*13-1)] = Card{i, "hearts", "red"}; //26-38
				deck[i+(3*13-1)] = Card{i, "diamonds", "red"}; //39-51
			}
		}

		void print_deck(){
			for(auto card: deck)
				std::cout << card.value << card.suit << card.color << std::endl;
		}

		Card draw(){
    			std::uniform_int_distribution<std::size_t> distrib(0, deck.size() - 1);
    			std::size_t randomIndex = distrib(gen);
			Card res = deck[randomIndex];
			deck.erase(deck.begin() + randomIndex);
			if(deck.size() == 0)
				*this = deck_of_cards();
			return res;
		}
};



int main(){
	deck_of_cards Deck; //constructor should fire here
	//Deck.print_deck();
	
	for(int i = 0; i < 52; i++){
		Card card = Deck.draw();
		std::cout << card.value << card.suit << card.color << std::endl;
	}

	std::cout << "\n\n";
	Deck.print_deck();

	return 0;
}
