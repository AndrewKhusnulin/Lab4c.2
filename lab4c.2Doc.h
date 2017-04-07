
// lab4c.2Doc.h : интерфейс класса Clab4c2Doc
//


#pragma once

#include "MyLine.h"
class Clab4c2Doc : public CDocument
{

protected: // создать только из сериализации

	DECLARE_DYNCREATE(Clab4c2Doc)

// Атрибуты
public:
	MyLine *pF; // Указатель на первый элемент списка линий 
	bool flagFig1, flagFig2, flagFig3; // Флаги, что геометрические фигуры нарисованы 
	CString text; // Строка текта, которая выводится 

// Операции
public:
		Clab4c2Doc()
	{
		// TODO: add one-time construction code here 
		pF = 0;
		flagFig1 = flagFig2 = false; // Фигуры не нарисованы 
		text = ""; // Строка текcта пустая 
	}
// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~Clab4c2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
