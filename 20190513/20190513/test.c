#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include <windows.h>
//定义及初始化
struct Student
{
	char name[200000];
	int age;
};
void Show(struct Student s )
{
	printf("%s,%d\n",s.name,s.age);
}
void Show2(struct Student *ps)
{
	printf("%s,%d\n",ps->name,ps->age);
}
int main()
{
	struct Student stu = {"bit",10};

	int time = 0;
	int time2 = 0;
	int start = 0;
	int end = 0;
	int i = 0;
	start = GetTickCount();
	for(i = 0;i < 100000;i++)
	{
		Show(stu);
	}
	end = GetTickCount();
	time = end-start;
	printf("%d\n",time);
	start = GetTickCount();
	for(i = 0;i < 100000;i++)
	{
		Show2(&stu);
	}
	end = GetTickCount();
	time2 = end-start;
	printf("%d\n",time2-time);
}

#if 0
/*
void *memcpy(void *dest,const void *src,
   int count 
);
count:字节数
*/
void *Mymemcpy(void *dest,const void *src,int count )
{
	void *ret = dest;
	while(count != 0)
	{
		*((char*)dest) = *((char*)src);
		((char*)dest)++;
		((char*)src)++;
		count--;
	}
	return ret;
}
void *Mymemmove(void *dest,const void *src, int count )
{
	void *p = dest;
	if(src > dest)
	{
		while(count != 0)
		{
			*((char*)dest) = *((char*)src);
			((char*)dest)++;
			((char*)src)++;
			count--;
		}
	}
	else
	{
		while(count--) 
		{
			 *((char*)dest+count)= *((char*)src+count);
			//count--;
		}
	}
	return p;
}
void *Mymemmove2(void *dest,void *src,int count)
{
	void *ret = dest;
	if(dest < src)
	{
		while(count--)
		{
			*(char*)dest = *(char *)src;
			((char*)dest)++;
			((char*)src)++;
		}
	}
	else
	{
		while(count--)
		{
			*((char*)dest+count) = *((char*)src+count);
		}
	}
	return ret;
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int arr2[10] = {0};
	//Mymemmove(arr+2,arr,16);
	//Mymemcpy(arr,arr+2,16);
	//内存拷贝函数
	int*p = (int *)Mymemcpy(arr2,arr,16);
	//int*p = (int *)memcpy(arr2,arr,16);
	int i = 0;
	for(i = 0;i < 10;i++)
	{
		printf("%d ",p[i]);//*(p+i)
	}
	return 0;
}



char *Mystrcpy(char *dest,const char *src)
{
	/*char *p = dest;
	while(*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return p;   0' '\0' 0 NULL*/ 
	char *p = dest;
	while(*dest++ = *src++){}
	return p;
}
char *Mystrcat(char *dest,const char *src)
{
	char *p = dest;
	assert(dest!= NULL && src != NULL);
	while(*dest != '\0')
	{
		dest++;
	}
	//dest指向了\0
	while(*dest++ = *src++){}
	return p;
}
//
char *Mystrncat(char *dest,const char *src,int n)
{
	return NULL;
}

char *Mystrncpy(char *dest,const char *src,int n)
{return NULL;}
const char *Mystrstr1 (const char *str1,const char *str2 )
{
	while(*str1 != '\0')
	{
		const char *p = str1;
		while(*str1!= '\0' && *str2 != '\0'&&*str1 == *str2)
		{
			str1++;
			str2++;
		}
		if(*str1 == '\0')
		{
			return NULL;
		}
		if(*str2 == '\0')
		{
			return p;
		}
		str1++;
	}
	return NULL;
}
//朴素算法--      KMP--
const char *Mystrstr (const char *str1,const char *str2 )
{
	const char *s1 = NULL;
	const char *s2 = NULL;
	const char *start = str1;
	while(*start != '\0')
	{
		s1 = start;//s1回退到上一次的下一个位置
		s2 = str2;//s2回退到str2的起始位置
		while(*s1!= '\0' && *s2 != '\0'&&*s1 == *s2)
		{
			s1++;
			s2++;
		}
		if(*s1 == '\0')
		{
			return NULL;
		}
		if(*s2 == '\0')
		{
			return start;
		}
		start++;
	}
	return NULL;
}
const char *Mystrchr(const char *src,char ch)
{
	while(*src != '\0')
	{
		if(*src == ch)
		{
			return src;
		}
		src++;
	}
	return NULL;
}
//str1和str2比较  
int Mystrncmp(const char *str1, const char *str2,int n)
{}
int Mystrcmp(const char *str1, const char *str2)
{
	//ab       abc      abc     ab
	while(*str1 == *str2)
	{
		if(*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if(*str1 > *str2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int main()
{
	char *dest= "abc";//主串
	char *src = "abc";//子串
	printf("%d\n",strncmp("abcd","abcd",3));//0
	printf("%d\n",strncmp("abde","abce",1));//0
	printf("%d\n",strncmp("abce","adcd",3));//-1
	//printf("%s\n",Mystrstr(dest,src));

	//printf("%s\n",strncpy(dest,src,6));
	//printf("%s\n",strncat(dest,src,3));
	return 0;
}


int main()
{
	int money = 0;
	int empty = 0;
	int total = 0;
	scanf("%d",&money);
	total = money;
	empty = money;
	while(empty > 1)
	{
		total += empty/2;
		empty = empty/2+empty%2;
	}
	printf("%d\n",total);
	return 0;
}

void Fun(int *px,int *py)
{

}
int main()
{
	int x =0;
	int y = 0;
	Fun(&x,&y);

	return 0;
}

int main()
{
	int arr[] = {2,4,3,6,3,2,5,5};
	int len = sizeof(arr)/sizeof(arr[0]);
	//1、异或数组中的所有数字
	int i = 0;
	int num = 0;
	int pos = 0;//pos用来保存第i位为1的位置
	int x = 0;
	int y = 0;
	for(i = 0;i < len;i++)
	{
		//num = num^arr[i];
		num ^= arr[i];
	}
	//2、num肯定是异或的结果。
	//--->找到num二进制第一位为1的位数
	
	for(i = 0;i < 32;i++)
	{
		if(((num>>i) & 1)  == 1)
		{
			pos = i;
			break;
		}
	}
	//3、遍历数组，分为两个子数组
	for(i = 0;i < len;i++)
	{
		if(((arr[i]>>pos) & 1) == 1)
		{
			x ^= arr[i];
		}
		else
		{
			y ^= arr[i];
		}
	}
	printf("%d,%d\n",x,y);
	return 0;
}
#endif