// ex3.cpp -- placement new
#include <iostream>
#include <new>


struct chaff
{
    char dross[20];
    int slag;
};


void chaff_set(chaff& ch, const char* dross, int slag);
void chaff_show(const chaff& ch);


const int BUF = 512;
char buffer[BUF];
const int N = 2;

int main()
{
    using namespace std;

    char* newbuff = new char[BUF];

    chaff *pc1;
    chaff *pc2;
    cout << "Calling placement new:\n";
    pc1 = new(buffer) chaff[N];
    pc2 = new(newbuff) chaff[N];

    const char* names[N] = {"Name_1", "Name_2"};

    chaff* chaffs[] = {pc1, pc2, nullptr};
    
    for(chaff** ppchaff=chaffs; *ppchaff != nullptr; ++ppchaff){
        for(int i=0; i<N; ++i){
            chaff_set((*ppchaff)[i],names[i], i+1);
        }
    }

    for(chaff** ppchaff=chaffs; *ppchaff != nullptr; ++ppchaff){
        for(int i=0; i<N; ++i){
            chaff_show((*ppchaff)[i]);
        }
    }

    // for(int i=0; i<2; ++i){
    //     for(int j=0; j<N; ++j){
    //         chaff_set(chaffs[i][j], names[j], j+i);
    //     }
    // }
    // for(int i=0; i<2; ++i){
    //     for(int j=0; j<N; ++j){
    //         chaff_show(chaffs[i][j]);
    //     }
    // }

    delete[] newbuff;

    return 0;
}


void chaff_set(chaff& ch, const char* dross, int slag)
{
    int i{0};
    for(; i<20 && dross[i]; ++i){
        ch.dross[i] = dross[i];
    }
    for(; i<20; ++i){
        ch.dross[i] = '\0';
    }

    ch.slag = slag;
}

void chaff_show(const chaff& ch)
{
    std::cout << "Dross: " << ch.dross
              << ", Slag: " << ch.slag
              << std::endl;
}
