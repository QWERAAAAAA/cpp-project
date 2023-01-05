#include <iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX_V 50  //最大顶点个数 
#define INFINITY 32767  //最大值 

typedef struct
{
	char* vexs[MAX_V]; //顶点向量 
	int arcs[MAX_V][MAX_V];  //邻接矩阵
	int vexnum,arcnum;  //图的当前顶点数和弧数 
}MGraph;

int CreateUDN(MGraph &G){
	//采用邻接矩阵表示法，构造无向图G
	int i=0,j=0;
	G.vexnum=15;
	G.arcnum=24;
	
	G.vexs[0]=(char *)"体育场"; 
	G.vexs[1]=(char *)"大会堂";
	G.vexs[2]=(char *)"图书馆";
	G.vexs[3]=(char *)"学术报告厅";
	G.vexs[4]=(char *)"实验楼";
	G.vexs[5]=(char *)"办公楼";
	G.vexs[6]=(char *)"教学楼";
	G.vexs[7]=(char *)"八角楼";
	G.vexs[8]=(char *)"第一饭堂";
	G.vexs[9]=(char *)"第二饭堂";
	G.vexs[10]=(char *)"隧道口";
	G.vexs[11]=(char *)"门诊楼";
	G.vexs[12]=(char *)"又康超市";
	G.vexs[13]=(char *)"GoGo新天地";
	G.vexs[14]=(char *)"宿舍";
	
	for(i=0;i<G.vexnum;i++){ //初始化路径长度 
		for(j=0;j<G.vexnum;j++){
			if(i==j){
				G.arcs[i][j]=0;
			}
			else{
				G.arcs[i][j]=INFINITY;
			}
		}
	}
	
	//为每一条边赋权
	G.arcs[0][1]=G.arcs[1][0]=420;
	G.arcs[0][3]=G.arcs[3][0]=500;
	G.arcs[0][2]=G.arcs[2][0]=400;
	G.arcs[1][2]=G.arcs[2][1]=80;
	G.arcs[1][3]=G.arcs[3][1]=150;
	G.arcs[2][3]=G.arcs[3][2]=150;
	G.arcs[3][4]=G.arcs[4][3]=150;
	G.arcs[4][5]=G.arcs[5][4]=270;
	G.arcs[4][7]=G.arcs[7][4]=300;
	G.arcs[5][7]=G.arcs[7][5]=80;
	G.arcs[2][6]=G.arcs[6][2]=400;
	G.arcs[4][6]=G.arcs[6][4]=200;
	G.arcs[6][7]=G.arcs[7][6]=350;
	G.arcs[2][8]=G.arcs[8][2]=880;
	G.arcs[6][8]=G.arcs[8][6]=400;
	G.arcs[6][10]=G.arcs[10][6]=200;
	G.arcs[6][9]=G.arcs[9][6]=700;
	G.arcs[10][9]=G.arcs[9][10]=100;
	G.arcs[12][5]=G.arcs[5][12]=1000;
	G.arcs[10][8]=G.arcs[8][10]=60;
	G.arcs[10][12]=G.arcs[12][10]=220;
	G.arcs[11][8]=G.arcs[8][11]=200;
	G.arcs[12][13]=G.arcs[13][12]=900;
	G.arcs[12][14]=G.arcs[14][12]=210;
	
	return 1;
}

void caidan(){
		printf("\t*********************************************************************************\t\n");
		printf("\t*                      广东外语外贸大学校园导航系统                             *\t\n");
		printf("\t*********************************************************************************\t\n");
		printf("\t*                                                                               *\t\n");
		printf("\t*                                                                               *\t\n");
		printf("\t*  1.修改地图                                                                   *\t\n");
		printf("\t*                                                                               *\t\n");
		printf("\t*  2.删除两景点间的距离信息                                                     *\t\n");
		printf("\t*                                                                               *\t\n");
		printf("\t*  3.邻接表查询                                                                 *\t\n");
		printf("\t*                                                                               *\t\n");
		printf("\t*  4.邻接矩阵查询                                                               *\t\n");
		printf("\t*                                                                               *\t\n");
		printf("\t*  5.输出从某地点出发，打卡所有点之后回到起点的经过地点序列，并求出所经历的路程 *\t\n");
		printf("\t*                                                                               *\t\n");
		printf("\t*  6.输出从指定点出发，到达图中所有点的最短距离                                 *\t\n");
		printf("\t*                                                                               *\t\n");
		printf("\t*  7.输出从指定的地点(起点)到达另一指定地点(终点)的最短距离，以及经过的地点     *\t\n");
		printf("\t*                                                                               *\t\n");
		printf("\t*  8.输出图中所有两点之间的最短距离                                             *\t\n");
		printf("\t*                                                                               *\t\n");
		printf("\t*  9.输出广东外语外贸平面图                                                     *\t\n");
		printf("\t*                                                                               *\t\n");
		printf("\t*  10.退出                                                                      *\t\n");
		printf("\t*********************************************************************************\t\n");
		printf("\n\n请选择你需要的功能，输入代号：\n");
}

