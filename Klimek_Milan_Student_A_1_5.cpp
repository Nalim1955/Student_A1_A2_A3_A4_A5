#include <iostream>
#include <string>
using namespace std;

class Student_cls
{

private:
    string meno_str;
    const int MAX_ZNAKOV_MENO = 30;
    string menoInfo_str;

    int rocnik_int;
    string rocnikInfo_str;

public:
    bool menoInfo_bl = false;
    bool rocnikInfo_bl = false;

    int pocetZnamok_F_int = 0;
    int pocetZnamok_int = 0;
    int znamky[10]; // pole pre ukladanie znamok

    bool vlozZnamku(int znamka);
    double priemer();

    Student_cls(string n, int y)
    {
        // **** meno_str ****
        if(n.length() > MAX_ZNAKOV_MENO) //zisti dlzku ak je > MAX_ZNAKOV_MENO tak info
        {
            meno_str = n.substr(0, MAX_ZNAKOV_MENO);
            menoInfo_str = "Meno bolo skratene. Presahuje maximalny pocet znakov ";
            menoInfo_bl = true;
        }
        else //ak je dlzka < ako MAX_ZNAKOV_MENO
        {
            meno_str = n;
            menoInfo_bl = false;
        }


        // **** rocnik_int ****
        if(y >= 1 && y <= 5) //zisti rocnik
        {
            rocnik_int = y;
            rocnikInfo_bl = false;
        }
        else //ak je mimo 1 az 5 tak info
        {
            rocnik_int = 1;
            rocnikInfo_str = "Nespravne zadany rocnik ! Ak nezmenite rocnik bude nastaveny na 1 !!!";
            rocnikInfo_bl = true;
        }

    }

    bool Bakalar_bl()
    {
        return (rocnik_int >= 1 && rocnik_int <= 3);
    }

    bool Inzinier_bl()
    {
        return (rocnik_int >= 4 && rocnik_int <= 5);
    }

    string nacitajMeno_str()
    {
        return meno_str;
    }

    void vypis() //vypis pre uzivatela
    {
        string Trieda_str = "";
        if (Bakalar_bl()) //ak je true napise Bakalar inak pokracuje na else if
        {
            Trieda_str = "Bakalar";
        }
        else if (Inzinier_bl()) //ak je true napise Inzinier
        {
            Trieda_str = "Inzinier";
        }

        if((menoInfo_bl == false) && (rocnikInfo_bl == false)) //Ak su false tak zapis meno rocnik trieda
        {
            cout << meno_str << " je v " << rocnik_int << " rocniku : " << Trieda_str << endl;
        }
        else if ((menoInfo_bl == true) && (rocnikInfo_bl == false)) //menoInfo_bl == true informuje o tom ze meno je dlhsie ako MAX_ZNAKOV_MENO
        {
            cout << meno_str << " je v " << rocnik_int << " rocniku : " << Trieda_str << " | " << menoInfo_str << MAX_ZNAKOV_MENO << " ." << endl;
        }
        else if ((menoInfo_bl == false) && (rocnikInfo_bl == true)) //rocnikInfo_bl == true informuje o tom ze je zle zadany rocnik
        {
            cout << meno_str << " je v " << rocnik_int << " rocniku : " << Trieda_str << " | " << rocnikInfo_str << endl;
        }
        else if ((menoInfo_bl == true) && (rocnikInfo_bl == true)) //informuje o prekroceni mena aj zle zadanom rocniku
        {
            cout << meno_str << " je v " << rocnik_int << " rocniku : " << Trieda_str << " | " << rocnikInfo_str << " " << menoInfo_str << MAX_ZNAKOV_MENO << " ." << endl;
        }

    }

};

bool Student_cls::vlozZnamku(int znamka)
{

    if (pocetZnamok_int < 10 && znamka >= 1 && znamka <= 5) // kontrola dostupného miesta v poli a platnosti znamky
    {
        znamky[pocetZnamok_int++] = znamka;
        return true;
    }
    else
    {
        pocetZnamok_F_int ++;
        return false;
    }
}

double Student_cls::priemer()
{
    double priemer_dbl = 0.0;

    for (int i = 0; i < pocetZnamok_int; i++)
    {
        priemer_dbl += znamky[i];
    }

    if (pocetZnamok_int > 0)
    {
        priemer_dbl /= pocetZnamok_int;
    }
    return priemer_dbl;
}

int main(int argc, char** argv)
{

    Student_cls Student_clss[] = //Vlozenie studenta a rocniku
    {
        Student_cls("Lukas", 2),
        Student_cls("Jano", 4),
        Student_cls("Peter", 1),
        Student_cls("Martin", 5),
        Student_cls("Jozef", 3)
    };


    int numStudent_int = sizeof(Student_clss) / sizeof(Student_cls); //vypocitanie poctu opakovani pre Student_clss[i]

    for (int i = 0; i < numStudent_int; i++)
    {
        Student_clss[i].vypis();
    }

    Student_cls Jano("Jano", 4); //vlozenie znamky pre studenta Jano
    Jano.vlozZnamku(4);
    Jano.vlozZnamku(5);
    Jano.vlozZnamku(1);
    Jano.vlozZnamku(3);
    Jano.vlozZnamku(8);
    Jano.vlozZnamku(3);
    Jano.vlozZnamku(6);
    Jano.vlozZnamku(3);
    Jano.vlozZnamku(3);
    Jano.vlozZnamku(3);
    Jano.vlozZnamku(3);

    cout << " ******** "<< endl;
    int novaZnamka;

    cout << "Zadajte novu znamku (pre ukoncenie vkladania stlac 0): ";
    cin >> novaZnamka;
    Jano.vlozZnamku(novaZnamka);

    if (novaZnamka != 0) //ak je 0 ukonci vkladanie
    {
        do //vlozenie znamky pre studenta Jano cez do while
        {

            cout << endl;
            cout << "Zadajte dalsiu znamku (pre ukoncenie vkladania stlac 0): ";
            cin >> novaZnamka;

            if (novaZnamka != 0) //ak to nie je 0 tak pokracuj nizsie
            {
                bool vysledok_TF = Jano.vlozZnamku(novaZnamka); //zisti ci je vlozZnamku TRUE alebo FALSE

                if (!vysledok_TF) //ak je FALSE informuj
                {
                    cout << "Nepodarilo sa pridat znamku. Znamka je mimo rozsahu 1 az 5." << endl;
                }

                if(Jano.pocetZnamok_int >= 10)
                {
                    cout << endl;
                    cout << "POZOR, zadali ste maximalny pocet znamok." << endl;
                    cout << "Maximalny pocet pre vypocet priemeru je 10 znakom." << endl;
                }
            }


        }
        while(novaZnamka!=0); //ak je 0 ukonci zadavanie novaZnamka

    }


    cout << endl;
    Jano.vypis();
    cout << "Priemer znamok pre studenta " << Jano.nacitajMeno_str() << " je: " << Jano.priemer() << " ." << endl;

    cout << endl;
    cout << "Pocet nezapocitanych znamok, alebo znamok mimo rozsahu 1 az 5 pre studenta " << Jano.nacitajMeno_str() << " je: " << Jano.pocetZnamok_F_int << " ." << endl;
    cout << endl;


    return 0;
}
