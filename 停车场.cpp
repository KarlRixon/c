#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <malloc.h>

#define ClearScreen()  system( "cls" )// ����
#define Pause( szPrompt ) printf( "%s", szPrompt ),getch()// ��ʾ�ַ��� szPrompt,�ȴ��û����������

typedef struct carinformation    // ������Ϣ
{//����״̬��'A'Ϊ���'D'Ϊ�뿪��'G'��ʾ��ǰͣ�����ͱ��ʹ�������'E'Ϊ�������
 char RegistrationMark[64];   // ���ƺ�
 char ArrivalTime[16];    // ����ʱ��
 char EntranceTime[16];   // ����ͣ����(��ʼ�Ʒ�)ʱ��
 char DepartureTime[16];   // �뿪ʱ��
} TCARINFORMATION, *LPTCARINFORMATION;

typedef struct carstack
{
 LPTCARINFORMATION lpCarInformation;  // ������Ϣ  
 int Top;     // ջ��Ԫ���±�
 int StackSize;     // ջ����
} TCARSTACK, *LPTCARSTACK;

// ��ʼ��ջ lpCarStack, ������������Ϊ Size
void InitStack( LPTCARSTACK &lpCarStack, int Size )
{
 lpCarStack = ( LPTCARSTACK ) malloc( sizeof ( TCARSTACK ) );
 lpCarStack->lpCarInformation = ( LPTCARINFORMATION ) malloc(
 Size * sizeof ( TCARINFORMATION )
  );
 lpCarStack->Top = -1;
 lpCarStack->StackSize = Size;
}

// ������Ϣ carinfo ��ջ lpCarStack
void Push( LPTCARSTACK &lpCarStack, TCARINFORMATION carinfo )
{
 lpCarStack->Top++;
 lpCarStack->lpCarInformation[lpCarStack->Top] = carinfo;
}

// ������Ϣ��ջ lpCarStack �е��������� carinfo
void Pop( LPTCARSTACK &lpCarStack, TCARINFORMATION &carinfo )
{
 carinfo = lpCarStack->lpCarInformation[lpCarStack->Top];
 lpCarStack->Top--;
}

// ��ջ lpCarstack ��,���� TRUE;����,���� FALSE
BOOL IsStackEmpty( LPTCARSTACK lpCarStack )
{
 return lpCarStack->Top == -1;
}

// ��ջ lpStackFull ��,���� TRUE;����,���� FALSE
BOOL IsStackFull( LPTCARSTACK lpCarStack )
{
 return lpCarStack->Top == ( lpCarStack->StackSize - 1 );
}

// ����ջ lpCarStack,��ָ�� lpCarStack ��Ϊ NULL
void DestroyStack( LPTCARSTACK &lpCarStack )
{
 free( lpCarStack->lpCarInformation );
 free( lpCarStack );
 lpCarStack = NULL;
}

typedef struct carnode     // ���ӽ����Ϣ
{
 TCARINFORMATION carinfo;   // ������Ϣ
 struct carnode *lpNext;    // ָ����һ��Ԫ�ص�ָ��
} TCARNODE, *LPTCARNODE;

typedef struct carqueue     // ����
{
 LPTCARNODE lpHead;    // ͷ���
 LPTCARNODE lpRear;    // ָ��ǰ��β��ָ��
 int EffectiveSize;    // ��ǰ����Ԫ�ظ���
} TCARQUEUE, *LPTCARQUEUE;

// ��ʼ������ lpCarQueue
void InitQueue( LPTCARQUEUE &lpCarQueue )
{
 lpCarQueue = ( LPTCARQUEUE ) malloc( sizeof( TCARQUEUE ) );
 lpCarQueue->lpHead = ( LPTCARNODE) malloc( sizeof( TCARNODE ) );
 lpCarQueue->lpHead->lpNext = NULL;
 lpCarQueue->lpRear = lpCarQueue->lpHead;
 lpCarQueue->EffectiveSize = 0;
}

