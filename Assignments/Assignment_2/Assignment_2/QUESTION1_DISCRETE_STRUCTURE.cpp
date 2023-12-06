////DISCRETE FINAL PROJECT
//#include <iostream>
//#include <cmath>
//using namespace std;
//void cartesian(int arr1[100], int arr2[100], int s1, int s2);
//int relationnumber(int s1, int s2);
//void isreflexive(int arr1[20], int arr2[20], int s1, int s2);
//void issymmetric(int arr1[20], int arr2[20], int s1, int s2);
//int reflexiveno(int s1, int s2);
//int symmetricno(int s1, int s2);
//int antisymmetric(int s1, int s2);
////antisymmetric
//int main()
//{
//	int arr1[100], arr2[100];
//	int s1, s2;//size of set 
//	cout << "ENTER SIZE OF SET A : ";
//	cin >> s1;
//	cout << "ENTER THE SIZE OF SET B : ";
//	cin >> s2;
//	cout << "ENTER THE VALUE OF SET A : " << endl;//ASKING THE USER TO ENTER THE  VALUE OF SET A
//		for (int i = 0; i < s1; i++)
//		{
//			cout << "ENTER THE VALUE OF ELEMENT " << i + 1 << " : ";
//			cin >> arr1[i];
//		}
//	cout << endl;
//	cout << "ENTER THE VALUE OF SET 2 : " << endl;//ASKING THE USER TO ENTER THE VALUE OF SET B
//		for (int i = 0; i < s2; i++)
//		{
//			cout << "ENTER THE VALUE OF ELEMENT " << i + 1 << " : ";
//			cin >> arr2[i];
//		}
//	cout << endl;
//	system("cls");//CLEARING SCREEN TO DISPLAY SET 
//	cout << "SET A={";//DISPLAYING SET A IN SET FORMAT 
//	for (int i = 0; i < s1; i++)
//	{
//		if (i < s1 - 1)
//		{
//			cout << arr1[i] << ",";
//		}
//		else if (i == s1 - 1)
//		{
//			cout << arr1[i];
//		}
//	}
//	cout << "}" << endl << endl;
//	cout << "SET B={";//DISPLAYING SET B IN SET FORMAT 
//	for (int i = 0; i < s2; i++)
//	{
//		if (i < s2 - 1)
//		{
//			cout << arr2[i] << ",";
//		}
//		else if (i == s2 - 1)
//		{
//			cout << arr2[i];
//		}
//	}
//	cout << "}" << endl << endl;
//	cartesian(arr1, arr2, s1, s2);//printing cartesian product or a relation formed by two sets
//		cout << endl << endl;
//	cout << "TOTAL NUMBER OF POSSIBLE RELATIONS FROM SET A AND B ARE : " <<
//		relationnumber(s1, s2) << endl << endl;// printing number of possible relation can be formed
//		cout << "NOW CHECKING IF THE THE RELATION IS REFLEXIVE ,SYMMETRIC OR ANTI SYMMETRIC : " << endl;
//		isreflexive(arr1, arr2, s1, s2);//calling the function to check the relation is reflexive or not
//		cout << endl;
//	issymmetric(arr1, arr2, s1, s2);//calling the function to check whether the relation is symmetric or anti symmetric
//		cout << endl << endl;
//	if (s1 == s2)
//	{
//		cout << "NUMBER OF POSSIBLE REFLEXIVE RELATIONS ARE :"<<reflexiveno(s1,s2)<<endl<<endl;
//			cout << "NUMBER OF POSSIBLE SYMMETRIC RELATIONS ARE :" <<
//			symmetricno(s1, s2) << endl << endl;
//		cout << "NUMBER OF POSSIBLE ANTI-SYMMETRIC RELATIONS ARE :" << antisymmetric(s1, s2) << endl << endl;
//	}
//	system("pause");
//	return 0;
//}
//void cartesian(int arr1[10], int arr2[10], int s1, int s2)//TO FIND CARTESIAN PRODUCT
//{
//	cout << "Cartesian Product = { ";
//	for (int i = 0; i < s1; i++)
//	{
//		for (int j = 0; j < s2; j++)
//		{
//			if (i == s1 - 1 && j == s2 - 1)
//			{
//				cout << "(" << arr1[i] << "," << arr2[j] << ")";
//			}
//			else
//			{
//				cout << "(" << arr1[i] << "," << arr2[j] << "),";
//			}
//		}
//	}
//	cout << "}";
//}
//int relationnumber(int s1, int s2)//TOTAL NUMBER OF POSSIBLE RELATION CAN BE MADE FROM SET A AND SET B ARE
//{
//int R;
//R = pow(2,(s1 * s2));
//return R;
//}
//int reflexiveno(int s1, int s2)
//{
//	int R;
//	R = pow(2, (s1 * (s2 - 1)));
//	return R;
//}
//int symmetricno(int s1, int s2)
//{
//	int R;
//	R = pow(2, ((s1 * (s2 + 1)) / 2));
//	return R;
//}
//int antisymmetric(int s1, int s2)//2n 3n(n-1)/2
//{
//	int R;
//	R = (pow(2, s1) * pow(3, (s1 * (s2 - 1) / 2)));
//	return R;
//}
//void isreflexive(int arr1[20], int arr2[20], int s1, int s2)//function to find whether the relation is reflexive aur not
//{
//	int c = 0;
//	for (int i = 0; i < s1; i++)
//	{
//		for (int j = 0; j < s2; j++)
//		{
//			if (arr1[i] == arr2[j])
//			{
//				c++;
//			}
//		}
//	}
//	if (s1 == s2)//if both sizes are same then the relation can be reflexive
//	{
//		if (c == s1 && c == s2)//if the count and sizes are equal then the relation will be reflexive
//		{
//		cout << endl << "RELATION IS REFLEXIVE " << endl;
//		}
//		else if (c != s1 && c != s2)
//		{
//			cout << endl << "RELATION IS NOT REFLEXIVE " << endl;
//		}
//	}
//	else if (s2 > s1 || s1 > s2)
//	{
//		cout << endl << "RELATION IS NOT REFLEXIVE " << endl;
//	}
//}
//void issymmetric(int arr1[20], int arr2[20], int s1, int s2)//function to check if the  relation is symmetric or not
//{
//	int c = 0;
//	if (s1 == s2)
//	{
//		for (int i = 0; i < s1; i++)
//		{
//			for (int j = 0; j < s2; j++)
//			{
//				if (arr1[i] == arr2[j])
//				{
//					c++;
//				}
//			}
//		}
//		if (c == s1 && c == s2)
//		{
//			cout << "THE RELATION IS SYMMETRC " << endl;
//			cout << endl << "THE RELATION IS NOT ANTI-SYMMETRIC " << endl;
//		}
//		else if (c != s1 && c != s2)
//		{
//			cout << "THE RELATION IS NOT SYMMETRIC " << endl << endl;
//			cout << "RELATION IS ANTI-SYMMETRIC" << endl;
//		}
//	}
//	else if (s1 != s2)
//	{
//		cout << "THE RELATION IS NOT SYMMETRIC " << endl << endl;
//		cout << " THE RELATION IS ANTI-SYMMETRIC " << endl;
//	}
//}