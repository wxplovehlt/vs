// Hello.cpp : 定义控制台应用程序的入口点。
//def AddMult(a, b) :
//print("in FunctionAddMult...")
//print(a)
//print(b)
//return[[1, 2, 3], [4, 5, 6], [7, 8, 9]]

#include "stdafx.h"
#include"Python.h"
#include "iostream"
#include<vector>

using namespace std;
using std::vector;
void main(){
	//////仿真环境///////////////////////////////////////////////////////////////////////
	//Py_Initialize(); /*初始化python解释器,告诉编译器要用的python编译器*/
	//PyRun_SimpleString("import sys; sys.path.append('.')");
	//PyRun_SimpleString("import helloworld"); /*调用python文件*/
	//PyRun_SimpleString("helloworld.hello()");/*调用python文件中的函数*/
	//Py_Finalize(); /*结束python解释器，释放资源*/
	//system("pause");
	/////////传参数////////////////////////////////////////////////////////////
	/*Py_Initialize();
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");
	PyObject* pModule = NULL;
	PyObject* pList = NULL;
	PyObject* pFunc = NULL;
	PyObject* pArgs = NULL;
	pModule = PyImport_ImportModule("PyFile");
	pFunc = PyObject_GetAttrString(pModule, "TestList");
	pArgs = PyTuple_New(1);
	pList = PyList_New(0);
	for (int i = 0; i < 3; i++)
	{
		PyList_Append(pList, Py_BuildValue("i", i));
	}

	PyTuple_SetItem(pArgs, 0, pList);
	PyObject* pRet = PyEval_CallObject(pFunc, pArgs);
	int i, j, k;
	PyArg_ParseTuple(pRet, "i,i,i", &i, &j, &k);

	printf("%d, %d, %d\n", i, j, k);*/

	PyObject* pName = NULL;
	PyObject* pModule = NULL;
	PyObject* pDict = NULL;
	PyObject* pFunc = NULL;
	PyObject* pArgs = NULL;
	PyObject* pRet = NULL;
    PyObject *item;
		// 初始化Python
		// 在使用Python系统前，必须使用Py_Initialize对其
		// 进行初始化。它会载入Python的内建模块并添加系统路
		// 径到模块搜索路径中。这个函数没有返回值，检查系统
		// 是否初始化成功需要使用Py_IsInitialized。
		Py_Initialize();

		PyRun_SimpleString("import sys");
		PyRun_SimpleString("sys.path.append('./')");
		pModule = PyImport_ImportModule("PyFile");
		pFunc = PyObject_GetAttrString(pModule, "AddMult");

		//// 找出函数名为AddMult的函数
		////pFunc = PyDict_GetItemString(pDict, "AddMult");
		//if (!pFunc || !PyCallable_Check(pFunc))
		//{
		//	printf("can't find function [AddMult]\n");
	
		//}

	  pArgs = Py_BuildValue("si", "wxp", 14);
	  pRet = PyEval_CallObject(pFunc, pArgs);

		//
		//int aa = 0;
		//int bb = 0;
		//int cc = 0;
		//if (pRet && PyArg_ParseTuple(pRet, "iii", &aa, &bb,&cc))
		//{
		//	printf("Function[AddMult] call successful a + b = %d, a * b = %d,%d\n", aa, bb, cc);
		//}
		//int size = PyList_Size(pRet);//prrr 为列表
		//printf("the size is %d\n", size);
	
		//for (int i = 0; i < size; ++i)

		//{

		//	PyObject *pNewAge = PyList_GetItem(pRet, i);//相当于 python中的prrr[i]
		//	vector<int> result;
		//	int newAge = 0;
		//	int ff = 0;
		//	int hh = 0;
		//	//char*newAge = 0;
		//	int len = PyList_Size(pNewAge);

		//	for (int j = 0; j < len; ++j)

		//	{

		//		item = PyList_GetItem(pNewAge, j);

		//		PyArg_Parse(item, "i", &hh);
		//		//printf("Function[AddMult]%d\n", hh);
		//		result.push_back(hh);
		//		

		//	}
		//	for (vector<int>::iterator iter = result.begin(); iter != result.end(); ++iter)
		//	{
		//		cout << *iter << endl;
		//	}
		//	//PyArg_Parse(pNewAge, "iii", &newAge,&ff,&hh);//将python的字符串转为c字符串

		//	//printf("Function[AddMult]%d,%d,%d\n", newAge,ff,hh);

		//}
		//if (pArgs)
		//	Py_DECREF(pArgs);
		//if (pFunc)
		//	Py_DECREF(pFunc);

		///////传列表///////////
		PyObject*pyFunc_printList = PyObject_GetAttrString(pModule,"printList");
		if(pModule&& PyCallable_Check(pyFunc_printList))
		{

			PyObject*pyParams = PyList_New(0);           //初始化一个列表

			PyList_Append(pyParams,Py_BuildValue("i",555));//列表添加元素值

			PyList_Append(pyParams,Py_BuildValue("i",111));

			//PyList_Append(pyParams,Py_BuildValue("i",6));

			//PyList_Append(pyParams,Py_BuildValue("i",8));

			PyObject*args = PyTuple_New(1); //这步很关键：将列表转换成元组的一个元素后传递给Python程序

				PyTuple_SetItem(args,0,pyParams);

			//pRet=PyEval_CallObject(pyFunc_printList,args);
			//int j=0;
		    char*s;
			int j=0;
			int h=0;
			int len=0;
			PyObject *py_tuple;
			//item = PyList_GetItem(pRet, 1);//python文件中返回的是list,取list[1]
			//int size = PyList_Size(pRet);//prrr 为列表
			item =PyTuple_GetItem(pRet, 1);//python文件中返回的是tuple,取tuple[1]
			int size = PyTuple_Size(pRet);//prrr 为列表
			//PyArg_ParseTuple(pRet, "O", &py_tuple);
			//len = PyTuple_Size(py_tuple);
			PyArg_ParseTuple(pRet, "si", &s,&h);//解析多个数，需要python返回的是元组
	       // PyArg_Parse(item, "i", &j);//解析单个数
			printf("the size is %d\n", size);
			//printf("the len is %d\n", len);
			printf("Function[AddMult]%s,%d\n", s,h);//打印python返回的字符串
		}
    system("pause");
	Py_Finalize();
}
//def AddMult(a, b):
//print("in FunctionAddMult...") 
//	print (a)
//	print (b)
//	return ("wxphello",1234)
//	def TestList(nlist):
//a=[1,2,3]
//print(nlist)
//	return a
//	def printList(l):
//#print(len(l))
//for var in l:
//print(var)
//	a = [241, 123]
//#return (11111111,22222)
//return tuple(a)


