#include<cstring>
#include <iostream>
#include <fstream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<map>
using namespace std;
ifstream fin("Agent.csv");

/// Clasa AGENT
class AGENT //////////////////////////////////////////////////////////////////////////////////////////////////////// AGENT
{
    int cod;
    string NumeAgent;
    string TelAgent;
    string email;
    friend class AGENTIE;
public:
    AGENT(int = 0, string = nullptr, string = nullptr, string = nullptr);
    friend ostream& operator <<(ostream&, const AGENT&);
    friend void InserareAgent();
    friend void StergereAgent();

};
AGENT::AGENT(int z, string a, string b, string c)
    :email(c), NumeAgent(a), TelAgent(b), cod(z)
{}
ostream& operator<<(ostream& os, const AGENT& a)
{
    os <<"\t\t\t\t\t"<< a.cod << " NUME:" << a.NumeAgent <<endl<<"\t\t\t\t\t    Telefonul: "<<a.TelAgent<<"   E-mail:"<<a.email<< endl<<endl;
    return os;
}


/// Clasa AGENTIE
class AGENTIE //////////////////////////////////////////////////////////////////////////////////////////////////////// AGENTIE
{
private:
    int cod = 2639623;
    char Nume[101] = "Firma1"; //nume de test
    vector <AGENT> ListaAgenti;
    
public:
    friend ostream& operator<<(ostream&, const AGENTIE&);
    void SetLista(AGENT& a);
    void afisareLista();
    void stergereagenti(int);
    friend void InserareAgent();
    friend void StergereAgent();


};
void AGENTIE::stergereagenti(int c)
{
    int i;
    for (i = 0; i < ListaAgenti.size(); i++)
    {
        //cout << ListaAgenti.at(i);
        if (ListaAgenti.at(i).cod == c)
        {
            //cout << endl << endl;
            //cout << ListaAgenti.at(i);
            //cout<< endl << endl;
            ListaAgenti.erase(ListaAgenti.begin() + i+ 1);
        }
            
    }
}
void AGENTIE::afisareLista()
{
    int i;
    for (i = 0; i <ListaAgenti.size(); i++)
        cout << ListaAgenti[i];
}
void AGENTIE::SetLista(AGENT& a)
{
    ListaAgenti.push_back(a);
}
ostream& operator<<(ostream& os, const AGENTIE& p)
{
    os << "Buna! Noi suntem firma " << p.Nume << " si suntem incantati sa colaboram!" << endl;
    return os;

}


/// Clasa TEREN
class TEREN //////////////////////////////////////////////////////////////////////////////////////////////////////// TEREN
{
private:
    int cod;
    float pretT;
    string Oras;
    string Judet;
    string AdresaT;
    string numePropT;
    string telPropT;
    float suprafata;
    bool tip; //1 - intravilan
             // 0 - extravilan
    friend class IMOBILE;
public:
    TEREN(int = 0, float = 0.0, string = nullptr, string = nullptr, string = nullptr, string = nullptr, string = nullptr, bool = 0, float = 0);
    TEREN(const TEREN&);
    friend ostream& operator<<(ostream&, const TEREN&);
    friend void DupaJudet();
    friend void DupaOras();
    friend void DupaMediu();
    friend void IntrePret();
    friend void AnalizeazaPiata();
    friend void InserareImobil();
    friend void StergereImobil();

};
TEREN::TEREN(int z, float a, string b, string c, string d, string e, string f, bool g, float h)
    :cod(z), pretT(a), Oras(b), Judet(c), AdresaT(d), numePropT(e), telPropT(f), tip(g), suprafata(h)
{}
TEREN::TEREN(const TEREN& c)
    : cod(c.cod), pretT(c.pretT), Oras(c.Oras), Judet(c.Judet), AdresaT(c.AdresaT), numePropT(c.numePropT), telPropT(c.telPropT), tip(c.tip), suprafata(c.suprafata)

{}
ostream& operator <<(ostream& os, const TEREN& c)
{
    os << "\t\t\t\t\t" << c.cod << " " << c.Oras << " " << c.pretT << endl;
    return os;
}


/// Clasa CONSTRUCTIE
class CONSTRUCTIE //////////////////////////////////////////////////////////////////////////////////////////////////////// CONSTRUCTIE
{
    int cod;
    string Oras;
    string Judet;
    string tip;//
    int NrCamere;//
    float pretC;
    string AdresaC;
    string numePropC;
    string telPropC;
    float suprafata;
    friend class IMOBILE;
public:

