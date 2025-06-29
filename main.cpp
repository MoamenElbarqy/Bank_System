#include "Global.h"
#include "LoginScreen.h"
int main()
{
	do
	{
		LoginScreen::ShowLoginScreen();
		if (LockTheSystem)// The System Will Lock If You Fail 3 Times In Login
		{
			cout << "The System Has Been Locked :-(";
			return 0;
		} 
	} while (Util::ContinueOperation("\nDo You Wany To Login Again (y / n) : "));
	return 0;
}