#include <iostream>
#include <vector>

void DFS(std::vector<std::vector<int>> &map, std::vector<int> &reverse_pos_y, std::vector<int> &ret,
         int &dfs_ret, int tot_sum, int &sum, bool &found) {
    if (found) {
        return;
    }
    
    if ((reverse_pos_y.back() != map.size() && reverse_pos_y.back() != 1) &&
        map[map.size() - reverse_pos_y.back()][map.size() - reverse_pos_y.size()] == 0) {
        return;
    }

    if (sum == tot_sum/2 && tot_sum%2 == 0) {
        dfs_ret = sum;
        ret.clear();
        if (reverse_pos_y.size() != map.size()) {
            for (int i = 0; i < map.size() - reverse_pos_y.size(); i++) {
                ret.push_back(0);
            }
        }
        for (int i = 0; i < reverse_pos_y.size(); i++) {
            int size = reverse_pos_y.size();
            ret.push_back(reverse_pos_y[size-i-1]);
        }
        found = true;
        return;
    } else if (tot_sum%2 == 1 && (sum == tot_sum/2 || sum == tot_sum/2+1)) {
        dfs_ret = sum;
        ret.clear();
        if (reverse_pos_y.size() != map.size()) {
            for (int i = 0; i < map.size() - reverse_pos_y.size(); i++) {
                ret.push_back(0);
            }
        }
        for (int i = 0; i < reverse_pos_y.size(); i++) {
            int size = reverse_pos_y.size();
            ret.push_back(reverse_pos_y[size-i-1]);
        }
        found = true;
        return;
    }
    
    if ((tot_sum/2 - dfs_ret)*(dfs_ret - tot_sum/2) <= (tot_sum/2 - sum)*(sum-tot_sum/2)
             && (dfs_ret > sum || dfs_ret == 0 || sum > tot_sum/2)) {
        dfs_ret = sum;
        ret.clear();
        if (reverse_pos_y.size() != map.size()) {
            for (int i = 0; i < map.size() - reverse_pos_y.size(); i++) {
                ret.push_back(0);
            }
        }
        for (int i = 0; i < reverse_pos_y.size(); i++) {
            int size = reverse_pos_y.size();
            ret.push_back(reverse_pos_y[size-i-1]);
        }
    } else if (sum == tot_sum) {
        dfs_ret = sum;
        ret.clear();
        if (reverse_pos_y.size() != map.size()) {
            for (int i = 0; i < map.size() - reverse_pos_y.size(); i++) {
                ret.push_back(0);
            }
        }
        for (int i = 0; i < reverse_pos_y.size(); i++) {
            int size = reverse_pos_y.size();
            ret.push_back(reverse_pos_y[size-i-1]);
        }
    }
    
    if (reverse_pos_y.size() < map.size() && sum < tot_sum/2) {
        int pos_y = reverse_pos_y.back();
        for (int i = pos_y; i >= 1; i--) {
            int next_sum;
            for (int j = i; j >= 1; j--) {
                sum += map[map.size()-j][map.size() - reverse_pos_y.size()-1];
            }
            reverse_pos_y.push_back(i);
            DFS(map, reverse_pos_y, ret, dfs_ret, tot_sum, sum, found);
            for (int j = 1; j <= i; j++) {
                sum -= map[map.size()-j][map.size() - reverse_pos_y.size()];
            }
            reverse_pos_y.pop_back();
            if (found) {
                break;
            }
        }
    }
}

int main()
{
    int size;
    int tot = 0;
    std::vector<std::vector<int>> map;
    std::vector<int> ret_pos;
    std::vector<int> reverse_h;
    int ret_sum = 0;
    bool found = false;
    
    std::cin >> size;
    
    for (int i = 0; i < size; i++) {
        std::vector<int> i_th_row;
        for (int j = 0; j < size; j++) {
            int elem;
            std::cin >> elem;
            tot += elem;
            i_th_row.push_back(elem);
        }
        map.push_back(i_th_row);
    }
    
    for (int i = size; i >= 1; i--) {
        int sum = 0;
        for (int j = 1; j <= i; j++) {
            sum += map[size-j][size-1];
        }
        reverse_h.push_back(i);
        DFS(map, reverse_h, ret_pos, ret_sum, tot, sum, found);
        reverse_h.pop_back();
    }
    
    if (tot-ret_sum > ret_sum) {
       std::cout << (tot - ret_sum - ret_sum) << std::endl; 
    } else {
        std::cout << (2*ret_sum - tot) << std::endl;
    }
    for (int i = 0; i < ret_pos.size(); i++) {
        std::cout << ret_pos[i] << ' ';
    }
    
    return 0;
}