    CONSTRUCTIE(int = 0, string = nullptr, string = nullptr, string = nullptr, int = 0, float = 0, string = nullptr, string = nullptr, string = nullptr, float = 0);
    CONSTRUCTIE(const CONSTRUCTIE&);
    friend ostream& operator<<(ostream&, const CONSTRUCTIE&);
    friend void DupaJudet();
    friend void DupaOras();
    friend void IntrePret();
    friend void AnalizeazaPiata();
    friend void InserareImobil();
    friend void StergereImobil();

};
CONSTRUCTIE::CONSTRUCTIE(int z, string a, string b, string c, int d, float f, string g, string h, string i, float j)
    :cod(z), Oras(a), Judet(b), tip(c), NrCamere(d), pretC(f), AdresaC(g), numePropC(h), telPropC(i), suprafata(j)
{}
CONSTRUCTIE::CONSTRUCTIE(const CONSTRUCTIE& c)
    : cod(c.cod), Oras(c.Oras), Judet(c.Judet), tip(c.tip), NrCamere(c.NrCamere), pretC(c.pretC), AdresaC(c.AdresaC), numePropC(c.numePropC), telPropC(c.telPropC), suprafata(c.suprafata)
{}
ostream& operator<<(ostream&os, const CONSTRUCTIE&c)
{
    os <<"\t\t\t\t\t"<< c.cod << " " << c.AdresaC << " " << c.Oras << " " << c.suprafata << endl;
    return os;
}


/// Clasa IMOBILE 
class IMOBILE//////////////////////////////////////////////////////////////////////////////////////////////////////////////////IMOBIL
{
private:
    vector <TEREN> ListaTeren;
    vector <CONSTRUCTIE> ListaConstructie;
 
public:

    void SetLista(TEREN& a);
    void afisareListaT(); 
    void SetLista(CONSTRUCTIE& a);
    void afisareListaC();
    friend void DupaJudet();
    friend void DupaOras();
    friend void DupaMediu();
    friend void IntrePret();
    friend void AnalizeazaPiata();
    friend void InserareImobil();
    friend void InserareAgent();
    friend void StergereImobil();
    void stergeteren(int);
    void stergeconstructie(int);
};
void IMOBILE::stergeconstructie(int c)
{
    int i;
    for (i = 0; i < ListaConstructie.size(); i++)
    {
        if (ListaConstructie.at(i).cod == c)
            ListaConstructie.erase(ListaConstructie.begin() + i + 1);
    }
}
void IMOBILE::stergeteren(int c)
{
    int i;
    for (i = 0; i < ListaTeren.size(); i++)
    {
        if (ListaTeren.at(i).cod == c)
            ListaTeren.erase(ListaTeren.begin() + i + 1);
    }
}
void IMOBILE::afisareListaT()
{
    int i;
    for (i = 0; i < ListaTeren.size(); i++)
        cout << ListaTeren[i] ;
}
void IMOBILE::SetLista(CONSTRUCTIE& a)
{
    ListaConstructie.push_back(a);
}
void IMOBILE::afisareListaC()
{
    int i;
    for (i = 0; i < ListaConstructie.size(); i++)
        cout << ListaConstructie.at(i) ;
}
void IMOBILE::SetLista(TEREN& a)
{
    ListaTeren.push_back(a);
}


/// Declararea agentiei si a imobilului
AGENTIE Firma;
IMOBILE ImobileleNoastre;
void initializare()
{
    ifstream inFile;
    inFile.open("Agenti.txt");

    string num, tel, mail;
    int i = 0;
    inFile >> num;
    while (!inFile.eof())
    {

        i++;
        inFile >> num >> tel >> mail;
        //cout << num << " " << tel << " " << mail << endl;
            AGENT a(i, num, tel, mail);
            Firma.SetLista(a);
        
    }
    inFile.close();
    //Firma.afisareLista();

       //////////////////////////////////////////////////////////////////////////////////


    inFile.open("TERENURI.txt");

    i = 0;
    float pretul, suprafatateren;
    string o, j, a, n, t;
    bool tp;
    inFile >> o;
    while (!inFile.eof())
    {

        i++;
        inFile >> pretul >> o >> j >> a >> n >> t >> tp >> suprafatateren;
        //cout <<pretul<< o << j << a << n << t << tp << endl;
        TEREN Ter(i, pretul, o, j, a, n, t, tp, suprafatateren);
        //  cout << Ter;
        ImobileleNoastre.SetLista(Ter);

    }

    inFile.close();
    //ImobileleNoastre.afisareListaT();
   /////////////////////////////////////////////////

    inFile.open("CONSTRUCTII.txt");
    i = 0;
    string ab, b, c, f, g, h;
    int d;
    float e, z;
    inFile >> a;
    while (!inFile.eof())
    {

        i++;
        inFile >> ab >> b >> c >> d >> e >> f >> g >> h >> z;
        //cout << ab <<" "<< b <<" "<< c <<" "<< d <<" "<< e <<" "<< f <<" "<< g <<" "<< h <<" "<< z<<endl;

        CONSTRUCTIE Cons(i, ab, b, c, d, e, f, g, h, z);
        //cout << Cons;
        ImobileleNoastre.SetLista(Cons);

    }
    inFile.close();
    //ImobileleNoastre.afisareListaC();

}


