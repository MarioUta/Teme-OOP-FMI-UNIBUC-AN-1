#include <iostream>
#include <cmath>

using namespace std;

////Clasa Complex este in mare parte cea de la laboator, diferenta este ca am adaugat o functie swap si am modificat operatorii << si >>, mai jos arat cum le-am modificat;

class Complex {
    double real;
    double imaginary;
public:
    //constructori init
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {
//        std::cout << "S-a apelat constructorul cu doi parametri" << std::endl;
    }

    Complex(double real) : imaginary(0) { this->real = real; }

    Complex() : real(0), imaginary(0) {}

    //constructor copiere
    Complex(const Complex &c) {
        real = c.real;
        imaginary = c.imaginary;
//        std::cout << "S-a apelat constructorul de copiere" << std::endl;
    }

    Complex &operator=(const Complex &c) {
        real = c.real;
        imaginary = c.imaginary;
        return *this;
    }

    double abs() {
        return sqrt(pow(real, 2) + pow(imaginary, 2));
    }

//    Complex operator=(Complex c) {
//        real = c.real; imaginary = c.imaginary;
//        return *this;
//    }
    //destructor
    ~Complex() {
//        std::cout << "S-a apelat destructorul" << std::endl;
    }

    //setter
    void SetReal(double real) { this->real = real; }

    void SetImaginary(double imaginary) { this->imaginary = imaginary; }

    //getter
    double GetReal() { return real; }

    double GetImaginary() { return imaginary; }

    static void swap(Complex &c1, Complex &c2) {
        Complex c3;                                         //Functie care interschimba 2 numere complexe
        c3 = c1;
        c1 = c2;
        c2 = c3;
    }

    friend ostream &operator<<(std::ostream &output,
                               const Complex &c);             //Supraincarcarea operaturului << pentru clasa Complex

    //operatori
    friend Complex operator+(Complex c1, Complex c2) {
        double realRes = c1.real + c2.real;
        double imgRes = c1.imaginary + c2.imaginary;
        Complex result(realRes, imgRes);
        return result;
    }

    Complex operator*(Complex c2) {
        Complex result;
        result.real = real * c2.real - imaginary * c2.imaginary;
        result.imaginary = real * c2.imaginary + imaginary * c2.real;
        return result;
    }

};


ostream &operator<<(std::ostream &output, const Complex &c) {

    cout << c.real;
    if (c.imaginary != 0) {
        cout << "+" << c.imaginary << "*i";                         ///Afisarea usor diferita de laborator
    }
    return output;
}

istream &operator>>(std::istream &input, Complex &c) {

    double real, imaginary;
    cin >> real >> imaginary;                                       //Am folosit setteri in loc de in;
    c.SetReal(real);
    c.SetImaginary(imaginary);
    return input;
}

Complex operator/(Complex c1, Complex c2) {
    Complex temp(c2.GetReal(), -c2.GetImaginary());
    Complex result;
    result = c1 * temp;
    double absSquared = c2.GetReal() * c2.GetReal() + c2.GetImaginary() * c2.GetImaginary();
    result.SetReal(result.GetReal() / absSquared);
    result.SetImaginary(result.GetImaginary() / absSquared);
    return result;
}

class ComplexVector {

private:

    Complex *p;
    int size;

public:

    ComplexVector() : size(0) {
        p = new Complex[0];
    }

    //Nu folosim un Setter pentru pointerul p, nu vrem sa schimbam locatia din memorie a vectorului

    ComplexVector(const int size) : size(size) {
        p = new Complex[size];
    }

    ///void setSize(const int size) {
    ///    this->size = size;             //Nu folosim un setter pentru size, nu vrem sa schimbam marimea vectorului dupa declarare
    ///}

    ComplexVector(ComplexVector &v) {
        p = new Complex[v.getSize()];
        size = v.getSize();
        for (int i = 0; i < v.getSize(); i++)           //Constructorul de copiere pentru clasa Complex vector
        {
            p[i] = v.getLocation()[i];
        }
    }

    int getSize() const {
        return size;                        //Intoarce marimea vectorului
    }

    void setValues() {
        for (int i = 0; i < size; i++)      //Ii da valori Vectorului
            cin >> p[i];
    }

    Complex *getLocation() const {        //Intoarce adresa de memorie a vectorului
        return p;
    }

    ComplexVector ModuleVector() {
        ComplexVector mod(size);
        for (int i = 0; i < size; i++)
            mod.getLocation()[i] = p[i].abs();      //Construirea vectorului de module
        return mod;
    };

    void SortModule() {
        for (int i = 0; i < size; i++)
            for (int j = i; j < size; j++) {
                if (ModuleVector().getLocation()[i].GetReal() > ModuleVector().getLocation()[j].GetReal()) {
                    Complex::swap(ModuleVector().getLocation()[i],
                                  ModuleVector().getLocation()[j]);                                         //Metoda care sorteaza vectorul dupa module
                    Complex::swap(p[i], p[j]);
                }
            }
    }

    Complex Sum() {
        Complex s;
        for (int i = 0; i < size; i++)          //Metoda care calculeaza suma elementelor unui vector
            s = s + p[i];
        return s;

    }

