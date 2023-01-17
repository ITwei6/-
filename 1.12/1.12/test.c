//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;//&arr取出的是整个数组的地址，用数组指针来接收
//	return 0;//但很少这样使用
//}
//void Print1(int arr[2][5], int row, int col)
//{
//	int i, j;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			printf("%d", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void Print2(int(*arr)[5], int row, int col)
//{
//	int i, j;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			printf("%d", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[2][5] = {1,2,3,4,5,6,7,8,9,10};
//	Print1(arr, 2, 5);
//	//arr数组名表示首元素的地址
//	//但是二维数组中arr表示二维数组第一行中的地址也就是一维数组的地址
//	//所以可以用数组指针来接收.
//	Print2(arr, 2, 5);
//	return 0;
//}


//void test(int arr[])//ok?
//{}
//void test(int arr[10])//ok?
//{}
//void test(int* arr)//ok?
//{}
//void test2(int* arr[20])//ok?
//{}
//void test2(int** arr)
//{
//}//
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test(arr);
//	test2(arr2);
//	return 0;
//}
//void test()
//{
//	printf("hehe\n");
//}
//int main()
//{
//	printf("%p\n", test);
//	printf("%p\n", &test);
//	return 0;
//}
//( *( void (*)() )0 )();