// ������Ϣ carinfo ������ lpCarQueue
void EnQueue( LPTCARQUEUE &lpCarQueue, TCARINFORMATION carinfo )
{
 LPTCARNODE lpCarNode = ( LPTCARNODE ) malloc( sizeof( carnode ) );
 lpCarNode->carinfo = carinfo;
 lpCarNode->lpNext = NULL;
 lpCarQueue->lpRear->lpNext = lpCarNode;
 lpCarQueue->lpRear = lpCarQueue->lpRear->lpNext;
 lpCarQueue->EffectiveSize++;
}

// ��ͷԪ�ش����� lpCarQueue �г��Ӳ����� carinfo
void DeQueue( LPTCARQUEUE &lpCarQueue, TCARINFORMATION &carinfo )
{
 LPTCARNODE lpTemp = lpCarQueue->lpHead->lpNext;
 carinfo = lpTemp->carinfo;
 lpCarQueue->lpHead->lpNext = lpTemp->lpNext;
 free( lpTemp );
 lpCarQueue->EffectiveSize--;
}

// ������ lpCarQueue Ϊ��,���� TRUE;����,���� FALSE
BOOL IsQueueEmpty( LPTCARQUEUE lpCarQueue )
{
 return lpCarQueue->EffectiveSize == 0;
}

// �������� lpCarQueue
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

// ���ַ���ʱ���ʽת��Ϊ����(����)��ʽ,���� 12:36 ����ת��Ϊ 756 ( 12 * 60 + 36 )
int ConvertTimeFormat( char *lpTime )
{
 int Hour = 0;
 int Minute = 0;

 sscanf( lpTime, "%d:%d", &Hour, &Minute );

return Hour * 60 + Minute;
}

// ������ͣ�����ڵ�ͣ��ʱ�� ContinuanceMinutes (����)�������
double CalculateExpense( int ContinuanceMinutes )
{
 return ContinuanceMinutes * ( 5.0 / 60 );
}

