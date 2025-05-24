#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int num_people;
    cin >> num_people;
    cin.ignore();
    
    int time_arr[num_people];
    string input;
    
    getline(cin, input);
    char *input_ch = (char*)malloc(input.size());
    char *each_ch;
    strcpy(input_ch, input.c_str());
    int i=0;
    for (each_ch = strtok(input_ch, " "); each_ch; each_ch=strtok(NULL, " "), i++) {
       if(sscanf(each_ch, "%d", &time_arr[i]) < 1)
           break;
    }
    free(input_ch);
    
    
    for (int i = 0; i < num_people; i++) {
        int temp, cur;
        temp = time_arr[i];
        for (int j=i; j < num_people; j++) {
            cur = time_arr[j];
            if (temp > cur) {
                time_arr[i] = cur;
                time_arr[j] = temp;
                temp = cur;
            }
        }
    }
    
    int ret = 0;
    for (int i = 0; i < num_people; i++) {
        ret += (num_people-i)*time_arr[i];
    }
    
    cout << ret;
    return 0;
    
}

