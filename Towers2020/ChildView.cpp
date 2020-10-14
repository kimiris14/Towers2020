
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "DoubleBufferDC.h"
#include "framework.h"
#include "Towers2020.h"
#include "ChildView.h"
#include "Game.h"
#include "ImageMap.h"
#include <memory>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Gdiplus;
using namespace std;


/// Frame duration in milliseconds
const int FrameDuration = 30;


// CChildView

CChildView::CChildView()
{

	// create the game object
	mGame = CGame();

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_LEVEL_LEVEL0, &CChildView::OnLevelLevel0)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{

	if (mFirstDraw)
	{
		mFirstDraw = false;
		SetTimer(1, FrameDuration, nullptr);

		/*
		 * Initialize the elapsed time system
		 */
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}

	/*
	 * Compute the elapsed time since the last draw
	 */
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	CPaintDC paintDC(this);
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Graphics graphics(dc.m_hDC);

	// get the client's rectangle viewing box
	CRect rect;
	GetClientRect(&rect);

	mGame.OnDraw(&graphics, rect.Width(), rect.Height());
}



/**
 * Handle timer events
 * \param nIDEvent The timer event ID
 */
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}



/**
 * Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context
 * \returns FALSE
 */
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}




void CChildView::OnLevelLevel0()
{
	// TODO: Add your command handler code here
}