/// Functiile care se apeleaza in Meniu
void ExitProgram()
{
    cout << endl << endl << endl << "                   Multumim pentru increderea acordata!" << endl << endl << endl;
}
void AfisareDisponibil()
{
    cout << endl << endl;
    cout <<"\t\t\tImobilele disponibile sunt:" << endl<<endl;
    cout << "\t\t\t\tA. Terenurile goale:" << endl;
    ImobileleNoastre.afisareListaT();
    cout << endl;
    cout << "\t\t\t\tB. Terenurile cu constructie:" << endl;
    ImobileleNoastre.afisareListaC();
}
void AfisareAgent()
{
    cout << endl << endl;
    cout << "\t\t\tAgentii nostri Imobiliari sunt:" << endl;
    Firma.afisareLista();
    cout << endl;
}
void DupaJudet()
{
    string s;
    cin >> s;
    cout << "\t\t\t\tA.Terenurile:"<<endl;
    int i, sw = 0;
    for (i = 0; i < ImobileleNoastre.ListaTeren.size(); i++)
        if (ImobileleNoastre.ListaTeren.at(i).Judet == s)
        {
            cout << ImobileleNoastre.ListaTeren.at(i);
            sw = 1;
        }
    if (sw == 0) cout << "\t\t\t\tNu exista terenuri din acest judet";
    cout << endl << endl;
    cout << "\t\t\t\tB.Terenurile cu constructie:" << endl;
    sw = 0;
    for (i = 0; i < ImobileleNoastre.ListaConstructie.size();i++)
        if(ImobileleNoastre.ListaConstructie.at(i).Judet == s)
    {
        cout << ImobileleNoastre.ListaConstructie.at(i);
        sw = 1;
    }
    if (sw == 0) cout << "\t\t\t\tNu exista constructii din acest judet";

}
void AfisareJudet()
{
    int i;
    cout << "\t\t\tAlegeti judetul din care doriti sa vedeti imobilele"<<endl;
    cout << "\t\t\tAlegerea dumneavoastra este: ";
    DupaJudet();
}
void  DupaOras()
{
    string s;
    cin >> s;
    cout << "\t\t\t\tA.Terenurile:" << endl;
    int i, sw = 0;
    for (i = 0; i < ImobileleNoastre.ListaTeren.size(); i++)
        if (ImobileleNoastre.ListaTeren.at(i).Oras== s)
        {
            cout << ImobileleNoastre.ListaTeren.at(i);
            sw = 1;
        }
    if (sw == 0) cout << "\t\t\t\tNu exista terenuri din acest oras";
    cout << endl << endl;
    cout << "\t\t\t\tB.Terenurile cu constructie:" << endl;
    sw = 0;
    for (i = 0; i < ImobileleNoastre.ListaConstructie.size(); i++)
        if (ImobileleNoastre.ListaConstructie.at(i).Oras == s)
        {
            cout << ImobileleNoastre.ListaConstructie.at(i);
            sw = 1;
        }
    if (sw == 0) cout << "\t\t\t\tNu exista constructii din acest oras" << endl << endl;
}
void AfisareOras()
{
    cout << "\t\t\tAlegeti orasul din care doriti sa vedeti imobilele" << endl;
    cout << "\t\t\tAlegerea dumneavoastra este: ";
    DupaOras();
}
void DupaMediu()
{
    int n,i,sw=0;
    cin >> n;
    for (i = 0; i < ImobileleNoastre.ListaTeren.size(); i++)
        if (ImobileleNoastre.ListaTeren.at(i).tip == n)
        {
            cout << ImobileleNoastre.ListaTeren.at(i);
            sw = 1;
        }
    if (sw == 0) cout << "\t\t\tNu exista!" << endl;

}
void AfisareDupaMediu()
{
    cout << "\t\t\tAlegeti tipul de mediu din care doriti sa vedeti terenurile" << endl;
    cout << "\t\t\t\t0 - extravilan" << endl << "\t\t\t\t1 - intravilan" << endl;
    cout << "\t\t\tAlegerea dumneavoastra este: ";
    DupaMediu();

}
void IntrePret()
{
    int mini, maxi;
    cout << "\t\t\t\tPretul minim: ";
    cin >> mini;
    cout << "\t\t\t\tPretul maxim: ";
    cin >> maxi;
    cout << endl << "\t\t\tA. Terenuri: "<<endl;
    int i, sw=0;
    for (i = 0; i < ImobileleNoastre.ListaTeren.size(); i++)
        if (mini <= ImobileleNoastre.ListaTeren.at(i).pretT && ImobileleNoastre.ListaTeren.at(i).pretT <= maxi)
        {
            cout << ImobileleNoastre.ListaTeren.at(i);
            sw = 1;
        }
    if (sw == 0) cout << "\t\t\t\tNe cerem scuze, nu exista terenuri intre " << mini << " - " << maxi << endl;
    cout << endl;
    cout << endl << "\t\t\tB. Terenuri cu constructie: "<<endl;
    sw = 0;
    for(i = 0; i<ImobileleNoastre.ListaConstructie.size();i++)
        if (mini <= ImobileleNoastre.ListaConstructie.at(i).pretC && ImobileleNoastre.ListaConstructie.at(i).pretC <= maxi)
        {
            cout << ImobileleNoastre.ListaConstructie.at(i);
            sw = 1;
        }
   if (sw == 0) cout << "\t\t\t\tNe cerem scuze, nu exista terenuri cu constructie  intre " << mini << " - " << maxi << endl;
   cout << endl;
}
void AfisareIntrePret()
{
    cout << "\t\t\tAlegeti variatia de pret:" << endl;
    IntrePret();
}
void AnalizeazaPiata()
{
    cout << "\t\t\tA. Terenuri: " << endl;
    int i,a=0,b=0,c=0;
    float miniT = ImobileleNoastre.ListaTeren.at(0).pretT, maxiT = 0;
    float miniTi = 0, maxiTi = 0;
    float miniTe = 0, maxiTe = 0;
    long long medT = 0, medTi = 0, medTe = 0;
    for (i = 0; i < ImobileleNoastre.ListaTeren.size(); i++)
    {
        a++;
        medT = medT + ImobileleNoastre.ListaTeren.at(i).pretT;
        if (miniT > ImobileleNoastre.ListaTeren.at(i).pretT)
            miniT = ImobileleNoastre.ListaTeren.at(i).pretT;
        if(maxiT< ImobileleNoastre.ListaTeren.at(i).pretT)
            maxiT= ImobileleNoastre.ListaTeren.at(i).pretT;

        if (ImobileleNoastre.ListaTeren.at(i).tip == 1)
        {
            b++;
            medTi = medTi + ImobileleNoastre.ListaTeren.at(i).pretT;
            if(miniTi==0) miniTi = ImobileleNoastre.ListaTeren.at(i).pretT;
            if (miniTi > ImobileleNoastre.ListaTeren.at(i).pretT)
                miniTi = ImobileleNoastre.ListaTeren.at(i).pretT;
            if (maxiTi < ImobileleNoastre.ListaTeren.at(i).pretT)
                maxiTi = ImobileleNoastre.ListaTeren.at(i).pretT;
        }
        if (ImobileleNoastre.ListaTeren.at(i).tip == 0)
        {
            c++;
            medTe = medTe + ImobileleNoastre.ListaTeren.at(i).pretT;
            if (miniTe == 0) miniTe = ImobileleNoastre.ListaTeren.at(i).pretT;
            if (miniTe > ImobileleNoastre.ListaTeren.at(i).pretT)
                miniTe = ImobileleNoastre.ListaTeren.at(i).pretT;
            if (maxiTe < ImobileleNoastre.ListaTeren.at(i).pretT)
                maxiTe = ImobileleNoastre.ListaTeren.at(i).pretT;
        }
    }
    medT = medT / a;
    medTi = medTi / b;
    medTe = medTe / c;
    cout << "\t\t\t\tPretul mediu: "<<medT<<endl;
    cout << "\t\t\t\tPretul minim: " << miniT << endl;
    cout << "\t\t\t\tPretul maxim: " << maxiT << endl;
    cout << endl << endl;
    cout << "\t\t\tB. Terenuri intravilane: " << endl;
    cout << "\t\t\t\tPretul mediu: " << medTi << endl;
    cout << "\t\t\t\tPretul minim: " << miniTi << endl;
    cout << "\t\t\t\tPretul maxim: " << maxiTi << endl;
    cout << endl << endl;
    cout << "\t\t\tC. Terenuri extravilane: " << endl;
    cout << "\t\t\t\tPretul mediu: " << medTe << endl;
    cout << "\t\t\t\tPretul minim: " << miniTe << endl;
    cout << "\t\t\t\tPretul maxim: " << maxiTe << endl;
    cout << endl << endl;
    cout << "\t\t\tC. Terenuri cu constructii: " << endl;
    float miniC = ImobileleNoastre.ListaConstructie.at(0).pretC, maxiC = 0;
    long long medC = 0;
    a = 0;
    for (i = 0; i < ImobileleNoastre.ListaConstructie.size(); i++)
    {
        a++;
        medC = medC + ImobileleNoastre.ListaConstructie.at(i).pretC;
        if (miniC > ImobileleNoastre.ListaConstructie.at(i).pretC)
            miniC = ImobileleNoastre.ListaConstructie.at(i).pretC;
        if (maxiC < ImobileleNoastre.ListaConstructie.at(i).pretC)
            maxiC = ImobileleNoastre.ListaConstructie.at(i).pretC;
    }
    cout << "\t\t\t\tPretul mediu: " << medC << endl;
    cout << "\t\t\t\tPretul minim: " << miniC << endl;
    cout << "\t\t\t\tPretul maxim: " << maxiC << endl << endl;

}
void Piata()
{
    cout << "\t\t\tAm pregatit pentru tine o analiza extraordinara!" << endl;
    AnalizeazaPiata();
}
void FiesierTeren(float pr, string oras, string jude, string adr, string numeprop, string tel, bool tipT, float supr)
{
    ifstream ter;
    ter.open("TERENURI.txt");
    ofstream aux;
    aux.open("auxiliar.txt");
    float p;
    string o, j, a, n, t;
    bool tip;
    float s;
    ter >> o;
    aux << o << endl;
    while (!ter.eof()) {
        ter >> p >> o >> j >> a >> n >> t >> tip >> s;
        aux << p << " " << o << " " << j << " " << a << " " << n << " " << t << " " << tip << " " << s << endl;
    }
    aux << pr << " " << oras << " " << jude << " " << adr << " " << numeprop << " " << tel << " " << tipT << " " << supr;
    ter.close();
    aux.close();
    char filename1[] = "TERENURI.txt";
    char filename2[] = "auxiliar.txt";
    if (remove(filename1) != 0)
        perror("File deletion failed");
    else
        cout << "File deleted successfully";

    if (rename(filename2, filename1) != 0)
        perror("Error renaming file");
    else
        cout << "File renamed successfully";
    cout << endl;
}
void FisierConstructii(string oras, string jud, string tipC, int nrcam, float pr, string adr, string numeprop, string tel, float sup)
{
    ifstream con;
    con.open("CONSTRUCTII.txt");
    ofstream aux;
    aux.open("auxiliar.txt");
    float pret,supr;
    string o, j, t,a, num, telefon;
    int n;
    con>> o;
    aux << o << endl;
    while (!con.eof()) {
        con >> o >> j >> t >> n >> pret >> a >> num >> telefon >> supr;
        aux << o << " " << j << " " << t << " " << n << " " << pret << " " << a << " " << num << " " << telefon << " "<<supr<<endl;
    }
    aux << oras << " " << jud << " " << tipC << " " << nrcam << " " << pr << " " <<adr << " " << numeprop << " " << tel<<" "<<sup;
    con.close();
    aux.close();
    char filename1[] = "CONSTRUCTII.txt";
    char filename2[] = "auxiliar.txt";
    if (remove(filename1) != 0)
        perror("File deletion failed");
    else
        cout << "File deleted successfully";

    if (rename(filename2, filename1) != 0)
        perror("Error renaming file");
    else
        cout << "File renamed successfully";
    cout << endl;
}
void InserareImobil()
{
    int n;
    cout << "\t\t\t\tBuna! Alegeti varianta de raspuns dorita"<<endl;
    cout << "\t\t\t\t\t1 - Teren" << endl << "\t\t\t\t\t2 - Constructie" << endl;
    cout << "\t\t\t\tDecizia dumneavoastra este: ";
    cin >> n;
    string judetinser, orasinser, adresainser, numepropinser, telinser;
    float pretinser, suprinser;
    cout << "\t\t\tJudetul: "; cin >> judetinser;
    cout << "\t\t\tOras: ";    cin >> orasinser;
    cout << "\t\t\tAdresa: ";  cin >> adresainser;
    cout << "\t\t\tPret: ";    cin >> pretinser;
    cout << "\t\t\tNume proprietar: "; cin >> numepropinser;
    cout << "\t\t\tTelefon: "; cin >> telinser;
    cout << "\t\t\tSuprafata: "; cin >> suprinser;
    bool tipinserT;
    string tipinserC;
    int nrcamereinser;
    if (n == 1)
    {
        cout << "\t\t\tTip(1-intravilan;0-extravilan):"; cin >> tipinserT;
        int cod1 =  ImobileleNoastre.ListaTeren.size()+1;
        TEREN t(cod1, pretinser, orasinser, judetinser, adresainser, numepropinser, telinser, tipinserT, suprinser);
        ImobileleNoastre.SetLista(t);
        FiesierTeren(pretinser,orasinser,judetinser,adresainser,numepropinser,telinser,tipinserT,suprinser);
    }
    else if (n == 2)
    {
        cout << "\t\t\tTip constructie: "; cin >> tipinserC;
        cout << "\t\t\tNumarul de camere: "; cin >> nrcamereinser;
        int cod2 = ImobileleNoastre.ListaConstructie.size();
        CONSTRUCTIE c(cod2, orasinser, judetinser, tipinserC, nrcamereinser, pretinser, adresainser, numepropinser, telinser, suprinser);
        ImobileleNoastre.SetLista(c);
        FisierConstructii(orasinser,judetinser,tipinserC,nrcamereinser,pretinser,adresainser,numepropinser,telinser, suprinser );
    }
}
void FisierAgenti(string num, string tel,string mail)
{
    ifstream ag;
    ag.open("Agenti.txt");
    ofstream aux;
    aux.open("auxiliar.txt");
    string n, t, m;
    ag >> n;
    aux << n<<endl;
    while (!ag.eof()) {
        ag >> n>>t>>m;
        aux <<n<<" "<<t<<" "<<m<< endl;
    }
    aux << num << " " << tel << " " << mail << endl;
    ag.close();
    aux.close();
    char filename1[] = "Agenti.txt";
    char filename2[] = "auxiliar.txt";
    if (remove(filename1) != 0)
        perror("File deletion failed");
    else
        cout << "File deleted successfully";

    if (rename(filename2, filename1) != 0)
        perror("Error renaming file");
    else
        cout << "File renamed successfully";
    cout << endl;
}
void InserareAgent()
{
    cout << "\t\t\t\tBuna! Aici poti sa inserezi un nou agent!" << endl;
    string nume, telefon, mail;
    cout << "\t\t\t\t\tNumele acestuia: " ;
    cin >> nume;
    cout<< "\t\t\t\t\tTelefonul acestuia: " ;
    cin >> telefon;
    cout << "\t\t\t\t\tAdresa de e-mail a acestuia: " ;
    cin >> mail;
    int cod = Firma.ListaAgenti.size()+1;
    AGENT a(cod, nume, telefon, mail);
    Firma.SetLista(a);
    FisierAgenti(nume,telefon,mail);
}
void StergeTeren(string oras, string adr, string num)
{
    //cout << oras <<" "<< adr <<" "<< num<<endl<<endl<<endl;
    ifstream ter;
    ter.open("TERENURI.txt");
    ofstream aux;
    aux.open("auxiliar.txt");
    float p;
    string o, j, a, n, t;
    bool tip;
    float s;
    ter >> o;
    aux << o;
    while (!ter.eof()) {
        ter >> p >> o >> j >> a >> n >> t >> tip >> s;
        if(o!=oras || adr!=a || num!=n)
        {
            aux << endl;
            aux << p << " " << o << " " << j << " " << a << " " << n << " " << t << " " << tip << " " << s ;
         //cout<< p << " " << o << " " << j << " " << a << " " << n << " " << t << " " << tip << " " << s << endl;
        }
        
    }

    ter.close();
    aux.close();
    char filename1[] = "TERENURI.txt";
    char filename2[] = "auxiliar.txt";
    if (remove(filename1) != 0)
        perror("File deletion failed");
    else
        cout << "File deleted successfully";

    if (rename(filename2, filename1) != 0)
        perror("Error renaming file");
    else
        cout << "File renamed successfully";
    cout << endl;
}
void StergeConstructie(string oras, string adr, string nume)
{
    //cout << oras << " " << adr << " " << nume << endl << endl << endl;
    ifstream con;
    con.open("CONSTRUCTII.txt");
    ofstream aux;
    aux.open("auxiliar.txt");
    float pret, supr;
    string o, j, t, a, num, telefon;
    int n;
    con >> o;
    aux << o ;
    while (!con.eof()) {
        con >> o >> j >> t >> n >> pret >> a >> num >> telefon >> supr;
        if (o != oras || adr != a || num!= nume)
        {
            aux << endl;
            aux << o << " " << j << " " << t << " " << n << " " << pret << " " << a << " " << num << " " << telefon << " " << supr;
            //cout << o << " " << j << " " << t << " " << n << " " << pret << " " << a << " " << num << " " << telefon << " " << supr << endl;
        }

    }

    con.close();
    aux.close();
    char filename1[] = "CONSTRUCTII.txt";
    char filename2[] = "auxiliar.txt";
    if (remove(filename1) != 0)
        perror("File deletion failed");
    else
        cout << "File deleted successfully";

    if (rename(filename2, filename1) != 0)
        perror("Error renaming file");
    else
        cout << "File renamed successfully";
    cout << endl;
}
void StergereImobil()
{
    int n, ok = 0;
    cout << "\t\t\t\tBuna! Alegeti varianta de raspuns dorita" << endl;
    cout << "\t\t\t\t\t1 - Teren" << endl << "\t\t\t\t\t2 - Constructie" << endl;
    cout << "\t\t\t\tDecizia dumneavoastra este: ";
    cin >> n;
    if (n == 1)
    {
        ImobileleNoastre.afisareListaT();
        cout << "\t\t\t\tAlegere: ";
        cin >> ok;
        ok = ok - 1;
        string oras1 = ImobileleNoastre.ListaTeren.at(ok).Oras;
        string adresa = ImobileleNoastre.ListaTeren.at(ok).AdresaT;
        string numeprop = ImobileleNoastre.ListaTeren.at(ok).numePropT;
        StergeTeren(oras1,adresa,numeprop);
        ImobileleNoastre.stergeteren(ok);
    }
        
    else if (n == 2)
    {
        ImobileleNoastre.afisareListaC();
        cout << "\t\t\t\tAlegere: ";
        cin >> ok;
        ok = ok - 1;
        string oras1 = ImobileleNoastre.ListaConstructie.at(ok).Oras;
        string adresa = ImobileleNoastre.ListaConstructie.at(ok).AdresaC;
        string numeprop = ImobileleNoastre.ListaConstructie.at(ok).numePropC;
        StergeConstructie(oras1, adresa, numeprop);
        ImobileleNoastre.stergeconstructie(ok);

    }
    
}
void  Stergdinfisierulageti(string a, string b, string c)
{
    //cout << a << "         " << b << "         " << c << endl << endl;
    ifstream ag;
    ag.open("Agenti.txt");
    ofstream aux;
    aux.open("auxiliar.txt");
    string n, t, m;
    ag >> n;
    aux << n ;
    while (!ag.eof()) {
        ag >> n >> t >> m;
        if (a!=n || t!= b || m!=c)
        {
            aux << endl;
            aux << n << " " << t << " " << m ;
            //cout << n << " " << t << " " << m << endl;
        }
    }
    ag.close();
    aux.close();
    char filename1[] = "Agenti.txt";
    char filename2[] = "auxiliar.txt";
    if (remove(filename1) != 0)
        perror("File deletion failed");
    else
        cout << "File deleted successfully";

    if (rename(filename2, filename1) != 0)
        perror("Error renaming file");
    else
        cout << "File renamed successfully";
    cout << endl;
}
void StergereAgent()
{
    int ok = 0;
    cout << "\t\t\t\tBuna! Alegeti varianta de raspuns dorita" << endl;
    Firma.afisareLista();
    cout << "\t\t\t\tAlegerea: ";
    cin >> ok;
    ok = ok - 1;
    string nume = Firma.ListaAgenti.at(ok).NumeAgent;
    string tel = Firma.ListaAgenti.at(ok).TelAgent;
    string mail = Firma.ListaAgenti.at(ok).email;
    Stergdinfisierulageti(nume, tel, mail);
    Firma.stergereagenti(ok);
   
}


