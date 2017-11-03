#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <malloc.h>

#define ClearScreen()  system( "cls" )// 清屏
#define Pause( szPrompt ) printf( "%s", szPrompt ),getch()// 显示字符串 szPrompt,等待用户按下任意键

typedef struct carinformation    // 车辆信息
{//汽车状态，'A'为到达，'D'为离开，'G'显示当前停车场和便道使用情况，'E'为输入结束
 char RegistrationMark[64];   // 车牌号
 char ArrivalTime[16];    // 到达时间
 char EntranceTime[16];   // 进入停车场(开始计费)时间
 char DepartureTime[16];   // 离开时间
} TCARINFORMATION, *LPTCARINFORMATION;

typedef struct carstack
{
 LPTCARINFORMATION lpCarInformation;  // 车辆信息  
 int Top;     // 栈顶元素下标
 int StackSize;     // 栈容量
} TCARSTACK, *LPTCARSTACK;

// 初始化栈 lpCarStack, 将其容量设置为 Size
void InitStack( LPTCARSTACK &lpCarStack, int Size )
{
 lpCarStack = ( LPTCARSTACK ) malloc( sizeof ( TCARSTACK ) );
 lpCarStack->lpCarInformation = ( LPTCARINFORMATION ) malloc(
 Size * sizeof ( TCARINFORMATION )
  );
 lpCarStack->Top = -1;
 lpCarStack->StackSize = Size;
}

// 车辆信息 carinfo 入栈 lpCarStack
void Push( LPTCARSTACK &lpCarStack, TCARINFORMATION carinfo )
{
 lpCarStack->Top++;
 lpCarStack->lpCarInformation[lpCarStack->Top] = carinfo;
}

// 车辆信息从栈 lpCarStack 中弹出并存入 carinfo
void Pop( LPTCARSTACK &lpCarStack, TCARINFORMATION &carinfo )
{
 carinfo = lpCarStack->lpCarInformation[lpCarStack->Top];
 lpCarStack->Top--;
}

// 若栈 lpCarstack 空,返回 TRUE;否则,返回 FALSE
BOOL IsStackEmpty( LPTCARSTACK lpCarStack )
{
 return lpCarStack->Top == -1;
}

// 若栈 lpStackFull 满,返回 TRUE;否则,返回 FALSE
BOOL IsStackFull( LPTCARSTACK lpCarStack )
{
 return lpCarStack->Top == ( lpCarStack->StackSize - 1 );
}

// 销毁栈 lpCarStack,将指针 lpCarStack 置为 NULL
void DestroyStack( LPTCARSTACK &lpCarStack )
{
 free( lpCarStack->lpCarInformation );
 free( lpCarStack );
 lpCarStack = NULL;
}

typedef struct carnode     // 链队结点信息
{
 TCARINFORMATION carinfo;   // 车辆信息
 struct carnode *lpNext;    // 指向下一个元素的指针
} TCARNODE, *LPTCARNODE;

typedef struct carqueue     // 链队
{
 LPTCARNODE lpHead;    // 头结点
 LPTCARNODE lpRear;    // 指向当前队尾的指针
 int EffectiveSize;    // 当前队中元素个数
} TCARQUEUE, *LPTCARQUEUE;

// 初始化链队 lpCarQueue
void InitQueue( LPTCARQUEUE &lpCarQueue )
{
 lpCarQueue = ( LPTCARQUEUE ) malloc( sizeof( TCARQUEUE ) );
 lpCarQueue->lpHead = ( LPTCARNODE) malloc( sizeof( TCARNODE ) );
 lpCarQueue->lpHead->lpNext = NULL;
 lpCarQueue->lpRear = lpCarQueue->lpHead;
 lpCarQueue->EffectiveSize = 0;
}

// 车辆信息 carinfo 入链队 lpCarQueue
void EnQueue( LPTCARQUEUE &lpCarQueue, TCARINFORMATION carinfo )
{
 LPTCARNODE lpCarNode = ( LPTCARNODE ) malloc( sizeof( carnode ) );
 lpCarNode->carinfo = carinfo;
 lpCarNode->lpNext = NULL;
 lpCarQueue->lpRear->lpNext = lpCarNode;
 lpCarQueue->lpRear = lpCarQueue->lpRear->lpNext;
 lpCarQueue->EffectiveSize++;
}

// 队头元素从链队 lpCarQueue 中出队并存入 carinfo
void DeQueue( LPTCARQUEUE &lpCarQueue, TCARINFORMATION &carinfo )
{
 LPTCARNODE lpTemp = lpCarQueue->lpHead->lpNext;
 carinfo = lpTemp->carinfo;
 lpCarQueue->lpHead->lpNext = lpTemp->lpNext;
 free( lpTemp );
 lpCarQueue->EffectiveSize--;
}

