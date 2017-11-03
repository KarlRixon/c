#include<stdio.h>
void move(char getone,char putone)
{ printf("%c----->%c\n",getone,putone);
 } 
void hanoi(int n,char one,char two,char three)
{
	if(n==1)  move(one,three);
	else
	{  hanoi(n-1,one,three,two);
	   move(one,three);
	   hanoi(n-1,two,one,three);
	}
}
int main()
{  int m;
   printf("Input the number of disks:");
   scanf("%d",&m);
   printf("The steps to moving %3d disks:\n",m);
   hanoi(m,'A','B','C'); 

}
/*现在再来看汉诺塔问题就容易理解了，剧本是这样的，n层的盘子对上面的盘子说：
你们全部挪到B柱，我再挪到C柱，然后你们再过来不就行了么。n-1 层的盘子说：你说
的简单，每次只能挪1个盘呀，我们怎样全部挪到B柱？n层盘子说：笨蛋，反正我最大，
你们尽管放在我上面木有问题，你们完全可以无视我的 存在。这样你们n-1个盘全部挪到
B柱，与我们n个盘全部挪到C柱所面临的问题不是一样的吗？都是移柱的问题呀，你们还比
我少了一个盘，问题复杂度还简化 了呢，你就照样画葫芦就行了。n-1层的盘说：哇塞！
说的对！上面n-2个盘听好了，我们现在要全部挪到B柱，你们n-2个盘先全部挪到C柱，我
再挪到B 柱，然后你们再过来。这个对话一直往上传直到最顶层，问题简化为1个盘从A柱
挪到C柱。解决了这个问题，其它问题也就全解决了。*/
