#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

float noise();
float profit(float eff1,float eff2);

int main()
{
    float effort1 = 2.0001;
    float effort2 = 2.0001;
    float profit1 = 2.0001;
    float profit2 = 2.0001;

    srand(time(NULL));
    for(int i = 0;i < 10000;i++){

        //Jeu1 :
        float noise2 = noise();
        float himprofit2 = profit(effort2*noise2,effort1);


        //Jeu2 :
        float noise1 = noise();
        float himprofit1 = profit(effort1*noise(),effort2);


        if(profit2 < himprofit1){
            effort2 = effort1*noise1;
        }

        if(profit1 < himprofit2){
            effort1 = effort2*noise2;
        }

        profit1 = profit(effort1,effort2);
        profit2 = profit(effort2,effort1);
        cout << "effort 1 : " << effort1 << " profit 1 : " << profit1 << " effort2 : " << effort2 << " profit 2 : " << profit2 << " himeffort : " << himprofit1 << " himeffort 2 : " << himprofit2 << " average : " << (himprofit1+himprofit2)/2 << endl;

    }

    return 0;
}


float noise(){
    return (1.0 + ((rand()%(101) - 50.0) / 100.0));
}

float profit(float eff1,float eff2){
    return 5*sqrt(eff1+eff2)-eff1*eff1;
}


