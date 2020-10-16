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

	CPaintDC paintDC(this);
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Graphics graphics(dc.m_hDC);

	// get the client's rectangle viewing box
	CRect rect;
	GetClientRect(&rect);

	mGame.OnDraw(&graphics, rect.Width(), rect.Height());

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

	auto newLevel = make_shared<CLevel>(&mGame, mGame.GetPallette(), Level0);
	mGame.SetLevel(newLevel);
	mGame.StartLevel();

}

/**
* Handler for loading Level1
*/
void CChildView::OnLevelLevel1()
{
	auto newLevel = make_shared<CLevel>(&mGame, mGame.GetPallette(), Level1);
	mGame.SetLevel(newLevel);
	mGame.StartLevel();
}

/**
* Handler for loading Level2
*/
void CChildView::OnLevelLevel2()
{
	auto newLevel = make_shared<CLevel>(&mGame, mGame.GetPallette(), Level2);
	mGame.SetLevel(newLevel);
	mGame.StartLevel();
}
