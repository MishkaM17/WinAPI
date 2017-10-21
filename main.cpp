#include <windows.h>

#define ID_PRZYCISK1 501
#define ID_PRZYCISK2 502
#define ID_PRZYCISK3 503

LPSTR NazwaKlasy = "Klasa Okienka";
MSG Komunikat;
HWND g_hDalej;
HWND g_hWiecej;
HWND g_hMniej;
HWND hStatic;

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
    
    wc.cbSize = sizeof( WNDCLASSEX );
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );
    wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1 );
    wc.lpszMenuName = NULL;
    wc.lpszClassName = NazwaKlasy;
    wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION );
    
        
    RegisterClassEx( & wc );
    
	HWND hwnd;
	hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, NazwaKlasy, "Zgadywanka", WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 300, 300, NULL, NULL, hInstance, NULL );
    
   		hStatic = CreateWindowEx (0, "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_LEFT, 2, 2 ,300, 80, hwnd, NULL, hInstance, NULL);
			SetWindowText(hStatic, "Pomyœl o liczbê z przedzia³u od 0 do 30!");
   		
		g_hDalej = CreateWindowEx( 0, "BUTTON", "Dalej!", WS_CHILD | WS_VISIBLE, 110, 150, 50, 30, hwnd, ( HMENU ) ID_PRZYCISK1, hInstance, NULL );
   		g_hWiecej = CreateWindowEx( 0, "BUTTON", "Wiêcej!", WS_CHILD | WS_VISIBLE, 160, 180, 60, 30, hwnd, ( HMENU ) ID_PRZYCISK2, hInstance, NULL );
   		g_hMniej = CreateWindowEx( 0, "BUTTON", "Mniej", WS_CHILD | WS_VISIBLE, 60, 180, 50, 30, hwnd, ( HMENU ) ID_PRZYCISK3, hInstance, NULL );
		
		
	

    
	ShowWindow( hwnd, nCmdShow );
    UpdateWindow( hwnd );
    
     while( GetMessage( & Komunikat, NULL, 0, 0 ) )
    {
        TranslateMessage( & Komunikat );
        DispatchMessage( & Komunikat );
    }
    return Komunikat.wParam;
}



LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
     switch( msg )
    {
    case WM_CLOSE:
        DestroyWindow( hwnd );
        break;
        
    case WM_DESTROY:
        PostQuitMessage( 0 );
        break;
        
        default:
        return DefWindowProc( hwnd, msg, wParam, lParam );
    }
    
    return 0;
}
