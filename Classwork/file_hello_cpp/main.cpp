#include <fstream>

using namespace std;

int main()
{
    ofstream fout;
    fout.open("sample.txt");
    fout <<"zu" <<5<<"+"<<9<<endl;
    fout.close();
    return 0;
}