    ComplexVector &operator=(ComplexVector const &v2) {
        if (v2.getLocation() != this->p) {
            delete[]p;
            this->size = v2.getSize();                          //Supraincarcarea operartotului '=' pentru clasa ComplexVector
            p = new Complex[v2.getSize()];
            for (int i = 0; i < v2.getSize(); i++) {
                p[i] = v2.getLocation()[i];
            }
        }
        return *this;
    }

    ComplexVector &operator+(ComplexVector &v2) {
        static ComplexVector v3(max(this->size, v2.size));
        for (int i = 0; i < min(this->size, v2.size); ++i) {
            v3.getLocation()[i] = p[i] + v2.getLocation()[i];
        }
        if (this->size >
            v2.size)                                           //Supraincarcarea operatoului '+' pentru clasa ComplexVector
            for (int i = v2.size; i < this->size; i++) {
                v3.getLocation()[i] = p[i];
            }
        else
            for (int i = this->size; i < v2.size; i++) {
                v3.getLocation()[i] = v2.getLocation()[i];
            }

        return v3;
    }

    friend ostream &
    operator<<(std::ostream &output, const ComplexVector &v); //Supraincarcarea operatorului '<<' pentru clasa ComplexVector

    friend istream &
    operator>>(std::istream &input, ComplexVector &v); //Supraincarcarea operatorului '>>' pentru clasa ComplexVector

    ~ComplexVector() {
        delete[] p;   //Destructorul
    }
};

ostream &operator<<(std::ostream &output, const ComplexVector &v) {
    for (int i = 0; i < v.getSize(); i++) {
        cout << v.getLocation()[i] << " ";
    }
    return output;
}

istream &operator>>(std::istream &input, ComplexVector &v) {
    for (int i = 0; i < v.getSize(); i++)
        cin >> v.getLocation()[i];
    return input;
}





ComplexVector *val;         //Vectorul unde se vor retine cele n obiecte complete cerute in cerinta comuna "functie (nu metoda) pentru citirea, memorarea si afisarea a n obiecte complete din clasa din subiect"

void CitireAfisareMemorare(int n){
    delete [] val;
    val= new ComplexVector[n];
    for (int i=0;i<n;i++)
    {
        cout<<"Introduce marimea vectorului:\n";            //functie (nu metoda) pentru citirea, memorarea si afisarea a n obiecte complete din clasa din subiect
        int m;
        cin>>m;
        ComplexVector vec(m);
        cout<<"Introduce valorile vectorului:\n";
        cin>>vec;
        val[i]=vec;
    }
    for (int i=0;i<n;i++)
    {
        cout<<val[i]<<'\n';
    }
}

//Functiile de mai jos pentru testing, cum se cere in cerinta "toate conceptele trebuie utilizate/testate "

void testSetter(ComplexVector &v)
{
    v.setValues();
    cout<<"Elementele vectorului sunt:\n";
    cout<<v;
}

void testGetteri(ComplexVector &v)
{
    cout<<"Locatia din memorie a vectorului:\n";
    cout<<v.getLocation()<<'\n';
    cout<<"Lunigimea vectorului:\n";
    cout<<v.getSize();
}

void testOperatoriAdunareEgal(ComplexVector&v1,ComplexVector&v2){
    cout<<"Vectorul de sume:\n"<<v1+v2<<'\n';
    v1=v2;
    cout<<"Vectorul v1 ia valoarea vectorului v2:\n"<<v1;

}

void testOperatoriInputOutput(ComplexVector &v)
{
    cout<<"Introduce valorile vectorului:\n";
    cin>>v;
    cout<<"Valorile vectorului sunt:\n"<<v;

}
void testVectorModule(ComplexVector &v)
{

    cout<<"Vectorul de module:\n"<<v.ModuleVector()<<'\n';//vectorul de module
    cout<<"Vectorul initial:\n"<<v;   //vectorul initial a ramas neschimbat
}

void testSortareVector(ComplexVector &v)
{
    cout<<"Vectorul inaite de sortare:\n"<<v<<'\n';
    cout<<"Vectorul de module:\n"<<v.ModuleVector()<<'\n';
    v.SortModule();
    cout<<"Vectorul dupa sortare:\n"<<v<<'\n';
}

void testSumaElementeVector(ComplexVector&v)
{
    cout<<"Suma elementelor vectorului este:\n"<<v.Sum();
}

int main() {

    ComplexVector v1(5),v2(3);
    cin>>v1;
    //CitireAfisareMemorare(2);
    //testGetteri(v1);
    //testSetter(v1);
    //testOperatoriAdunareEgal(v1,v2);         //Vectorii trebuie sa aiba n valori memorate.
    //testOperatoriInputOutput(v1);
    //testVectorModule(v1);                    //Vectorul trebuie sa aiba n valori memorate.
    //testSortareVector(v1);                   //Vectorul trebuie sa aiba n valori memorate.
    //testSumaElementeVector(v1);           //Vectorul trebuie sa aiba n valori memorate.
    delete []val;
    return 0;
}
