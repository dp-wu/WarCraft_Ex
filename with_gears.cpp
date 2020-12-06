#include <iostream>
#include <iomanip>
using namespace std;


const int MAX_STRENGTH = 10000;
const int WARRIOR_TYPES = 5; // number of types of different warriors
const int WEAPON_TYPES = 3; // number if types of different weapons
const string RED_ORDER[] = { "iceman", "lion", "wolf", "ninja", "dragon" };
const string BLUE_ORDER[] = { "lion", "dragon", "ninja", "iceman", "wolf" };
const string WEAPON_ORDER[] = { "sword", "bomb", "arrow" };

struct Stats {
    char name;
    int strength;
};


class Warrior {
public:
    string team;
    string name;  // warrior name
    int strength;  // strength needed to create this warrior
    int HQ_strength; // strength left in HQ after creating this warrior
    int ind;  // the value of total_warrior in HQ
    int counter;
    const string *weapons; // weapon array

    Warrior(string tm, string n, int s, int h, int tw, int c):
        team(tm), name(n), strength(s), HQ_strength(h), ind(tw), counter(c) { weapons = WEAPON_ORDER; }

    virtual void print_feature() {}
    void print_common() {
        cout << " " << team << " " << name << " " << ind;
        cout << " born with strength " << strength << "," << counter;
        cout << " " << name << " in " << team << " headquarter" << endl;
    }
    virtual ~Warrior() {}
};

class Dragon: public Warrior {
public:
    string weapon;
    double morale;

    Dragon(string tm, string n, int s, int h, int tw, int c): Warrior(tm, n, s, h, tw, c) {
        weapon = weapons[ind%WEAPON_TYPES];
        morale = (double) HQ_strength / strength;
    }

    void set_value(string tm, string n, int s, int h, int tw){
        Warrior::team = tm;
        weapon = weapons[ind%WEAPON_TYPES];
        morale = (double) HQ_strength / strength;
    }
    virtual void print_feature() {
        print_common();
        cout << "It has a " << weapon << ",and it's morale is " << fixed << setprecision(2) << morale << endl;
    }
};

class Ninja: public Warrior {
public:
    string weapon[2];

    Ninja(string tm, string n, int s, int h, int tw, int c): Warrior(tm, n, s, h, tw, c) {
        weapon[0] = weapons[ind%WEAPON_TYPES];
        weapon[1] = weapons[(ind+1)%WEAPON_TYPES];
    }

    virtual void print_feature() {
        print_common();
        cout << "It has a " << weapon[0] << " and a " << weapon[1] << endl;
    }
};

class Wolf: public Warrior {
public:
    Wolf(string tm, string n, int s, int h, int tw, int c): Warrior(tm, n, s, h, tw, c) {}

    virtual void print_feature() {
        print_common();
    }
};

class Iceman: public Warrior {
public:
    string weapon;

    Iceman(string tm, string n, int s, int h, int tw, int c): Warrior(tm, n, s, h, tw, c) { weapon = weapons[ind%WEAPON_TYPES]; }

    virtual void print_feature() {
        print_common();
        cout << "It has a " << weapon << endl;
    }
};

class Lion: public Warrior {
public:
    int loyalty;

//    Lion() {}
    Lion(string tm, string n, int s, int h, int tw, int c): Warrior(tm, n, s, h, tw, c) { loyalty = HQ_strength; }

    virtual void print_feature() {
        print_common();
        cout << "It's loyalty is " << loyalty << endl;
    }
};

class Game {
public:
    static int time;
    bool end_game;

    Game() { end_game = true; }
};


class HQ {
public:
    string team;  // red or blue
    int total_warrior;  // total number of warriors in this HQ
    int total_strength;  // total strength left in the HQ

    const string *warrior_order;  // order to produce the warrior (name)
    int prod_order[WARRIOR_TYPES];  // order to produce the warrior (strength)
    int min_strength; // minimum strength needed for producing a warrior
    int p;  // index indicating which warrior we are producing

