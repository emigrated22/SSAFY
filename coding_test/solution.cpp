#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int League_info[10][13331];
int Player_info[39991];
int League_num;
int Player_cnt;
// int temp_ability[39991];

int debug = 0;
void print_leag(){
    if(debug){
        cout<<"print League info for debug \n";
        for(int i = 0; i<League_num; i++){
            cout<<"League "<<i <<" (id)"<<endl;
            for(int j=0; j<Player_cnt/League_num; j++){
                cout<< League_info[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
void sort_L(){
    for(int i = 0; i<League_num; i++){
        sort(&League_info[i][0], &League_info[i][Player_cnt/League_num], [](int a, int b){
            if(Player_info[a] == Player_info[b]){
                return a < b;
            }
            return Player_info[a] > Player_info[b];
            });
    }

}
void init(int N, int L, int mAbility[])
{
    int player_num = 0;
    League_num = 0;
    Player_cnt = 0;
    // memset(League_info, 0, sizeof(League_info));
    // memset(Player_info, 0, sizeof(Player_info));
    for(int i = 0; i<L; i++){
        for(int j = 0; j<N/L; j++){
            League_info[i][j] = player_num;
            Player_info[player_num] = mAbility[player_num];
            player_num++;
        }
    }
    // for(int i = 0; i<N; i++){
    //     temp_ability[i] = mAbility[i];
    // }
    League_num = L;
    Player_cnt = N;
    // print_leag();
    sort_L();
    // print_leag();
}

int move()
{
    int Last_idx = Player_cnt / League_num - 1;
    int First_idx = 0;
    int ID_sum = 0;
    for(int league_num = 0; league_num < League_num - 1; league_num++){
        swap(League_info[league_num][Last_idx] , League_info[league_num + 1][0]);
        ID_sum += League_info[league_num][Last_idx] + League_info[league_num + 1][0];
    }
    // if(debug){
    //     cout<<"right after move"<<endl;
    //     print_leag();
    // }
    sort_L();
    // print_leag();
    return ID_sum;
}

int trade()
{
    int ID_sum = 0;
    int Middle_idx = (Player_cnt / League_num + 1) / 2 - 1;
    for(int league_num = 0; league_num < League_num - 1; league_num++){
        swap(League_info[league_num][Middle_idx],League_info[league_num + 1][0]);
        ID_sum += League_info[league_num][Middle_idx] + League_info[league_num + 1][0];
    }
    // if(debug){
    //     cout<<"right after trade"<<endl;
    //     print_leag();
    // }
    sort_L();
    // print_leag();
    return ID_sum;
}