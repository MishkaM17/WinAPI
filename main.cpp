#include <windows.h>
#include <cstdlib>
#include <ctime>



#define ID_PRZYCISK1 501
#define ID_PRZYCISK2 502

LPSTR NazwaKlasy = "Klasa Okienka";
MSG Komunikat;
HWND g_hDalej;
HWND g_hWyjdz;
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
    CW_USEDEFAULT, CW_USEDEFAULT, 310, 300, NULL, NULL, hInstance, NULL );
    
   		hStatic = CreateWindowEx (0, "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_LEFT, 2, 2 ,300, 80, hwnd, NULL, hInstance, NULL);
			SetWindowText(hStatic, "Pomyœl o liczbê z przedzia³u od 0 do 30, a nastêpnie naciœnij Dalej!");
   		
   		g_hDalej = CreateWindowEx( 0, "BUTTON", "Dalej!", WS_CHILD | WS_VISIBLE, 30, 180, 80, 30, hwnd, ( HMENU ) ID_PRZYCISK1, hInstance, NULL );
   		g_hWyjdz = CreateWindowEx( 0, "BUTTON", "WyjdŸ!", WS_CHILD | WS_VISIBLE, 160, 180, 80, 30, hwnd, ( HMENU ) ID_PRZYCISK2, hInstance, NULL );
		
		

    
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
        
    case WM_COMMAND:
		switch( wParam )
	{
		case ID_PRZYCISK1:
    	MessageBox( hwnd, "Czy Twoja liczba jest wiêksza od 15?", "Zgadywanka", MB_YESNO );
    		case IDYES:
    			
				srand( (unsigned)time( NULL ) ); 
      			char l[2];
      			l[0] = (rand()%15)+48;
     			l[1] = NULL;
      			MessageBox (NULL, l, "Zgdywanka", MB_YESNO );
      			break;
					
				   	
    		
			case IDNO:
    			srand( (unsigned)time( NULL ) ); 
      			char j[2];
      			j[0] = (rand()%6)+48;
      			j[1] = NULL;
      			MessageBox (NULL, j, "Zgadywanka", MB_YESNO);
    
    break;
    
		case ID_PRZYCISK2:
    	MessageBox( hwnd, "Dziêkujemy za skorzystanie ze zgadywanki, do zobaczenia!", "Zgadywanka", MB_ICONINFORMATION );
   	 	 exit(0);
    
    	
	}
	break;
    }
    
    return 0;
}