//修改地图
void xiugai(MGraph &G,int x,int y,int z)
{
	if(x>G.vexnum || y>G.vexnum){
		cout<<"不存在此景点"<<endl;
	}
	else{
		G.arcs[x][y]=G.arcs[y][x]=z;	
	}
}

//删除两景点间的距离信息
void shanchu(MGraph &G,int x,int y)
{
	if(x>G.vexnum || y>G.vexnum){
		cout<<"不存在此景点"<<endl;
	}
	else{
		if(G.arcs[x][y] != INFINITY){
			G.arcs[x][y]=G.arcs[y][x]=INFINITY;
		}
		else{
			cout<<"两个景点间没有距离信息"<<endl;
		}	
	}
}

void print(MGraph G)
{
	
	for(int i=0;i<G.vexnum;i++)
	{
		
		for(int j=0;j<G.vexnum;j++)
		{
			if(G.arcs[i][j]==INFINITY)
			{
				cout<<0<<"\t";
			}
			else
			{
			   cout<<G.arcs[i][j]<<"\t";	
			}
			
		}
		cout<<endl;
	}
}

void print2(MGraph G)
{
	for(int i=0;i<G.vexnum;i++)
	{
		cout<<G.vexs[i];
		for(int j=0;j<G.vexnum;j++)
		{
			if(G.arcs[i][j]!=0)
			cout<<" ---> "<<G.vexs[j];
		}
		cout<<endl<<endl;
	}
}





int LocateVex_MGraph(MGraph &G,string v)
{
	for(int i=0;i<G.vexnum;i++)
	{
		if(G.vexs[i]==v) return i;
	}
}
int test(MGraph &G,int visited[])
{
	for(int i=0;i<G.vexnum;i++){
		if(visited[i]==0) return 0;
	} 
	return 1;
}
int Punch_in_All_Sport(MGraph &G,string *Node,int &k)
{
	int visited[G.vexnum];
	for(int i=0;i<G.vexnum;i++)
	{
		visited[i]=0;
	} 
	string StartPlace;
	cout << "请输入一个起点：";
	cin >> StartPlace;
	int StartNode=LocateVex_MGraph(G,StartPlace);
	int i=StartNode;
	string EndPlace;
	int j; 
	int dist; 
	
	Node[k]=G.vexs[i];visited[i]=1;k++;
	cout<<"还未经过的点有："<<endl; 
	for(int t=0;t<G.vexnum;t++)
	{
	    if(visited[t]==0) cout<<G.vexs[t]<<" ";
     }
    cout<<endl<<"可直接到达的点有："<<endl;
    for(int t=0;t<G.vexnum;t++)
     {
	    if(G.arcs[i][t]<INFINITY) cout<<G.vexs[t]<<" ";
	}
	cout<<endl<<endl<<"请输入下一个目的地：";
	while(cin>>EndPlace)
	{
		j=LocateVex_MGraph(G,EndPlace);
		if(j==StartNode)
		{
			if(G.arcs[i][j]!=INFINITY)
			{
				Node[k]=G.vexs[j];k++;
			    if(test(G,visited)==0)
			    {
				  dist=dist+G.arcs[i][j]; 
				  visited[j]==1;
				  i=j; 
		         }
		        else return dist;
			}
			else
			{
				cout<<"对不起，无法直接到达该点"; 
			}
		}
		else{
			if(G.arcs[i][j]!=INFINITY)
			{
			  Node[k]=G.vexs[j];k++;
			  dist=dist+G.arcs[i][j];
			  visited[j]=1;
			  i=j;				
			}
			else
			{
			  cout<<"对不起，无法直接到达该点"<<endl; 
			}
		} 
		cout<<"还未经过的点有："<<endl; 
		for(int t=0;t<G.vexnum;t++)
		{
			if(visited[t]==0) cout<<G.vexs[t]<<" ";
	     }
	    cout<<endl<<"可直接到达的点有："<<endl;
	    for(int t=0;t<G.vexnum;t++)
	     {
	    	if(G.arcs[i][t]<INFINITY) cout<<G.vexs[t]<<" ";
		}
		cout<<endl<<endl<<"请输入下一个目的地："; 
	} 

}



