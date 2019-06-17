/**************************************************************************
*
* Project:  OpenCPN
* Purpose:  Simulator Plugin
* Author:  Ron Southworth April 2019 Mike Rossiter
*
***************************************************************************
*   Copyright (C) Ron Southworth 1985 - April 2019 Mike Rossiter                                   *
*   $EMAIL$                                                               *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************
*/

#ifndef _HRGUI_IMPL_H_
#define _HRGUI_IMPL_H_

#ifdef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "Simulatorgui.h"
#include "Simulator_pi.h"
#include "AisMaker.h"
#include <wx/utils.h>
#include <wx/gdicmn.h>
#include <sstream>
#include <cmath>
#include <wx/stdpaths.h>
#include "wx/process.h"
#include "wx/jsonreader.h"
#include "wx/jsonwriter.h"
#include <wx/thread.h>
#include "tinyxml.h"
#include "tinystr.h"
#include <wx/filedlg.h>
#include "ocpn_plugin.h"

#ifdef __WXOSX__
#define SIMULATOR_DLG_STYLE wxCLOSE_BOX|wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxSTAY_ON_TOP
#else
#define SIMULATOR_DLG_STYLE wxCLOSE_BOX|wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER
#endif
using namespace std;

class Simulator_pi;

// ----------------------------------------------------------------------------
// a simple thread
// ----------------------------------------------------------------------------



class MyThread : public wxThread
{
public:
	MyThread();
	virtual ~MyThread();

	// thread execution starts here
	virtual void *Entry();

public:
	unsigned m_count;
};

// An identifier to notify the application when the // work is done #define ID_COUNTED_COLORS    100

class AisMaker;

class Dlg : public SimulatorBase
{
public:
	Dlg(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Simulator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = SIMULATOR_DLG_STYLE);
	Simulator_pi *plugin;

//	wxString createGSVSentence(double satNum1, double satNum2, double satNum3, double satNum4, double satNumInView);
	wxString createGSVSentence();
	wxString createGSVSentence2();
	wxString createGSVSentence3();
	wxString createGSVSentence4();
	wxString createVHWSentence(double stw, double hdg, double hdm, double vKmhr );
	wxString createMWVTSentence(double spd, double hdg, double winddirection, double windspeed);
	wxString createMWVASentence(double spd, double hdg, double winddirection, double windspeed);
//	wxString createMWDSentence(double winddirection, double windspeed);
	wxString createRMCSentence(wxDateTime myTime, double myLat, double myLon, double mySpd, double myDir, double myDirMag);
	wxString createGLLSentence(wxDateTime myTime, double myLat, double myLon, double mySpd, double myDir);
	wxString createVTGSentence(wxDateTime myTime, double mySpd, double myDir, double myDirMag, double vKmhr);
    wxString createRSASentence(double myRudder);
	wxString createHDTSentence(double myDir);
	wxString createHDMSentence(double myDirMag);
	wxString createXDRPRSentence(double pitch, double heel);
	wxString createXDRAWSentence(double air, double water);
	wxString LatitudeToString(double mLat);
	wxString LongitudeToString(double mLon);
	wxString DateTimeToTimeString(wxDateTime myDT);
	wxString DateTimeToDateString(wxDateTime myDT);
	void OnContextMenu(double m_lat, double m_lon);

	wxString makeCheckSum(wxString mySentence);

	wxTimer *   m_Timer;
	void OnTimer(wxTimerEvent& event);

	double GetLatitude()  { return initLat; };
	double GetLongitude() { return initLon; };

	double initPitch;
	double initHeel;
	double initAir;
	double initWater;

	double initLat;
	double initLon;
	double stepLat;
	double stepLon;

	AisMaker* myAIS;
	wxTextFile* nmeafile;

	bool m_bUseAis;
	bool m_bUseFile;
	wxString m_tMMSI;

	wxDateTime m_GribTimelineTime;

protected:
	bool m_bNeedsGrib;

private:
	void Notify();
	wxString GSV, GSV2, GSV3, GSV4, VHW, MWVT, MWVA, GLL, VTG, HDT, HDM, RMC, RSA, XDRPR, XDRAW; // removed MWD atm
	double initDir, initSpd, initSpdKmhr, initRudder, myDir, myDirMag, vKmhr , myRudder, pitch, heel, air, water;

	wxDateTime dt;
	void SetInterval(int interval);
	int  m_interval;

	wxString m_sTimeSentence;
	wxString m_sTimeID;
	wxString m_sNmeaTime;

	bool dbg;

	bool m_bUseSetTime;
	bool m_bUseStop;
	bool m_bUsePause;

	wxString ParseNMEAIdentifier(wxString sentence);
	wxString ParseNMEASentence(wxString sentence, wxString id);

	void SetNextStep(double inLat, double inLon, double inDir, double inSpd, double &outLat, double &outLon);

	void OnStart(wxCommandEvent& event);
	void OnStop(wxCommandEvent& event);
	void OnClose(wxCloseEvent& event);

	void OnTest(wxCommandEvent& event);
	int mainTest(int argc, char *argv[]);
	//void SendAIS(double cse, double spd, double lat, double lon);

	void OnMidships(wxCommandEvent& event);
	void OnMinus10(wxCommandEvent& event);
	void OnPlus10(wxCommandEvent& event);
	void OnMinus1(wxCommandEvent& event);
	void OnPlus1(wxCommandEvent& event);
	void OnStandby(wxCommandEvent& event);
	void OnAuto(wxCommandEvent& event);

	bool m_bAuto;
	long m_iMMSI;

	virtual void Lock() { routemutex.Lock(); }
	virtual void Unlock() { routemutex.Unlock(); }
	wxMutex routemutex;


	void RequestGrib(wxDateTime time);
	bool GetGribSpdDir(wxDateTime dt, double lat, double lon, double &spd, double &dir);
	void OnWind(wxCommandEvent& event);
	double GetPolarSpeed(double lat, double lon, double cse);

	double AttributeDouble(TiXmlElement *e, const char *name, double def);
	double ReadPolars(wxString filename, double windangle, double windspeed);

	bool m_bUsingWind;
	bool m_bInvalidPolarsFile;
	bool m_bInvalidGribFile;
	bool m_bSimulatorHasStarted;

};

#endif
