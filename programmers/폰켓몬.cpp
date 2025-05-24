#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int cnt = 0;

    vector<bool> pokemon_list;
    pokemon_list.assign(200001, false);

    for (size_t i = 0; i < nums.size(); i++) {
        if (!pokemon_list[nums[i]] && cnt < nums.size()/2) {
            pokemon_list[nums[i]] = true;
            answer++;
            cnt++;
        }
        else if (cnt == nums.size()/2) {
            return answer;
        }
    }
    return answer;
}