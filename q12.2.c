//2. Monte Carlo Simulation for Estimating p
//This algorithm estimates p by simulating random points inside a square and counting how many fall inside 
//a quarter circle.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int totalPoints = 1000000;
    int insideCircle = 0;

    srand(time(0));

    for (int i = 0; i < totalPoints; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1) {
            insideCircle++;
        }
    }

    double piEstimate = 4.0 * insideCircle / totalPoints;
    printf("Estimated value of p: %f\n", piEstimate);

    return 0;
}

