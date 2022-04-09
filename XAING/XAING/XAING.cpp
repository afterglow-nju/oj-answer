#include<stdio.h>
#include<easyx.h>
#include<conio.h>
#include<Windows.h>

#include <windows.h>
#pragma  comment (lib,"Winmm.lib") //使用音乐播放库

/**********加载全局函数********/
void InitGame();
void RenderGame();
void UpdateGame();
bool isWin();
bool isFail();
/**********加载全局变量********/
IMAGE img[6];
char dir;
int index_Row, index_Col;
#define SPACE_LAND	0	//空地
#define SPACE_WALL	1	//墙
#define SPACE_BOX	2	//箱子
#define SPACE_MAN	3	//玩家
#define SPACE_AIM	4	//目的地
#define SPACE_BOX_ON_AIM	6	//箱子在目的地
#define SPACE_MAN_ON_AIM	7	//玩家在目的地

#define MAP_R 6  //地图行数 
#define MAP_C 12  //地图列数
//初始地图
int map[6][12] = {
	SPACE_LAND, SPACE_WALL, SPACE_WALL, SPACE_WALL, SPACE_WALL, SPACE_LAND, SPACE_LAND, SPACE_WALL, SPACE_WALL, SPACE_WALL, SPACE_WALL, SPACE_WALL,
	SPACE_WALL, SPACE_WALL, SPACE_LAND, SPACE_LAND, SPACE_WALL, SPACE_LAND, SPACE_LAND, SPACE_WALL, SPACE_LAND, SPACE_LAND, SPACE_LAND, SPACE_WALL,
	SPACE_WALL, SPACE_LAND, SPACE_LAND, SPACE_LAND, SPACE_WALL, SPACE_WALL, SPACE_WALL, SPACE_WALL, SPACE_BOX, SPACE_BOX, SPACE_LAND, SPACE_WALL,
	SPACE_WALL, SPACE_LAND, SPACE_LAND, SPACE_MAN, SPACE_BOX_ON_AIM, SPACE_AIM, SPACE_AIM, SPACE_AIM, SPACE_BOX, SPACE_LAND, SPACE_LAND, SPACE_WALL,
	SPACE_WALL, SPACE_WALL, SPACE_LAND, SPACE_LAND, SPACE_LAND, SPACE_LAND, SPACE_WALL, SPACE_LAND, SPACE_LAND, SPACE_LAND, SPACE_WALL, SPACE_WALL,
	SPACE_LAND, SPACE_WALL, SPACE_WALL, SPACE_WALL, SPACE_WALL, SPACE_WALL, SPACE_WALL, SPACE_WALL, SPACE_WALL, SPACE_WALL, SPACE_WALL, SPACE_LAND
};

int main()
{
	initgraph(50 * MAP_C, 50 * MAP_R);
	InitGame();				//加载游戏
	RenderGame();			//绘制游戏
	while (1)
	{
		UpdateGame();		//数据更新
		if (isWin())
		{
			MessageBox(GetHWnd(), L"恭喜你赢了", L"Vectory", MB_OK);
			break;
		}
		if (isFail())
		{
			MessageBox(GetHWnd(), L"抱歉你输了", L"Defeated", MB_OK);
			break;
		}
	}
	closegraph();
	return 0;
}

void InitGame()
{
	loadimage(&img[0], L"images/land.jpg", 50, 50);		//空地
	loadimage(&img[1], L"images/wall.jpg", 50, 50);		//墙
	loadimage(&img[2], L"images/BoxYellow.jpg", 50, 50);	//箱子
	loadimage(&img[3], L"images/ManDOWN1.jpg", 50, 50);	//人
	loadimage(&img[4], L"images/aim.jpg", 50, 50);		//目标
	loadimage(&img[5], L"images/BoxRed.jpg", 50, 50);	//箱子到达目的地

	mciSendString(L"open images/Music/back.mp3 alias back", nullptr, 0, nullptr);	//文件路径采用相对路径	alias 取别名
	mciSendString(_T("play back repeat"), 0, 0, 0);		//repeat循环播放
}

void RenderGame()
{
	BeginBatchDraw();		//开始画图	防闪屏
	//循环绘制地图




	//Todo Task1: 参考并修改以下代码，绘制整个游戏界面

	for (int y = 0; y < MAP_R; y++)		//循环每一行
	{
		for (int i = 0; i < MAP_C; i++)
		{
			if (map[y][i] == SPACE_LAND)
				putimage(i * 50, y * 50, &img[0]);
			else if (map[y][i] == SPACE_WALL)
				putimage(i * 50, y * 50, &img[1]);
			else if (map[y][i] == SPACE_MAN || map[y][i] == SPACE_MAN_ON_AIM)
				putimage(i * 50, y * 50, &img[3]);
			else if (map[y][i] == SPACE_BOX_ON_AIM)
				putimage(i * 50, y * 50, &img[5]);
			else if (map[y][i] == SPACE_AIM)
				putimage(i * 50, y * 50, &img[4]);
			else if (map[y][i] == SPACE_BOX)
				putimage(i * 50, y * 50, &img[2]);
		}
	}
	//End Todo Task1




	EndBatchDraw();			//结束绘图
}

