
// lab4c.2View.h : ��������� ������ Clab4c2View
//

#pragma once


class Clab4c2View : public CView
{
protected: // ������� ������ �� ������������
	
	DECLARE_DYNCREATE(Clab4c2View)

// ��������
public:
	Clab4c2Doc* GetDocument() const;
	CPoint p1, p2; // �����, �������� �������� ������� 
	CPen pen1; // ���� ��� ��������� ����� ����� ���� 
	CBrush brush1; // ����� ��� ��������� ����� ����� ���� 
// ��������
public:
	Clab4c2View::Clab4c2View()
	{
		// TODO: ������� ���� � ����� ��� ��������� ����� ����� ���� 
		pen1.CreatePen(PS_DASH, 1, RGB(0, 0, 255)); // ������� ����� ���������� ���� 
		brush1.CreateHatchBrush(HS_VERTICAL, RGB(255, 0, 0)); // ������� �������  
															  // ����� ������������� ������� 
	}
// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~Clab4c2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void kvadrat();
	afx_msg void Krug();
};

#ifndef _DEBUG  // ���������� ������ � lab4c.2View.cpp
inline Clab4c2Doc* Clab4c2View::GetDocument() const
   { return reinterpret_cast<Clab4c2Doc*>(m_pDocument); }
#endif

