// Hello.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//////���滷��///////////////////////////////////////////////////////////////////////
	//Py_Initialize(); /*��ʼ��python������,���߱�����Ҫ�õ�python������*/
	//PyRun_SimpleString("import sys; sys.path.append('.')");
	//PyRun_SimpleString("import helloworld"); /*����python�ļ�*/
	//PyRun_SimpleString("helloworld.hello()");/*����python�ļ��еĺ���*/
	//Py_Finalize(); /*����python���������ͷ���Դ*/
	//system("pause");
	/////////������////////////////////////////////////////////////////////////
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
		// ��ʼ��Python
		// ��ʹ��Pythonϵͳǰ������ʹ��Py_Initialize����
		// ���г�ʼ������������Python���ڽ�ģ�鲢���ϵͳ·
		// ����ģ������·���С��������û�з���ֵ�����ϵͳ
		// �Ƿ��ʼ���ɹ���Ҫʹ��Py_IsInitialized��
		Py_Initialize();

		PyRun_SimpleString("import sys");
		PyRun_SimpleString("sys.path.append('./')");
		pModule = PyImport_ImportModule("PyFile");
		pFunc = PyObject_GetAttrString(pModule, "AddMult");

		//// �ҳ�������ΪAddMult�ĺ���
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
		//int size = PyList_Size(pRet);//prrr Ϊ�б�
		//printf("the size is %d\n", size);
	
		//for (int i = 0; i < size; ++i)

		//{

		//	PyObject *pNewAge = PyList_GetItem(pRet, i);//�൱�� python�е�prrr[i]
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
		//	//PyArg_Parse(pNewAge, "iii", &newAge,&ff,&hh);//��python���ַ���תΪc�ַ���

		//	//printf("Function[AddMult]%d,%d,%d\n", newAge,ff,hh);

		//}
		//if (pArgs)
		//	Py_DECREF(pArgs);
		//if (pFunc)
		//	Py_DECREF(pFunc);

		///////���б�///////////
		PyObject*pyFunc_printList = PyObject_GetAttrString(pModule,"printList");
		if(pModule&& PyCallable_Check(pyFunc_printList))
		{

			PyObject*pyParams = PyList_New(0);           //��ʼ��һ���б�

			PyList_Append(pyParams,Py_BuildValue("i",555));//�б����Ԫ��ֵ

			PyList_Append(pyParams,Py_BuildValue("i",111));

			//PyList_Append(pyParams,Py_BuildValue("i",6));

			//PyList_Append(pyParams,Py_BuildValue("i",8));

			PyObject*args = PyTuple_New(1); //�ⲽ�ܹؼ������б�ת����Ԫ���һ��Ԫ�غ󴫵ݸ�Python����

				PyTuple_SetItem(args,0,pyParams);

			//pRet=PyEval_CallObject(pyFunc_printList,args);
			//int j=0;
		    char*s;
			int j=0;
			int h=0;
			int len=0;
			PyObject *py_tuple;
			//item = PyList_GetItem(pRet, 1);//python�ļ��з��ص���list,ȡlist[1]
			//int size = PyList_Size(pRet);//prrr Ϊ�б�
			item =PyTuple_GetItem(pRet, 1);//python�ļ��з��ص���tuple,ȡtuple[1]
			int size = PyTuple_Size(pRet);//prrr Ϊ�б�
			//PyArg_ParseTuple(pRet, "O", &py_tuple);
			//len = PyTuple_Size(py_tuple);
			PyArg_ParseTuple(pRet, "si", &s,&h);//�������������Ҫpython���ص���Ԫ��
	       // PyArg_Parse(item, "i", &j);//����������
			printf("the size is %d\n", size);
			//printf("the len is %d\n", len);
			printf("Function[AddMult]%s,%d\n", s,h);//��ӡpython���ص��ַ���
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


