#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
int i=	MessageBox (NULL, "Wybierz liczbê z przedzia³u od 0 do 30", "Zgadywanka", MB_OKCANCEL);
	switch(i)
	{
	case IDCANCEL:
		MessageBox (NULL, "Do zobaczenia natêpnym razem!", "Zgadywanka", MB_OK);
		break;
	
	case IDOK:
		int o=	MessageBox (NULL, "Czy Twoja liczba jest wiêksza od 15?", "Zgadywanka", MB_YESNO);
			switch(o)
			{//cdn.
				case IDYES:
					break;
				case IDNO:
					break;
				}
		
		
	}
	return 0;
}
