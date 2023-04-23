#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Student {
private:
    string meno;
    string priezvisko;
    vector<int> znamky;

public:
    // Konstruktor triedy
    Student(string meno, string priezvisko = "") {
        this->meno = meno;
        this->priezvisko = priezvisko;
    }

    // Destruktor triedy
    ~Student() {
        // v tejto triede sa nealokuje ziadna pamat, takze nie je co uvolnovat
    }

    // Getter a setter pre meno
   string getMeno() const {
        return meno;
    }
    void setMeno(string meno) {
        this->meno = meno;
    }

    // Getter a setter pre priezvisko
    string getPriezvisko() const {
        return priezvisko;
    }
    void setPriezvisko(string priezvisko) {
        this->priezvisko = priezvisko;
    }

    // Metóda pre vkladanie znamok
    void vlozitZnamku(int znamka) {
        if (znamka >= 1 && znamka <= 5) {
            znamky.push_back(znamka);
            cout << "Znamka " << znamka << " bola vlozena." << endl;
        } else {
            cout << "Neplatna znamka. Znamka musi byt v rozsahu 1-5." << endl;
        }
    }

    // Metóda pre výpis znamok
    void vypisatZnamky() const {
        if (znamky.empty()) {
            cout << "Ziaden zaznam o znamkach." << endl;
            return;
        }
        cout << "Znamky: ";
        for (int znamka : znamky) {
            cout << znamka << " ";
        }
        cout << endl;
    }

    // Metóda pre výpis informácií o študentovi
    void vypisatInformacie() const {
        cout << "Meno a priezvisko: " << meno << " " << priezvisko << endl;
        vypisatZnamky();
    }

};

int main() {
    // Vytvorenie noveho studenta a vlozenie znamok
    Student student("Janko", "Hrasko");
    student.vypisatInformacie();

    student.vlozitZnamku(1);
    student.vlozitZnamku(2);
    student.vlozitZnamku(3);
    student.vlozitZnamku(4);
    student.vlozitZnamku(5);

    student.vypisatInformacie();

    // Vytvorenie dalsieho studenta bez priezviska
    Student student2("Ferko");
    student2.vypisatInformacie();

    return 0;
}