/// Meniu
int ACCES()
{
    // OCTAVIAN 12345678
    //ROBERT 87654321
    //ALE 27727227
    // RARES 11111111
    cout << "\t\t\t\tAveti nevoie de acces pentru a realiza aceasta operatie" << endl;
    cout << "\t\t\t\t\tNUME: ";
        string nume;
    cin >> nume;
    cout << "\t\t\t\t\tPAROLA: ";
        int parola;
    cin >> parola;
    if (nume == "OCTAVIAN" && parola == 12345678) { cout << "\t\t\t\t\tBuna, Octa!" << endl; return 1; }
    else if (nume == "ROBERT" && parola == 87654321) { cout << "\t\t\t\t\tBuna, Robert!" << endl; return 1; }
    else if (nume == "RARES" && parola == 11111111) {cout << "\t\t\t\t\tBuna, Rares!" << endl; return 1;}
    else if (nume == "ALE" && parola == 27727227) {cout << "\t\t\t\t\tBuna, Aleeee!" << endl; return 1; }
    else cout << "\t\tNe pare rau, nu puteti efectua aceasta operatie!"<<endl<<endl;
}
void legenda(int &n)
{
    cout << endl << endl;
    cout << "\t\t//        //       //  ////////  //            //////     //////     //         //  ////////" << endl;
    cout << "\t\t //     // //     //   //        //          //         //      //   // //   // //  //      " << endl;
    cout << "\t\t  //   //   //   //    //////    //        //          //        //  //    //   //  //////  " << endl;
    cout << "\t\t   // //     // //     //        //         //         //       //   //         //  //      " << endl;
    cout << "\t\t    //        //       ///////   ////////     //////     //////      //         //  ////////" << endl;
    
    cout << endl << endl;
    cout << "\t\t\tAlege te rog functia pe care o doresti:" << endl; ///////
    cout << "\t\t\t1) Se afiseaza toate imobilele disponibile" << endl; ///////////////////////////////////////////////////GATA
    cout << "\t\t\t2) Se afiseaza imobilele dintr-un anumit judet" << endl;///////////////////////////////////////////////GATA
    cout << "\t\t\t3) Se afiseaza imobilele dintr-un anumit oras" << endl;////////////////////////////////////////////////GATA
    cout << "\t\t\t4) Se afiseaza toti agentii imobiliari si datele acestora" << endl;/////////////////////////////////////GATA
    cout << "\t\t\t5) Se afiseaza lista imobilelor dintr-un anumit mediu" << endl;/////////////////////////////////////////GATA
    cout << "\t\t\t6) Se afiseaza lista tuturor imobilelor cuprinse intr-un anumit pret" << endl;/////////////////////////GATA
    cout << "\t\t\t7) Se studiaza piata " << endl; ///////////////////////////////////////////////////////////////////////GATA
    cout << "\t\t\t0) Daca doriti sa opriti programul";
    cout << endl << endl;
    cout << "\t\t\t\t8) Adaugarea unui imobil" << endl;//////////////////////////////////////////////////////////////////GATA
    cout << "\t\t\t\t9) Adaugarea unui agent" << endl;///////////////////////////////////////////////////////////////////GATA
    cout << "\t\t\t\t10) Stergerea unui imobil" << endl;
    cout << "\t\t\t\t11) Stergerea unui agent" << endl;
    cout << endl << endl;
    cout << "\t\t\tCare este decizia dumneavoastra: ";
    cin >> n;
}
void meniu()
{
    int n;
    legenda(n);
    int sw = 0;
    while (sw != 1)
    {
        if (n == 1) AfisareDisponibil();
        else if (n == 2) AfisareJudet();
        else if (n == 3) AfisareOras();
        else if (n == 4) AfisareAgent();
        else if (n == 5) AfisareDupaMediu();
        else if (n == 6) AfisareIntrePret();
        else if (n == 7) Piata();
        ///////////////////////////////
        else if (n == 8)
        {
            if(ACCES()==1)
            InserareImobil();
            
        }
        else if (n == 9)
        {
            if (ACCES() == 1)
            InserareAgent();
        }
        else if (n == 10)
        {
            if (ACCES() == 1)
            StergereImobil();
        }
        else if (n == 11) 
        {
            if (ACCES() == 1)
            StergereAgent();
        }
        else if (n == 0) { ExitProgram(); sw = 1; }

        system("pause");
        system("cls");
        legenda(n);

    }
}


int main() 
{
    initializare();
        meniu();
        return 0;
}