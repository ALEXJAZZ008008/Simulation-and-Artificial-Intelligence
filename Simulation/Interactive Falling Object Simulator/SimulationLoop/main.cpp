#include "simulation.h"

const array<char, 16> m_Title =
{
	'W',
	'i',
	'n',
	'd',
	'o',
	'w',
	' ',
	'C',
	'r',
	'e',
	'a',
	't',
	'i',
	'o',
	'n'
};

Simulation *m_Simulation;

//********************OpenGL Initialization********************************
HDC m_HDC = nullptr;		// Private GDI Device Context
//*****************************************************************************

//************************ MESSAGE HANDLER **************************
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	// this is the main message handler of the system
	PAINTSTRUCT paintStruct;	// used in WM_PAINT
	HDC hdc;					// handle to a device context

	// what is the message 
	switch (msg)
	{
	case WM_CREATE:
	{
		// do initialization stuff here
		return static_cast<LRESULT>(0.0);
	}

	case WM_PAINT:
	{
		// validate the window
		hdc = BeginPaint(hwnd, &paintStruct);
		EndPaint(hwnd, &paintStruct);

		return static_cast<LRESULT>(0.0);
	}

	case WM_KEYDOWN:
	{
		// Handle any non-accelerated key commands
		switch (wparam)
		{
		case VK_ESCAPE:
		case VK_F12: PostMessage(hwnd, WM_CLOSE, 0, 0);

			return 0;
		}

		break;
	}

	case WM_DESTROY:
	{
		// kill the application			
		PostQuitMessage(0);

		return 0;
	}

	default:
	{
		break;
	}
	} // end switch

	// process any messages that we didn't take care of 
	return (DefWindowProc(hwnd, msg, wparam, lparam));
} // end WinProc

wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
{
	wchar_t* wString = new wchar_t[4096];

	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);

	return wString;
}

//**************************Setup OpenGL***********************
void InitializeOpenGL(HWND hwnd, int width, int height)
{
	GLuint glUnit;			// Holds The Results After Searching For A Match
	HGLRC hglrc = nullptr;	// Permanent Rendering Context

	static PIXELFORMATDESCRIPTOR pixelFormatDescriptor =	// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),	// Size Of This Pixel Format Descriptor
		1,								// Version Number
		PFD_DRAW_TO_WINDOW |			// Format Must Support Window
		PFD_SUPPORT_OPENGL |			// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,				// Must Support Double Buffering
		PFD_TYPE_RGBA,					// Request An RGBA Format
		24,								// Select Our Color Depth
		0, 0, 0, 0, 0, 0,				// Color Bits Ignored
		0,							// No Alpha Buffer
		0,							// Shift Bit Ignored
		0,							// No Accumulation Buffer
		0, 0, 0, 0,				// Accumulation Bits Ignored
		16,							// 16Bit Z-Buffer (Depth Buffer)  
		0,							// No Stencil Buffer
		0,							// No Auxiliary Buffer
		PFD_MAIN_PLANE,					// Main Drawing Layer
		0,							// Reserved
		0, 0, 0					// Layer Masks Ignored
	};

	if (!(m_HDC = GetDC(hwnd)))											// Did We Get A Device Context?
	{
#ifdef _DEBUG

		MessageBox(nullptr, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);

#else

		MessageBox(nullptr, convertCharArrayToLPCWSTR("Can't Create A GL Device Context."), convertCharArrayToLPCWSTR("ERROR"), MB_OK | MB_ICONEXCLAMATION);

#endif
	}

	if (!(glUnit = ChoosePixelFormat(m_HDC, &pixelFormatDescriptor)))	// Did Windows Find A Matching Pixel Format?
	{
#ifdef _DEBUG

		MessageBox(nullptr, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);

#else

		MessageBox(nullptr, convertCharArrayToLPCWSTR("Can't Find A Suitable PixelFormat."), convertCharArrayToLPCWSTR("ERROR"), MB_OK | MB_ICONEXCLAMATION);

#endif
	}

	if (!SetPixelFormat(m_HDC, glUnit, &pixelFormatDescriptor))			// Are We Able To Set The Pixel Format?
	{
#ifdef _DEBUG
		MessageBox(nullptr, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);

#else

		MessageBox(nullptr, convertCharArrayToLPCWSTR("Can't Set The PixelFormat."), convertCharArrayToLPCWSTR("ERROR"), MB_OK | MB_ICONEXCLAMATION);

#endif
	}

	if (!(hglrc = wglCreateContext(m_HDC)))								// Are We Able To Get A Rendering Context?
	{
#ifdef _DEBUG
		MessageBox(nullptr, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);

#else

		MessageBox(nullptr, convertCharArrayToLPCWSTR("Can't Create A GL Rendering Context."), convertCharArrayToLPCWSTR("ERROR"), MB_OK | MB_ICONEXCLAMATION);

#endif
	}

	if (!wglMakeCurrent(m_HDC, hglrc))									// Try To Activate The Rendering Context
	{
#ifdef _DEBUG

		MessageBox(nullptr, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);

#else

		MessageBox(nullptr, convertCharArrayToLPCWSTR("Can't Activate The GL Rendering Context."), convertCharArrayToLPCWSTR("ERROR"), MB_OK | MB_ICONEXCLAMATION);

#endif
	}

	ShowWindow(hwnd, SW_SHOW);							// Show The Window
	SetForegroundWindow(hwnd);							// Slightly Higher Priority
	SetFocus(hwnd);										// Sets Keyboard Focus To The Window

	if (height == 0.0)									// Prevent A Divide By Zero By
	{
		height = 1;									// Making Height Equal One
	}

	glViewport(0, 0, width, height);				// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0, static_cast<GLfloat>(width) / static_cast<GLfloat>(height), 0.1f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix

	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0, 0.0, 0.0, 1.0);					// Black Background
	glClearDepth(1.0);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
}