//������ 
int main( void )
{
 int ParkCapability = -1;   // ͣ��������

 putchar( '\n' );
 printf("|********************************************|\n");
 printf("|********                            ********|\n");   
 printf("|===========��ӭʹ��ͣ��������ϵͳ===========|\n");
 printf("|********                            ********|\n");  
 printf("|********************************************|\n");
 printf("����������������������������������������������\n\n\n\n");
 printf("������ͣ��������:");
 scanf( "%d", &ParkCapability) ;
 loop:if(ParkCapability>=0)   // ��֤ͣ��������Ϊһ������ 
     printf("OK,����ɹ���");
 else{
    printf("������Ҫ����һ�����֣�\n\n");
    printf("������ͣ��������:");
    fflush(stdin); 
	scanf( "%d", &ParkCapability) ; 
	goto loop ;
	} 

 LPTCARSTACK lpCarStack = NULL;   // ͣ����,��ջģ��
 InitStack( lpCarStack, ParkCapability );

 LPTCARQUEUE lpCarQueue = NULL;   // ���,������ģ��
 InitQueue( lpCarQueue );

 char CommandType = NULL;   // ��������
 char UserInput[128] = { NULL };  // �û�����
 do 
 {
  ClearScreen();
  putchar( '\n' );
  puts( "--------------------" );
  puts( "[��������]" );
  puts( "A - ��������" );
  puts( "D - �����뿪" );
  puts( "G - ��ʾ��ǰͣ�����ͱ��ʹ�����" );
  puts( "E - ��������" );
  putchar( '\n' );
  puts( "��:" );
  puts( "A,1,5" );
  puts( "D,5,20" );
  puts( "G,0,0" );
  puts( "E,0,0" );
  putchar( '\n' );
  printf( "����������:" );
  scanf( "%s", UserInput );

  char CarInformation[128] = { NULL };
  sscanf( UserInput,   // �����������복����Ϣ�ֿ����
   "%c,%s",
   &CommandType,   // �û������ǰ�벿��,����������
   CarInformation  // �û�����ĺ�벿��,��������Ϣ
   );

  char *lpCommaLocation = NULL;  // ������Ϣ�ַ����еĶ���λ��

  for ( lpCommaLocation = CarInformation; *lpCommaLocation != '\0'; lpCommaLocation++ )
  {
   if ( *lpCommaLocation == ',' )
   {
    break;
   }
  }
  *lpCommaLocation = '\0';
  
  TCARINFORMATION carinfo = { NULL }; // �洢�����û�����ĳ�����Ϣ
  
  strcpy( carinfo.RegistrationMark, CarInformation );

  if ( CommandType == 'A' )
  {
   strcpy( carinfo.ArrivalTime, lpCommaLocation + 1 );

   if ( FALSE == IsStackFull( lpCarStack ) )
   {
    strcpy( carinfo.EntranceTime, carinfo.ArrivalTime );
    Push( lpCarStack, carinfo );
    printf( "�ѽ���ͣ������ %d ����λ\n",
     lpCarStack->Top + 1
     );
    printf( "���ƺ�:\t\t%s\n", carinfo.RegistrationMark );
    printf( "����ʱ��:\t%s\n", carinfo.EntranceTime );
    puts( "�Ƿ��շ�:\t��" );
   }
   else
   {
    EnQueue( lpCarQueue, carinfo );
    printf( "ͣ��������,��ͣ���ڱ���ĵ� %d ����λ\n",
     lpCarQueue->EffectiveSize
     );
    printf( "���ƺ�:\t\t%s\n", carinfo.RegistrationMark );
    printf( "ͣ��ʱ��:\t%s\n", carinfo.ArrivalTime );
    puts( "�Ƿ��շ�:\t��" );
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
    printf( "���ƺ�Ϊ %s �ĳ�δ����ͣ��������Ҫ����.\n", carinfo.RegistrationMark );
    Pause( "--------------------\n�������������һ����Ϣ...\n" );
    continue;
   }

   strcpy( carinfoOut.DepartureTime, carinfo.DepartureTime );
   int EntranceTime = ConvertTimeFormat( carinfoOut.EntranceTime );
   int DepartureTime = ConvertTimeFormat( carinfoOut.DepartureTime );
   int ContinuanceMinutes = DepartureTime - EntranceTime; 
   if( ContinuanceMinutes>0)
   { printf( "�Ʒ�ʱ��:\t%s - %s (�� %d ����)\n",
    carinfoOut.EntranceTime,
    carinfoOut.DepartureTime,
    ContinuanceMinutes
    );
    
	double Expense = CalculateExpense( ContinuanceMinutes );
    printf( "Ӧ���ɵķ���:\t%.1lf Ԫ\n", Expense );
    
    if ( FALSE == IsQueueEmpty( lpCarQueue ) )
   {
    TCARINFORMATION tempcarinfo = { NULL };
    DeQueue( lpCarQueue, tempcarinfo );
    strcpy( tempcarinfo.EntranceTime, carinfoOut.DepartureTime );
    Push( lpCarStack, tempcarinfo );
    puts( "--------------------" );
    printf( "ͣ���ڱ���ĵ� 1 ����λ,���ƺ�Ϊ %s �ĳ��ѽ���ͣ����\n",
     tempcarinfo.RegistrationMark
    );
   }
   } 
     else{
  	 printf( "�뿪ʱ�������Ҫ��ȷ��ʱ�䣡\n" );
   } 
  }
  
  else if ( CommandType == 'G' )
  {
   ClearScreen();
   putchar( '\n' );
   puts( "[ͣ����ʹ�����]\n" );
   puts( "[��λ]\t[���ƺ�]\t[����ʱ��]\t[����(��ʼ�Ʒ�)ʱ��]\n");
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
   puts( "[���ʹ�����]\n" );
   puts( "[��λ]\t[���ƺ�]\t[����ʱ��]\t[����(��ʼ�Ʒ�)ʱ��]\n");
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
   puts( "������Ϣ����.��һ���ַ�ֻ��Ϊ 'A' �� 'D' �� 'G' ��'E' (ע�����ִ�Сд)." );
  }
  Pause( "--------------------\n�������������һ����Ϣ.\n" );
 } while ( TRUE ); 

 DestroyStack( lpCarStack );
 DestroyQueue( lpCarQueue );

 Pause( "\n��������˳�����...\n" );

 return 0;
}
