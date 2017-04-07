
// lab4c.2View.cpp : реализация класса Clab4c2View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "lab4c.2.h"
#endif

#include "lab4c.2Doc.h"
#include "lab4c.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab4c2View

IMPLEMENT_DYNCREATE(Clab4c2View, CView)

BEGIN_MESSAGE_MAP(Clab4c2View, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32771, &Clab4c2View::kvadrat)
	ON_COMMAND(ID_32772, &Clab4c2View::Krug)
END_MESSAGE_MAP()

// создание/уничтожение Clab4c2View

Clab4c2View::~Clab4c2View()
{
}

BOOL Clab4c2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование Clab4c2View


void Clab4c2View::OnDraw(CDC* pDC)
	{
		Clab4c2Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		// TODO: add draw code for native data here 
		CPen pen(PS_SOLID, 1, RGB(255, 0, 0));  // Перо для рисования линий 
		pDC->SelectObject(pen); // Загружаем перо в контекст устройства 
		MyLine *p = pDoc->pF; // Указатель указывает на первый элемент списка 
		while (p) // Просматриваем список и рисуем линии 
		{
			pDC->MoveTo(p->p1);
			pDC->LineTo(p->p2);
			p = p->pNext;
		}
		// Перерисовка строки текста 
		pDC->TextOut(50, 50, pDoc->text); // Выводим строку текста в контекст устройства 

		if (pDoc->flagFig1) // Если фигура была нарисована 
		{
			pDC->SelectObject(&pen1); // Загружаем перо 
			pDC->SelectObject(&brush1); // Загружаем кисть 
			pDC->Rectangle(100, 100, 200, 200); // Рисуем круг 
		}

		if (pDoc->flagFig2) // Если фигура была нарисована 
		{
			pDC->SelectObject(&pen1); // Загружаем перо 
			pDC->SelectObject(&brush1); // Загружаем кисть 
			pDC->Ellipse(300, 100, 400, 200); // Рисуем круг 
		}

	}

	// TODO: добавьте здесь код отрисовки для собственных данных

void Clab4c2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default 
	p1 = p2 = point;

	CView::OnLButtonDown(nFlags, point);
}


void Clab4c2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default 
	if (nFlags == MK_LBUTTON) // Нажата левая кнопка мыши 
	{
		CPen pen1, pen2;
		pen1.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		pen2.CreateStockObject(WHITE_PEN);
		CClientDC d(this);
		d.SelectObject(&pen2);
		d.MoveTo(p1); d.LineTo(p2); // Стирание старой линии 
		p2 = point;
		d.SelectObject(&pen1);
		d.MoveTo(p1); d.LineTo(p2); // Рисование новой линии 
	}

	CView::OnMouseMove(nFlags, point);
}

void Clab4c2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default 
	MyLine *p = new MyLine(p1, p2); // Создаем объект - линия 
	Clab4c2Doc* pDoc = GetDocument(); // Указатель объект - Документ 
	p->add(pDoc->pF); // Добавляем объект в список 
	pDoc->SetModifiedFlag(1); // Документ изменен 

	CView::OnLButtonUp(nFlags, point);
}







void Clab4c2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Обработчик сообщения - ввод символа 
	Clab4c2Doc* pDoc = GetDocument(); // Указатель объект - Документ 
	pDoc->text += (TCHAR)nChar; // Дописываем символ к строке текста 
	CClientDC dc(this); // Создаем объект - Контекст устройства 
	dc.TextOut(50, 50, pDoc->text); // Выводим строку текста в контекст устройства 

	CView::OnChar(nChar, nRepCnt, nFlags);
}

// печать Clab4c2View

BOOL Clab4c2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void Clab4c2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void Clab4c2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}
/*void Clab4c2View::On32773()

{

	// TODO: äîáàâüòå ñâîé êîä îáðàáîò÷èêà êîìàíä

		CClientDC dc(this);
		dc.SelectObject(&pen1);
		dc.SelectObject(&brush1);
		dc.MoveTo(100, 100);
		dc.LineTo(100, 300);
		dc.MoveTo(100, 300);
		dc.LineTo(250, 400);
		dc.MoveTo(250, 400);
		dc.LineTo(100, 100);
		Clab4c2Doc* pDoc = GetDocument();
		pDoc->flagFig3 = true;
}
*/
// диагностика Clab4c2View

#ifdef _DEBUG
void Clab4c2View::AssertValid() const
{
	CView::AssertValid();
}

void Clab4c2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab4c2Doc* Clab4c2View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab4c2Doc)));
	return (Clab4c2Doc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений Clab4c2View


void Clab4c2View::kvadrat()
{
	// TODO: Рисуем квадрат 
	CClientDC dc(this); // Создаем объект - Контекст устройства 
	dc.SelectObject(&pen1); // Загружаем перо 
	dc.SelectObject(&brush1); // Загружаем кисть 
	dc.Rectangle(100, 100, 200, 200); // Рисуем квадрат 
	Clab4c2Doc* pDoc = GetDocument(); // Указатель объект - Документ 
	pDoc->flagFig1 = true; // Флаг, что фигура нарисована
}


void Clab4c2View::Krug()
{
	// TODO: Рисуем круг 
	CClientDC dc(this); // Создаем объект - Контекст устройства 
	dc.SelectObject(&pen1); // Загружаем перо 
	dc.SelectObject(&brush1); // Загружаем кисть 
	dc.Ellipse(300, 100, 400, 200); // Рисуем круг 
	Clab4c2Doc* pDoc = GetDocument(); // Указатель объект - Документ 
	pDoc->flagFig2 = true; // Флаг, что фигура нарисована 
}
