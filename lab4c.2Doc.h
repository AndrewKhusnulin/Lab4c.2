
// lab4c.2Doc.h : ��������� ������ Clab4c2Doc
//


#pragma once

#include "MyLine.h"
class Clab4c2Doc : public CDocument
{

protected: // ������� ������ �� ������������

	DECLARE_DYNCREATE(Clab4c2Doc)

// ��������
public:
	MyLine *pF; // ��������� �� ������ ������� ������ ����� 
	bool flagFig1, flagFig2, flagFig3; // �����, ��� �������������� ������ ���������� 
	CString text; // ������ �����, ������� ��������� 

// ��������
public:
		Clab4c2Doc()
	{
		// TODO: add one-time construction code here 
		pF = 0;
		flagFig1 = flagFig2 = false; // ������ �� ���������� 
		text = ""; // ������ ���c�� ������ 
	}
// ���������������
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~Clab4c2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
