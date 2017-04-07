#if !defined(AFX_MYLINE_H__65C81C1E_6FED_4C5E_8888_7132A02976AB__INCLUDED_) 
#define AFX_MYLINE_H__65C81C1E_6FED_4C5E_8888_7132A02976AB__INCLUDED_ 

#if _MSC_VER > 1000 
#pragma once 
#endif // _MSC_VER > 1000 
class MyLine : public CObject
{
public:
	void add(MyLine *&pF); // Добавить элемент в начало списка 
	MyLine();
	MyLine(CPoint p1, CPoint p2);
	virtual ~MyLine();
	CPoint p1, p2; // Координаты концов отрезка 
	MyLine *pNext; // Указатель на следующий элемент 
	static int Num; // Счетчик созданных объектов 
	DECLARE_SERIAL(MyLine)
};
#endif