void UpdateGame()
{
	//收到键盘输入
	if (kbhit())
	{
		//先找到所在小人位置
		for (int Row = 0; Row < MAP_R; Row++)
		{
			for (int Col = 0; Col < MAP_C; Col++)
			{
				if (map[Row][Col] == 3 || map[Row][Col] == 7)
				{
					index_Row = Row;
					index_Col = Col;
				}
			}
		}
		//接收键盘输入符号
		dir = getch();





		//Todo Task2: 参考并修改以下代码，当接收用户操作时更新数据

		switch (dir)
		{
			//注意→←↑↓对应的数字分别为77 75 72 80
		case 'w':
		case 72:
			if (map[index_Row - 1][index_Col] == 0 || map[index_Row - 1][index_Col] == 4)
			{
				//推箱人的上面是 空地 或者 目的地  --->直接上去
				map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
				map[index_Row - 1][index_Col] = map[index_Row - 1][index_Col] + 3;
			}
			else
			{
				if (map[index_Row - 1][index_Col] == SPACE_BOX && (map[index_Row - 2][index_Col] == SPACE_LAND))
				{
					map[index_Row - 2][index_Col] = SPACE_BOX;
					map[index_Row - 1][index_Col] = SPACE_MAN;
					map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
				}
				else
				{
					if (map[index_Row - 1][index_Col] == SPACE_BOX && map[index_Row - 2][index_Col] == SPACE_AIM)
					{
						map[index_Row - 2][index_Col] = SPACE_BOX_ON_AIM;
						map[index_Row - 1][index_Col] = SPACE_MAN;
						map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
					}
					else
					{
						if (map[index_Row - 1][index_Col] == SPACE_BOX_ON_AIM && map[index_Row - 2][index_Col] == SPACE_AIM)
						{
							map[index_Row - 2][index_Col] = SPACE_BOX_ON_AIM;
							map[index_Row - 1][index_Col] = SPACE_MAN_ON_AIM;
							map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
						}
						else
						{
							if (map[index_Row - 1][index_Col] == SPACE_BOX_ON_AIM && map[index_Row - 2][index_Col] == SPACE_LAND)
							{
								map[index_Row - 2][index_Col] = SPACE_BOX;
								map[index_Row - 1][index_Col] = SPACE_MAN_ON_AIM;
								map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
							}
						}
					}
				}

			}

			//|| map[index_Row - 2][index_Col] == SPACE_AIM
			break;
		case 'd':
		case 77:
			if (map[index_Row][index_Col + 1] == 0 || map[index_Row][index_Col + 1] == 4)
			{
				//推箱人的上面是 空地 或者 目的地  --->直接 right
				map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
				map[index_Row][index_Col + 1] = map[index_Row][index_Col + 1] + 3;
			}
			else
			{
				if (map[index_Row][index_Col + 1] == SPACE_BOX && (map[index_Row][index_Col + 2] == SPACE_LAND))
				{
					map[index_Row][index_Col + 2] = SPACE_BOX;
					map[index_Row][index_Col + 1] = SPACE_MAN;
					map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
				}
				else
				{
					if (map[index_Row][index_Col + 1] == SPACE_BOX && map[index_Row][index_Col + 2] == SPACE_AIM)
					{
						map[index_Row][index_Col + 2] = SPACE_BOX_ON_AIM;
						map[index_Row][index_Col + 1] = SPACE_MAN;
						map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
					}
					else
					{
						if (map[index_Row][index_Col + 1] == SPACE_BOX_ON_AIM && map[index_Row][index_Col + 2] == SPACE_AIM)
						{
							map[index_Row][index_Col + 2] = SPACE_BOX_ON_AIM;
							map[index_Row][index_Col + 1] = SPACE_MAN_ON_AIM;
							map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
						}
						else
						{
							if (map[index_Row][index_Col + 1] == SPACE_BOX_ON_AIM && map[index_Row][index_Col + 2] == SPACE_LAND)
							{
								map[index_Row][index_Col + 2] = SPACE_BOX;
								map[index_Row][index_Col + 1] = SPACE_MAN_ON_AIM;
								map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
							}
						}
					}
				}
			}
			break;
		case 's':
		case 80:
			if (map[index_Row + 1][index_Col] == 0 || map[index_Row + 1][index_Col] == 4)
			{
				//推箱人的上面是 空地 或者 目的地  --->直接xia
				map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
				map[index_Row + 1][index_Col] = map[index_Row + 1][index_Col] + 3;
			}
			else
			{
				if (map[index_Row + 1][index_Col] == SPACE_BOX && (map[index_Row + 2][index_Col] == SPACE_LAND))
				{
					map[index_Row + 2][index_Col] = SPACE_BOX;
					map[index_Row + 1][index_Col] = SPACE_MAN;
					map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
				}
				else
				{
					if (map[index_Row + 1][index_Col] == SPACE_BOX && map[index_Row + 2][index_Col] == SPACE_AIM)
					{
						map[index_Row + 2][index_Col] = SPACE_BOX_ON_AIM;
						map[index_Row + 1][index_Col] = SPACE_MAN;
						map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
					}
					else
					{
						if (map[index_Row + 1][index_Col] == SPACE_BOX_ON_AIM && map[index_Row + 2][index_Col] == SPACE_AIM)
						{
							map[index_Row + 2][index_Col] = SPACE_BOX_ON_AIM;
							map[index_Row + 1][index_Col] = SPACE_MAN_ON_AIM;
							map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
						}
						else
						{
							if (map[index_Row + 1][index_Col] == SPACE_BOX_ON_AIM && map[index_Row + 2][index_Col] == SPACE_LAND)
							{
								map[index_Row + 2][index_Col] = SPACE_BOX;
								map[index_Row + 1][index_Col] = SPACE_MAN_ON_AIM;
								map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
							}
						}
					}
				}
			}

			break;
		case 'a':
		case 75:
			if (map[index_Row][index_Col - 1] == 0 || map[index_Row][index_Col - 1] == 4)
			{
				//推箱人的上面是 空地 或者 目的地  --->直接left
				map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
				map[index_Row][index_Col - 1] = map[index_Row][index_Col - 1] + 3;
			}

			if (map[index_Row][index_Col - 1] == SPACE_BOX && (map[index_Row][index_Col - 2] == SPACE_LAND))
			{
				map[index_Row][index_Col - 2] = SPACE_BOX;
				map[index_Row][index_Col - 1] = SPACE_MAN;
				map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
			}
			else
			{
				if (map[index_Row][index_Col - 1] == SPACE_BOX && map[index_Row][index_Col - 2] == SPACE_AIM)
				{
					map[index_Row][index_Col - 2] = SPACE_BOX_ON_AIM;
					map[index_Row][index_Col - 1] = SPACE_MAN;
					map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
				}
				else
				{
					if (map[index_Row][index_Col - 1] == SPACE_BOX_ON_AIM && map[index_Row][index_Col - 2] == SPACE_AIM)
					{
						map[index_Row][index_Col - 2] = SPACE_BOX_ON_AIM;
						map[index_Row][index_Col - 1] = SPACE_MAN_ON_AIM;
						map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
					}
					else
					{
						if (map[index_Row][index_Col - 1] == SPACE_BOX_ON_AIM && map[index_Row][index_Col - 2] == SPACE_LAND)
						{
							map[index_Row][index_Col - 2] = SPACE_BOX;
							map[index_Row][index_Col - 1] = SPACE_MAN_ON_AIM;
							map[index_Row][index_Col] = map[index_Row][index_Col] - 3;
						}
					}
				}
			}

			break;
		}

		//End Todo Task2






		PlaySound(L"../images/Music/Boxmove.WAV", nullptr, SND_FILENAME | SND_ASYNC);
		RenderGame();	//绘制游戏
	}
}






