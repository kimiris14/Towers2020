
// Towers2020.h : main header file for the Towers2020 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


/// CTowers2020App:
/// See Towers2020.cpp for the implementation of this class
///
class CTowers2020App : public CWinApp
{
public:
	CTowers2020App() noexcept;


// Overrides
public:

	/**
	 * Initializes the instance
	 * \returns bool, true if successful
	 */
	virtual BOOL InitInstance();

	/**
	 * Exits the instance
	 * \returns an integer exit code
	 */
	virtual int ExitInstance();

// Implementation

public:


	/**
	 * Generates the about message for this application
	 * \returns the about message
	 */
	afx_msg void OnAppAbout();


	DECLARE_MESSAGE_MAP()

private:

	/// The gdiplus startup input object for the towers2020 application
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;

	/// The special token for the gdiplus graphics
	ULONG_PTR gdiplusToken = 0;
};

extern CTowers2020App theApp;
