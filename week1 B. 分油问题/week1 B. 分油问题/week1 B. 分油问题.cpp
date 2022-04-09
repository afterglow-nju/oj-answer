#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct oil
{
    int x, y, z;
    long long num;
};

vector<oil> v;
bool check(oil a)
{   
    bool flag = true;
    for (auto i : v)
    {
        if (i.x==a.x&&i.y==a.y&&i.z==a.z) { flag = false; break; }
    }
    return flag;
}

int main()
{   
    long long a, b, c,k,ans=INT_MAX;
    cin >> a >> b >> c >> k;
    oil t;
    t.x = a, t.y = 0, t.z = 0,t.num=0;
    queue<oil> q;
    q.push(t);
    v.push_back(t);
    bool f = false,add=true;
    oil tem;
    if (k > a)cout << "no";
    else
    {
        while (!q.empty() && (f == false))
        {
            oil i = q.front();
            q.pop();
            tem = i;
            if (tem.x >= b - tem.y) { tem.x = tem.x - b + tem.y; tem.y = b; }
            else { tem.y += tem.x; tem.x = 0; }
            if (tem.x == k || tem.y == k || tem.z == k) { tem.num++; f = true; ans = min(tem.num, ans); add = false; }
            if (check(tem)&& add) { tem.num++; v.push_back(tem); q.push(tem); }
            tem = i;

            if (tem.z >= b - tem.y) { tem.z = tem.z - b + tem.y; tem.y = b; }
            else { tem.y += tem.z; tem.z = 0; }
            if (tem.x == k || tem.y == k || tem.z == k) { tem.num++; f = true; ans = min(tem.num, ans);  add = false; }
            if (check(tem)&&add) { tem.num++; v.push_back(tem); q.push(tem); }
            tem = i;

            if (tem.x >= c - tem.z) { tem.x = tem.x - c + tem.z; tem.z = c; }
            else { tem.z += tem.x; tem.x = 0; }//唯物论，认识论，唯物辩证法，唯物史观//为什么马克思的哲学产生如此深远的影响，影响历史进程，改变世界版图的意识形态思想体系，//文科资深教授痛心疾首说人文和科学精神的分裂，院士则恰恰相反//人非工具or物or手段//人的理性不应该建立在经济理想上//马克思主义的目的 ：全人类的解放 从哪里解放出来？打工人的现象折射出来的社会心理//三大社会形式：1857,1858经济学收到 人的依赖性社会（原始社会、奴隶社会、封建社会）（血缘，家族共同体，宗法，师徒）结果：没有自由，每个人都能得到共同体的关心？
            //物的依赖性社会，（商品交换，法律）发达资本主义原则一钱二法律，人的独立性凸显，但被商品经济原则所支配，家族从宗法大家庭变成原子式的不稳定的小家庭，自由但联合//个体的自由不应该与共同体矛盾
            //1、什么是百年未有之大变局，中国特色社会主义进入新时代，什么是新时代
            //2、人，物依赖性，实际生活中的表现
            //电影：年轻的马克思，BBC世界天才马克思
            if (tem.x == k || tem.y == k || tem.z == k) { tem.num++; f = true; ans = min(tem.num, ans); add = false; }
            if (check(tem)&&add) { tem.num++; v.push_back(tem); q.push(tem); }
            tem = i;

            if (tem.y >= c - tem.z) { tem.y = tem.y - c + tem.z; tem.z = c; }
            else { tem.z += tem.y; tem.y = 0; }
            if (tem.x == k || tem.y == k || tem.z == k) { tem.num++; f = true; ans = min(tem.num, ans);  add = false; }
            if (check(tem)&&add) { tem.num++; v.push_back(tem); q.push(tem); }
            tem = i;

            if (tem.y >= a - tem.x) { tem.y = tem.y - a + tem.x; tem.x = a; }
            else { tem.x += tem.y; tem.y = 0; }
            if (tem.x == k || tem.y == k || tem.z == k) { tem.num++; f = true; ans = min(tem.num, ans); add = false;}
            if (check(tem)&&add) { tem.num++; v.push_back(tem); q.push(tem); }
            tem = i;

            if (tem.z >= a - tem.x) { tem.z = tem.z - a + tem.x; tem.x = a; }
            else { tem.x += tem.z; tem.z = 0; }
            if (tem.x == k || tem.y == k || tem.z == k) { tem.num++; f = true; ans = min(tem.num, ans); add = false; }
            if (check(tem)&&add) { tem.num++; v.push_back(tem); q.push(tem); }
        }
        if (f) cout << "yes" << '\n' << ans;
        else cout << "no";
    }
}