// 若链队 lpCarQueue 为空,返回 TRUE;否则,返回 FALSE
BOOL IsQueueEmpty( LPTCARQUEUE lpCarQueue )
{
 return lpCarQueue->EffectiveSize == 0;
}

// 销毁链队 lpCarQueue
void DestroyQueue( LPTCARQUEUE &lpCarQueue )
{
 LPTCARNODE lpNextCarNode = NULL;
 for ( LPTCARNODE lpCarNode = lpCarQueue->lpHead; lpCarNode != NULL; lpCarNode = lpNextCarNode )
 {
  lpNextCarNode = lpCarNode->lpNext;
  free( lpCarNode );
 }
 free( lpCarQueue );
 lpCarQueue = NULL;
}

// 将字符串时间格式转换为数字(分钟)格式,例如 12:36 将被转换为 756 ( 12 * 60 + 36 )
int ConvertTimeFormat( char *lpTime )
{
 int Hour = 0;
 int Minute = 0;

 sscanf( lpTime, "%d:%d", &Hour, &Minute );

return Hour * 60 + Minute;
}

// 根据在停车场内的停留时间 ContinuanceMinutes (分钟)计算费用
double CalculateExpense( int ContinuanceMinutes )
{
 return ContinuanceMinutes * ( 5.0 / 60 );
}

