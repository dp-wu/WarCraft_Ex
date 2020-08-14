/* preparation */
#include <iostream>
#include <iomanip>
using namespace std;

const int WARRIOR_TYPES = 5; // number of types of different warriors
const string RED_ORDER[] = { "iceman", "lion", "wolf", "ninja", "dragon" };
const string BLUE_ORDER[] = { "lion", "dragon", "ninja", "iceman", "wolf" };

struct Warrior {
	string name;
	int strength;
	int count;
};

class Game {
public:
	static int time;
	bool game_end;

	Game() { game_end = false; } // game not end when starts
};

class Base {
public:
	int m; // total amount of shengmingyuan for making warriors for each team
	int id; // id of warriors of each team
	int current_warrior_index;
	bool terminate_game; // end the game if m is not enough to create any warriors
	Warrior warriors[WARRIOR_TYPES];
	Warrior w; // current warrior

	Base(const string team[WARRIOR_TYPES], int hp[][WARRIOR_TYPES], int M) {
		for (int i = 0; i < WARRIOR_TYPES; ++i) {
			warriors[i].name = team[i]; // initiate team member names
			warriors[i].count = 0; // initiate team member id, starting from #1

			for (int j = 0; j < WARRIOR_TYPES; ++j) {
				if (team[i][0] == hp[0][j]) warriors[i].strength = hp[1][j];
			} // initiate team member starting hp
		}

		m = M;
		id = 0;
		current_warrior_index = 0;
		terminate_game = false;
	} // constructor

	void create_warrior() {
		for (int k = current_warrior_index; k < current_warrior_index + WARRIOR_TYPES; ++k) {
			int i = k % WARRIOR_TYPES;

			if (m >= warriors[i].strength) {
				// if there are enough m to create a warrior, create one
				++warriors[i].count;
				m -= warriors[i].strength;
				++id;

				w = { warriors[i].name, warriors[i].strength, warriors[i].count };
				current_warrior_index = i + 1;
				break;
			}
			else if (k == current_warrior_index + WARRIOR_TYPES - 1) {
				// if m is not enough to create any warrior, terminate the game
				terminate_game = true;
				break;
			}
		}
	} // create warrior according to the given order
};

int Game::time = 0;

int main() {
	int n_cases, case_counter = 1;
	cin >> n_cases; cin.ignore(1000, 10);

	do {
		// get each team's initial strength, 1<=M<=10000
		int M = 0;
		cin >> M; cin.ignore(1000, 10);
		// get each warrior's initial HP, 0<HP<=10000
		int init_hp[2][WARRIOR_TYPES] = { {'d', 'n', 'i', 'l', 'w'}, {0, 0, 0, 0, 0} };
		for (int i = 0; i < WARRIOR_TYPES; ++i) cin >> init_hp[1][i];

		cout << "Case:" << case_counter << endl;

		// initiate the game
		Game game;
		// initialize the two teams
		Base r(RED_ORDER, init_hp, M);
		Base b(BLUE_ORDER, init_hp, M);

		// start game
		do {
			if (r.terminate_game && b.terminate_game) game.game_end = true;
			else {
				if (!r.terminate_game && !b.terminate_game) {
					cout << setw(3) << setfill('0') << game.time;
					r.create_warrior();
					if (r.terminate_game) cout << " red headquarter stops making warriors" << endl;
					else {
						cout << " red " << r.w.name << " " << r.id << " born with strength " << r.w.strength << ",";
						cout << r.w.count << " " << r.w.name << " in red headquarter" << endl;
					}

					cout << setw(3) << setfill('0') << game.time;
					b.create_warrior();
					if (b.terminate_game) cout << " blue headquarter stops making warriors" << endl;
					else {
						cout << " blue " << b.w.name << " " << b.id << " born with strength " << b.w.strength << ",";
						cout << b.w.count << " " << b.w.name << " in blue headquarter" << endl;
					}
				}
				else if (!r.terminate_game && b.terminate_game) {
					cout << setw(3) << setfill('0') << game.time;
					r.create_warrior();
					if (r.terminate_game) cout << " red headquarter stops making warriors" << endl;
					else {
						cout << " red " << r.w.name << " " << r.id << " born with strength " << r.w.strength << ",";
						cout << r.w.count << " " << r.w.name << " in red headquarter" << endl;
					}
				}
				else if (r.terminate_game && !b.terminate_game) {
					cout << setw(3) << setfill('0') << game.time;
					b.create_warrior();
					if (b.terminate_game) cout << " blue headquarter stops making warriors" << endl;
					else {
						cout << " blue " << b.w.name << " " << b.id << " born with strength " << b.w.strength << ",";
						cout << b.w.count << " " << b.w.name << " in red headquarter" << endl;
					}
				}
			}
			++game.time;
		} while (!game.game_end);

		++case_counter;
		game.time = 0;
	} while (case_counter <= n_cases);

	return 0;
}
