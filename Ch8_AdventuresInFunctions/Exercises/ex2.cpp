// ex2.cpp
#include <iostream>


struct CandyBar
{
    const char* name;
    float weight;
    int calories;
};


void CandyBar_init(CandyBar& bar,
                   const char* name="Millennium Munch",
                   float weight=2.85,
                   int cal=350);
void CandyBar_show(const CandyBar& bar);

int main()
{
    CandyBar bars[5];
    const char* names[5] = {"Bar One", "Bar Two", "Bar Three", "Bar Four",
                            "Bar Five"
                            };
    for(int i=0; i<5; ++i){
        float w = i + 0.1;
        int cal = (i+111) * (i+1);
        CandyBar_init(bars[i], names[i], w, cal);
        CandyBar_show(bars[i]);
    }
}


void CandyBar_init(CandyBar& bar, const char* name, float weight, int cal)
{
    bar.name = name;
    bar.weight = weight;
    bar.calories = cal;
}

void CandyBar_show(const CandyBar& bar)
{
    std::cout << "Name: " << bar.name
              << "\nWeight: " << bar.weight
              << "\nCalories: " << bar.calories
              << '\n' << std::endl;
}
