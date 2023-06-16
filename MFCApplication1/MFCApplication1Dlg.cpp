﻿
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "Dino.h"
#include "Cactus.h"
#include "Cloud.h"
#include "BackGround.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	player = new Dino();
	cactus = new Cactus();
	cloud = new Cloud();
	backGround = new BackGround();
	score = 0;
	time = 0;
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	player->ImageLoad();
	cactus->ImageLoadCactus();
	cloud->ImageLoadCloud();
	backGround->ImageLoadBackGround();
	score = 0;
	time = 0;
	
	SetTimer(1, 20, NULL);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);


		player->DrawDino(dc);

		// Cactus 객체 그리기
		for (const auto& cactus : cactusVector)
		{
			cactus->DrawCactus(dc);
		}

		cloud->DrawCloud(dc);

		backGround->DrawBackGround(dc);

		// 텍스트 그리기
		CRect rectText(20, 20, 200, 40); // 텍스트가 그려질 영역
		CString strText; // 표시할 텍스트
		strText.Format(L"Score: %d", score);

		dc.DrawText(strText, rectText, DT_LEFT);

		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nIDEvent)
	{
	case 1:
		time++;
		player->Tick();

		//선인장 생성, 최소한의 간격 설정을 못 했습니다.
		if (time % ((rand() % 150) + 1) == 0 && cactusVector.size() < 3) {
			Cactus* newCactus = new Cactus();
			newCactus->ImageLoadCactus();
			cactusVector.push_back(newCactus);
		}

		//게임 오브젝트들 업데이트
		for (auto& cactus : cactusVector)
		{
			cactus->Tick();
		}

		cloud->Tick();

		backGround->Tick();

		score++;

		if (score == 180) {
			backGround->speedRate += 10;
		}

		if (score == 420) {
			backGround->speedRate += 10;
		}

		if (score >= 180) {

			score++;
		}

		if (score >= 420) {

			score++;
		}
		
		// 선인장 삭제
		for (auto it = cactusVector.begin(); it != cactusVector.end(); )
		{
			Cactus* cactus = *it;

			if (cactus->x <= -100) {
				delete cactus;
				it = cactusVector.erase(it);
			}
			else {
				++it;
			}
		}

		for (auto& cactus : cactusVector)
		{
			if (player->Collider(cactus)) {
				KillTimer(1);
				CString message;
				message.Format(L"%d 점\n다시 도전해보세요!", score);
				MessageBox(message, L"결과");
			}
		}

		Invalidate();
		break;

	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CMFCApplication1Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar) {
	case VK_SPACE:
		player->StartJump();
		break;
	}

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}