    Warrior *warrior;
    int counter[WARRIOR_TYPES];
    bool end_of_prod; // true if HQ strength is insufficient to produce any warrior

    HQ(int M, string t, int *arr): team(t), total_warrior(0), total_strength(M) {
        if (t == "red") warrior_order = RED_ORDER;
        else warrior_order = BLUE_ORDER;

        min_strength = MAX_STRENGTH;
        for (int i=0; i<WARRIOR_TYPES; ++i) {
            counter[i] = 0;
            prod_order[i] = arr[i];
            if (arr[i] < min_strength) min_strength = arr[i];
        }
        p = 0;
        end_of_prod = false;
        warrior = nullptr;
    }
    ~HQ() { if (warrior) delete warrior; }

    void create_warrior(int current_time) {
        if (total_strength < min_strength) { end_of_prod = true; }
        else {
            for (int i=0; i<WARRIOR_TYPES; ++i) {
                p %= WARRIOR_TYPES;
                if (total_strength >= prod_order[p]) {
                    total_strength -= prod_order[p];
                    ++total_warrior;
                    ++counter[p];
                    switch (warrior_order[p][0]) {
                        case 'd': {
                            warrior = new Dragon(team, warrior_order[p], prod_order[p], total_strength, total_warrior, counter[p]);
                            break;
                        }
                        case 'n': {
                            warrior = new Ninja(team, warrior_order[p], prod_order[p], total_strength, total_warrior, counter[p]);
                            break;
                        }
                        case 'w': {
                            warrior = new Wolf(team, warrior_order[p], prod_order[p], total_strength, total_warrior, counter[p]);
                            break;
                        }
                        case 'i': {
                            warrior = new Iceman(team, warrior_order[p], prod_order[p], total_strength, total_warrior, counter[p]);
                            break;
                        }
                        case 'l': {
                            warrior = new Lion(team, warrior_order[p], prod_order[p], total_strength, total_warrior, counter[p]);
                            break;
                        }
                        default: break;
                    }
                    ++p;
                    break;
                }
                ++p;
            }
        }
    }
};


int Game::time = 0;


int main() {
    // get input values
    int n_cases, case_counter = 1, M;
    cin >> n_cases; cin.ignore(1000, 10);

    do {
        // read in initial strength of HQs
        cin >> M; cin.ignore(1000, 10);

        // read in each warrior's strength needed for production
        Stats slist[WARRIOR_TYPES];
        slist[0].name = 'd';
        slist[1].name = 'n';
        slist[2].name = 'i';
        slist[3].name = 'l';
        slist[4].name = 'w';
        for (int i=0; i<WARRIOR_TYPES; ++i) cin >> slist[i].strength;

        // create production order
        int r_arr[WARRIOR_TYPES], b_arr[WARRIOR_TYPES];
        for (int i=0; i<WARRIOR_TYPES; ++i) {
            for (int j=0; j<WARRIOR_TYPES; ++j) {
                if (slist[i].name == RED_ORDER[j][0]) r_arr[j] = slist[i].strength;
                if (slist[i].name == BLUE_ORDER[j][0]) b_arr[j] = slist[i].strength;
            }
        }

        Game g; // start game;
        HQ r(M, "red", r_arr);
        HQ b(M, "blue", b_arr);


        cout << "Case:" << case_counter << endl;
        for (g.time=0 ;!(r.end_of_prod&&b.end_of_prod); ++g.time) {
            if (!r.end_of_prod) {
                r.create_warrior(g.time);
                cout << setw(3) << setfill('0') << g.time;
                if (!r.end_of_prod) r.warrior->print_feature();
                else cout << " red headquarter stops making warriors" << endl;
            }
            if (!b.end_of_prod) {
                b.create_warrior(g.time);
                cout << setw(3) << setfill('0') << g.time;
                if (!b.end_of_prod) b.warrior->print_feature();
                else cout << " blue headquarter stops making warriors" << endl;
            }
        }

        ++case_counter;
    } while (case_counter <= n_cases);

    return 0;
}
