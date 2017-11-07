#include <windows.h>
#include <cstdlib>


#define ID_PRZYCISK1 501
#define ID_PRZYCISK2 502
#define ID_PRZYCISK3 503
#define ID_PRZYCISK4 504
#define ID_PRZYCISK5 505


LPSTR NazwaKlasy = "Klasa Okienka";
MSG Komunikat;
HWND g_hDalej;
HWND g_hWyjdz;
HWND g_hPrzedzial1;
HWND g_hPrzedzial2;
HWND g_hPrzedzial3;
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
	hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, NazwaKlasy, "Zgadywanka", WS_CAPTION,
    CW_USEDEFAULT, CW_USEDEFAULT, 400, 400, NULL, NULL, hInstance, NULL );
    
   		hStatic = CreateWindowEx (0, "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_LEFT, 2, 2 ,400, 80, hwnd, NULL, hInstance, NULL);
			SetWindowText(hStatic, "Pomyœl o liczbê z przedzia³u od 1 do 15, a nastêpnie naciœnij Dalej!");
   		
   		g_hDalej = CreateWindowEx( 0, "BUTTON", "Dalej!", WS_CHILD | WS_VISIBLE, 80, 180, 90, 50, hwnd, ( HMENU ) ID_PRZYCISK1, hInstance, NULL );
   		g_hWyjdz = CreateWindowEx( 0, "BUTTON", "WyjdŸ!", WS_CHILD | WS_VISIBLE, 200, 180, 90, 50, hwnd, ( HMENU ) ID_PRZYCISK2, hInstance, NULL );
   		g_hPrzedzial1 = CreateWindowEx( 0, "BUTTON", "Przedzia³ nr 1", WS_CHILD | WS_VISIBLE, 10, 300, 110, 30, hwnd, ( HMENU ) ID_PRZYCISK3, hInstance, NULL );
   		g_hPrzedzial2 = CreateWindowEx( 0, "BUTTON", "Przedzia³ nr 2", WS_CHILD | WS_VISIBLE, 140, 300, 110, 30, hwnd, ( HMENU ) ID_PRZYCISK4, hInstance, NULL );
   		g_hPrzedzial3 = CreateWindowEx( 0, "BUTTON", "Przedzia³ nr 3", WS_CHILD | WS_VISIBLE, 270, 300, 110, 30, hwnd, ( HMENU ) ID_PRZYCISK5, hInstance, NULL );
 		
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
    
    	case WM_COMMAND:
    	switch( wParam )
   	{
    	case ID_PRZYCISK1: 
    		MessageBox( hwnd, "Wybierz przedzia³, do którego nale¿y Twoja liczba:\n Nr 1: <1, 5>\nNr 2: <6, 10>\nNr 3: <11, 15>", "Zgadywanka", MB_ICONQUESTION);
			return(0);	
		case ID_PRZYCISK3:
			{
			int a= MessageBox( hwnd, "Czy Twoja liczba jest parzysta?", "Zgadywanka", MB_YESNO | MB_ICONQUESTION);
			if(a==IDYES)
			{
			int b = MessageBox( hwnd, "Twoja liczba to 4!", "Zgadywanka", MB_RETRYCANCEL | MB_ICONQUESTION);
			if(b==IDRETRY)
			MessageBox( hwnd, "Twoja liczba to 2!", "Zgadywanka", MB_OK | MB_ICONQUESTION);
			return(0);
			}
			if(a==IDNO)
			{
			int c = MessageBox( hwnd, "Twoja liczba to 3!", "Zgadywanka", MB_RETRYCANCEL | MB_ICONQUESTION);
			if (c==IDRETRY)
			{
			int f = MessageBox( hwnd, "Twoja liczba to 5!", "Zgadywanka", MB_RETRYCANCEL| MB_ICONQUESTION);
			if(f==IDRETRY)
			MessageBox( hwnd, "Twoja liczba to 1!", "Zgadywanka", MB_OK| MB_ICONQUESTION);}}
			return(0);
			}
		case ID_PRZYCISK4:
			{
				{
				int l = MessageBox( hwnd, "Czy Twoja liczba to któraœ z tych liczb:\n 6,7,8", "Zgadywanka", MB_YESNO | MB_ICONQUESTION);
					if(l==IDYES)
					{
						int k = MessageBox( hwnd, "Czy Twoja liczba jest parzysta?", "Zgadywanka", MB_YESNO | MB_ICONQUESTION);
						if(k==IDYES)
							{
							int j=MessageBox( hwnd, "Twoja liczba to 6!", "Zgadywanka", MB_RETRYCANCEL | MB_ICONQUESTION);
							if(j==IDRETRY)
							MessageBox( hwnd, "Twoja liczba to 8!", "Zgadywanka", MB_OK | MB_ICONQUESTION);
							return(0);
							}
						if(k==IDNO)
							MessageBox( hwnd, "Twoja liczba to 7!", "Zgadywanka", MB_OK | MB_ICONQUESTION);
							return(0);
					}
					if(l==IDNO)
					{
						int h = MessageBox( hwnd, "Czy Twoja liczba jest nieparzysta?", "Zgadywanka", MB_YESNO | MB_ICONQUESTION);
						if(h==IDYES)
							MessageBox( hwnd, "Twoja liczba to 9!", "Zgadywanka", MB_OK | MB_ICONQUESTION);
							return(0);
						if(h==IDNO)
							MessageBox( hwnd, "Twoja liczba to 10!", "Zgadywanka", MB_OK | MB_ICONQUESTION);
							return(0);
					}
				}
			}
		case ID_PRZYCISK5:
			{
				{
				int g = MessageBox( hwnd, "Czy Twoja liczba jest nieparzysta?", "Zgadywanka", MB_YESNO | MB_ICONQUESTION);
					if(g==IDNO)
					{
					int f = MessageBox( hwnd, "Twoja liczba to 12!", "Zgadywanka", MB_RETRYCANCEL | MB_ICONQUESTION);
					if(f==IDRETRY)
					MessageBox( hwnd, "Twoja liczba to 14!", "Zgadywanka", MB_RETRYCANCEL | MB_ICONQUESTION);
					return(0);
					}
					if(g==IDYES)
					{
					int p = MessageBox( hwnd, "Czy Twoja liczba jest podzielna przez 3?", "Zgadywanka", MB_YESNO | MB_ICONQUESTION);
					if(p==IDYES)
					MessageBox( hwnd, "Twoja liczba to 15!", "Zgadywanka", MB_OK | MB_ICONQUESTION);
					if(p==IDNO)
					{
					int o= MessageBox( hwnd, "Twoja liczba to 11", "Zgadywanka", MB_RETRYCANCEL | MB_ICONQUESTION);
					if(o==IDRETRY)
					MessageBox( hwnd, "Twoja liczba to 13!", "Zgadywanka", MB_OK | MB_ICONQUESTION);
					return(0);
					}
					}	
				}
			}	
    		
	
		case ID_PRZYCISK2:
    	MessageBox( hwnd, "Dziêkujemy za skorzystanie ze zgadywanki, do zobaczenia!", "Zgadywanka", MB_ICONINFORMATION );
   	 	 exit(0);
	
	
	}
	
	
	
    	
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



