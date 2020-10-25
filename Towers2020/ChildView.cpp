/**
 * \file ChildView.cpp
 *
 * \author PaulaRed
 */



#include "pch.h"
#include "DoubleBufferDC.h"
#include "framework.h"
#include "Towers2020.h"
#include "ChildView.h"
#include "Game.h"
#include "Level.h"
#include "ImageMap.h"
#include <memory>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Gdiplus;
using namespace std;
using namespace xmlnode;

/// Maximum amount of time to allow for elapsed
const double MaxElapsed = 0.050;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/// Level 0 filename
wstring Level0 = L"levels/level0.xml"; 

/// Level 1 filename
wstring Level1 = L"levels/level1.xml";

/// Level 2 filename
wstring Level2 = L"levels/level2.xml";

/// Level 3 filename
wstring Level3 = L"levels/level3.xml";

// CChildView

CChildView::CChildView()
{


}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_LEVEL_LEVEL0, &CChildView::OnLevelLevel0)
	ON_COMMAND(ID_LEVEL_LEVEL1, &CChildView::OnLevelLevel1)
	ON_COMMAND(ID_LEVEL_LEVEL2, &CChildView::OnLevelLevel2)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_LEVEL_LEVEL3, &CChildView::OnLevelLevel3)
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



/**
 * This function is called for everytime there is a screen update. 
 This is where all drawing starts.
 */
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


	//
	// Prevent tunnelling
	//
	while (elapsed > MaxElapsed)
	{
		mGame.Update(MaxElapsed);

		elapsed -= MaxElapsed;
	}

	// Consume any remaining time
	if (elapsed > 0)
	{
		mGame.Update(elapsed);
	}


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

/**
* Handler for loading Level0
*/
void CChildView::OnLevelLevel0()
{
	auto newLevel = make_shared<CLevel>(&mGame, Level0);
	int levelNumber = 0;
	mGame.SetLevel(newLevel, levelNumber);

}

/**
* Handler for loading Level1
*/
void CChildView::OnLevelLevel1()
{
	auto newLevel = make_shared<CLevel>(&mGame, Level1);
	int levelNumber = 1;
	mGame.SetLevel(newLevel, levelNumber);
}

/**
* Handler for loading Level2
*/
void CChildView::OnLevelLevel2()
{
	auto newLevel = make_shared<CLevel>(&mGame, Level2);
	int levelNumber = 2;
	mGame.SetLevel(newLevel, levelNumber);
}


/**
* Handler for loading Level3
*/
void CChildView::OnLevelLevel3()
{
	auto newLevel = make_shared<CLevel>(&mGame, Level3);
	int levelNumber = 3;
	mGame.SetLevel(newLevel, levelNumber);
}

/**
 * Called when there is a left mouse button press
 * \param nFlags Flags associated with the mouse button press
 * \param point Where the button was pressed
*/
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	mGame.OnLButtonDown(point.x, point.y);
}


/**
 * Called when the left mouse button is released
 * \param nFlags Flags associated with the mouse button release
 * \param point Where the button was pressed
 */
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	OnMouseMove(nFlags, point);
	
}


/**
* Called when the mouse is moved
* \param nFlags Flags associated with the mouse movement
* \param point Where the button was pressed
*/
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{

	mGame.OnMouseMove(point.x, point.y, nFlags);
}


