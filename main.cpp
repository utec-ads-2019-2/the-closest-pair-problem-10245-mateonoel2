#include <iostream>
#include <vector>
#include <cmath>
#include <float.h>
#include <iomanip>

using namespace std;

float distance(float x1,float y1, float x2, float y2){
    float z = 0;
    z = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    return z;
}

int main() {
    int x=0;
    while(cin>>x){
        if(x==0){
            break;
        }

        vector<pair<float, float>> points;

        float arr[x];
        float arr1[x];
        for(int i =0; i<x; i++){
            cin>>arr[i];
            cin>>arr1[i];
        }

        for (int i=0; i<x; i++) {
            points.push_back(make_pair(arr[i], arr1[i]));
        }

        float MinDistance = 10000;

        for (int i=0; i<x; i++){
            for(int j=0; j<x; j++){
                if(i!=j){
                    if(MinDistance > distance(points[i].first, points[i].second, points[j].first, points[j].second)){
                        MinDistance = distance(points[i].first, points[i].second, points[j].first, points[j].second);
                    }
                }
            }
        }

        if(MinDistance>9999){
            cout<<"INFINITY"<<'\n';
        }
        else{
            cout<< fixed << setprecision(4)<< MinDistance<<'\n';
        }
    }
    return 0;
}