//主程序 
int main( void )
{
 int ParkCapability = -1;   // 停车场容量

 putchar( '\n' );
 printf("|********************************************|\n");
 printf("|********                            ********|\n");   
 printf("|===========欢迎使用停车场管理系统===========|\n");
 printf("|********                            ********|\n");  
 printf("|********************************************|\n");
 printf("———————————————————————\n\n\n\n");
 printf("请输入停车场容量:");
 scanf( "%d", &ParkCapability) ;
 loop:if(ParkCapability>=0)   // 保证停车场容量为一个数字 
     printf("OK,输入成功！");
 else{
    printf("错误，需要输入一个数字！\n\n");
    printf("请输入停车场容量:");
    fflush(stdin); 
	scanf( "%d", &ParkCapability) ; 
	goto loop ;
	} 

 LPTCARSTACK lpCarStack = NULL;   // 停车场,用栈模拟
 InitStack( lpCarStack, ParkCapability );

 LPTCARQUEUE lpCarQueue = NULL;   // 便道,用链队模拟
 InitQueue( lpCarQueue );

 char CommandType = NULL;   // 命令类型
 char UserInput[128] = { NULL };  // 用户输入
 do 
 {
  ClearScreen();
  putchar( '\n' );
  puts( "--------------------" );
  puts( "[命令类型]" );
  puts( "A - 车辆到达" );
  puts( "D - 车辆离开" );
  puts( "G - 显示当前停车场和便道使用情况" );
  puts( "E - 结束操作" );
  putchar( '\n' );
  puts( "例:" );
  puts( "A,1,5" );
  puts( "D,5,20" );
  puts( "G,0,0" );
  puts( "E,0,0" );
  putchar( '\n' );
  printf( "请输入命令:" );
  scanf( "%s", UserInput );

  char CarInformation[128] = { NULL };
  sscanf( UserInput,   // 将命令类型与车辆信息分开存放
   "%c,%s",
   &CommandType,   // 用户输入的前半部分,即命令类型
   CarInformation  // 用户输入的后半部分,即车辆信息
   );

  char *lpCommaLocation = NULL;  // 车辆信息字符串中的逗号位置

  for ( lpCommaLocation = CarInformation; *lpCommaLocation != '\0'; lpCommaLocation++ )
  {
   if ( *lpCommaLocation == ',' )
   {
    break;
   }
  }
  *lpCommaLocation = '\0';
  
  TCARINFORMATION carinfo = { NULL }; // 存储本次用户输入的车辆信息
  
  strcpy( carinfo.RegistrationMark, CarInformation );

  if ( CommandType == 'A' )
  {
   strcpy( carinfo.ArrivalTime, lpCommaLocation + 1 );

   if ( FALSE == IsStackFull( lpCarStack ) )
   {
    strcpy( carinfo.EntranceTime, carinfo.ArrivalTime );
    Push( lpCarStack, carinfo );
    printf( "已进入停车场第 %d 个车位\n",
     lpCarStack->Top + 1
     );
    printf( "车牌号:\t\t%s\n", carinfo.RegistrationMark );
    printf( "进入时间:\t%s\n", carinfo.EntranceTime );
    puts( "是否收费:\t是" );
   }
   else
   {
    EnQueue( lpCarQueue, carinfo );
    printf( "停车场已满,已停放在便道的第 %d 个车位\n",
     lpCarQueue->EffectiveSize
     );
    printf( "车牌号:\t\t%s\n", carinfo.RegistrationMark );
    printf( "停放时间:\t%s\n", carinfo.ArrivalTime );
    puts( "是否收费:\t否" );
   }
  }
  else if ( CommandType == 'D' )
  {
   strcpy( carinfo.DepartureTime, lpCommaLocation + 1 );

   LPTCARSTACK lpTempCarStack = NULL;
   InitStack( lpTempCarStack, ParkCapability );
   
   TCARINFORMATION carinfoOut = { NULL };

   BOOL bIsCarFound = FALSE;
   while ( FALSE == IsStackEmpty( lpCarStack ) )
   {
    Pop( lpCarStack, carinfoOut );
    if ( 0 != strcmp( carinfoOut.RegistrationMark, carinfo.RegistrationMark ) )
    {
     Push( lpTempCarStack, carinfoOut );
    }
    else
    {
     bIsCarFound = TRUE;
     break;
    }
   }

   while ( FALSE == IsStackEmpty( lpTempCarStack ) )
   {
    TCARINFORMATION tempcarinfo = { NULL };
    Pop( lpTempCarStack, tempcarinfo );
    Push( lpCarStack, tempcarinfo );
   }

   if ( FALSE == bIsCarFound )
   {
    printf( "车牌号为 %s 的车未进入停车场或不需要交费.\n", carinfo.RegistrationMark );
    Pause( "--------------------\n按任意键输入下一条信息...\n" );
    continue;
   }

   strcpy( carinfoOut.DepartureTime, carinfo.DepartureTime );
   int EntranceTime = ConvertTimeFormat( carinfoOut.EntranceTime );
   int DepartureTime = ConvertTimeFormat( carinfoOut.DepartureTime );
   int ContinuanceMinutes = DepartureTime - EntranceTime; 
   if( ContinuanceMinutes>0)
   { printf( "计费时段:\t%s - %s (共 %d 分钟)\n",
    carinfoOut.EntranceTime,
    carinfoOut.DepartureTime,
    ContinuanceMinutes
    );
    
	double Expense = CalculateExpense( ContinuanceMinutes );
    printf( "应交纳的费用:\t%.1lf 元\n", Expense );
    
    if ( FALSE == IsQueueEmpty( lpCarQueue ) )
   {
    TCARINFORMATION tempcarinfo = { NULL };
    DeQueue( lpCarQueue, tempcarinfo );
    strcpy( tempcarinfo.EntranceTime, carinfoOut.DepartureTime );
    Push( lpCarStack, tempcarinfo );
    puts( "--------------------" );
    printf( "停放在便道的第 1 个车位,车牌号为 %s 的车已进入停车场\n",
     tempcarinfo.RegistrationMark
    );
   }
   } 
     else{
  	 printf( "离开时间错误，需要正确的时间！\n" );
   } 
  }
  
  else if ( CommandType == 'G' )
  {
   ClearScreen();
   putchar( '\n' );
   puts( "[停车场使用情况]\n" );
   puts( "[车位]\t[车牌号]\t[到达时间]\t[进入(开始计费)时间]\n");
   for ( int i = 0; i <= lpCarStack->Top; i++ )
   {
    printf( "%d\t%s\t\t%s\t\t%s\n",
     i + 1,
     lpCarStack->lpCarInformation[i].RegistrationMark,
     lpCarStack->lpCarInformation[i].ArrivalTime,
     lpCarStack->lpCarInformation[i].EntranceTime
     );
   }
   putchar( '\n' );
   putchar( '\n' );
   putchar( '\n' );
   puts( "[便道使用情况]\n" );
   puts( "[车位]\t[车牌号]\t[到达时间]\t[进入(开始计费)时间]\n");
   int Num = 0;
   for ( LPTCARNODE lpCarNode = lpCarQueue->lpHead->lpNext;
    lpCarNode != NULL; lpCarNode = lpCarNode->lpNext )
   {
    Num++;
    printf( "%d\t%s\t\t%s\t\t%s\n",
     Num,
     lpCarNode->carinfo.RegistrationMark,
     lpCarNode->carinfo.ArrivalTime,
     lpCarNode->carinfo.EntranceTime
    );
   }
   putchar( '\n' );
  }
  else if ( CommandType == 'E' )
  {
  break;
  } 
  else
  {
   puts( "输入信息有误.第一个字符只能为 'A' 或 'D' 或 'G' 或'E' (注意区分大小写)." );
  }
  Pause( "--------------------\n按任意键输入下一条信息.\n" );
 } while ( TRUE ); 

 DestroyStack( lpCarStack );
 DestroyQueue( lpCarQueue );

 Pause( "\n按任意键退出程序...\n" );

 return 0;
}
