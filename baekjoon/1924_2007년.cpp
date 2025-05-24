#include <iostream>
#include <cstdlib>
#include <string>

int main() {
    int x, y;
    std::cin >> x >> y;
   
    if(x==1 && y>=1 && y<=31){
        int day = y;
        int day_week = day % 7;
        switch (day_week) {

            case 1:
                std::cout << "MON" << std::endl;
                break;
            case 2:
                std::cout << "TUE" << std::endl;
                break;
            case 3:
                std::cout << "WED" << std::endl;
                break;
            case 4:
                std::cout << "THU" << std::endl;
                break;
            case 5:
                std::cout << "FRI" << std::endl;
                break;
            case 6:
                std::cout << "SAT" << std::endl;
                break;
            case 0:
                std::cout << "SUN" << std::endl;
                break;
        }
    }

    else if(x==2 && y>=1 && y<=28) {
        int day = 31 + y;
        int day_week = day % 7;
        switch (day_week){

            case 1:
                std::cout << "MON" << std::endl;
                break;
            case 2:
                std::cout << "TUE" << std::endl;
                break;
            case 3:
                std::cout << "WED" << std::endl;
                break;
            case 4:
                std::cout << "THU" << std::endl;
                break;
            case 5:
                std::cout << "FRI" << std::endl;
                break;
            case 6:
                std::cout << "SAT" << std::endl;
                break;
            case 0:
                std::cout << "SUN" << std::endl;
                break;
        }
    }

    else if(x==3 && y>=1 && y<=31) {
        int day = 31+28+y;
        int day_week = day % 7;
        switch (day_week) {

            case 1:
                std::cout << "MON" << std::endl;
                break;
            case 2:
                std::cout << "TUE" << std::endl;
                break;
            case 3:
                std::cout << "WED" << std::endl;
                break;
            case 4:
                std::cout << "THU" << std::endl;
                break;
            case 5:
                std::cout << "FRI" << std::endl;
                break;
            case 6:
                std::cout << "SAT" << std::endl;
                break;
            case 0:
                std::cout << "SUN" << std::endl;
                break;
        }
    }

    else if(x==4 && y>=1 && y<=30) {
        int day = 31+28+31+y;
        int day_week = day % 7;
        switch (day_week) {

            case 1:
                std::cout << "MON" << std::endl;
                break;
            case 2:
                std::cout << "TUE" << std::endl;
                break;
            case 3:
                std::cout << "WED" << std::endl;
                break;
            case 4:
                std::cout << "THU" << std::endl;
                break;
            case 5:
                std::cout << "FRI" << std::endl;
                break;
            case 6:
                std::cout << "SAT" << std::endl;
                break;
            case 0:
                std::cout << "SUN" << std::endl;
                break;
        }
    }    
    else if(x==5 && y>=1 && y<=31) {
        int day = 31+28+31+30+y;
        int day_week = day % 7;
        switch (day_week){

            case 1:
                std::cout << "MON" << std::endl;
                break;
            case 2:
                std::cout << "TUE" << std::endl;
                break;
            case 3:
                std::cout << "WED" << std::endl;
                break;
            case 4:
                std::cout << "THU" << std::endl;
                break;
            case 5:
                std::cout << "FRI" << std::endl;
                break;
            case 6:
                std::cout << "SAT" << std::endl;
                break;
            case 0:
                std::cout << "SUN" << std::endl;
                break;
        }
    }    
    else if(x==6 && y>=1 && y<=30) {
        int day = 31+28+31+30+31+y;
        int day_week = day % 7;
        switch (day_week) {

            case 1:
                std::cout << "MON" << std::endl;
                break;
            case 2:
                std::cout << "TUE" << std::endl;
                break;
            case 3:
                std::cout << "WED" << std::endl;
                break;
            case 4:
                std::cout << "THU" << std::endl;
                break;
            case 5:
                std::cout << "FRI" << std::endl;
                break;
            case 6:
                std::cout << "SAT" << std::endl;
                break;
            case 0:
                std::cout << "SUN" << std::endl;
                break;
        }
    }
    else if(x==7 && y>=1 && y<=31) {
        int day = 31+28+31+30+31+30+y;
        int day_week = day % 7;
        switch (day_week) {

            case 1:
                std::cout << "MON" << std::endl;
                break;
            case 2:
                std::cout << "TUE" << std::endl;
                break;
            case 3:
                std::cout << "WED" << std::endl;
                break;
            case 4:
                std::cout << "THU" << std::endl;
                break;
            case 5:
                std::cout << "FRI" << std::endl;
                break;
            case 6:
                std::cout << "SAT" << std::endl;
                break;
            case 0:
                std::cout << "SUN" << std::endl;
                break;
        }
    }
    else if(x==8 && y>=1 && y<=31) {
        int day = 31+28+31+30+31+30+31+y;
        int day_week = day % 7;
        switch (day_week){

            case 1:
                std::cout << "MON" << std::endl;
                break;
            case 2:
                std::cout << "TUE" << std::endl;
                break;
            case 3:
                std::cout << "WED" << std::endl;
                break;
            case 4:
                std::cout << "THU" << std::endl;
                break;
            case 5:
                std::cout << "FRI" << std::endl;
                break;
            case 6:
                std::cout << "SAT" << std::endl;
                break;
            case 0:
                std::cout << "SUN" << std::endl;
                break;
        }
    }

    else if(x==9 && y>=1 && y<=30) {
        int day = 31+28+31+30+31+30+31+31+y;
        int day_week = day % 7;
        switch (day_week){

            case 1:
                std::cout << "MON" << std::endl;
                break;
            case 2:
                std::cout << "TUE" << std::endl;
                break;
            case 3:
                std::cout << "WED" << std::endl;
                break;
            case 4:
                std::cout << "THU" << std::endl;
                break;
            case 5:
                std::cout << "FRI" << std::endl;
                break;
            case 6:
                std::cout << "SAT" << std::endl;
                break;
            case 0:
                std::cout << "SUN" << std::endl;
                break;
        }
    }
    else if(x==10 && y>=1 && y<=31) {
        int day = 31+28+31+30+31+30+31+31+30+y;
        int day_week = day % 7;
        switch (day_week) {

            case 1:
                std::cout << "MON" << std::endl;
                break;
            case 2:
                std::cout << "TUE" << std::endl;
                break;
            case 3:
                std::cout << "WED" << std::endl;
                break;
            case 4:
                std::cout << "THU" << std::endl;
                break;
            case 5:
                std::cout << "FRI" << std::endl;
                break;
            case 6:
                std::cout << "SAT" << std::endl;
                break;
            case 0:
                std::cout << "SUN" << std::endl;
                break;
        }
    }
    else if(x==11 && y>=1 && y<=30) {
        int day = 31+28+31+30+31+30+31+31+30+31+y;
        int day_week = day % 7;
        switch (day_week) {

            case 1:
                std::cout << "MON" << std::endl;
                break;
            case 2:
                std::cout << "TUE" << std::endl;
                break;
            case 3:
                std::cout << "WED" << std::endl;
                break;
            case 4:
                std::cout << "THU" << std::endl;
                break;
            case 5:
                std::cout << "FRI" << std::endl;
                break;
            case 6:
                std::cout << "SAT" << std::endl;
                break;
            case 0:
                std::cout << "SUN" << std::endl;
                break;
        }
    }
    else if(x==12 && y>=1 && y<=31) {
        int day = 31+28+31+30+31+30+31+31+30+31+30+y;
        int day_week = day % 7;
        switch (day_week) {

            case 1:
                std::cout << "MON" << std::endl;
                break;
            case 2:
                std::cout << "TUE" << std::endl;
                break;
            case 3:
                std::cout << "WED" << std::endl;
                break;
            case 4:
                std::cout << "THU" << std::endl;
                break;
            case 5:
                std::cout << "FRI" << std::endl;
                break;
            case 6:
                std::cout << "SAT" << std::endl;
                break;
            case 0:
                std::cout << "SUN" << std::endl;
                break;
        }
    }
    else
    {
        std::cout << "wrong month or date"<< std::endl;
    }
    
    return 0;
}