int ShortesPath_DIJ(MGraph &G, int v0)
{
	
	int S[100], D[100], Path[100];
	int i, v, w; 
	int n = G.vexnum;
	for(v=0; v<n; ++v)
	{
		S[v]=false;
		D[v]=G.arcs[v0][v];
		if(D[v]<INFINITY) Path[v]=v0;
		else Path[v]=-1;
	}
	S[v0]=true;
	D[v0]=0;
	for(i=1; i<n; ++i)
	{
		int min=INFINITY;
		for(w=0; w<n; ++w)
		{
			 if(!S[w]&&D[w]<min)
			 {
			 	v=w;
			 	min=D[w];
			 }
			 
		}
		S[v]=true;
		for(w=0; w<n; ++w)
		{
			if(!S[w]&&(D[v]+G.arcs[v][w]<D[w]))
			{
				D[w]=D[v]+G.arcs[v][w];
				Path[w]=v;
			 
			}
		}
	}
	cout<<"到其他点的最短路程分别为：";
	cout<<endl;
	for(w=0; w<=n; w++)
	{
		cout << D[w]<<endl; 
	}
}


void liebiao()			//景点列表 
{
	system("cls");			//清屏 
	printf("\n\n\n");
	printf("\t\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t\t * *                     *景点列表*                     * *\n");
	printf("\t\t\t\t\t * ****************************************************** *\n");
	printf("\t\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t\t * *  <0>体育场   <1>大会堂   <2>图书馆  <3>学术报告厅  * *\n");
	printf("\t\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t\t * *  <4>实验楼   <5>办公楼   <6>教学楼  <7>八角楼      * *\n");
	printf("\t\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t\t * *  <8>第一饭堂  <9>第二饭堂  <10>隧道口 <11>门诊楼   * *\n");
	printf("\t\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t\t * *  <12>又康超市     <13>GoGo新天地    <14>宿舍	* *\n");
	printf("\t\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t\t * ****************************************************** *\n");
	printf("\t\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
	printf("\n\n\n");
}
// 7.输出从指定的地(起点)到达另一指定地点(终点)的最短距离，以及经过的地点
void Dijkstra(int v0,int s,MGraph G)		//迪杰斯特拉求最短路径，并输出路线 
{
	int min,i,j,u,v;
	int p[110],l[110];
	int book[110],dis[110];
	memset(p,-1,sizeof(p));		// 初始化数组	数组p中每个元素赋值为-1、数组l和book赋值为0
	memset(l,0,sizeof(l));		
	memset(book,0,sizeof(book));
	for(i=0;i<=14;i++)
	{
		dis[i]=G.arcs[v0][i];
		if(dis[i]<INFINITY)			// v0能直接到达，即上一站点为v0 
			p[i]=v0;
	}
		
	book[v0]=1;		// 标记数组置1
	
	for(i=0;i<14;i++)
	{
		min=INFINITY;
		for(j=0;j<=14;j++)			// 每次找出距离v0最近点 
		{
			if(book[j]==0 && dis[j]<min)
			{
				min=dis[j];
				u=j;
			}
		}
		book[u]=1;			// 标记该点 
		for(v=0;v<=14;v++)
		{
			if(book[v]==0 && dis[v]>dis[u]+G.arcs[u][v])			 
			{
				p[v]=u;					
				dis[v]=dis[u]+G.arcs[u][v];		
			}
		}
	}
	v=s;
	i=1;
	while(p[v]!=v0)			//将路线存入栈中，正序输出 
	{
		
		l[i++]=p[v];
		v=p[v];
	}
	printf("\n");
	u=i-1;
	printf("路线为：\n");
	printf("%s--->",G.vexs[v0]);
	for(i=u;i>=1;i--)
		printf("%s--->",G.vexs[l[i]]); 
	printf("%s\n",G.vexs[s]);
	printf("最短路径长度为：%d 米\n",dis[s]);
}





void Floyd(MGraph G){
	int Path[100][100], D[100][100];
	for(int i=0;i<G.vexnum;++i){
		for(int j=0;j<G.vexnum;++j){
			D[i][j]=G.arcs[i][j];
			if(D[i][j]<INFINITY && i!=j) Path[i][j]=i;
			else Path[i][j]=-1;
		}
	}
	for(int k=0;k<G.vexnum;++k)
		for(int i=0;i<G.vexnum;++i)
			for(int j=0;j<G.vexnum;++j)
				if(D[i][k]+D[k][j]<D[i][j]){
					D[i][j] = D[i][k] + D[k][j];
					Path[i][j] = Path[k][j];
				}
	for(int i=0;i<G.vexnum;++i){
		for(int j=0;j<G.vexnum;++j){
			if(i==j)	break;
			else 
				cout<<G.vexs[i]<<"——>"<<G.vexs[j]<<"的最短路径为："<<D[i][j]<<endl;
		}
	}

}

void printpc()
{    cout<<"                                                                                                   "<<endl;
     cout<<"                                                                                                   "<<endl;
	cout<<"                                         *体育场                                                     "<<endl;
	cout<<"                                         / \\     \\                                                   "<<endl;
	cout<<"                                        /   \\     \\                                                  "<<endl;
	cout<<"                                       /    420    \\--500--\\                                         "<<endl;
	cout<<"                                      /       \\             \\                                        "<<endl;
	cout<<"                                    400   *大会堂--150--- *学术报告厅                                "<<endl;
	cout<<"                                    /       /                  /  \\                                  "<<endl;
	cout<<"                                   /    -80-                  /    150                               "<<endl;
	cout<<"                                  /    /                     /        \\                              "<<endl;
	cout<<"                                *图书馆 -------------150----/         *实验楼                        "<<endl;
	cout<<"                               /      \\                              /  /    \\                       "<<endl;
	cout<<"                              /        \\-400--\\     /------200------/  /      \\                      "<<endl;
	cout<<"                             /                 \\   /                 300       270                   "<<endl;
	cout<<"                *门诊楼    880                 教学楼                /           \\                   "<<endl;
	cout<<"                    \\      /                  /  / \\  \\             /             \\                  "<<endl;
	cout<<"                    200   /   /-----400------/  /   \\  \\--350-----*八角楼----80---*办公楼            "<<endl;
	cout<<"                      \\  /   /                 /     \\                              /                "<<endl;
	cout<<"                     *第一饭堂              200      700                           /                 "<<endl;
	cout<<"                            \\                /         \\                          /                  "<<endl;
	cout<<"                             \\--60--\\       /           \\                        /                   "<<endl;
	cout<<"              *GOGO新天地            \\     /             \\                      /                    "<<endl;
	cout<<"                    \\                 *隧道口----100----*第二饭堂              /                     "<<endl;
	cout<<"                     \\                   /                                  1000                     "<<endl;
	cout<<"                      \\--900--\\         /                                    /                       "<<endl;
	cout<<"                               \\      220                                   /                        "<<endl;
	cout<<"                                \\     /                                    /                         "<<endl;
	cout<<"                                 \\   /                                    /                          "<<endl;
	cout<<"                                *又康超市--------------------------------/                           "<<endl;
	cout<<"                                   /                                                                 "<<endl;
	cout<<"                                 210                                                                 "<<endl;
	cout<<"                                 /                                                                   "<<endl;
	cout<<"                              *宿舍                                                                  "<<endl;
	cout<<"                                                                                                   "<<endl;
	cout<<"                                                                                                   "<<endl;
	cout<<"                                                                                                   "<<endl;
}

int main(){
	MGraph G;
	CreateUDN(G);
	int n;
	while(true){
		caidan();
		cin>>n;
		switch(n){
			int x,y,z;
			case 1:{
				cout<<"请输入你要修改的两个景点的编号";
				cin>>x>>y;
				cout<<"请输入两景点间的距离信息";
				cin>>z;
				xiugai(G,x,y,z);
				break;
			}
			case 2:{
				cout<<"请输入你要删除的两个景点的编号";
				cin>>x>>y;
				shanchu(G,x,y); 
				break;
			} 
			case 3:
				{
					print2(G);
					break;
				}
			case 4:
				{
					print(G);
					break;
				}
			case 5:
				{
					string Node[MAX_V];//记录已经经过的顶点 
					int k=0;
					int dist=Punch_in_All_Sport(G,Node,k);
					for(int i=0;i<k-1;i++)
		                   cout<<Node[i]<<endl;
		               cout<<dist<<endl;
		               break;
				}
			case 6:
				{
					string StartPlace;
					cout<<"请输入起始地点：";
					cin>>StartPlace;
					int v0=LocateVex_MGraph(G,StartPlace);
					ShortesPath_DIJ(G,v0);
					break;
			     }
			case 7:
				{
					cout<<"查询任意两景点间的最短路径"<<endl;
					int n,m;
					liebiao();
					printf("请输入起点景点编号：\n");
					scanf("%d",&n);
					printf("\n请输入终点景点编号：\n");
					scanf("%d",&m);
					while(1)
					{
						if(n>=0&&n<=14&&m>=0&&m<=14&&n!=m)
						{
							Dijkstra(n,m,G);
							printf("\n\n按回车键返回至导航系统界面\n\n");
							getchar();getchar();
							void caidan();
							break;
						}
						else
						{
							printf("\n输入不合法！请重新输入！\n\n");
							printf("请输入起点景点编号：\n");
							scanf("%d",&n);
							printf("\n请输入终点景点编号：\n");
							scanf("%d",&m);
						}
					}
					break;
				}
				case 8:
					{
						cout<<"输出图中所有两点之间的最短距离"<<endl;
						Floyd(G);
					
					}
				case 9:
		    	          {
		    		          printpc();
				     }
			}
				
		}	
}