//Todo Task3: 修改以下代码，判断游戏成功或失败
bool isWin()
{
	int num = 0;
	for (int Row = 0; Row < MAP_R; Row++)
	{
		for (int Col = 0; Col < MAP_C; Col++)
		{
			if (map[Row][Col] == SPACE_BOX_ON_AIM)
			{
				num++;
			}
		}
	}
	if (num == 4) return true;
	else return false;
}

bool isFail()
{
	bool f1 = false, f2 = false, f3 = false, f4 = false, f11 = false, f22 = false, f33 = false, f44 = false;
	for (int Row = 0; Row < MAP_R; Row++)
	{
		for (int Col = 0; Col < MAP_C; Col++)
		{
			int num = 0;
			f1 = false, f2 = false, f3 = false, f4 = false;
			if (map[Row][Col] == SPACE_BOX)
			{
				if (map[Row - 1][Col] == SPACE_WALL || map[Row - 1][Col] == SPACE_MAN) f1 = true;
				if (map[Row + 1][Col] == SPACE_WALL || map[Row + 1][Col] == SPACE_MAN) f2 = true;
				if (map[Row][Col - 1] == SPACE_WALL || map[Row][Col - 1] == SPACE_MAN) f3 = true;
				if (map[Row][Col + 1] == SPACE_WALL || map[Row][Col + 1] == SPACE_MAN) f4 = true;
				//		if (map[Row - 1][Col] == SPACE_WALL) f11 = true;
					//	if (map[Row + 1][Col] == SPACE_WALL) f22 = true;
						//if (map[Row][Col + 2] == SPACE_WALL) f33 = true;
						//if (map[Row][Col + 1] == SPACE_WALL) f44 = true;
						//int num = 0;
				if (f1) num++;
				if (f2) num++;
				if (f3) num++;
				if (f4) num++;
				if (num >= 3) { return true; break; }

			}
		}
	}
	return false;
}
//End 