//************************ WIN MAIN***********************

int main(HINSTANCE hinstance, HINSTANCE hprevinstance, LPSTR lpstr, int ncmdshow)
{
	WNDCLASS winclass;	// this will hold the class we create
	HWND hwnd;			// generic window handle
	MSG msg;			// generic message

	// first fill in the window class stucture
	winclass.style = CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = hinstance;
	winclass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	winclass.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	winclass.lpszMenuName = nullptr;

#ifdef _DEBUG

	winclass.lpszClassName = "WindowCreation";

#else

	winclass.lpszClassName = convertCharArrayToLPCWSTR("WindowCreation");

#endif

	// register the window class
	if (!RegisterClass(&winclass))
	{
		return 0;
	}

#ifdef _DEBUG

	// create the window
	if (!(hwnd = CreateWindow("WindowCreation",	// class
		m_Title.data(),							// title
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0,
		0,
		//Set the size of the window to the size of the screen 
		1280,
		720,
		nullptr,								// handle to parent 
		nullptr,								// handle to menu
		hinstance,								// instance
		nullptr)))								// creation parms

#else

	// create the window
	if (!(hwnd = CreateWindow(convertCharArrayToLPCWSTR("WindowCreation"),	// class
		convertCharArrayToLPCWSTR(m_Title.data()),							// title
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0,
		0,
		//Set the size of the window to the size of the screen 
		1280,
		720,
		nullptr,															// handle to parent 
		nullptr,															// handle to menu
		hinstance,															// instance
		nullptr)))															// creation parms

#endif

		return 0;

	InitializeOpenGL(hwnd, 1280, 720);

	m_Simulation = new Simulation(m_HDC);

	// enter main event loop
	bool quit = false;

	while (!quit)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			// test if this is a quit
			if (msg.message == WM_QUIT)
			{
				quit = true;
			}

			// translate any accelerator keys
			TranslateMessage(&msg);

			// send the message to the window proc
			DispatchMessage(&msg);
		} // end if
		else
		{
			m_Simulation->Update();
		}
	} // end while

	delete m_Simulation;

	// return to Windows like this
	return(msg.wParam);
} // end WinMain
//************************ END OF WIN MAIN ***********************